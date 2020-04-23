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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    using P = array<int, 3>;
    vector<P> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i][0]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i][1]);
        v[i][2] = i+1;
    }
    sort(v.begin(),v.end(), [&](P a, P b){
        return a[0]*b[1] > a[1]*b[0];
    });
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", v[i][2]);
    }
    puts("");
    return 0;
}