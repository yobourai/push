// Created: 20/04/21 - 16:00
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	int			size;
	int	*arr;
}t_stack;	

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	_c;

	i = 0;
	a = (unsigned char *)b;
	_c = (unsigned char)c;
	while (len > i)
	{
		a[i] = _c;
		i++;
	}
	return (a);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if ((int)count < 0 && (int)size < 0)
		return (NULL);
	p = malloc(size * count);
	if (!p)
		return (p);
	ft_bzero(p, count * size);
	return (p);
}
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (src[i] != '\0' && dstsize - 1 > i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[len] != '\0')
	{
		len++;
	}
	return (len);
}
char	*ft_strdup( char *s1)
{
	char	*s;
	char	*s2;

	s = (char *)s1;
	s2 = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s, ft_strlen(s) + 1);
	s2[ft_strlen(s)] = '\0';
	return (s2);
}
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*str;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen || !len)
		return (ft_calloc(1, 1));
	if (len >= (ft_strlen(s) - start))
		return (ft_strdup(s + start));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

static int	ft_nbw(char  *s, char c)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if ((s[i] == c && s[i - 1] != c) || (s[i + 1] == '\0' && s[i] != c))
			j++;
		i++;
	}
	return (j);
}

static int	ft_nbc(char  *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		j++;
		i++;
	}
	return (j);
}

static	void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static	char	**ft_uncj(char **tab, char  *s, char c, int j)
{
	int	i;
	int	start;
	int	slen;

	i = 0;
	start = 0;
	while (i < j)
	{
		while (s && s[start] == c)
			start++;
		slen = 0;
		slen = ft_nbc(s + start, c);
		tab[i] = ft_substr(s, start, slen);
		if (!tab[i])
		{
			ft_free(tab);
			return (NULL);
		}
		i++;
		start = slen + start;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char  *s, char c)
{
	int		j;
	char	**tab;

	j = ft_nbw(s, c);
	if (!s)
		return (NULL);
	tab = (char **)malloc((j + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = ft_uncj(tab, s, c, j);
	return (tab);
}
int	ft_long(int n)
{
	long	nb;
	int		i;

	nb = n;
	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
int ft_atoi(char *str , int *flag)
 {
    int i = 0;
    int sign = 1;
         int result = 0;

    while (str[i] == ' ' || str[i] == '\t' || (str[i] >= 9 && str[i] <= 13))
        i++;

    if (str[i] == '+' || str[i] == '-') 
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if(!(str[i] >= '0' && str[i] <= '9'))
    {
        printf("Error\n");
        *flag = 1;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if(ft_long(result*sign)!= ft_strlen(str))
    {
        printf("Error bad character\n");
        *flag = 1;
    }
    return result * sign;
}
int len(char ***ptr)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while(ptr[i])
    {
        j = 0;
            while(ptr[i][j])
            {
                j++;
                
            }
            k = k +j;
        i++;
    }
    return k;
}

int check(int *arr ,int size )
{
    int i = 0;
    int j = 0;
    while (i < size) 
    {
		int num = arr[i];
		int pos= i ;
		j = 0;
     	while(j < size)
		{
			if(num == arr[j] && j != pos)
			{
				return 1;
			}
			j++;
		}
        i++;
    }
	return 0; 
}



void print_arr(int *arr, int size)
{
	int i = 0;
	while (i < size)
	{
		printf("arr[%d] = %d, ", i, arr[i]);
		i++;
	}
	printf("\n");
}


void print_arg(char ***tabs)
{
	int i = 0;
	while (tabs[i])
	{
		int j = 0;
		while (tabs[i][j])
		{
			printf("tab=%s, ", tabs[i][j++]);
		}
		i ++;
	}
	printf("\n");
}


int *parc(int ac, char *av[] , t_stack *l) 
{

    if(ac == 1)
    {
        printf("Error\n");
        exit(1);
    }
    int i = 1;
    int j = 0;
    int *arr;
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
    j = 0;
    i=0;
    k= 0;

	#include <stdio.h>
	l->size = len(ptr);
    int flag = 0;

    arr = malloc(sizeof(int) * (l->size) );
    while(ptr[j])
    {
        i = 0;
        while(ptr[j][i])    
        {
                arr[k] = ft_atoi(ptr[j][i],&flag);
                k++;
            	i++;
    
        }
        j++;
    }
    if(flag == 1)
    {
        printf("Error\n");
        exit(1);
    }
	if(check(arr , len(ptr))== 1)
    {
		printf("errro num\n");
        exit(1);
    }
    return arr;
}
void sa(t_stack *arr)
{
	int k = 0;
		k =arr->arr[0]; 
		arr->arr[0] = arr->arr[1];
		arr->arr[1] = k ;

}
void sb(t_stack *arr)
{
	int k = 0;
		k =arr->arr[0]; 
		arr->arr[0] = arr->arr[1];
		arr->arr[1] = k ;

}
void ss(t_stack *arr)
{
	sa(arr);
	sb(arr);
}
void ra(t_stack *arr)
{
    int first;
    int i;
    if (arr->size <= 1) 
        return;
    first = arr->arr[0];
    i = 0;
    
    while (i < arr->size - 1)
    {
        arr->arr[i] = arr->arr[i + 1];
        i++;
    }
    arr->arr[arr->size -1] = first;
	
}

void rb(t_stack *arr)
{
    int first;
    int i;
    if (arr->size <= 1) 
        return;
    first = arr->arr[0];
    i = 0;
    
    while (i < arr->size - 1)
    {
        arr->arr[i] = arr->arr[i + 1];
        i++;
    }
    arr->arr[arr->size -1] = first;
	
}
void rr(t_stack *arr)
{
	ra(arr);
	rb(arr);
}
void rra(t_stack *arr)
{
    int last;
    int i;
    if (arr->size <= 1) 
        return;
    last = arr->arr[arr->size - 1];
    i = 0;
    
    while (i < arr->size - 1)
		 	i++;

	while(i > 0)
	{
		arr->arr[i] = arr->arr[i - 1];
		i--;

	}
    arr->arr[0] = last;

}

void rrb(t_stack *arr)
{
	int last;
    int i;
    if (arr->size <= 1) 
        return;
    last = arr->arr[arr->size - 1];
    i = 0;
    
    while (i < arr->size - 1)
		 	i++;

	while(i > 0)
	{
		arr->arr[i] = arr->arr[i - 1];
		i--;

	}
    arr->arr[0] = last;

}
void rrr(t_stack *arr)
{
	rra(arr);
	rrb(arr);
}

void sort_fc(t_stack *arr)
{
	int i = 0;
		while(i < arr->size - 1)
		{		
			if(arr->arr[i] > arr->arr[i+1])
			{
				sa(arr);
			}
			i++;
		}

}
void sort_tree(t_stack *arr)
{
	int i = 0;
	int tmp ;
	while(arr->size > i)
			i++;

	int k = i;
	i = 0;
	int first ;
	first = arr->arr[0];
		if(arr->arr[i] > arr->arr[i+1])
				sa(arr);
		if(arr->arr[i] > arr->arr[k])
				sa(arr);
		if(first > arr->arr[k])
			{
				 tmp = first;
				 first =arr->arr[k];
				 arr->arr[k] = tmp;
			}
	
}

int main(int ac, char *av[]) 
{
	if(ac <= 1)
	{
		printf("error\n");
		exit(1);
	}
	t_stack *ke ;
	ke = malloc(sizeof(t_stack)); 
	t_stack len ;
    int *tab;
    int i = 0;
    tab= parc(ac, av , &len);
	ke->arr = tab ;
	ke->size = ac  - 1;
	sort_tree(ke);
	i =0;
    while (i < len.size ) 
    {
        printf("%d\n", ke->arr[i]);
        i++;                                                                                            
    }
    return 0;

}
