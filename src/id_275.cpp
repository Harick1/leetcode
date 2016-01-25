class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int left(0), right(len-1);
        while(left <= right) {
            int mid = (left + right) * 0.5;
            if ((len-mid) == citations[mid]) return len-mid;
            else if ((len-mid) > citations[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return len - left;
    }
};