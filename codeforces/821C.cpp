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
    std::cin.tie(nullptr);std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    deque<int> q;
    string s;
    int ans = 0, cnt = 0;
    for (int i = 0; i < 2*n; ++i) {
        cin >> s;
        if(s == "add"){
            int x;
            cin >> x; x--;
            q.push_back(x);
        }else {
            if(!q.empty()){
                if(q.back() != cnt){
                    ans++;
                    while(!q.empty()) q.pop_front();
                }else q.pop_back();
            }
            cnt++;
        }
    }
    cout << ans << "\n";
    return 0;
}