class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int j = 0; 
        int i = 0; 
        unordered_map <int,int> freq; 
        while (abs(i-j)<=k && j<nums.size()){
            freq[nums[j]]++; 
            if (freq[nums[j]] >1 )
                return true; 
            else
                j++; 
        }
        if (j<nums.size())
        freq[nums[j]]++; 
        while (j< nums.size()){
            freq[nums[i]]--;
            i++;
            if (freq[nums[j]]>1)
                return true; 
            j++;
            if ( j<nums.size())
            freq[nums[j]]++; 
            
        }
        return false; 
    }
};