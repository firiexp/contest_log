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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(m), c(m);
    for (int i = 0; i < m; ++i) {
        cin >> s[i] >> c[i];
    }
    for (int i = 0; i <= 1000; ++i) {
        string A = to_string(i);
        if(A.size() != n) continue;
        int ok = 1;
        for (int j = 0; j < m; ++j) {
            if(A[s[j]-1]-'0' != c[j]) ok = 0;
        }
        if(ok){
            cout << A << "\n";
            return 0;
        }
    }
    puts("-1");
    return 0;
}