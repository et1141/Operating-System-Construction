/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* This class allows accessing the PC's screen.  Accesses work directly on   */
/* the hardware level, i.e. via the video memory and the graphic adapter's   */
/* I/O ports.                                                                */
/*****************************************************************************/

#include "machine/cgascr.h"
#include "machine/io_port.h"

    /**
     * This method displays the character c at the position (x,y) with the specified color attribute attrib.  The position (0,0) designates the upper left corner of the screen. 
     * @param x specifies the column where 0<=x<=79 
     * @param y specifies the row where 0<=y<=24
     * @param attrib can be used to specify features such as background color, foreground color and blinking.
    */
    void CGA_Screen::show (int x, int y, char c, unsigned char attrib){        
    //ex1 slide 29:
        char *CGA_START = (char *)0xb8000;
        char *pos;
        pos = CGA_START + 2*(x + y*80);
        *pos = c;
        *(pos + 1) = attrib; 
    }

/**
 * This method sets the cursor to the specified position where 0<=x<=79, 0<=y<=24
 * @param x specifies the column where 0<=x<=79 
 * @param y specifies the row where 0<=y<=24 
*/
void CGA_Screen::setpos (int x, int y){

    /*
    if(x<0){
        x=0;
        // TODO:  interrupt
    }
    else if (x>79){
        x=79;
        // TODO:  interrupt
    }
    if(y<0){
        y=0;
        // TODO:  interrupt
    }
    else if (y>24){
        y=24;
        // TODO:  interrupt
    }
        */
    int pos = y * 80 + x;

    //the number of the control register to be read or written is first written into the index register.
    outb(0x3d4, 14); 
    //The actual access to the content of the control register (read/write) is then done via the data register.
    outb(0x3d5, pos >> 8); 
    
    outb(0x3d4, 15); 
    outb(0x3d5, pos & 0xFF); 
};

/**
 *     This can be used to get the current position of the cursor from the graphics card. x and y are references and serve as output parameters.
*/

void CGA_Screen::getpos (int &x, int &y){
    outb(0x3d4, 14); 
    int pos_high=inb(0x3d5);
    outb(0x3d4, 15); 
    int pos_low=inb(0x3d5);

    int pos = (pos_high<<8)+pos_low;
    //TODO conditions for x,y? 
    x=pos%80;
    y=pos/80;
};

/**
 * This method can be used to output a string text, starting at the current position of the cursor. Since the string does not need to contain a zero terminator, as is usually the case with C, the length parameter is required, which must specify of how many characters text consists. After the output is finished, the cursor should be placed behind the last printed character. The whole text should be displayed uniformly with the colors chosen by attrib.
If there is not enough space left until the end of the line, the output should be continued on the following line. As soon as the last screen line is filled, the entire screen area should be moved up by one line. This makes the first line disappear. Now, the last line can be deleted and the output can be continued there. 
 * 
*/
void CGA_Screen::move_up(){
    char *CGA_START = (char *)0xb8000;
    char *pos;
    for(int pos_y=0;pos_y<24;pos_y++){ 
                for(int pos_x=0;pos_x<80;pos_x++){
                    
                    pos=CGA_START+ 2*(pos_x + (pos_y+1)*80);//faster way-increment in the loop
                    show(pos_x,pos_y,*pos,*(pos+1));   
                }
            }
            for(int i=0;i<80;i++){
                show(i,24,'x',0); //black color last line
            }
            setpos(0,24);
};
void CGA_Screen::print (char* text, int length, unsigned char attrib){
    int x,y;
    for (int i=0;i<length;i++){
        getpos(x,y);
        if(x>=80){
            setpos(0,y+1);
        }
        if(y>24){ 
            move_up();
        }
        
        if(text[i]== '\n'){//&& length-i>1 &&text[i+1]=='n'){
            if(y==24)
                move_up();
            else
                setpos(0,y+1);
        }else{
            getpos(x,y);
            show(x,y,text[i],attrib);
            setpos(x+1,y);
        }
    }
};
