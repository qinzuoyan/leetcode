
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        string s = to_string(x);
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j]) i++,j--;
        return i >= j;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
