class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n2(num2.size());
        vector<string> ress;
        for (int i(0); i < n2; i++) {
            string tmp, res_tmp;
            tmp.push_back(num2[i]);
            res_tmp = multiplySimple(num1, tmp);
            for (int j(i+1); j < n2; j++)
                res_tmp.push_back('0');
            ress.push_back(res_tmp);
        }
        string res = addString(ress);
        return res;
    }
    
    string multiplySimple(string num1, string num2) {
        int flg(0), n1(num1.size()), q(num2[0]-'0');
        string res;
        for (int i(n1-1); i >= 0; i--) {
            int p(num1[i]-'0');
            char c = '0' + (p * q + flg) % 10;
            flg = (p * q + flg) / 10;
            res.push_back(c);
        }
        if (flg > 0) res.push_back('0' + flg);
        string result;
        for (int i(res.size()-1); i >= 0; i--)
            result.push_back(res[i]);
        return result;
    }
    
    string addString(vector<string> inputs) {
        string res;
        int flg(0), maxlen(0);
        for (int i(0); i < inputs.size(); i++) {
            if (maxlen < inputs[i].length()) maxlen = inputs[i].length();
        }
        for (int i(1); i <=maxlen; i++) {
            int tmp = flg;
            for (int j(0); j < inputs.size(); j++) {
                if (inputs[j].length() < i)
                    continue;
                tmp += (inputs[j][inputs[j].length()-i] - '0');
            }
            char c = tmp % 10 + '0';
            res.push_back(c);
            flg = tmp / 10;
        }
        if (flg > 0) res.push_back('0' + flg);
        string result;
        for (int i(res.size()-1); i >= 0; i--)
            result.push_back(res[i]);
        return result;
    }
};