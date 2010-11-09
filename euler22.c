#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* for strcmp */

#define MAX_NAMES 6000
#define MAX_NAME_LENGTH 20

char names[MAX_NAMES][MAX_NAME_LENGTH];
int values[MAX_NAMES];

int read_names(char[][MAX_NAME_LENGTH]);
void sort_names(char[][MAX_NAME_LENGTH], int);
void name_values(int[], char[][MAX_NAME_LENGTH], int);

int main()
{
  int n_names, i;
  long sum;

  n_names = read_names(names);

  printf("Read %d names\n", n_names);

  sort_names(names, n_names);

  printf("Sorted names\n");

  name_values(values, names, n_names);

  printf("Valued names\n");

  for (i=0;i<n_names;i++) {
    printf("%s: %d\n", names[i], values[i]);
    sum+=(i+1)*values[i];
  }
  
  printf("Sum: %ld\n", sum);

  return 0;
}

int read_names(char names_array[][MAX_NAME_LENGTH])
{
  int c, i=0;
  int name_index=0;

  while((c=getchar())!=EOF) {
    if (c==',') {
      names_array[name_index++][i]='\0';
      i=0;
    } else if (c!='"')
      names_array[name_index][i++] = c;
  }
  names_array[name_index++][i] = '\0';

  return name_index;
}

int cmpstringp(const void *p1, const void *p2)
{
  return strcmp((char*) p1, (char*) p2);
}


void sort_names(char names_array[][MAX_NAME_LENGTH], int n_names)
{
  qsort(names_array, n_names, sizeof(names_array[0]), cmpstringp);
}

void name_values(int values[], char names[][MAX_NAME_LENGTH], int n_names)
{
  int i,j,value;
  for (i=0; i<n_names; i++) {
    j=0;
    value=0;
    while(names[i][j]!='\0')
      value += names[i][j++] - 'A' + 1;
    values[i] = value;
  }
}
