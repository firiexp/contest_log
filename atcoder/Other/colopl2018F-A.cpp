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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> v;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'A') {
            int streak = 1;
            for (int j = i + 1; j < s.length(); ++j) {
                i = j+1;
                if (s[j] == 'A') streak++;
                else {i = j; break;}
            }
            v.emplace_back(streak);
        }
    }
    ll ans = 0;
    if(s[s.length()-1] != 'A' || s[0] != 'A' || n == 1){
        for (auto &&a : v) {
            ans += a*(a+1)/2*n;
        }
    }else {
        if(v.size() == 1){
            ans += (v[0]*n)*(v[0]*n+1)/2;
        }
        else {
            for (int i = 1; i < v.size() - 1; ++i) {
                ans += v[i] * (v[i] + 1) / 2 * n;
            }
            ans += v[0]*(v[0]+1)/2;
            ans += v[v.size()-1] * (v[v.size()-1]+1)/2;
            ans += (v[0]+v[v.size()-1])*(v[0]+v[v.size()-1]+1)/2*(n-1);
        }
    }
    cout << ans << "\n";
    return 0;
}
