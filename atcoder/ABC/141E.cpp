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
    int n; string s;
    cin >> n >> s;
    int ok = 0, ng = n;
    while(ng - ok > 1){
        int mid = (ok+ng)/2;
        map<string, int> v;
        int good = 0;
        for (int i = 0; i+mid-1 < n; ++i) {
            string t = s.substr(i, mid);
            if(v.count(t)){
                if(v[t]+mid-1 < i) good = 1;
            }else {
                v[t] = i;
            }
        }
        if(good) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
    return 0;
}