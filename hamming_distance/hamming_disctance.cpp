

class Solution {
public:
  int hammingDistance(int x, int y) {
    int ret = 0;
    while (x != 0 || y != 0) {
      ret += ((x ^ y) & 1);
      x >>= 1;
      y >>= 1;
    }
    return ret;
  }
};
