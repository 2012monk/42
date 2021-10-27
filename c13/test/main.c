#include "ft_btree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	f(void *i, int l, int f)
{
	printf("%s %d %d\n",(char *) i, l, f);
}

int	c(void *l, void *r)
{
	return (((char *)l)[0] - ((char *)r)[0]);
}

void    ap(void *i)
{
    printf("%s\n", (char *)i);
}

int main(){
	char *m[] = {"6","3","5","4","2","1","8","9","7"};

	t_btree *r = btree_create_node(m[0]);
	for (int i=1; i<9;i++){
		btree_insert_data(&r, m[i], c);
	}
	printf("\n");
	btree_apply_by_level(r, f);
	printf("\n");
    // btree_apply_infix(r, ap);
	// printf("\ninfix\n");
    // btree_apply_prefix(r, ap);
	// printf("\nprefix\n");
    // btree_apply_suffix(r, ap);
	// printf("\npostfix\n");
	// btree_apply_by_level(r, f);
	printf("item : = %s\n", (char *) btree_search_item(r, "8", c)->item);
	printf("level is == %d\n", btree_level_count(r));
}
