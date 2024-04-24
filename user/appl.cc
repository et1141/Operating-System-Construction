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

/* GLOBAL VARIABLES */

CGA_Stream kout;
Keyboard_Controller keyboard;
Key key;

Application::Application()
{
    test_cga_screen();
    test_cga_stream();
    //test_keyboard_controller(); 
    test_debian_logo();
}
void Application::action()
{

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
    keyboard.set_repeat_rate(0, 3);
    keyboard.set_led(1, true);
    keyboard.set_led(2, true);
    keyboard.set_led(4, true);

    // Print instructions
    kout.print("\nYou are in while true loop for keyboard testing. Click q to quit", 66, 4);
    kout.print("\nClick m to set minimum(31) repeat_rate", 35, 4);
    kout.print("\nClick m to set max(0) repeat_rate", 36, 4);
    kout.print("\nClick c to turn on all controls", 33, 4);

    // Main loop to wait for key presses
    while (true)
    {
        key = keyboard.key_hit();

        if (key.valid())
        {
            if (key.ascii() == 'q')
            {
                break;
            }

            if (key.ascii() == 'm')
            {
                keyboard.set_repeat_rate(31, 3);
            }
            if (key.ascii() == 'M')
            {
                keyboard.set_repeat_rate(0, 3);
            }
            if (key.ascii() == 'c')
            {
                keyboard.set_led(1, true);
                keyboard.set_led(2, true);
                keyboard.set_led(4, true);
            }

            char pressedKey[2];
            pressedKey[0] = (char)key.ascii();
            pressedKey[1] = '\0'; // 1st arg of screen.print needs to be char* (not char)
            kout.print(pressedKey, 1, 6);
        }
    }
}