#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
  bool is_valid(string s) {
    stack<char> stack;
    for(auto c: s){
      switch(c){
        case '(':
        case '[':
        case '{': stack.push(c); break;
        case ')':
                  if(stack.empty() || stack.top() != '(') return false;
                  else stack.pop(); break;
        case ']':
                  if(stack.empty() || stack.top() != '[') return false;
                  else stack.pop(); break;
        case '}':
                  if(stack.empty() || stack.top() != '{') return false;
                  else stack.pop(); break;
        default: return false;
      }
    }
    return stack.empty();
  }
};
