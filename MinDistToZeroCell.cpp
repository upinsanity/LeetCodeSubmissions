#include<vector>
using namespace std;
/*
Leetcode #542
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

Solution -
Use dist array to keep distances calculated so far
Traverse the array first from top left
Use pre-calculated dist values to fill current dist
Only top and left cell values available for re-use in this traversal

Next traverse the input from bottom right
Update dist values considering right and bottom cell values 
*/

 vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int rows = mat.size();
        if (rows == 0)
            return mat;
        int cols = mat[0].size();

        vector<vector <int>> dist(rows, vector<int>(cols, INT_MAX));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j] == 0)
                    dist[i][j] = 0;
                else            
                {
                    int val =  min( j>0?dist[i][j - 1]:INT_MAX , i>0?dist[i - 1][j]:INT_MAX );
                    dist[i][j] = min( val==INT_MAX?INT_MAX:val+1, dist[i][j] );       
                }
            }
        }

        for (int i = rows-1; i >= 0; i--)
        {
            for (int j = cols-1; j >= 0; j--)
            {
                if (mat[i][j] == 0)
                    dist[i][j] = 0;
                else
                {
                    int val = min( j < (cols-1) ? dist[i][j + 1] : INT_MAX , i < (rows-1) ? dist[i + 1][j] : INT_MAX );
                    dist[i][j] = min( val==INT_MAX?INT_MAX:val+1 , dist[i][j]);
                }
            }
        }

        return dist;
