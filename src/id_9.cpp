class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int tmp1(1), tmp2(10);
        while (x / tmp1 >= 10)
            tmp1 *= 10;
        while (tmp1 >= tmp2) {
            int f = x / tmp1 % 10;
            int l = x % tmp2 / (tmp2 / 10);
            if (f != l)
                return false;
            tmp1 /= 10;
            tmp2 *= 10;
        }
        return true;
    }

};
