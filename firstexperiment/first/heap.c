#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

char global[] = "This is a global string";
const int read_only = 123456;


int main(){
    int pid = getpid();
    //char * heap = malloc(20);
    //*heap = 0x61;
    //printf("heap pointing to: 0x%x\n", *heap);
    //free(heap);

    //char *foo = malloc(20);
    //*foo = 0x62;

    long * heap = (unsigned long*) calloc(10, sizeof(unsigned long));

    printf("heap[2]:    0x%lx\n", heap[2]);
    printf("heap[1]:    0x%lx\n", heap[1]);
    printf("heap[0]:    0x%lx\n", heap[0]);
    printf("heap[-1]:    0x%lx\n", heap[-1]);
    printf("heap[-2]:    0x%lx\n", heap[-2]);

    free(heap);

    printf("heap[2]:    0x%lx\n", heap[2]);
    printf("heap[1]:    0x%lx\n", heap[1]);
    printf("heap[0]:    0x%lx\n", heap[0]);
    printf("heap[-1]:    0x%lx\n", heap[-1]);
    printf("heap[-2]:    0x%lx\n", heap[-2]);

    printf("\n\n/proc/%d/maps \n\n", pid);

    char command[50];
    sprintf(command, "cat /proc/%d/maps", pid);
    system(command);
    return 0;
}
