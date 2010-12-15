#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
  char *word;
  int count;
  struct node *next;
} Node;

#define NHASH 29989
#define MULT 31

Node *bin[NHASH];

unsigned int hash(char *word)
{
  unsigned int h = 0;
  for (; *word; word++)
    h = h*MULT + *word;
  return h % NHASH;
}


void incword(char *word)
{
  unsigned int h = hash(word);
  Node *p;

  for (p=bin[h];p!=NULL;p=p->next)
    if (strcmp(word,p->word)==0) {
      p->count++;
      return;
    }
  p = malloc(sizeof(Node));
  p->count=1;
  p->word=malloc(strlen(word)+1);
  strcpy(p->word, word);
  p->next = bin[h];
  bin[h] = p;
}

int getword(char *buf)
{
  int length=0;
  int c;
  while ((c=getchar())!=EOF && ! isalpha(c))
    ;
  while (c != EOF && isalpha(c)) {
    *buf = toupper(c);
    buf++;
    length++;
    c=getchar();
  }
  while (c!= EOF && ! isspace(c))
    c=getchar();
  while (c != EOF && ! isalpha(c))
    c=getchar();
  ungetc(c,stdin);
  *buf='\0';
  return length;
}


#define MAXWORD 100

char buf[MAXWORD];


int main()
{
  int i;
  Node *p;

  for (i=0;i<NHASH;i++)
    bin[i]=NULL;

  while (getword(buf)>0)
    incword(buf);

  for (i=0;i<NHASH;i++)
    for (p=bin[i];p!=NULL;p=p->next)
      printf("%d %s\n", p->count, p->word);

  return 0;
}

