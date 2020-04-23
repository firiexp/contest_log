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
    array <int, 10> v{};
    for (int i = 0; i < 10; ++i) {
        cin >> v[i];
    }
    int n;
    cin >> n;
    vector<pair<int, int>> u;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int a = stoi(s);
        for (auto &&j : s) {
            for (int k = 0; k < 10; ++k) {
                if(j == v[k] + '0'){
                    j = static_cast<char>(k + '0');
                    break;
                }
            }
        }
        u.emplace_back(stoi(s), a);
    }
    sort(u.begin(), u.end());
    for (auto &&i : u) {
        cout << i.second << "\n";
    }
    return 0;
}
