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

int main() {
    int n;
    while(cin >> n, n) {
        vector<string> v(n);
        for (auto & i : v) {
            cin >> i;
        }
        if(n == 1){
            cout << v.front() << "\n";
            continue;
        }
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            int m = (int)v[i].size()-1;
            while(s.size() > 2*m) {
                s.pop();
                int x = s.top(); s.pop();
                int y = s.top(); s.pop();
                int z = s.top(); s.pop();
                if(y == -1) x += z;
                else x *= z;
                s.emplace(x);
                s.emplace(y);
            }
            if(v[i].back() == '+') s.push(0), s.push(-1);
            else if(v[i].back() == '*') s.push(1), s.push(-2);
            else {
                int x = v[i].back()-'0';
                int y = s.top(); s.pop();
                int z = s.top(); s.pop();
                if(y == -1) x += z;
                else x *= z;
                s.emplace(x);
                s.emplace(y);
            }
        }
        while(s.size() > 2) {
            s.pop();
            int x = s.top(); s.pop();
            int y = s.top(); s.pop();
            int z = s.top(); s.pop();
            if(y == -1) x += z;
            else x *= z;
            s.emplace(x);
            s.emplace(y);
        }
        s.pop();
        cout << s.top() << "\n";
    }
    return 0;
}