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

using P = array<int, 4>;
bool solve(vector<int> &a1, vector<int> &b1, vector<int> &a2, vector<int> &b2){
    int n = a1.size();
    vector<P> query(2*n);
    for (int i = 0; i < n; ++i) {
        query[i] = {a1[i], 1, a2[i], b2[i]};
        query[i+n] = {b1[i]+1, 0, a2[i], b2[i]};
    }
    sort(query.begin(),query.end());
    multiset<int, greater<>> L;
    multiset<int> R;
    for (int i = 0; i < 2*n; ++i) {
        if(query[i][1]){
            if(!L.empty()){
                if(*L.begin() > query[i][3] || *R.begin() < query[i][2]){
                    return false;
                }
            }
            L.insert(query[i][2]);
            R.insert(query[i][3]);
        }else {
            L.erase(L.find(query[i][2]));
            R.erase(R.find(query[i][3]));
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }
    if(solve(a, b, c, d) && solve(c, d, a, b)){
        puts("YES");
    }else {
        puts("NO");
    }
    return 0;
}