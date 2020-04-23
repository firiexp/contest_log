#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <numeric>
#include <bitset>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <fstream>
static const int MOD = 1000000007;
using u32 = unsigned;
using namespace std;

using ll = long long;

class TwoLadders {
    public:
    long long minSteps(int sx, int lx1, int lx2, vector<int> X, vector<int> Y) {
        int n = X.size();
        vector<ll> z(n);
        for (int i = 0; i < n; ++i) {
            z[i] = Y[i];
        }
        z.emplace_back(0);
        sort(z.begin(), z.end());
        z.erase(unique(z.begin(), z.end()), z.end());
        auto f = [&z](ll i){return lower_bound(z.begin(),z.end(), i) - z.begin(); };
        vector<pair<ll, ll>> coins(n);
        for (int i = 0; i < n; ++i) {
            coins[i] = {f(Y[i]), X[i]};
        }
        int m = z.size();
        vector<ll> dp(m), dq(m);
        int k = (m != 1);
        {
            ll l = sx, r = sx;
            for (int i = 0; i < n; ++i) {
                if(coins[i].first == 0) {
                    l = min(l, coins[i].second);
                    r = max(r, coins[i].second);
                }
            }
            dp[0] = min(abs(sx-l)+abs(r-l)+k*abs(r-lx1),
                        abs(sx-r)+abs(r-l)+k*abs(l-lx1));
            dq[0] = min(abs(sx-l)+abs(r-l)+k*abs(r-lx2),
                        abs(sx-r)+abs(r-l)+k*abs(l-lx2));
        }
        for (int i = 1; i < m; ++i) {
            k = (i != m-1);
            ll l = lx1, r = lx1;
            for (int j = 0; j < n; ++j) {
                if(coins[j].first == i) {
                    l = min(l, coins[j].second);
                    r = max(r, coins[j].second);
                }
            }
            dp[i] = dp[i-1]+min(abs(lx1-l)+abs(r-l)+k*abs(r-lx1),
                        abs(lx1-r)+abs(r-l)+k*abs(l-lx1));
            dq[i] = dp[i-1]+min(abs(lx1-l)+abs(r-l)+k*abs(r-lx2),
                        abs(lx1-r)+abs(r-l)+k*abs(l-lx2));
        }
        for (int i = 1; i < m; ++i) {
            k = (i != m-1);
            ll l = lx2, r = lx2;
            for (int j = 0; j < n; ++j) {
                if(coins[j].first == i) {
                    l = min(l, coins[j].second);
                    r = max(r, coins[j].second);
                }
            }
            dp[i] = min({dp[i], dq[i-1]+abs(lx2-l)+abs(r-l)+k*abs(r-lx1),
                        dq[i-1]+abs(lx2-r)+abs(r-l)+k*abs(l-lx1)});
            dq[i] = min({dp[i], dq[i-1]+abs(lx2-l)+abs(r-l)+k*abs(r-lx2),
                        dq[i-1]+abs(lx2-r)+abs(r-l)+k*abs(l-lx2)});
        }
        return min(dp.back(), dq.back())+z.back();
    }
};

// CUT begin
ifstream data("TwoLadders.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int sx, int lx1, int lx2, vector<int> X, vector<int> Y, long long __expected) {
    time_t startClock = clock();
    TwoLadders *instance = new TwoLadders();
    long long __result = instance->minSteps(sx, lx1, lx2, X, Y);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int sx;
        from_stream(sx);
        int lx1;
        from_stream(lx1);
        int lx2;
        from_stream(lx2);
        vector<int> X;
        from_stream(X);
        vector<int> Y;
        from_stream(Y);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(sx, lx1, lx2, X, Y, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1563497964;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "TwoLadders (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
