//I've never thought of typing the problem description so helpful, 
//it's a enjoyable melodious tranquilizer
//Section 13.2, Ex13.28, p516 implement a default constructor and the necessary 
//copy-control members for class TreeNode and class BinStrTree

#include <iostream>
#include <string>

//decision: value-like behavior!
class TreeNode{
public:
    TreeNode (): s{""}, count {0}, left{nullptr}, right {nullptr} {}
    TreeNode (const TreeNode& source) = delete;  
    TreeNode& operator= (const TreeNode& source){
        if(this != &source){
            delete left;
            delete right;
            left = source.left;
            right = source.right;
            s = source.s;
            count = source.count;
        }
        return *this;
    }
    ~TreeNode (){delete left; delete right;}
private:
    std::string s;
    int count;
    TreeNode* left;
    TreeNode* right;
};

class BinStrTree{
public:
    BinStrTree (const TreeNode& node = nullptr) : root {node} {}
    BinStrTree& operator= (const BinStrTree& source){
        auto N = source.root;
        delete root;
        root = N;
        return *this;
    }
    ~BinStrTree () {delete root;}    
private:
    TreeNode* root;
    
};


int main ()
{
    return 0;
}