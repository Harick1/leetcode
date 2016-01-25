class Solution {
public:
    int bSearch(int A[], int start, int end, int target) {
        if (start > end)
            return -1;
        int mid = (start + end) / 2;
        if (target == A[mid])
            return mid;
        else if (target < A[mid]) 
            return bSearch(A, start, mid-1, target);
        else
            return bSearch(A, mid+1, end, target);
    }
    
    int getLeft(int A[], int start, int idx, int target) {
        if (A[start] == target)
            return start;
        int mid = (start + idx) / 2;
        if (A[mid] < target)
            return getLeft(A, mid+1, idx, target);
        else if (A[mid-1] == target)
            return getLeft(A, start, mid-1, target);
        else 
            return mid;
    }
    
    int getRight(int A[], int idx, int end, int target) {
        if (A[end] == target)
            return end;
        int mid = (idx + end) / 2;
        if (A[mid] > target)
            return getRight(A, idx, mid-1, target);
        else if (A[mid+1] == target)
            return getRight(A, mid+1, end, target);
        else
            return mid;
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        int idx = bSearch(A, 0, n, target);
        vector<int> res;
        if (idx == -1) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int tmp1(idx), tmp2(idx);
        tmp1 = getLeft(A, 0, idx, target);
        tmp2 = getRight(A, idx, n-1, target);
        res.push_back(tmp1);
        res.push_back(tmp2);
        return res;
    }
};