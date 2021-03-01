#include "Ch13Ex34MessageFolder.h"
#include "Ch13Ex34MessageFolder.cpp"

//test driver
//references/aliases are used in every method, therefore, no need to worry about memory leak at all.
//precision shooting, the offset is neither too much or too less, just engage the target.

int main ()
{
    Message *m1 = new Message("Mike Pence");
    Folder f1;
    m1->Save(f1);
    //precious picture of an iceberg under water:)
    std::cout << m1->Occurrences() <<std::endl; 
    Message *m2 = new Message ("team leader fighting chinese wuhan virus");
    m2->Save(f1);
    std::cout << f1.MessageElements() <<std::endl; //the world falls in peace now
   	Message m3 = *m2;
    m3 = Message("Mike Pompeo is a true man!");
    return 0;
}
