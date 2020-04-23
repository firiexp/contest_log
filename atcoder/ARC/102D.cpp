#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int l;
    cin >> l;
    int n = 0;
    while((1 << n) <= l) n++;
    vector<vector<int>> v;
    for (int i = 0; i < n-1; ++i) {
        v.push_back({i+1, i+2, 0});
        v.push_back({i+1, i+2, 1 << i});
    }
    int p = (1 << (n-1));
    for (int i = n-2; i >= 0; --i) {
        if(l & (1 << i)){
            v.push_back({i+1, n, p});
            p += (1 << i);
        }
    }
    printf("%d %d\n", n, static_cast<int>(v.size()));
    for (auto &i : v) {
        for (int j = 0; j < i.size(); ++j) {
            if(j) printf(" ");
            printf("%d", i[j]);
        }
        printf("\n");
    }
    return 0;
}
