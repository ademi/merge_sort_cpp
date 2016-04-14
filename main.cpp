#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdexcept>
using namespace std;

template <class T>
void array_sort_merge(T sort[8],T temp[8], int begin,int end){
    static int i=0;i++;
    if(end-begin <2){
        return;
    }
    else{
        int mid =((end-begin)/2)+begin;
        array_sort_merge(sort,temp,begin,mid);
        array_sort_merge(sort,temp,mid,end);
        
        int l=begin,r=mid;
        for(int k=begin;k<end;k++){
            if(l<mid &&(r>=end || sort[l]<sort[r]))
                temp[k]=sort[l++];
            else 
                temp[k] = sort[r++];
        }
    for(int j =begin;j<end;j++)sort[j]=temp[j];
    }
}
template <class V>
void vector_sort_merge(V & sort,V& temp){
    
}
int main(){
    int integers[]  =   {3, 2, 1, 4, 6, 5, 9,23,15,25};
    int temp[]    =   {0, 2, 0, 0, 0, 0, 0,0 ,0 ,0 };
    array_sort_merge(integers,temp,0,10);
    for(int j=0;j<10;j++)cout<<integers[j]<<endl;cout<<"************"<<endl;
    return 0;
}