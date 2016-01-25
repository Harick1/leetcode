bool cmp(const string& s1, const string& s2) {
    return ((s1 + s2) > (s2 + s1));
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> num_s;
        for (vector<int>::iterator i = num.begin(); i < num.end(); i++) {
            num_s.push_back(to_string(*i));
        }
        sort(num_s.begin(), num_s.end(), cmp);
        string res = "";
        for (vector<string>::iterator i = num_s.begin(); i < num_s.end(); i++) {
            if (res == "" && *i == "0")
                return "0";
            res += *i;
        }
        return res == "" ? "0" : res;
    }
};