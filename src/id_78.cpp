class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        sort(S.begin(), S.end());
        res = getSubsets(S, 0);
        return res;
    }
    
    vector<vector<int> > getSubsets(vector<int>&S, int i) {
        vector<vector<int> > v, res;
        if (i == S.size()) { 
            vector<int> tmp;
            v.push_back(tmp);
            return v;
        }
        
        v = getSubsets(S, i+1);
        int n = S[i];
        for (int i(0); i < v.size(); i++) {
            vector<int> tmp = v[i];
            res.push_back(tmp);
            tmp.insert(tmp.begin(), n);
            res.push_back(tmp);
        }
        return res;
    }
};