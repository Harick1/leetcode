class Solution {
public:
int findMinassist(vector<int> &num, size_t s, size_t e) {
        if (num[s] >= num[e] && s < e) {
                size_t mid = (s + e) / 2;
                if (num[s] > num[mid]) {
                        return findMinassist(num, s, mid);
                } else if (num[s] == num[mid]) {
                        int tmp1 = findMinassist(num, s, mid);
                        int tmp2 = findMinassist(num, mid+1, e);
                        return tmp1 > tmp2 ? tmp2 : tmp1;
                } else {
                        return findMinassist(num, mid+1, e);
                }
        } else {
                return num[s];
        }
}

int findMin(vector<int> &num) {
        size_t l = num.size() - 1;
        return findMinassist(num, 0, l);
}


};