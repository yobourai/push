#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int			size;
	int top ;
	int index;
	int	*arr;
}t_stack;

#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strdup( char *s1);
static int	ft_nbw(char  *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
static int	ft_nbc(char  *s, char c);
static	void	ft_free(char **s);
static	char	**ft_uncj(char **tab, char  *s, char c, int j);
char	**ft_split(char  *s, char c);
int	ft_long(int n);
int ft_atoi(char *str , int *flag);
int len(char ***ptr);
int check(int *arr ,int size );
void print_arr(int *arr, int size);
void print_arg(char ***tabs);
t_stack *parc(int ac, char *av[]); 
int min(t_stack *arr);
void sort_five(t_stack *a , t_stack *b);
t_stack *init(t_stack *stack , int size);
void printstack(t_stack *a , t_stack *b);
int *copy_array(t_stack *a); 
int bubl(t_stack *a); 
void range(t_stack *a , t_stack *b );
void pb(t_stack *a,t_stack *b);
void pa(t_stack *a,t_stack *b);
void push_to_stack(t_stack *src , t_stack *dst);
void sort_three(t_stack *stack);
void sort_fc(t_stack *arr);
void rrr(t_stack *stacka , t_stack* stackb);
void rrotatea(t_stack *arr);
void rrotateb(t_stack *arr);
void rrb(t_stack *arr);
void rra(t_stack *arr);
void rr(t_stack *stacka , t_stack *stackb);
void rotate_a(t_stack *arr);
void rotate_b(t_stack *arr);
void rb(t_stack *arr);
void ra(t_stack *arr);
void ss(t_stack *a, t_stack *b );
void sb(t_stack *arr);
void sa(t_stack *arr);

#endif
