#include <iostream>
#include <sstream>
#include <cmath>
#include "LMI.hpp"

using std::cout;
using std::endl;
using namespace LMI;

int main(void) {
    std::string stringToDescribe;

    std::string jsonCString = "{\"firstName\": \"John\",\"lastName\": \"Smith\",\"isAlive\": true,\"age\": 27,\"address\": {\"streetAddress\": \"21 2nd Street\",\"city\": \"New York\",\"state\": \"NY\",\"postalCode\": \"10021-3100\",},\"phoneNumbers\": [{\"type\": \"home\",\"number\": \"212 555-1234\"},{\"type\": \"office\",\"number\": \"646 555-4567\"}],\"children\": [],\"spouse\": null}";
    JSONDescriber::describe(cout, jsonCString);
    cout << endl;

    cout << endl;
    const char charArray[] = { 'a', 'b', 'c' };
    WrapArray<const char> charWrapArray(charArray, 3);
    stringToDescribe = debugDescription(charWrapArray);
    JSONDescriber::describe(cout, stringToDescribe);
    cout << endl;

    cout << endl;
    const WrapChar wrapCharArray[] = { 'd', 'e', 'f' };
    WrapArray<const WrapChar> wrapWrapCharArray(wrapCharArray, 3);
    stringToDescribe = debugDescription(wrapWrapCharArray);
    JSONDescriber::describe(cout, stringToDescribe);
    cout << endl;

    cout << endl;
    const char* cStrings[] = { "ab", "bc", "cd" };
    WrapArray<const char*> cStringArray(cStrings, 3);
    stringToDescribe = debugDescription(cStringArray);
    JSONDescriber::describe(cout, stringToDescribe);
    cout << endl;

    cout << endl;
    const double doubleArray[] = { 1.2, 12.34, HUGE_VAL, 0, NAN };
    WrapArray<double> wrapDoubleArray(doubleArray, 5);
    stringToDescribe = debugDescription(wrapDoubleArray);
    JSONDescriber::describe(cout, stringToDescribe);
    cout << endl;

    return 0;
}
