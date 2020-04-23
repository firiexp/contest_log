#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    vector<int> used(n, 0);
    deque<int> s;
    vector<pair<int, int>> x;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v[b-1].emplace_back(a-1);
        v[a-1].emplace_back(b-1);
    }

    int k = n-1, l = -1;
    while(!used[k]){
        if(!used[k]) s.emplace_front(k);
        used[k] = 1;
        l = -1;
        for (auto &&i : v[k]) {
            if(!used[i]) {
                l = i;
            }
        }
        k = l;
        if(l == -1) break;
    }
    int c = 0;
    while(!s.empty()){
        if(c) cout << " ";
        cout << s.back()+1;
        s.pop_back();
        c++;
    }
    return 0;
}
