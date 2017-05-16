#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int calculator();
int notes();


class Messages{
    private:
       string inbox_messages[500];
       string outbox_messages[500];
       string draft_messages[500];
       string template_messages[50];
       string sent_messages[500];

    public:

};

class CallHistory{
    private:

    public:

};

class Contacts{
    private:
       string contacts[1000];
    public:

};

class tools{
    public:

        int Choice() {
        int tool_choice;
        cout << "Type 1 for Calculator Or 2 for Notes: ";
        tool_choice = getch();
        if(tool_choice == 49){
            calculator();
        }else if(tool_choice == 50){
            notes();
            }else{
                cout << "Invalid Choice" << endl;
                system("CLS");
            }

    }
};
        int calculator(){
            int his_Choice;
            float first_Number, second_Number, answer, choice, sub_Choice;
            system("CLS");
            cout << "Type 1 to continue to Calculator or press any key to see Calculation History";
            his_Choice = getch();
            cout << "\n\n";
            if(his_Choice == 49){

                ofstream calculation;
                calculation.open ("Calculation.txt", ios::out | ios::app | ios::binary);

                cout << "Type first Number: ";
                cin >> first_Number;
                cout << "Type Second Number: ";
                cin >> second_Number;
                cout << "1 to add, 2 to Multiply, 3 to Subtract, 4 to divide" << endl;
                choice = getch();

                if(choice == 49){
                    system("CLS");
                    cout << "The Sum is: " << first_Number + second_Number << endl;
                    calculation << first_Number + second_Number << endl;
                    cout << "\nPress exit to go to main menu or any key to continue Using Calculator: ";
                    sub_Choice = getch();
                        if(sub_Choice == 27){
                            system("CLS");
                                }else{
                                    system("CLS");
                                    return calculator();
                                }


                    }else if(choice == 50){
                        system("CLS");
                        cout << "The Multiplication is: " << first_Number * second_Number << endl;
                        calculation << first_Number * second_Number << endl;
                         cout << "\nPress exit to go to main menu or any key to continue Using Calculator: ";
                        sub_Choice = getch();
                        if(sub_Choice == 27){
                            system("CLS");
                                }else{
                                    system("CLS");
                                    return calculator();

                                }

                        }else if(choice == 51){
                            system("CLS");
                            cout << "The Subtraction is: " << first_Number - second_Number << endl;
                            calculation << first_Number - second_Number << endl;
                            cout << "\nPress exit to go to main menu or any key to continue Using Calculator: ";
                            sub_Choice = getch();
                            if(sub_Choice == 27){
                                system("CLS");
                                }else{
                                    system("CLS");
                                    return calculator();

                                }
                            }else if(choice == 52){
                                system("CLS");
                                cout << "The Division is: " << first_Number / second_Number << endl;
                                calculation << first_Number / second_Number << endl;
                                cout << "\nPress exit to go to main menu or any key to continue Using Calculator: ";
                                sub_Choice = getch();

                                if(sub_Choice == 27){
                                    system("CLS");
                                    calculation.close();


                                }else{
                                    system("CLS");
                                    return calculator();

                                }
                }else {
                    cout << "Invalid choice.";
                    getch();
                    system("CLS");
                    return calculator();

                }
        }else{
            ofstream calculation;
            calculation.open ("Calculation.txt", ios::out | ios::app | ios::binary);
            if(calculation.is_open()){


                    string STRING;
                    ifstream calculation_output("calculation.txt");
                    while (std::getline(calculation_output, STRING)){
                            cout << STRING << endl;
                        }
                    calculation_output.close();
                    cout << "\nPress exit to go to main menu or any key to continue Using Calculator: ";
                    sub_Choice = getch();
                        if(sub_Choice == 27){
                            system("CLS");
                                }else{
                                    system("CLS");
                                    return calculator();

                                }

            }else{
                cout << "File is not open";
            }
        }
}


    int notes() {
        int note_Choice;
        string input_String;
        ofstream note("notes.txt", ios::in | ios::app | ios::binary);
        if(note.is_open()){
            system("CLS");
            cout  << "Press 1 to Add a note And 2 to view Notes: ";
            note_Choice = getch();
            if(note_Choice == 49){
                system("CLS");
                cout << "Type the Note: ";
                getline(cin, input_String);
                note << input_String + "\n\n";
                system("ClS");
                cout << "The Note have been saved" << endl;
                note.close();
                getch();
                system("CLS");
                cout << "Press 1 to stay in note function press any key to go to main Menu: ";
                note_Choice = getch();
                if(note_Choice == 49){
                        system("CLS");
                        return notes();
                }else{
                    system("CLS");
                    }

              }else if(note_Choice == 50){
                    system("CLS");
                    ifstream notes("notes.txt", ios::in | ios::app | ios::binary);
                    string line;
                    while(getline(notes, line)){
                        cout << line << endl;
                    }
                    getch();
                    system("CLS");

              }

            }else {
                cout << "The File is not Associated" << endl;
            }
        }



int menu() {
    tools to;
    int choice;
    while(choice != 27){
        cout << "------------------------------------------------------------" << endl;
        cout << "1 for Messages 2 for Contacts 3 for Call history 4 for Tools" << endl;
        cout << "-------------------------------------------------------------" << endl;
        choice = getch();
        if(choice == 49){
            cout << "Messages" << endl;
            }else if(choice == 50){
                cout << "Contacts" << endl;
                }else if(choice == 51){
                    cout << "Call History" << endl;
                    }else if(choice == 52){
                       to.Choice();

                        }else {
                            cout << "Invalid Number." << endl;
                            getch();
                            system("CLS");
                            return menu();
                        }

    }

}



int main() {
    menu();
}
