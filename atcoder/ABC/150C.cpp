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
    vector<int> a(n), b(n);
    for (auto &&i : a) scanf("%d", &i);
    for (auto &&j : b) scanf("%d", &j);
    vector<int> X(n);
    iota(X.begin(),X.end(), 1);
    int cnt = 1, p = 0, q = 0;
    do {
        if(a == X) p = cnt;
        if(b == X) q = cnt;
        cnt++;
    }while(next_permutation(X.begin(),X.end()));
    cout << abs(p-q) << "\n";
    return 0;
}