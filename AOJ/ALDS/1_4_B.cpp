#include <iostream>
using ll = long long;
using namespace std;

int binarysearch(int A[], int n, int key){
    int left = 0;
    int right = n;
    int mid;
    while (left < right){
        mid = (left + right)/2;
        if (A[mid] == key) return 1;
        else if (key > A[mid]) left = mid + 1;
        else if (key < A[mid]) right = mid;
    }
    return 0;
}

int main() {
    int n, q, key, sum=0;
    cin >> n;
    int V[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &V[i]);
    }
    cin >> q;
    for (int j = 0; j < q; ++j) {
        scanf("%d", &key);
        sum += binarysearch(V, n, key);
    }
    cout << sum << "\n";
    return 0;
}