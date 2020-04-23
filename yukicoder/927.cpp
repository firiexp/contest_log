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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    sort(s.begin(),s.end(), greater<>());
    for (int i = n-2; i >= 0; --i) {
        if(s[i] != s[i+1] && !(s[i+1] == '0' && !i)){
            swap(s[i], s[i+1]);
            cout << s << "\n";
            return 0;
        }
    }
    puts("-1");
    return 0;
}