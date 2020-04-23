#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

vector<ll> gauss_jordan(vector<ll> a){
    int n = a.size(), m = 64;
    int cnt = 0;
    for (int i = 0; i < m && cnt != n; ++i) {
        int p = cnt;
        for (int j = cnt; j < n; ++j) {
            if(a[j] & (1LL << i)){
              p = j;
              break;
            }
        }
        if((a[p] & (1LL << i)) == 0) continue;
        swap(a[cnt], a[p]);
        for (int j = 0; j < n; ++j) {
            if(cnt == j) continue;
            if(a[j] & (1LL << i)) a[j] ^= a[cnt];
        }
        cnt++;
    }
    return a;
}


int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &&i : a) scanf("%lld", &i);
    for (auto &&i : b) scanf("%lld", &i);
    puts(gauss_jordan(a) == gauss_jordan(b) ? "Yes" : "No");
    return 0;
}
