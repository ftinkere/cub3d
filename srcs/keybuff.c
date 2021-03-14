#include "types.h"

t_keybuf	keybuff_new(void)
{
	t_keybuf	keybuff;

	keybuff.w = 0;
	keybuff.a = 0;
	keybuff.s = 0;
	keybuff.d = 0;
	keybuff.q = 0;
	keybuff.e = 0;
	return (keybuff);
}
