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
    while(n--){
        string s;
        cin >> s;
        int ok1 = 0, ok2 = 0, sum = 0;
        for (auto &&i : s) {
            if (((i-'0')&1) == 0) ok1++;
            if(i == '0') ok2++;
            sum += i-'0';
        }
        if(sum%3 == 0 && ok1 >= 2 && ok2) puts("red");
        else puts("cyan");
    }
    return 0;
}