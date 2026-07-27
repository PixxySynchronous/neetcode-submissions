class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> freq; 
        int i = 0 ; 
        int j = 0 ; 
        int maxSize = 0; 
        while (j<s.size()){
            freq[s[j]]++; //add curr elem in freq. 
            while (freq[s[j]]>1){ //if adding the current elem makes it NOT UNIQUE,
            //we remove an element from the back till adding the curr elem makes it unique in the window. 
                freq[s[i]] -- ;
                i++; 
            }
            //else we have an unique valid window. 
            maxSize = max (maxSize, j-i+1); 
            j++;
        }
        return maxSize; 
    }
};
