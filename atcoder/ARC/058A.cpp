#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <set>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    set<int> v;
    for (int j = 0; j < k; ++j) {
        int a;
        cin >> a;
        v.emplace(a+'0');
    }
    for (int i = n; ; ++i) {
        int flag = 1;
        for (auto &&a : to_string(i)) {
            for (auto &&b : v) {
                if(a == b){
                    flag = 0;
                }
            }
        }
        if(flag){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
