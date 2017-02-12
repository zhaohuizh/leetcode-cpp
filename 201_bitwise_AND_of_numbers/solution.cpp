#include <iostream>
using namespace std;

class Solution {
public:
  int range_bitwise_and(int m, int n) {
    int ret = 0;
    int i = 31;
    for (; i >= 0; i--) {
      if(ret == 0 && (m >> i) == 0 && (n >> i) == 0) {
        continue;
      }
      if(((m ^ n) >> i) & 1) {
        break;
      } else {
        ret += m & (1 << i);
      }
    }
    return ret << i;
  }
};
