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

template<typename T>
int gauss_jordan(vector<T> &a){
    int n = a.size(), m = sizeof(T)*8;
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
    a.erase(a.begin()+cnt, a.begin()+n);
    return cnt;
}

template <class T>
T pow_ (T x, T n, T M){
    uint64_t u = 1, xx = x;
    while (n > 0){
        if (n&1) u = u * xx % M;
        xx = xx * xx % M;
        n >>= 1;
    }
    return static_cast<T>(u);
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int x = gauss_jordan(v);
    v.emplace_back(k);
    int y = gauss_jordan(v);
    if(x != y) {
        puts("0");
        return 0;
    }else {
        cout << pow_(2, n-x, MOD) << "\n";
    }
    return 0;
}
