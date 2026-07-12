class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>rank(arr.size() , 0);
        vector<int>temp = arr;
        sort(temp.begin(), temp.end());
        int ranking  = 0;
        unordered_map<int , int>mp;

        for(int i = 0;i<temp.size();i++){
            int element = temp[i];
            if(mp.find(element) != mp.end()){
                continue;
            }
            else{
                ranking++;
                mp[element]  = ranking;
            }
        }

    for(int i = 0;i<arr.size();i++){
        int val = arr[i];
        rank[i] = mp[val];
    }
        
return rank;
    }
};