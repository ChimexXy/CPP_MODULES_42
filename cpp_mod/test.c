#include <stdio.h>


typedef struct l_list{

	char *str;
	struct l_list *next;

} t_list;
int main()
{	
	t_list *new;
	new->str = strdup("hamza");
	

	printf("%s\n", "helloword");
}