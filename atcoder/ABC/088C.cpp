#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    vector<vector<int>> v(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> v[i][j];
        }
    }
    bool flag = true;
    for (int i = 0; i < 2; ++i) {
        int x = v[i][0] - v[i + 1][0];
        for (int j = 1; j <= 2; ++j) {
            if (v[i][j] - v[i + 1][j] != x) {
                flag = false;
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        int x = v[0][i] - v[0][i+1];
        for (int j = 1; j <= 2; ++j) {
            if(v[j][i] - v[j][i+1] != x){
                flag = false;
            }
        }
    }
    cout << (flag ? "Yes" : "No") << "\n";
    return 0;
}
