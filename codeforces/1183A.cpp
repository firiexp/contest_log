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
    int n;
    cin >> n;
    while(true){
        string s = to_string(n);
        int cnt = 0;
        for (auto &&i : s) {
            cnt += i-'0';
        }
        if((cnt&3) == 0) break;
        n++;
    }
    cout << n << "\n";
    return 0;
}