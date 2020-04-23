#include <iostream>
#include <vector>
#include <queue>
using ll = long long;
using namespace std;


int main() {
    int n, l,a, sum=0, j = 0;
    priority_queue<int, vector<int>, greater<> > Q;
    cin >> l >> n;
    for (int i = 0; i < n; ++i) {scanf("%d", &a); Q.push(a);}
    for (; !Q.empty();Q.pop()) {
        a = Q.top();
        if(a + sum <= l){
            sum += a; j++;
        }
    }

    cout << j << "\n";

    return 0;
}