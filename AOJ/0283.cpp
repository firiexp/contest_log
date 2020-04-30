#include <iostream>
#include <algorithm>
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
    int n, q;
    cin >> n >> q;
    vector<int> v(n), v2(n);
    for (auto &&i : v) scanf("%d", &i);
    v2 = v;
    sort(v2.begin(),v2.end());
    map<int, int> m;
    for (int _ = 0; _ < q; ++_) {
        string s; int x;
        cin >> s >> x;
        if(s == "ADD"){
            m[v[x-1]]++;
        }else if(s == "REMOVE"){
            m[v[x-1]]--;
            if(!m[v[x-1]]) m.erase(v[x-1]);
        }else {
            int ng = -1, ok = 1000000001;
            while(ok-ng > 1){
                int mid = (ok+ng)/2;
                int val = 0, r = 0;
                for (auto &&i : m) {
                    int l = lower_bound(v2.begin(),v2.end(), i.first-mid)-v2.begin();
                    int newr = upper_bound(v2.begin(),v2.end(), i.first)-v2.begin();
                    if(r < l) val += l-r;
                    r = newr;
                }
                if(n-r+val <= x) ok = mid;
                else ng = mid;
            }
            if(ok == 1000000001) puts("NA");
            else cout << ok << "\n";
        }
    }
    return 0;
}