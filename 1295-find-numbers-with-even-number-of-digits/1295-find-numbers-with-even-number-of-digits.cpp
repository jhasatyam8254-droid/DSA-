class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;

        for(int i = 0; i <nums.size(); i++){
            int digit = 0;
            int num = nums[i];

            while(num>0){
                num/=10;
                digit++;

            }

            if(digit % 2 == 0){
                count++;
            }
        }

        return count;
    }
};