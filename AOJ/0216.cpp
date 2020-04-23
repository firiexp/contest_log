#include <iostream>
#include <algorithm>
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
    auto f = [](int n){
        if(n <= 10) return 1150;
        else if(n <= 20) return n*125-100;
        else if(n <= 30) return n*140-400;
        else return n*160-1000;
    };
    int n;
    while(cin >> n, ~n) cout << 4280-f(n) << "\n";
    return 0;
}