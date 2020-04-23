#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    locale::global(locale("ja_JP.UTF-8"));
    wcout.imbue(std::locale("ja_JP.UTF-8"));
    wcin.imbue(std::locale("ja_JP.UTF-8"));
    wstring s;
    getline(std::wcin, s);
    wstring t;
    s += u'う';
    vector<wstring> v;
    for (int i = 0; i+1 < s.size(); ++i) {
        if(s[i] == u'ｗ' && s[i+1] != u'ｗ') {
            t += s[i];
            v.emplace_back(t);
            t = {};
        }else t += s[i];
    }
    map<int, vector<wstring>> w;
    for (auto &i : v) {
        int cnt = 0;
        wstring x;
        for (wchar_t j : i) {
            if(j == u'ｗ') cnt++;
            else x += j;
        }
        if(i.size() != cnt) w[cnt].emplace_back(x);
    }
    if(!w.empty()){
        for (auto &&i : (*max_element(begin(w), end(w))).second) {
            wcout << i << "\n";
        }
    }
    return 0;
}
