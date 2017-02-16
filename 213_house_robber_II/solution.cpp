#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    int size = nums.size();
    if (size == 1) return nums[0];
    int even = 0, odd = 0;
    int a = 0, b = 0;
    for(int i = 0; i < size - 1; i++) {
      if(i % 2 == 0) {
        even = max(even + nums[i], odd);
        a = max(a + nums[i + 1], b);
      } else {
        odd = max(even, odd + nums[i]);
        b = max(a, b + nums[i + 1]);
      }
    }
    return max(max(even, odd), max(a, b));
  }
};
