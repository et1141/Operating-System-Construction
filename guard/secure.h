/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               S E C U R E                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Secure class eases locking and unlocking Locker variables that are    */
/* used to protect critical sections of the OS kernel.  In the constructor,  */
/* this class takes the lock; in the destructor it releases it again. Thus,  */
/* it suffices to define a Secure object to protect its complete scope as a  */
/* critical section.                                                         */
/*****************************************************************************/

#ifndef __Secure_include__
#define __Secure_include__

#include "guard.h"

extern Guard guard;

class Secure {
public:
    /**
     * In the constructor, the critical section protected by the Guard object guard is entered.
     */
    inline Secure() {
        guard.enter();
    }

    /**
     * In the destructor, the critical section is exited.
     */
    inline ~Secure() {
        guard.leave();
    }
};

#endif
