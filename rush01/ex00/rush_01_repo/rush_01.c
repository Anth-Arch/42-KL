/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:19:05 by shkok             #+#    #+#             */
/*   Updated: 2024/05/05 14:57:18 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#define N 4

bool view_check (int isgrid[N][N], int next_row, char *str)
{
	int i = 0;
	int view_left=1;
	int view_right=1;
	int maxLeft = isgrid[next_row][0];
	int maxRight = isgrid[next_row][N-1];
	int y = 0;
	
	while (i < N)
	{
		if (maxLeft < isgrid[next_row][i])
		{
			maxLeft = isgrid[next_row][i];
			view_left++;
		}
		if (maxRight < isgrid[next_row][N-1-i])
		{
			maxRight = isgrid[next_row][N-1-i];
			view_right++;
		}
		i++;
	}
	
	int j = 0;
	while (str[j] != '\0')
		j++;	

	int x;
	char c;
	while (y < 4)
	{
		x = 0;
		while(x < 4)
		{
			c = '0' + isgrid[y][x];
			write (1, &c, 1);
			x++;
		}
		write (1, "\n", 1);
		y++;
	}

	int n_left = (16 + (next_row*2));
	int n_right = (24 + (next_row*2));
	int left_c = (str[n_left]-48);
	int right_c = (str[n_right]-48);

	printf("The next row is %i\n", (next_row));
	printf("The left view is %i.\n",view_left );
	printf("The left_c is %i.\n",left_c);
	printf("The right view is %i.\n",view_right);
	printf("The right_c is %i.\n\n",right_c);
	if ((view_left == left_c) && (view_right == right_c))
	{
		return true;
	}
	return false;
}

bool human_logic(int isgrid[N][N], int next_row, char *str)
{
	int next_column = 0;
	int n_top ;
	int n_bottom;
	int top_c;
	int bottom_c;
	int n_left = (16 + (next_row*2));
	int n_right = (24 + (next_row*2));
	int left_c = (str[n_left]-48);
	int right_c = (str[n_right]-48);

	while (next_column< N)

	{
		n_top = (0 + (next_column*2));
		n_bottom = (8 + (next_column*2));
		top_c = (str[n_top]-48);
		bottom_c = (str[n_bottom]-48);
		if ((top_c == 4) && (bottom_c == 1))
			if (isgrid[next_row][next_column] != (next_row+1))
			{
				printf("First False!");
				return false;
			}
		if ((top_c == 1) && (bottom_c == 4))
			if (isgrid[next_row][next_column] != (N-next_row))
			{
				printf("Second False!");
				return false;
			}
		if (top_c == 4)
			if (isgrid[0][next_column] != 1)
			{	
				printf("Third False!");
				return false;
			}
		if (top_c == 3)
			if (isgrid[0][next_column] == 3)
			{	
				printf("Topic C is %i, Fourth False!\n", top_c);
				printf("Row is :%i\n", next_column);
				printf("The n_top number is : %i\n",n_top);
				return false;
			}
		if (top_c == 2 && bottom_c == 1)
			if (isgrid[0][next_column] != 3 || isgrid[3][next_column] != 4)
			{	
				printf("Fifth False!");
				return false;
			}
		
		next_column ++;
	}
	return true;
}


bool isSafe(int isgrid[N][N], int row, int col, int num)
{
	int z;
	z = 0;
	while (z < N)
	{
		if ((isgrid[row][z] == num) && (z < col)) 
		{
			return false;
		}
		if ((isgrid[z][col] == num) && ((z < row) || (z > row)))
		{	
			return false;
		}
		z++;
	}
	return true;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d", a[i]);
    printf("\n");
}

void permute(int a[], int l, int r, int arr_ans[N][N], int *stored, int next_row, char *str) 
{
	if (*stored == 1) return;

    if (l == r) //This condition help to print the final permutation when the l(start) = r(end)
	{
		int isSafe_check = 0;
		for (int i = 0; i <= r; i++)
		{
			arr_ans[next_row][i] = a[i];
			if (isSafe(arr_ans, next_row, i, a[i]))
			{
				isSafe_check++;
			}
		}
		if ((isSafe_check == r + 1) && (view_check(arr_ans,next_row,str)) && human_logic(arr_ans,next_row,str))	
			*stored = 1;
		return;
	} 
	else 
	{
        for (int i = l; i <= r; i++)
		{ 
            swap(&a[l], &a[i]);   // Fix the number at i (start iteration at the l value)
            permute(a, l + 1, r, arr_ans, stored, next_row, str); // Start a new l value to start a new iteration + permutation.
            swap(&a[l], &a[i]);   // Backtrack to previous configuration
    	}
    }
}

void Four_One_fill(int isgrid[N][N],char *str)
{
	int x;
	int y;

	x = 0;
	while (x < N)
	{
		if ((str[x*2]-48) == 1)
			isgrid[0][x] = N;

		if ((str[(x*2+8)]-48) == 1)
			isgrid[3][x] = N;

		if ((str[(x*2+16)]-48) == 1)
			isgrid[x][0] = N;

		if ((str[(x*2+24)]-48) == 1)
			isgrid[x][3] = N;
		
		if ((str[x*2]-48) == 4)
		{
			y = 0;
			while (y < N)
			{
				isgrid[y][x] = y+1;
				y++;
			}
		}

		if ((str[x*2+8]-48) == 4)
		{
			y = 0;
			while (y < N)
			{
				isgrid[3-y][x] = y+1;
				y++;
			}
		}

		if ((str[x*2+16]-48) == 4)
		{
			y = 0;
			while (y < N)
			{
				isgrid[x][y] = y+1;
				y++;
			}
		}

		if ((str[x*2+24]-48) == 4)
		{
			y = 0;
			while (y < N)
			{
				isgrid[x][3-y] = y+1;
				y++;
			}
		}




		x++;
	}
	return;
}
int main(int argC, char **argV) 
{
    int arr[] = {1, 2, 3, 4};
	int arr_ans[N][N] = {0};
	int y = 0;
	int x = 0;
	char c;
	int next_row;
	printf ("%s\n",argV[1]);


    int n = sizeof(arr) / sizeof(arr[0]);
	int stored = 0;
	
	Four_One_fill(arr_ans, argV[1]);

	next_row = 0;
	while (next_row < N)
	{
		int stored = 0;
    	permute(arr, 0, n - 1, arr_ans, &stored, next_row, argV[1]);
		next_row++;
	}

	while (y < 4)
	{
		x = 0;
		while(x < 4)
		{
			c = '0' + arr_ans[y][x];
			write (1, &c, 1);
			x++;
		}
		write (1, "\n", 1);
		y++;
	}
    return 0;
}
