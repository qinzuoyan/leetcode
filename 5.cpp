
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;
        int start = 0, max_len = 1, len = s.size(), head, tail;
        for (int i = 0; i < len; i++) {
            // aba
            head = tail = i;
            while (head - 1 >= 0 && tail + 1 < len && s[head - 1] == s[tail + 1]) {
                head--;
                tail++;
            }
            if (tail - head + 1 > max_len) {
                max_len = tail - head + 1;
                start = head;
            }
            // aa
            head = i + 1;
            tail = i;
            while (head - 1 >= 0 && tail + 1 < len && s[head - 1] == s[tail + 1]) {
                head--;
                tail++;
            }
            if (head < tail && tail - head + 1 > max_len) {
                max_len = tail - head + 1;
                start = head;
            }
        }
        return s.substr(start, max_len);
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
