//HEADING: NUMBER OF TRAILING ZEROS IN FACTORIAL OF A NUMBER//

//PROBLEM STATEMENT:
/*
    FIND AND PRINT THE NUMBER OF TRAILING ZEROS IN FACTORIAL OF A NUMBER. 
*/

//SOLUTION-1: (BRUTE_FORCE) --> O(n)
int findTrailingZerosInFact(int n) {
    int count = 0;
    int i = 5;
    while((n/i)>=1) {
        count += (n/i);
        i *= 5;
    }
    return count;
}

//DESCRIPTION:
    /*
        TO COUNT NUMBER OF SINGLE 5 OCCURENCES DOUBLE 5 OCCURENCES... 
        DIVIDING THE NUMBER BY 5 THE QUOTIENT WILL RESULT IN NUMBER OF 5'S.
        SIMILARLY DIVIDING THE NUMBER BY 25 WILL RESULT IN NUMBER OF 25'S.
        ...

        NOTE: trailingZerosCount = floor(n/5) + floor(n/5^2) + ... + floor(n/5^k) 
                where 5^k <= n
    
    */


//RELATED ALGORITHMS:
    /*
        -FIND THE SMALLEST NUMBER WHICH HAS ATLEAST k ZEROS IN ITS FACTORIAL
    */
