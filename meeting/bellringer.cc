/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          B E L L R I N G E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The "bell ringer" (Bellringer) is activated periodically and checks if    */
/* any "bells" (Bell objects) need to ring. The bells are in a list that the */
/* bellringer manages.                                                       */
/*****************************************************************************/

#include "object/list.h"
#include "meeting/bell.h"

// The "bell ringer" (Bellringer) is activated periodically and 
// checks if any "bells" (Bell objects) need to ring. 
// The bells are in a list that the bellringer manages.
class Bellringer
/* Add your code here */ 
: public List
{
private:
	Bellringer(const Bellringer &copy); // prevent copying
public:
	Bellringer() {}
/* Add your code here */

	// Checks whether bells are to be rung and does so if necessary
	void check () {
		Bell *tmp = static_cast<Bell *>(first());
		// need this variable because in remove method the variable item's next pointer is set to 0
		// see https://github.com/yaoxin1995/oostubs/blob/main/object/queue.cc#L69
		Bell *del = nullptr;  

		while(tmp) {
			tmp->tick();
			if (tmp->run_down()) {
				tmp->ring();
				del = tmp;
				tmp = static_cast<Bell *>(tmp->next);
				remove(del);
				continue;
			}
			tmp = static_cast<Bell *>(tmp->next);
		}
	}

	// The bell is given to the bell ringer. 
	// It should be rung after ticks time units.
	void job (Bell *bell, int ticks) {
		bell->wait(ticks);
		enqueue(bell);
	}

	// The bell should not be rung after all.
	void cancel (Bell *bell) {
		remove(bell);

	}


};