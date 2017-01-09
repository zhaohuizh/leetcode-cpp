#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int max_product(vector<string>& words) {
    int ret = 0;
    unordered_map<int, int> max_len;
    for(int i = 0; i < words.size(); ++i) {
      int mask = 0;
      for(char c : words[i]){
        mask |= (1 << (c - 'a'));
      }
      max_len[mask] = max(max_len[mask], (int) words[i].size());
    }

    for(auto a : max_len) {
      for(auto b : max_len) {
        if(!(a.first & b.first)) {
          ret = max(ret, a.second * b.second);
        }
      }
    }
    return ret;
  }
};
