#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main(){
    using A = array<int, 3>;
    int n;
    cin >> n;
    set<A> s;
    for (int i = 0; i < n; ++i) {
        A x;
        for (auto &&j : x) cin >> j;
        sort(x.begin(),x.end());
        s.emplace(x);
    }
    cout << n-s.size() << "\n";
    return 0;
}