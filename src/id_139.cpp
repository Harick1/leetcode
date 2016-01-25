class Solution {
public:
    bool wordBreakSub(string s, unordered_set<string> &dict, unordered_set<string> &unmatch) {
        unordered_set<string>::const_iterator got = dict.find(s);
        if (got != dict.end())
            return true;
        if (s.size() <= 1)
            return false;
        bool res = false;
        for (size_t i = 0; i < s.size()-1; i++) {
            string tmp1 = s.substr(0, i+1);
            if (unmatch.find(tmp1) != unmatch.end())
                continue;
            if (dict.find(tmp1) != dict.end()) {
                string tmp2 = s.substr(i+1);
                if (unmatch.find(tmp2) != unmatch.end())
                    continue;
                if (wordBreakSub(tmp2, dict, unmatch))
                    return true;
                else
                    unmatch.insert(tmp2);
                    
            } else
                unmatch.insert(tmp1);
        }
        return res;
    }
    
    bool wordBreak(string s, unordered_set<string> &dict) {
        unordered_set<string> unmatch;
        return wordBreakSub(s, dict, unmatch);
    }
};