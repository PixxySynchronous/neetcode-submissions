class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //Approach is to store the index of all the elements whos next greater element
        //hasnt been found yet. So we traverse the array. If array element is greater than 
        //st.top() then the index currently at top of stack has found its next greatest element 
        //so we note that and now we pop that index from the stack. 
        //In this question we need the number of days so we do index of array element and st.top()
        stack<int> st; 
        st.push(0); //first we have index 0. 
        int n = temperatures.size(); 
        vector<int> ans (n,0); //initialising important as we need to access index of this vector. 
        for (int i = 1; i<temperatures.size(); i++){
            while (!st.empty() && temperatures[i] > temperatures[st.top()]){
                ans[st.top()] = i-st.top(); //st.top() has the index, not the value. 
                st.pop(); 
            }
            st.push(i); 
        }
        return ans; 
    }
};
