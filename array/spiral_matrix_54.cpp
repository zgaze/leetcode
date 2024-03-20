#include <stdio.h>
#include <vector>
#include <string>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
	    vector<int> ret;
	    int i = 0, j = 0;
	    int i_max = matrix.size();
	    if (i_max == 0) return ret;
	    int j_max = matrix[0].size();
	    while (i < i_max && j < j_max) {
		    for (; i < i_max; ++i) {
			    ret.push_back(matrix[j][i]);
		    }
		    j += 1;
		    for (; j < j_max; ++j) {
			    ret.push_back(matrix[j][i]);
		    }
		    i -= 1;
		    for (; i >)
		    
	    }

    }
};
