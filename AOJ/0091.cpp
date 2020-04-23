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
    int x;
    cin >> x;
    array<int, 100> v{};
    for (auto &&i : v) scanf("%d", &i);
    int A[] = {0, 9, 10, 11, 20};
    int B[] = {0, 1, 2, 10, 11, 12, 20, 21, 22};
    int C[] = {0, 9, 10, 11, 18, 19, 20, 21, 22, 29, 30, 31, 40};
    auto dfs = [&](int cur, int cnt, auto &&f) -> bool {
        if(cnt == 0){
            int ok = !*max_element(v.begin(),v.end());
            if(ok) return 1;
        }
        for (int i = cur; i < 100; ++i) {
            int y = i/10, x = i%10;
            if(y <= 5 && 2 <= x && x <= 7) {
                int ok = 1;
                for (auto &&p : C) if(!v[i+p]) ok = 0;
                if(ok){
                    for (auto &&p : C) v[i+p]--;
                    if(f(i,cnt-1, f)){
                        printf("%d %d 3\n", x, y+2);
                        return 1;
                    }
                    for (auto &&p : C) v[i+p]++;
                }
            }
            if(y <= 7 && x <= 7) {
                int ok = 1;
                for (auto &&p : B) if(!v[i+p]) ok = 0;
                if(ok){
                    for (auto &&p : B) v[i+p]--;
                    if(f(i,cnt-1, f)){
                        printf("%d %d 2\n", x+1, y+1);
                        return 1;
                    }
                    for (auto &&p : B) v[i+p]++;
                }
            }
            if(y <= 7 && 1 <= x && x <= 8) {
                int ok = 1;
                for (auto &&p : A) if(!v[i+p]) ok = 0;
                if(ok){
                    for (auto &&p : A) v[i+p]--;
                    if(f(i,cnt-1, f)){
                        printf("%d %d 1\n", x, y+1);
                        return 1;
                    }
                    for (auto &&p : A) v[i+p]++;
                }
            }


        }
        return 0;
    };
    dfs(0, x, dfs);

    return 0;
}
