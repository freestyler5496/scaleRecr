#include <cstdlib>
#include <fstream>     // file operations
#include <iostream>
#include <ctime>
using namespace std;
    struct Node
    {
        char *item;
        Node* next;
    };

void findSubsets(const int *arr, int n, int k, int *taken, const int step)
{
    if(k==0)
    {
        for(int j=0; j<n; j++)
            if(taken[j] == 1)
                cout << arr[j];
            cout << endl;
    }

    else if(step < n)
    {
        taken[step]=0;
        findSubsets(arr+1, n-1, k, taken, step+1);
        taken[step]=1;
        findSubsets(arr+1, n-1, k-1, taken, step+1);
    }

    // k!=0 ==> do nothing;
}



bool isPalindrome(char *str, int size)
{
    if(size <= 1)
        return true;
    if(str[0] == str[size-1])
        return isPalindrome(str+1, size-2);
    else
        return false;

}

void writeBackward(char *str)
{
    if((*str) != '\0')
        writeBackward(str+1);
    cout << *str;
}
void swapViaPtr(char *a, char*b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
void inverse(char *str, int len)
{
    if(len > 1){
        swapViaPtr(str, str+len-1);
        inverse(str+1, len-2);
    }
}

bool binaryRecSearch(int *a, int size, int item)
{//int a[5] = {0, 1 , 4, 5, 6};

   //int mid;
    if(item == a[size/2])
        return true;
    if (size/2==0)
        return false;
    if(item < a[size/2])
        return binaryRecSearch(a,  size/2, item);
    else
        return binaryRecSearch(a+size/2, size - size/2, item);

}

int binarySearch(int *a, int low, int high, int item)
{
    int mid = (low+high)/2;
    if(low <= high)
    {

        if(a[mid] == item)
            return mid;
        else if(a[mid] <= item)
            return binarySearch(a, mid+1, high, item);
        else
            return binarySearch(a, low, mid-1, item);

    }

    else
        return -mid;  // the negative of the position to be inserted
}

int binaryIterSearch(int* a, int size,int item)
{
    int h = size-1, low = 0, mid;

    while(h>=low)
    {
        mid = (h+low)/2;
        if(a[mid] == item)
            return mid;
        else if(a[mid] < item)
            low = mid+1;
        else
            h= mid-1;

    }

    return -mid;

}




bool scale(const int *weights, const int size, const int item,
        const int i, const int sum, int *used)
{
    if ( sum == item )
        return true;
    if ( i == size )
        return false;
    bool result = false;
        result = scale(weights, size, item, i + 1, sum + weights[i], used);
        used[i] = 1;
    if ( result == false ){
        result = scale(weights, size, item, i + 1, sum - weights[i], used);
        used[i] = -1;
    }
    if ( result == false ) {
        result = scale(weights, size, item, i + 1, sum, used);
        used[i] = 0;
    }
    return result;
}
// This is the function to be called
void scale(const int *weights, const int size, const int item)
{
    int *used = new int[size];
    for (int i = 0; i < size; i++)
        used[i] = 0;
    if (scale(weights,size,item,0,0,used))
    {
        cout << "Put the purchased item on the left bucket" << endl;
        // Check the metal weights that are to be put on the left scale
        // The first flag is used for formatting purposes. It is also used
        // whether or not there is at least one item to be put on
        // the left scale
        bool first = true;
        for (int j = 0; j < size; j++){
            if (used[j] == -1){
                if (first){
                    cout << "Put " << weights[j] << "kg";
                    first = false;
                }
                else
                    cout << ", " << weights[j] << "kg";
            }
        }
        if (first == false)
        cout << " on the left bucket" << endl;
        // Now check the metal weights that are to be put on the right scale
        first = true;
        for (int j = 0; j < size; j++){
            if (used[j] == 1){
                if (first){
                    cout << "Put " << weights[j] << "kg";
                    first = false;
                }
                else
                    cout << ", " << weights[j] << "kg";
            }
        }
        if (first == false)
        cout << " on the right bucket" << endl;
    }
    else
        cout << "It is not possible to weigh the purchased item" << endl;
    delete []used;
}
int main()
{
//    int W[] = {1, 4, 8, 9};
//    scale(W,4,10);
//    scale(W,4,16);
//    scale(W,4,19);
//    return 0;

    ofstream sol1, sol2, sol3;
    sol1.open("sol1.txt");
    sol2.open("sol2.txt");
    sol3.open("sol3.txt");

    char a[] = "Hello";
    int taken[4]={};
    int arr[4]={1, 2, 3, 4};
    findSubsets(arr, 4, 2, taken , 0);

//    char a[6] = {0, 1 , 4, 5, 6, '\0'};
//    writeBackward(a) ;
//    cout <<"\n" << isPalindrome("aba", 3) << "\n";
//
//     inverse(a, 5);
//    cout << a;
//    cout << binaryRecSearch(a, 5, 4) << "\n"; //search for 5
//    cout << binaryIterSearch(a,size, 6) << "\n";
//    cout << binarySearch(a, 0, 4, 6) << "\n";
//
//    for(int n = 10; n < 500000; n+=100){
//        cout << "RANDOM ARRAY " <<  ++m << ":\tSIZE: " << n << "\n";
//        int inArr[n];
//        srand((unsigned)time(0));
//        for(int i = 0; i < n; i++)
//        {
//            inArr[i] = (rand()%500)+1;
//        }
//        int item = ((rand()%500) + 1);
//
//    double duration;
//
//        clock_t startTime = clock();
//         cout << binaryRecSearch(inArr, n, item) << "\n";
//        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
//        sol1 << duration << ", ";
//
//        startTime = clock();
//        cout << binaryIterSearch(inArr,n, item) << "\n";
//        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
//        sol2 << duration << ", ";
//
//        startTime = clock();
//        cout << binarySearch(inArr, 0, n-1, item) << "\n";
//        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
//        sol3 << duration << ", ";
//
//
//    }
//
//    sol1.close();
//    sol2.close();
//    sol3.close();

}
