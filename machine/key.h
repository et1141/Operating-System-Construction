/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                K E Y                                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* A key, consisting of an ASCII code, a scan code, and modifier bits.       */
/*****************************************************************************/

#ifndef __Key_include__
#define __Key_include__

class Key {
	// copying allowed

	unsigned char asc;
	unsigned char scan;
	unsigned char modi;

	// bit masks for modifier keys
	struct mbit {
		enum {
			shift       = 1,
			alt_left    = 2,
			alt_right   = 4,
			ctrl_left   = 8,
			ctrl_right  = 16,
			caps_lock   = 32,
			num_lock    = 64,
			scroll_lock = 128
		};
	};

public:
	// DEFAULT CONSTRUCTOR: sets ASCII code, scan code and modifiers to 0
	//                      and thereby marks an invalid key code
	Key() : asc(0), scan(0), modi(0) {}

	// VALID: scancode 0 marks an invalid key
	bool valid() { return scan != 0; }

	// INVALIDATE: sets the scan code to zero and makes this key invalid
	void invalidate() { scan = 0; }

	// ASCII, SCANCODE: setting/getting ASCII code and scan code
	void ascii(unsigned char a) { asc = a; }
	void scancode(unsigned char s) { scan = s; }
	unsigned char ascii() { return asc; }
	unsigned char scancode() { return scan; }

	// functions for setting/clearing SHIFT, ALT, CTRL etc.
	void shift (bool pressed)
	{
		modi = pressed ? modi | mbit::shift : modi & ~mbit::shift;
	}
	void alt_left(bool pressed)
	{
		modi = pressed ? modi | mbit::alt_left : modi & ~mbit::alt_left;
	}
	void alt_right(bool pressed)
	{
		modi =
		    pressed ? modi | mbit::alt_right : modi & ~mbit::alt_right;
	}
	void ctrl_left(bool pressed)
	{
		modi =
		    pressed ? modi | mbit::ctrl_left : modi & ~mbit::ctrl_left;
	}
	void ctrl_right(bool pressed)
	{
		modi = pressed ? modi | mbit::ctrl_right
			       : modi & ~mbit::ctrl_right;
	}
	void caps_lock(bool pressed)
	{
		modi =
		    pressed ? modi | mbit::caps_lock : modi & ~mbit::caps_lock;
	}
	void num_lock(bool pressed)
	{
		modi = pressed ? modi | mbit::num_lock : modi & ~mbit::num_lock;
	}
	void scroll_lock(bool pressed)
	{
		modi = pressed ? modi | mbit::scroll_lock
			       : modi & ~mbit::scroll_lock;
	}

	// functions for reading the state of SHIFT, ALT, CTRL etc.
	bool shift () { return modi & mbit::shift; }
	bool alt_left() { return modi & mbit::alt_left; }
	bool alt_right() { return modi & mbit::alt_right; }
	bool ctrl_left() { return modi & mbit::ctrl_left; }
	bool ctrl_right() { return modi & mbit::ctrl_right; }
	bool caps_lock() { return modi & mbit::caps_lock; }
	bool num_lock() { return modi & mbit::num_lock; }
	bool scroll_lock() { return modi & mbit::scroll_lock; }
	bool alt() { return alt_left() | alt_right(); }
	bool ctrl() { return ctrl_left() | ctrl_right(); }

	operator char() { return (char)asc; }

	// scan codes of a few specific keys
	struct scan {
		enum {
			f1 = 0x3b,
			del = 0x53,
			up = 72,
			down = 80,
			left = 75,
			right = 77,
			div = 8
		};
	};
};

#endif
