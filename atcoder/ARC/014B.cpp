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
    map<string, int> m;
    string t;
    cin >> t;
    m[t]++;
    for (int i = 0; i < n-1; ++i) {
        string s;
        cin >> s;
        if(m[s] || *t.rbegin() != *s.begin()){
            puts(i%2 ? "LOSE" : "WIN");
            return 0;
        }
        m[s]++;
        t = s;
    }
    puts("DRAW");
    return 0;
}
