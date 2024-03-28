#include <iostream>
using namespace std;

int arr[20];
int cmp_count = 0; // number of comparasion
int mov_count = 0; // number of data movements
int n;

void input (){
    while (true)
    {
        cout << "masukan panjang element array: ";
        cin >> n;
        if (n <=20)
            break;
        else
            cout << "\nMaksimum panjang array adalah 20" << endl;

    }

    cout << "\n------------------" << endl;
    cout << "\nMasukan elemen array" << endl;
    cout << "\n------------------" << endl;

    for (int i = 0; i < n; i++){
        cout << "<" << (i + 1) << ">";
        cin >> arr[i];

    }
}

void swap (int x, int y){
    int temp = arr [x] ;
    arr [x] = arr [y] ;
    arr [y] = temp ;
    mov_count++;
}

void q_short (int low, int high)
{
    int trmp;
    int pivot, i, j;
    if  (low > high) { // step 1
    return;

    }

    pivot = arr [low]; // step 2
    i = low + 1; // step 3
    j = high; // step 4

    while (i = j) // step 10 
    {
        while ((arr[i] <= pivot) && (i <= high)) // step 5
        {
            i++; // step 6
            cmp_count++;
        }
        cmp_count++;
        while ((arr[j] > pivot ) &&  (j >= low)) // step 7
        {
           j--; // step 8
           cmp_count++;
        }
        cmp_count++;
        if(i < j) // step 9
        {
            swap (i , j); 
        }
    }
    
    if (low < j) // step 11
    {
        swap(low , j); 
    }

    q_short (low, j - 1); // step 12
    q_short (j+1, high); // step 13
}

void display () {
    cout << "\n------------------" << endl;
    cout << "sorted array" << endl;
    cout << "--------------------" << endl;

    for (int i = 0; i < n; i++){
        cout  << arr[i] << " ";
    }
    cout << "\n nNumber  of comparisons: " << cmp_count << endl;
    cout << "\n number of data movements: " << mov_count << endl;
    
}