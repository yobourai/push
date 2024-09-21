#include "push_swap.h"


void sort_fc(t_stack *arr)
{
	if(arr->size <= 1)
		return ;
	if(arr->arr[arr->top] > arr->arr[arr->top - 1])
				sa(arr);

}

void sort_three(t_stack *stack)
{
	if(stack->size <= 2)
		{
			sort_fc(stack);
			return ;
		}
		if(stack->arr[stack->top] < stack->arr[stack->top -1] && stack->arr[stack->top -2] < stack->arr[stack->top -1] && stack->arr[stack->top - 2] > stack->arr[stack->top])
		{		
					sa(stack);
					ra(stack);
		}
		else if(stack->arr[stack->top] > stack->arr[stack->top -1] && stack->arr[stack->top -2] > stack->arr[stack->top -1] && stack->arr[stack->top -2] > stack->arr[stack->top])
				 sa(stack);
		else if(stack->arr[stack->top] < stack->arr[stack->top -1] && stack->arr[stack->top -2] < stack->arr[stack->top] && stack->arr[stack->top -2] < stack->arr[stack->top - 1])
				rra(stack);
		else if(stack->arr[stack->top] > stack->arr[stack->top -1] && stack->arr[stack->top -2] > stack->arr[stack->top - 1] && stack->arr[stack->top - 2] < stack->arr[stack->top])
				ra(stack);
		else if(stack->arr[stack->top] > stack->arr[stack->top -1] && stack->arr[stack->top -2] < stack->arr[stack->top] && stack->arr[stack->top -2] < stack->arr[stack->top - 1])
		{
			sa(stack);
			rra(stack);
			ra(stack);
			ra(stack);
			ra(stack);
		}
}

int min(t_stack *arr)
{
	int i = 0;
	int tmp;
	while(i < arr->size -1)
	{
		if(arr->arr[i] < arr->arr[i+1])
		{
			printf("arr[%d] = %d\n", i, arr->arr[i]);
			printf("arr[%d] = %d\n", i + 1, arr->arr[i + 1]);
			tmp = arr->arr[i];
			arr->arr[i] = arr->arr[i+1];
			arr->arr[i+1] = tmp ;
			printf("arr[%d] = %d\n", i, arr->arr[i]);
			printf("arr[%d] = %d\n", i + 1, arr->arr[i + 1]);
			i =0;
		}
		i++;
	}
	if(arr->arr[arr->top] > arr->arr[arr->top -1])
			sa(arr);
	return arr->arr[arr->top];
}
void sort_five(t_stack *a , t_stack *b)
{
		min(a);
		pb(a ,b);
		min(a);
		pb(a,b);
		sort_three(a);
		pa(a,b);
		pa(a,b);
		sort_fc(a);
}