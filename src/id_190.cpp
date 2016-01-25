class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        uint32_t tmp1 = 0b10000000000000000000000000000000;
        uint32_t tmp2 = 1;
        int cnt = 0;
        while (cnt < 32) {
            int bit = n / tmp1;
            res += tmp2 * bit;
            n = n % tmp1;
            tmp1 >>= 1;
            tmp2 <<= 1;
            cnt += 1;
        }
        return res;
    }
};