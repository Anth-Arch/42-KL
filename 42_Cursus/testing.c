#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *s1 = "ABCDEF";
    char *s2 = "   --++123";
    char *s3 = " + 123";
    char *s4 = " -456abc";
    char *s5 = "-789";
    char *s6 = "+-123";
    char *s7 = "+-456";

    printf("Result 1: %i\n",atoi(s1));
    printf("Result 2: %i\n",atoi(s2));
    printf("Result 3: %i\n",atoi(s3));
    printf("Result 4: %i\n",atoi(s4));
    printf("Result 5: %i\n",atoi(s5));
    printf("Result 6: %i\n",atoi(s6));
    printf("Result 7: %i\n",atoi(s7));
}
