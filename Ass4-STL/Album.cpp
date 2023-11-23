#include "Album.h"

Album::Album(string newArtist, string newTitle, int newYear)
	: artist(newArtist), title(newTitle), year(newYear){
}

string Album::GetArtist() const{
	return (this->artist);
}

string Album::GetTitle() const{
	return (this->title);
}

int Album::GetYear() const{
	return (this->year);
}

bool Album::operator==(const Album &itemToCompare) const{
	if(itemToCompare.artist == this->artist && itemToCompare.title == this->title && itemToCompare.year == this->year){
		return true;
	}
	return false;
}

bool Album::operator<(const Album &itemToCompare) const{

    if(this->artist < itemToCompare.GetArtist()){
        return true;
	}else if(this->artist == itemToCompare.GetArtist()){

	    if(this->title < itemToCompare.GetTitle()){
            return true;
        }else if(this->title == itemToCompare.GetTitle()){

            if(this->year < itemToCompare.GetYear()){
                return true;
            }
        }
	}
	return false;
}

