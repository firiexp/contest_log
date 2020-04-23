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

bool solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i) {
        A[i] = i+1; B[i] = n-i;
    }

    for (int i = 0; i < n; ++i) {
        if(v == A || v == B){
            return true;
        }
        rotate(v.begin(),v.begin()+1, v.end());
    }
    return false;
}

int main() {
    int q;
    cin >> q;
    while(q--){
        puts(solve() ? "YES" : "NO");
    }
    return 0;
}