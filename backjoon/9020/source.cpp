#include <stdio.h>

int main ()
{
    int sieve[11111] = { 0, };
    for (int i = 2; i <= 5000; i++) {
       if (sieve[i] == 1) {
           continue;
       }
       int k = 2;
       while (i * k <= 10000) {
           sieve[i * k] = 1;
           k++;
       }
    }
    int T;
    scanf("%d", &T);
    for (int i=0; i<T; i++) {
        int N;
        scanf("%d", &N);
        for (int j = N/2; j >= 2; j--) {
            if (sieve[j] == 0 && sieve[N-j] == 0) {
                printf("%d %d\n", j, N-j);
                break;
            }
        }
    }

    return 0;
}
