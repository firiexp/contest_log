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
    vector<string> ans;
    string def(s.size(), '0');
    while(true){
        string t(def);
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] != '0'){
                t[i]++; s[i]--;
            }
        }
        if(t == def) break;
        ans.emplace_back(t);
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        if(i) printf(" ");
        printf("%d", stoi(ans[i]));
    }
    puts("");
    return 0;
}