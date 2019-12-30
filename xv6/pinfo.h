#ifdef MLFQ
    struct proc_stat{
        int pid;
        long long int runtime;
        long long int num_run;
        int current_queue;
        long long int ticks[NPQ];
    };
#endif