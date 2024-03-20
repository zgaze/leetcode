class MyQueue {
public:
    MyQueue() {
    }
    
    void push(int x) {
			ele_1.push(x);
    }
    
    int pop() {
			int ret = 0;
			if (ele_2.empty()) {
				while (!ele_1.empty()) {
					ele_2.push(ele_1.top());
					ele_1.pop();
				}
			}
			ret = ele_2.top();
			ele_2.pop();
			return ret;
		}
    
    int peek() {
			int ret = 0;
			if (ele_2.empty()) {
				while (!ele_1.empty()) {
					ele_2.push(ele_1.top());
					ele_1.pop();
				}
			}
			ret = ele_2.top();
			return ret;
    }
    
    bool empty() {
			return ele_1.empty() && ele_2.empty();
    }
 private:
	std::stack<int> ele_1;
	std::stack<int> ele_2;
};
