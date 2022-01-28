// Copyright (c) 2019 xiaomi.com, Inc. All Rights Reserved.

#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int r = 0, len = s.size();
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if (c == 'M') {
                r += 1000;
            } else if (c == 'D') {
                r += 500;
            } else if (c == 'L') {
                r += 50;
            } else if (c == 'V') {
                r += 5;
            } else if (c == 'C') {
                r += 100;
                if (i < len - 1) {
                    char d = s[i + 1];
                    if (d == 'M') {
                        r += 800;
                        i++;
                    } else if (d == 'D') {
                        r += 300;
                        i++;
                    }
                }
            } else if (c == 'X') {
                r += 10;
                if (i < len - 1) {
                    char d = s[i + 1];
                    if (d == 'C') {
                        r += 80;
                        i++;
                    } else if (d == 'L') {
                        r += 30;
                        i++;
                    }
                }
            } else if (c == 'I') {
                r += 1;
                if (i < len - 1) {
                    char d = s[i + 1];
                    if (d == 'X') {
                        r += 8;
                        i++;
                    } else if (d == 'V') {
                        r += 3;
                        i++;
                    }
                }
            }
        }
        return r;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
