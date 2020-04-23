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

using u32 = unsigned;
using namespace std;

using ll = long long;
static const ll MOD = 1000000007;
class StrawberryHard {
    public:

    template<typename T> T mod_inv(T x, T M){
        T u = 1, t = 1, v = 0, s = 0, m = M;
        while (x) { T q = m/x; swap(s -= q*u, u); swap(t -= q*v, v); swap(m -= q*x, x); }
        if(s < 0) s += M;
        return s;
    }

    int competitive(int n, int k, int Arange, int Brange, int seed) {
        ll state = seed;
        vector<int> A(2*k+1), B(2*k+1);
        ll s = 0, t = 0;
        for (int i = 0; i <= 2*k; ++i) {
            state = (1103515245*state+12345)%(1LL<<31);
            A[i] = state%Arange;
            s += A[i];
            state = (1103515245*state+12345)%(1LL<<31);
            B[2*k-i-1] = state%Brange;
            t += B[2*k-i-1];
        }
        s %= MOD; s = mod_inv(s, MOD);
        t %= MOD; t = mod_inv(t, MOD);
        for (int i = 0; i <= 2*k; ++i) {
            A[i] = (s*A[i])%MOD;
            B[i] = (t*B[i])%MOD;
        }

        return 0;
    }
};

// CUT begin
ifstream data("StrawberryHard.sample");

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

bool do_test(int n, int k, int Arange, int Brange, int seed, int __expected) {
    time_t startClock = clock();
    StrawberryHard *instance = new StrawberryHard();
    int __result = instance->competitive(n, k, Arange, Brange, seed);
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
        int n;
        from_stream(n);
        int k;
        from_stream(k);
        int Arange;
        from_stream(Arange);
        int Brange;
        from_stream(Brange);
        int seed;
        from_stream(seed);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, k, Arange, Brange, seed, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1562153008;
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
        cout << "StrawberryHard (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
