#include "Ch13Ex34MessageFolder.h"

//test the logic
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
   
    return 0;
}
