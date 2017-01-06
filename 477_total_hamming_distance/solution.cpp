#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int total_hamming_distance(vector<int>& nums) {
    int ret = 0, ones = 0;
    bool should_exit = true;
    while(true) {
      should_exit = true;
      ones = 0;
      for (int i = 0; i < nums.size(); i++) {
        ones += (nums[i] & 1); 
        nums[i] >>= 1;
        if (should_exit && nums[i] > 0) {
          should_exit = false;
        }
      }
      ret += ones * (nums.size() - ones);
      if(should_exit) break;
    }
    return ret;
  }
};
