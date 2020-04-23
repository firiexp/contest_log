#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;



int main() {
    string s;
    cin >> s;
    int n = static_cast<int>(s.size());
    vector<string> v;
    deque<char> q;
    for (auto &&i : s) q.emplace_back(i);
    for (int i = 0; i < (1<<n); ++i) {
        auto Q = q;
        string t;
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)){
                t += Q.back(); Q.pop_back();
            }else {
                t += Q.front(); Q.pop_front();
            }
        }
        v.emplace_back(t);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size() << "\n";
    return 0;
}
