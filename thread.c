// using 2 threads to compute sum n factorial
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *sum(void *arg);
void *mul(void *arg);
int sm=0, prod=1;
void main(int argc, char * argv[])
{
  pthread_t T1,T2;
  pthread_attr_t attr;//set of thread attributes
  pthread_attr_init(&attr);//get the default attributes
    
  pthread_create(&T1, &attr, sum, argv[1]);
  pthread_create(&T2, &attr, mul, argv[1]);
  pthread_join(T1,NULL);
  pthread_join(T2,NULL);
  
  printf("Inside main thread\n");
  printf("sum=%d\n",sm);
  printf("product=%d\n",prod);
 }
void *sum(void *parm) 
{ 
  int i, n; 
   n = atoi(parm);//string to integer 
  printf("inside  sum thread\n");
  
  for(i=1; i<=n;i++)
  {
    sm+=i;     
  }
 printf("sum thread completed\n");
}
void *mul(void *parm)
{
  int i, n;
  n = atoi(parm);
  printf("inside mul thread\n");
  for(i=2; i<=n;i++)
  {
    prod =prod *i;
  }
  printf("mul thread completed  product\n");
}
