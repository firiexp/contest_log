#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
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

class ModularQuadrant {
    public:
    long long sum(int r1, int r2, int c1, int c2) {
        ll ans = 0;
        if(c1 <= r1){
            swap(r1, c1), swap(r2, c2);
        }
        if(r1 < c1){
            ll p = c1-r1, q = 0;
            for (ll i = c1+1; i < c2; ++i) {
                if(i%3 == 0){
                    q += (c2-i)/3*3;
                    i += (c2-i)/3;
                }else {
                    q += i%3;
                }
            }
            ans += p*q;
            c1 = r1;
        }
        if(c2 <= r2){
            swap(r1, c1), swap(r2, c2);
        }
        if(r2 < c2){
            ll p = r2-r1, q = 0;
            for (ll i = c1; i < c2; ++i) {
                if(i%3 == 0){
                    q += (c2-i)/3*3;
                    i += (c2-i)/3;
                }else {
                    q += i%3;
                }
            }
            c2 = r2;
        }
        return 0;
    }
};

// CUT begin
ifstream data("ModularQuadrant.sample");

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

bool do_test(int r1, int r2, int c1, int c2, long long __expected) {
    time_t startClock = clock();
    ModularQuadrant *instance = new ModularQuadrant();
    long long __result = instance->sum(r1, r2, c1, c2);
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
        int r1;
        from_stream(r1);
        int r2;
        from_stream(r2);
        int c1;
        from_stream(c1);
        int c2;
        from_stream(c2);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(r1, r2, c1, c2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1544804224;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "ModularQuadrant (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
