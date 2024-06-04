/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Application class defines the (only) application for OOStuBS.         */
/*****************************************************************************/

/* INCLUDES */


#include "user/appl.h"
#include "user/globals.h"
#include "guard/secure.h"

/* GLOBAL VARIABLES are moved to globals.h*/

Key key;


Application::Application(void* tos) : Coroutine(tos) {
    cpu.enable_int();
    pic.allow(pic.timer);
    keyboard.plugin(); 

  //  test_cga_screen();
  //  test_cga_stream();
  //  test_debian_logo();
  //  test_keyboard_controller();
    

   // test_keyboard_controller();
}

/**
 * Test the keyboard interrupt handling. 
*/
void Application::action()
 {    
    while(true){
        kout.print("1", 1, 4);
    }
}

void Application::test_cga_screen()
{
    kout.setpos(0, 0);
    for (int i = 0; i < 80 * 24; i++)
    {
        kout.print("1", 1, 4);
    }

    kout.print("\n", 1, 4);
    for (int i = 0; i < 77; i++)
    {
        kout.print("4", 1, 7);
    }
    kout.print("bsfff", 5, 8);
    kout.print("\n", 1, 4);
    kout.print("bsfff", 5, 8);
    kout.setpos(0, 23);
    kout.print("\n", 1, 11);
}

void Application::test_cga_stream()
{
    kout << "Test          <stream result> -> <expected>" << endl;
    kout << "zero:         " << 0 << " -> 0" << endl;
    kout << "decimal:      " << dec << 42 << " -> 42" << endl;
    kout << "binary:       " << bin << 42 << dec << " -> 0b101010" << endl;
    kout << "octal:        " << oct << 42 << dec << " -> 052" << endl;
    kout << "hex:          " << hex << 42 << dec << " -> 0x2a" << endl;
    kout << "uint64_t max: " << ~((unsigned long)0) << " -> 18446744073709551615" << endl;
    kout << "int64_t max:  " << ~(1l << 63) << " -> 9223372036854775807" << endl;
    kout << "int64_t min:  " << (1l << 63) << " -> -9223372036854775808" << endl;
    kout << "some int64_t: " << (-1234567890123456789) << " -> -1234567890123456789" << endl;
    kout << "pointer:      " << reinterpret_cast<void *>(1994473406541717165ul) << " -> 0x1badcafefee1dead" << endl;
    kout << "smiley:       " << static_cast<char>(1) << endl;
}

void Application::test_debian_logo()
{
    kout << "    _,met$$$$$gg.                                                            " << endl;;
    kout << " ,g$$$$$$$$$$$$$$$P.                                                         " << endl;;
    kout << "g$$P\"" << "       " << "\"\"\"" << "Y$$\"." << "                                                        " << endl;;
    kout << "$P'" << "              " << "`$$$.                                                      " << endl;;
    kout << "P       ,ggs.     " << "`$$b:                                                     " << endl;;
    kout << "'" << "     ,$P\"" << "    " << " ." << "    $$$" << "                               ,#." << endl;;
    kout << "      d$'" << "     " << ",    $$P      ##:          :##        :###:                   " << endl;;
    kout << "      $$." << "   -    " << ",d$$'" << "      ##'          `##         `#'                    " << endl;;
    kout << "      Y$b._   _,d$" << "P'" << "    __  ##     __     ##  __      _     __          _   " << endl;;
    kout << "." << "    `." << "`\"" << "Y$$$$P" << "\"" << "'     " << ",####:##  ,######.  ##.#####. :### ,######. ###.####: " << endl;;
    kout << "b      \"-.__         ,##'" << " `###  ##:  :##  ###' `###  ##' #:   `## `###' `##:" << endl;;
    kout << "$$b                  ##" << "    `##  ##    ##  ##'   `##  ##    ___,##  ##:   `##" << endl;;
    kout << "Y$$." << "                 ##" << "     ##  #######:  ##     ##  ##  .#######  ##'" << endl;;
    kout << " `$$b.               ##" << "     ##  ##'       ##     ##  ##  ##'  `##  ##" << endl;;
    kout << "   `Y$$b.            ##." << "   ,##  ##        ##    ,##  ##  ##    ##  ##" << endl;;
    kout << "     `\"Y$b._         :#:._,###  ##:__,##  ##:__,##' ,##. ##.__:##. ##" << endl;;
    kout << "         `\"\"\"\"" << "       `:#### ###  ######'  `######'  #### `#####" << "##" << " ##" << "      ##" << endl;;
}


void Application::test_keyboard_controller()
{

    keyboard.keyboard_controller.set_repeat_rate(0, 3);
    keyboard.keyboard_controller.set_led(1, true);
    keyboard.keyboard_controller.set_led(2, true);
    keyboard.keyboard_controller.set_led(4, true);

    /*
    // Print instructions
    kout.print("\nClick q to quit keyboard testing while loop", 45, 4);
    kout.print("\nClick m to set minimum(31) repeat_rate", 40, 4);
    kout.print("\nClick M to set max(0) repeat_rate", 35, 4);
    kout.print("\nClick c to turn on all controls", 33, 4);

    // Main loop to wait for key presses
    while (true)
    {
        key = keyboard.keyboard_controller.key_hit();

        if (key.valid())
        {
            if (key.ascii() == 'q')
            {
                break;
            }

            if (key.ascii() == 'm')
            {
                keyboard.keyboard_controller.set_repeat_rate(31, 3);
            }
            if (key.ascii() == 'M')
            {
                keyboard.keyboard_controller.set_repeat_rate(0, 3);
            }
            if (key.ascii() == 'c')
            {
                keyboard.keyboard_controller.set_led(1, true);
                keyboard.keyboard_controller.set_led(2, true);
                keyboard.keyboard_controller.set_led(4, true);
            }

            char pressedKey[2];
            pressedKey[0] = (char)key.ascii();
            pressedKey[1] = '\0'; // 1st arg of screen.print needs to be char* (not char)
            kout.print(pressedKey, 1, 6);
        }
    }
    */
}