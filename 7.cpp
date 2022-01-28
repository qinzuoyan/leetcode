
#include <string>
#include <cstdlib>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        int len = str.size();
        int i = str[0] == '-' ? 1 : 0;
        int j = len - 1;
        while (i < j) {
            char c = str[i];
            str[i++] = str[j];
            str[j--] = c;
        }
        char *p;
        long long int n = strtoll(str.c_str(), &p, 10);
        if (*p != '\0')
            return 0;
        if (n > INT_MAX || n < INT_MIN)
            return 0;
        return n;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
