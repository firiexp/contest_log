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

vector<ll> divisor(ll n)
{
  vector<ll> ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return(ret);
}

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ",";
        os << v[i];
    }
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a;
        cin >> a;
        int mask = 1;
        while(mask <= a) mask *= 2;
        if(mask-a-1 != 0){
            printf("%d\n", mask-1);
        }else {
            auto x = divisor(a);
            if(x.size() == 2){
                printf("1\n");
            }else {
                printf("%lld\n", a/x[1]);
            }
        }
    }
    return 0;
}
