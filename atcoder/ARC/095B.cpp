#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>

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
    sort(v.begin(), v.end());
    int a = v[n-1], b = 0;
    for (int j = 1; j < n-1; ++j) {
        if(fabs(a/2.0-v[j]) < fabs(a/2.0-v[b])) b = j;
    }
    cout << a << " " << v[b] << "\n";
    return 0;
}
