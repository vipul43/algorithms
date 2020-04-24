##HEADING: Binary Search Algorithm

#PROBLEM STATEMENT:
"""
    TO CHECK WHETHER A SORTED ARRAY CONTAINS GIVEN ELEMENT(INTEGER).
    IF THE ELEMENT IS PRESENT RETURN ITS INDEX.
    ELSE RETURN -1. 
"""

#SOLUTION-1: (BRUTE_FORCE) --> O(n)
def search1(arr: List[int], key: int) -> int:
    for i in range(len(arr)):
        if(arr[i]==key):
            return i
    return -1

#SOLUTION-2: (BETTER_BRUTE_FORCE) --> O(n)
def search2(arr: List[int], key: int) -> int:
    try: 
        return arr.index(key)
    except:
        return -1

#SOLUTION-3: (ITERATIVE_ALGORITHM) --> O(log(n))
def search3(arr: List[int], key: int) -> int:
    n = len(arr)
    L = 0
    R = n-1
    while(L<=R):
        mid = L + (R-L)//2
        if arr[mid] == key:
            return mid
        if arr[mid] < key:
            L = mid + 1
        else:
            R = mid - 1
    return -1

#SOLUTION-4: (RECURSIVE_ALGORITHM) --> O(log(n))
def search4(arr: List[int], key: int, L: int, R: int) -> int:
    if L<=R:
        mid = L + (R-L)//2
        if arr[mid]==key:
            return mid
        if arr[mid] < key:
            return search4(arr, key, mid+1, R)
        else:
            return search4(arr, key, L, mid-1)
    else:
        return -1
# #DRIVER CODE FOR SOLUTION-4
# result = search4(arr, key, 0, n-1)

#DESCRIPTION:
    """
        ##DISCLAIMER: EXPLANATION IS ASSUMING THAT ARRAY IS SORTED IN ASCENDING ORDER.
        OPTIMIZATION:
        IN A SORTED ARRAY INSTEAD OF SEARCHING FOR WHOLE ARRAY LINEARLY
        WHICH TAKES TIME O(n), WE CAN SEARCH BY DIVIDE AND CONQUER TECHNIQUE.
        COM PARE THE TARGET VALUE WHICH IS TO BE SEARCHED WITH THE MIDDLE ELEMENT.
        IF MATCHES THEN RETURN THE MIDDLE ELEMENTS INDEX.
        ELSE IF THE TARGET VALUE IS GREATER THAN THE MIDDLE ELEMENT, SEARCH FOR
        THE TARGET VALUE IN RIGHT PART OF THE ARRAY. WHICH STARTS FROM ELEMENT
        AFTER THE MIDDLE ELEMENT AND ENDS AT THE END OF THE ARRAY.
        ELSE IF THE TARGET VALUE IS LESS THAN THE MIDDLE ELEMENT< SEARCH FOR
        THE TARGET VALUE IN LEFT PART OF THE ARRAY. WHICH STARTS FROM ELEMENT
        AT THE BEGINNING AND ENDS BEFORE THE MIDDLE ELEMENT.
        CONTINUE THIS PROCESS OF MAKING THE SEARCH SPACE SMALLER.
        IF THE SEARCH SPACE IS SMALLER ENOUGH COMPRISING OF ONLY ONE ELEMENT
        AND THAT ELEMENT IS NOT THE TARGET VALUE THEN THE ARRAY DOESN'T CONTAIN
        THE GIVEN TARGET VALUE RETURN -1.
        
        BOTH ITERATIVE AND RECURSIVE ALGORITHMS ACHIEVE THE SAME RESULT.
        
        ALGORITHM CAN FURTHER BE MODIDFIED TO RETURN TRUE IF THE TARGET ELEMENT
        IS IN THE ARRAY ELSE FALSE
        
        NOTE: FINDING THE MIDDLE ELEMENT IS DONE THAT WAY TO AVOID OVERFLOW.
    
    """
    
    
#RELATED ALGORITHMS:
    """
        -BINARY SEARCH IN SORTED ROTATED ARRAY
        -FINDING MINIMUM ELEMENT IN SORTED ROTATED ARRAY
        -META BINARY SEARCH
        -TERNARY SEARCH
    """

    
