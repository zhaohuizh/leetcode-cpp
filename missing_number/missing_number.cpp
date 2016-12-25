#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int missing_number(vector<int>& nums) {
    int ret = nums.size(), i = 0;
    for (int num : nums) {
      ret ^= num;
      ret ^= i;
      i++;
    }
    return ret;
  }
};
