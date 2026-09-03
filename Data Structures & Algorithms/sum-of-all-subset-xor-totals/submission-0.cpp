class Solution {
public:
    void recursive (vector<int>& nums, vector<vector<int>>& subsets, int index, vector<int> & curr){
        if (index >= nums.size()){
            subsets.push_back(curr);
            return; 
        }
        //exclude the element
        recursive (nums, subsets, index + 1, curr); 
        //include the element 
        curr.push_back(nums[index]); 
        recursive (nums, subsets, index+1, curr);
        //backtrack
        curr.pop_back(); 

    }

    int subsetXORSum(vector<int>& nums) {
        vector<int> curr; 
        vector<vector<int>> subsets; 
        int index = 0; 
        int ans = 0; 
        recursive (nums, subsets, index, curr);
        for (auto i: subsets){
            int arrSum = 0; 
            for ( int j = 0 ; j<i.size(); j++){
                 arrSum = arrSum ^ i[j]; 
            }
            ans+= arrSum; 
        }
        return ans; 
        
    }
};