class MinStack {
    stack<int> st; 
    stack<int> minSt; 
public:
    MinStack() {}
    
    
    void push(int val) {
        st.push(val); 
        if (minSt.size()==0){
            minSt.push(val);
            return; 
        }
        if (st.top()<minSt.top())
            minSt.push(val);
        else{
            int minelem = minSt.top();
            minSt.push(minelem);
        }
    }
    
    void pop() {
        st.pop();
        minSt.pop(); 
    }
    
    int top() {
        return st.top();

    }
    
    int getMin() {
       return minSt.top(); 
    }
};
