class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        
        int ans = 0;
        for(int i =0;i<nums.size();i++){
            int size = 0;
            int count = 0;
       for(int j = i;j<nums.size();j++){
        if(nums[j] == target){
            count++;
        }
        size++;
        if(size/2 < count){
            ans++;
        }
       }

        }
        return ans;
    }
};