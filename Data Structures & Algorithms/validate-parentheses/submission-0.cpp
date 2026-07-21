class Solution {
public:
    bool isValid(string s) {
        stack <char> st; 
        st.push('a'); //need to push one random element as we will be accessing the
        //top of the stack in the for loop which will give us error otherwise. 
        for (char c:s){
            if (st.top()=='(' && c == ')'){
                st.pop();
                continue;
            } 
            if (st.top()=='{' && c == '}'){
                st.pop();
                continue;
            }   
            if (st.top()=='[' && c == ']'){
                st.pop();
                continue;
            }
            else
                st.push(c); 
        }
        if (st.size() == 1)
            return true; 
        return false; 
    }
};
