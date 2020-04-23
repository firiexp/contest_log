#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    string s, t, u, v;
    cin >> s >> t;
    u = s, v = t;
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());
    if(u != v){
        puts("-1");
        return 0;
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if(s[i] != t[i]){
            for (int j = i+1; j < n; ++j) {
                if(s[j] == t[i]){
                    for (int k = j-1; k >= i; --k) {
                        q.emplace(k);
                        swap(s[k], s[k+1]);
                    }
                    j = n;
                }
            }
        }
    }
    printf("%lu\n", q.size());
    while (!q.empty()){
        printf("%d", q.front()+1);
        q.pop();
        if(!q.empty()) printf(" ");
        else printf("\n");
    }
    return 0;
}
