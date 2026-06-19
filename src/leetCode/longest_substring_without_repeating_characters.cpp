#include <iostream>
#include <string>

using namespace std;

// leetcode 3. 无重复字符的最长字串

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0 || n == 1) return "01"[n] - '0';
        int last[128];
        fill(last, last + 128, -1);
        int left = 0, right = 0;
        int res = 0;
        while (right < n) {
            unsigned char c = s[right];
            if (last[c] >= left) {
                res = max(res, right - left);
                left = last[c] + 1;
            }
            last[c] = right;
            right++;
        }
        res = max(res, right - left);
        return res;
    }
};

int main() {
    Solution solution;
    string s = "abcd";
    int res = solution.lengthOfLongestSubstring(s);
    cout << res << endl;
    return 0;
}