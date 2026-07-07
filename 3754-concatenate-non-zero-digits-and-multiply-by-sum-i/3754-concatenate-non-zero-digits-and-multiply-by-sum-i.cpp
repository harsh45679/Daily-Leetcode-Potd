class Solution {
public:
    long long sumAndMultiply(int n) {

        if(n== 0){
            return 0;
        }
        long long sum = 0;
        string nonzero = "";
         string number = to_string(n);
         for(int i = 0;i<number.length();i++){
            char ch = number[i];
            if(ch != '0'){
              nonzero = nonzero + ch;
             int val = ch - '0';
             sum = sum + val;
            }
         }

    
      int   result = stoi(nonzero);
        long long ans = result  * sum;
        return ans;
    }
};