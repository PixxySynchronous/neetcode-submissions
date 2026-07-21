class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; 
        for (string c: tokens){
            if (c == "+"){
                int secdig = st.top();
                st.pop();
                int firstdig = st.top();
                st.pop();
                int res = firstdig + secdig; 
                st.push(res);
            }
            else if (c == "-"){
                int secdig = st.top();
                st.pop();
                int firstdig = st.top();
                st.pop();
                int res = firstdig - secdig; 
                st.push(res);
            }
            else if (c == "*"){
                int secdig = st.top();
                st.pop();
                int firstdig = st.top();
                st.pop();
                int res = firstdig * secdig; 
                st.push(res);
            }
            else if (c == "/"){
                int secdig = st.top();
                st.pop();
                int firstdig = st.top();
                st.pop();
                int res = firstdig/secdig; 
                st.push(res);
            }
            else {
                int dig = stoi(c);
                st.push(dig);
            }

        }
        return st.top(); 
    }
};
