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

int main() {
    int N, K;
    cin >> N >> K;
    if (K >= (1 << N)) {
        cout << -1 << endl;
        return 0;
    }
    if (N == 1) {
        if (K == 1) {
            cout << -1 << endl;
            return 0;
        }
        else {
            cout << "0 0 1 1" << endl;
            return 0;
        }
    }
    int n = (1 << N);
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (i != K) {
            res.push_back(i);
        }
    }
    res.push_back(K);
    for (int i = n - 1; i >= 0; i--) {
        if (i != K) {
            res.push_back(i);
        }
    }
    res.push_back(K);
    for (int i = 0; i < res.size(); i++) {
        if (i > 0)cout << " ";
        cout << res[i];
    }
    cout << endl;
    return 0;
}