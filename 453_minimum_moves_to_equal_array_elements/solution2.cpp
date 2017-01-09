#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
  int min_moves(vector<int>& nums){
    int ret = 0, minimum = INT_MAX;
    for(int num : nums) minimum = min(minimum, num);
    for(int num : nums) ret += (num - minimum);
    return ret;
  }
};
