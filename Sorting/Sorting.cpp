#include<bits/stdc++.h>
using namespace std;
void Bubblesort(vector<int>&a){
    int n = a.size();
    for(int i = 0 ; i < n - 1 ; i++){
        bool swapy = false;
        for(int j = 0 ; j < n - i -1 ; j++){
            if(a[j+1]<a[j]){
                swap(a[j+1],a[j]);
                swapy=true;
            }
        }
        if(swapy==false)return;
    }
}
void SelectionSort(vector<int> &a){
    for(int i = 0 ; i < a.size() -1 ; i++){
        int mini = i;
        for(int j = i + 1; j < a.size() ; j++){
            if(a[j]<a[mini]){
                mini=j;
            }
        }
        swap(a[i],a[mini]);
    }
}
void insertionsort(vector<int>&a){
    int n = a.size();
    for(int i = 1 ; i < n ; i++){
        int curr = a[i];
        int prev = i-1;
        while(a[prev]>curr){
            a[prev+1]=a[prev];
            prev--;
        }
        a[prev+1]=curr;
    }
}
void merge(vector<int>&a , int low , int mid , int high){
    int lp = low , rp = mid + 1;
    vector<int>temp;
    while(lp<=mid&&rp<=high){
        if(a[lp]<=a[rp]){
            temp.push_back(a[lp++]);
        }else{
            temp.push_back(a[rp++]);
        }
    }
    while(lp<=mid){
        temp.push_back(a[lp++]);
    }
    while(rp<=high){
        temp.push_back(a[rp++]);
    }
    for(int i = low ; i<=high ;i++){
        a[i]=temp[i-low];
    }
}
void mergesort(vector<int> &a,int low , int high){
    if(low>=high)return;
    int mid = low+(high-low)/2;
    mergesort(a,low,mid);
    mergesort(a,mid + 1,high);
    merge(a,low,mid,high);
}
int partition(vector<int> &a , int low , int high){
    int pivot=a[low];
    int i = low , j = high;
    while(i<j){
        while(a[i] <= pivot && i < high){
            i++;
        }
        while(a[j]>pivot && j > low){
            j--;
        }
        if(i<j)swap(a[i],a[j]);
    }
    swap(a[low],a[j]);
    return j ;  
}
void quicksort(vector<int> &a,int low , int high){
    if(high<=low)return;
    int perfect_place = partition(a,low,high);
    quicksort(a,low,perfect_place-1);
    quicksort(a,perfect_place+1,high);
}
int main(){
    vector<int> original = {8, 7, 6, 5, 4, 3, 2};
    vector<int> a = original;
    SelectionSort(a);
    cout << "Selection Sort: ";
    for (int i : a) cout << i << " ";
    cout << endl;

    a = original;
    Bubblesort(a);
    cout << "Bubble Sort: ";
    for (int i : a) cout << i << " ";
    cout << endl;

    a = original;
    insertionsort(a);
    cout << "Insertion Sort: ";
    for (int i : a) cout << i << " ";
    cout << endl;

    a = original;
    mergesort(a, 0, a.size() - 1);
    cout << "Merge Sort: ";
    for (int i : a) cout << i << " ";
    cout << endl;

    a = original;
    quicksort(a, 0, a.size() - 1);
    cout << "Quick Sort: ";
    for (int i : a) cout << i << " ";
    cout << endl;

    return 0;
}