class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<string>::iterator it = tokens.begin();
        int res;
        while (it != tokens.end()) {
            if (*it == "+" || *it == "-" || *it == "*" || *it == "/") {
                int tmp;
                string a(*(it-2)), b(*(it-1));
                if(*it == "+")
                    tmp = atoi(a.c_str()) + atoi(b.c_str());
                else if (*it == "-")
                    tmp = atoi(a.c_str()) - atoi(b.c_str());
                else if (*it == "*")
                    tmp = atoi(a.c_str()) * atoi(b.c_str());
                else 
                    tmp = atoi(a.c_str()) / atoi(b.c_str());
                string s_tmp;
                stringstream ss;
                ss << tmp;
                ss >> s_tmp;
                vector<string>::iterator i_tmp = tokens.erase(it-2, it+1);
                it = tokens.insert(i_tmp, s_tmp);
            }
            it++;
        }
        return atoi(tokens[0].c_str());
    }
};