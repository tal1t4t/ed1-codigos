#include <stdio.h>
#include <stdlib.h>

int main(){

    int num, *pnum;

    pnum = &num;

    printf("%p\n", pnum);
    printf("%p\n", &num);

    printf("%p\n", &pnum);
    return 0;
}