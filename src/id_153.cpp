class Solution {
public:
    int findMin(vector<int> &num) {
        size_t l = num.size() - 1;
        size_t i = 0;
        while (num[i] > num[l]) {
                size_t mid = (i + l) / 2;
                if (num[i] > num[mid]) {
                        l = mid;
                } else {
                        i = mid + 1;
                }
        }
        return num[i];
    }
};