#include "UnsortedWordList.h"





UnsortedWordList::UnsortedWordList(){
    first = nullptr;
    last = nullptr;
    length = 0;

}

UnsortedWordList::~UnsortedWordList(){
    DeleteAll();
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
    Node *maxi = first;

    if(current == nullptr){
        return "undefined";
    }

    while(current != nullptr){
        if(current->count > maxi->count){
            maxi = current;
        }
        current = current->link;
    }
    current = first;
    while(current != nullptr){
        if((current->count == maxi->count) && (current->word != maxi->word)){
            return "undefined";
        }
        current = current->link;
    }
    return(maxi->word);
}

int UnsortedWordList::MaxCount() const{
    Node *current = first;
    Node *maxi = first;

    if(current == nullptr){
        return 0;
    }

    while(current != nullptr){
        if(current->count > maxi->count){
            maxi = current;
        }
        current = current->link;
    }
    return(maxi->count);
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
    Node *current = FindWord(word);
    if(current != nullptr){
        current->count++;
    }else{
        Node* node = new Node(word, 1);
        length++;
        node->link = first;
        first = node;
        if(last == nullptr){
            last = first;
        }
    }
}

void UnsortedWordList::DeleteAll(){
    Node* currentnode = first;
    Node* nextnode;
    while (currentnode != nullptr){
        nextnode = currentnode->link;
        delete currentnode;
        currentnode=nextnode;
    }
    length =0;
    first = nullptr;
    last = nullptr;
}

void UnsortedWordList::DeleteWord(string word){
    Node *current = FindWord(word);
    if(current != nullptr && current == first && first == last){//if node is first and only node
        length--;
        first = nullptr;
        last = nullptr;
        delete current;
    }else if(current != nullptr && current == first){//if node is first in list
        first = first->link;
        length--;
        delete current;
    }else if(current != nullptr){//if node is somewhere else
        Node *previous = nullptr;
        current = first;
        while(current != nullptr && current->word != word){
            previous = current;
            current = current->link;
        }
        if(current == last){//if node is last in list
            previous->link = nullptr;
            last = previous;
            delete current;
            length--;
        }else{//if node is somewhere in the middle of list
            previous->link = current->link;
            length--;
            delete current;
        }
    }
}