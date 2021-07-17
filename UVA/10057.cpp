    #include <bits/stdc++.h>
    using namespace std ;
    int main ()
    {
        int n; 
        while (cin>>n)
        {
            int arr[n];
            map<int,int>req ; 
            for (int i =0 ;i < n ;i++)cin>>arr[i],req[arr[i]]++;
            sort(arr ,arr+n);
            if ( n%2==0 )
            {
                n--;
                int mid1=n/2;
                int mid2=mid1+1;
                cout<< arr[mid1] <<" "<<((arr[mid1]!=arr[mid2])?req[arr[mid1]]+req[arr[mid2]] : req[arr[mid1]])<<" "<<arr[mid2]-arr[mid1]+1<<"\n";
            }
            else 
            {
                int mid = n/2;
                cout<<arr[mid]<<" "<<req[arr[mid]]<<" 1\n";
            }
        }
        return 0 ;
    }