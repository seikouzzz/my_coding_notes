#include <iostream>
#include <vector>

using namespace std;

// leetcode 4. 寻找两个正序数组的中位数

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int n = nums1.size(), m = nums2.size();
        int half = (n + m + 1) / 2; 
        int l = 0, r = n;
        while (l <= r) {
            int i = (l+r) / 2;
            int j = half - i;
            
            int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i-1];
            int nums1RightMin = (i == n) ? INT_MAX : nums1[i];
            int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j-1];
            int nums2RightMin = (j == m) ? INT_MAX : nums2[j];

            if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
                if ((n + m) % 2 == 1) return max(nums1LeftMax, nums2LeftMax);
                else return ((max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0);
            } else{
                if (nums1LeftMax > nums2RightMin) r = i - 1;
                else l = i + 1;
            }
        }
        return 0.0;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = { 1, 2 };
    vector<int> nums2 = { 3, 4 };
    cout << solution.findMedianSortedArrays(nums1, nums2);
    return 0;
}