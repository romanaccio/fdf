#include "mlx.h"

int main()
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "Antoine");
	mlx_pixel_put(mlx, win, 200, 200, 0x00FFFFFF);
	mlx_loop(mlx);
}
