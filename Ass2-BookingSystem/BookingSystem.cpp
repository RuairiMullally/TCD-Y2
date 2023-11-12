//Ruairi Mullally 22336002
#include "BookingSystem.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;



BookingSystem::BookingSystem()
    : m_name("Trinity Laptop Bookings"), m_totalWindowsLaptops(20), m_totalMacBooks(20){

    m_availableWindowsLaptops = m_totalWindowsLaptops;
    m_availableMacBooks = m_totalMacBooks;
}

BookingSystem::BookingSystem(string name, int totalWindowsLaptops, int totalMacBooks){
    name = name.substr(0,64);
    m_name = name;

    m_totalWindowsLaptops = (totalWindowsLaptops > 0) ? totalWindowsLaptops : 0;
    m_totalMacBooks = (totalMacBooks > 0) ? totalMacBooks : 0;

    m_availableWindowsLaptops = m_totalWindowsLaptops;
    m_availableMacBooks = m_totalMacBooks;
}

//rent laptops
bool BookingSystem::RentWindowsLaptop(){
    if(m_availableWindowsLaptops > 0){
        m_availableWindowsLaptops -= 1;
        return true;
    }else return false;
}
bool BookingSystem::RentMacBook() {
    if(m_availableMacBooks > 0){
        m_availableMacBooks -= 1;
        return true;
    }else return false;
}

//return laptops
void BookingSystem::ReturnWindowsLaptop() {
    if(m_totalWindowsLaptops - m_availableWindowsLaptops > 0 ) {
        m_availableWindowsLaptops += 1;
    }
}
void BookingSystem::ReturnMacBook() {
    if(m_totalMacBooks - m_availableMacBooks > 0){
        m_availableMacBooks += 1;
    }

}

//add or remove laptops
void BookingSystem::addWindowsLaptops(unsigned int additionalWindowsLaptops){
    m_totalWindowsLaptops += additionalWindowsLaptops;
    m_availableWindowsLaptops += additionalWindowsLaptops;
}
void BookingSystem::addMacBooks(unsigned int additionalMacBooks){
    m_totalMacBooks += additionalMacBooks;
    m_availableMacBooks += additionalMacBooks;
}
void BookingSystem::removeWindowsLaptops(unsigned int removedWindowsLaptops){
    if(m_availableWindowsLaptops >= removedWindowsLaptops){
        m_totalWindowsLaptops -= removedWindowsLaptops;
        m_availableWindowsLaptops -= removedWindowsLaptops;
    }else{
        m_totalWindowsLaptops -= m_availableWindowsLaptops;
        m_availableWindowsLaptops = 0;
    }
}
void BookingSystem::removeMacBooks(unsigned int removedMacBooks){
    if(m_availableMacBooks >= removedMacBooks){
        m_totalMacBooks -= removedMacBooks;
        m_availableMacBooks -= removedMacBooks;
    }else {
        m_totalMacBooks -= m_availableMacBooks;
        m_availableMacBooks = 0;
    }
}


// get functions. all return the value of the func name
string BookingSystem::getName(){
    return m_name;
}
unsigned int BookingSystem::getTotalWindowsLaptops(){
    return m_totalWindowsLaptops;
}
unsigned int BookingSystem::getTotalMacBooks(){
    return m_totalMacBooks;
}

unsigned int BookingSystem::getAvailableWindowsLaptops(){
    return m_availableWindowsLaptops;
}
unsigned int BookingSystem::getAvailableMacBooks(){
    return m_availableMacBooks;
}
unsigned int BookingSystem::getAvailableLaptops(){
    return m_availableWindowsLaptops + m_availableMacBooks;
}

unsigned int BookingSystem::getRentedWindowsLaptops(){
    return m_totalWindowsLaptops - m_availableWindowsLaptops;
}
unsigned int BookingSystem::getRentedMacBooks(){
    return m_totalMacBooks - m_availableMacBooks;
}
unsigned int BookingSystem::getRentedLaptops(){
    return (m_totalWindowsLaptops - m_availableWindowsLaptops) + (m_totalMacBooks - m_availableMacBooks);
}

//print report
void BookingSystem::PrintReport(){
    cout << "---------------------\nLaptop Booking System\n---------------------" << endl;
    cout << setw(25) << left << "Name"<< " : " << m_name << endl;
    cout << setw(25) << left << "Total Windows Laptops"<< " : " << getTotalWindowsLaptops() << endl;
    cout << setw(25) << left << "Total MacBooks"<< " : " << getTotalMacBooks() << endl;
    cout << setw(25) << left << "Rented Windows Laptops"<< " : " << getRentedWindowsLaptops() << endl;
    cout << setw(25) << left << "Rented MacBooks"<< " : " << getRentedMacBooks() << endl;
    cout << setw(25) << left << "Rented Laptops"<< " : " << getRentedLaptops() << endl;
    cout << setw(25) << left << "Available Windows Laptops"<< " : " << getAvailableWindowsLaptops() << endl;
    cout << setw(25) << left << "Available MacBooks"<< " : " << getAvailableMacBooks() << endl;
    cout << setw(25) << left << "Available Laptops"<< " : " << getAvailableLaptops() << endl;

}


