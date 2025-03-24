#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to print the vector
void printVector(const vector<int> &v)
{
    cout << "Vector: ";
    for (int num : v)
        cout << num << " ";
    cout << endl;
}

// 1️⃣ Initialization
vector<int> initializeVector()
{
    vector<int> v = {10, 20, 30, 40, 50};
    cout << "Initialized Vector: ";
    printVector(v);
    return v;
}

// 2️⃣ Insertion Operations
void insertOperations(vector<int> &v)
{
    v.push_back(60);
    cout << "After push_back(60): ";
    printVector(v);

    v.insert(v.begin() + 2, 99);
    cout << "After inserting 99 at index 2: ";
    printVector(v);
}

// 3️⃣ Deletion Operations
void deleteOperations(vector<int> &v)
{
    v.pop_back();
    cout << "After pop_back(): ";
    printVector(v);

    v.erase(v.begin() + 2);
    cout << "After erasing element at index 2: ";
    printVector(v);
}

void accessElements(const vector<int> &v)
{
    cout << "First element: " << v.front() << endl;
    cout << "Last element: " << v.back() << endl;
    cout << "Element at index 2: " << v[2] << endl;
}
void sortVector(vector<int> &v)
{
    sort(v.begin(), v.end());
    cout << "After sorting: ";
    printVector(v);
}
void reverseVector(vector<int> &v)
{
    reverse(v.begin(), v.end());
    cout << "After reversing: ";
    printVector(v);
}

void searchElement(vector<int> &v, int target)
{
    if (binary_search(v.begin(), v.end(), target))
    {
        cout << target << " is found in the vector!" << endl;
    }
    else
    {
        cout << target << " is NOT found in the vector!" << endl;
    }
}

void findMinMax(vector<int> &v)
{
    cout << "Minimum element: " << *min_element(v.begin(), v.end()) << endl;
    cout << "Maximum element: " << *max_element(v.begin(), v.end()) << endl;
}


void removeDuplicates(vector<int> &v)
{
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << "After removing duplicates: ";
    printVector(v);
}

void mergeVectors(vector<int> &v1, vector<int> &v2)
{
    vector<int> merged;
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(merged));
    cout << "Merged Sorted Vector: ";
    printVector(merged);
}


int main()
{
    vector<int> v = initializeVector();
    insertOperations(v);
    deleteOperations(v);
    accessElements(v);
    sortVector(v);
    reverseVector(v);
    searchElement(v, 30);
    findMinMax(v);
    removeDuplicates(v);

    vector<int> v2 = {5, 15, 25, 35, 45};
    mergeVectors(v, v2);

    return 0;
}
