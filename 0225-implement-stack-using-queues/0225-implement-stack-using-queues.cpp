#include <queue>

class MyStack {
private:
    std::queue<int> q;

public:
    MyStack() {}
    
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top_element = q.front();
        q.pop();
        return top_element;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};