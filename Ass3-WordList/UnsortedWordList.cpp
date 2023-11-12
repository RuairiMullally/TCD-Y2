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

    while((current != nullptr) && (current->word != word)){
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
    Node *current = first;
    cout << "WordList(" << endl;
    cout << "length=" << length << endl;
    while(current != nullptr){
        cout << "Word(" << current->word << "," << current->count << ")" << endl;
        current = current->link;
    }
    cout << ")" << endl;
}

void UnsortedWordList::CountWord(string word){
    Node *current = FindWord(word);

    if(current != nullptr){
        current->count++;
    }else{
        Node* node = new Node(word, 1);
        length++;

        if(first == nullptr){
            first = node;
            last = node;
        }else{
            last->link = node;
            last = node;
        }
    }
}

void UnsortedWordList::InsertFirst(string word){

}
void UnsortedWordList::DeleteAll(){

}
void UnsortedWordList::DeleteWord(string word){

}
