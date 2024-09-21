#include "push_swap.h"

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
