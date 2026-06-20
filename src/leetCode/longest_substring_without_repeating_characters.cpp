#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// leetcode 3. 无重复字符的最长字串

class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        unsigned short n = s.size();
        static unsigned short last[128];
        memset(last, 0, sizeof(last));
        unsigned short left = 0, right = 0;
        unsigned short res = 0;
        while (right < n) {
            unsigned char c = s[right];
            if ((last[c] != 0) && ((last[c]-1) >= left)) left = last[c];
            last[c] = right + 1;
            right++;
            res = res > (right - left) ? res : (right - left);
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s = "aab";
    int res = solution.lengthOfLongestSubstring(s);
    cout << res << endl;
    return 0;
}