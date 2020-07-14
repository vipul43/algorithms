#include <string>
using namespace std;
//HEADING: LONGEST PALINDROMIC SUBSTRING//

//PROBLEM STATEMENT:
/*
    FIND AND RETURN LONGEST PALINDROMIC SUBSTRING PRESENT IN INPUT STRING.
    INPUT IS A STRING AND OUTPUT IS A PALINDROMIC STRING WHICH IS A SUBSTRING OF INPUT STRING.
    ALL SUBSTRINGS OF INPUT STRING OF LENGTH 1 ARE CONSIDERED PALINDROMES.
    IF INPUT STRING IS EMPTY THEN OUTPUT STRING IS ALSO EMPTY.
*/

//SOLUTION-1: (BRUTE_FORCE) --> O(n^3)
string longestPalindromicSubstring1(string s) {
    int n = s.length();
    if(n==0){
        return "";
    }
    int max_length = 1;
    int start_index = 0;
    for(int i=0; i<n; ++i){
        for(int j=i; j<n; ++j){
            int len = (j-i+1);
            bool isPalindrome=true;
            for(int k=0; k<len/2; ++k){
                if(s[i+k]!=s[j-k]){
                    isPalindrome=false;
                }
            }
            if(isPalindrome && len>max_length){
                max_length=len;
                start_index=i;
            }
        }
    }
    return s.substr(start_index, max_length);
}

//SOLUTION-2: (DP_ALGORITHM) --> O(n^2)
string longestPalindromicSubstring2(string s) {
    int n = s.length();
    if(n==0){
        return "";
    }
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    for(int i=0; i<n; ++i){
        dp[i][i]=true;
    }
    int max_length = 1;
    int start_index = 0;
    for(int i=0; i<n-1; ++i){
        if(s[i]==s[i+1]){
            dp[i][i+1]=true;
            max_length=2;
        }
    }
    for(int len=3; len<=n; ++len){
        for(int i=0; i<n-len+1; ++i){
            int j=i+len-1;
            if(dp[i+1][j-1] && s[i]==s[j]){
                dp[i][j]=true;
                if(len>max_length){
                    max_length=len;
                    start_index=i;
                }
            }
        }
    }
    return s.substr(start_index, max_length);
}

//SOLUTION-3: (ITERATIVE_ALGORITHM) --> O(n^2)
string longestPalindromicSubstring3(string s) {
    int n = s.length();
    if(n==0){
        return "";
    }
    int max_length=1;
    int start_index=0;
    for(int i=0; i<n; ++i){
        int low = i-1;
        int high = i;
        while(low>=0 && high<n && s[low]==s[high]){
            int len = high-low+1;
            if(len>max_length){
                max_length = len;
                start_index = low;
            }
            --low;
            ++high;
        }
        int low = i-1;
        int high = i+1;
        while(low>=0 && high<n && s[low]==s[high]){
            int len = high-low+1;
            if(len>max_length){
                max_length=len;
                start_index=low;
            }
        }
    }
    return s.substr(start_index, max_length);

//SOLUTION-4: (MANACHER'S ALGORITHM) --> O(n)

//DESCRIPTION:
/*
    DISCLAIMER: LENGTH OF LONGEST PALINDROME IS ATLEAST 1 I.E. SINGLE CHARACTER IS CONSIDERED AS A PALINDROME
    [DESCRIPTION LINE1]
    [DESCRIPTION LINE2]
    [DESCRIPTION LINE3]
    [DESCRIPTION LINE4]
    [DESCRIPTION LINE5]
    [DESCRIPTION LINE6]
    [DESCRIPTION LINE7]
    [DESCRIPTION LINE8]
    
    THE BEST ALGORITHM TO USE IS MANACHER'S ALGORITHM, AS IT IS O(n). MANY CP WEBSITES ONLY ACCEPT MANACHER'S
    ALGORITHM SOLUTION
    
    [FURTHER MODIFICATIONS TO ALGORITHM]
    
    [NOTE: 1]
    
    [NOTE: 2]

*/
    

//APPLICATION-1: ([APPLICATION PROBLEM STATEMENT]) --> [TIME COMPLEXITY LIKE O(n), O(log2(n)), O(n^2), O(sqrt(n)), O(n/2)==O(n), O(n/3)==O(n)]

//APPLICATION-2: ([APPLICATION PROBLEM STATEMENT]) --> [TIME COMPLEXITY LIKE O(n), O(log2(n)), O(n^2), O(sqrt(n)), O(n/2)==O(n), O(n/3)==O(n)]


//DESCRIPTION:
/*
    [DESCRIPTION LINE1]
    [DESCRIPTION LINE2]
    [DESCRIPTION LINE3]
    [DESCRIPTION LINE4]
    [DESCRIPTION LINE5]

    [NOTE: 1]

*/


//RELATED ALGORITHMS:
/*
    -[RELATED ALGORITHM1]
    -[RELATED ALGORITHM2]
    -[RELATED ALGORITHM3]
*/