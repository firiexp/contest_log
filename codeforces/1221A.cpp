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

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

bool solve(){
    int n;
    cin >> n;
    GPQ<int> Q;
    int ok = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x == 2048) ok = 1;
        if(x < 2048) Q.emplace(x);
    }
    if(ok) return true;
    while(Q.size() >= 2){
        int i = Q.top(); Q.pop();
        int j = Q.top(); Q.pop();
        if(i != j){
            Q.emplace(j);
            continue;
        }
        if(2*j == 2048) return true;
        Q.emplace(2*j);
    }
    while(!Q.empty()){
        if(Q.top() == 2048) return true;
        Q.pop();
    }
    return false;
}

int main() {
    int q;
    cin >> q;
    while(q--){
        cout << (solve() ? "YES" : "NO") << "\n";
    }
    return 0;
}