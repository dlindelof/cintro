#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int age = 0, reste1=0, reste2=0;
  printf("quel age avez-vous?\n");
  scanf("%d", &age);

  if (age >= 18)
    {
      double ans1=0, reste1= 18-age;
      ans1= fabs(reste1);
      
      printf ("Vous etes majeur !\nEt cela depuis %g ans", ans1);
      
    }
  else
  {
    double ans2=0, reste2= 18- age;
    ans2= fabs(reste2);
    printf("et bam t'es mineur, ahahahahah!\nEncore %g ans a attendre", ans2);
    
  }

  return 0;
}
