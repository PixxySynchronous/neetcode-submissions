class Solution {
public:
    int characterReplacement(string s, int k) {
        //In a given window, there would be sev elements. 
        //One element would be in the majority. 
        //the size of the window - majority elem gives number of elems
        //which can be flipped to make the window valid
        //so our condition for valid window becomes length - maxF <=k
        unordered_map <char, int> freq; 
        int maxF = 0; 
        int i = 0; 
        int j = 0;
        int maxLength = 0; 
        int length = 0; 
        while (j < s.size()){
            freq[s[j]]++;
            maxF = max ( maxF, freq[s[j]]); //maintaining highest freq. 
            while ( j-i+1 - maxF > k){
                freq[s[i]] --; 
                i++;
                length --;
            }
            //Once out the loop, we know that the window is valid. SO we increase the length. 
            length++;
            maxLength = max (maxLength, length); 
            j++; //expand window to right. 
        }
        return maxLength; 
    }
};
