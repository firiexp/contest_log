#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
using bigint = boost::multiprecision::cpp_int;
static const int INF = 1000000007;
using ll = long long;
using namespace std;


bigint lcm(bigint a, bigint b){
    bigint v = a * b / __gcd(a, b);
    return v;
}

int main() {
    int n;
    bigint ans;
    cin >> n;
    cin >> ans;
    for (int i = 0; i < n - 1; ++i) {
        ll k;
        cin >> k;
        ans = lcm(ans , k);
    }
    cout << ans << "\n";
    return 0;
}
