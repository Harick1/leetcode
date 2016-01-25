class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        sort(S.begin(), S.end());
        res = getSubsets(S, 0);
        return res;
    }
    
    vector<vector<int> > getSubsets(vector<int>&S, int i) {
        vector<vector<int> > v, res;
        if (i == S.size()) { 
            vector<int> tmp;
            res.push_back(tmp);
            return res;
        }
        
        v = getSubsets(S, i+1);
        int n = S[i];
        for (int i(0); i < v.size(); i++) {
            vector<int> tmp = v[i];
            if (!exists(res, tmp))
                res.push_back(tmp);
            tmp.insert(tmp.begin(), n);
            if (!exists(res, tmp))
                res.push_back(tmp);
        }
        return res;
    }
    
    bool exists(vector<vector<int> > all, vector<int> single) {
        bool flg = false;
        for (int i(0); i < all.size(); i++) {
            vector<int> tmp = all[i];
            if (tmp.size() != single.size()) continue;
            int j(0);
            for (; j < tmp.size(); j++) {
                if (tmp[j] != single[j]) break;
            }
            if (j == tmp.size()) {
                flg = true;
                break;
            }
        }
        return flg;
    }
};