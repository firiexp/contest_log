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
    ll k, x, y;
    cin >> k >> x >> y;
    if(k%2 == 0 && (x+y) % 2) {
        puts("-1");
        return 0;
    }else if(abs(x)+abs(y) == k){
        puts("1");
        cout << x << " " << y << "\n";
        return 0;
    }
    int negax = 0, negay = 0, swapxy = 0;
    if(x < 0) negax = 1, x = -x;
    if(y < 0) negay = 1, y = -y;
    if(y > x) swapxy = 1, swap(x, y);
    vector<pair<ll, ll>> v;
    ll step = (x+y+k-1)/k;
    if(x + y < k) {
        if((x+y)%2 == 0) step = 2;
        else step = 3;
    }
    if(x + y >= k && ((step*k)-x-y)%2) step++;
    if(step == 3 && (x+y) < k && (x+y)%2){
        for (ll p = k; p <= step*k; p += k) {
            if(p <= k-x){
                v.emplace_back(0, -p);
            }else if(p <= k+(k+x-y)/2){
                v.emplace_back(p-(k-x), x-k);
            }else if(p <= 2*k+(k-x+y)/2){
                v.emplace_back(x+(k+x-y)/2,p-(k+(k+x-y)/2)+x-k);
            }else {
                v.emplace_back(x, y);
            }
        }
    }else {
        for (ll p = k; p <= step*k; p += k) {
            if(p <= (k*step-x-y)/2){
                v.emplace_back(0, -p);
            }else if(p <= x + (k*step-x-y)/2){
                v.emplace_back(p-(k*step-x-y)/2, -(k*step-x-y)/2);
            }else {
                v.emplace_back(x, -(k*step-x-y)/2+p-(x + (k*step-x-y)/2));
            }
        }
    }
    cout << v.size() << "\n";
    for (auto &&i : v) {
        if(!swapxy) cout << (negax ? -i.first : i.first) << " " << (negay ? -i.second : i.second)  << "\n";
        else cout <<  (negax ? -i.second : i.second) << " " << (negay ? -i.first : i.first)  << "\n";
    }
    return 0;
}