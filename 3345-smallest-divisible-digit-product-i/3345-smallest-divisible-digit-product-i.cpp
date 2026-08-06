class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = 1;
        for(int i = n;i<INT_MAX;i++){
            int val = i;
             int product = 1;
             while(val != 0){
                int digit = val % 10;
                product = product * digit;
                val = val/10;
             }

             if(product % t == 0){
           ans  = i;
           break;
             }
        }

        return ans;
    }
};