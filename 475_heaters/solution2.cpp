#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
  int find_radius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int ret = INT_MIN;
    for(int house : houses) {
      int dis = INT_MAX;
      vector<int>::iterator idx = lower_bound(heaters.begin(), heaters.end(), house);
      if(idx != heaters.end()){
        dis = *idx - house;
      }
      if(idx != heaters.begin()){
        dis = min (dis, house - *(idx - 1));
      }
      ret = max(ret, dis);
    }
    return ret;
  }
};
