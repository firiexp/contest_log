#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    locale::global(locale("ja_JP.UTF-8"));
    wcout.imbue(locale("ja_JP.UTF-8"));
    wcin.imbue(locale("ja_JP.UTF-8"));
    wstring ans;
    int c = 0;
    for (int i = 0; i < (1<<n); ++i) {
        vector<int> v(n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &v[j]);
        }
        int k;
        cin >> k;
        if(k == 1){
            if(!ans.empty()) ans += u'∨';
            ans += u'(';
            for (int j = 0; j < n; ++j) {
                if(j) ans += u'∧';
                if(v[j] == 0) ans += u'¬';
                ans += L"P_";
                ans += to_wstring(j+1);

            }
            ans += u')';
            c++;
        }
    }
    if(ans.empty()) ans = L"⊥";
    if(c == (1 << n)) ans = L"⊤";
    wcout << L"A=" << ans << L"\n";
    return 0;
}
