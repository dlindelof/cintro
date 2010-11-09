#include <ctype.h>
#include <stdio.h>
#include "calc.h"

/* getop:  get next character or numeric operand */
int getop(char s[])
{
    int i = 0;
    int c;
    int next;

    /* Skip whitespace */
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    /* Not a number but may contain a unary minus. */
    if(!isdigit(c) && c != '.' && c != '-')
        return c;               

    if(c == '-')
    {
        next = getch();
        if(!isdigit(next) && next != '.')
        {
           return c;
        }
        c = next;
    }
    else
    {
        c = getch();
    }
 
    while(isdigit(s[++i] = c))
            c = getch();
    if(c == '.')                     /* Collect fraction part. */
        while(isdigit(s[++i] = c = getch()))
                        ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}
