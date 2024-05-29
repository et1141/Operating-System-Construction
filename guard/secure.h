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

#include "user/globals.h"

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


/*
Convention how to use it to enter critical section: 
Description
The Secure class is used for convenient protection of critical sections. It exploits the fact that the C++ compiler automatically includes constructor and destructor calls in the code for each object and that an object loses its validity as soon as it leaves the scope in which it was declared.

Therefore, if a critical section is entered in the constructor of Secure and exited in the destructor, marking critical code sections can be done quite simply as follows:

    // uncritical
    ...
     { Secure section;
       // here come the critical instructions 
       ...
     }
    // end of the critical section
*/