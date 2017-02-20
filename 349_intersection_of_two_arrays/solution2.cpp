#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret;
    set<int> num_set(nums1.begin(), nums1.end());
    for (int num: nums2) {
      if (num_set.erase(num)) {
        ret.push_back(num);
      }
    }
    return ret;
  }
};
