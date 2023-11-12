#include <iostream>
#include <string>
#include <cmath>

void PrintResults(int minimum, std::string minname, int maximum, std::string maxname, int total);


int main() {
  //declarations
  const std::string SENTINEL = "done";
  std::string filter_name = "all", username, maxname, minname;
  int total = 0, maximum = -1, minimum = -1;
  double score;

  //read in filter requirements
  std::cout << "Enter name to filter. Enter \"all\" to process all records:" << std::endl;
  std::cin >> filter_name;

  std::cout << "Enter data:" << std::endl;
  std::cin >> username;

  bool end_loop = (username == SENTINEL) ? true : false; //checks if the Sentinel was entered, thus terminating loop

  while (!end_loop) {
    std::cin >> score;

    if(!std::cin.fail()){ // checks if the input is a number

      if((filter_name == "all" || username == filter_name) && score == floor(score) && score >= 0 ){//uses filters, checks if number is a natural number
        total += score;

        if(maximum == -1){// initializes the min and max as the first read in values
          maximum = score;
          maxname = username;
          minimum = score;
          minname = username;
        }

        if(score > maximum){//logs max and name of max
          maximum = score;
          maxname = username;
        }

        if(score < minimum){//logs min and name of min
          minimum = score;
          minname = username;
        }
      }



    }
    else{//if input is not a number, input is cleared
      std::cin.clear();
      std::cin.ignore(100, '\n');
    }

    std::cin >> username;
    end_loop = (username == SENTINEL) ? true : false;//check if loop should be terminated
  }
  PrintResults(minimum, minname, maximum, maxname, total);
  return 0;
}


void PrintResults(int minimum, std::string minname, int maximum, std::string maxname, int total){
  /*
  Args:
    minimum (int): smallest number from inputs
    minname (str): name of person with minimum
    maximum (int): largest number from inputs
    maxname (str): name of person with maximum

  Raises:
    None

  Returns:
    None
  */

  if (minimum == -1 || maximum == -1){// if nomatches are found
    std::cout << "-------" << std::endl << "Results" << std::endl << "-------" << std::endl;
    std::cout << "Minimum: " << "(no data found)" << std::endl;
    std::cout << "Maximum: " << "(no data found)" << std::endl;
    std::cout << "Total: " << "(no data found)" << std::endl;
  }else {//prints summarized data
    std::cout << "-------" << std::endl << "Results" << std::endl << "-------" << std::endl;
    std::cout << "Minimum: " << minname << " " << minimum << std::endl;
    std::cout << "Maximum: " << maxname << " " << maximum << std::endl;
    std::cout << "Total: " << total << std::endl;
  }

}
