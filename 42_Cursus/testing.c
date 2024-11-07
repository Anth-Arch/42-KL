#include <unistd.h>
#include <stdio.h>

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t dst_len = 0;
    size_t src_len = 0;
    const char *s = src;
    char *d = dst;

    // Calculate the length of src
    while (*s++)
        src_len++;

    // Calculate the length of dst and move d pointer to the end of dst
    while (*d && dst_len < dstsize)
    {
        d++;
        dst_len++;
    }

    // If dst is already larger than dstsize, return dstsize + src_len
    if (dst_len == dstsize)
        return dstsize + src_len;

    size_t remaining_space = dstsize - dst_len - 1;

    // Append src to dst
    while (*src && remaining_space--)
        *d++ = *src++;

    // Null-terminate the result
    *d = '\0';

    return dst_len + src_len;
}

int main(void)
{
    char dst[20] = "1234";
    char src[] = "HELLO WORLD";
    int i = ft_strlcat(dst, src, sizeof(dst));

    printf("Dst: %s\n", dst);
    printf("Src: %s\n", src);
    printf("Len: %i\n", i);
    write(1, dst, 20);
    return (0);
}
