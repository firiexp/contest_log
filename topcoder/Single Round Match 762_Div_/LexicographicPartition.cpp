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

class LexicographicPartition {
    public:
    vector<int> positiveSum(int n, vector<int> Aprefix, int seed, int Arange) {
        vector<int> A(n);
        for (int i = 0; i < Aprefix.size(); ++i) {
            A[i] = Aprefix[i];
        }
        ll state = seed;
        for (int i = Aprefix.size(); i < n; ++i) {
            state = (1103515245*state+12345);
            A[i] = state%(2*Arange+1);
            A[i] = A[i] - Arange;
            state = state % (1LL<<31);
        }
        ll S = accumulate(A.begin(),A.end(), 0LL);
        if(S <= 0) return vector<int> {-1};
        vector<int> ans;
        ll partial = 0;
        int cur = -1;
        for (int i = 0; i < n; ++i) {
            partial += A[i];
            if(partial > 0 && S > partial){
                S -= partial;
                ans.emplace_back(i-cur);
                cur = i;
                partial = 0;
            }
        }
        ans.emplace_back(n-1-cur);
        reverse(ans.begin(),ans.end());
        ans.emplace_back(ans.size());
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// CUT begin
ifstream data("LexicographicPartition.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(int n, vector<int> Aprefix, int seed, int Arange, vector<int> __expected) {
    time_t startClock = clock();
    LexicographicPartition *instance = new LexicographicPartition();
    vector<int> __result = instance->positiveSum(n, Aprefix, seed, Arange);
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
        vector<int> Aprefix;
        from_stream(Aprefix);
        int seed;
        from_stream(seed);
        int Arange;
        from_stream(Arange);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, Aprefix, seed, Arange, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1562152172;
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
        cout << "LexicographicPartition (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
