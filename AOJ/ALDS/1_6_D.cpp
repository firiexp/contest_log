#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;

/* initialize */
int n, A[1010], cost =0;
pair<int, int> P[1010], Q[1010];
/* main */

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
    for (int i = 0; i < n; ++i) {
        P[i].first = A[i]; P[i].second = i;
    }
    sort(P, P+n);
    for (int i = 0; i < n; ++i) {
        Q[i].first = A[i];
        Q[P[i].second].second = i;
    }
    int s = P[1].first;
    for (int i = 0; i < n; ++i) {
        int j = Q[i].second;
        if(j >= 0 && j != 1){
            int m = 1, amin, sum;
            amin=sum=Q[i].first;
            while(j!=i){
                int next = Q[j].second;
                if(next<amin) amin = Q[j].first;
                sum +=Q[j].first;
                m++;
                Q[j].second=-1;
                j=next;
            }
            cost += min(sum+(m-2)*amin, sum+amin+(n+1)*s);
        }
    }
    cout << cost << "\n";

}