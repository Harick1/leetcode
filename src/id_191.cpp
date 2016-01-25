class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res(0), cnt(0);
        uint32_t tmp = 0b10000000000000000000000000000000;
        while (cnt < 32) {
            res += n / tmp;
            n %= tmp;
            tmp >>= 1;
            cnt += 1;
        }
        return res;
    }
};