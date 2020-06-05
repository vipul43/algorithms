##HEADING: Primality algorithm

#PROBLEM STATEMENT:
"""
    TO CHECK WHETHER AN INTEGER IS PRIME OR NOT.
    IF THE INTEGER IS PRIME RETURN TRUE.
    ELSE RETURN FALSE.
"""

#SOLUTION-1: (BRUTE_FORCE) --> O(n)
def isPrime1(n: int) -> bool:
    if(n<=1):
        return False
    elif(n==2):
        return True
    else:
        for i in range(2, n):
            if(n%i==0):
                return False
        return True
            
#SOLUTION-2: (BETTER_BRUTE_FORCE) --> O(n/2)==O(n)!
def isPrime2(n: int) -> bool:
    if(n<=1):
        return False
    elif(n==2):
        return True
    else:
        for i in range(2, n//2):
            if(n%i==0):
                return False
        return True
            
#SOLUTION-3: (ALGORIHTHM) --> O(sqrt(n))
def isPrime3(n: int) -> bool:
    if(n<=1):
        return False
    elif(n<=3):
        return True
    elif(n%2==0 or n%3==0):
        return False
    else:
        for i in range(5, int(n**0.5)+1):
            if(n%i==0):
                return False
        return True
            
#SOLUTION-4 (BETTER_ALGORITHM) --> O(sqrt(n)/3)==O(sqrt(n))!
def isPrime4(n: int) -> bool:
    if(n<=1):
        return False
    elif(n<=3):
        return True
    elif(n%2==0 or n%3==0):
        return False
    else:
        i=5
        while(i<=int(n**0.5)):
            if(n%i==0 or n%(i+2)==0):
                return False
            i=i+6
        return True
 
 
#DESCRIPTION:
    """
        OPTIMIZATION-1: (ALGORITHM)
            INSTEAD OF CHECKING TILL n, WE CAN CHECK TILL sqrt(n).
            BECAUSE A LARGER FACTOR OF n MUST BE A MULTIPLE OF SMALLER
            FACTOR THAT HAS BEEN ALREADY CHECKED.
        OPTIMIZATION-2: (BETTER_ALGORITHM)
            ALL INTEGERS CAN BE EXPRESSED AS THE FORM OF 6k+i.
            WHERE k IS SOME INTEGER. AND i IS 0, 1, 2, 3, 4, 5.
            OF THESE PRIME NUMBERS TAKE THE FORM WHERE i = 1 OR 5.
            I.E. PRIME NUMBERS ARE OF FORM 6k+1 or 6k+5.
            OR 6k-1 or 6k+1.
            SO WE CHECK DIVISIBLITY BY NUMBERS OF THIS FORMS ONLY.
            HERE i IS ALWAYS OF FORM 6k-1. AND i+2 OF FORM 6k+1.
            
        NOTE: isprime() IS A FUNCTION IN sympy MODULE WHICH CHECKS THE PRIMALITY.
    """
        
#RELATED ALGORITHMS:
    """
        -FERMAT PRIMALITY TEST METHOD
        -MILLER RABIN PRIMALITY TEST METHOD
        -SOLOVAY STRASSEN PRIMALITY TEST METHOD
        -PRIMALITY TEST USING LUCAS LEHMER SERIES
        -AKS(AGRAWAL-KAYAL-SAXENA) PRIMALITY TEST METHOD
        -LUCAS PRIMALITY TEST
        -WILSON PRIMALITY TEST
        -VANTIEGHEMS THEOREM FOR PRIMALITY TEST
    """
            
