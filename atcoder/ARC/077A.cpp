#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    int n;
    cin >> n;
    deque<int> v;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        if(i % 2) v.push_front(a);
        else v.push_back(a);
    }
    if(n % 2){
        for (int i = 0; i < n; ++i) {
            int k = v.back(); v.pop_back();
            if(i) cout << " " << k;
            else cout << k;
        }
    }else {
        for (int i = 0; i < n; ++i) {
            int k = v.front(); v.pop_front();
            if(i) cout << " " << k;
            else cout << k;
        }
    }
    cout << "\n";
    return 0;

}
