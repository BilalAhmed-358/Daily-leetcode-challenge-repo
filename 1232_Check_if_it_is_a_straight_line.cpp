/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.





Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false



Constraints:

    2 <= coordinates.length <= 1000
    coordinates[i].length == 2
    -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
    coordinates contains no duplicate point.

*/
#include <bits/stdc++.h>
using namespace std;

bool checkStraightLine(vector<vector<int>> &coordinates);
int determinant_of_matrix(int matrix[3][3]);
void Print_Matrix(int matrix[3][3]);
int main()
{
    vector<vector<int>> line = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
    cout << checkStraightLine(line) << endl;
}
bool checkStraightLine(vector<vector<int>> &coordinates)
{
    bool straight_line = true;
    int matrix[3][3];
    if (coordinates.size() == 2)
    {
        return true;
    }
    for (int i = 0; i < coordinates.size() - 2; i++)
    {
        matrix[0][0] = coordinates[i][0];
        matrix[0][1] = coordinates[i][1];
        matrix[1][0] = coordinates[i + 1][0];
        matrix[1][1] = coordinates[i + 1][1];
        matrix[2][0] = coordinates[i + 2][0];
        matrix[2][1] = coordinates[i + 2][1];
        matrix[0][2] = matrix[1][2] = matrix[2][2] = 1;
        if (determinant_of_matrix(matrix) != 0)
            return false;
    }
    return straight_line;
}
int determinant_of_matrix(int matrix[3][3])
{
    int Determinant = 0;
    // Print_Matrix(matrix);
    Determinant = matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[2][1] * matrix[1][2])) - matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[2][0] * matrix[1][2])) + matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[2][0] * matrix[1][1]));
    // cout << "Determinant is " << Determinant << endl;
    return Determinant;
}