// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <vector>

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main(){
    std::fstream file ("names.csv", std::ios::in);
    // Read the CSV file.
    if(file.is_open()){
        file.seekg(0, file.end);
        int length = file.tellg();
        file.seekg(0, file.beg);
        char * arr = new char[length];
        file.read(arr, length);

        std::istringstream iss(arr);
        std::string token;

        std::map<std::string, std::vector<std::string>> names;
        std::string firstname;
        std::string surname;
        while(getline(iss, token, ','))
        {
            int spaceIndex = token.find(' ', 0);
            surname = token.substr(spaceIndex + 1, token.length() - spaceIndex + 1);
            firstname = token.substr(0, spaceIndex);
            if (names.find(surname) == names.end())
            {
                std::vector<std::string> temp;
                temp.push_back(firstname);
                names.insert({surname, temp});
            }
            else
            {
                names[surname].push_back(firstname);
            }

        } 

        std::map<std::string, std::vector<std::string>>::iterator it = names.begin();
        while (it != names.end())
        {
            surname = it->first;
            std::vector<std::string> firstnames = it->second;
            if (firstnames.size() >= 2)
            {
                std::cout << firstnames[0] << " & " <<firstnames[1] << " " << surname << std::endl; 
            }
            ++it;
        }
        file.close();
        delete [] arr;
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    // Write your code here

    std::cout << "No relatives found.\n\n" << std::flush;    
    return 0;
}
 