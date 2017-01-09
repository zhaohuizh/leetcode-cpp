#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
  bool share_common(string word1, string word2) {
    int bits[26] = {0};
    for(char c : word1){
      bits[c - 'a'] = 1;
    }
    for(char c : word2){
      if(bits[c - 'a'] == 1) return true;
    }
    return false;
  }
public:
  int max_product(vector<string>& words) {
    int ret = 0;
    for(int i = 0; i < words.size(); ++i) {
      for(int j = i + 1; j < words.size(); ++j) {
        if(!share_common(words[i], words[j])){
          int size1 = words[i].size();
          int size2 = words[j].size();
          ret = max(ret, size1 * size2);
        }
      }
    }
    return ret;
  }
};
