#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*buc;

	i = 0;
	buc = (unsigned char *)s;
	while (i < n)
	{
		buc[i] = c;
		i++;
	}
	return (s = buc);
}
