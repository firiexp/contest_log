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
    int n; string s, t;
    cin >> n >> s >> t;
    array<int, 4> v{};
    for (int i = 0; i < n; ++i) {
        v[(s[i]-'0')*2 + (t[i]-'0')]++;
    }
    int a = v[0], b = v[1], c = v[2], d = v[3];
    for (int i = 0; i <= n/2; ++i) {
        for (int j = 0; j <= b; ++j) {
            if(d-i+j < 0) continue;
            if(d-i+b-j < 0) continue;
            if(2*i-d-b+j < 0) continue;
            if(i-b+j < 0) continue;
            if(c-2*i+d+b-j < 0) continue;
            if(i+j > n/2) continue;
            if(c+d+b > i+j + n/2) continue;
            int bcnt = j, dcnt = d-i+b-j, ccnt = 2*i-d-b+j, acnt = n/2-i-j;
            for (int cur = 0; cur < n; ++cur) {
                if(acnt && (s[cur]-'0')*2 + (t[cur]-'0') == 0) printf("%d ", cur+1), acnt--;
                if(bcnt && (s[cur]-'0')*2 + (t[cur]-'0') == 1) printf("%d ", cur+1), bcnt--;
                if(ccnt && (s[cur]-'0')*2 + (t[cur]-'0') == 2) printf("%d ", cur+1), ccnt--;
                if(dcnt && (s[cur]-'0')*2 + (t[cur]-'0') == 3) printf("%d ", cur+1), dcnt--;
            }
            puts("");
            return 0;
        }
    }
    puts("-1");
    return 0;
}
