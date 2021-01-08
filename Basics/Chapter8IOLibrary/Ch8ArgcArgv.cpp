//run it in terminal to observe argc and argv
#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int counter; 
    printf("Program Name Is: %s",argv[0]); 
    if(argc==1) 
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name"); 
    if(argc>=2) 
    { 
        printf("\nNumber Of Arguments Passed: %d",argc); 
        printf("\n----Following Are The Command Line Arguments Passed----"); 
        for(counter=0;counter<argc;counter++) 
            printf("\nargv[%d]: %s",counter,argv[counter]); 
    } 
    /*
    cout << "You have entered " << argc 
         << " arguments:" << "\n"; 
  
    for (int i = 0; i < argc; ++i) 
        cout << argv[i] << "\n"; 
    */
    return 0; 
}
/*
 You have entered 1 arguments:
/home/primer/Documents/FirstWorkspace/Ch8argc/Debug/Ch8argc
Hit any key to continue...
 */

//g++ -o ArgToMain main.cpp
//run it: ./ArgToMain file1 file2
//run it: ./ArgToMain "file1 file2"
//run it: ./ArgToMain 'file1 file2'