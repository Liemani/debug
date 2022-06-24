#include <iostream>
#include <sstream>
#include "LMI.hpp"

using std::cout;
using std::endl;
using std::string;
using namespace LMI;

int main(void) {
    string jsonCString = "{\"firstName\": \"John\",\"lastName\": \"Smith\",\"isAlive\": true,\"age\": 27,\"address\": {\"streetAddress\": \"21 2nd Street\",\"city\": \"New York\",\"state\": \"NY\",\"postalCode\": \"10021-3100\",},\"phoneNumbers\": [{\"type\": \"home\",\"number\": \"212 555-1234\"},{\"type\": \"office\",\"number\": \"646 555-4567\"}],\"children\": [],\"spouse\": null}";
    describe(cout, jsonCString.c_str());
    cout << endl;

    cout << endl;
    const char charArray[] = { 'a', 'b', 'c' };
    WrapArray<const char> charWrapArray(charArray, 3);
    std::ostringstream oss;
    debugDescription(oss, charWrapArray);
    describe(cout, oss.str());
    cout << endl;

    cout << endl;
    const WrapChar wrapCharArray[] = { 'd', 'e', 'f' };
    WrapArray<const WrapChar> wrapWrapCharArray(wrapCharArray, 3);
    oss.str(string());
    debugDescription(oss, wrapWrapCharArray);
    describe(cout, oss.str());
    cout << endl;

    cout << endl;
    const char* cStrings[] = { "ab", "bc", "cd" };
    WrapArray<const char*> cStringArray(cStrings, 3);
    oss.str(string());
    debugDescription(oss, cStringArray);
    describe(cout, oss.str());
    cout << endl;

    return 0;
}
