#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
  int min_moves(vector<int>& nums){
    int ret = 0;
    while(true) {
      bool equals = true;
      int idx = 0;
      int max = INT_MIN;
      for(int i = 0; i < nums.size(); ++i){
        if(i > 0 && nums[i] != nums[i - 1] - 1) equals = false;
        if(nums[i] > max){
          max = nums[i];
          idx = i;
        }
        nums[i]++;
      }
      if(equals) return ret;
      nums[idx]--;
      ret++;
    }
  }
};
