class Solution {
public:
    int search(int A[], int n, int target) {
        if (n == 1)
            return A[0] == target ? 0 : -1;
        int i(0);
        for (; i < n; i++) {
            if (A[i] > A[(i+1)%n])
                break;
        }
        return bsearch(A, (i+1)%n, i, target, n);
    }
    
    int bsearch(int A[], int begin, int end, int target, int n) {
        int mid;
        if (begin == end)
            return A[begin] == target ? begin : -1;
        else
            mid = (begin < end ? (begin + end) / 2 : (begin + end + n) / 2) % n;
        if (A[mid] == target)
            return mid;
        else if (A[mid] > target)
            return bsearch(A, begin, mid, target, n);
        else
            return bsearch(A, (mid+1)%n, end, target, n);
    }
};