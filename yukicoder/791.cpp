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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    string s;
    cin >> s;
    if(s.size() == 1){
        puts("-1");
        return 0;
    }
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] != (i == 0 ? '1' : '3')){
            puts("-1");
            return 0;
        }
    }
    cout << s.size()-1 << "\n";
    return 0;
}
