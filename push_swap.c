#include "push_swap.h"

t_stack *init(t_stack *stack , int size)
{
	stack = malloc(sizeof(t_stack));
	stack->arr = malloc(sizeof(int) * size);
	// ft_memset(&stack->arr, 0,stack->size);
	stack->top = -1;
	stack->size = 0;
	return stack;
}

void printstack(t_stack *a , t_stack *b)
{
	int i ;
	i = a->size - 1;
	while(0 <= i)
	{
		printf("stack A = 			%d\n",a->arr[i]);
		i--;
	}
	int k = b->size -1;
		printf("***************\n");

	while(k >= 0 )
	{
		printf("stack B		%d\n", b->arr[k]);
		k--;
	}


}

int *copy_array(t_stack *a) 
{
    int i = 0;
    int *arr = malloc(sizeof(int) * a->size); 

    int *c = a->arr;
    while (i < a->size) 
	{
        arr[i] = c[i];
        i++;
    }
    return arr;
}

int bubl(t_stack *a) 
{
    int *arr = copy_array(a);  
    int i = 1;
     a->index = 0;
    
    while (i < a->size -1) 
	{
        if (a->arr[i] > a->arr[a->index]) 
            {
				a->index = i;
			}
        i++;
    }
	printf("index%d\n", arr[a->index]);
    return a->index ;
}
void range(t_stack *a , t_stack *b )
{
	int i = 0;

	while(i < a->size -1)
	{
		if(a->arr[a->index] == a->arr[a->top])
		{
			pb(a,b);
		}
		else
			ra(a);
		i++;
	}
	printf("index%d\n", a->arr[a->index]);

}
int main(int ac, char *av[]) 
{
	t_stack *a;
	t_stack *b;

	if(ac <= 1)
	{
		printf("error\n");
		exit(1);
	}

    int *tab;
    int i = 0;
    a = parc(ac, av);
	b = init(b, a->size);
	printstack(a ,b);
	// bubl(a);
	sort_five(a,b);
	// range(a,b);
	printstack(a ,b);
    return 0;

}
