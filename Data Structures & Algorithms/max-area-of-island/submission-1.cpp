class Solution {
public:
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0 || vis[i][j]){
            return 0;
        }
        vis[i][j]=true;
        int area= 1;
        area+= dfs(i-1, j, n, m, grid, vis);
        area+= dfs(i, j+1, n, m, grid, vis);
        area+= dfs(i+1, j, n, m, grid, vis);
        area+= dfs(i, j-1, n, m, grid, vis);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea= 0;
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int area= dfs(i, j, n, m, grid, vis);
                    vis[i][j]= true;
                    maxarea= max(area, maxarea);
                }
            }
        }
        return maxarea;
    }
};
