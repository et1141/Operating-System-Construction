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

class Gate : public Chain {
private:
   bool _queued; // Flag indicating whether epilogue is queued

public:
   Gate() : _queued(false) {}

   /** 
    * Interrupt handling function.
    * Should be overridden in derived classes.
    */
   virtual bool prologue() {
       return false; // By default, does not require executing epilogue
   }

   /**
    * Default implementation of epilogue.
    * Can be overridden in derived classes.
    */
   virtual void epilogue() {}

   // Setter for _queued flag
   void queued(bool q) {
       _queued = q;
   }

   // Getter for _queued flag
   bool queued() const {
       return _queued;
   }
};

#endif
