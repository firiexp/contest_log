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
    int x, y;
    while(cin >> x >> y, x){
        vector<int> v(5);
        v[0] = x+y;
        for (int i = 1; i < 5; ++i) {
            int a, b;
            cin >> a >> b;
            v[i] = a+b;
        }
        int res = max_element(v.begin(),v.end()) - v.begin();
        printf("%c %d\n", 'A'+res, v[res]);
    }

    return 0;
}