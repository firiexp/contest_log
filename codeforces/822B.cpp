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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int k = m-n+1;
    vector<int> ans(k);
    for (int i = 0; i < k; ++i) {
        int val = 0;
        for (int j = 0; j < n; ++j) {
            if(s[j] != t[i+j]) val++;
        }
        ans[i] = val;
    }
    auto a = min_element(ans.begin(),ans.end());
    printf("%d\n", *a);
    vector<int> v;
    int aa = a-ans.begin();
    for (int i = 0; i < n; ++i) {
        if(s[i] != t[i+aa]) v.emplace_back(i+1);
    }
    for (int i = 0; i < v.size(); ++i) {
        if(i) printf(" ");
        printf("%d", v[i]);
    }
    puts("");
    return 0;
}