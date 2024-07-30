//Silly Calculator App - Berger
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//Display for calculator
void calcDisplay() {
    cout<<" _______"<<endl;
    cout<<"[_______]"<<endl;
    cout<<"|1_2_3_+|"<<endl;
    cout<<"|4_5_6_-|"<<endl;
    cout<<"|7_8_9_*|"<<endl;
    cout<<"|__0___/|"<<endl<<endl;
}

//Logic for the math
double performOperation (double input, double temp, string op) {
    switch (op[0]) {            //handles each operation type and returns appropriate result
        case '+': return input + temp;
        case '-': return input - temp;
        case '*': return input * temp;
        case '/':
        if (temp == 0) {        //Checks for zero division errors
            cout<<"Zero Division Error"<<endl;
            return input;
        } else {
            return input / temp;
        }
        default: return input;
    }
}

//Asks user questions and calls functions
void calculator (string sillyType2 = "", string sillyType = "") {
    string op;              //op gets what operation the user wants to do, silly 
    double input, temp;     //input is the first amount user gives and is reasigned after each operation
                            //temp is the second amount user gives
    calcDisplay();          //display
    cout<<"Enter in amount "<<sillyType2<<": ";
    cin>>input;

    //loops through questions until user wants to clear
    while (true) {
        cout<<"Enter in an operation (+, -, *, /, or clear): ";
        cin>>op;
        if (op == "clear") {        //clears the display, puts up the title screen, and then runs calc function
            system("clear");
            cout<<"Silly Calculator App - Berger"<<endl;
            cout<<"-----------------------"<<endl;
            calcDisplay();          //display
            cout<<"Enter in first amount "<<sillyType2<<": ";
            cin>>input;
        } else {                    //gets second amount, performs calculations, displays total
            cout<<"Enter in second amount "<<sillyType2<<": ";
            cin>>temp;
            input = performOperation(input, temp, op);
            cout<<"Total: "<<input<<" "<<sillyType<<endl;
        }
    }
}

//Handles the beggining of the program, gets what sillyType the user wants
int main() {
    //Initialize variables
    string silly, sillyType, sillyType2;

    //Welcome Screen
    cout<<"Silly Calculator App - Berger"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"Silly mode? (y/n): ";
    cin>>silly;

    switch (silly[0]) {
    case 'y':
        cout<<"Enter in the plural of your silly type.\nExamples: cats, capybaras, blobfishes, or anything"<<endl;
        cin.ignore();
        getline(cin, sillyType);     //gets sillyType
        sillyType2 = "of " + sillyType;     //Adds the word "of " before the string sillyType so when printing out the results it reads normally
        cout<<"Silly mode activated"<<endl;     //Teehee
        calculator(sillyType2, sillyType);      //Calls the function calculator with our sillyType with the "of " and without the "of " in front of it
    case 'n':
        calculator();
    default:
        cout<<"Invalid input"<<endl;
        break;
    }
    return 0;
}