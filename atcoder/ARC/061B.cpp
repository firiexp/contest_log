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
using P = pair<int, int>;
template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    map<P, int> v;
    vector<ll> v2(10, 0);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j <= 2; ++j) {
            for (int k = 0; k <= 2; ++k) {
                if(a-j>=1 && b-k>=1 && a-j+2 <= h && b-k+2 <= w){
                    v[make_pair(a-j, b-k)]++;
                }
            }
        }
    }
    for (auto &&a : v) {
        v2[a.second]++;
    }
    ll k = (ll)(h-2)*(w-2);
    for (int i = 1; i <= 9; ++i) {
        k -= v2[i];
    }
    v2[0] = k;
    for (auto &&item : v2) {
        cout << item << "\n";
    }
    return 0;
}
