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
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    if(s[0] == s[1] && s[1] != s[2] && s[2] == s[3]){
        cout << "Yes" << "\n";
    }else puts("No");
    return 0;
}