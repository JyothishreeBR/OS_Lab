//parent program(primeShm.c)
//first compile the child pgm "gcc pchild.c -lm -lrt"  then  "./a.out m n"
//after compile the parent pgm "gcc primeShm.c -lm -lrt" then "./a.out m n"

#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<math.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<string.h>

 int main(int argc,char *argv[])
{
 if(argc!=3){
 fprintf(stderr,"insufficient num of argument\n");
 exit(1);
 }
 
 int shmid;
 char *ptr;
 shmid=shm_open("OS",O_CREAT|O_RDWR,0666);
 ftruncate(shmid,4096);
 ptr=mmap(0,4096,PROT_READ,MAP_SHARED,shmid,0);
 pid_t child_pid=fork();
 if(child_pid==0){
 execlp("./pchild","./pchild",argv[1],argv[2],NULL);
 }
 else{
 wait(NULL);
 printf("child finished execution\n");
 printf("prime numbers are %s",ptr);
 }
 munmap(ptr,4096);
 close(shmid);
 shm_unlink("OS");
 return 0;
}

// child program(pchild.c)
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<math.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<string.h>
#define SIZE 1024

int isPrime(int num){
if(num<=0)
return 0;
 for(int i=2;i<=sqrt(num);i++){
 if(num%i==0)
 return 0;
 }
return 1;
}

void generateP(int m,int n,char*rslt){
char buffer[SIZE]=" ";
for(int i=m;i<=n;i++){
 if(isPrime(i)){
 char nums[12];
 sprintf( nums,"%d\t",i);
 strcat(buffer,nums);
 }
}
strcpy(rslt,buffer);
}
 int main(int argc,char *argv[])
{
 if(argc!=3){
 fprintf(stderr,"insufficient num of argument\n");
 exit(1);
 }
 int m=atoi(argv[1]);
 int n=atoi(argv[2]);
 int shmid;
 char *ptr;
 shmid=shm_open("OS",O_CREAT|O_RDWR,0666);
 ftruncate(shmid,4096);
 ptr=mmap(0,4096,PROT_WRITE,MAP_SHARED,shmid,0);
 generateP(m,n,ptr);
 munmap(ptr,4096);
 close(shmid);
 return 0;
 }
 




