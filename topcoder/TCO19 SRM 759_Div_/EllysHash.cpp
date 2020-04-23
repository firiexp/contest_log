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
static const long long MOD = 1000000000000037;
using u32 = unsigned;
using namespace std;

using ll = long long;

class EllysHash {
    public:
    long long getHash(int N, string A, string B, string C) {
        vector<ll> v{0};
        ll a = 1, b = 127;
        reverse(A.begin(),A.end());
        reverse(B.begin(),B.end());
        reverse(C.begin(),C.end());
        for (int i = 0; i < N/2; ++i) {
            vector<ll> v2;
            for (ll j : v) {
                v2.emplace_back((j+a*A[i])%MOD);
                v2.emplace_back((j+a*B[i])%MOD);
                v2.emplace_back((j+a*C[i])%MOD);
            }
            (a *= b) %= MOD;
            v.swap(v2);
        }
        vector<ll> vv{0};
        for (int i = N/2; i < N; ++i) {
            vector<ll> v2;
            for (ll j : vv) {
                v2.emplace_back((j+a*A[i])%MOD);
                v2.emplace_back((j+a*B[i])%MOD);
                v2.emplace_back((j+a*C[i])%MOD);
            }
            (a *= b) %= MOD;
            vv.swap(v2);
        }
        sort(v.begin(),v.end());
        sort(vv.begin(),vv.end());
        ll ans = MOD;
        for (auto &&k : v) {
            ll ta = MOD-k;
            auto cur = lower_bound(vv.begin(),vv.end(), ta);
            if(cur == vv.end()) cur = vv.begin();
            ans = min(ans, (*cur+k)%MOD);
        }
        return ans;
    }
};

// CUT begin
ifstream data("EllysHash.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int N, string A, string B, string C, long long __expected) {
    time_t startClock = clock();
    EllysHash *instance = new EllysHash();
    long long __result = instance->getHash(N, A, B, C);
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
        int N;
        from_stream(N);
        string A;
        from_stream(A);
        string B;
        from_stream(B);
        string C;
        from_stream(C);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, A, B, C, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1559129845;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "EllysHash (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
