#include <stdio.h>
#define MAX_SIZE 1000

void combSort(int a[], int n);
void swap(int* a, int* b);

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i) {
        int num;
        int a[MAX_SIZE];
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
            scanf("%d", &a[j]);
        combSort(a, num);
    }
    return 0;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void combSort(int a[], int n) {
    int countCmpOps = 0; 
    int countSwaps = 0; 
    int gap = n;
    float shrink = 1.3;
    bool isSorted = false;

    while(!isSorted){
        gap = int(gap / shrink);
        if(gap <= 1){
            gap = 1;
            isSorted = true;
        }

        for(int i=0; i<n-gap; i++){
            countCmpOps++;
            if(a[i] > a[i+gap]){
                swap(&a[i], &a[i+gap]);
                countSwaps++;
                isSorted = false;
            }
        }
    }
    
    printf("%d %d\n", countCmpOps, countSwaps);
}
