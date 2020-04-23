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
#include <unordered_set>

static const int MOD = 1000000007;
using u32 = unsigned;
using namespace std;

using ll = long long;

class CrazyCrazy {
    public:
    string possible(string song) {
        int n = song.size()/2;
        vector<unordered_set<string>> v(n+1);
        for (int i = 0; i < (1 << n); ++i) {
            string s, t;
            for (int j = 0; j < n; ++j) {
                if(i & (1 << j)) s += song[j];
                else t += song[j];
            }
            if(s > t) swap(s, t);
            int valid = true;
            for (int j = 0; j < min(s.size(), t.size()); ++j) {
                if(s[j] != t[j]) valid = false;
            }
            if(valid){
                string u;
                for (int j = s.size(); j < t.size(); ++j) {
                    u += t[j];
                }
                v[s.size()].emplace(u);
            }
        }
        for (int i = 0; i < (1 << n); ++i) {
            string s, t;
            for (int j = 0; j < n; ++j) {
                if(i & (1 << j)) s += song[j+n];
                else t += song[j+n];
            }
            if(s > t) swap(s, t);
            int valid = true;
            for (int j = 0; j < min(s.size(), t.size()); ++j) {
                if(s[j] != t[j]) valid = false;
            }
            if(valid){
                string u;
                for (int j = 0; j < t.size()-s.size(); ++j) {
                    u += t[j];
                }
                if(v[s.size()].count(u)) return "possible";
            }
        }
        return "impossible";
    }
};

// CUT begin
ifstream data("CrazyCrazy.sample");

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

bool do_test(string song, string __expected) {
    time_t startClock = clock();
    CrazyCrazy *instance = new CrazyCrazy();
    string __result = instance->possible(song);
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
        string song;
        from_stream(song);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(song, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1556191013;
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
        cout << "CrazyCrazy (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
