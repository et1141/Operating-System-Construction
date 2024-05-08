/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Application class defines the (only) application for OOStuBS.         */
/*****************************************************************************/

#ifndef __application_include__
#define __application_include__

#include "device/cgastr.h"
#include "machine/keyctrl.h"
#include "machine/cpu.h"


extern CGA_Stream kout;
extern Keyboard_Controller keyboard;
extern Key key;
extern CPU cpu;
class Application

{

public:
	Application();
	Application(const Application &copy) = delete; // prevent copying
												   /* Add your code here */

	void action();

	void test_cga_screen();
	void test_cga_stream();
	void test_keyboard_controller();
	void test_debian_logo();
};

#endif
