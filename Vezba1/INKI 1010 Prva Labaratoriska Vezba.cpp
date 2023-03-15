#include <iostream>
using namespace std;


void merge(char array[], int left, int middle, int right)
{
  
    int fh = middle - left + 1;
    int sh = right - middle;
    
    char t1[fh], t2[sh];
  
    for (int m = 0; m < fh; m++)
        t1[m] = array[left + m];
    for (int n = 0; n < sh; n++)
        t2[n] = array[middle + 1 + n];

    int a = 0;
    int b = 0;
    int c = left;
    while (a < fh && b < sh) {
        if (t1[a] <= t2[b]) {
            array[c] = t1[a];
            a++;
        }
        else {
            array[c] = t2[b];
            b++;
        }
        c++;
    }
    while (a < fh) {
        array[c] = t1[a];
        a++;
        c++;
    }
    while (b < sh) {
        array[c] = t2[b];
        b++;
        c++;
    }
}


void mergeSort(char array[], int left, int right) {
    if (left >= right) {
        return;
    }
    int middle = left + (right - left) / 2;
    mergeSort(array, left, middle);
    mergeSort(array, middle + 1, right);
    merge(array, left, middle, right);
}


void printArray(char Array[], int size)
{
    for (int d = 0; d < size; d++)
        cout << Array[d] << " ";
}


int main()
{
    char array[] = { 'M','e','n','d','e',' ','T','a','l','e','v','s','k','i',' ','I','N','K','I', '1', '0', '1', '0' };
    int array_size = sizeof(array) / sizeof(array[0]);
    cout << "The elements of the input array before sorting are: \n";
    printArray(array, array_size);
    mergeSort(array, 0, array_size - 1);
    cout << "\nThe elements of the input array after sorting are: \n";
    printArray(array, array_size);
    return 0;
    /*Оваа програма го имплементира алгоритмот на сортирање со спојување (merge sort) врз низа на карактери. Програмата прво го испишува низата пред да ја сортира, потоа ја сортира низата со користење на функцијата mergeSort,
    која го повикува самата себе рекурзивно за да ја разделува низата на половини се додека не остане само по еден елемент. Потоа повторно ги спојува двата дела во помали групи, кои се сортирани, се додека не се спојат во целосна сортирана низа.*/
    
}
