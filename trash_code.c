	// dx = var->x1 - var->x0;
	// dy = var->y1 - var->y0;
	// x = var->x0;
	// y = var->y0;
	// if ((float)dy / (float)dx < 1 && (float)dy / (float)dx >= 0)
	// {
	// 	p = 2 * dy - dx;
	// 	while(x <= var->x1 && y <= var->y1)
	// 	{
	// 		mlx_pixel_put(var->mlx, var->mlx_win, x + var->xo, y + var->yo, color);
	// 		if(p < 0)
	// 			p = p + 2 * dy;
	// 		else
	// 		{
	// 			p = p + 2 * dy - 2 * dx;
	// 			y++;
	// 		}
	// 		x++;
	// 	}
	// }
	// else
	// {
	// 	p = 2 * dx - dy;
	// 	while (x <= var->x1 && y <= var->y1)
	// 	{	
	// 		mlx_pixel_put(var->mlx, var->mlx_win, x + var->xo, y + var->yo, color);
	// 		if(p < 0)
	// 			p = p + 2 * dx;
	// 		else
	// 		{
	// 			p = p + 2 * dx - 2 * dy;
	// 			x++;
	// 		}
	// 		y++;
	// 	}
		
	// }