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

int solve(string &s, array<int, 4> &v){
    stack<int> S;
    for (auto &&i : s) {
        if(i == '[' || i == ']') continue;
        if(isalpha(i)){
            S.emplace(v[i-'a']);
        }else {
            int A = S.top(); S.pop();
            int B = S.top(); S.pop();
            if(i == '+') S.emplace(A|B);
            else if(i == '*') S.emplace(A&B);
            else if(i == '^') S.emplace(A^B);
        }
    }
    return S.top();
}

int main() {
    string s;
    while(cin >> s, s != "."){
        string t;
        cin >> t;
        array<int, 4> v{};
        for (int i = 0; i < 4; ++i) {
            v[i] = t[i]-'0';
        }
        reverse(s.begin(),s.end());
        int x = solve(s, v);
        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    for (int l = 0; l < 10; ++l) {
                        v = {i, j, k, l};
                        if(x == solve(s, v)) ans++;
                    }
                }
            }
        }
        cout << x << " " << ans << "\n";
    }

    return 0;
}