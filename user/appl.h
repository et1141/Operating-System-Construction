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

class Application
{
public:
	Application();
	Application(const Application &copy) = delete; // prevent copying
												   /* Add your code here */

	void test_cga_screen();
	void test_cga_stream();
	void test_keyboard_controller();
	void test_debian_logo();
	void test_keyboard_interrupt_handling();

};

#endif
