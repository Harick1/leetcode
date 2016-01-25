class Solution {
public:
    int singleNumber(int A[], int n) {
        int bits[32]={0}, res(0);
        for (int i(0); i < 32; i++) {
            for (int j(0); j < n; j++)
                bits[i] += (A[j]>>i)&1;
            res |= (bits[i]%3)<<i;
        }
        return res;
    }
};