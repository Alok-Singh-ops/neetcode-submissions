class Solution {
public:

    void printGrid(vector<vector<char>> grid){
       for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;

       }
    }

    
    void solve(int sr,int sc,vector<vector<char>> &grid){
        if(sr >= grid.size() || sr < 0) return;
        if(sc >= grid[0].size() || sc < 0) return; 

        if(grid[sr][sc] =='0')
            return;
       
        if(grid[sr][sc] == '1'){
           grid[sr][sc] = '0';
           solve(sr+1,sc,grid);
           solve(sr-1,sc,grid);
           solve(sr,sc+1,grid);
           solve(sr,sc-1,grid);
        }
        
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int i  = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j] == '1'){
                    solve(i,j,grid);
                    // printGrid(grid);
                    ans++;
                }
            }
            cout << endl;
        }
        return ans;
    }
};
