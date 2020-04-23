#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    for (int i = 1; i <= 2*n-4; ++i) {
        for (int j = 0; j <= i; ++j) {
            if(j < i-j && j < n && i-j < n && v[j] > v[i-j]) swap(v[j], v[i-j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if(i) cout << " ";
        cout << v[i];
    }
    cout << "\n";
    return 0;
}
