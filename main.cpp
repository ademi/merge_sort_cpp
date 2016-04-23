#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int get_random(int min , int max){
    return min +rand()%(int)(min-max);
}
template <class T>
void sort_merge(T sort[],T temp[], int begin,int end){
    if(end-begin <2)return;                  // in cas of one element cosidered it ordered and return;

    else{
        int mid =((end-begin)/2)+begin;     // calculate the index of the middle element
        sort_merge(sort,temp,begin,mid);    // sorting the right side 
        sort_merge(sort,temp,mid,end);      // sorting the left  side
        
        int l=begin,r=mid;                  // initializing left and right counters
        for(int k=begin;k<end;k++){         // main for loop
            if(l<mid &&(r>=end || sort[l]<sort[r]))
                temp[k]=sort[l++];
            else 
                temp[k] = sort[r++];
        }
    for(int j =begin;j<end;j++)sort[j]=temp[j]; // copy the the sorted elements from temp to sort;
    }
}
template <class T>
void quicksort(T sort[], int start,int end){
    if((end-start)<2)return;                // in cas of one element cosidered it ordered and return;
    
    else{
        int pivot  = get_random(start,end); // choose pivot index randomly
        int i       =start+1;               //initiate the counter between the smaller and bigger elements
        swap(sort[start],sort[pivot]);      //move the chosen pivot to the front
        for(int j =start+1; j<end;j++)      //maint for loop
            if(sort[j]<sort[start]){        
                if(i !=j)swap(sort[j],sort[i]); 
                i++;
            }
        swap(sort[start],sort[i-1]);       // moving the pivot to its rightful place
        
        quicksort(sort, start, i-1);       // partitioning the left side
        quicksort(sort, i, end);            //partitioning the right side

    }
}

template <class T>void swap(T &i,T &j){
    T temp = i;
    i = j;
    j = temp;
}

int main(){
    int random_length = get_random(1,1000);
    int integers[random_length];
    for(int i=0;i<random_length;i++)integers[i]=get_random(-1000,1000);
    
    int sort_merge_array [random_length];
    int quicksort_array [random_length];
    
    for(int j=0;j<sizeof(integers)/sizeof(integers[0]);j++){
        sort_merge_array[j]=integers[j];
        quicksort_array[j] =integers[j];
    }
    int temp[sizeof(integers)/sizeof(integers[0])] ;
    
    int start_sort_merge    = clock();
    sort_merge(sort_merge_array,temp,0,random_length);
    int end_sort_merge  =clock();
    
    int start_quicksort =clock();
    quicksort(quicksort_array,0,random_length);
    int end_quicksort   =clock();
    
    cout<<"***********************"<<endl<<"length: "<<random_length<<endl;
    
    cout<<"quicksort took"<<(end_quicksort - start_quicksort)<<" clocks"<<endl;
    cout<<"merge sort took"<<((float)end_sort_merge-start_sort_merge)<<" clocks"<<endl;
    cout<<"random \t sort_merge \t quicksort"<<endl;
    for(int j=0;j<(sizeof(integers)/sizeof(integers[0]));j++){
        cout<<integers[j]<<"\t"<<sort_merge_array[j]<<"\t"<<quicksort_array[j];
        if(sort_merge_array[j]!=quicksort_array[j])cout <<"##### ERROR";
        cout<<endl;
    }
    return 0;
}