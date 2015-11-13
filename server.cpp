#include "XmlRpc.h"
#include <iostream>
using namespace XmlRpc;

// The server
XmlRpcServer s;

// The Hello method. No arguments, result is "Hello".
class Hello : public XmlRpcServerMethod
{
public:
  Hello(XmlRpcServer* s) : XmlRpcServerMethod("Hello", s) {}

  void execute(XmlRpcValue& params, XmlRpcValue& result)
  {
    result = "Hello";
  }

} hello(&s);    // This constructor registers the method with the server

class Bye : public XmlRpcServerMethod
{
public:
  Bye(XmlRpcServer * s) : XmlRpcServerMethod("Bye", s) {}

  void execute(XmlRpcValue& params, XmlRpcValue& result)
  {
    result = "Bye";
  }
} bye(&s);

// The port to use
const int PORT = 8080;

int main(int argc, char* argv[]) {

  // Create the server socket on the specified port
  s.bindAndListen(PORT);

  // Wait for requests and process indefinitely (Ctrl-C to exit)
  s.work(-1.0);

  return 0;
}
