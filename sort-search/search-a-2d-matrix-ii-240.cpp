#include <vector>
#include <stdio.h>
using std::vector;
/*
static std::string base64_encode(BYTE const* buf, unsigned int bufLen) {
  std::string ret;
  int i = 0;
  int j = 0;
  BYTE char_array_3[3];
  BYTE char_array_4[4];

  while (bufLen--) {
    char_array_3[i++] = *(buf++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for(i = 0; (i <4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }
}
*/
/*
 *  1 10  20 30 40
 *  2 12  21 31 41
 *  3 13  80 81 120 
 *
 *  30 40
 *  31 41
 *  80 82 120
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] > target) {
                --y;
            }
            else {
                ++x;
            }
        }
        return false;
    }
};

bool base64_decode(vector<vector<int>>& matrix, int target) {
	size_t total_row = matrix.size(), total_col = matrix[0].size();
	int col = total_col - 1, row = 0;
	while (col >= 0 && row < total_row) {
		if (matrix[row][col] == target) {
			return true;
		}
		if (matrix[row][col] > target) {
			--col;
		} else {
			++row;
		}
	}
	return false;
}

int main() {
	Solution s;
	vector<vector<int>> matrix {
		{-1,10,20,30,40},
		{2,12,21,31,41},
		{3,51,61,70,111}
	};
	for (int i = -10; i < 120; ++i) {
		if (base64_decode(matrix, i)) {
			printf("[path 1]found %d in matrix\n", i);
		} 
		if (s.searchMatrix(matrix, i)) {
			printf("[path 2]found %d in matrix\n", i);
		}
	}
	return 0;
}
