#include "UnsortedWordList.h"





UnsortedWordList::UnsortedWordList(){
    first = nullptr;
    last = nullptr;
    length = 0;

}

UnsortedWordList::~UnsortedWordList(){
    
}

bool UnsortedWordList::IsEmpty() const{
    return(length == 0);
}

int UnsortedWordList::Length() const{//return length
    return (length);
}

Node *UnsortedWordList::Front() const{//return pointer to first node
    return (first);
}

Node *UnsortedWordList::Back() const{//return pointer to last node
    return (last);
}

bool UnsortedWordList::Contains(string word){
    Node *current = first;

    while(current != nullptr){
        if(current->word == word){
            return true;
        }
        current = current->link;
    }
    return false;
}

Node *UnsortedWordList::FindWord(string word){
    Node *current = first;

    while((current->word != word) && (current != nullptr)){
        current = current->link;
    }
    return current;
}

string UnsortedWordList::MaxWord() const{
    Node *current = first;
    Node *max = first;

    if(current == nullptr){
        return "undefined";
    }

    while(current != nullptr){
        if(current->count > max->count){
            max = current;
        }
        current = current->link;
    }
    current = first;
    while(current != nullptr){
        if(current->count == max->count && current->word != max->word){
            return "undefined";
        }
        current = current->link;
    }
    return(max->word);
}

int UnsortedWordList::MaxCount() const{
    Node *current = first;
    Node *max = first;

    if(current == nullptr){
        return 0;
    }

    while(current != nullptr){
        if(current->count > max->count){
            max = current;
        }
        current = current->link;
    }
    return(max->count);  
}

void UnsortedWordList::Print() const{
    Node *current = Front();
    cout << "WordList(" << endl;
    cout << "length=" << length;
    while(current != nullptr){
        cout << "Word(" << current->word << "," << current->count << ")" << endl;   
    }
    cout << ")" << endl;
}

void UnsortedWordList::CountWord(string word){
    Node *current = FindWord(word);
    
    if(first == nullptr){
        first = new Node(word, 1);
        last = first;
        length++; 
    }
    else if(current != nullptr){
        current->count++;
    }else{
        Node* node = new Node(word, 1);
        last->link = node;
        length++;
    } 
}

void UnsortedWordList::InsertFirst(string word){

}
void UnsortedWordList::DeleteAll(){

}
void UnsortedWordList::DeleteWord(string word){

}