#include <iostream>
using ll = long long;
using namespace std;

/* initialize */
struct card{
    char suit;
    int value;
};
card A[100000];
card L[60000], R[60000];
/* main */

int partition(card A[],int p,int r);


int quicksort(card A[], int p, int r) {
    if (p < r){
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }

}

int partition(card A[], int p, int r) {
    card temp{};
    card x = A[r];
    int i = p-1;
    for (int j = p; j < r; j++) {
        if (A[j].value <= x.value){
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;
    return i+1;
}

void merge(card A[],int left, int right){
    int mid = (left + right) / 2;
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; ++i)  L[i] = A[left+i];
    for (int j = 0; j < n2; ++j) R[j] = A[mid+j];
    L[n1].value = R[n2].value = INT32_MAX;
    int i = 0, j = 0;
    for ( int k = left; k < right; k++ ){
        if (L[i].value <= R[j].value) A[k] = L[i++];
        else A[k] = R[j++];
    }
}

void mergeSort(card A[], int n, int left, int right){
    if(left+1 < right){
        mergeSort(A, n, left,(left+right)/2);
        mergeSort(A, n, (left+right)/2, right);
        merge(A, left, right);
    }
}

int main() {
    int v;
    card A[100000], B[100000];
    char S[10];
    int stable = 1, n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%s %d" , S, &v);
        A[i].suit = B[i].suit = S[0];
        A[i].value = B[i].value = v;
    }

    quicksort(B, 0, n-1);
    mergeSort(A, n, 0, n);


    for (int i = 0; i < n; ++i) {
        if (A[i].suit != B[i].suit) stable = 0;
    }
    if (stable) printf("Stable\n"); else printf("Not stable\n");
    for (int j = 0; j < n; j++) {
        printf("%c %d\n", B[j].suit, B[j].value);
    }
    return 0;
}