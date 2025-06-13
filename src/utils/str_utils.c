#include "../../includes/tokenizer.h"

static size_t  ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return i;
}

int isstrequal(const char *s1, const char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (0);
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
        return (1);
    return (0);

}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*dup;
    size_t  i;

    i = 0;
	len = ft_strlen(str);
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}


char *ft_strndup(const char *str, size_t n)
{
    size_t len;
    size_t i;
    char *dup;
    
    len = 0;
    i = 0;
    while (str[len] && len < n)
        len++;
    dup = malloc(len + 1);
    if (!dup)
        return NULL;
    while(i < len)
    {
        dup[i] = str[i];
        i++;
    }
    dup[len] = '\0';
    return dup;
}