class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if(nums[0]<=nums[n-1]){
            return nums[0];
        }

        int left = 0, right = n-1;
        int minElement;

        while(left<=right){
            int mid = left + (right-left) / 2;
            
            if(nums[mid]>=nums[0]){
                left = mid+1;
            }
            else{
                right = mid-1;
                minElement = nums[mid];
            }
        }
        return minElement;
    }
};