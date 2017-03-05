#include<bits/stdc++.h>
using namespace std;
long long int s=0;
//Just replace start with last to count for last element as pivot
//just replace median of index to get count  for  median element as pivot
void QuickSort(long long int arr[],long long int start,long long int last)
{
     long long int i=start+1,j=last,temp;
     if(i>j)
     return;
     while(i<=j)
     {
              if(arr[i]<=arr[start])
              {
                               i++;
              }
              if(arr[j]>=arr[start])
              {
                               j--;
              }
              if(i<=j)
              {
                  temp=arr[i];
                  arr[i]=arr[j];
                  arr[j]=temp;
              }
      }

       temp=arr[start];
       arr[start]=arr[j];
       arr[j]=temp;
        s+=last-start-1;
       QuickSort(arr,start,j-1);
       QuickSort(arr,j+1,last);
}

int main()
{
     //faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin>>n;
    long long int arr[n];
    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    QuickSort(arr,0,n-1);
    cout<<s<<endl;
}
