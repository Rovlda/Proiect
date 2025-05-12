#include <stdio.h>
#include <stdlib.h>

struct {
    char nume[100];
    double timp;
} p[100],aux;
int main() {
    int i,j;
    for (i=0;i<10;i++) {
        scanf("%s",p[i].nume);
        scanf("%lf",&p[i].timp);
    }
    for (i=0;i<9;i++) {
        for (j=i+1;j<10;j++) {
            if (p[i].timp<p[j].timp) {
                aux=p[i];
                p[i]=p[j];
                p[j]=aux;
            }
        }
    }
    for (i=0;i<10;i++) {
        printf("%s %d",p[i].nume,i+1);
        printf("\n");
    }

    return 0;
}