#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int max_product(vector<string>& words) {
    int ret = 0;
    vector<int> mask(words.size());
    for(int i = 0; i < words.size(); ++i) {
      for(char c : words[i]){
        mask[i] |= (1 << (c - 'a'));
      }
      for(int j = 0; j < i; ++j) {
        if(!(mask[i] & mask[j])){
          ret = max(ret, int(words[i].size() * words[j].size()));
        }
      }
    }
    return ret;
  }
};
