#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    string s = "0000000000";
    int cur = 0;
    while(true){
        int m = 0; string k = s, kk = s;
        for (int i = 0; i < 10; ++i) {
            k[cur] = static_cast<char>('0' + i);
            cout << k << endl;
            int a; string t;
            cin >> a >> t;
            if(t == "unlocked"){
                return 0;
            }
            if(m < a){
                kk = k;
                m = a;
            }
        }
        s = kk;
        cur++;
    }
    return 0;
}
