#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static void sigHandler(int signo){
  if(signo == SIGINT){
    write(STDERR_FILENO, "Caught SIGINT\n", 15);
    exit(0);
  }
  if(signo == SIGUSR1){
    pid_t ppid = getppid();
    printf("parent process: %d\n", ppid);
  }
}

int main(){
  while(1){
    pid_t pid = getpid();
    printf("pid: %d\n", pid);
    sleep(1);
    signal(SIGINT, sigHandler);
  }
}
