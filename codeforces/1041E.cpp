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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> cnt(n-1);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        if(b != n){
            puts("NO");
            return 0;
        }
        cnt[a-1]++;
    }
    vector<int> ansl, ansr;
    vector<int> a;
    for (int i = 0; i < n-1; ++i) {
        if(!cnt[i]){
            a.emplace_back(i+1);
        }else {
            int prv = n;
            for (int j = 0; j < cnt[i]-1; ++j) {
                if(a.empty()){
                    puts("NO");
                    return 0;
                }
                ansl.emplace_back(a.back());
                ansr.emplace_back(prv);
                prv = a.back(); a.pop_back();
            }
            ansl.emplace_back(i+1);
            ansr.emplace_back(prv);
        }
    }
    if(ansl.size() != n-1){
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i = 0; i < n-1; ++i) {
        printf("%d %d\n", ansl[i], ansr[i]);
    }
    return 0;
}