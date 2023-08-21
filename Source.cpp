#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

class CornerGrocer {
    public:
        int optionOne(string userWord, int wordFreq);
        void optionTwo();
        void optionThree();
        void Menu();
 
    private:     
        string userWord;
        int wordFreq = 0;   
        string currWord;
};

int CornerGrocer::optionOne(string userWord, int wordFreq) {
    
    cout << wordFreq << endl;

    return 0;
}

void CornerGrocer::optionTwo() {
    ofstream outFS;    //Output file stream
    map<string, int> wordFreq;    //map stores string and int
    ifstream input;

    input.open("CS210_Project_Three_Input_File.txt");
    string word;
    while (input >> word) {     //Obtains word frequency for a certain word
        ++wordFreq[word];       //Increments number of word
    }
    for (map<string, int>::iterator it = wordFreq.begin(); it != wordFreq.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;     //Prints first and second key
    }

    outFS.open("frequency.dat");    //Opens file for writing
    if (!outFS.is_open()) {
        cout << "Could not open file myoutfile.txt." << endl;
        abort();
    }
    for (map<string, int>::iterator it = wordFreq.begin(); it != wordFreq.end(); ++it) {
        outFS << it->first << " " << it->second << endl;   //Writes to file
    }
    outFS.close();    //Close the file

}

void CornerGrocer::optionThree() {
    char asterisk = '*';    //Initializes asterisk character

    map<string, int> wordFreq;    //Defines the map with a string and int
    ifstream input;

    input.open("CS210_Project_Three_Input_File.txt");
    string word;
    while (input >> word)
    {
        ++wordFreq[word];
    }
    for (map<string, int>::iterator it = wordFreq.begin(); it != wordFreq.end(); ++it)
    {
        cout << it->first << " " << string(it->second, asterisk) << endl;   //Multiplies asterisk by the second key of the map
    }
}


void CornerGrocer::Menu() {
    cout << "List of menu options:" << endl;
    cout << "Menu option: '1' - Displays the frequency of items purchased." << endl;
    cout << "Menu option: '2' - Displays the item and frequency of all items purchased." << endl;
    cout << "Menu option: '3' - Displays the item and frequency of all items purchased through a histogram." << endl;
    cout << "Menu option: '4' - Exit the program." << endl;
}

int main() {
    ifstream inFS;     // Input file stream
    string userWord;
    CornerGrocer Employee;
    char menuOption = '0';
    string currWord;
    int wordFreq = 0;   //Initialize word frequency so that we can increment evry time the word is found

    cout << "Enter the item you are looking for: ";
    cin >> userWord;

    inFS.open("CS210_Project_Three_Input_File.txt");    //opens the file
    if (!inFS.is_open()) {   //determines if the file was opened or not
        cout << "Could not open file wordFile.txt." << endl;
        return 1;
    }

    while (!inFS.eof()) {    //Checks if the word matches the words in file
        inFS >> currWord;
        if (!inFS.fail()) {
            if (currWord == userWord) {
                ++wordFreq;     //Increases word frequency for every instance of the word
            }
        }
    }

    while (menuOption != '4') {     //While loop ends program when "4" is entered
        Employee.Menu();
        cout << "Enter Menu option: " << endl;
        cin >> menuOption;
        if (menuOption == '1') {    //Selects menu option 1
            Employee.optionOne(userWord, wordFreq);
        }
        else if (menuOption == '2') {
            Employee.optionTwo();
        }
        else if (menuOption == '3') {
            Employee.optionThree();
        }
        else if (menuOption == '4') {
            cout << "Exiting program.";
            break;
        }
        else {
            cout << "Error. Enter a different option." << endl;
        }
    }
    inFS.close();   //Closes the file

    return 0;
}