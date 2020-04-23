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
    vector<int> deg(100);
    int a, b;
    while(cin >> a >> b){

        if(a == 0){
            int ok = (deg[0]&1) && (deg[1]&1);
            for (int i = 2; i < 100; ++i) {
                if(deg[i]&1) ok = 0;
            }
            puts(ok ? "OK" : "NG");
            fill(deg.begin(),deg.end(), 0);
        }else {
            a--; b--;
            deg[a]++;
            deg[b]++;
        }
    }

    return 0;
}