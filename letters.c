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
    printf("%c: %.1g\n", 'a'+i, count[i]/(double)total);

  printf("Total: %ld letters\n", total);

  return 0;
}
