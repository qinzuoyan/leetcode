// Copyright (c) 2019 xiaomi.com, Inc. All Rights Reserved.

#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string result;
        int gap = (numRows - 1) * 2, len = s.size(), x;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < len; j += gap) {
                if (i == 0) {
                    result += s[j];
                } else if (i == numRows - 1) {
                    x = j + numRows - 1;
                    if (x < len)
                        result += s[x];
                } else {
                    x = j + i;
                    if (x < len)
                        result += s[x];
                    x = j + gap - i;
                    if (x < len)
                        result += s[x];
                }
            }
        }
        return result;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
