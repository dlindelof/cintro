#include <stdio.h>
#include <ctype.h>

int main()
{
  int c, i;
  long count[26], total=0;

  for (i=0;i<26;i++)
    count[i] = 0;

  while ((c = getchar()) != EOF)
    if (isalpha(c)) {
      count[tolower(c) - 'a']++;
      total++;
    }

  for (i=0;i<26;i++)
    printf("%c: %ld\n", 'a'+i, count[i]);

  printf("Total: %ld letters\n", total);

  return 0;
}
