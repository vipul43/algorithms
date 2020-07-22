#include <bits/stdc++.h>
using namespace std;
//HEADING: STRING MATCHING//

//PROBLEM STATEMENT:
/*
    FIND THE NUMBER OF OCCURENCES OF A SUBSTRING IN A GIVEN STRING.
    NUMBER OF OCCURENCES ALSO INCLUDE OVERLAPPING SUBSTRINGS.
    NUMBER OF OCCURENCES ALSO INCLUDE REPETIIONS.
    ALGORITHM RETURNS THE NUMBER OF SUCH OCCURENCES.
*/

//SOLUTION-1: (BRUTE_FORCE) --> [O(m(n-m+1))]
int stringSearch1(string s, string sub_s){
    int n = s.length();
    int m = sub_s.length();
    int count=0;
    for(int i=0; i<n-m+1; ++i){
        int l=0;
        for(int j=i; j<m; ++j){
            if(s[j]!=sub_s[l]){
                break;
            }
            l+=1;
        }
        if(l==m){
            count+=1;
        }
    }
    return count;
}

//SOLUTION-2: (KMP ALGORITHM) --> [O(m+n)]
int stringSearch2(string s, string sub_s){
    int n = s.length();
    int m = sub_s.length();

    int lps[m];
    int l=0;
    lps[0]=0;
    int i=1;
    while(i<m){
        if(sub_s[i]==sub_s[l]){
            l+=1;
            lps[i]=l;
            i+=1;
        } else {
            if(l!=0){
                l=lps[l-1];
            } else {
                lps[i]=0;
                i+=1;
            }
        }
    }

    i=0;
    int j=0;
    int count=0;
    while(i<n){
        if(s[i]==sub_s[j]){
            i+=1;
            j+=1;
        }
        if(j==m){
            count+=1;
            j=lps[j-1];
        } else if(i<n && s[i]!=sub_s[j]){
            if(j!=0){
                j=lps[j-1];
            } else {
                i+=1;
            }
        }
    }
    return count;
}


//DESCRIPTION:
/*
    DISCLAIMER: IN THE PROBLEM WHILE COUNTING THE NUMBER OF OCCURENCES OF SUBSTRING IN A STRING REPETITIONS
    AND OVERLAPPING IS CONSIDERED.
    IN THE BRUTE FORCE METHOD, WE ITERATE THROUGH EACH INDEX OF THE STRING s AND MATCH THE STRING sub_s FROM 
    THAT INDEX, IF MATCH OCCURS THEN WE COUNT IT AND MOVE THE INDEX OF THE STRING s BY 1 AND AGAIN MATCH THE
    STRING sub_s FROM THAT INDEX. IF MISMATCH THEN WE MOVE THE INDEX OF THE STRING BY s AND MATCH THE 
    STRING sub_s.
    IN THE KMP ALGORITHM, THERE ARE TWO PARTS, ONE IS CREATING LONGEST PREFIX WHIXH IS ALSO A SUFFIX(LPS) ARRAY
    FROM THE STRING sub_s. THIS ARRAY WILL HELP IN MATCHING THE sub_s TO s WHEN THERE IS A MISMATCH.
    WHEN THERE IS A MISMATCH INSTEAD OF MOVING THE INDEX OF THE STRING s TO NEXT POSITION I.E. INCREMENTING BY
    ONE, MOVE IT TO THE POSITION IN STRING s ACCORDING TO THE PREVIOUSLY CREATED LPS ARRAY.
    IN THE LPS ARRAY WE HAVE THE INFO ABOUT THE LONGEST PREFIX WHICH IS ALSO A SUFFIX IN STRING sub_s. IF A
    MISMATCH OCCURS at INDEX i IN STRING s, THEN INSTEAD OF MOVING TO NEXT POSITION, MOVE TO THE POISITION
    AFTER THE LONGEST PREFIX WHICH IS ALSO SUFFIX BEFORE THE MISMATCH POSITION.
    
    THE ALGORITHM CAN BE FURTHER MODIFIED TO RETURN THE INDICES WHERE THE MATCHING OCCURED.
    
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