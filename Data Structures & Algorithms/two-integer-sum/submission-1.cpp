class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp; 
        vector<int> ans; 
        for (int x = 0; x < nums.size(); x++){
            mp[nums[x]]=x; 
        }
        for (int x = 0; x < nums.size(); x++){
            if (mp.find(target-nums[x]) != mp.end() && mp[(target-nums[x])] != x){
                ans.push_back(mp[target-nums[x]]);
                ans.push_back(x); 
                sort(ans.begin(),ans.end());
                return ans; 
            }      
        }
        return ans;


    }
};
