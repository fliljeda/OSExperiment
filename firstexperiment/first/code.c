#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

char global[] = "This is a global string";
const int read_only = 123456;

void zot(unsigned long * stop){

    unsigned long r = 0x3;
    unsigned long k = 0x15;

    unsigned long *i;
    printf("i : %p\n", &i);
    for(i = &r; i <= stop; i++){
        printf(" %p     0x%lx\n", i, *i);
    }
}

void foo(unsigned long * stop){
    unsigned long q = 0x2;

    zot(stop);
}


int main(){
    int pid = getpid();
    unsigned long p = 0x1;
    //printf("   p: (0x%lx )   \n", (unsigned long)&p);

    foo(&p);

back:
    printf("    p: %p \n", &p);
    printf("    back: %p \n", &&back);

    printf("\n\n/proc/%d/maps \n\n", pid);
    char command[50];
    sprintf(command, "cat /proc/%d/maps", pid);
    system(command);

    return 0;
}
