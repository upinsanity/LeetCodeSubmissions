
/*
Leetcode #994

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
*/
    int orangesRotting(vector<vector<int>>& grid) {
        int nFreshO = 0;
        queue<pair<int,int>> q;
        vector<int> dx = { -1,	1,  0,  0 };
        vector<int> dy = { 0,	0, -1,  1 };

        int rowSize = grid.size();
        int colSize = grid[0].size();

        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (grid[i][j] == 1)
                    nFreshO++;
                else if (grid[i][j] == 2)
                    q.push({ i,j });
            }	
        }
        
        if(!nFreshO)
            return 0;
        
        int time = 0;
        while (!q.empty() && nFreshO)
        {
            time++;
            int currSize = q.size();
            while (currSize--)
            {
                pair<int, int> currPos = q.front();
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int nexti = currPos.first + dx[k];
                    int nextj = currPos.second + dy[k];

                    if ( nexti>=0 && nexti<rowSize && nextj>=0 && nextj<colSize && grid[nexti][nextj] == 1)
                    {
                        grid[nexti][nextj] = 2;
                        q.push({ nexti,nextj });
                        nFreshO--;
                    }
                }
            }
            
        }

        if (nFreshO)
            return -1;

        return time;
    }
