#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

static const int INF = 1000000007;
using ll = long long;
using namespace std;
using P = pair<int, int>;
using board = array<array<int, 3>, 3>;
int a[2][3], b[3][2];
map<board, int> m;

int c (board x){
    int ans=0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(x[i][j] == x[i+1][j]) ans += a[i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if(x[i][j] == x[i][j+1]) ans += b[i][j];
        }
    }
    return ans;
}

int searchboard(board x, int u){
    if(m.count(x)) return m[x];
    if(u == 9) return c(x);
    int mm = u % 2 == 0 ? -INF : INF;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(x[i][j] >= 1) continue;
            if(u % 2 == 0){
                x[i][j] = 1;
                mm = max(mm, searchboard(x, u+1));
                x[i][j] = 0;
            }
            else {
                x[i][j] = 2;
                mm = min(mm, searchboard(x, u+1));
                x[i][j] = 0;
            }
        }
    }
    m[x] = mm;
    return mm;
}

int main() {
    int sum = 0;
    for (auto &i : a) for (int &j : i) {cin >> j; sum += j;}
    for (auto &i : b) for (int &j : i) {cin >> j; sum += j;}
    board e;
    for (auto &i : e) for (auto &j : i) j = 0;
    int choku = searchboard(e ,0);
    cout << choku << "\n";
    cout << sum - choku << "\n";
    return 0;
}
