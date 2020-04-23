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
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {

        ll a, b, c;
        cin >> a >> b >> c;
        if (c%2){
            cout << "No\n";
            continue;
        }
        ll p = (a)/2*100, p2 = (a+1)/2*100;
        while (p < p2 && b){
            p += 10;
            b-= 1;
        }
        while (p < p2 && c){
            p += 1;
            c -= 1;
        }
        while (p > p2 && b){
            p2 += 10;
            b-= 1;
        }
        while (p > p2 && c){
            p2 += 1;
            c -= 1;
        }
        p2 += (b+1)/2*10, p += b/2*10;
        while (p < p2 && c >= 10){
            p += 10;
            c -= 10;
        }
        while (p > p2 && c >= 10){
            p2 += 10;
            c -= 10;
        }
        p += c/2, p2 += (c+1)/2;
        if(p != p2){
            cout << "No\n";
        }else {
            cout << "Yes\n";
        }
    }
    return 0;
}
