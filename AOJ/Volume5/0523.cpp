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
    while(cin >> n, n){
        vector<int> v, u;
        map<int, int> m, m2;
        for (int i = 0; i < n; ++i) {
            int k;
            scanf("%d", &k);
            v.emplace_back(k);
            m[k]++;
        }
        for (int i = 1; i <= 2*n; ++i) {
            if(!m[i]) {
                u.emplace_back(i);
                m2[i]++;
            }
        }
        sort(u.begin(), u.end());
        int t = 0, x = 0, p = n, q = n;
        while(p && q){
            int z = 0;
            if(t == 0) {
                for (int i = x+1; i <= 2*n; ++i) {
                    if(m[i]) {
                        p--;
                        m[i]--;
                        x = i;
                        z = 1;
                        break;
                    }
                }
                if(!z) x = 0;
            }else {
                for (int i = x+1; i <= 2*n; ++i) {
                    if(m2[i]) {
                        q--;
                        m2[i]--;
                        x = i;
                        z = 1;
                        break;
                    }
                }
                if(!z) x = 0;
            }
            t ^= 1;
        }
        cout << q << "\n" << p << "\n";
    }

    return 0;
}
