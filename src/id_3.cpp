class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res(0), pos[256] = {0}, left(-1);
        size_t len(s.size());
        for (size_t i(0); i < len; i++) {
            int tmp = s[i];
            if (pos[tmp] > left)
                left = pos[tmp] - 1;
            pos[tmp] = i + 1;
            if (res < i - left)
                res = i - left;
        }
        return res;
    }
};