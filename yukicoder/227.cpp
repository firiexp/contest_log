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
    map<int, int> m;
    string s = "NO HAND";
    int p = 0, q = 0;
    for (int i = 0; i < 5; ++i) {
        int k;
        cin >> k;
        m[k]++;
    }
    for (auto &&j : m) {
        if(j.second == 2) p++;
        if(j.second == 3) q++;
    }
    if(p == 1) s = "ONE PAIR";
    if(p == 2) s = "TWO PAIR";
    if(q == 1) s = "THREE CARD";
    if(q == 1 && p == 1) s = "FULL HOUSE";
    cout << s << "\n";
    return 0;
}
