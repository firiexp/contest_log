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
    int a, b;
    while(cin >> a >> b, a){
        int cnt = 0;
        if(a < b) swap(a, b);
        while(b){
            cnt++;
            a %= b;
            swap(a, b);
        }
        cout << a << " " << cnt << "\n";
    }
    return 0;
}