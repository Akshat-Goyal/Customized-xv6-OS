#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

// Added sys_waitx call to load parameters and calling waitx
int
sys_waitx(void)
{
  int *wtime;
  int *rtime; 
  
  if(argptr(0, (char**)&wtime, sizeof(int)) < 0)
    return -1;

  if(argptr(1, (char**)&rtime, sizeof(int)) < 0)
    return -1;
  
  return waitx(wtime, rtime);
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

#ifdef PBS
int
sys_set_priority(void){
  int pid, pr;
  if(argint(0, &pid) < 0)
    return -1;
  if(argint(1, &pr) < 0)
    return -1;
  return set_priority(pid, pr);
}
#endif

#ifdef MLFQ
  int
  sys_getpinfo(void){
    int pid;
    struct proc_stat *stat;
    if(argint(0, &pid) < 0)
      return -1;
    if(argint(1, (int*)&stat) < 0)
      return -1;
    return getpinfo(pid, stat);
  }
#endif