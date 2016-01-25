class Solution {
public:
    void reverseWords(string &s) {
        vector<string> ss;
        string str = s;
        int len = str.length();
        if (len == 0) {
            return;
        }
        for (int i = 0; i < len; i++) {
            if(str[i] != ' ') {
                string tmp;
                int j = i;
                while(str[j] != ' ' && j < len) {
                    tmp += str[j];
                    ++j;
                }
                ss.push_back(tmp);
                i = j;
            }
        }
        s.clear();
        for(int i = ss.size() - 1; i >= 0; i--) {
            s += ss[i];
            if (i > 0) {
                s += ' ';
            }
        }
    }
};