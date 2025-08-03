// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// void bucket_sort(float arr[],int size){
//     //creating the buckets from 0 to size-1.
//     vector<vector<float>> vec(size,vector<float> ());

//     //inserting elements in the buckets.
//     for(int i=0;i<size;i++){
//         int index=arr[i]*size;
//         vec[index].push_back(arr[i]);
//     }

//     //individually sorting the buckets.
//     for(int i=0;i<size;i++){
//         if(!vec[i].empty()){
//         sort(vec[i].begin(),vec[i].end());
//         }
//     }

//     //combining our elements.
//     int k=0;
//     for(int i=0;i<size;i++){
//         for(int j=0;j<vec[i].size();j++){
//             arr[k++]=vec[i][j];
//         }
//     }
// }
// int main(){
//     float arr[]={0.12,0.98,0.43,0.87,0.21,0.32,0.65};
//     int size=sizeof(arr)/sizeof(arr[0]);
//     bucket_sort(arr,size);
//     for(int i=0;i<size;i++){
//       cout<<arr[i]<<" ";
//     }
//     return 0;
// }




// //when there is much difference in elements.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void bucket_sort(float arr[],int size){
    //creating the buckets from 0 to size-1.
    vector<vector<float>> vec(size,vector<float> ());


    //finding max and min ele and finding range
    float min_ele=arr[0];
    float max_ele=arr[0];
    for(int i=1;i<size;i++){
        max_ele=max(arr[i],max_ele);
        min_ele=min(arr[i],min_ele);
    }
    float range=(max_ele-min_ele)/size;


    //inserting elements in the buckets.
    for(int i=0;i<size;i++){
        //finding the integer index
        int index=(arr[i]-min_ele)/range;
        //finding the difference for boundary ele
        float diff=(arr[i]-min_ele)/range - index;
        if(diff==0 && arr[i]!=min_ele){
            vec[index-1].push_back(arr[i]);
        }
        else{
            vec[index].push_back(arr[i]);
        }
    }

    //individually sorting the buckets.
    for(int i=0;i<size;i++){
        if(!vec[i].empty()){
        sort(vec[i].begin(),vec[i].end());
        }
    }

    //combining our elements.
    int k=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<vec[i].size();j++){
            arr[k++]=vec[i][j];
        }
    }
}
int main(){
    float arr[]={0.12,0.98,7.43,0.87,6.21,8.32,10.65}; 
    int size=sizeof(arr)/sizeof(arr[0]);
    bucket_sort(arr,size);
    for(int i=0;i<size;i++){
      cout<<arr[i]<<" ";
    }
    return 0;
}


//   //if negative float numbers are there
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// void bucket_sort(float arr[],int size){
//     //finding min and max ele
//     float min_ele=arr[0];
//     float max_ele=arr[0];
//     for(int i=1;i<size;i++){
//         min_ele=min(arr[i],min_ele);
//         max_ele=max(arr[i],max_ele);
//     }
//     for(int i=0;i<size;i++){
//         arr[i]-=min_ele;
        
//     }

//     float min_ele_x=min_ele;

//     max_ele-=min_ele_x;
//     min_ele-=min_ele_x;

//     float range=(max_ele)/size;
    
//     //making buckets
//     vector<vector<float>> buckets(size);
    
//     //inserting ele in buckets.
//     for(int i=0;i<size;i++){
//         int index=(arr[i])/range;
//         if(arr[i]==max_ele){   //hum max ele ka case sidha hi handle kr lenge.....
//             buckets[index-1].push_back(arr[i]); //for max ele
//         }
//         else{
//             buckets[index].push_back(arr[i]);
//         }
//     }
    
//     //individually sorting the buckets
//     for(int i=0;i<size;i++){
//         if(buckets[i].size()>1){
//             sort(buckets[i].begin(),buckets[i].end());
//         }
//     }
    
//     //putting ele in original array
//     int k=0;
//     for(int i=0;i<size;i++){
//         for(auto ele:buckets[i]){
//              arr[k++]=(ele+min_ele_x);
//         }
//     }

// }
// int main(){
//     float arr[]={-0.12,-0.98,7.43,0.87,6.21,8.32,10.65,10.66,11.90,0.45,0.67,8.89}; 
//     int size=sizeof(arr)/sizeof(arr[0]);
//     bucket_sort(arr,size);
//     for(int i=0;i<size;i++){
//       cout<<arr[i]<<" ";
//     }
//     return 0;
// }