class Solution {
public:
    int countDigitOne(int n) {
        int d(1), tmp(n/10);
        while (tmp) {
            tmp /= 10;
            d *= 10;
        }
        if (d == 1) 
            return n >= 1;
        int f(n/d), s(n%d);
        if (f == 1) 
            return (countDigitOne(s) + s + 1 + countDigitOne(d-1));
        else 
            return (countDigitOne(s) + f * countDigitOne(d-1) + d);
    }
};