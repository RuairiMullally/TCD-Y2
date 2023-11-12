/* CE2 Assignment 2 Testing File
 * Authors: Darragh Elliott, Sean McGoff
 * To use, make this your main entry point for a compiled executable
 */
#include <iostream>
#include <sstream>
#include <vector>
#include "BookingSystem.h"

class testCase {
    private:
        void(*tf)(); // Test Function (test1, test2, etc.)
        std::string eo; // Expected Output
    public:
        // Constructor
        testCase(void(*test_func)(), std::string expected_output) : tf(test_func), eo(expected_output){};
        // Get Expected Output
        std::string getExpectedOutput() { return this->eo; };
        // Stream Buffer Madness (NOT THREAD SAFE AT ALL)
        std::string captureOutput() {
            std::stringstream b;
            std::streambuf * old = std::cout.rdbuf(b.rdbuf());
            tf();
            std::string o = b.str();
            std::cout.rdbuf(old);
            return o;
        }
        // The Actual Test Function
        bool test() {
            return captureOutput() == this->eo;
        }
};

void test1() {
  // Default constructor
  BookingSystem bookingSystemA;
  bookingSystemA.PrintReport();
}

void test2() {
  // Defined constructor, renting less than number of laptops
  BookingSystem bookingSystemB("GamesCon 2022 Laptops", 200, 200);
  for (int i = 0; i < 5; i++) {
    bookingSystemB.RentWindowsLaptop();
    bookingSystemB.RentMacBook();
  }
  bookingSystemB.ReturnWindowsLaptop();
  bookingSystemB.PrintReport();
}

void test3() {
  // Renting more than available, then return 1 of each
  BookingSystem bookingSystemC("Confused Shop", 10, 5);
  for (int i = 0; i < 20; i++) {
    bookingSystemC.RentWindowsLaptop();
    bookingSystemC.RentMacBook();
  }
  bookingSystemC.ReturnWindowsLaptop();
  bookingSystemC.ReturnMacBook();
  bookingSystemC.PrintReport();
}
void test4() {
  // Name may not be longer than 64 chars test and negative inits
  // for laptops
  BookingSystem bookingSystemD(
      "This sentence is longer than 64 chars.We reach 64 chars at line| This"
      " text should be cut from the name ",
      -10, -4);
  bookingSystemD.PrintReport();
}
void test5() {
  // Add laptops and then remove more than are present in the shop.
  BookingSystem bookingSystemE("Laptop breaky shop", 10, 10);
  bookingSystemE.addWindowsLaptops(10);
  bookingSystemE.addMacBooks(100);
  bookingSystemE.removeWindowsLaptops(100);
  bookingSystemE.removeMacBooks(95);
  bookingSystemE.PrintReport();
}
void test6() {
  // Test removing laptops when some have been rented out
  // Not sure if he what he means by "It is not possible to remove more than
  // what is currently available" I chose to interpret this that laptops that
  // are not available, ie rented out, cannot be removed
  BookingSystem bookingSystemF("Laptop shop 2 electric boogaloo", 10, 10);
  for (int i = 0; i < 5; i++) {
    bookingSystemF.RentWindowsLaptop();
    bookingSystemF.RentMacBook();
  };
  bookingSystemF.removeWindowsLaptops(100);
  bookingSystemF.removeMacBooks(1);
  bookingSystemF.PrintReport();
}
void test7() { // Test returning more laptops than possible
  BookingSystem bookingSystemG("Too many laptops.com", 10, 10);
  for (int i = 0; i < 5; i++) {
    bookingSystemG.RentWindowsLaptop();
    bookingSystemG.RentMacBook();
  };
  for (int i = 0; i < 20; i++) {
    bookingSystemG.ReturnWindowsLaptop();
    bookingSystemG.ReturnMacBook();
  }
  bookingSystemG.PrintReport();
}

int main() {
    vector<testCase> tests;
    tests.push_back(testCase{&test1,
    "---------------------\n"s+
    "Laptop Booking System\n"s+
    "---------------------\n"s+
    "Name                      : Trinity Laptop Bookings\n"s+
    "Total Windows Laptops     : 20\n"s+
    "Total MacBooks            : 20\n"s+
    "Rented Windows Laptops    : 0\n"s+
    "Rented MacBooks           : 0\n"s+
    "Rented Laptops            : 0\n"s+
    "Available Windows Laptops : 20\n"s+
    "Available MacBooks        : 20\n"s+
    "Available Laptops         : 40\n"s});
    tests.push_back(testCase{&test2,
    "---------------------\n"s+
    "Laptop Booking System\n"s+
    "---------------------\n"s+
    "Name                      : GamesCon 2022 Laptops\n"s+
    "Total Windows Laptops     : 200\n"s+
    "Total MacBooks            : 200\n"s+
    "Rented Windows Laptops    : 4\n"s+
    "Rented MacBooks           : 5\n"s+
    "Rented Laptops            : 9\n"s+
    "Available Windows Laptops : 196\n"s+
    "Available MacBooks        : 195\n"s+
    "Available Laptops         : 391\n"s});
    tests.push_back(testCase{&test3,
    "---------------------\n"s+
    "Laptop Booking System\n"s+
    "---------------------\n"s+
    "Name                      : Confused Shop\n"s+
    "Total Windows Laptops     : 10\n"s+
    "Total MacBooks            : 5\n"s+
    "Rented Windows Laptops    : 9\n"s+
    "Rented MacBooks           : 4\n"s+
    "Rented Laptops            : 13\n"s+
    "Available Windows Laptops : 1\n"s+
    "Available MacBooks        : 1\n"s+
    "Available Laptops         : 2\n"s});
    tests.push_back(testCase{&test4,
    "---------------------\n"s+
    "Laptop Booking System\n"s+
    "---------------------\n"s+
    "Name                      : This sentence is longer than 64 chars.We reach 64 chars at line|\n"s+
    "Total Windows Laptops     : 0\n"s+
    "Total MacBooks            : 0\n"s+
    "Rented Windows Laptops    : 0\n"s+
    "Rented MacBooks           : 0\n"s+
    "Rented Laptops            : 0\n"s+
    "Available Windows Laptops : 0\n"s+
    "Available MacBooks        : 0\n"s+
    "Available Laptops         : 0\n"s});
    tests.push_back(testCase{&test5,
    "---------------------\n"s+
    "Laptop Booking System\n"s+
    "---------------------\n"s+
    "Name                      : Laptop breaky shop\n"s+
    "Total Windows Laptops     : 0\n"s+
    "Total MacBooks            : 15\n"s+
    "Rented Windows Laptops    : 0\n"s+
    "Rented MacBooks           : 0\n"s+
    "Rented Laptops            : 0\n"s+
    "Available Windows Laptops : 0\n"s+
    "Available MacBooks        : 15\n"s+
    "Available Laptops         : 15\n"s});
    tests.push_back(testCase{&test6,
    "---------------------\n"s+
    "Laptop Booking System\n"s+
    "---------------------\n"s+
    "Name                      : Laptop shop 2 electric boogaloo\n"s+
    "Total Windows Laptops     : 5\n"s+
    "Total MacBooks            : 9\n"s+
    "Rented Windows Laptops    : 5\n"s+
    "Rented MacBooks           : 5\n"s+
    "Rented Laptops            : 10\n"s+
    "Available Windows Laptops : 0\n"s+
    "Available MacBooks        : 4\n"s+
    "Available Laptops         : 4\n"s});
    tests.push_back(testCase{&test7,
    "---------------------\n"s+
    "Laptop Booking System\n"s+
    "---------------------\n"s+
    "Name                      : Too many laptops.com\n"s+
    "Total Windows Laptops     : 10\n"s+
    "Total MacBooks            : 10\n"s+
    "Rented Windows Laptops    : 0\n"s+
    "Rented MacBooks           : 0\n"s+
    "Rented Laptops            : 0\n"s+
    "Available Windows Laptops : 10\n"s+
    "Available MacBooks        : 10\n"s+
    "Available Laptops         : 20\n"s});

    bool didCasePass;
    for(int i = 0; i < tests.size(); ++i) {
      std::cout << "Test Case " << i+1 << ":\n-------------\n";
      didCasePass = tests[i].test();
      std::cout << "Test Case " << i+1 << " " << (didCasePass ? "Passed!" : "Failed") << "\n";
      if(!didCasePass) {
        std::cout << "Expected Output:\n" << tests[i].getExpectedOutput() << "\n";
        std::cout << "Student Output:\n" << tests[i].captureOutput() << "\n";
      }
      std::cout << "\n\n";
    }
}

//lol
