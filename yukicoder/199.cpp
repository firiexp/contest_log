#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

int main() {
    vector<int> A(4), B(4);
    int n, c = 0, x = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> B[j];
    }
    sort(A.begin(), A.begin()+n);
    sort(B.begin(), B.begin()+n);
    do {
        do{
            x++;
            int a = 0, b = 0;
            for (int i = 0; i < n; ++i) {
                if (A[i] > B[i]) a++;
                else if (B[i] > A[i]) b++;
            }
            if(a > b) c++;
        }while (next_permutation(B.begin(), B.begin()+n));
    }while(next_permutation(A.begin(), A.begin()+n));
    cout << ((double)c)/x << "\n";
    return 0;
}
