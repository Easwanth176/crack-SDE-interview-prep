#include <bits/stdc++.h>
using namespace std;

// Standard Binary Search
int binarySearch(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Not found
}

// Lower Bound (First position where arr[i] >= target)
int lowerBound(vector<int> &arr, int target)
{
    int left = 0, right = arr.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

// Upper Bound (First position where arr[i] > target)
int upperBound(vector<int> &arr, int target)
{
    int left = 0, right = arr.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

// Floating Point Binary Search (Example: Square Root)
double binarySearchDouble(double left, double right, double target, double precision)
{
    while (right - left > precision)
    {
        double mid = left + (right - left) / 2;
        if (mid * mid < target)
            left = mid;
        else
            right = mid;
    }
    return left;
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9};
    cout << "Binary Search for 5: " << binarySearch(arr, 5) << endl;
    cout << "Lower Bound of 4: " << lowerBound(arr, 4) << endl;
    cout << "Upper Bound of 5: " << upperBound(arr, 5) << endl;
    cout << "Square Root of 10: " << binarySearchDouble(0, 10, 10, 1e-6) << endl;
    return 0;
}
