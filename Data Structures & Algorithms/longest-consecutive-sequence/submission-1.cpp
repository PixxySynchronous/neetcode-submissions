class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st; 
        if (nums.size() == 0) return 0; 
        int maxLength = 1; 
        for (int i = 0; i<nums.size() ; i++){
            st.insert(nums[i]); 
        }
        for (int i = 0; i<nums.size() ; i++){
            int startelem = nums[i];
            while (st.count(startelem - 1)){
                startelem--; 
            }
            int length = 1; 
            int currElem = startelem; 
            while (st.count(currElem + 1)){
                length++; 
                currElem++; 
            }
            maxLength = max(length, maxLength); 
        }
        return maxLength;
    }
};
