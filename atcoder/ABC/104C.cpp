#include <iostream>
#include <deque>

using ll = long long;
using namespace std;

int main() {
    int d, g, ma = 100000000;
    cin >> d >> g;
    int p[d], c[d], k[d];
    int x[d] = {};
    for (int i = 0; i < d; ++i) {
        cin >> p[i] >> c[i];
        k[i] =p[i]* i * 100 + c[i];
    }
    for (int i = 0; i < (1 << d); ++i) {
        deque<int> S;
        int frag = 1;
        int je = 0, e = 0;
        for (int j = 0; j < d; ++j) {
            if (i & (1<<j)) S.emplace_back(j);
        }
        while(!S.empty() && frag) {
            e += p[S.front()];
            je += k[S.front()];
            if (je > g){
                ma = max(e, ma);
                frag = 0;
            }
            S.pop_front();
        }

    }
    return 0;
}
