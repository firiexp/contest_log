#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    string s;
    cin >> n >> s;
    stack<int> S;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if(s[i] == '(') S.emplace(i);
        else {
            ans[S.top()] = i+1;
            ans[i] = S.top()+1;
            S.pop();
        }
    }
    for (auto &&i : ans) printf("%d\n", i);
    return 0;
}
