#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

/* initialize */
int pos;
vector<int> A, B, C;
/* main */
void recon(int l, int r){
    if (l >= r) return;
    int root = A[pos++];
    int m;
    m = distance(B.begin(), find(B.begin(), B.end(), root));
    recon(l, m);
    recon(m+1, r);
    C.push_back(root);
}
int main() {
    int n;
    cin >> n;
    int k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        A.push_back(k);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        B.push_back(k);
    }

    int pos = 0;
    recon(0, A.size());
    for (int j = 0; j < n; ++j) {
        if (j) cout << " ";
        cout << C[j];
    }
    cout << "\n";
    return 0;
}