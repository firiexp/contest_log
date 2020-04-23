#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;
using P = pair<int, int>;
int main() {
    u32 h, w;
    cin >> h >> w;
    vector<vector<int>> v(h+1, vector<int>(w+1, 0));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            int k;
            cin >> k;
            v[i][j] = k;
        }
    }
    stringstream ss;
    vector<string> ans;
    int flag = 0;
    for (int i = 1; i <= h; ++i) {
        if(i%2) {
            for (int j = 1; j <= w; ++j) {
                if(v[i][j]%2) flag = 1;
                else flag = 0;
                if(flag){
                    flag = 1;
                    if(j != w){
                        ss << i << " " <<  j << " " << i << " " << j+1;
                        v[i][j]--;
                        v[i][j+1]++;
                        ans.emplace_back(ss.str());
                        ss.str("");
                        ss.clear(stringstream::goodbit);
                    }else if(i != h){
                        ss << i << " " <<  j << " " << i+1 << " " << j;
                        v[i][j]--;
                        v[i+1][j]++;
                        ans.emplace_back(ss.str());
                        ss.str("");
                        ss.clear(stringstream::goodbit);
                    }
                }
            }
        }else {
            for (int j = w; j >= 1; --j) {
                if(v[i][j]%2) flag = 1;
                else flag = 0;
                if(flag){
                    flag = 1;
                    if(j != 1){
                        ss << i << " " <<  j << " " << i << " " << j-1;
                        v[i][j]--;
                        v[i][j-1]++;
                        ans.emplace_back(ss.str());
                        ss.str("");
                        ss.clear(stringstream::goodbit);
                    }else if(i != h){
                        ss << i << " " <<  j << " " << i+1 << " " << j;
                        v[i][j]--;
                        v[i+1][j]++;
                        ans.emplace_back(ss.str());
                        ss.str("");
                        ss.clear(stringstream::goodbit);
                    }
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for (const auto &an : ans) {
        cout << an << "\n";
    }
    return 0;
}
