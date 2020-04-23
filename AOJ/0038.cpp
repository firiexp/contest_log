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
    int a, b, c, d, e;
    while(scanf("%d,%d,%d,%d,%d", &a, &b, &c, &d, &e) != EOF){
        vector<int> v{a, b, c, d, e};
        [&](){
            vector<int> cnt(14);
            for (int i = 0; i < 5; ++i) {
                cnt[v[i]]++;
            }
            int two = 0, three = 0;
            for (int i = 0; i < 14; ++i) {
                if(cnt[i] == 4) {
                    puts("four card");
                    return;
                }else if(cnt[i] == 3) three++;
                else if(cnt[i] == 2) two++;
            }
            if(three && two){
                puts("full house");
                return;
            }
            sort(v.begin(),v.end());
            if(v == vector<int>{1, 10, 11, 12, 13}){
                puts("straight");
                return;
            }
            int ok = 1;
            for (int i = 0; i < 4; ++i) {
                if(v[i]+1 != v[i+1]) ok = 0;
            }
            if(ok){
                puts("straight");
                return;
            }
            if(three) puts("three card");
            else if(two == 2) puts("two pair");
            else if(two) puts("one pair");
            else puts("null");
        }();
    }
    return 0;
}