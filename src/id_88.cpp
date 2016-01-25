class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i(0), j(0), cnt(0);
        while (cnt < n) {
            if (B[j] < A[i]) {
                insert(A, m+cnt, i++, B[j++]);
                cnt++;
            } else {
                i++;
            }
        }
    }
    
    void insert(int A[], int len, int pos, int e) {
        int i(len);
        while (i > pos) {
            A[i] = A[i-1];
            i--;
        }
        A[i] = e;
    }
};