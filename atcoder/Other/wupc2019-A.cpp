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
    string s;
    cin >> s;
    int cur = 0;
    while(cur+1 < s.size()){
        if(s[cur] == 'W' && s[cur+1] == 'A'){
            s[cur] = 'A'; s[cur+1] = 'C';
            cur -= 3;
        }
        cur++;
        if(cur < 0) cur = 0;
    }
    cout << s << "\n";
    return 0;
}
