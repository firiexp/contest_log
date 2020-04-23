#include <iostream>
using ll = long long;
using namespace std;

/* initialize */
int n, A[500000], L[300000], R[300000], count = 0;
/* main */
ll merge(int A[],int left, int right){
    ll c = 0;
    int mid = (left + right) / 2;
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; ++i)  L[i] = A[left+i];
    for (int j = 0; j < n2; ++j) R[j] = A[mid+j];
    L[n1] = R[n2] = INT32_MAX;
    int i = 0, j = 0;
    for ( int k = left; k < right; k++ ){
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        }
        else {
            A[k] = R[j++];
            c += n1 - i;
        }
    }
    return c;
}

ll mergeSort(int A[], int n, int left, int right){
    if(left+1 < right){
        ll v1 = mergeSort(A, n, left,(left+right)/2);
        ll v2 = mergeSort(A, n, (left+right)/2, right);
        ll v3 = merge(A, left, right);
        return v1+v2+v3;
    }
    return 0;
}

/* main */
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];
    ll ans = mergeSort(A, n, 0, n);
    cout << ans << "\n";
    return 0;
}