#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "param.h"
#include "pinfo.h"

int main(int argc, char *argv[]){

    #ifdef MLFQ
        if(argc != 2){
            printf(2, "Usage: ps <pid>\n");
            exit();
        }
        int pid = atoi(argv[1]);
        struct proc_stat stat;
        if(getpinfo(pid, &stat) == -1){
            printf(2, "Error: Wrong pid\n");
        }
        else{
            printf(1, "pid %d    runtime %d    num_run %d    current_queue %d\n", stat.pid, stat.runtime, stat.num_run, stat.current_queue);
            for(int i = 0; i < NPQ; i++){
                printf(1, "ticks%d: %d      ", i, stat.ticks[i]);
            }
            printf(1, "\n");
        }
    #else   
        printf(2, "Error: ps is for MLFQ Scheduler\n");
    #endif
    exit();
}