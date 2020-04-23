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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i), i--;
    if(n <= 7){
        vector<int> P(n);
        iota(P.begin(),P.end(), 0);
        do {
            int ok = 1;
            for (int i = 0; i < n-1; ++i) {
                if(P[i+1] == v[P[i]]) ok = 0;
            }
            if(ok){
                for (int i = 0; i < n; ++i) {
                    if(i) printf(" ");
                    printf("%d", P[i]+1);
                }
                puts("");
                return 0;
            }
        }while(next_permutation(P.begin(),P.end()));
        puts("-1");
        return 0;
    }
    vector<int> ans(n);
    vector<int> A;
    for (int i = 0; i < n; ++i) {
        A.emplace_back(n-i-1);
    }
    for (int i = 0; i < n-7; ++i) {
        if(i == 0 || v[ans[i-1]] != A.back()){
            ans[i] = A.back();
            A.pop_back();
        }else {
            int a = A.back(); A.pop_back();
            ans[i] = A.back(); A.pop_back();
            A.emplace_back(a);
        }
    }
    sort(A.begin(),A.end());
    do {
        if(v[ans[n-8]] == A[0]) continue;
        int ok = 1;
        for (int i = 0; i < 6; ++i) {
            if(v[A[i]] == A[i+1]) ok = 0;
        }
        if(ok) break;
    }while(next_permutation(A.begin(),A.end()));
    for (int i = 0; i < 7; ++i) {
        ans[n-7+i] = A[i];
    }
    auto ans2 = ans;
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]+1);
    }
    puts("");
    return 0;
}