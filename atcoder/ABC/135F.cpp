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

vector<int> makeTable(const string& s) {
    int n = s.size();
    vector<int> ret(n+1);
    ret[0] = -1;
    int j = -1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && s[i] != s[j]) j = ret[j];
        ret[i+1] = ++j;
    }
    return ret;
}

vector<int> kmp(const string& str, const string& word) {
    vector<int> table = makeTable(word), ret(str.size());
    int m = 0, i = 0, n = str.size();
    while (m+i < n) {
        if (word[i] == str[m+i]) {
            if (++i == (int)(word.size())) {
                ret[m]++;
                m = m+i-table[i];
                i = table[i];
            }
        } else {
            m = m+i-table[i];
            if (i > 0) i = table[i];
        }
    }
    return ret;
}


int main() {
    string s, t, u;
    cin >> s >> t;
    u = s;
    int cnt = 0;
    while(s.size() < t.size()*15 || cnt < 15){
        s += u;
        cnt++;
    }
    auto A = kmp(s, t);
    s += s;
    auto B = kmp(s, t);
    int m = t.size();
    for (int i = m; i < A.size(); ++i) {
        if(A[i]) A[i] = max(A[i], A[i-m]+1);
    }
    for (int i = m; i < B.size(); ++i) {
        if(B[i]) B[i] = max(B[i], B[i-m]+1);
    }
    int ans = *max_element(A.begin(),A.end()), ans2 = *max_element(B.begin(),B.end());
    if(ans != ans2){
        puts("-1");
    }else {
        cout << ans << "\n";
    }
    return 0;
}