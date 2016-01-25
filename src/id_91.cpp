class Solution {
public:
    int numDecodingshelp(string s) {
        if (!s.size() || s[0] == '0')
            return 0;
        if (s.size() == 1)
            return 1;
        if (s.size() == 2)
            if (atoi(s.c_str()) % 10 == 0 || atoi(s.c_str()) > 26)
                return 1;
            else
                return 2;
        int a = s[0] - '0', b = s[0] - '0';
        int sum = a * 10 + b;
        if (sum > 26 || sum % 10 == 0)
            return numDecodingshelp(s.substr(2));
        else
            return numDecodingshelp(s.substr(1)) + numDecodingshelp(s.substr(2));
    }
    
    int numDecodings(string s) {
        if (!s.size() || s[0] == '0')
            return 0;
        int res = 1;
        string tmp;
        for (size_t i = 0; i < s.size(); i++) {
            tmp += s[i];
            if (s[i] == '0' || s[i] > '2' || i+1 == s.size()) {
                res *= numDecodingshelp(tmp);
                tmp.clear();
            }
        }
        return res;
    }
};