class MyQueue {
private:
    std::stack<int> stk_in;
    std::stack<int> stk_out;
    void shiftStacks() {
        if (stk_out.empty()) {
            while (!stk_in.empty()) {
                stk_out.push(stk_in.top());
                stk_in.pop();
            }
        }
    }
public:
    MyQueue() {
        // Constructor
    }
        void push(int x) {
        stk_in.push(x);
    }
        int pop() {
        shiftStacks();
        int frontElement = stk_out.top();
        stk_out.pop();
        return frontElement;
            }
    
    int peek() {
        shiftStacks();
        return stk_out.top();
    }
    
    bool empty() {
        return stk_in.empty() && stk_out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */