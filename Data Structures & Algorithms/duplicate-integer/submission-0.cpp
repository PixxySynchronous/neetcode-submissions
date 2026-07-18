class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st; 
        for (int x:nums){
            if (st.find(x) ==st.end()){
                st.insert(x);}
            else 
                return true; 
        }
        return false; 
    }
};