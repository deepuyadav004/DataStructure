
// Recursive solution

#include <iostream>
#include<vector>

using namespace std;

bool cansum(int targetSum, vector<int> number){
    if(targetSum==0) return true;
    if(targetSum < 0) return false;
    
    for(int i : number){
        int rem=targetSum-i;
        if(cansum(rem,number)){
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> nums={2,4,3,7};
    cout<<cansum(7,nums)<<endl;

    return 0;
}


// optimized solution using dynamic programming
