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
    string s, t, u;
    cin >> s >> t >> u;
    int a = static_cast<int>(s.size() & 1 ? (s.size() + 1) / 2 : 0);
    int b = static_cast<int>(t.size() & 1 ? (t.size() + 1) / 2 : 0);
    int c = static_cast<int>(u.size() & 1 ? (u.size() + 1) / 2 : 0);
    cout << (16-a)*(16-a)*(16-b)*(16-b)*(16-c)*(16-c) << "\n";
    return 0;
}
