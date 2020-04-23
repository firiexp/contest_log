#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;



void solve(int val, int x, vector<int> &state){

}
int main() {
    int n;
    cin >> n;
    vector<int> v(n), ans;
    for (auto &&i : v) scanf("%d", &i);
    vector<int> state(n);
    auto rec = [&](auto &&f, int val, int cur, vector<int> &state) -> void {
        while(cur < n && state[cur] == 1) cur++;
        if(cur == n) {
            ans.emplace_back(val);
            return;
        }

        state[cur] = 1;
        for (int i = cur+1; i < n; ++i) {
            if(state[i]) continue;
            state[i] = 1;
            f(f, val^(v[cur]+v[i]), cur+1+(i == cur+1), state);
            state[i] = 0;
        }
        state[cur] = 0;
    };
    rec(rec, 0, 0, state);
    cout << *max_element(ans.begin(),ans.end()) << "\n";
    return 0;
}