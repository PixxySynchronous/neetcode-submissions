class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st; 
        if (nums.size() == 0) return 0; 
        int maxLength = 1; 
        for (int i = 0; i<nums.size() ; i++){
            st.insert(nums[i]); 
        }
        //Below is o(n^2): For every element I am looking for a smaller element and then starting to count once the smallest element is met. 
        //What I can do is if a smaller number exists, skip the loop because it is not the beginning of a sequence. 
        // for (int i = 0; i<nums.size() ; i++){
        //     int startelem = nums[i];
        //     while (st.count(startelem - 1)){
        //         startelem--; 
        //     }
        //     int length = 1; 
        //     int currElem = startelem; 
        //     while (st.count(currElem + 1)){
        //         length++; 
        //         currElem++; 
        //     }
        //     maxLength = max(length, maxLength); 
        // }
        for (int i = 0 ; i<nums.size() ; i++){
            if (st.count(nums[i] - 1)) //if a smaller element exists, current element is not the start of the sequence, and hence no point in processing this. 
                continue; 
            //else the number is the smallest in the sequence so:
            int length = 1; 
            int curr = nums[i];
            while (st.count(curr + 1)){
                curr++;
                length++;
            }
            maxLength = max(length, maxLength); 
        }

        return maxLength;
    }
};
