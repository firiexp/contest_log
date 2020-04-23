#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    int k = n;
    while (k%2 == 0 && k != 0){
        k/=2;
    }
    if(n == 1){
        cout << 1 << "\n";
        return 0;
    }
    int ma = 0;
    map<int, int> m;
    for (int i = 1; i <= n; ++i) {
        int p = 1, q = i;
        while(q%2 == 0){
            p*=2;
            q/=2;
        }
        m[p]++;
        ma = max(ma, p);
    }
    if(ma/2*3 <= n){
        m[ma]--;
        m[ma/2*3]++;
    }
    vector<int> v;
    for (auto &&i : m) {
        for (int j = 0; j < i.second; ++j) {
            v.emplace_back(i.first);
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        if(i) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n");
    return 0;
}
