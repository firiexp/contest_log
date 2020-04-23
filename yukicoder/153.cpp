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
    vector<int> v(n+1);
    v[1] = 0;
    for (int i = 2; i <= n; ++i) {
        vector<int> a;
        a.emplace_back(INF<int>);
        if(i&1) a.emplace_back(v[i/2]^v[i/2+1]);
        else a.emplace_back(0);
        if(i != 2){
            if(i%3 == 0) a.emplace_back(v[i/3]);
            else if(i%3 == 1) a.emplace_back(v[i/3+1]);
            else a.emplace_back(v[i/3]);
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        for (int j = 0; j < a.size(); ++j) {
            if(j != a[j]){
                v[i] = j;
                break;
            }
        }
    }
    puts(v.back() ? "A" : "B");
    return 0;
}