#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>



char *getInputLine(void)
{
  char *line = NULL;
  size_t bufsize = 0; // have getline allocate a buffer for us

  if (getline(&line, &bufsize, stdin) == -1){
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);  // We recieved an EOF
    } else  {
      perror("getInputLine");
      exit(EXIT_FAILURE);
    }
  }

  return line;
}

#define tokenBuffSize 64
#define tokenDelim " \t\r\n\a"
char **splitupLine(char *line)
{
  int bufsize = tokenBuffSize, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, tokenDelim);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += tokenBuffSize;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, tokenDelim);
  }
  tokens[position] = NULL;
  return tokens;
}

int forkLaunch(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child proc
    if (execvp(args[0], args) == -1) {
      perror("error in execvp");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("error with pid");
  } else {
    // Parent proc
    do {
      //printf("$ ");
      wpid = waitpid(pid, &status, 0);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  wpid = wpid;
  return 1;
}

int execvpCommand(char **args)
{

  if (args[0] == NULL) {
    // Command Empty
    return 1;
  }
  return forkLaunch(args);
}

void shellLoop(void)
{
  char *line;
  char **args;
  int status;
  int statusLast;
  do {
    printf("$ ");
    
    line = getInputLine();
    args = splitupLine(line);
    fflush(stdout);
    status = execvpCommand(args);
    statusLast = status; 

    free(line);
    free(args);
  } while (status);
}


int main(int argc, char **argv) {
  //printf("Entered main function\n");

  // Run command loop.
  shellLoop();

  // Perform any shutdown/cleanup.

  return 0;
}

