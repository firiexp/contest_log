#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>
#include <iomanip>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    while(cin >> n, n){
        cin.ignore();
        vector<map<string, int>> v(26);
        for (int i = 0; i < n; ++i) {
            string A; getline(cin, A);
            stringstream ss; ss << A;
            string s;
            while(ss >> s){
                v[s.front()-'a'][s]++;
            }
        }
        char c;
        cin >> c;
        if(v[c-'a'].empty()) puts("NA");
        else {
            vector<pair<int, string>> ans;
            for (auto &&i : v[c-'a']) {
                ans.emplace_back(-i.second, i.first);
            }
            sort(ans.begin(),ans.end());
            for (int i = 0; i < min<int>(ans.size(), 5); ++i) {
                if(i) putchar(' ');
                cout << ans[i].second;
            }
            puts("");
        }
    }
    return 0;
}