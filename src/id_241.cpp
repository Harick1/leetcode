class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        vector<int> indexes;
        for (int i(0); i < input.length(); i++)
            if (!(input[i] >= '0' && input[i] <= '9')) indexes.push_back(i);
        if (indexes.size() == 0) res.push_back(atoi(input.c_str()));
        for (int i(0); i < indexes.size(); i++) {
            string left = input.substr(0, indexes[i]);
            string right = input.substr(indexes[i]+1, input.length()-indexes[i]-1);
            vector<int> res_left = diffWaysToCompute(left);
            vector<int> res_right = diffWaysToCompute(right);
            for (int j(0); j < res_left.size(); j++) {
                for (int k(0); k < res_right.size(); k++)
                    res.push_back(calc(res_left[j], res_right[k], input[indexes[i]]));
            }
        }
        return res;
    }
    
    int calc(int a, int b, char c) {
        switch (c){
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
        }
    }
};