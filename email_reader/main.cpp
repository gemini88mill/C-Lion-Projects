#include <iostream>
#include <stdio.h>
#include <Poco/Net/MailMessage.h>
#include <Poco/Net/MailRecipient.h>
#include <Poco/Net/SecureStreamSocket.h>            //some libs not downloaded
#include <Poco/Net/SMTPClientSession.h>
#include <Poco/Net/NetException.h>
#include <Poco/Net/Context.h>
#include <Poco/Net/SSLManager.h>
#include <Poco/Net/AcceptCertificateHandler.h>
#include <Poco/AutoPtr.h>

using namespace std;
using namespace Poco::Net;
using namespace Poco;

int main() {
    printf("Hello, World!");
    return 0;
}