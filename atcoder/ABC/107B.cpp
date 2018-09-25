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
    int h, w;
    cin >> h >> w;
    map<int, int> hh, ww;
    vector<string> aaa(h);
    for (int i = 0; i < h; ++i) {
        cin >> aaa[i];
    }
    for (int i = 0; i < h; ++i) {
        int flag = 1;
        for (int j = 0; j < w; ++j) {
            if(aaa[i][j] == '#') flag = 0;
        }
        if(flag) hh[i]++;
    }
    for (int j = 0; j < w; ++j) {
        int flag = 1;
        for (int i = 0; i < h; ++i) {
            if(aaa[i][j] == '#') flag = 0;
        }
        if(flag) ww[j]++;
    }
    for (int i = 0; i < h; ++i) {
        if(hh[i]) continue;
        for (int j = 0; j < w; ++j) {
            if(ww[j] == 0) cout << aaa[i][j];
        }
        cout << "\n";
    }
    return 0;
}
