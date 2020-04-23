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
    int n, d;
    cin >> n >> d;
    string s(min(d, 2*n-d), 'A');
    for (int i = 0; i < d-n; ++i) {
        s += 'B';
    }
    while(s.size() < n){
        s += 'C';
    }
    cout << s << "\n";
    return 0;
}
