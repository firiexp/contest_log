#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    while(cin >> n, n){
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            v[i] = s.size();
        }
        vector<int> u{5, 7, 5, 7, 7, 100000};
        for (int i = 0; i < n; ++i) {
            int cur = 0, p = 0;
            int valid = true;
            for (int j = i; j < n; ++j) {
                p += v[j];
                if(u[cur] == p) cur++, p = 0;
                else if(u[cur] < p) valid = false;
            }
            if(valid && cur == 5){
                cout << i+1 << "\n";
                break;
            }
        }
    }
    return 0;
}