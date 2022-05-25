#include <iostream>
#include <vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    int Mu = 0, Mb = r - 1, Nl = 0, Nr = c - 1;
    int current_col, current_row;
    vector<int> spiral;
    while (spiral.size() != r * c)
    {
        for (current_col = Nl, current_row = Mu; current_col <= Nr; current_col++)
        {
            spiral.push_back(matrix[current_row][current_col]);
        }
        if (spiral.size() == r * c)
            break;
        Mu++;

        for (current_row = Mu, current_col = Nr; current_row <= Mb; current_row++)
        {
            spiral.push_back(matrix[current_row][current_col]);
        }
        if (spiral.size() == r * c)
            break;
        Nr--;

        for (current_row = Mb, current_col = Nr; current_col >= Nl; current_col--)
        {
            spiral.push_back(matrix[current_row][current_col]);
        }
        if (spiral.size() == r * c)
            break;
        Mb--;

        for (current_col = Nl, current_row = Mb; current_row >= Mu; current_row--)
        {
            spiral.push_back(matrix[current_row][current_col]);
        }
        if (spiral.size() == r * c)
            break;
        Nl++;
    }

    return spiral;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
    };

    vector<int> spiral = spirallyTraverse(matrix, 4, 4);
    for (int i = 0; i < spiral.size(); i++)
    {
        cout << spiral[i] << " ";
    }
}