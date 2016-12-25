#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void move_zeros(vector<int>& nums) {
    int i = 0, j = 0;
    while(i < nums.size()) {
      if (nums[i] != 0) {
        swap(nums[i++], nums[j++]);
      } else {
        i++;
      }
    }
  }
  
};
