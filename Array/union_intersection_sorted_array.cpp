#include <bits/stdc++.h>
using namespace std;

void unionn(int arr1[], int arr2[], int n1, int n2)
{
    int uni[n1 + n2];
    int i = 0, j = 0;
    int c = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            uni[c] = arr1[i];
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            uni[c] = arr2[j];
            j++;
        }
        else
        {
            uni[c] = arr1[i];
            i++, j++;
        }
        c++;
    }
    while (i < n1)
    {
        uni[c] = arr1[i];
        c++;
        i++;
    }
    while (j < n2)
    {
        uni[c] = arr2[j];
        c++;
        j++;
    }
    cout << "Union: ";
    for (int k = 0; k < c; k++)
        cout << uni[k] << " ";
    cout << endl;
}
void intersection(int arr1[], int arr2[], int n1, int n2)
{
    int inter[n1 < n2 ? n1 : n2];
    int i = 0, j = 0, c = 0;
    while (i < n1 && j < n2)
    {

        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else
        {
            inter[c] = arr1[i];
            i++, j++;
            c++;
        }
    }
    cout << "Intersection: ";
    for (int k = 0; k < c; k++)
        cout << inter[k] << " ";
    cout << endl;
}

int main()
{
    int arr1[] = {1, 3, 4, 5, 7};
    int arr2[] = {2, 3, 5, 6};
    int n1 = 5;
    int n2 = 4;

    unionn(arr1, arr2, n1, n2);
    intersection(arr1, arr2, n1, n2);
}