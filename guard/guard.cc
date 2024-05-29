/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Using this class, we can synchronize activities with a critical section   */
/* with interrupt handlers that also access this critical section. This      */
/* synchronization takes place along the prologue/epilogue model.            */
/*****************************************************************************/

/* Add your code here */ 
#include "guard/guard.h"
#include "user/globals.h"

void Guard::relay(Gate * item){
    if (guard.avail()){
        cpu.enable_int(); //Since in our implementation interrupts are disabled before guardian() is called, they must be enabled again "manually" 
        item->epilogue();
    }
    else{
        queue.enqueue(item);
    }
}