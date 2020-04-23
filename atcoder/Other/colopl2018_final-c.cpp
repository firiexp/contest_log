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

template<class T>
class monotonic_CHT {
    using P = pair<T, T>;
    vector<P> lines;
public:
    monotonic_CHT() {}

    bool check(P l1, P l2, P l3){
        if(l1 < l3) swap(l1, l3);
        return (l3.second - l2.second)*(l2.first-l1.first)
            >= (l2.second - l1.second)*(l3.first-l2.first);
    }
    void add(T a, T b){
        P line(a, b);
        while(lines.size() >= 2 && check(*(lines.end()-2), lines.back(), line)) lines.pop_back();
        lines.emplace_back(line);
    }

    T f(int i, T x){
        return lines[i].first * x + lines[i].second;
    }

    T f(P line, T x){
        return line.first * x + line.second;
    }

    T get(T x){
        static int head = 0;
        while(lines.size()-head >= 2 && f(head, x) >= f(head+1, x)) ++head;
        return f(head, x);
    }
};

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    monotonic_CHT<ll> cht;
    for (ll i = 1; i <= n; ++i) {
        cht.add(-2*i,i*i+v[i-1]);
    }
    for (ll i = 1; i <= n; ++i) {
        cout << i*i+cht.get(i) << "\n";
    }
    return 0;
}
