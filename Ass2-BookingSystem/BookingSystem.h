#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include <string>
using namespace std;
class BookingSystem {
    private:
        string m_name;
        unsigned int m_totalWindowsLaptops;
        unsigned int m_totalMacBooks;
        unsigned int m_availableWindowsLaptops;
        unsigned int m_availableMacBooks;
    public:
        BookingSystem();
        BookingSystem(string name, int totalWindowsLaptops, int totalMacBooks);

        bool RentWindowsLaptop();
        bool RentMacBook();

        void ReturnWindowsLaptop();
        void ReturnMacBook();

        string getName();
        unsigned int getTotalWindowsLaptops();
        unsigned int getTotalMacBooks();

        unsigned int getAvailableWindowsLaptops();
        unsigned int getAvailableMacBooks();
        unsigned int getAvailableLaptops();

        unsigned int getRentedWindowsLaptops();
        unsigned int getRentedMacBooks();
        unsigned int getRentedLaptops();

        void addWindowsLaptops(unsigned int additionalWindowsLaptops);
        void addMacBooks(unsigned int additionalMacBooks);

        void removeWindowsLaptops(unsigned int removedWindowsLaptops);
        void removeMacBooks(unsigned int removedMacBooks);

        void PrintReport();
};
#endif //BOOKINGSYSTEM_H
