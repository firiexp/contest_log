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

bool solve(){
    string s;
    cin >> s;
    int wgr = 0, gr = 0, r = 0;
    reverse(s.begin(),s.end());
    for (auto &&i : s) {
        if(i == 'R') r++;
        else if(i == 'G'){
            if(!r) return false;
            gr++; r--;
        }else if(i == 'W'){
            if(!wgr && !gr) return false;
            if(gr) wgr++, gr--;
        }
    }
    if(gr || r) return false;
    return true;
}


int main() {
    int t;
    cin >> t;
    while(t--){
        puts(solve() ? "possible" : "impossible");
    }
    return 0;
}