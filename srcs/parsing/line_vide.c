#include "../../includes/shell.h"

int         line_vide(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
            return (1);
        i++;
    }
    return (0);
}
