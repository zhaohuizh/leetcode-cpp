#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int h_index(vector<int>& citations) {
    int size = citations.size(), tot = 0;
    int count[size + 1] = {0};
    for(int citation : citations) {
      if(citation >= size) {
        count[size]++;
      } else {
        count[citation]++;
      }
    }
    for(int i = size; i >= 0; i--) {
      tot += count[i];
      if(tot >= i) return i;
    }
    return 0;
  }
};
