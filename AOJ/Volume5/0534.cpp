#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n+4, -1);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i+2]);
    }
    v[0] = 100; v[n+3] = 100;
    int ans = 0;
    for (int i = 2; i <= n+1; ++i) {
        for (int j = 1; j <= 3; ++j) {
            int t = v[i];
            v[i] = j;
            int valid = 1, l = i, r = i, c = 0;
            while(valid){
                valid = 0;
                while(v[l-1] == v[l]) l--;
                while(v[r+1] == v[r]) r++;
                if(r-l+1-c >= 4){
                    valid = 1;
                    c += r-l+1-c;
                    l--; r++;
                }
                if(v[l] != v[r]) break;
            }
            v[i] = t;
            ans = max(ans, c);
        }
    }
    cout << n-ans << "\n";
    return 0;
}
