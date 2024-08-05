#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

  int main()
{
 pid_t my_pid,child_pid,parent_pid;
 child_pid=fork();
   if(child_pid<0)
 {
  printf("Fork failed..Exiting\n");
  exit(0);
 }
 if(child_pid==0)
 {
 printf("[CHILD] T his is a child process");
 my_pid=getpid();
 parent_pid=getppid();
 printf("[CHILD] my pid is=%d\n[CHILD] my parent pid is=%d\n",my_pid,parent_pid);
 printf("[CHILD] Exiting..");
 exit(0);
 }
 
   else
 {
 printf("[PARENT] T his is aparent process\n");
 my_pid=getpid();
 parent_pid=getppid();
 printf("[CHILD] my pid is=%d\n[CHILD] my parent pid is=%d\n",my_pid,parent_pid);
 printf("sleeping for 10 sec\n");
 sleep(10);
 printf("[PARENT] child pid=%d is ended but its entry is in process table so [PARENT] is a ZOMBIE process",child_pid);
 }
 return 0;
}
