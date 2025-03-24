#include <bits/stdc++.h>
using namespace std;

// 1D Prefix Sum
vector<int> prefixSum(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + arr[i - 1];
    return pref;
}

// Query sum of range [L, R] (1-based index)
int rangeSum(vector<int> &pref, int L, int R)
{
    return pref[R] - pref[L - 1];
}

// 2D Prefix Sum for Matrix
vector<vector<int>> prefixSum2D(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            pref[i][j] = matrix[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    return pref;
}

// Query sum of submatrix (x1, y1) to (x2, y2) (1-based index)
int subMatrixSum(vector<vector<int>> &pref, int x1, int y1, int x2, int y2)
{
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
}

// 1D Prefix XOR
vector<int> prefixXOR(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] ^ arr[i - 1];
    return pref;
}

// Query XOR of range [L, R] (1-based index)
int rangeXOR(vector<int> &pref, int L, int R)
{
    return pref[R] ^ pref[L - 1];
}

// 1D Prefix GCD
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

vector<int> prefixGCD(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = gcd(pref[i - 1], arr[i - 1]);
    return pref;
}

// Query GCD of range [L, R] (1-based index)
int rangeGCD(vector<int> &pref, int L, int R)
{
    return gcd(pref[R], pref[L - 1]);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    // 1D Prefix Sum
    vector<int> pref = prefixSum(arr);
    cout << "Sum of range [2, 4]: " << rangeSum(pref, 2, 4) << endl;

    // 1D Prefix XOR
    vector<int> prefXor = prefixXOR(arr);
    cout << "XOR of range [2, 4]: " << rangeXOR(prefXor, 2, 4) << endl;

    // 1D Prefix GCD
    vector<int> prefGcd = prefixGCD(arr);
    cout << "GCD of range [2, 4]: " << rangeGCD(prefGcd, 2, 4) << endl;

    // 2D Prefix Sum
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> prefMatrix = prefixSum2D(matrix);
    cout << "Sum of submatrix (1,1) to (2,2): " << subMatrixSum(prefMatrix, 1, 1, 2, 2) << endl;

    return 0;
}
