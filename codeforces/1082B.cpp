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
    string s;
    cin >> n >> s;
    using P = pair<int, int>;
    vector<P> v;
    int x = -1;
    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == 'S'){
            if(x != -1){
                v.emplace_back(x, i-1);
                ans = max(ans, i-x);
                x = -1;
            }
        }else {
            if(x == -1) x = i;

        }
    }
    if(x != -1) {
        v.emplace_back(x, n-1);
        ans = max(ans, n-x);
    }

    if(!v.empty()) for (int i = 0; i < v.size()-1; ++i) {
        if(v[i+1].first-v[i].second == 2 ){
            if(v.size() >= 3) ans = max(ans, v[i+1].second-v[i].first+1);
            else ans = max(ans, v[i+1].second-v[i].first);
        }else {
            ans = max(ans, v[i].second-v[i].first+2);
            ans = max(ans, v[i+1].second-v[i+1].first+2);
        }
    }
    cout << ans << "\n";
    return 0;
}
