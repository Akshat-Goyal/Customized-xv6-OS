#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int main(int argc, char *argv[]) {
    int pid, n = 8, limit = 3e8;
    double x = 0, z;
    x = 0;
    pid = 0;
    for (int k = 0; k < n; k++) {
        pid = fork();
        if (pid < 0) {
            printf(1, "%d failed in fork!\n", getpid());
        }
        if (pid == 0) {  // child
            for (z = 0; z < limit; z += 1)
                x = x +
                    3.14 * 89.64;  // useless calculations to consume CPU time
            exit();
        }
    }
    for (int k = 0; k < n; k++) {
        wait();
    }

    exit();
}