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
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    for (int i = 0; i < k+1; ++i) {
        cout << "?";
        for (int j = 0; j < k+1; ++j) {
            if(i != j) cout << " " << j+1;
        }
        cout << endl;
        int ret1, ret2;
        cin >> ret1 >> ret2;
        cnt[ret2]++;
    }
    int a = -1, b = 0;
    for (auto &&i : cnt) {
        if(a < i.first){
            a = i.first;
            b = i.second;
        }
    }
    cout << "! " << b << endl;
    return 0;
}