/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:37:13 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/24 17:43:07 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to handle all movements
void	cub_movement_manager(int move, t_render *render, t_camera *cam)
{
	if (move == MOVE_FORWARD)
        cub_move_forward(render, MOVE_SPEED, &cam->pos, &cam->dir);
	else if (move == MOVE_BACKWARD)
		cub_move_backward(render, MOVE_SPEED, &cam->pos, &cam->dir);
	else if (move == ROTATE_RIGHT)
		cub_rotate_right(ROTATE_SPEED, &cam->dir, &cam->plane);
	else if (move == ROTATE_LEFT)
		cub_rotate_left(ROTATE_SPEED, &cam->dir, &cam->plane);
}

// Function to move forward
void	cub_move_forward(t_render *render , double speed, t_pos_double *pos,
			t_vector *dir)
{
	printf("MOVING FORWARD\n");
	if (render->world[(int)pos->y][(int)(pos->x + dir->x * speed)]
		== 0)
		pos->x += dir->x * speed;
	if (render->world[(int)(pos->y + dir->y * speed)][(int)pos->x]
		== 0)
		pos->y += dir->y * speed;
}

// Function to move backward
void	cub_move_backward(t_render *render , double speed, t_pos_double *pos,
			t_vector *dir)
{
	printf("MOVING BACKWARD\n");
	if (render->world[(int)pos->y][(int)(pos->x + dir->x * speed)]
		== 0)
		pos->x -= dir->x * speed;
	if (render->world[(int)(pos->y + dir->y * speed)][(int)pos->x]
		== 0)
		pos->y -= dir->y * speed;
}

// Function to rotate right
void	cub_rotate_right(double speed, t_vector *dir, t_plane *plane)
{
	double	old_dirX;
	double	old_planeX;

	printf("ROTATE RIGHT\n");
	old_dirX = dir->x;
	dir->x = dir->x * cos(-speed) - dir->y * sin(-speed);
	dir->y = old_dirX * sin(-speed) + dir->y * cos(-speed);
	old_planeX = plane->x;
	plane->x = plane->x * cos(-speed) - plane->y * sin(-speed);
	plane->y = old_planeX * sin(-speed) + plane->y * cos(-speed);
}

// Function to rotate left
void	cub_rotate_left(double speed, t_vector *dir, t_plane *plane)
{
	double	old_dirX;
	double	old_planeX;

	printf("ROTATE LEFT\n");
	old_dirX = dir->x;
	dir->x = dir->x * cos(speed) - dir->y * sin(speed);
	dir->y = old_dirX * sin(speed) + dir->y * cos(speed);
	old_planeX = plane->x;
	plane->x = plane->x * cos(speed) - plane->x * sin(speed);
	plane->y = old_planeX * sin(speed) + plane->y * cos(speed);
}