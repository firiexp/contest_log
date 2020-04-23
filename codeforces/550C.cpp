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
    string s;
    cin >> s;
    s = '0' + s;
    s = '0' + s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                string t;
                t += s[i];
                t += s[j];
                t += s[k];
                int tt = stoi(t);
                if(tt%8 == 0){
                    puts("YES");
                    cout << tt << "\n";
                    return 0;
                }
            }
        }
    }
    puts("NO");
    return 0;
}