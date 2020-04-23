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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    string s = "yuiophjklnm";
    string in;
    while(cin >> in, in != "#"){
        vector<int> v(in.size());
        for (int i = 0; i < in.size(); ++i) {
            v[i] = (s.find(in[i]) != string::npos);
        }
        int ans = 0;
        for (int i = 0; i+1 < in.size(); ++i) {
            if(v[i] != v[i+1]) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
