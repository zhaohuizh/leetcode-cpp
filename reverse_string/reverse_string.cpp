#include <string>

using namespace std;

class Solution {
public:
  string reverse_string(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      swap(s[i++], s[j--]);
    }
    return s;
  }
};
