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
    int n, k;
    cin >> n >> k;
    int x = 0, s = 0;
    vector<int> v(50, 0);
    while(n){
        v[x]+=(n%2);
        s += (n%2);
        n /= 2;
        x++;
    }
    for (int i = 49; i >= 1; --i) {
        if(s >= k) break;
        if(v[i] == 0) continue;
        while(v[i] && s < k){
            v[i]--;
            v[i-1] += 2;
            s++;
        }
    }
    if(s != k){
        puts("NO");
    }else {
        puts("YES");
        int z = 1, p = 0;
        for (int i = 0; i < 50; ++i) {
            for (int j = 0; j < v[i]; ++j) {
                if(p) printf(" ");
                cout << z;
                p++;
            }
            z *= 2;
        }
    }
    return 0;
}
