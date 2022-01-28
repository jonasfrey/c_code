
// c file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


#include <wait.h>

void how_many_forks()
{
    printf("\n before fork");
    fork();
    fork();
    fork();
    printf("\n after fork");
}

void child_and_parent_process()
{

    int n_id = fork();
    int n_child_process_id = 0; // the child process has always id 0

    if (n_id == n_child_process_id)
    {
        printf("\n child process");
    }
    else
    {
        printf("\n parent process");
    }

    printf("\n printf hello from id: %i", n_id);
}

int fork_and_wait(){
    
    int n_pid = fork();
    if(!n_pid){
        // child process 
        sleep(4);
        printf("\n %*s: %*i", 20, "n_pid", 30, n_pid);
        printf("\n process finished");
        fflush(stdout);
        return 0; 
    }
    int n_pid2 = fork();
    if(!n_pid2){
        // child process
        sleep(3);
        printf("\n %*s: %*i", 20, "n_pid2", 30, n_pid2);
        printf("\n process finished");
        fflush(stdout);
        return 0;
    }

    printf("\n");

    int pid1_return = waitpid(n_pid, NULL, 0);
    printf("pid1_return %i \n", pid1_return);


    int pid2_return = waitpid(n_pid2, NULL, 0);
    printf("pid2_return %i \n", pid2_return);


    // int pid1_return = waitpid(n_pid, NULL, WNOHANG);
    // printf("pid1_return %i \n", pid1_return);


    // int pid2_return = waitpid(n_pid2, NULL, WNOHANG);
    // printf("pid2_return %i \n", pid2_return);
    
    return 0;
}

void double_fork()
{
    // this functions shows, that when you fork twice
    // the programm will run 4 times

                                                                        // processes |

    fflush(stdout);

    int n_process_id = fork();                                          // processes | |

    printf("\n %*s: %*s", 20, "scope", 30, __func__);
    printf("\n %*s: %*i", 20, "n_process_id", 30, n_process_id);

    int n_process_id2 = fork();                                         // processes | | | |
    printf("\n %*s: %*s", 20, "scope", 30, __func__);
    printf("\n %*s: %*i", 20, "n_process_id2", 30, n_process_id2);

    printf("\n programm end \n");
}

void simple_fork()
{
    fflush(stdout);
    // this function shows that when you fork the process,
    // the child process with id 0, will start after the fork() function is called!
    int n_process_id = fork();
    
    printf("\n %*s: %*s",20, "scope", 30, __func__);
    printf("\n %*s: %*i",20,"n_process_id", 30, n_process_id);

    printf("\n programm end \n");
}

void external_function()
{
    printf("main called\n");
    int cid = fork();
    printf("\nprogramm end");
    // int cid2 = fork();
    if (cid)
    {
    }
}


void fork_without_newlines(){
    printf(" - main called - ");
    fork();
    printf(" - after fork - ");
}

void fork_without_newlines_fflush(){
    printf(" - main called - ");
    fflush(stdout);
    fork();
    printf(" - after fork - ");
    fflush(stdout);
}
void fork_with_newlines()
{
    printf(" - main called - \n");
    fork();
    printf(" - after fork - \n");
}

void important_fflush(){
// this function shows that it is important 
// to use fflush after a printf if no newline 
// is used in the string 

// if we call
//      fork_without_newlines(); 
// one could think, fork starts the child process from the main function
// since the console output is:
//      - main called -  - after fork -  - main called -  - after fork - 

// this is because the printf will only print when the buffer is full or a newline is encountered, 
// hence, the - main called - content is copied to the child process printf buffer, so it will also print
// - main called - - after fork -


// if we call 
//      fork_without_newlines_fflush();
// the output will look ok like, 
//      - main called -  - after fork -  - after fork - 
// because printf() has no "leftover" text

}

int main()
{

    //important_fflush();
    
    printf("\n %*s: %*s",20, "scope", 30, __func__);

    //simple_fork();

    // double_fork();

    return fork_and_wait();

    return 0;
}
