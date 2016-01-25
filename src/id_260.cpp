class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x(0), len(nums.size());
        for (int i(0); i < len; i++) 
            x ^= nums[i];
        int bit(1);
        while (!(x & bit)) bit <<= 1;
        int A(0), B(0);
        for (int i(0); i < len; i++) {
            if (bit & nums[i]) 
                A ^= nums[i];
            else
                B ^= nums[i];
        }
        return vector<int>({A, B});
    }
};