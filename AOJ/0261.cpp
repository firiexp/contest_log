#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>
#include <sstream>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


int main() {
    int X[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string s;
    while(getline(cin, s), s != "#"){
        int cnt = 0;
        for (auto &&i : s) cnt += i == '.';
        vector<ll> val{0};
        for (auto &&i : s) {
            if(isdigit(i)) val.back() = val.back()*10+i-'0';
            else val.emplace_back();
        }
        if(val.size() == 3){
            if(val[1] <= 2) val[1] += 12, val[0]--;
            ll x = 365*val[0]+val[0]/4-val[0]/100+val[0]/400+306*(val[1]+1)/10+val[2]-735286;
            vector<int> ans(5);
            ans[4] = x%20; x /= 20;
            ans[3] = x%18; x /= 18;
            ans[2] = x%20; x /= 20;
            ans[1] = x%20; x /= 20;
            ans[0] = x%13;
            printf("%d.%d.%d.%d.%d\n", ans[0], ans[1], ans[2], ans[3], ans[4]);
        }else {
            ll x = val[4]+20*(val[3]+18*(val[2]+20*(val[1]+20*(val[0]))));
            int ok = 2011, ng = 8000;
            while(ng-ok > 1){
                auto mid = (ok+ng)/2;
                if(365*mid+mid/4-mid/100+mid/400-734857 <= x) ok = mid;
                else ng = mid;
            }
            x = x-(365*ok+ok/4-ok/100+ok/400-734857);
            ok++;
            if(ok%4 == 0 && ok%100 != 0 || ok%400 == 0) X[2] = 29;
            else X[2] = 28;
            for (int i = 1; i <= 12; ++i) {
                for (int j = 1; j <= X[i]; ++j) {
                    if(!x) printf("%d.%d.%d\n", ok, i, j);
                    x--;
                }
            }
        }
    }
    return 0;
}