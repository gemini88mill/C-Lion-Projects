#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <error.h>






using namespace std;

/*Email Reader:
 * This program is designed to make a program read emails from any domain and display them from the command line.
 * the basic structure should work just like a normal email program run from a phone or generic email system.
 *
 * Structure is as follows:
 *  - ask user for credentials: username, password, POP3 or IMAP, etc.
 *  - ask user for push notification settings
 *  - display email without graphics in a command line format. */

//no globals
//current soundtrack: Vangelis - Bladerunner Soundtrack.

struct sockaddr_in server;
struct hostent *hp, *gethostbyname();
char *host_id = "smtp.gmail.com";

void user_defined_email_cred(string *email, string *pString, string *pBasic_string, string *pBasicString,
                             int *pInt); //email credential function
int menu();                     //main menu for email client

int main() {

    //---Variables---
    string password, server, security_type;
    string email;
    int port;

    user_defined_email_cred(&email, &password, &server, &security_type, &port);


    //debug center---------
    cout << email << endl;
    cout << password << endl;
    cout << server << endl;
    cout << security_type << endl;
    cout << port << endl;
    //--------------------



    return 0;
}

void send_email() {
    /*gather_email_data: function to gather information related to the menu. ex. number of emails, with or without
     * attachments, handling of all incoming requests. If i understand correctly:
     *
     *      1. User credentials verified
     *      2. use socket communication to gather information.
     *          - Create a socket with the socket() system call
     *          - Connect the socket to the address of the server using the connect() system call.
     *          - send and receive data. using read() and write() system calls.
     *      3. send back to main().
     *
     *      need a little more understanding on how sockets work in order to fully implement code. 05.05.15
     *          Happy Cinco de Mayo.
     *
     ****Trying to understand cMake is giving me a headache, going to shelf the project for now and come back once
     * I get a better grasp of sockets, and cMake. 05.06.15*** */



    //verify host.


}

void receive_mail(){

}

int menu() {

    /*Starting Menu for program (once credentials have been input)*/

    int choice;

    cout << "------Email Client-----" << endl;
    cout << "- 1. Compose          -" << endl;
    cout << "- 2. Inbox            -" << endl;
    cout << "- 3. Sent             -" << endl;
    cout << "- 4. Spam             -" << endl;
    cout << "-----------------------" << endl;

    cin >> choice;

    return choice;
}

void user_defined_email_cred(string *pEmail, string *pString, string *pBasic_string, string *pBasicString, int *pInt) {

    /*user_defined_email_cred():
     *  description:
     *      - Accepts 4 strings and an int to that point to variables in the main function in order to save email
     *      credentials for future use and login information for the program.
     *      -void function, only points to corresponding variables in the main function.
     *      -points to (in order): string email, password, server, security_type, int port*/

    cout << "Email Address: " << endl;
    cin >> *pEmail;

    cout << "Password: " << endl;
    cin >> *pString;

    /* cout << "server type: (IMAP or POP3)" << endl;
     cin >> *pBasic_string;

     cout << "security type: " << endl;
     cin >> *pBasicString;

     cout << "port: " << endl;
     cin >> *pInt;*/

}