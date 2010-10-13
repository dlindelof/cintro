#include <stdio.h>

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itob: convert n to characters in s - base b */
void itob(int n, char s[], int b)
{
  int i, j, sign;

  if ((sign = n) < 0)
    n = -n;

  i = 0;
  do {
    j = n % b;
    s[i++] = (j <= 9) ? j+'0' : j+'a'-10;
  } while ((n /= b) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

main()
{
  int test_n = 14159;
  char test_s[20];
  int test_b = 16;

  itob(test_n, test_s, test_b);

  printf("%d in base %d is %s\n", test_n, test_b, test_s);
}
