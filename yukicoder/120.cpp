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
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        map<int, int> m;
        for (int j = 0; j < n; ++j) {
            int k;
            cin >> k;
            m[k]++;
        }
        priority_queue<int> w;
        for (auto &&l : m) {
            w.emplace(l.second);
        }
        int ans = 0;
        while(w.size() >= 3){
            int a = w.top(); w.pop();
            int b = w.top(); w.pop();
            int c = w.top(); w.pop();
            if(a != 1) w.emplace(a-1);
            if(b != 1) w.emplace(b-1);
            if(c != 1) w.emplace(c-1);
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
