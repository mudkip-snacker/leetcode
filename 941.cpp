#include <iostream>
#include <vector>
using namespace std;

bool validMountainArray(vector<int> &arr)
{
    if (arr.size() < 3)
        return false;

    int prev = arr[0];
    bool increasing = true;
    if (prev >= arr[1]) // if first num isn't less than second, return false
        return false;
    prev = arr[1];
    for (int i = 2; i < arr.size(); i++)
    {
        if (prev == arr[i])
            return false;
        if (prev > arr[i])
            increasing = false;
        if (increasing && prev > arr[i])
            return false;
        if (!increasing && prev < arr[i])
            return false;
        prev = arr[i];
    }
    return !increasing;
}

int main()
{
    vector<int> arr = {2, 1};
    cout << validMountainArray(arr) << endl;
    return 0;
}