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
    int a, b;
    cin >> a >> b;
    int cur = 1;
    while(true){
        if(cur&1){
            if(a < cur) {
                puts("Vladik");
                return 0;
            }
            a -= cur++;
        }else {
            if(b < cur){
                puts("Valera");
                return 0;
            }
            b -= cur++;
        }
    }
    return 0;
}