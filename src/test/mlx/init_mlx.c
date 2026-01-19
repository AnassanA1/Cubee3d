#include "../../../include/main.h"

void init_mlx(t_game *ref)
{
    if (!ref)
        return;

    ref->display.mlx = mlx_init(WIN_WIDTH, WIN_HIGHT, WIN_TITLE, true);
    if (!ref->display.mlx)
    {
        setError(&ref->error, "Error: Unable to init mlx !");
        setStat(&ref->error, 1);
        return;
    }
    ref->display.image.img = mlx_new_image(ref->display.mlx, WIN_WIDTH, WIN_HIGHT);
    if (!ref->display.image.img)
    {
        mlx_delete_image(ref->display.mlx, ref->display.image.img);
        setError(&ref->error, "Error: Unable to init mlx right image!");
        setStat(&ref->error, 1);
        mlx_terminate(ref->display.mlx);
        return;
    }
    if (mlx_image_to_window(ref->display.mlx, ref->display.image.img, 0, 0) < 0)
    {
        mlx_delete_image(ref->display.mlx, ref->display.image.img);
        setError(&ref->error, "Error: Unable to draw left image!");
        setStat(&ref->error, 1);
        mlx_terminate(ref->display.mlx);
        return;
    }
}
