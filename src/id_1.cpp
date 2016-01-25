class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, vector<int> > iMap;
        size_t n = numbers.size();
        for (size_t i(0); i < n; i++) 
            iMap[numbers[i]].push_back(i+1);
        map<int, vector<int> >::iterator id1 = iMap.begin(), id2;
        int x, y, index1, index2;
        for (; id1 != iMap.end(); id1++) {
            x = id1->first;
            y = target - x;
            if (x == y && id1->second.size() > 1) {
                index1 = id1->second[0];
                index2 = id1->second[1];
                break;
            }
            id2 = iMap.find(y);
            if (id2 != iMap.end()) {
                index1 = id1->second[0];
                index2 = id2->second[0];
                break;
            }
        }
        //cout << res[0] << " " << res[1] << endl;
        vector<int> res;
        res.push_back(index1 > index2 ? index2 : index1);
        res.push_back(index1 > index2 ? index1 : index2);
        return res;
    }
};