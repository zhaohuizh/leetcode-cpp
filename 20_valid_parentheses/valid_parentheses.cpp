#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
private:
  bool is_left(char c) {
    return c == '(' || c == '[' || c == '{';
  }
  bool is_match(char l, char r) {
    switch(l) {
      case '(': return r == ')';
      case '[': return r == ']';
      case '{': return r == '}';
      default: return false;
    }
  }

public:
  bool is_valid(string s) {
    stack<char> stack;
    for(char c: s){
      if(is_left(c)) {
        stack.push(c);
      }else{
        if(stack.empty()) return false;
        char l = stack.top();
        if(!is_match(l, c)) return false;
        stack.pop();
      }
    }
    return stack.empty();
  }
};
