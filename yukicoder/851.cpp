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
    int n;
    cin >> n;
    cin.ignore();
    vector<ll> v;
    string s;
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        if(s.find(' ') != string::npos){
            puts("\"assert\"");
            return 0;
        }
        v.emplace_back(stoll(s));
    }
    vector<ll> u{v[0]+v[1], v[0]+v[2], v[1]+v[2]};
    sort(u.begin(), u.end(), greater<>());
    u.erase(unique(u.begin(), u.end()), u.end());
    cout <<  u[1] << "\n";
    return 0;
}