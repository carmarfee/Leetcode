#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class NumMatrix
{
private:
    vector<vector<int>> prefix_sum_;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return;
        }
        prefix_sum_.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for(int i = 1; i <= matrix.size(); i++)
        {
            for (int j = 1; j <= matrix[0].size(); j++)
            {
                prefix_sum_[i][j] = prefix_sum_[i - 1][j] + prefix_sum_[i][j - 1] - prefix_sum_[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return prefix_sum_[row2 + 1][col2 + 1] - prefix_sum_[row1][col2 + 1] - prefix_sum_[row2 + 1][col1] + prefix_sum_[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */