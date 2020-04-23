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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int l;
        scanf("%d",&l);
        v.emplace_back(l);
    }
    int ans = 0;
    sort(v.begin(), v.end());
    deque<int> Q;
    for (int i = 0; i < n; ++i) {
        Q.emplace_back(v[i]);
    }
    while(!Q.empty()){
        if(Q.size()>1){
            if(Q.front()+Q.back()+1 <= c){
                Q.pop_back(); Q.pop_front();
                ans++;
            }else {
                Q.pop_back();
                ans++;
            }
        }else {
            ans++;
            Q.pop_back();
        }
    }
    cout << ans << "\n";
    return 0;
}
