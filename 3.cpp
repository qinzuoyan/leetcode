// Copyright (c) 2019 xiaomi.com, Inc. All Rights Reserved.

#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int count[256];
        memset(count, 0, sizeof(count));
        int dup_num = 0, head = 0, tail = 0, result = 1, len = s.size();
        count[(unsigned)s[0]]++;
        while (tail < len - 1) {
            if ((++count[(unsigned)s[++tail]]) == 2)
                while (head < tail)
                    if ((--count[(unsigned)s[head++]]) == 1)
                        break;
            if (tail - head + 1 > result)
                result = tail - head + 1;
        }
        return result;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
