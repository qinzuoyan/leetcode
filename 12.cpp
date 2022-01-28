
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    struct Pair {
        Pair(int n_, const string& s_): n(n_),s(s_) {}
        int n;
        string s;
    };

    Solution() {
        _v.emplace_back(1000, "M");
        _v.emplace_back(900, "CM");
        _v.emplace_back(500, "D");
        _v.emplace_back(400, "CD");
        _v.emplace_back(100, "C");
        _v.emplace_back(90, "XC");
        _v.emplace_back(50, "L");
        _v.emplace_back(40, "XL");
        _v.emplace_back(10, "X");
        _v.emplace_back(9, "IX");
        _v.emplace_back(5, "V");
        _v.emplace_back(4, "IV");
        _v.emplace_back(1, "I");
    }

    string intToRoman(int num) {
        string r;
        int i = 0;
        while (num > 0) {
            Pair &p = _v[i];
            if (p.n <= num) {
                r += p.s;
                num -= p.n;
            } else {
                i++;
            }
        }
        return r;
    }

private:
    vector<Pair> _v;
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
