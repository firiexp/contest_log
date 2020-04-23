#include <iostream>
#include <array>

using ll = long long;
using namespace std;

int main() {
    array<int, 1001> A{};
    fill(A.begin(), A.end(), 10000);
    A[0] = 0;
    int a[6] = {500, 100, 50, 10, 5, 1};
    for (int i = 0; i < 1001; ++i) {
        for (auto &&v : a) {
            if (v <= i) {
                A[i] = min(A[i-v]+1, A[i]);
                break;
            }
        }
    }
    int n;
    while(cin>>n, n) {
        cout << A[1000 - n] << "\n";
    }
    return 0;
}
