#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
  int find_radius(vector<int>& houses, vector<int>& heaters) {
    int ret = INT_MIN;
    for(int house : houses) {
      int dis = INT_MAX;
      for(int heater : heaters) {
        dis = min(dis, abs(house - heater));
      }
      ret = max(ret, dis);
    }
    return ret;
  }
};
