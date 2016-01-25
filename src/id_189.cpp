class Solution {
public:
    void rotate(int nums[], int n, int k) {
        int t = k % n;
        int *head = new int[n-t];
        int *tail = new int[t];
        for (int i = 0; i < n-t; i++) {
            head[i] = nums[i];
        }
        for (int i = 0; i < t; i++) {
            tail[i] = nums[n-t+i];
        }
        for (int i = 0; i < n; i++) {
            if (i < t) {
                nums[i] = tail[i];
            } else {
                nums[i] = head[i - t];
            }
        }
        delete [] head;
        delete [] tail;
    }
};