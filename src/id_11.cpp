class Solution {
public:
    int maxArea(vector<int>& height) {
        int num = height.size();
        if (num <= 1) return 0;
        int i(0), j(num-1);
        int area(0);
        while (i < j) {
            int h = height[j] > height[i] ? height[i] : height[j];
            area = h*(j-i) > area ? h*(j-i) : area;
            if (height[j] < height[i]) j--;
            else i++;
        }
        return area;
    }
};