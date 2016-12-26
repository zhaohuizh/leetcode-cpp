#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int h_index(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int i = 0, size = citations.size();
    while(i < size) {
      if(citations[size - 1 - i] <= i) {
        break;
      }
      i++;
    }
    return i;
  }
};
