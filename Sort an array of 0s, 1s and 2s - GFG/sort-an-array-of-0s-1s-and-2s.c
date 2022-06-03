// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

void sort012(int a[], int n)
{
    int i, countZero, countOne, countTwo;
    i = countZero = countOne = countTwo = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            countZero++;
        }
        else if (a[i] == 1)
        {
            countOne++;
        }
        else
        {
            countTwo++;
        }
    }
    for (i = 0; i < countZero; i++)
    {
        a[i] = 0;
    }
    for (i = countZero; i < countZero + countOne; i++)
    {
        a[i] = 1;
    }
    for (i = countZero + countOne; i < n; i++)
    {
        a[i] = 2;
    }
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends