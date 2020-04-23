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

void insert(vector<pair<char, int>> &v, pair<char, int> c){
    if(c.second == 0) return;
    if(v.empty() || v.back().first != c.first) v.emplace_back(c);
    else v.back().second += c.second;
}

int main() {
    vector<pair<char, int>> A, B, C;
    char c;
    int cnt = 1;
    while(cin >> c, c != '$'){
        int x; cin >> x;
        A.emplace_back(c, x);
        cnt++;
    }
    while(cin >> c, c != '$'){
        int x; cin >> x;
        B.emplace_back(c, x);
        cnt--;
    }
    while(cin >> c, c != '$'){
        int x; cin >> x;
        C.emplace_back(c, x);
    }
    int n = A.size(), m = B.size(), p = C.size();
    for (int i = 0; i < cnt; ++i) {
        int ok = 1;
        for (int j = 0; j < m; ++j) {
            if(A[i+j].first != B[j].first) {
                ok = 0;
                break;
            }
            if(j == 0 || j+1 == m){
                if(A[i+j].second < B[j].second) {
                    ok = 0;
                    break;
                }
            }else {
                if(A[i+j].second != B[j].second){
                    ok = 0;
                    break;
                }
            }
        }
        if(ok){
            for (int j = 0; j < m; ++j) {
                A[i+j].second -= B[j].second;
            }
            vector<pair<char, int>> ans;
            for (int j = 0; j <= i-(m == 1); ++j) {
                insert(ans, A[j]);
            }
            for (int k = 0; k < p; ++k) {
                insert(ans, C[k]);
            }
            for (int j = i+1-(m == 1); j < n; ++j) {
                insert(ans, A[j]);
            }
            for (auto &&l : ans) {
                cout << l.first << " " << l.second << " ";
            }
            puts("$");
            return 0;
        }

    }
    for (auto &&l : A) {
        cout << l.first << " " << l.second << " ";
    }
    puts("$");
    return 0;
}