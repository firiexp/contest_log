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
    while(cin >> n, n){
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            char c;
            cin >> c;
            v[i] = c-'A';
        }
        vector<int> cnt(26);
        bool det = false;
        for (int i = 0; i < n; ++i) {
            cnt[v[i]]++;
            auto cnt2(cnt);
            sort(cnt2.begin(),cnt2.end(), greater<>());
            if(cnt2[0]-cnt2[1] > n-i-1 && !det){
                det = true;
                cout << char((max_element(cnt.begin(),cnt.end())-cnt.begin()+'A')) << " " << i+1 << "\n";
            }
        }

        if(!det){
            puts("TIE");
        }
    }
    return 0;
}