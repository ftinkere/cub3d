#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <debug.h>
#include <raycast.h>
#include <glob.h>
#include "unistd.h"
#include "mlx.h"
#include "libft.h"
#include "cvec.h"
#include "parse.h"
#include "intmlx.h"
#include "cub3d_utils.h"
#include "map_validates.h"

t_keybuf	keybuff_new(void)
{
	t_keybuf keybuff;

	keybuff.w = 0;
	keybuff.a = 0;
	keybuff.s = 0;
	keybuff.d = 0;
	keybuff.q = 0;
	keybuff.e = 0;
	return (keybuff);
}