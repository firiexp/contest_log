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
    int plus = 0, minus = 0;
    vector<int> num;
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        if(c == '+') plus++;
        else if(c == '-') minus++;
        else num.emplace_back(c-'0');
    }
    int amari = num.size()-minus-plus;
    sort(num.begin(),num.end(), greater<>());
    ll a = 0;
    for (int i = 0; i < amari; ++i) {
        a = a*10+num[i];
    }
    ll ans1 = a;
    for (int i = amari; i < amari + plus; ++i) {
        ans1 += num[i];
    }
    for (int i = amari + plus; i < amari + plus + minus; ++i) {
        ans1 -= num[i];
    }
    ll ans2 = 0;
    if(!minus){
        int p = plus+minus+1;
        int cur = 0, tmp = 0;
        while (cur < num.size()) {
            for (int i = 0; i < p && cur < num.size(); i++) {
                ll x = num[cur++];
                for (int j = 0; j < tmp; j++) x *= 10;
                ans2 += x;
            }
            tmp++;
        }
    }else {
        ans2 = -a;
        for (int i = amari; i < amari + minus - 1; i++) {
            ans2 -= num[i];
        }
        for (int i = amari + minus - 1; i < num.size(); i++) {
            ans2 += num[i];
        }
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}