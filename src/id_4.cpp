class Solution {
public:
    double findKth(int a[], int m, int b[], int n, int k) {
        if (m > n) return findKth(b, n, a, m, k);
        if (m == 0) return b[k-1];
        if (k == 1) return min(a[0], b[0]);
        int pa = min(k/2, m);
        int pb = k - pa;
        if (a[pa-1] == b[pb-1]) 
            return a[pa-1];
        else if (a[pa-1] > b[pb-1])
            return findKth(a, pa, b+pb, n-pb, k-pb);
        else
            return findKth(a+pa, m-pa, b, pb, k-pa);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        if (size % 2 == 0)
            return (findKth(&(nums1[0]), nums1.size(), &(nums2[0]), nums2.size(), size / 2) +
                    findKth(&(nums1[0]), nums1.size(), &(nums2[0]), nums2.size(), size / 2 + 1)) / 2;
        else
            return findKth(&(nums1[0]), nums1.size(), &(nums2[0]), nums2.size(), size / 2 + 1);
    }
    
};