# REQUIREMENTS

+ linux shell
+ qemu


# RUNNING

+ `SCHEDULER` can be `DEFAULT`, `PBS`, `FCFS`, `MLFQ`
+ run `make clean qemu SCHEDULER=DEFAULT`.


# FUNCTIONS IMPLEMENTED

## TASK 1

### WAITX SYSCALL:
+ Syscall waitx is implemented. 
+ It is used to get total waittime and runtime of process.
+ Using Terminal we can access this syscall via 'time' command
+ time takes a command as an argument and prints the runtime and waitime of that command using waitx on the terminal.
c
						time <command>


### GETPINFO SYSCALL:
+ Syscall detpinfo is implemented. 
+ It is used to get information of a process like runtime,num_run, current_queue , ticks in different queues.
+ It will be used in case of multi level feedback queue scheduling.
+ Using Terminal we can access this syscall via 'info' command
+ info takes pid as an argument and prints the info of the process corresponding to the pid  on the terminal.
c
						ps <pid>


## TASK 2

### FCFS SCHEDULING:
+ First in, first out (FIFO), also known as first come, first served (FCFS), is the simplest scheduling algorithm. 
+ FIFO simply queues processes in the order that they arrive in the ready queue.
+ No preemption is allowed.
+ In this, the process that comes first will be executed first and next process starts only after the previous gets fully executed.
+ To change the default scheduling to FCFS , run the make in the following way:
c
				make clean qemu-nox SCHEDULER=FCFS


### PRIORITY BASED SCHEDULING:
+ Priority scheduling is a preemptive algorithm.
+ Each process is assigned a priority. Process with highest priority (numerically least) is to be executed first and so on.
+ Processes with same priority are executed on first come first served basis.
+ If a process of higher priority(numerically less) arrives while a lower priority process is being executed the lower priority process is preempted.
+ To change the default scheduling to PBS , run the make in the following way: 
c
				make clean qemu-nox SCHEDULER=PBS


#### SET_PRIORITY SYSCALL
+ Syscall set_priority is implemented. 
+ It is used to change the priority of a process.
+ Using Terminal we can access this syscall via 'chngpr' command
+ chngpr takes pid of the process and the new priority  as an argument and prints the old priority on the terminal.
c
				chpr <pid> <new_priority>


### MULTILEVEL FEEDBACK QUEUE SCHEDULING:
+ Multilevel feedback queue scheduling, processes are initially assigned the 0th queue out of total 5 queues.
+ It allows a process to move between queues. If a process uses too much CPU time, it will be moved to a lower-priority queue. Similarly, a process that waits too long in a lower-priority queue may be moved to a higher-priority queue. This form of aging prevents starvation.
+ To change the default scheduling to MLFQ , run the make in the following way:
c
			make clean qemu-nox SCHEDULER=MLFQ