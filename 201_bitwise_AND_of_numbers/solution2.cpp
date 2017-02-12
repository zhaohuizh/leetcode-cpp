#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
  int range_bitwise_and(int m, int n) {
    int i = INT_MAX;
    while((m & i) != (n & i)) i <<= 1;
    return m & i;
  }
};
