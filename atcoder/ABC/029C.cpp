#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T>
T pow_ (T x, T n, T M){
    uint64_t u = 1, xx = x;
    while (n > 0){
        if (n&1) u = u * xx % M;
        xx = xx * xx % M;
        n >>= 1;
    }
    return static_cast<T>(u);
};



int main() {
    int n;
    cin >> n;
    queue<string> ss;
    ss.emplace("");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < pow_(3, i, INF<int>); ++j) {
            string t = ss.front();
            ss.pop();
            for (char k = 'a'; k < 'd'; ++k) {
                ss.emplace(t + k);
            }
        }
    }
    while(!ss.empty()){
        cout << ss.front() << "\n";
        ss.pop();
    }
    return 0;
}
