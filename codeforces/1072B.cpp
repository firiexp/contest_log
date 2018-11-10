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
    vector<int> va(n-1), vb(n-1);
    for (auto &&i : va) scanf("%d", &i);
    for (auto &&i : vb) scanf("%d", &i);
    for (int i = 0; i <= 3; ++i) {
        vector<int> v(n, -1);
        v[0] = i;
        for (int j = 0; j < n - 1; ++j) {
            for (int k = 0; k <= 3; ++k) {
                if(((v[j]|k) == va[j]) && ((v[j]&k) == vb[j])) v[j+1] = k;
            }
            if(v[j+1] == -1) break;
        }
        if(v[n-1] != -1){
            cout << "YES\n";
            for (int x = 0; x < n; ++x) {
                if(x) printf(" ");
                printf("%d", v[x]);
            }
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
