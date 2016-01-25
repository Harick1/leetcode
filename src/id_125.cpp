class Solution {
public:
char lower(char c) {
    if (c >= '0' && c <= '9' ||
            c >= 'a' && c <= 'z')
        return c;
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return 0;
}

bool isPalindrome(string s) {
    if (s.length() == 0)
        return true;
    int start(0), end(s.length()-1);
    while (start < end) {
        char tmp1 = lower(s[start]);
        char tmp2 = lower(s[end]);
        if (!tmp1) {
            start++;
            continue;
        }
        if (!tmp2) {
            end--;
            continue;
        }
        if (tmp1 == tmp2) {
            start++;
            end--;
        } else
            return false;
    }
    return true;
}
    // bool isPalindrome(string s) {
        
    // }
};