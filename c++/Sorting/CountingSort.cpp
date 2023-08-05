#include <bits/stdc++.h>
using namespace std;

void printArray(int *A,int n) {
    for(int i=0;i<n;i++) {
        cout<< A[i] << " ";
    }
    cout << endl;
}
int maximum(int A[],int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
            max = A[i];
    }
    return max;
}
void CountSort(int *A,int n){
    int i,j;
   int max=maximum(A,n);
   int* count=(int *)malloc((max+1)*sizeof(int));

   for(i=0;i<max+1;i++)
    count[i]=0;

    for(i=0;i<n;i++) {
    count[A[i]] = count[A[i]] + 1;
    }
    i=0,j=0;
    while(i<=max) {
        if(count[i] >0) {
            A[j]=i;
            count[i]=count[i]-1; 
            j++;
        }
        else {
            i++;
        }
    }
} 
int main()
{
    int A[]={9,1,4,14,4,15,6};
    int n=7;
    printArray(A,n);

    CountSort(A,n);

    printArray(A,n);
    return 0;
}
// // C++ Program for counting sort
// #include <bits/stdc++.h>
// #include <string.h>
// using namespace std;
// #define RANGE 255

// // The main function that sort
// // the given string arr[] in
// // alphabetical order
// void countSort(char arr[])
// {
//     // The output character array
//     // that will have sorted arr
//     char output[strlen(arr)];

//     // Create a count array to store count of individual
//     // characters and initialize count array as 0
//     int count[RANGE + 1], i;
//     memset(count, 0, sizeof(count));

//     // Store count of each character
//     for (i = 0; arr[i]; ++i)
//         ++count[arr[i]];

//     // Change count[i] so that count[i] now contains actual
//     // position of this character in output array
//     for (i = 1; i <= RANGE; ++i)
//         count[i] += count[i - 1];

//     // Build the output character array
//     for (i = 0; arr[i]; ++i)
//     {
//         output[count[arr[i]] - 1] = arr[i];
//         --count[arr[i]];
//     }

//     /*
//     For Stable algorithm
//     for (i = sizeof(arr)-1; i>=0; --i)
//     {
//         output[count[arr[i]]-1] = arr[i];
//         --count[arr[i]];
//     }

//     For Logic : See implementation
//     */

//     // Copy the output array to arr, so that arr now
//     // contains sorted characters
//     for (i = 0; arr[i]; ++i)
//         arr[i] = output[i];
// }

// // Driver code
// int main()
// {
//     char arr[] = "geeksforgeeks";

//     // Function call
//     countSort(arr);

//     cout << "Sorted character array is " << arr;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// void countSort(vector<int> &arr)
// {
//     int max = *max_element(arr.begin(), arr.end());
//     int min = *min_element(arr.begin(), arr.end());
//     int range = max - min + 1;

//     vector<int> count(range), output(arr.size());
//     for (int i = 0; i < arr.size(); i++)
//         count[arr[i] - min]++;

//     for (int i = 1; i < count.size(); i++)
//         count[i] += count[i - 1];

//     for (int i = arr.size() - 1; i >= 0; i--)
//     {
//         output[count[arr[i] - min] - 1] = arr[i];
//         count[arr[i] - min]--;
//     }

//     for (int i = 0; i < arr.size(); i++)
//         arr[i] = output[i];
// }

// void printArray(vector<int> &arr)
// {
//     for (int i = 0; i < arr.size(); i++)
//         cout << arr[i] << " ";
//     cout << "\n";
// }

// // Driver code
// int main()
// {
//     vector<int> arr = {-5, -10, 0, -3, 8, 5, -1, 10};

//     // Function call
//     countSort(arr);
//     printArray(arr);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> countingSort(vector<int> vec, int n)
// {
//     for (int i = 0; i < n; cin >> vec[i], i++)
//         ;
//     map<int, int> count;
//     // Here we are initializing every element of count to 0
//     // from 1 to n
//     for (int i = 0; i < n; count[i] = 0, i++)
//         ;
//     // Here we are storing count of every element
//     for (int i = 0; i < n; count[vec[i]]++, i++)
//         ;
//     vector<int> sortedArr;
//     int i = 0;
//     while (n > 0)
//     {
//         // Here we are checking if the count[element] = 0
//         // then incrementing for the next Element
//         if (count[i] == 0)
//         {
//             i++;
//         }
//         // Here we are inserting the element into the
//         // sortedArr decrementing count[element] and n by 1
//         else
//         {
//             sortedArr.push_back(i);
//             count[i]--;
//             --n;
//         }
//     }
//     return sortedArr;
// }

// void printArr(vector<int> vec, int n)
// {
//     cout << "Sorted Array: ";
//     for (int i = 0; i < n; cout << vec[i] << " ", i++)
//         ;
//     cout << endl;
// }
// signed main()
// {
//     vector<int> vec1 = {6, 0, 7, 8, 7, 2, 0};
//     vector<int> sortedArr1 = countingSort(vec1, vec1.size());
//     printArr(sortedArr1, sortedArr1.size());

//     vector<int> vec2 = {4, 8, 1, 0, 1, 1, 0, 0};
//     vector<int> sortedArr2 = countingSort(vec2, vec2.size());
//     printArr(sortedArr2, sortedArr2.size());

//     return 0;
// }