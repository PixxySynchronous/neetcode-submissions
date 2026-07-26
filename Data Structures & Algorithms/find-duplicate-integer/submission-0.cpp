class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Since values lie between 1,n, to not use extra space what we do is,turn the 
        //corresponding index into its negative value. If for another element, the same corresponding
        //index is hit, we will know as itll be negative and then boom. 
        for (int i = 0; i<nums.size() ; i++){
            if (nums[abs(nums[i])] < 0){
                return abs(nums[i]); 
            }
            nums[abs(nums[i])] *= -1; 
        }
        return -1 ; 
        //in order to do this wihtout editing the original array, we can treat the array as a ll and then use fast and slow pointers
        
    }
};
