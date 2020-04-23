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
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (n, 0));
    vector<string> ss = {"xoooo", "ooxoo", "oooox", "oxooo", "oooxo"};
    vector<string> s(n+2);
    for (int i = 0; i < n+2; ++i) {
        s[0] += 'o';
        s[n+1] += 'o';
    }
    for (int i = 1; i <= n; ++i) {
        s[i] += 'o';
        for (int j = 0; j < n; ++j) {
            s[i] += ss[(i-1)%5][j%5];
        }
        s[i] += 'o';
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(s[i-1][j+1] != 'x' && s[i-1][j-1] != 'x' && s[i+1][j-1] != 'x' && s[i+1][j+1] != 'x' && s[i][j] != 'x'){
                s[i][j] = 'x';
            }
            cout << (s[i][j] == 'o' ? '.' : 'X');
            if(s[i][j] == 'x') ans++;
        }
        cout << "\n";
    }
    return 0;
}
