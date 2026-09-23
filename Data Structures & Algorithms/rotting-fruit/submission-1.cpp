class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> q;

        vector<vector<int>> directions = {
            {-1,0},
            {1,0},
            {0,1},
            {0,-1}
        };

        int freshCount = 0;
        int minutes = -1;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {

                if(grid[i][j] == 2)
                    q.push({i,j});

                if(grid[i][j] == 1)
                    freshCount++;
            }
        }

        // Nothing needs to rot
        if(freshCount == 0)
            return 0;

        while(!q.empty()) {

            int n = q.size();

            while(n--) {

                auto [i,j] = q.front();
                q.pop();

                for(auto it : directions) {

                    int new_i = i + it[0];
                    int new_j = j + it[1];

                    if(new_i < 0 || new_i >= grid.size() ||
                       new_j < 0 || new_j >= grid[0].size()) {
                        continue;
                    }

                    if(grid[new_i][new_j] == 1) {

                        grid[new_i][new_j] = 2;
                        freshCount--;

                        q.push({new_i,new_j});
                    }
                }
            }

            minutes++;
        }

        if(freshCount > 0)
            return -1;

        return minutes;
    }
};