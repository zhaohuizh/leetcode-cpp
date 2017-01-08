#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int island_perimeter(vector<vector<int> >& grid){
    int island = 0, edge = 0;
    for(int i = 0; i < grid.size(); ++i){
      for(int j = 0; j < grid[i].size(); ++j){
        if(grid[i][j] == 1){
          island++;
          if(i > 0 && grid[i - 1][j] == 1) edge++;
          if(j > 0 && grid[i][j - 1] == 1) edge++;
        }
      }
    }
    return island * 4 - edge * 2;
  }
};
