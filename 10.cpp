
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();
        if (p[0] == '*' || p.find("**") != string::npos) // invalid pattern
            return false;
        int slen = s.size(), plen = p.size(), alen = (slen + 1) * (plen + 1);
        int *a = new int[alen];
        for (int i = 0; i < alen; i++)
            a[i] = -1;
        a[0] = 1; // null pattern && null string
        bool b = match(a, plen + 1, s, slen - 1, p, plen - 1);
        delete []a;
        return b;
    }

    bool match(int *a, int y, const std::string& s, int i, const std::string &p, int j) {
        int pos = (i + 1) * y + (j + 1);
        if (a[pos] != -1) {
            return a[pos];
        }
        if (j == -1) { // null pattern
            a[pos] = false;
        } else if (i == -1) { // null string
            if (p[j] == '*') {
                a[pos] = match(a, y, s, i, p, j - 2);
            } else {
                a[pos] = false;
            }
        } else if (p[j] == '*') {
            if (p[j - 1] == '.' || p[j - 1] == s[i]) {
                a[pos] = match(a, y, s, i - 1, p, j - 2) || match(a, y, s, i, p, j - 2) || match (a, y, s, i - 1, p, j);
            } else {
                a[pos] = match(a, y, s, i, p, j - 2);
            }
        } else if (p[j] == '.' || p[j] == s[i]) {
            a[pos] = match(a, y, s, i - 1, p, j - 1);
        } else {
            a[pos] = false;
        }
        return a[pos];
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
