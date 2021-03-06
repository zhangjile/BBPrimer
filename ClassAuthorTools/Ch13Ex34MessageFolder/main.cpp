#include "Ch13Ex34MessageFolder.h"
#include "Ch13Ex34MessageFolder.cpp"

//test driver
int main ()
{
    Message *m1 = new Message("Mike Pence");
    Folder f1;
    m1->Save(f1);
    
    Message *m2 = new Message ("team leader fighting wuhan virus");
    m2->Save(f1);
    
   	Message m3 = *m2;
    std::cout << "f1: " << f1.MessageElements() <<std::endl; //3
    
    Message m4("Mike Pompeo is a true man!");
    Folder f2;
    m4.Save(f2);
    std::cout << "f2: " << f2.MessageElements() <<std::endl; //1
    m4 = std::move(m3);
//    m4 = m3;
    std::cout << "f1: " << f1.MessageElements() <<std::endl; //3
    std::cout << "f2: " << f2.MessageElements() <<std::endl; //0
    return 0;
}
