#include "../csapp.h"

static char *mem_heap;
static char *mem_brk;
static char *mem_max_addr;

static size_t MAX_HEAP = 8192;

void mem_init(void)
{
    mem_heap = (char *)Malloc(MAX_HEAP);
    mem_brk = (char *)mem_heap;
    mem_max_addr = (char *)(mem_heap + MAX_HEAP);
}

void *mem_sbrk(int incr)
{
    char *old_brk = mem_brk;

    if ( (incr < 0) || ((mem_brk + incr) > mem_max_addr)) {
        errno = ENOMEM;
        fprintf(stderr, "ERROR: mem_sbrk failed\n");
        return (void *)-1;
    }
    mem_sbrk += incr;
    return (void *)old_brk;
}