#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &&i : a) scanf("%d", &i);
    for (auto &&i : b) scanf("%d", &i);
    pair<int, int> aa, bb;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(a[i] == a[j]) aa = {i, j};
            if(b[i] == b[j]) bb = {i, j};
        }
    }
    vector<int> aaa{aa.first, aa.second, bb.first, bb.second};
    sort(aaa.begin(), aaa.end());
    aaa.erase(unique(aaa.begin(), aaa.end()), aaa.end());
    vector<int> ans(n), abc;
    for (int i = 0; i < n; ++i) {
        if(aa.first != i && aa.second != i && bb.first != i && bb.second != i){
            ans[i] = a[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        int ok = 0;
        for (int j = 0; j < n; ++j) {
            if(ans[j] == i) ok = 1;
        }
        if(!ok) abc.emplace_back(i);
    }
    do {
        for (int i = 0; i < abc.size(); ++i) {
            ans[aaa[i]] = abc[i];
        }
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            if(a[i] != ans[i]) cnt1++;
            if(b[i] != ans[i]) cnt2++;
        }
        if(cnt1 == 1 && cnt2 == 1){
            for (int i = 0; i < n; ++i) {
                if(i) printf(" ");
                printf("%d", ans[i]);
            }
            puts("");
            return 0;
        }
    } while(next_permutation(abc.begin(),abc.end()));
    return 0;
}