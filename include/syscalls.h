#ifndef _SYSCALLS_H_
#define _SYSCALLS_H_

#include "sys.h"
#include "syscallnums.h"

// Notes:
// * xxxxram numbers are in pages, multiply them by PAGE_SIZE to get bytes
// * the commented fields are not (yet?) implemented, uncomment them as we go
typedef struct sysinfo_s {
    // uint32_t uptime;             // Seconds since boot
    // uint32_t loads[3];  // 1, 5, and 15 minute load averages
    uint32_t totalram;  // Total usable main memory size
    uint32_t freeram;   // Available memory size
    // uint32_t sharedram; // Amount of shared memory
    // uint32_t bufferram; // Memory used by buffers
    // uint32_t totalswap; // Total swap space size
    // uint32_t freeswap;  // Swap space still available
    uint32_t procs;    // Number of current processes
} sysinfo_t;

void sys_restart();
void sys_exit();
uint32_t sys_fork();
int32_t sys_read(uint32_t fd, char* buf, uint32_t bufsize);
void sys_write();
int32_t sys_wait();
uint32_t sys_execv();
uint32_t sys_getpid();
uint32_t sys_sysinfo();

// These are implemented in assembler as of now:
extern void prints();
extern void poweroff();

#endif // ifndef _SYSCALLS_H_
