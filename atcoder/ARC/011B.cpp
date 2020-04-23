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
    vector<string> v = {"zr","bc","dw","tj","fq","lv","sx","pm","hk", "ng"};
    map<char, int> m;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 2; ++j) {
            m[v[i][j]] = i;
            m[v[i][j] + 'A' - 'a'] = i;
        }
    }
    int n;
    cin >> n;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        string s, t;
        cin >> s;
        for (auto &&j : s) {
            if(m.count(j)){
                t += to_string(m[j]);
            }
        }
        if(!t.empty()){
            c++;
            if(c != 1) cout << " ";
            cout << t;
        }
    }
    cout << "\n";
    return 0;
}
