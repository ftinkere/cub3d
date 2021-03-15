#import <AppKit/NSScreen.h>

int    mlx_get_screen_size(void *mlx, int *width, int *height)
{
    NSRect disp = [[NSScreen mainScreen] frame];
    *height = (int)disp.size.height;
    *width = (int)disp.size.width;
}