class Solution {
public:
    int reverse(int x) {
        int abs_x = abs(x);
        vector<int> res;
        while(abs_x > 0) {
            res.push_back(abs_x % 10);
            abs_x /= 10;
        }
        int ans = 0, tmp = 1;
        for (int i = res.size() - 1; i >= 0; i--) {
            ans += res[i] * tmp;
            tmp *= 10;
        }
        if (x > 0) {
            return ans;
        } else if(x < 0) {
            return -1 * ans;
        } else {
            return 0;
        }
    }
};