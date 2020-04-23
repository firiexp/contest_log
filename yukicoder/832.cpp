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

bool solve(string s){
    map<int, int> m;
    for (auto &&i : s) {
        m[i]++;
    }
    int a = 0;
    for (auto &&j : m) {
        if(j.second == 2) a++;
    }
    if(a == 7) return true;
    sort(s.begin(),s.end());
    vector<string> v, u;
    for (int i = 1; i <= 9; ++i) {
        v.emplace_back(3, (char)(i+'0'));
        u.emplace_back(2, (char)(i+'0'));
    }
    for (int i = 1; i < 8; ++i) {
        string t;
        for (int j = 0; j < 3; ++j) {
            t += (char)(i+j+'0');
        }
        v.emplace_back(t);
    }
    int n = v.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            for (int k = j; k < n; ++k) {
                for (int l = k; l < n; ++l) {
                    for (int o = 0; o < 9; ++o) {
                        string t = v[i]+v[j]+v[k]+v[l]+u[o];
                        sort(t.begin(),t.end());
                        if(s == t) return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    map<int, int> cnt;
    for (auto &&i : s) {
        cnt[i-'0']++;
    }
    for (int i = 1; i <= 9; ++i) {
        if(cnt[i] < 4){
            string t = s;
            t += char(i + '0');
            if(solve(t)) cout << i << "\n";
        }
    }
    return 0;
}