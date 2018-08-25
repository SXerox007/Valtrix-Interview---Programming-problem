//Assignment-4 Stack
//Linked list
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class MemoryManage{
private:
    int *memoryBufferReader;
    int totalMemoryBuffer;
    int memoryPointer;
public:
    void setMemoryBufferReader(int *memoryBufferReader,int totalMemoryBuffer);
    void allocate(int value);
    void deAllocate(int value);
    void list();
};

void MemoryManage::setMemoryBufferReader(int *memoryBufferReader,int totalMemoryBuffer){
    this->memoryBufferReader = memoryBufferReader;
    this->totalMemoryBuffer = totalMemoryBuffer;
    memoryPointer=0;
}

void MemoryManage::allocate(int value){
    int temp=0;
    if(totalMemoryBuffer<value){
        cout<<"Error:- memory offset not available which satisfies the size and alignment requirements\n";
        return;
    }else{
        if((totalMemoryBuffer-memoryPointer)>value){
       for(int i=memoryPointer;i<(value+memoryPointer);i++){
        memoryBufferReader[i]=temp;
        temp+=value;
        }
        memoryPointer = value+memoryPointer;
        }else{
            cout<<"Error:- trying to allocate memory offset which has already been reserved\n";
        }
    }
}

void MemoryManage::deAllocate(int value){
    memoryPointer -=value;
    if(memoryPointer<0)
        cout<<"Error:-  trying to deallocate memory offset which is not reserved"<<endl;
    else{
        for (int i=memoryPointer;i<totalMemoryBuffer; i++)
            memoryBufferReader[i]=-1;
    }
}


void MemoryManage::list(){
    for(int i=0;i<memoryPointer;i++){
        cout<<i+1<<" :- "<<memoryBufferReader[i]<<endl;
    }
}



int main()
{
    MemoryManage memoryManagerUser;
    int memoryBuffers,allignment;
    int *memoryBufferReader;
    cout<<"Enter the size of memory buffers\n";
    cin>>memoryBuffers;
    memoryBufferReader = new int[memoryBuffers];
    memoryManagerUser.setMemoryBufferReader(memoryBufferReader,memoryBuffers);
    while (1) {
    cout<<"Enter the Allignment i.e (4, 32)\nEnter 1 to dellocate the memory.\nEnter 2 to print.\nPress 0 to exit\n";
    cin>>allignment;
    switch (allignment) {
        case 1:
            int dellocationEntry;
            cout<<"Enter the dellocation allignment i.e (4,32)\n";
            cin>>dellocationEntry;
            memoryManagerUser.deAllocate(dellocationEntry);
            break;
            case 2:
            memoryManagerUser.list();
            break;
        case 4:
            memoryManagerUser.allocate(allignment);
        break;
        case 32:
            memoryManagerUser.allocate(allignment);
        break;
        case 0:
            exit(1);
            break;
        default:
            cout<<"invalid allignment !!!!!\n Please enter again \n";
            break;
    }
    }
    return 0;
}
