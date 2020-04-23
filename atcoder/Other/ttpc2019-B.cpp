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
    vector<string> v(n);
    for(auto &&i : v) cin >> i;
    for (auto &&s : v) {
        string A = "okyo", B = "ech";
        int a = 0, b = 0;
        for (int i = 0; i < s.size(); ++i) {
            if(a == 0){
                if(s.substr(i, 4) == A){
                    a++;
                }
            }else {
                if(s.substr(i, 3) == B){
                    b++;
                }
            }
        }
        puts((a && b) ? "Yes" : "No");
    }
    return 0;
}