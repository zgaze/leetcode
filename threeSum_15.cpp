#include <vector>

class Solution {
public:
    /**
     * @brief 寻找数组中所有和为 0 的不重复三元组
     * @param nums 输入的整数数组
     * @return std::vector<std::vector<int>> 包含所有符合条件的三元组列表
     */
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        int i = 0, j = 0, k = 0;
        for (i = 0; i < j; ++i) {
            for (j = i+1; j < k; ++j) {
                for (k = j+1; k < nums.size(); ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        res.emplace_back(i, j, k);
                    }
                }
                if (nums[i] + nums[j] > 0) break;
            }
            if (nums[i] > 0) break;
        }
        return res;
    }
};