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
    int n, k;
    cin >> n >> k;
    map<int, int> v;
    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        v[x]++;
    }
    vector<string> yes, no;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        if(v[i]) yes.emplace_back(s);
        else no.emplace_back(s);
    }
    string s;
    if(!yes.empty()){
        s = yes[0];
        int p = static_cast<int>(s.length());
        for (int i = 1; i < yes.size(); ++i) {
            int x = 0;
            for (int j = 0; j < min(s.length(), yes[i].length()); ++j) {
                if(s[j] == yes[i][j]) x++;
                else break;
            }
            p = min(p, x);
        }
        s = s.substr(0, p);
    }
    if(!no.empty()){
        int p = 0;
        for (auto &i : no) {
            int x = 0;
            for (int j = 0; j < min(s.length(), i.length()); ++j) {
                if(i[j] == s[j]) x++;
                else break;
            }
            p = max(p, x);
        }
        if(p >= s.length()){
            cout << -1 << "\n";
        }else {
            cout << s.substr(0, p+1) << "\n";
        }
    }else {
        cout << "\n";
    }
    return 0;
}
