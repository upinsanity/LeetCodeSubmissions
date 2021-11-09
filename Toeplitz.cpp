
/*
Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
*/
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row > 0)
        {   
            int col = matrix[0].size();
            int i = 0, j = 0;

            while (j < col - 1)
            {
                int k = j;
                i = 0;
                while (k < col-1 && i< row-1)
                {
                    if (matrix[i][k] != matrix[i + 1][k + 1])
                        return false;
                    k++; i++;
                }
                j++;
            }

            i = 1, j = 0;
            while (i < row - 1)
            {
                int k = i;
                j = 0;
                while (k < row-1 && j<col-1)
                {
                    if (matrix[k][j] != matrix[k + 1][j + 1])
                        return false;
                    k++; j++;
                }
                i++;
            }
            return true;
            
        }
        return true;
    }
