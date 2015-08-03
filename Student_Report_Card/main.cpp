#include <iostream>
#include <fstream>


using namespace std;

/*Student Report Card - Program designed to make have the user enter in grades, notes, tests, quizzes and allows the
 *      user to see the grades in real time. The program should set up with areas to save information to be used at
 *      a later date. 05.06.15
 *
 *      main() function - chronological order for program
 *          - start program.
 *          - start login information (once core program is complete)
 *          - user menu1 (class directory)
 *          - menu for grades notes blah blah blah.
 *
 *     Core program - level 1
 *          -basic spreadsheet of grades with area for notes and weighted averages, facts and figures for user. */

void create_student(string student_name);

void read_student(string student_name);

void delete_student();

void update_student(string student_name);

int main_UI();

int menu_switch(int i, string student_name);

struct student_data{
    string student_name;
    ofstream student_file;
}student_data;

int main() {
    int choice;


    while (choice != 5) {
        choice = main_UI();
        menu_switch(choice, student_data.student_name);
    }

    return 0;
}

int main_UI() {
    //user interface for program.

    int selection;

    cout << "what would you like to do? " << endl;
    cout << "1. create a student " << endl;
    cout << "2. view students" << endl;
    cout << "3. delete student" << endl;
    cout << "4. edit student" << endl;
    cout << "5. quit program" << endl;
    cout << "selection: ";
    cin >> selection;

    return selection;
}

int menu_switch(int i, string student_name) {



        switch (i) {
            case 1:
                create_student(student_name);
                break;
            case 2:
                read_student(student_name);
                break;
            case 3:
                delete_student();
                break;
            case 4:
                update_student(student_name);
                break;
        }


    return 0;
}


/*core program functions, allows for crud interface to work. accessed through menu_switch() function*/
void create_student(string student_name) {
    cout << "" << endl;


    student_data.student_file.open("student_names.txt");

    while (student_name != "quit") {
        cin >> student_name;
        student_data.student_file << student_name + "\n";
    }

    student_data.student_file.close();
}

void read_student(string student_name) {
    string line;

    ifstream student_file ("student_names.txt");
    if (student_file.is_open()){
        while (getline (student_file, line)){
            cout << line << endl;
        }
        student_file.close();
    } else cout << "Unable to open file" << endl;

}

void update_student(string student_name) {
    cout << "in update_student" << endl;
    read_student(student_name);


}

void delete_student() {
    cout << "in delete_student" << endl;
}

