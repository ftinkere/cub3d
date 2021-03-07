#include    "mlx_int.h"

int		closed_win(void *mlx, void *win)
{
Atom wmDeleteMessage = XInternAtom(((t_xvar*)mlx)->display, "WM_DELETE_WINDOW", False);
XSetWMProtocols(((t_xvar*)mlx)->display, ((t_win_list*)win)->window, &wmDeleteMessage, 1);
}

