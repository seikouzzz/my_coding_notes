#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// leetcode 1. 两数之和

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            int a = target - nums[i];
            if (map.find(a) != map.end()) return {map[a], i};
            map[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    cout << "输出: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}