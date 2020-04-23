#include <iostream>
#include <array>

using ll = long long;
using namespace std;

int main() {
    array<int, 101> A = {};
    fill(A.begin()+1, A.end(), 10000);
    int n;
    cin >> n;
    int B[2] = {4, 7};
    for (int i = 1; i < 101; ++i) {
        for (auto &&b : B) {
            if(b <= i && A[i-b] != 10000){
                A[i] = min(A[i-b] + 1, A[i]);
            }
        }
    }

    cout << (A[n] < 10000 ? "Yes" : "No") << "\n";
    return 0;
}
