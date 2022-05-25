#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> &Mat)
{
    // code here
    vector<int> sortedMat;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sortedMat.push_back(Mat[i][j]);
        }
    }
    sort(sortedMat.begin(), sortedMat.end());
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Mat[i][j] = sortedMat[i * N + j];
        }
    }
    return Mat;
}

int main()
{
    vector<vector<int>> mat = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50},
    };
    sortedMatrix(mat.size(), mat);
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat.size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}