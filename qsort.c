#include <stdio.h>

#define N 1000

float t_38[N+1] = {0};
float t_39[N+1] = {0};

main()
{
  int n,i;
  float sum;

  for (n=1;n<=N;n++) {
    sum=0;
    for (i=1;i<=n;i++)
      sum+=n-1+t_38[i-1]+t_38[n-i];
    t_38[n]=sum/n;
  }


  for (n=1;n<=N;n++) {
    sum=0;
    for (i=1;i<=n;i++)
      sum+=t_39[i-1]+t_39[n-i];
    t_39[n]=n-1+sum/n;
  }

  printf("t_38[1000] = %g\n", t_38[999]);
  printf("t_39[1000] = %g\n", t_39[999]);
}
