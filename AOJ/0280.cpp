#include <iostream>
#include <algorithm>
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
    while(cin >> n, n){
        string s;
        cin >> s;
        vector<int> val(n);
        int cur = 0, ba = 0;
        for (auto &&i : s) {
            if(i == 'M') val[cur]++;
            else if(i == 'S') ba += val[cur]+1, val[cur] = 0;
            else if(i == 'L') val[cur] += ba+1, ba = 0;
            cur = (cur+1)%n;
        }
        sort(val.begin(),val.end());
        for (int i = 0; i < n; ++i) {
            printf("%d ", val[i]);
        }
        cout << ba << "\n";
    }
    return 0;
}