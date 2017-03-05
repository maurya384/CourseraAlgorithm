//c++ Program To Count no of Inversion
#include<bits/stdc++.h>
using namespace std;

long long int getSum(long long int BITree[], long long int index)
{
    long long int sum = 0;

    while (index > 0)
    {

        sum += BITree[index];


        index -= index & (-index);
    }
    return sum;
}

void updateBIT(long long int BITree[], long long int n, long long int index, long long int val)
{
    while (index <= n)
    {
       BITree[index] += val;

       index += index & (-index);
    }
}

long long int getInvCount(long long int arr[], long long int n)
{
    long long int invcount = 0;

    long long int maxElement = 0;
    for (long long int i=0; i<n; i++)
        if (maxElement < arr[i])
            maxElement = arr[i];

    long long int BIT[maxElement+1];
    for (long long int i=1; i<=maxElement; i++)
        BIT[i] = 0;


    for (long long int i=n-1; i>=0; i--)
    {

        invcount += getSum(BIT, arr[i]-1);


        updateBIT(BIT, maxElement, arr[i], 1);
    }

    return invcount;
}

int main()
{
     //faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin>>n; // take 10000 as input
    long long int arr[n];
    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout << "Number of inversions are : " << getInvCount(arr,n);
    return 0;
}
