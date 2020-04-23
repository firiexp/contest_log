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
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        s += c;
    }
    for (int i = 0; i <= 10000; ++i) {
        string x = to_string(i);
        if(s.find(x) == string::npos){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}