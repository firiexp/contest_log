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
    string s, t; int n;
    cin >> s >> n >> t;
    int cnt = 0;
    for (auto &&i : s) cnt += i == 'o';
    for (auto &&i : t) cnt -= i == 'o';
    if(cnt != 0){
        puts("SUCCESS");
        return 0;
    }else if(n >= 2){
        puts("FAILURE");
        return 0;
    }else {
        string s2 = s, s3 = s;
        if(n == 1) swap(s2[0], s2[1]); swap(s3[1], s3[2]);
        puts(s2 == t || s3 == t ? "FAILURE" : "SUCCESS");
    }

    return 0;
}
