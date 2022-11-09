#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void main(int argc, char * argv[]) {
  if (argc < 3) {
    printf("[Main] You must enter the first (output of the file to be run with .o extension) and second (how many seconds will it run) parameters.");
    return;
  }

  printf("[Main] %s will run for %s seconds.\n", argv[1], argv[2]);
  int convertedSecond = atoi(argv[2]);
  pid_t pid = fork();
  if (pid == 0) {
    char runCommand[] = "./";
    strcat(runCommand, argv[1]);
    char * args[] = {
      runCommand,
      NULL
    };
    if (execv(args[0], args)) {
      printf("[Main] File not found!");
      return;
    }
  } else {
    sleep(convertedSecond);
    kill(pid, SIGKILL);
    printf("[Main] %d seconds is over. %s terminated.\n", convertedSecond, argv[1]);
  }
}
