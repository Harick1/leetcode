class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        vector<string> pos;
        for (int i(0); i < numRows; i++) {
            string tmp = "";
            pos.push_back(tmp);
        }
        int r = 0, flg = -1, a[s.length()] = {0};
        for (int i(0); i < s.length(); i++) {
            pos[r] += s[i];
            if (r == numRows-1 || r == 0) flg *= -1;
            r += flg;
        }
        string res = "";
        for (int i(0); i < pos.size(); i++)
            res += pos[i];
        return res;
    }
};