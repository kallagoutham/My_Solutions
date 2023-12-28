class Solution {
public:
    int sumofMultiplesDivisibleBy(int number,int maxDigit){
        //using sum of terms in the AP first term and last term by finding the last term with the below logic
        int t = maxDigit/number;
        return (t*(number *(1+ t)))/2;
    }
    int sumOfMultiples(int n) {
        //as the sum is multiples of 3,5,7 
        //n(A U B U C) = n(A) + n(B) + n(C) - n(A ∩ B) - n(B ∩ C) - n(C ∩ A) + a(A ∩ B ∩ C)
        return sumofMultiplesDivisibleBy(3,n)+sumofMultiplesDivisibleBy(5,n)+sumofMultiplesDivisibleBy(7,n) - sumofMultiplesDivisibleBy(3*5,n) - sumofMultiplesDivisibleBy(5*7,n) - sumofMultiplesDivisibleBy(7*3,n) + sumofMultiplesDivisibleBy(3*5*7,n);
    }
};
