class Solution {
public:
    string simplifyPath(string s) {
        string path;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '/')
                while(s[i+1] == '/')
                    i++;
            path += s[i];
        }
        vector<string> v_res;
        size_t len = path.size();
        if (path == "/")
            return path;
        path += "/";
        for (size_t i = 0; i < len; i++) {
            if (path[i] == '/' && i+1 < len) {
                string tmp;
                while (path[i+1] != '/') {
                    tmp += path[++i];
                }
                if(tmp[0] == '.' && tmp.size() < 3 && v_res.empty()) {
                    v_res.push_back("/");
                    continue;
                }
                if (tmp == "..") {
                    v_res.erase(v_res.end()-1);
                    if (v_res.empty())
                        v_res.push_back("/");
                    continue;
                } else if(tmp == ".") {
                    continue;
                }
                if(!v_res.empty())
                    if (v_res.back() == "/") {
                        v_res.push_back(tmp);
                        continue;
                    }
                v_res.push_back("/" + tmp);
            }
        }
        string res;
        for (vector<string>::iterator i = v_res.begin(); i != v_res.end(); i++) {
            res += *i;
        }
        return res;
    }
};