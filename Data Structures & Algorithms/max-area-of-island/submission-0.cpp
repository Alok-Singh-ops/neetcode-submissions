class Solution {
public:

    int solve(int sr,int sc,vector<vector<int>> &grid){
        if(sr >= grid.size() || sr < 0) return 0;
         if(sc >= grid[0].size() || sc < 0) return 0;

        int area = 0;
        if(grid[sr][sc] == 1){
            grid[sr][sc] = 0;
         area = 1 + solve(sr+1, sc, grid) + 
                    solve(sr-1, sc, grid) +              
                    solve(sr, sc+1, grid) + 
                    solve(sr, sc-1, grid);
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    int currentArea = solve(i,j,grid);
                    ans = max(ans,currentArea); 
                }
            }
        }



        return ans;
    }
};
