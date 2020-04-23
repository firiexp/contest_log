#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

bool issymmetric(string s, string t){
    if(s.size() != t.size()) return false;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] != t[(int)s.size()-i-1]) return false;
    }
    return true;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> v(h);
    for (auto &&i : v) cin >> i;
    vector<int> perm(h);
    for (int i = 0; i < h; ++i) perm[i] = i/2;
    int x = 0;
    do {
        bool ok = true;
        int p = 0;
        for (int i = 0; i < h; ++i) {
            if (h % 2 == 1 && perm[i] == h / 2) continue;
            if(perm[i] < p) continue;
            if(perm[i] == p) { ++p; continue;}
            ok = false;
            break;
        }
        if(!ok) continue;
        vector<int> u = perm, cnt((h+1)/2, 0);
        for (int i = 0; i < h; ++i) {
            if(cnt[u[i]] == 0) cnt[u[i]]++;
            else u[i] = h - u[i] - 1;
        }
        map<string, int> m;
        for (int i = 0; i < w; ++i) {
            string t(h, ' ');
            for (int j = 0; j < h; ++j) {
                t[u[j]] = v[j][i];
            }
            ++m[t];
        }
        int a = w%2;
        ok = true;
        for (auto &&k : m) {
            if(issymmetric(k.first, k.first)){
                if(k.second % 2 == 1) --a;
                continue;
            }
            string t = k.first;
            reverse(t.begin(), t.end());
            if(k.second != m[t]) {
                ok = false;
                break;
            }
        }
        if(!ok || a != 0) continue;
        puts("YES");
        return 0;
    }while(next_permutation(perm.begin(), perm.end()));
    puts("NO");
    return 0;
}
