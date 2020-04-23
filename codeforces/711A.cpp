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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        if(v[i][0] == 'O' && v[i][1] == 'O'){
            v[i][0] = v[i][1] =  '+';
            puts("YES");

            for (int j = 0; j < n; ++j) {
                cout << v[j] << "\n";
            }
            return 0;
        }
        if(v[i][3] == 'O' && v[i][4] == 'O'){
            v[i][3]= v[i][4] =  '+';
            puts("YES");
            for (int j = 0; j < n; ++j) {
                cout << v[j] << "\n";
            }
            return 0;
        }
    }
    puts("NO");
    return 0;
}
