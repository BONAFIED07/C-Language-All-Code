#include <stdio.h>

int incre(int *y) {
    *y = *y +1;
}

int main() {
    //int *a = 3;            Pointers should only point to memory allocated i.e variable not constants
    int x =3;
    int *a = &x;
    incre(a);                // while declaring pointer *a acts as address after that a act as address and *a acts as value
    printf("%d ", *a);       // passed address in incre and then take it with pointer and then increased value of it
 }
