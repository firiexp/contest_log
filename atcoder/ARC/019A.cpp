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
    char c[] = {'O', 'D', 'I', 'Z', 'S', 'B'}, d[] = {'0', '0', '1', '2', '5', '8'};
    cin >> s;
    for (auto &&i : s) {
        for (int j = 0; j < 6; ++j) {
            if(i == c[j]) i = d[j];
        }
    }
    cout << s << "\n";
    return 0;
}
