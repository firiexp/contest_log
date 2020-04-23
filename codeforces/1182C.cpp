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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;



int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    string t = "aeiou";
    vector<array<int, 3>> cnt(n);
    vector<pair<int, int>> A, B;
    for (int i = 0; i < n; ++i) {
        cnt[i][2] = i;
        for (int j = 0; j < v[i].size(); ++j) {
            for (int k = 0; k < 5; ++k) {
                if(v[i][j] == t[k]){
                    cnt[i][0]++;
                    cnt[i][1] = k;
                }
            }
        }
    }
    sort(cnt.begin(),cnt.end());
    vector<int> matched(n+1);
    matched[n] = 1;
    for (int i = 0; i < n-1; ++i) {
        if(cnt[i][0] == cnt[i+1][0] && cnt[i][1] == cnt[i+1][1] && !matched[cnt[i][2]] && !matched[cnt[i+1][2]]){
            matched[cnt[i][2]] = matched[cnt[i+1][2]] = 1;
            A.emplace_back(cnt[i][2], cnt[i+1][2]);
            cnt[i] = cnt[i+1] = {-1, -1, n};
        }
    }
    sort(cnt.begin(), cnt.end());
    cnt.erase(unique(cnt.begin(), cnt.end()), cnt.end());
    for (int i = 0; i+1 < cnt.size(); ++i) {
        if(cnt[i][0] == cnt[i+1][0] && !matched[cnt[i][2]] && !matched[cnt[i+1][2]]) {
            matched[cnt[i][2]] = matched[cnt[i+1][2]] = 1;
            B.emplace_back(cnt[i][2], cnt[i+1][2]);
            cnt[i] = cnt[i+1] = {-1, -1, n};
        }
    }

    int cnt1 = 0, cnt2 = 0;
    {
        int l = A.size(), r = B.size();
        int ans = min(l, r); l -= ans; r -= ans;
        ans += l/2;
        cout << ans << "\n";

    }
    while(cnt2 < B.size() && cnt1 < A.size()){
        cout << v[B[cnt2].first] << " " << v[A[cnt1].first] << "\n";
        cout << v[B[cnt2].second] << " " << v[A[cnt1].second] << "\n";
        cnt1++;
        cnt2++;
    }
    while(cnt1+1 < A.size()){
        cout << v[A[cnt1].first] << " " << v[A[cnt1+1].first] << "\n";
        cout << v[A[cnt1].second] << " " << v[A[cnt1+1].second] << "\n";
        cnt1 += 2;
    }
    return 0;
}