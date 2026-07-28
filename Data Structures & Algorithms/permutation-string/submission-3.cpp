class Solution {
public:
    bool isEqual(int a[],int b[]){
        int i = 0;
        while ( i < 26){
            if (a[i]!=b[i])
            return 0;
            i++;
        }
        return 1; 
    }
    
    bool checkInclusion(string s1, string s2) {
        if (s2.size()<s1.size()) return false; 
        int freq1 [26] = {0}; 
        for ( int i = 0; i<s1.size(); i++){
            freq1 [s1[i] - 'a']++;
        }
        int freq2 [26] = {0}; 
        for ( int i = 0; i<s1.size(); i++){
            freq2 [s2[i] - 'a']++;
        }
        if (isEqual (freq1, freq2)) return true; 
        int l = 0 ; 
        int r = s1.size() -1 ; 
        while (r<s2.size() - 1){ //as we access r+1
           freq2[s2[l] -'a'] --;
           l++;
           r++;
           freq2[s2[r] - 'a'] ++;
           if (isEqual (freq1, freq2)) return true;
        }
        //make a window of size s1 in s2. Check if that is equal to the freq of s1.
        //If not move right. 
        return false; 
    }
};
