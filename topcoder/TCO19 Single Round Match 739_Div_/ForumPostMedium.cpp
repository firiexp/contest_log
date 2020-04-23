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
using namespace std;

using ll = long long;

class ForumPostMedium {
    public:
    string getShownPostTime(string currentTime, string exactPostTime) {
        int nowtime = ((currentTime[0]-'0')*10+(currentTime[1]-'0'))*3600+
                ((currentTime[3]-'0')*10+(currentTime[4]-'0'))*60+
                ((currentTime[6]-'0')*10+(currentTime[7]-'0'));
        int posttime = ((exactPostTime[0]-'0')*10+(exactPostTime[1]-'0'))*3600+
                      ((exactPostTime[3]-'0')*10+(exactPostTime[4]-'0'))*60+
                      ((exactPostTime[6]-'0')*10+(exactPostTime[7]-'0'));
        if(nowtime < posttime) nowtime += 86400;
        int k = nowtime - posttime;
        if(k < 60) return "few seconds ago";
        else if(k < 3600) return (to_string(k/60) + " minutes ago");
        else return (to_string(k/3600) + " hours ago");
    }
};

// CUT begin
ifstream data("ForumPostMedium.sample");

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

bool do_test(string currentTime, string exactPostTime, string __expected) {
    time_t startClock = clock();
    ForumPostMedium *instance = new ForumPostMedium();
    string __result = instance->getShownPostTime(currentTime, exactPostTime);
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
        string currentTime;
        from_stream(currentTime);
        string exactPostTime;
        from_stream(exactPostTime);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(currentTime, exactPostTime, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1539184204;
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
        cout << "ForumPostMedium (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
