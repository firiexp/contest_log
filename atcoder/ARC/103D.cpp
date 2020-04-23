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
    cin >> n;
    vector<pair<ll, ll>> v;
    ll k = INF<ll>;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        if(k == INF<ll>) k = x+y;
        else if((k+INF<ll>)%2 != (x+y+INF<ll>)%2){
            puts("-1");
            return 0;
        }
        v.emplace_back(x, y);
    }
    vector<ll> nums;
    for (int j = 0; j < 37; ++j) {
        nums.emplace_back(1LL << (36-j));
    }
    if((k+INF<ll>)%2==1) nums.emplace_back(1);
    cout << nums.size() << "\n";
    for (int i = 0; i < nums.size(); ++i) {
        if(i) cout << " ";
        cout << nums[i];
    }
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        ll xx, yy;
        tie(xx, yy) = v[i];
        ll x = xx+yy, y = xx-yy;
        string s;
        for (auto &&d : nums) {
            if(x < 0 && y < 0) x += d, y += d, s += "L";
            else if(x >= 0 && y >= 0) x -= d, y -= d, s += "R";
            else if(x < 0 && y >= 0) x += d, y -= d, s += "D";
            else x -= d, y += d, s += "U";
        }
        cout << s << "\n";
    }
    return 0;
}
