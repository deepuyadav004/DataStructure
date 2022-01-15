 bool findTriplets(int arr[], int n)
    { 
        //Your code here
        sort(arr, arr+n);
        for(int i=0; i<n; i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int res=(arr[i]+arr[l]+arr[r]);
                if(!res) return 1;
                if(res < 0) l++;
                else r--;
            }
        }
        return 0;
    }

