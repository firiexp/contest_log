#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int a = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i-1; j < n; ++j) {
            string w;
            for (int k = 0; k < n; ++k) {
                if(i <= k && k <= j) continue;
                else w += s[k];
            }
            if(w.size() == 7){
                if(w == "keyence"){
                    a++;
                }
            }
        }
    }
    puts(a ? "YES" : "NO");
    return 0;
}
