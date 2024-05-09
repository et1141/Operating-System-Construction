/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  G A T E                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Class of objects that handle interrupts.   The classes of all objects to  */
/* be registered in the Plugbox must be derived from Gate                    */
/*****************************************************************************/

#ifndef __Gate_include__
#define __Gate_include__

class Gate{

    public:
    /**
     * Function for interrupt handling.
    */
    virtual void trigger (){};
};

#endif
