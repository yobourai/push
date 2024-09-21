#include "push_swap.h"

t_stack *parc(int ac, char *av[]) 
{
	t_stack *stack;
	stack =malloc(sizeof(t_stack));

    int i = 1;
    int j = 0;
    int k = 0;
    char ***ptr;
    ptr = malloc(sizeof(char **) * ac );

    while(av[i])
    {  
        ptr[j] =ft_split(av[i], ' ');
        i++;
        j++;
    }
    ptr[j] = NULL;

	stack->size = len(ptr);
	stack->top = stack->size - 1;
    
	k = stack->size -1;
    int flag = 0;

    stack->arr = malloc(sizeof(int) * (stack->size) );
	
	j = 0;
    while(ptr[j])
    {
        i = 0;
        while(ptr[j][i])    
        {
            	stack->arr[k] = ft_atoi(ptr[j][i],&flag);
                k--;
            	i++;
    
        }
        j++;
    }
    if(flag == 1)
    {
        printf("Error\n");
        exit(1);
    }
	if(check(stack->arr , len(ptr))== 1)
    {
		printf("errro num\n");
        exit(1);
    }
    return stack;
}
