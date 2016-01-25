class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.size() == 0) return res;
        int j(0);
        while (1) {
            if (strs[0] == "") return res;
            if (j > strs[0].length() - 1) return res;
            char tmp = strs[0][j];
            int i(1);
            for (; i < strs.size(); i++) {
                if (strs[i] == "" || j > strs[i].length() - 1 || tmp != strs[i][j]) return res;
            }
            res.push_back(tmp);
            j++;
        }
    }
};