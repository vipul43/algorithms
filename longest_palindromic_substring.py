##HEADING: LONGEST PALINDROMIC SUBSTRING

#PROBLEM STATEMENT:
"""
    FIND AND RETURN LONGEST PALINDROMIC SUBSTRING PRESENT IN INPUT STRING.
    INPUT IS A STRING AND OUTPUT IS A PALINDROMIC STRING WHICH IS A SUBSTRING OF INPUT STRING.
    ALL SUBSTRINGS OF INPUT STRING OF LENGTH 1 ARE CONSIDERED PALINDROMES.
    IF INPUT STRING IS EMPTY THEN OUTPUT STRING IS ALSO EMPTY.
"""

#SOLUTION-1: (BRUTE_FORCE) --> O(n^3)
def longestPalindromicSubstring1(str: s) -> str:
    n = len(s)
    if(n==0):
        return ""
    max_length = 1
    start_index = 0
    for i in range(n):
        for j in range(i, n):
            l = (j-i+1)
            isPalindrome=True
            for k in range(0, l/2):
                if(s[i+k]!=s[j-k]):
                    isPalindrome=False
            if(isPalindrome and l>max_length):
                max_length=l
                start_index=i
    return s[start_index:start_index+max_length]

#SOLUTION-2: (DP_ALGORITHM) --> O(n^2)
def longestPalindromicSubstring2(str: s) -> str:
    n = len(s)
    if(n==0):
        return ""
    dp = [[False for i in range(n)] for i in range(n)]
    for i in range(n):
        dp[i][i]=True
    max_length = 1
    start_index = 0
    for i in range(n-1):
        if(s[i]==s[i+1]):
            dp[i][i+1]=True
            max_length=2
            start_index=i
    for l in range(3, n+1):
        for i in range(n-l+1):
            j=i+l-1
            if(dp[i+1][j-1] and s[i]==s[j]):
                dp[i][j]=True
                if(l>max_length):
                    max_length=l
                    start_index=i
    return s[start_index:start_index+max_length]

#SOLUTION-3: (ITERATIVE_ALGORITHM) --> O(n^2)
def longestPalindromicSubstring3(s: str) -> str:
    n = len(s)
    if(n==0):
        return ""
    max_length = 1
    start_index = 0
    for i in range(n):
        low = i-1
        high = i
        while(low>=0 and high<n and s[low]==s[high]):
            l = high-low+1
            if(l>max_length):
                max_length = len
                start_index = low
            low-=1
            high+=1
        low = i-1
        high = i+1
        while(low>=0 and high<n and s[low]==s[high]):
            l = high-low+1
            if(l>max_length):
                max_length=l
                start_index=low
    return s[start_index:start_index+max_length]


#SOLUTION-4: (MANACHER'S ALGORITHM) --> O(n)


#DESCRIPTION:
"""
    DISCLAIMER: LENGTH OF LONGEST PALINDROME IS ATLEAST 1 I.E. SINGLE CHARACTER IS CONSIDERED AS A PALINDROME
    IN THE BRUTE FORCE METHOD, THE INDICES i AND j CHOOSE ALL POSSIBLE SUBSTRINGS OF THE STRING S. AND THE INNER
    LOOP CHECKS WHETHER THE CHOOSEN SUBSTRING IS A PALINDROME ALSO KEEPS TRACK OF THE MAX LENGTH PALINDROME
    SO FAR BY TWO OF IT PARAMETERS 1) THE STARTING POINT OF THE PALINDROME, start_index 2) LENGTH OF THE PALINDROME
    max_length. THESE ARE REQUIRED TO CONSTRUCT THE PALINDROME LATER FOR RETURNING.
    IN THE DP ALGORITHM WE CONSTRUCT AN NxN MATRIX. THE VALUE OF THE MATRIX AT POSITION X, Y IS TRUE IF THE SUBSTRING
    OF THE STRING WITH STARTING INDEX AS X AND ENDING INDEX AS Y(BOTH INCLUSIVE) IS A PALINDROME. INTIALLY ALL DIAGONAL
    ELEMENTS ARE TRUE, AS SINGLE CHARACTER IS CONSIDERED AS PALINDROME. THEN CHECK IF 2 LENGTH SUBSTRINGS OF S
    ARE PALINDROMES AND FILL THE MATRIX ACCORDINGLY. NOW CHECK IF LENGTH GREATER THAN 2 SUBSTRINGS S ARE PALINDROMES 
    BY CHECKING IF STRING FROM INDEX i+1 to INDEX j-1 IS A PALINDROME(WHICH WE GET BY MATRIX VALUE AT INDEX i+1, j-1)
    AND CHARACTER AT INDEX i AND CHARACTER AT INDEX j ARE EQUAL. THIS MEANS THAT THERE IS A PALINDROME FROM INDEX i 
    TO INDEX j(BOTH INCLUSIVE). CONSTRUCTING THE WHOLE MATRIX AS SUCH ALSO KEEPING TRACK OF THE MAX LENGTH PALINDROME
    SO FAR BY TWO OF IT PARAMETERS 1) THE STARTING POINT OF THE PALINDROME, start_index 2) LENGTH OF THE PALINDROME
    max_length. THESE ARE REQUIRED TO CONSTRUCT THE PALINDROME LATER FOR RETURNING.
    IN THE ITERATIVE ALGORITHM, THE INDEX i CHOOSES EVERY CHARACTER OF THE STRING, EACH TIME TWO POINTERS LOW AND 
    HIGH START AROUND THE INDEX i. EXPANDING IN BOTH DIRECTIONS AND CHECKING IF THE RESULTANT STRING IS A PALINDROME 
    AND KEEPS TRACK OF THE MAX LENGTH PALINDROME SO FAR BY TWO OF IT PARAMETERS 1) THE STARTING POINT OF THE 
    PALINDROME, start_index 2) LENGTH OF THE PALINDROME max_length. THESE ARE REQUIRED TO CONSTRUCT THE PALINDROME 
    LATER FOR RETURNING. EXPANDING AROUND INDEX i IS DONE TWO TIMES, FIRST TIME TO CHECK FOR EVEN LENGTH PALINDROME 
    AND SECOND TIME TO CHECK FOR ODD LENGTH PALINDROME.
    
    THE BEST ALGORITHM TO USE IS MANACHER'S ALGORITHM, AS IT IS O(n). MANY CP WEBSITES ONLY ACCEPT MANACHER'S
    ALGORITHM SOLUTION.
    
    [FURTHER MODIFICATIONS TO ALGORITHM]
    
    AS DP ALGORITHM AND ITERATIVE ALGORITHM BOTH HAVE SAME TIME COMPLEXITY, IT IS BETTER TO USE ITERATIVE ALGORITHM
    CONSIDERING BOTH HIGH SPACE COMPLEXITY OF DP ALGORITHM AND UNDERSTANDING DIFFICULTY OF DP ALGORITHM.
    
    [NOTE: 2]

"""


#APPLICATION-1: ([APPLICATION PROBLEM STATEMENT]) --> [TIME COMPLEXITY LIKE O(n), O(log2(n)), O(n^2), O(sqrt(n)), O(n/2)==O(n), O(n/3)==O(n)]

#APPLICATION-2: ([APPLICATION PROBLEM STATEMENT]) --> [TIME COMPLEXITY LIKE O(n), O(log2(n)), O(n^2), O(sqrt(n)), O(n/2)==O(n), O(n/3)==O(n)]


#DESCRIPTION:
"""
    [DESCRIPTION LINE1]
    [DESCRIPTION LINE2]
    [DESCRIPTION LINE3]
    [DESCRIPTION LINE4]
    [DESCRIPTION LINE5]

    [NOTE: 1]

"""


#RELATED ALGORITHMS:
"""
    -[RELATED ALGORITHM1]
    -[RELATED ALGORITHM2]
    -[RELATED ALGORITHM3]
"""