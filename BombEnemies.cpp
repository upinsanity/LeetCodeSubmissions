#include<vector>
using namespace std;

/*
Leetcode #361
Given an m x n matrix grid where each cell is either a wall 'W', an enemy 'E' or empty '0', return the maximum enemies you can kill using one bomb. 
You can only place the bomb in an empty cell.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since it is too strong to be destroyed.

Input: grid = [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3

Input: grid = [["W","W","W"],["0","0","0"],["E","E","E"]]
Output: 1

Solution-
Traverse the input
Calculate maximum number of enemies in that row and column 
Maintain max enenies in col to be able to re-use
Every time a wall is encountered re-set max enemy count to 0 
Returm max enemies killed count
*/

    int maxOf( int a, int b )
    {
        return a>b?a:b;
    }
    bool isWall(int i, int j, vector<vector<char>>& grid)
    {
        return (grid[i][j] == 'W');
    }

    bool isEnemy(int i, int j, vector<vector<char>>& grid)
    {
        return (grid[i][j] == 'E');
    }

    bool isEmpty(int i, int j, vector<vector<char>>& grid)
    {
        return (grid[i][j] == '0');
    }
    
    int maxKilledEnemies(vector<vector<char>>& grid) {

        int maxKilled = 0;
        int row = grid.size();
        if (row > 0)
        {
            int col = grid[0].size();

            int* maxColEnemies = new int[col];
            int maxRowEnemies = 0;


            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (j == 0 || isWall(i, j-1 , grid))
                    {
                        maxRowEnemies = 0;  //start at col=0 and restart when wall at prev col

                        for (int k = j; k < col; k++)
                        {
                            if (isWall(i, k, grid))
                                break;
                            if (isEnemy(i, k, grid))
                                maxRowEnemies++;
                        }
                    }

                    if (i == 0 || isWall(i-1, j , grid))
                    {
                        maxColEnemies[j] = 0; //start at row=0 and restart when wall at prev row

                        for (int k = i; k < row; k++)
                        {
                            if (isWall(k, j, grid))
                                break;
                            if (isEnemy(k, j, grid))
                                maxColEnemies[j]++;
                        }

                    }
                    if (isEmpty(i, j, grid))                    
                        maxKilled = maxOf( maxKilled, maxRowEnemies + maxColEnemies[j] );    
                    
                }
            }	
            
             delete [] maxColEnemies;
        }       
       
        return maxKilled;
    }
