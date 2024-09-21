
#include "push_swap.h"

void sa(t_stack *arr)
{
	int k = 0;
	if(arr->size <= 1)
			return ;
		k =arr->arr[arr->size-1]; 
		arr->arr[arr->size-1] = arr->arr[arr->size-2];
		arr->arr[arr->size -2] = k ;
		printf("sa\n");

}
void sb(t_stack *arr)
{
	if(arr->size <= 1)
			return ;
		int k = 0;
		k =arr->arr[arr->size-1]; 
		arr->arr[arr->size-1] = arr->arr[arr->size-2];
		arr->arr[arr->size -2] = k ;
		printf("sb\n");

}
void ss(t_stack *a, t_stack *b )
{
	if(a->size <= 1 || b->size <= 1)
		return ;
	int k = 0;
	int n = 0;
	k =a->arr[a->size-1]; 
	a->arr[a->size-1] = a->arr[a->size-2];
	a->arr[a->size -2] = k ;

	n =b->arr[b->size-1]; 
	b->arr[b->size-1] = b->arr[b->size-2];
	b->arr[b->size -2] = n ;
	printf("ss\n");
}
void ra(t_stack *arr)
{
    int last;
    int i;
    if (arr->size <= 1) 
        return;
    last = arr->arr[arr->size -1];
    i = arr->size -1;
    
    while (i > 0)
    {
        arr->arr[i] = arr->arr[i - 1];
        i--;
    }
    arr->arr[0] = last;
	printf("ra\n");
}

void rb(t_stack *arr)
{
    int last;
    int i;
    if (arr->size <= 1) 
        return;
    last = arr->arr[arr->size -1];
    i = arr->size -1;
    
    while (i > 0)
    {
        arr->arr[i] = arr->arr[i - 1];
        i--;
    }
    arr->arr[0] = last;
	printf("rb\n");
	
}
void rotate_b(t_stack *arr)
{
    int last;
    int i;
    if (arr->size <= 1) 
        return;
    last = arr->arr[arr->size -1];
    i = arr->size -1;
    
    while (i > 0)
    {
        arr->arr[i] = arr->arr[i - 1];
        i--;
    }
    arr->arr[0] = last;
	printf("rr\n");
	
}
void rotate_a(t_stack *arr)
{
    int last;
    int i;
    if (arr->size <= 1) 
        return;
    last = arr->arr[arr->size -1];
    i = arr->size -1;
    
    while (i > 0)
    {
        arr->arr[i] = arr->arr[i - 1];
        i--;
    }
    arr->arr[0] = last;
}
void rr(t_stack *stacka , t_stack *stackb)
{
	rotate_a(stacka);
	rotate_b(stackb);
}
void rra(t_stack *arr)
{
    int first;
    int i;
    if (arr->size <= 1) 
        return;
    first = arr->arr[0];
    i = 0;
    
	while(i < arr->size-1)
	{
		arr->arr[i] = arr->arr[i + 1];
		i++;

	}
    arr->arr[arr->size -1] = first;
	printf("rra\n");

}

void rrb(t_stack *arr)
{
	int first;
    int i;
    if (arr->size <= 1) 
        return;
    first = arr->arr[0];
    i = 0;
    
	while(i < arr->size-1)
	{
		arr->arr[i] = arr->arr[i + 1];
		i++;

	}
    arr->arr[arr->size -1] = first;
	printf("rrb\n");
}

void rrotateb(t_stack *arr)
{
	int first;
    int i;
    if (arr->size <= 1) 
        return;
    first = arr->arr[0];
    i = 0;
    
	while(i < arr->size-1)
	{
		arr->arr[i] = arr->arr[i + 1];
		i++;

	}
    arr->arr[arr->size -1] = first;
	printf("rrr\n");
}
void rrotatea(t_stack *arr)
{
	int first;
    int i;
    if (arr->size <= 1) 
        return;
    first = arr->arr[0];
    i = 0;
    
	while(i < arr->size-1)
	{
		arr->arr[i] = arr->arr[i + 1];
		i++;

	}
    arr->arr[arr->size -1] = first;
}
void rrr(t_stack *stacka , t_stack* stackb)
{
	rrotatea(stacka);
	rrotateb(stackb);
}


void push_to_stack(t_stack *src , t_stack *dst)
{
	dst->size++;
	dst->top++;
	dst->arr[dst->top] = src->arr[src->top];
	src->size--;
	src->top--;

}


void pa(t_stack *a,t_stack *b)
{
	if(!b->size)
		return ;
	push_to_stack(b ,a);
	printf("pa\n");
}

void pb(t_stack *a,t_stack *b)
{
	if(!a->size)
		return ;
	push_to_stack(a ,b);
	printf("pb\n");
}