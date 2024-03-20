class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
			bool ret = false;
			// pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
			std::stack<int> feedback;
			int idx = 0;
			for (int i = 0; i < popped.size(); ++i) {
				feedback.push(pushed[i]);
				while (!feedback.empty() && idx < popped.size() && feedback.top() == popped[idx]) {
					feedback.pop();
					idx++;
				}
			}
			return feedback.empty();

    }
};
