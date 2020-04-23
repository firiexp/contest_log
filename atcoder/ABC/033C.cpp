#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    string s;
    cin >> s;
    stringstream ss{s};
    string buf;
    vector<string> v;
    cout << flush;
    while (getline(ss, buf, '+')){
        v.emplace_back(buf);
    }
    int ans = 0;
    for (auto &&i : v) {
        int k = 1;
        for (int j = 0; j < i.length(); j += 2) {
            if(i[j] == '0') k = 0;
        }
        ans += k;
    }
    cout << ans << "\n";
    return 0;
}
