#include    <stdio.h>
#define MaxNum 10000

int checkPrime(int num) {
    int i;

    for (i=3; i<num; i+=2) {
        if (num % i==0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int j;

    printf("2 ");
    for(j=3; j<=MaxNum; j+=2) {
        if (checkPrime(j) == 1) {
            printf("%d ", j);
        }
    }
}

