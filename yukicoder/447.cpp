#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> solved(n);
    map<string, int> m; int cur = 0;
    map<int, string> minv;
    vector<vector<int>> table(0);
    int t;
    cin >> t;
    while(t--){
        string s; char c;
        cin >> s >> c;
        if(!m.count(s)) {
            minv[cur] = s;
            m[s] = cur++;
            table.emplace_back(n+2);
            table[m[s]][n] = cur-1;
        }
        int id = c - 'A';
        table[m[s]][id] = 50*v[id]+500*v[id]/(10+2*solved[id]);
        table[m[s]][n+1] += (50*v[id]+500*v[id]/(10+2*solved[id]))*10000;
        table[m[s]][n+1] = table[m[s]][n+1]/10000*10000 + t;
        solved[id]++;
    }
    sort(table.begin(),table.end(), [](vector<int> &a, vector<int> &b){
        return a.back() > b.back();
    });
    for (int i = 0; i < cur; ++i) {
        cout << i+1 << " " << minv[table[i][n]] << " ";
        for (int j = 0; j < n; ++j) {
            cout << table[i][j] << " ";
        }
        cout << table[i][n+1]/10000 << "\n";
    }
    return 0;
}