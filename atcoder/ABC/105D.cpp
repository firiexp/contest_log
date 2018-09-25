#include <iostream>
#include <array>
#include <vector>
#include <map>

using ll = long long;
using namespace std;

int main() {
    map<int, int> M;
    int n, m, k, p = 0;
    ll c = 0;
    cin >> n >> m;
    M[0] = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        p = (p + k)%m;
        c += M[p];
        M[p]++;
    }
    cout << c << "\n";
    return 0;
}
