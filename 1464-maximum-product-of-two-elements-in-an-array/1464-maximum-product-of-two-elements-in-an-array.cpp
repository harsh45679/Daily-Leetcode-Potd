class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i = 0;i<nums.size()-1;i++){
            for(int j = i+1;j<nums.size();j++){
                int a = nums[i]-1;
                int b = nums[j]-1;
                int c = a*b;
                maxi = max(maxi , c);
            }
        }
        return maxi;
    }
};