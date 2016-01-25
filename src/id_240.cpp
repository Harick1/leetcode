class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rmin(0), rmax(matrix.size()-1);
        int cmin(0), cmax(matrix[0].size()-1);
        return searchMatrixPlus(matrix, rmin, cmin, rmax, cmax, target);
    }
    
    bool searchMatrixPlus(vector<vector<int>>& matrix, int rmin, int cmin, int rmax, int cmax, int target) {
        if (rmin == rmax && cmin == cmax) return target == matrix[rmin][cmin];
        int rmid = (rmin+rmax)/2, cmid = (cmin+cmax)/2;
        if (matrix[rmid][cmid] == target) return true;
        if (matrix[rmid][cmid] < target) {
            if (cmid == cmax) return searchMatrixPlus(matrix, rmid+1, cmin, rmax, cmax, target);
            if (rmid == rmax) return searchMatrixPlus(matrix, rmin, cmid+1, rmax, cmax, target);
            return searchMatrixPlus(matrix, rmin, cmid+1, rmax, cmax, target) ||
                    searchMatrixPlus(matrix, rmid+1, cmin, rmax, cmid, target);
        } else {
            if (cmid == cmax) return searchMatrixPlus(matrix, rmin, cmin, rmid, cmax, target);
            if (rmid == rmax) return searchMatrixPlus(matrix, rmin, cmin, rmax, cmid, target);
            return searchMatrixPlus(matrix, rmin, cmin, rmax, cmid, target) ||
                    searchMatrixPlus(matrix, rmin, cmid, rmid, cmax, target);
        }
    }
};