#include <iostream>
using ll = long long;
using namespace std;

int main() {
    ll a,b ,x, c, d, v;
    cin >> a >> b >> x;
    c = (a+x-1)/x;
    d = b/x;
    if(d == c){
        v = 0;
        if (a != c *x) v = 1;
        if (a%x == 0) v = 1;
    } else {
        v = d-c+1;
    }
    cout << v;

    return 0;
}