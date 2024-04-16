/*
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. 
Merge them in sorted order without using any extra space. 
Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

Example 1:

Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]


*****************************************************************
TECHNICALLY USING THREE POINTERS ONE AT BEGINNING OF arr1(i) AND SECOND AT END OF arr1(k) AND THIRD AT BEGIINNING OF arr2(j)...
 void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
           int i = 0, j = 0, k = n - 1; 
 
    // Until i less than equal to k
    // or j is less than m
            while (i <= k && j < m) {// ANY ONE CONDITION SATISFIES THEN THE LOOP STOPS
                if (arr1[i] < arr2[j])
                     i++;
                 else {
                    swap(arr2[j], arr1[k]);// SWAPPING AT THE END OF arr1 AND REDUCING ITS SIZE
                    j++;
                    k--;
                     }
                }
 
    // Sort first array
             sort(arr1, arr1 + n);
 
    // Sort second array
            sort(arr2, arr2 + m);
        } 

        Time Complexity: O((N+M) * log(N+M))
*/