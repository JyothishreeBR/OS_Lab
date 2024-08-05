// use of I/O system calls for console

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define SIZE 40

int main()
{
char buffer[SIZE];
int n=read(0,buffer,SIZE);
// 0 IS THE FILE DISCRIPTOR FOR "stdin"
printf("\n number of characters read are %d\n",n);
write(1,buffer,n);
// 1 IS THE FILE DISCRIPTOR FOR "stdout"
}
