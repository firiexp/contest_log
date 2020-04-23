#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <set>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    string s;
    cin >> s;
    int n, x = 0;
    cin >> n;
    for (int i = 'a'; i <= 'z'; ++i) {
        set<string> v;
        for (int j = 0; j < s.length(); ++j) {
            if(s[j] == i){
                for (int k = 1; k <= min(static_cast<int>(s.length()-j), n); ++k) {
                    v.emplace(s.substr(j, k));
                }
            }
        }
        for (auto &&a : v) {
            x++;
            if(x == n) {
                cout << a << "\n";
                return 0;
            }
        }
    }
    return 0;
}
