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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> cnt(n+1);
    for (int i = 0; i < n; ++i) {
        cnt[v[i]]++;
    }
    vector<int> u;
    for (int i = 0; i < n; ++i) {
        if(!cnt[i+1]){
            u.emplace_back(i+1);
        }
    }
    for (int i = 0; i < n; ++i) {
        if(!v[i] && !cnt[i+1]){
            if(u.back() == i+1){
                int a = u.back(); u.pop_back();
                v[i] = u.back(); u.pop_back();
                u.push_back(a);
            }else {
                v[i] = u.back(); u.pop_back();
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if(!v[i]){
            v[i] = u.back(); u.pop_back();
        }
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", v[i]);
    }
    puts("");
    return 0;
}