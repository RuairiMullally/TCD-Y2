#include "AlbumCollection.h"

void AlbumCollection::InsertAlbum(string artist, string title, int year){
    Album *albumToInsert = new Album(artist, title, year);
    setAlbums.insert(*albumToInsert);
}

void AlbumCollection::Print(){
    set<Album>::iterator iterVar;

    for(iterVar = setAlbums.begin(); iterVar != setAlbums.end(); ++iterVar){
        cout << iterVar->GetArtist() << ", " << iterVar->GetTitle() << " (" << iterVar->GetYear() << ")" << endl;
    }

}

void AlbumCollection::PrintByTitleSubstring(string titleSubstring){
    set<Album>::iterator iterVar;

    for(iterVar = setAlbums.begin(); iterVar != setAlbums.end(); ++iterVar){
        if((iterVar->GetTitle()).find(titleSubstring) != string::npos){
        cout << iterVar->GetArtist() << ", " << iterVar->GetTitle() << " (" << iterVar->GetYear() << ")" << endl;
        }
    }
}


void AlbumCollection::PrintByArtist(string artist){
    set<Album>::iterator iterVar;

    for(iterVar = setAlbums.begin(); iterVar != setAlbums.end(); ++iterVar){
        if(iterVar->GetArtist() == artist){
        cout << iterVar->GetArtist() << ", " << iterVar->GetTitle() << " (" << iterVar->GetYear() << ")" << endl;
        }
    }
}


void AlbumCollection::PrintByYear(int year){
    set<Album>::iterator iterVar;

    for(iterVar = setAlbums.begin(); iterVar != setAlbums.end(); ++iterVar){
        if(iterVar->GetYear() == year){
        cout << iterVar->GetArtist() << ", " << iterVar->GetTitle() << " (" << iterVar->GetYear() << ")" << endl;
        }
    }
}

bool AlbumCollection::ContainsTitle(string title){
    set<Album>::iterator iterVar;

    for(iterVar = setAlbums.begin(); iterVar != setAlbums.end(); ++iterVar){
        if(iterVar->GetTitle() == title){
        return true;
        }
    }
    return false;
}

bool AlbumCollection::ContainsArtist(string artist){
    set<Album>::iterator iterVar;

    for(iterVar = setAlbums.begin(); iterVar != setAlbums.end(); ++iterVar){
        if(iterVar->GetArtist() == artist){
        return true;
        }

    }
    return false;
}

bool AlbumCollection::ContainsYear(int year){
    set<Album>::iterator iterVar;

    for(iterVar = setAlbums.begin(); iterVar != setAlbums.end(); ++iterVar){
        if(iterVar->GetYear() == year){
        return true;
        }
    }
    return false;
}

void AlbumCollection::DeleteAlbumByTitle(string titleToSearch){
    set<Album>::iterator iterVar;

    for(iterVar = setAlbums.begin(); iterVar != setAlbums.end(); ++iterVar){
        if(iterVar->GetTitle() == titleToSearch){
            setAlbums.erase(iterVar);
            return;
        }
    }
    cout << "No album found!" << endl;
}

void AlbumCollection::DeleteAlbumsByArtist(string artistToSearch){
    set<Album>::iterator iterVar = setAlbums.begin();
    bool found = false;

    while(iterVar != setAlbums.cend()){
        if(iterVar->GetArtist() == artistToSearch){
                found = true;
            iterVar = setAlbums.erase(iterVar);
        }else{
            ++iterVar;
        }

    }

    if(found == false){
        cout << "No album found!" << endl;
    }


}

int AlbumCollection::GetNumberAlbums(){
    return setAlbums.size();

}
