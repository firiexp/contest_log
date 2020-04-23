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
    int n;
    cin >> n;
    const int M = 2000000;
    vector<int> v(n);
    vector<int> minfactor(M+1);
    for (int i = 2; i <= M; ++i) {
        if(minfactor[i] == 0){
            for (int j = i; j <= M; j += i) {
                if(minfactor[j] == 0) minfactor[j] = i;
            }
        }
    }
    for (auto &&i : v) scanf("%d", &i);
    set<int> s;
    for (int i = 2; i <= M; ++i) {
        s.emplace(i);
    }
    vector<int> facs;
    auto del = [&](int x){
        facs.clear();
        while(x > 1){
            facs.emplace_back(minfactor[x]);
            x /= minfactor[x];
        }
        sort(facs.begin(), facs.end());
        facs.erase(unique(facs.begin(), facs.end()), facs.end());
        for (int i = 0; i < facs.size(); ++i) {
            for (int j = facs[i]; j <= M; j += facs[i]) {
                s.erase(j);
            }
        }
    };
    vector<int> ans(n);
    int upper = 0;
    for (int i = 0; i < n; ++i) {
        if(upper){
            ans[i] = *s.begin();
            del(ans[i]);
        }else {
            ans[i] = *s.lower_bound(v[i]);
            upper = ans[i] > v[i];
            del(ans[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}