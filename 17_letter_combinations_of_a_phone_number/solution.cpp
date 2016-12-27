#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> letter_combinations(string digits) {
    string charmap[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ret;
    for(auto d : digits) {
      vector<string> tmp;
      string chars = charmap[d - '0'];
      for(auto c : chars) {
        if(ret.empty()) {
          tmp.push_back(string(1, c));
          continue;
        }
        for(string s : ret) {
          tmp.push_back(s + c);
        }
      }
      ret = tmp;
    }
    return ret;
  }
 };

int main(){
  Solution* s = new Solution();
  s->letter_combinations("22");
  return 0;
}
