//finally a function that returns a pointer to another function
#include <iostream>

typedef int (*op_func)(int, int);

int add (int a, int b){ return a+b; }
int sub (int a, int b){ return a-b; }

op_func getfunc(char op){
    switch(op) {
        case '+': return add;
        case '-': return sub;
        default:
        	return add;
    };
}

int main(){
    printf("5 + 7 = %d\n", getfunc('+')(5, 7));
    printf("5 - 7 = %d\n", getfunc('-')(5, 7));
	return 0;
}