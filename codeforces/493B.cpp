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
    vector<int> va, vb;
    ll s = 0;
    int y = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if(x > 0) va.emplace_back(x);
        else vb.emplace_back(-x);
        y = x;
        s += x;
    }
    if(s != 0) {
        cout << (s > 0 ? "first" : "second") << "\n";
    } else if(va == vb) {
        cout << (y > 0 ? "first" : "second") << "\n";
    }else {
        cout << (va > vb ? "first" : "second") << "\n";
    }
    return 0;
}
