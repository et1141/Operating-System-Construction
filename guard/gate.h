/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  G A T E                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Class of objects that handle interrupts.   The classes of all objects to  */
/* be registered in the Plugbox must be derived from Gate                    */
/*************************************  ****************************************/



#ifndef __Gate_include__
#define __Gate_include__

#include "object/chain.h"

class Gate: public Chain{
    protected:
    bool is_queued; // determine whether a Gate object has already been added to the epilogue queue
    
    public:
    /**
     * Interrupt-handler routine that is executed immediately after the interrupt occurs, asynchronously to other kernel activities. The return value signals whether the epilogue should be executed.
    */
    virtual bool prologue (){return true;};
    /**
     * Potentially delayed and synchronously executed interrupt handler.
    */
    virtual void epilogue (){};
    /**
     * Sets a flag that remembers whether the epilogue is enqueued.
    */
    void queued (bool q){is_queued = q;};    
    
    /**
     * Checks whether the epilogue is enqueued.
    */
    bool queued (){return is_queued;};
};

#endif
