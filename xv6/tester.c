#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char *argv[]){

    int child = 0, limit = 3e7, ppid = 0;
    double z = 0, x = 0;
    if(argc != 2)
        child = 10;
    else
        child = atoi(argv[1]);

    #if defined FCFS || defined MLFQ || defined DEFAULT
        for(int j = 0; j < child; j++){
            ppid = fork();
            if(ppid == 0){
                for (z = 0; z < limit; z += 1)
                    x = x +
                        3.14 * 89.64;  // useless calculations to consume CPU time
                exit();
            }
            else if(ppid < 0){
                printf(1, "%d failed in fork!\n", getpid());
            }
        }
        for(int i = 0; i < child; i++){
            wait();
        }
    #elif PBS
        for(int j = 0; j < child; j++){
            ppid = fork();
            if(ppid == 0){
                int pid = getpid();
                for (z = 0; z < limit/2; z += 1)
                    x = x +
                        3.14 * 89.64;  // useless calculations to consume CPU time
                set_priority(pid, 100 - pid/2);
                for (z = 0; z < limit/2; z += 1)
                    x = x +
                        3.14 * 89.64;  // useless calculations to consume CPU time
                exit();
            }
            else if(ppid < 0){
                printf(1, "%d failed in fork!\n", getpid());
            }
        }
        for(int i = 0; i < child; i++){
            wait();
        }
    #endif

    exit();
}