#include <bits/stdc++.h>

using namespace std;

bool flag = 0;
void f(int i, int n, int arr[], int targetSum, vector<int> &subset)
{
    if (targetSum == 0)
    {
        flag = 1;
        cout << "[ ";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] << " ";
        }
        cout << "]";
        return;
    }
    if (i == n)
    {
        return;
    }

    f(i + 1, n, arr, targetSum, subset);

    if (arr[i] <= targetSum)
    {
        subset.push_back(arr[i]);

        f(i + 1, n, arr, targetSum - arr[i], subset);

        subset.pop_back();
    }
}

int main()
{
    int n;
    cout << "Enter n" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter array" << endl;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << "Enter targetsum:" << endl;
    int m;
    cin >> m;
    vector<int> subset;
    f(0, n, arr, m, subset);
    if (!flag)
    {
        cout << "NO SUBSET AVAILABLE" << endl;
    }
    return 0;
}