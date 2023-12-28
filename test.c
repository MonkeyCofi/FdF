#include <stdio.h>
#include "libft/libft.h"
#include <fcntl.h>

int main(void)
{
	// print a right angled triangle of height 5
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j <= i; j++)
	//		printf("*");
	//	printf("\n");
	//}
	// print a pyramid of height 5
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int spaces = 0; spaces < 5 - i; spaces++)
	//		printf(" ");
	//	for (int j = 0; j < (i * 2) + 1; j++)
	//	{
	//		//printf("%d ", j);
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	//char *str = NULL;
	char *str;

	int fd = open("fdf.c", O_RDONLY);
	if (fd < 0)
		return -1;
	while ((str = get_next_line(fd)))
	{
		ft_printf("%s", str);
		free(str);
	}
}