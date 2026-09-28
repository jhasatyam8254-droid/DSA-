class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightsum = 0;
        for(int i = 0; i < nums.size(); i++){
        rightsum+=nums[i];
        }

        int leftsum = 0;
        for(int i =0; i<nums.size(); i++){
            if(leftsum ==rightsum-nums[i]){
                return i;
            }

            leftsum += nums[i];
            rightsum -= nums[i];
        }

        return -1;
    }
};