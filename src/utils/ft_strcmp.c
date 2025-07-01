#include "../../includes/utils.h"
/*
 Handles NULL pointers.
 Casting to unsigned char is important: Without it, signed char could give incorrect comparisons with characters >127.
 Treat NULL as empty string
*/
int ft_strcmp(const char *str1, const char *str2)
{
    size_t i = 0;

    if (str1 == NULL && str2 == NULL)
        return 0;
    if (str1 == NULL)
        return -1;
    if (str2 == NULL)
        return 1;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
            return (unsigned char)str1[i] - (unsigned char)str2[i];
        i++;
    }
    return (unsigned char)str1[i] - (unsigned char)str2[i];
}
