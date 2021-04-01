#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void bubbleSort(int X[], int n)
{
    for (int i = n - 1; i >= 0; i--)
        for (int j = 1; j <= i; j++)
            if (X[j - 1] > X[j])
                swap(X[j - 1], X[j]);
}

void merge(int X[], int head, int mid, int tail)
{
    int n1 = mid - head + 1;
    int n2 = tail - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = X[head + i];
    for (int j = 0; j < n2; j++)
        R[j] = X[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = head;

    for (; i < n1 && j < n2;)
    {
        if (L[i] <= R[j])
        {
            X[k] = L[i];
            i++;
        }
        else
        {
            X[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        X[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        X[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int X[], int head, int tail)
{
    if (head < tail)
    {
        int mid = (head + tail) / 2;
        mergeSort(X, head, mid);
        mergeSort(X, mid + 1, tail);
        merge(X, head, mid, tail);
    }
    else
        return;
}

int partition(int X[], int left, int right)
{
    int i = left, pivot = X[left], j = right;
    while (i < j)
    {
        while ((i <= right) && (X[i] <= pivot))
            i++;
        while ((j >= left) && (X[j] > pivot))
            j--;
        if (i < j)
            swap(X[i], X[j]);
    }
    swap(X[left], X[j]);
    return j;
}

void quickSort(int X[], int left, int right)
{
    //if (left - right < 9)
    //    insertionSort(X,left,right);
    //else
    if (left < right)
    {
        int p = partition(X, left, right);
        quickSort(X, left, p - 1);
        quickSort(X, p + 1, right);
    }
}

void maxHeapify(int X[], int i, int n)
{
    int largest;
    int left = 2 * i + 1;  //leftChild(i)
    int right = 2 * i + 2; //rightChild(i)
    if (left <= n && X[left] > X[i])
        largest = left;
    else
        largest = i;
    if (right <= n && X[right] > X[largest])
        largest = right;
    if (largest != i)
    {
        swap(X[i], X[largest]);
        maxHeapify(X, largest, n);
    }
}

void buildMaxHeap(int X[], int n)
{
    for (int i = n / 2; i >= 0; i--)
        maxHeapify(X, i, n - 1);
}

void heapSort(int X[], int n)
{
    buildMaxHeap(X, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(X[0], X[i]);
        maxHeapify(X, 0, i - 1);
    }
}

vector<int> convertStrtoArr(string str)
{
    int str_length = str.length();
    vector<int> X;
    int j = 0, i, sum = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            j++;
        else
            X.push_back(str[i] - 48);
    }
    return X;
}

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

void fourSortAlgos(int A[], int n){
    {
        bubbleSort(A, n);
        cout << "Bubble Sort: ";
        printArray(A, n);
    }
    {
        mergeSort(A, 0, n - 1);
        cout << "Merge Sort: ";
        printArray(A, n);
    }
    {
        quickSort(A, 0, n - 1);
        cout << "Quick Sort: ";
        printArray(A, n);
    }
    {
        heapSort(A, n);
        cout << "Heap Sort: ";
        printArray(A, n);
    }
}

void sortFile()
{
    string myArray;
    ifstream myReadFile("Proj1_Ex1_SortingAlgos_DataFile.txt");
    getline(myReadFile, myArray);
    cout << "Initial data: " << myArray;
    vector<int> X = convertStrtoArr(myArray);
    int n = X.size();
    int A[n];
    for (int i = 0; i < X.size(); i ++)
        A[i] = X[i];
    cout << endl;
    fourSortAlgos(A,n);
    ofstream myWriteFile("Proj1_Ex1_SortingAlgos_DataFile.txt");
    for (int i = 0; i< n; i ++)
        myWriteFile << A[i] << " ";
}

void sortKeyboard()
{
    int n, x;
    cout << "Type in array size: ";
    cin >> n;
    cout << "Type in the array: ";
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        A[i] = x;
    }
    fourSortAlgos(A,n);
}

void sortRandomly()
{
    int n, m;
    cout << "Enter array size: ";
    cin >> n;
    cout << "Enter range of value (from 0 to x): ";
    cin >> m;
    int A[n];
    cout << "Initial data: ";
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % m;
        cout << A[i] << " ";
    }
    cout << endl;
    fourSortAlgos(A,n);
}

int main()
{
    cout << "Project1_Ex1: Sorting Algorithms" << endl;
    cout << "       1. Read from file" << endl;
    cout << "       2. Read from keyboard" << endl;
    cout << "       3. Generate randomly" << endl;
    char a;
    while (1)
    {
        cout << "Enter something... ";
        cin >> a;
        if (a == '1')
            sortFile();
        else if (a == '2')
            sortKeyboard();
        else if (a == '3')
            sortRandomly();
        else{
            cout << "Are you sure you want to quit? (y/n) ";
            cin >> a;
            if (a == 'n' || a == 'N')
                continue;
            else break;
        }
    }
    return 0;
}