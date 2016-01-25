class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 1) res.push_back(nums[0]);
        int tmp = 1;
        res.push_back(tmp);
        for (int i(0); i < nums.size()-1; i++) {
            tmp *= nums[i];
            res.push_back(tmp);
        }
        tmp = 1;
        for (int i(nums.size()-1); i > 0; i--) {
            tmp *= nums[i];
            res[i-1] *= tmp;
        }
        return res;
    }
};