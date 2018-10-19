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
    vector<int> ans(n, 0);
    for (int i = 0; i < (n+5)/6; ++i) {
        int l = i*6, r = min((i+1)*6, n)-1;
        int p = 1;
        cout << "?";
        for (int j = 0; j < n; ++j) {
            if(l <= j && j <= r){
                cout << " " << p;
                p *= 5;
            }else {
                cout << " 0";
            }
        }
        cout << endl;
        int q;
        cin >> q;
        q -= (p-1)*2;
        for (int j = l; j <= r; ++j) {
            ans[j] = q%5%2;
            q /= 5;
        }
    }
    cout << "!";
    for (int i = 0; i < n; ++i) {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}
