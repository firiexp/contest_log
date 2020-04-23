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
    using P = array<int, 6>;
    vector<P> ps{{0,1,2,3,4,5},{0,2,3,4,1,5},{0,3,4,1,2,5},{0,4,1,2,3,5},{1,0,4,5,2,3},{1,2,0,4,5,3},{1,4,5,2,0,3},{1,5,2,0,4,3},{2,0,1,5,3,4},{2,1,5,3,0,4},{2,3,0,1,5,4},{2,5,3,0,1,4},{3,0,2,5,4,1},{3,2,5,4,0,1},{3,4,0,2,5,1},{3,5,4,0,2,1},{4,0,3,5,1,2},{4,1,0,3,5,2},{4,3,5,1,0,2},{4,5,1,0,3,2},{5,1,4,3,2,0},{5,2,1,4,3,0},{5,3,2,1,4,0},{5,4,3,2,1,0}};
    auto mul = [](P a, P b){
        P res;
        for (int i = 0; i < 6; ++i) res[i] = a[b[i]];
        return res;
    };
    vector<string> v{"Blue","Cyan","Green","Magenta","Red","Yellow"};
    int n;
    while(cin >> n, n){
        vector<P> A(n);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 6; ++j) {
                string s;
                cin >> s;
                A[i][j] = lower_bound(v.begin(),v.end(), s)-v.begin();
            }
            swap(A[i][3], A[i][4]);
            int ok = 0;
            for (int j = 0; j < i; ++j) {
                for (int k = 0; k < ps.size(); ++k) {
                    if(A[j] == mul(A[i], ps[k])){
                        ok = 1;
                        j = k = 100;
                    }
                }
            }
            cnt += ok;
        }
        cout << cnt << "\n";
    }
    return 0;
}