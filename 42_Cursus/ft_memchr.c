#include <unistd.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *ptr = (const unsigned char *)s;
	unsigned char ch = (unsigned char)c;
	int	i;

	i = 0;
	while (i < n)
	{
		if (*ptr == ch)
			return (void *)ptr;
		i++;
		ptr++;
	}
}
