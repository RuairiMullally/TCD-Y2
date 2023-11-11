#include "Node.h"

Node::Node(string newWord){
    word = newWord;  
    link = nullptr;    
}

Node::Node(string newWord, int newCount){
    word = newWord;
    link = nullptr; 
    count = newCount;
}