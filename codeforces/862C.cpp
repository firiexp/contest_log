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
    int n, x;
    cin >> n >> x;
    if(n == 2 && x == 0){
        puts("NO");
        return 0;
    }
    vector<int> ans;
    for (int i = 0; i < (n-1)/4*4; ++i) {
        ans.emplace_back(200000+i);
    }
    if(n%4 == 1){
        ans.emplace_back(x);
    }else if(n%4 == 2){
        if(x == 0) {
            for (int i = 0; i < 4; ++i) {
                ans.pop_back();
            }
            ans.emplace_back(1);
            ans.emplace_back(2);
            ans.emplace_back(4);
            ans.emplace_back(6);
            ans.emplace_back(8);
            ans.emplace_back(9);
        }else {
            ans.emplace_back(0);
            ans.emplace_back(x);
        }
    }else if(n%4 == 3){
        ans.emplace_back(500000);
        ans.emplace_back(500001);
        ans.emplace_back(x^1);
    }else if(n%4 == 0){
        if(x == 1){
            ans.emplace_back(0);
            ans.emplace_back(2);
            ans.emplace_back(4);
            ans.emplace_back(7);
        }else {
            ans.emplace_back(500000);
            ans.emplace_back(500001);
            ans.emplace_back(0);
            ans.emplace_back(x^1);
        }
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}