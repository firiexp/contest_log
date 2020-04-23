#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    string s;
    cin >> s;
    array<int, 26> ar{};
    for (auto &&i : s) {
        ar[i-'a']++;
    }
    ll cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 26; ++i) {
        cnt1 += ar[i]/2;
        cnt2 += ar[i]%2;
    }
    cnt1 *= 2;
    if(cnt2) cnt1++, cnt2--;
    cout << cnt1*cnt1+cnt2 << "\n";
    return 0;
}
