class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;

        int leftmax = 0, rightmax = 0;
        int maxheight = height[0];
        int index = 0;

        // Find index of maximum height
        for (int i = 1; i < n; i++) {
            if (maxheight < height[i]) {
                maxheight = height[i];
                index = i;
            }
        }

        // Left side
        for (int i = 0; i < index; i++) {
            if (leftmax > height[i])
                water += leftmax - height[i];
            else
                leftmax = height[i];
        }

        // Right side
        for (int i = n - 1; i > index; i--) {
            if (rightmax > height[i])
                water += rightmax - height[i];
            else
                rightmax = height[i];
        }

        return water;
    }
};