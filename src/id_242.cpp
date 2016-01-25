class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26] = {0}, b[26] = {0};
        for (int i = 0; i < s.length(); i++)
            a[s[i]-'a']++;
        for (int i = 0; i < t.length(); i++)
            b[t[i]-'a']++;
        for (int j = 0; j < 26; j++)
            if (a[j] != b[j]) return false;
        return true;
    }
};