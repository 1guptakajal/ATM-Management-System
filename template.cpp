#include<iostream>
using namespace std;
template<class x>
class arraylist{
    private:
    struct controlBlock{
        int capacity;
        x *arr;
    };
    controlBlock *s;
    public:
    arraylist(int capacity){
        s=new controlBlock;
        s->capacity=capacity;
        s->arr=new x[s->capacity];
    }
    void addElement(int index,x data){
        if(index>=0 && index<=s->capacity-1)
        s->arr[index]=data;
        else
        cout<<"\n Array index is not valid\n";
    }
  /* void showElement(int index,x &data){
        if(index>=0 && index<=s->capacity-1){
        data=s->arr[index];
        //cout<<data<<endl;
        }
        else
        cout<<"\n Array index is not valid\n";
    }*/
    void viewList(){
        int i;
        for(i=0;i<s->capacity;i++){
            cout<<" "<<s->arr[i];
        }
    }
};
int main(){
    int data;
    arraylist<float> list1(4);
    list1.addElement(0,32.2);
    list1.addElement(1,39.3);
    list1.addElement(2,5.55);
   // list1.showElement(0,xdata);
  //  cout<<"value in the array is"<<data<<endl;
    list1.viewList();
}
