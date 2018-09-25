#include <iostream>
#include <numeric>
using ll = long long;
using namespace std;

int main() {
    int N, m, n = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> m;
        n += m - 1;
    }
    cout << n;

    return 0;
}