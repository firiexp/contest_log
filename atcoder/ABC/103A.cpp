#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int n,m,l;
    cin >> n >> m >> l;
    if(max(n,max(m,l)) == l) cout << (l-max(n,m)+abs(m-n));
    else if(max(n,max(m,l)) == m) cout << (m-max(n,l)+abs(l-n));
    else if(max(n,max(m,l)) == n) cout << (n-max(l,m)+abs(m-l));
    return 0;
}