/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:22:10 by shkok             #+#    #+#             */
/*   Updated: 2025/03/17 21:24:08 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Program name: fdf
* Turn in files: Makefile, *.h, *.c, demo .fdf files
* Makefile: NAME, all, clean, fclean, re
* Arguments: A file in format *.fdf
* External functs: -> open, close, read, write, malloc, free, perror, strerror, exit
* -> All functions of the math library (-lm compiler option, man 3 math on some operating systems)
* -> All functions of the MiniLibX
* -> ft_printf and any equivalent YOU coded
* Libft authorized: Yes
* Description: This project involves creating a simple wireframe model of a landscape
*/

#define MALLOC_ERROR	1
#define WIDTH			400
#define HEIGHT			400

#include "minilibx-linux/mlx.h"
#include "ft_libft/libft.h"
#include <X11/keysym.h>
#include <X11/X.h>

typedef struct s_mlx_data
{
	void *mlx_ptr;
	void *win_ptr;
	unsigned int color;
}		t_mlx_data;

/* HANDLER FUNCTION
*	Every time a key is pressed this function is called
*
*	Keysym VS Keycode
*	A keycode is a hardware-specific code sent by keyboard for a key press,
*	while a keysym is its abstract representation,
* 	often used in software to identify the key regardless of hardware.
*/

int handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("The %d key (ESC) has been pressed\n\n", keysym);
	return(0);
}

int change_color(t_mlx_data *data)
{
	//Fill the window with current color
	// mix_clear_window(data->mlx, data->win);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 150, data->color, "Color Changing Window!");
	if (data->color == 0xFF0000)
		data->color = 0x00FF00;
	else if(data->color == 0x00FF00)
		data->color = 0x0000FF;
	else
		data->color = 0xFF0000;
		
	return (0);
}

int main(void)
{
	t_mlx_data data;
	
	data.mlx_ptr = mlx_init();
	data.color = 0xFF0000;
	if (data.mlx_ptr == NULL)
		return (MALLOC_ERROR);
	/*
	* T_XVAR struct
	* This function creates a structure and return the address of a struct that contains all the stuff the minilibx will need in order to do its things 
	*/

	/*
	*/

	data.win_ptr = mlx_new_window(data.mlx_ptr, HEIGHT, WIDTH, "My window");
	if (NULL == data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr); 
		free(data.mlx_ptr);
		return (MALLOC_ERROR);
	}
	/* Hooks
	*	"Hooking into events" (react to events)
	*	When I press a key, handle_input() is triggered
	*	Every event is linked to its own prototype handler
	*/
	
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop_hook(data.mlx_ptr, change_color, &data);
	
	/*
	*MLX_HOOK
	* Handle both left and right mouse button presses with the same function.
	* If remove the mask, hook wont work
	*
	* In the X11 system (on which MiniLibx is based), events and event masks are two distinct things;
	*		Events (like ButtonPress): Describe the actual event type, such as pressing a button or moving the mouse.
	*		
	*		Event Masks (like ButtonPressMask): Are filter that determine which types of events a program wants
	*		to listen for. By setting a specific mask, you're saying, "Notify me when this type of event happens"
	*		
	* When you use mlx_hook(), specifying both the event and its correspinding mask ensure that you;
	* Precisely define the event you're interested in (ButtonPress for a mouse button being pressed).
	* Tell the X11 system that you want to be notified about this event by setting the appropriate filter (ButtonPressMask).data
	*	
	*		Wait but Why?
	*	Event Mask (Filter 1): Its the first layer of filtering. WHen you set a mask, you're essentially telling the X11 system,
	*		" I am interested in these type of events. Please notify me when they occur."
	*	Without the right mask set, the system won't even forward the event to your application.data
		
		Event Name (Filter 2): Once the vent gets through the mask and is delivered to your application,
		you then have handler function ( like your button_press function) which handle specific event types
		(like ButtonPress). This is where you react based on the exact event that occured.data

		In the context if mlx_hook(), you're setting up both layers of filtering.
		- You specify the mask to ensure X11 sends the event to your program,
		- and then your handler function responds based on the specific event name (every event has its how prototype)
	*/

	////mlx_hook(data.win_ptr, ButtonPress, ButtonPressMask, &button_press, &data);

	/*
	* Event Loop
	*
	* An event loop keeps the application running and constantly checks
	* for events, such as user input (like mouse clicks or keyboard presses).
	* As long as the application is running, this loop continues to execute.
	*
	*/
	mlx_loop(data.mlx_ptr);
	
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
