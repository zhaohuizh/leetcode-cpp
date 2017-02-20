#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret;
    map<int, int> times;
    for (int num : nums1) {
      times.insert(pair<int, int>(num, 1));
    }
    for (int num: nums2) {
      if (times.find(num) != times.end()) {
        if (times[num] == 1) {
          ret.push_back(num);
          times[num] = 2;
        }
      }
    }
    return ret;
  }
};
