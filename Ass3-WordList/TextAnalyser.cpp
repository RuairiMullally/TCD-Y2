#include "TextAnalyser.h"
#include <iostream>
#include <fstream>

using namespace std;

void TextAnalyser::ReadFile(string filename) {
    cout << "TextAnalyser::ReadFile, filename='" << filename << "'." << endl;

    ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        cout << "unable to open file with filename='" << filename << "'." << endl;
        return;
    }

    string word;
    UnsortedWordList *readList;

    if(readIntoA){
        readList = &listA;
    }else{
        readList = &listB;

    }

    while(file >> word){
        //cout << "word: " << word << endl;
        readList->CountWord(word);
    }
    readIntoA = !readIntoA;
}

void TextAnalyser::Intersection(){
    Node *currentA = listA.Front();
    Node *currentB;

    while(currentA != nullptr){
        currentB = listB.Front();
        while(currentB != nullptr){

            if(currentB->word == currentA->word){

                if((currentA->count) > (currentB->count)){

                    for(int i=0; i<currentB->count;i++){
                        listC.CountWord(currentB->word);
                    }
                }else{
                    for(int p=0; p<currentA->count;p++){
                        listC.CountWord(currentB->word);
                    }
                }
            }
            currentB = currentB->link;
        }
        currentA = currentA->link;
    }
}

void TextAnalyser::Union(){
    listC.DeleteAll();
    Node *currentA = listA.Front();
    Node *currentB = listB.Front();

    while(currentA != nullptr){
        for(int p=0; p<currentA->count;p++){
            listC.CountWord(currentA->word);
        }
        currentA = currentA->link;
    }

    while(currentB != nullptr){
        for(int i=0; i<currentB->count;i++){
            listC.CountWord(currentB->word);
        }
        currentB = currentB->link;
    }
}