class Solution {
public:
    void recursive (vector<int>& nums, int index, int& xorcurr, int& ans){
        if (index >= nums.size()){
            ans += xorcurr;
            return; 
        }
        //exclude the element
        recursive (nums, index + 1, xorcurr, ans); 
        //include the element 
        xorcurr = xorcurr ^ nums[index];
        recursive (nums, index+1,xorcurr, ans);
    }

    int subsetXORSum(vector<int>& nums) {
        int index = 0; 
        int ans = 0; 
        int xorcurr = 0; 
        recursive (nums, index, xorcurr, ans);
        return ans; 
        
    }
};