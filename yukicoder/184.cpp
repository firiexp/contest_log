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
int gauss_jordan(vector<T> a){
    int n = a.size(), m = 8*sizeof(T);
    int cnt = 0;
    for (int i = 0; i < m && cnt != n; ++i) {
        int p = cnt;
        for (int j = cnt; j < n; ++j) {
            if(a[j] & (static_cast<T>(1) << i)){
              p = j;
              break;
            }
        }
        if((a[p] & (static_cast<T>(1) << i)) == 0) continue;
        swap(a[cnt], a[p]);
        for (int j = 0; j < n; ++j) {
            if(cnt == j) continue;
            if(a[j] & (static_cast<T>(1) << i)) a[j] ^= a[cnt];
        }
        cnt++;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<short> v(n);
    for (auto &&i : v) scanf("%hi", &i);
    cout << (1 << (gauss_jordan(v))) << "\n";
    return 0;
}
