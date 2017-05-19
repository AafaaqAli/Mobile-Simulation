#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int menu();
int calculator();
int notes();
int read_Contact();
int add_Contact();
int find_Contact();
int edit_Contact();
int delete_Contact();


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
    public:
        int choice() {
            int co_Choice;
            cout << "1-show Contacts, 2-Add Contact, 3-Find Contact, 4-Edit Contact, 5-delete Contact or any other key to go to main Menu: ";
            co_Choice = getch();
            switch(co_Choice){
                case 49:
                    read_Contact();
                    break;


                case 50:

                    add_Contact();
                    break;
                case 51:
                    //find_Contact();
                    getch();
                    break;
                case 52:
                    //edit_Contact();

                    cout << " Edit Contact" << endl;
                    getch();
                    break;

                case 53:
                     //delete_Contact();

                    cout << "Delete Contact" << endl;
                    getch();
                    break;

                default:
                    system("CLS");
                    return menu();
            }

        }
};

int read_Contact(){
    system("CLS");
    string STRING;
    ifstream contact_Output;
    contact_Output.open("contacts.ali", ios::in | ios::app | ios::binary);
    if(contact_Output.is_open()){
            while (getline(contact_Output, STRING)){
                cout << STRING << endl;
            }
            contact_Output.close();
            getch();
            system("CLS");

    }else{
        cout << "File is Not Associated" << endl;
        system("CLS");
        getch();
    }
}


int add_Contact(){
    system("CLS");
    string full_Name, first_Name, last_Name, phone, Address;
        cout << "First Name: ";
        getline(cin, first_Name);
        cout << "Last Name: ";
        getline(cin, last_Name);
        cout << "Address: ";
        getline(cin, Address);
        cout << "Phone Number: ";
        getline(cin, phone);
        while(phone.size() != 13 && phone.size() != 11){
            cout << "Invalid Number Type the Number again in the form of (+92312345678 or 03123456789)" << endl;
            getline(cin, phone);
        }
        system("CLS");
        cout << "Contact Has Been Saved" << endl;
        getch();
        system("CLS");
        full_Name = "(" + first_Name + ") " + last_Name;
        ofstream contact_data;
        contact_data.open("contacts.ali", ios::in | ios::app | ios::binary);
        if(contact_data.is_open()){
            contact_data << full_Name << ", " << Address << ", " << phone << endl;
            contact_data.close();
        }else{
            cout << "File is Not Associated " << endl;
        }

};


int find_Contact(){

}

class tools{
    public:

        int Choice() {
        int tool_choice;
        cout << "1-Calculator, 2-Notes: ";
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
            cout << "1-continue to Calculator or press any key to see Calculation History";
            his_Choice = getch();
            cout << "\n\n";
            if(his_Choice == 49){

                ofstream calculation;
                calculation.open ("Calculation.ali", ios::out | ios::app | ios::binary);

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
            calculation.open ("Calculation.ali", ios::out | ios::app | ios::binary);
            if(calculation.is_open()){


                    string STRING;
                    ifstream calculation_output("calculation.ali");
                    while (getline(calculation_output, STRING)){
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
        ofstream note("notes.ali", ios::in | ios::app | ios::binary);
        if(note.is_open()){
            system("CLS");
            cout  << "1-Add a note\n2-view Notes";
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
                cout << "1-Stay in note function or any key to go to main Menu: ";
                note_Choice = getch();
                if(note_Choice == 49){
                        system("CLS");
                        return notes();
                }else{
                    system("CLS");
                    }

              }else if(note_Choice == 50){
                    system("CLS");
                    ifstream notes("notes.ali", ios::in | ios::app | ios::binary);
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
        cout << "----------------------------------------------------------------" << endl;
        cout << "1-Messages,  2-Contacts,  3-Call history,  4-Tools,  ESC to Exit" << endl;
        cout << "----------------------------------------------------------------" << endl;
        choice = getch();
        if(choice == 49){
            cout << "Messages" << endl;
            }else if(choice == 50){
                system("CLS");
                Contacts co;
                co.choice();
                }else if(choice == 51){
                    cout << "Call History" << endl;
                    }else if(choice == 52){
                       to.Choice();

                        }else if(choice == 27){
                            system("CLS");
                            exit('0');
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
