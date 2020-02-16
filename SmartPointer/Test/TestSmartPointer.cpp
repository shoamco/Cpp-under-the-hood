//
// Created by shoam on 2/13/20.
//

#include "TestSmartPointer.h"
#include "SharedPointer.h"
void testControlBlock(){
std::cout<<"\n\n\n**************  testControlBlock *******\n";
    ReferenceCounter referenceCounter();
std::cout<<referenceCounter;
}

void testCtorSmartPtr(){
    std::cout<<"\n\n\n**************  testCtorSmartPtr *******\n";

    SharedPointer<int> sharedPointer1(new int(5));
    std::cout<<"sharedPointer1 "<<sharedPointer1.get()<<std::endl;
    SharedPointer<int> sharedPointer2=sharedPointer1;
    std::cout<<"sharedPointer2 "<<sharedPointer2.get()<<std::endl;
    *sharedPointer2=10;
    std::cout<<"after set sharedPointer1 "<<sharedPointer1.get()<<std::endl;


}
void testSmartPtrInScope(){
    std::cout<<"\n\n\n**************  testSmartPtrInScope *******\n";

    SharedPointer<int> sharedPointer1(new int(5));
     std::cout<<"sharedPointer1 "<<sharedPointer1.get()<<std::endl;
    {
        SharedPointer<int> sharedPointer2 = sharedPointer1;
        std::cout << "sharedPointer2 " << sharedPointer2.get() << std::endl;
        *sharedPointer2 = 10;
        {
            SharedPointer<int> sharedPointer3 = sharedPointer1;
            std::cout << "sharedPointer3 " << sharedPointer3.get() << std::endl;
            std::cout<<"end of scope \n";
        }
        std::cout<<"end of scope \n";

    }
    std::cout<<"after set sharedPointer1 "<<sharedPointer1.get()<<std::endl;

}
void testSmartPointer(){
     testControlBlock();
    testCtorSmartPtr();
    testSmartPtrInScope();
}