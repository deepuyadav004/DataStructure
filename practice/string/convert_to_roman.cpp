Given an integer n, your task is to complete the function convertToRoman which prints the corresponding roman number of n. Various symbols and their values are given below.
  

I 1
V 5
X 10
L 50
C 100
D 500
M 1000

 

Example 1:

Input:
n = 5
Output: V



Algorithm to convert decimal number to Roman Numeral 
Compare given number with base values in the order 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1. Base value which is just smaller or equal to the given number will 
be the initial base value (largest base value) .Divide the number by its largest base value, the corresponding base symbol will be repeated quotient times, the remainder 
will then become the number for future division and repetitions.The process will be repeated until the number becomes zero.


  
Step 1


Initially number = 3549
Since 3549 >= 1000 ; largest base value will be 1000 initially.
Divide 3549/1000. Quotient = 3, Remainder =549. The corresponding symbol M will be repeated thrice.
We append the Result value in the 2nd List.
Now Remainder is not equal to 0 so we call the function again.
Step 2


Now, number = 549
1000 > 549 >= 500 ; largest base value will be 500.
Divide 549/500. Quotient = 1, Remainder =49. The corresponding symbol D will be repeated once & stop the loop.
We append the Result value in the 2nd List.
Now Remainder is not equal to 0 so we call the function again.
Step 3


Now, number = 49
50 > 49 >= 40 ; largest base value is 40.
Divide 49/40. Quotient = 1, Remainder = 9. The corresponding symbol XL will be repeated once & stop the loop.
We append the Result value in the 2nd List.
Now Remainder is not equal to 0 so we call the function again.
Step 4


Now, number = 9
Number 9 is present in list ls so we directly fetch the value from dictionary dict and set Remainder=0 & stop the loop.
Remainder = 0. The corresponding symbol IX will be repeated once and now remainder value is 0 so we will not call the function again.
Step 5


Finally, we join the 2nd list values.
The output obtained MMMDXLIX.
  
  
  
   string convertToRoman(int n) {
        // code here
         int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12;
    string ans="";
    while(n>0){
        int div=n/num[i];
        n=n%num[i];
        while(div--){
            ans+=sym[i];
        }
        i--;
    }
    return ans;
    
    }
