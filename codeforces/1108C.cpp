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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = "RGB";
    sort(t.begin(), t.end());
    map<string, int> m;
    int mi = INF<int>;
    do {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if(s[i] != t[i%3]) ans++;
        }
        mi = min(mi, ans);
        m[t] = ans;
    }while(next_permutation(t.begin(), t.end()));
    printf("%d\n", mi);
    for (auto &&i : m) {
        if(i.second == mi){
            for (int j = 0; j < n; ++j) {
                printf("%c", i.first[j%3]);
            }
            puts("");
            return 0;
        }
    }
    return 0;
}
