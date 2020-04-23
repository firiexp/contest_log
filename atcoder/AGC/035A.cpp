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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(),v.end());
    if(v.back() == 0){
        puts("Yes");
        return 0;
    }else if(n%3){
        puts("No");
        return 0;
    }
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        m[v[i]]++;
    }
    int k = 0;
    for (auto &&j : m) {
        if(j.second%(n/3)){
            puts("No");
            return 0;
        }else {
            for (int i = 0; i < j.second/(n/3); ++i) {
                k ^= j.first;
            }
        }
    }
    puts(k ? "No" : "Yes");
    return 0;
}