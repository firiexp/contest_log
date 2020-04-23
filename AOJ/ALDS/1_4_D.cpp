#include <iostream>
using ll = long long;
using namespace std;

/* initialize */
int n, k, A[100000], c;
ll sum = 0;


int check(ll P){
    int x = 0;
    for (int i = 0; i < k; ++i) {
        ll s = 0;
        while (s + A[x] <= P){
            s += A[x];
            x++;
            if (x == n) return n;
        }
    }
    return x;
}
ll search(ll right){
    ll left = 0;
    while (right - left > 1){
        ll mid = (right + left)/2;
        if (check(mid) >= n) right = mid;
        else left = mid;
    }

    return right;
}

/* main */
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c);
        sum += c;
        A[i] = c;
    }
    ll ans = search(sum+1);
    cout << ans << "\n";
    return 0;
}