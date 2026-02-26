#include <vector>
#include <sstream>
#include <iostream>
#include <string>
using std::vector;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.reserve(m+n);
        for (int i = m+n-1; i >= 0; i--) {
            if (n > 0 && m > 0) {
                if (nums1[m-1] > nums2[n-1]) {
                    nums1[i] = nums1[m-1];
                    m --;
                } else {
                    nums1[i] = nums2[n-1];
                    n --;
                }
            } else if (n != 0) {
                nums1[i] = nums2[n-1];
                n--;
            } else {
                nums1[i] = nums1[m-1];
                m--;
            }
        }
    }
};

void Print(std::vector<int>& in) {
    std::stringstream ss;
    for (auto & i :in) {
        ss << i;
    }
    std::cout << ss.str() << "n";
}

int main() {
    Solution s;
    std::vector<int> l{1,1,2,3,4};
    std::vector<int> l2{5,6,7,8,9};
    s.merge(l,l.size(), l2, l2.size());
    Print(l);
    return 0;
}