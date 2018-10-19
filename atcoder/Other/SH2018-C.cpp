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

class Bipartite_Matching {
    vector<vector<int>> G;
    vector<int> match, used, alive;
    int t;
public:
    explicit Bipartite_Matching(int n): t(0), G(n), match(n, -1), used(n, 0), alive(n, -1){};

    void connect(int a, int b){
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    bool dfs(int x){
        used[x] = t;
        for (auto &&i : G[x]) {
            int w = match[i];
            if(alive[i] == 0) continue;
            if(w == -1 || (used[w] != t && dfs(w))){
                match[x] = i;
                match[i] = x;
                return true;
            }
        }
        return false;
    }

    int matching() {
        int ans = 0;
        for (int i = 0; i < G.size(); ++i) {
            if(alive[i] == 0) continue;
            if(match[i] == -1) {
                ++t;
                ans += dfs(i);
            }
        }
        return ans;
    }
};

int main(){
    int h, w, f = 0;
    cin >> h >> w;
    vector<vector<int>> v(h+2, vector<int>(w+2, 0));
    for (int i = 1; i <= h; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= w; ++j) {
            if(s[j-1] == '.') v[i][j] = 1, f++;
        }
    }
    Bipartite_Matching b(h*w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(v[i+1][j+1] && v[i+2][j+1]) b.connect(i*w+j, (i+1)*w+j);
            if(v[i+1][j+1] && v[i+1][j+2]) b.connect(i*w+j, (i*w+j+1));
        }
    }
    cout << f - b.matching() << "\n";
    return 0;
}
