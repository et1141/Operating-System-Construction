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
#include "thread/coroutine.h"

class Application: public Coroutine
{
public:
	Application(void *tos);
	Application(const Application &copy) = delete; // prevent copying
	void action() override;
	
	void test_cga_screen();
	void test_cga_stream();
	void test_keyboard_controller();
	void test_debian_logo();

};

#endif
