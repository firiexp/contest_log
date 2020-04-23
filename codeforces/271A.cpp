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
    cin >> n;
    for (int i = n+1; i <= 10000; ++i) {
        string s = to_string(i);
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        if(s.size() == 4){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}