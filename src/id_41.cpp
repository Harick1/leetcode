class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) return 1;
        for (int i(0); i <nums.size(); i++) {
            if (nums[i] > 0) {
                int tmp = nums[i];
                if (nums[tmp-1] == tmp || tmp > nums.size()) continue;
                nums[i] = nums[tmp-1];
                nums[tmp-1] = tmp;
                i--;
            }
        }
        for (int i(0); i < nums.size(); i++) {
            if (i+1 != nums[i]) return i+1;
        }
        return nums.size()+1;
    }
};