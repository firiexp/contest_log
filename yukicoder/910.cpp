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

int main() {
    ll n; string s;
    cin >> n >> s;
    vector<ll> cnt(11);
    ll ans = 0;
    deque<int> a;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '1') a.emplace_back(i);
        else if(s[i] == '9'){
            if(!a.empty()){
                ans++;
                s[i] = '2';
                s[a.front()] = '2';
                a.pop_front();
            }
        }
        else cnt[s[i]-'0']++;
    }
    for (int i = 0; i < n; ++i) {
        if(s[i] == '1'){
            if(cnt[9] >= 2){
                ans++;
                cnt[9] -= 2;
                cnt[1]--;
            }
        }
        if(s[i] == '1' || s[i] == '9') cnt[s[i] - '0']++;
    }
    cout << ans+cnt[3]+cnt[5]+cnt[7]+(cnt[1]/2) << "\n";
    return 0;
}