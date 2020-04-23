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
    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);
    int cur = 0, go = 1, yama1 = 0, yama2 = 0;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if(yama1 && s != "drawtwo"){
            v[(cur+n)%n] -= yama1;
            cur = (cur+go+n) %n;
            yama1 = 0;
        }
        if(yama2 && s != "drawfour"){
            v[(cur+n)%n] -= yama2;
            cur = (cur+go+n) %n;
            yama2 = 0;
        }
        v[cur]++;
        if(s == "skip") cur = (cur+go+n) %n;
        else if(s == "reverse") go = -go;
        else if(s == "drawtwo") yama1+= 2;
        else if(s == "drawfour") yama2+= 4;
        cur = (cur+go+n) %n;
    }
    cout << (cur+n-go)%n+1 << " " << v[(cur+n-go)%n] << "\n";
    return 0;
}
