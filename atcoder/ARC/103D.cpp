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
    vector<int> vx, vy;
    int a, b;
    cin >> a >> b;
    vx.emplace_back(a);
    vy.emplace_back(b);
    int p = a+b;
    int k = abs(a)+abs(b);
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        cin >> x >> y;
        vx.emplace_back(x);
        vy.emplace_back(y);
        k = max(k, abs(x)+abs(y));
        if(k > 40) {
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << k << "\n";
    for (int i = 0; i < k; ++i) {

    }
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        string s;
        int P = vx[i], Q = vy[i], t = 0;
        for (int j = 0; j < k; ++j) {
            if(P > 0){
                s += "R";
                P--;
            }else if(P < 0){
                s += "L";
                P++;
            }else if(Q > 0){
                s += "U";
                Q--;
            }else if(Q < 0){
                s += "D";
                Q++;
            }else {
                if(t%2){
                    s += "U";
                }else {
                    s += "D";
                }
                t++;
            }
        }
        cout << s << "\n";
    }
    return 0;
}
