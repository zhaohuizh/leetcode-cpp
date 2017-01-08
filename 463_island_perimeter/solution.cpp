#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int island_perimeter(vector<vector<int> >& grid){
    int ret = 0;
    for(int i = 0; i < grid.size(); ++i){
      for(int j = 0; j < grid[i].size(); ++j){
        int curr = 0;
        if(grid[i][j] == 1){
          curr += (i == 0 || grid[i - 1][j] == 0) ? 1 : 0;
          curr += (i == grid.size() - 1 || grid[i + 1][j] == 0) ? 1 : 0;
          curr += (j == 0 || grid[i][j - 1] == 0) ? 1 : 0;
          curr += (j == grid[0].size() - 1 || grid[i][j + 1] == 0) ? 1 : 0;
        }
        ret += curr;
      }
    }
    return ret;
  }
};
