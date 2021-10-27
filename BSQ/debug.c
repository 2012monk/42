#include "bsq.h"
void	debug(t_board *map, int **bd)
{
	for (int i =0;i<map->height; i++){
		for (int j=0;j < map->width; j++){
			printf("%d", bd[i][j]);
		}
		printf("%s", "\n");
	}
	printf("%s", "\n");
}