class MinStack {
    stack<int> st; 
    stack<int> minSt; //Need to declare these here as I need to use them for all functions. 
public:
    MinStack() {}
    //Approach is to maintain 2 stacks. One is the normal stack and the other keeps the minimum element 
    // if the corresponding element would be on top of the main stack. Like a prefix. 
    
    void push(int val) {
        st.push(val); 
        if (minSt.size()==0){
            minSt.push(val);
            return; 
        }
        if (st.top()<minSt.top())
            minSt.push(val); //The current minElem gets outmogged by the newest elem getting pushed so we push that in minst as well. 
        else{
            int minelem = minSt.top();
            minSt.push(minelem);//repush the minelem as it is smaller than the current value being pushed in
        }
    }
    
    void pop() {
        st.pop();
        minSt.pop(); //Need to pop both!
    }
    
    int top() {
        return st.top();

    }
    
    int getMin() {
       return minSt.top(); 
    }
};
