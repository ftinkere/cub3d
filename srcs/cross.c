#include <types.h>
#include <mlx.h>

void	load_cross(t_vars *vars)
{
	const char	*cross_xpm[] = {
	"21 21 2 1", "     c None", ".    c #FFFFFF", "          .          ",
	"          .          ", "          .          ", "          .          ",
	"          .          ", "          .          ", "          .          ",
	"          .          ", "         . .         ", "        .   .        ",
	"........     ........", "        .   .        ", "         . .         ",
	"          .          ", "          .          ", "          .          ",
	"          .          ", "          .          ", "          .          ",
	"          .          ", "          .          "
	};
	t_img		*im;

	im = &vars->texs[vars->gui_offset];
	im->img = mlx_xpm_to_image(vars->mlx, (char **)cross_xpm, &im->w, &im->h);
	im->addr = mlx_get_data_addr(im->img, &im->bits_per_pixel,
			&im->line_len, &im->endian);
}
