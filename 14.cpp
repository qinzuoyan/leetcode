
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return string();
        int i = 0, len = strs.size();
        const string& str0 = strs[0];
        while (i < str0.size()) {
            char c = str0[i];
            int j = 1;
            for (; j < len; j++) {
                const string &s = strs[j];
                if (i >= s.size() || s[i] != c)
                    break;
            }
            if (j != len)
                break;
            i++;
        }
        return str0.substr(0, i);
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
