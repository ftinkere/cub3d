#include <cvec.h>
#include <types.h>
#include <mlx.h>
#include <libft.h>

void	img_load(t_vars *vars, t_img *img, t_path path)
{
	img->img = mlx_xpm_file_to_image(vars->mlx, path, &img->w, &img->h);
	if (!img->img)
	{
		ft_printf("Cannot load texture by path %s\n", path);
		exit(42);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_len, &img->endian);
}

void	load_texs(t_vars *vars)
{
	int		i;
	int		j;
	char	**btexs;

	i = 0;
	while (i < vars->conf->blocks_texs.siz)
	{
		btexs = ((char **)vars->conf->blocks_texs.arr[i]);
		j = 0;
		while (j < 4)
		{
			img_load(vars, &vars->texs[i * 4 + j], btexs[j]);
			j++;
		}
		i++;
	}
	vars->sprite_offset = vars->conf->blocks_texs.siz * 4;
	i = -1;
	while (++i < vars->conf->sprites_texs.siz)
		img_load(vars, &vars->texs[vars->sprite_offset + i],
			((char*)vars->conf->sprites_texs.arr[i]));
	vars->gui_offset = vars->sprite_offset + i;
	img_load(vars, &vars->texs[vars->gui_offset + 0], "../texs/gui/cross.xpm");
	cvec_free_all(&vars->conf->blocks_texs);
	cvec_free_all(&vars->conf->sprites_texs);
}
