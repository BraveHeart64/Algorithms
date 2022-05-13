#include<iostream>
using namespace std;

class Node{

    Node* node;

};

class Search{

    private:




    public:
        template<class B> void BubbleSort(B b[], int arrarysize);
        template<class B> void SelectionSort(B b[], int arrarysize);
        template<class B> void InsertionSort(B b[], int arrarysize);
        template<class B> void QuickSort(B b[],int low, int high);
        template<class B> void MySwap(int one,int two,B b[]);
        template<class B> int Partition(int low,int high,B b[]);
        template<class B> void MergeSort(B b[], int low , int high);
        template<class B> void MS_Sort(B b[],int low, int mid, int high);




         Search();
        ~Search();

};

Search::Search(){

}

Search::~Search(){



};


template<class B>void Search::BubbleSort(B b[], int arrarysize){

    B temp;
    for(int i =0; i< arrarysize; ++i){
        for(int c = 0; c < arrarysize; ++c){
            if(b[c] > b[i]){
                temp = b[c];
                b[c] = b[i];
                b[i] = temp;
            }
        }
    }


}




template<class B> void Search::SelectionSort(B b[], int arrarysize){
           int  smallest,c,i;

            for(i=0; i < arrarysize; ++i){
                smallest = i;

                for(c = i+1; c < arrarysize; ++c){
                    if(b[i] > b[c]){
                        smallest = c;
                    }

                }
                // swap preformed
                B temp = b[i];
                b[i] = b[smallest];
                b[smallest] = temp;

            }



}

template<class B> void Search::InsertionSort(B b[],int arr){
    int pivot = 0;

    int i,c;
    B smaller;


    for( i = 0; i < arr; ++i){
        smaller = b[i];
        c = i-1;

        while(c >= 0 && b[c] > smaller  ){
           b[c+1] = b[c];
           c=c-1;


        }
        b[c+1] = smaller;



    }

}

template<class B> void Search::QuickSort(B b[],int low, int high){
    if(high-low <=0){
     return;
    }
    else{
        int pivot = b[high];
        int partpt = Partition(low,high,b);
        QuickSort(b,low,partpt -1);
        QuickSort(b,partpt+1,high);

    }

}

template<class B>int Search::Partition(int low, int high, B b[]){
    int leftpt = low - 1;
    int rightpt = high;
    int pivot = high -1;

        while(b[++leftpt] < pivot ){

        }
        while(rightpt > 0 && b[--rightpt] > pivot){

        }
        if(leftpt >= rightpt){

        }else{
            MySwap(leftpt, rightpt,b);
        }


    MySwap(leftpt, high,b);
    return leftpt;

 }

 template<class B> void Search::MySwap(int one,int two, B b[]){
    int temp =b[one];
    b[one] = b[two];
    b[two] = temp;

 }

template<class B> void Search::MergeSort(B b[],int low , int high){

    int mid;

    if(low < high){
        mid = low +(high - low)/2;
        MergeSort(b,low,mid);
        MergeSort(b,mid + 1, high);
        MS_Sort(b, low,mid,high);
    }


}


template<class B> void Search::MS_Sort(B b[],int low, int mid, int high){

    // this is declares size of the 2 sub arrays
    int bl = mid - low + 1;
    int bh = high - mid;

    // this creats two temps arrays for the sorts
    B  Blow[bl];
    B  Rhigh[bh];

    int i,a =0;
    for( i = 0 ; i < bl; ++i){
        Blow[i] = b[low + i];
    }

    for( a = 0; a < bh; a++){
        Rhigh[a] = b[mid + 1 + a];
    }
    // rests the first and second temp array
    i = 0; a = 0;
    // indexing and merging of the sub arrays
    int counter = low;
    while(i < bl && a < bh){
        if(Blow[i] <= Rhigh[a]){
            b[counter] = Blow[i];
            i++;
        }
        else{
            b[counter] = Rhigh[a];
            a++;
        }
        counter++;
    }

    while( i < bl){
        b[counter] = Blow[i];
        i++;
        counter++;

    }

    while(a < bh){
        b[counter] = Rhigh[a];
        a++;
        counter++;

    }



}
// Driver
int main(int argc, char* argv[]){
    Search bub;
    int testarray[] = {9,8,7,5,4,3,2}; // 2,3,4,5,7,8,9
    string name[] = {"Sonic","Robotnic","Tails","Sally"};
    int arrsize = sizeof(testarray)/sizeof(testarray[0]);
    int nz = sizeof(name)/sizeof(name[0]);

    cout<<"Before the sort: "<<endl;
    for(int i =0; i<arrsize; ++i){
        cout<<testarray[i]<<endl;
    }
     cout<<"After The Sort:";
     cout<<endl<<endl;
   // bub.BubbleSort(testarray,arrsize);
    //bub.SelectionSort(testarray,arrsize);
  // bub.BubbleSort(name,nz);
   //bub.InsertionSort(testarray,arrsize);

    //bub.QuickSort(testarray,0,arrsize-1);
    bub.MergeSort(testarray,0, arrsize-1);
    cout<<endl<<endl;
    for(int i =0; i<arrsize; ++i){
        cout<<testarray[i]<<endl;
    }
    cout<<endl;
    for(int i =0; i<nz; ++i){
      //  cout<<name[i]<<endl;
    }

    return 0;
}
