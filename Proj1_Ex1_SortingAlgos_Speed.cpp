#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
void swap(long &x, long &y)
{
    long temp = x;
    x = y;
    y = temp;
}

void bubbleSort(long X[], long n)
{
    for (long i = n - 1; i >= 0; i--)
        for (long j = 1; j <= i; j++)
            if (X[j - 1] > X[j])
                swap(X[j - 1], X[j]);
}

void merge(long X[], long head, long mid, long tail)
{
    long n1 = mid - head + 1;
    long n2 = tail - mid;

    long L[n1], R[n2];

    for (long i = 0; i < n1; i++)
        L[i] = X[head + i];
    for (long j = 0; j < n2; j++)
        R[j] = X[mid + 1 + j];

    long i = 0;
    long j = 0;
    long k = head;

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

void mergeSort(long X[], long head, long tail)
{
    if (head < tail)
    {
        long mid = (head + tail) / 2;
        mergeSort(X, head, mid);
        mergeSort(X, mid + 1, tail);
        merge(X, head, mid, tail);
    }
    else
        return;
}

long partition(long X[], long left, long right)
{
    long i = left, pivot = X[left], j = right;
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

void quickSort(long X[], long left, long right)
{
    //if (left - right < 9)
    //    insertionSort(X,left,right);
    //else
    if (left < right)
    {
        long p = partition(X, left, right);
        quickSort(X, left, p - 1);
        quickSort(X, p + 1, right);
    }
}

void maxHeapify(long X[], long i, long n)
{
    long largest;
    long left = 2 * i + 1;  //leftChild(i)
    long right = 2 * i + 2; //rightChild(i)
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

void buildMaxHeap(long X[], long n)
{
    for (long i = n / 2; i >= 0; i--)
        maxHeapify(X, i, n - 1);
}

void heapSort(long X[], long n)
{
    buildMaxHeap(X, n);
    for (long i = n - 1; i >= 0; i--)
    {
        swap(X[0], X[i]);
        maxHeapify(X, 0, i - 1);
    }
}

void fourSortAlgos(long A[], long long n)
{
    {
        bubbleSort(A, n);
    }
    {
        mergeSort(A, 0, n - 1);
    }
    {
        quickSort(A, 0, n - 1);
    }
    {
        heapSort(A, n);
    }
}

void sortRandomly()
{
    long n, x, y, m;
    cout << "Enter array size x^y: ";
    cin >> x >> y;
    n = pow(x, y);
    cout << "Enter range of value (from 0 to x): ";
    cin >> m;
    long A[n];
    cout << "Initial data: ";
    for (long i = 0; i < n; i++)
    {
        A[i] = rand() % m;
    }
    cout << endl;
    fourSortAlgos(A, n);
}

int main()
{
    sortRandomly();
    cout << n;
    return 0;
}