#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "param.h"
#include "pinfo.h"

int main(int argc, char *argv[]){
    if(argc < 3 || argc > 3 || strcmp("chpr", argv[0]) != 0){
        printf(2, "Usage: chpr [pid] [priority]\n");
        exit();
    }  
    #ifdef PBS
        int priority = 0, pid = 0, old_priority = 0;
        pid = atoi(argv[1]);
        priority = atoi(argv[2]);
        if(priority < 0 || priority > 100){
            printf(2, "Invalid priority (0, 100)!\n");
            exit();
        }
        old_priority = set_priority(pid, priority);
        if(old_priority == -1){
            printf(2, "Invalid pid\n");
        }
        else{
            printf(1, "Priority of pid %d is changed from %d to %d\n", pid, old_priority, priority);
        }
    #else
        printf(2, "Error: To change priority, change SCHEDULER to PRIORITY\n");
    #endif
    exit();  
}