#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

double quick_zbir=0;
double insertion_zbir=0;
double selection_zbir=0;
double bubble_zbir=0;

int partition(long int input[],long int p,long int r)
{int pivot = input[(r+p)/2];
while ( p < r )
{while ( input[p] < pivot )
p++;
while ( input[r] > pivot )
r--;
if ( input[p] == input[r] )
p++;
else if ( p < r )
{int tmp = input[p];
input[p] = input[r];
input[r] = tmp;}}
return r;
}

void quicksort(long int input[], long int p, long int r)
{
if ( p < r )
{int j = partition(input, p, r);
quicksort(input, p, j-1);
quicksort(input, j+1, r);}
}

void random(long int insertion[],long int selection[],long int bubble[],long int quick[],int j){
int broj;
for(int i=0;i<j;i++){
broj=rand()%j+1;
insertion[i]=broj;
selection[i]=broj;
bubble[i]=broj;
quick[i]=broj;}
}

void insertionsort(long int a[],long int n){
long int j,t;
for(int i=1; i<n; i++){
j=i;
t=a[j];
while (j>0 && a[j-1] > t){
a[j]=a[j-1];
j--;}
a[j]=t;}}

void selectionsort(long int a[],long int n){
long int i,min,j, temp;
for(i=0;i<n-1;i++){
min=i;
for(j=i+1;j<n;j++){
if(a[min]>a[j])
min=j;}
if (min!=i){
temp=a[i];
a[i]=a[min];
a[min]=temp;}
}}

void bubblesort(long int a[],long int n){
long int i,j, smeni, temp;
for(i=n-1;i>=0;i--){
smeni=0;
for(j=0;j<i;j++){
if(a[j+1]<a[j]){
temp=a[j+1];
a[j+1]=a[j];
a[j]=temp;
smeni++;}}
if (smeni==0){
break;}}}

int main(int argc, char *argv[])
{int elementi[]={50,100,250,500,750,1000};
int j=0;
clock_t startTime;
while(j<6){
long int insertion[elementi[j]];
long int selection[elementi[j]];
long int bubble[elementi[j]];
long int quick[elementi[j]];
for(int povtoruvanja=0;povtoruvanja<5000;povtoruvanja++)
{
random(insertion,selection,bubble,quick,elementi[j]);
startTime = clock();
quicksort(quick,0, elementi[j]-1);
quick_zbir=quick_zbir+((double( clock() - startTime ) / (double)CLOCKS_PER_SEC)*1000);
startTime = clock();
insertionsort(insertion, elementi[j]);
insertion_zbir=insertion_zbir+((double( clock() - startTime ) / (double)CLOCKS_PER_SEC)*1000);
startTime = clock();
selectionsort(selection, elementi[j]);
selection_zbir=selection_zbir+((double( clock() - startTime ) / (double)CLOCKS_PER_SEC)*1000);
startTime = clock();
bubblesort(bubble, elementi[j]);
bubble_zbir=bubble_zbir+((double( clock() - startTime ) / (double)CLOCKS_PER_SEC)*1000);}
cout<<"Quicksort za "<<elementi[j]<<" elementi: "<<quick_zbir/5000<<" ms"<<endl;
cout<<"Bubblesort za "<<elementi[j]<<" elementi: "<<bubble_zbir/5000<<" ms"<<endl;
cout<<"Insertionsort za "<<elementi[j]<<" elementi: "<<insertion_zbir/5000<<" ms"<<endl;
cout<<"Selectionsort za "<<elementi[j]<<" elementi: "<<selection_zbir/5000<<" ms"<<endl;
cout<<endl;
quick_zbir=0; selection_zbir=0; insertion_zbir=0; bubble_zbir=0;
j++;}
system("PAUSE");
return EXIT_SUCCESS;

/*Оваа програма е имплементација на алгоритмите за сортирање на податочни структури. Точно, програмата ја споредува ефикасноста на четири различни алгоритми за сортирање на еден низ со различни големини. Алгоритмите кои се споредуваат во оваа програма се:

Quicksort
Bubblesort
Insertionsort
Selectionsort

Програмата го генерира низот на произволен начин со помош на функцијата "random". Потоа го сортира низот со секој од алгоритмите и го мери времето потребно за да се заврши сортирањето со помош на функцијата "clock".

Оваа програма е корисна за споредување на ефикасноста на алгоритмите за сортирање и за одредување на најбрзиот алгоритам за даден проблем. */
}

