#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    int size = nums.size();
    int even = 0, odd = 0;
    for(int i = 0; i < size; i++) {
      if(i % 2 == 0) {
        even = max(even + nums[i], odd);
      } else {
        odd = max(even, odd + nums[i]);
      }
    }
    return max(even, odd);
  }
};
