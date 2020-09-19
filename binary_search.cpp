//HEADING: BINARY SEARCH ALGORITHM//

//PROBLEM STATEMENT:
/*
    TO CHECK WHETHER A SORTED ARRAY CONTAINS GIVEN ELEMENT(INTEGER).
    IF THE ELEMENT IS PRESENT RETURN ITS INDEX.
    ELSE RETURN -1. 
*/

//SOLUTION-1: (BRUTE_FORCE) --> O(n)
int search1(int arr[], int key) {
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<n; i++) {
        if (arr[i]==key) {
            return i;
        }
    }
    return -1;
}

//SOLUTION-2: (ITERATIVE_ALGORITHM) --> O(log2(n))
int search2(int arr[], int key) {
    int n = sizeof(arr)/sizeof(arr[0]);
    int L = 0;
    int R = n-1;
    while (L<=R) {
        int mid = L + (R-L)/2;
        if (arr[mid]==key) {
            return mid;
        }
        if (arr[mid] < key) {
            L = mid + 1;
        }
        else {
            R = mid - 1;
        }
    }
    return -1;
}

//SOLUTION-3: (RECURSIVE_ALGORITHM) --> O(log2(n))
int search3(int arr[], int key, int L, int R) {
    if (L<=R) {
        int mid = L + (R-L)/2;
        if (arr[mid]==key) {
            return mid;
        }
        if (arr[mid] < key) {
            return search3(arr, key, mid+1, R);
        }
        else {
            return search3(arr, key, L, mid-1);
        }
    }   
    else {
        return -1;
    }
}
// //DRIVER CODE FOR SOLUTION-3
// int result = search3(arr, key, 0, n-1);


//DESCRIPTION:
    /*
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
    
    */
    

//APPLICATION-1: (MINIMUM ELEMENT GREATER THAN EQUAL TO key) --> O(log2(n))
int searchMinGreaterEqualToKey(int arr[], int key) {
    int n = sizeof(arr)/sizeof(arr[0]);
    int L = 0;
    int R = n-1;
    int ans = -1;                       //+
    while (L<=R) {
        int mid = L + (R-L)/2;
        if(arr[mid]>=key) {             //+
            ans = mid;                  //+
            R = mid-1;
        }
        else {
            L = mid+1;
        }
    }
    return ans;
}

//DESCRIPTION:
    /*
        SIMILAR TO BINARY SEARCH LOOK AT THE MIDDLE VALUE IN THE ARRAY, IF IT SATISFIES 
        OUR CRITERIA(GREATER THAN OR EQUAL TO KEY) THAN LOOK FOR SMALLER ELEMENT THAN 
        THE MIDDLE ELEMENT TO SATISFY COMPLETE CRITERIA(MINIMUM ELEMENT GREATER THAN OR
        EQUAL TO KEY).
        ELSE DEPENDING ON THE VALUE OF THE MIDDLE ELEMENT SEARCH IN LEFT SUB ARRAY(IF 
        ELEMENT IS GREATER THAN KEY) OR RIGHT SUB ARRAY(IF ELEMENT IS SMALLER THAN KEY).
        THE CHANGE IN THIS APPLICATION IS WE SHOULD'NT TERMINATE THE WHILE LOOP 
        IMMEDIATELY AFTER GETTING THE ELEMENT WHICH SATISFIES THE CRITERIA, WE HAVE TO 
        LOOK FURTHER FOR SMALLER OF ALL THOSE ELEMENTS WHICH SATISFIES THE CRITERIA.
        ADDITIONAL MODIFICATIONS CAN BE MADE TO RETURN VALUE OF THE KEY ELEMENT INSTEAD.

        NOTE: ADDITIONAL CHANGES MADE TO ACCUSTOM FOR THE PROBLEM STATEMENT ARE MARKED
        WITH "//+" MEANING INSERTION AND "//-" MEANING DELETION.

    */

//APPLICATION-2: (FLOOR OF SQUARE ROOT OF INTEGER) --> O(log2(n))
int squareRoot(int n){
    int l = 0;
    int r = n;
    int ans;
    while(l<=r){
        int mid = l + (r-l)/2;
        if((long long) mid*mid <=n){
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
	}
    }
    return ans;
}

//DESCRIPTION:
    /*
        WE NEED TO SEARCH FOR SQUAREROOT OF n FROM 0 to n. IF n IS PERFECT SQUARE THEN
        THE ANSWER WOULD BE SQUAREROOT OF n. IF n IS NOT A PERFECT SQUARE THEN THE
        ANSWER WOULD BE FLOOR OF THE SQUAREROOT OF n. AS USUAL BINARY SEARCH
        INITIALISATIONS AND WHILE LOOP BUT THE CHECK STATEMENT INSIDE WHILE LOOP IS 
        FOR mid SQUARED. CHECK FOR THE MAXIMUM ELEMENT THAT SATISFIES THE INEQUALITY
        mid*mid <= n, THAT WAY IF n IS PERFECT SQUARE THEN WE END UP GETTING 
        SQUAREROOT OF n. ELSE WHEN THE WHILE LOOP CONDITION IS MET SOME INTEGER
        WHICH SATISFIES THE INEQUALITY WOULD BE FOUND. THAT IS THE FLOOR OF SQUAREROOT
        OF n.
    */

//RELATED ALGORITHMS:
    /*
        -BINARY SEARCH IN SORTED ROTATED ARRAY
        -FINDING MINIMUM ELEMENT IN SORTED ROTATED ARRAY
        -META BINARY SEARCH
        -TERNARY SEARCH
    */
