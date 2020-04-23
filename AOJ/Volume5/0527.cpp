#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    while (cin >> n, n){
        stack<pair<int, int>> v;
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            if(i % 2 == 0){
                if(v.empty()){
                    v.emplace(k, 1);
                }else {
                    auto x = v.top(); v.pop();
                    if(x.first == k){
                        v.emplace(k, x.second + 1);
                    }else {
                        v.emplace(x);
                        v.emplace(k, 1);
                    }
                }
            } else if (i % 2 == 1 && k == v.top().first){
                auto x = v.top(); v.pop();
                if(x.first == k){
                    v.emplace(k, x.second + 1);
                }else {
                    v.emplace(x);
                    v.emplace(k, 1);
                }
            } else if((i % 2 == 1 && k != v.top().first && v.size() <= 1)) {
                auto x = v.top(); v.pop();
                v.emplace(k, x.second+1);
            }else {
                auto x = v.top(); v.pop();
                auto y = v.top(); v.pop();
                v.emplace(k, x.second+y.second+1);
            }
        }
        int ans = 0;
        while(!v.empty()){
            ans += (1-v.top().first)*v.top().second; v.pop();
        }
        cout << ans << "\n";
    }

    return 0;
}
