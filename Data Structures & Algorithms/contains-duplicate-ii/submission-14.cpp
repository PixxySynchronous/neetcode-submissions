class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int j = 0; 
        int i = 0; 
        unordered_map <int,int> freq; 
        while (j<nums.size()){
            //the curent nums[j] hasnt been added yet. If it alr has a freq>0 then we found a duplicate
            if (freq[nums[j]]>0)
                return true; 
            freq[nums[j]]++;
            j++;
            if (abs(i-j)>k){
                freq[nums[i]]--;
                i++;
            }
        }
        return false; 
    }
};