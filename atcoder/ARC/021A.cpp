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
    int n, m[4][4];
    for (auto &i : m) for (int &j : i) cin >> j;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if(m[i][j] == m[i+1][j]){
                cout << "CONTINUE" << "\n";
                return 0;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(m[i][j] == m[i][j+1]){
                cout << "CONTINUE" << "\n";
                return 0;
            }
        }
    }
    cout << "GAMEOVER\n";
    return 0;
}
