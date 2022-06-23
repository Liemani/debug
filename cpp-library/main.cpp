#include <iostream>
#include "LMI.hpp"

int main(void) {
    std::string string = "{\"firstName\": \"John\",\"lastName\": \"Smith\",\"isAlive\": true,\"age\": 27,\"address\": {\"streetAddress\": \"21 2nd Street\",\"city\": \"New York\",\"state\": \"NY\",\"postalCode\": \"10021-3100\",},\"phoneNumbers\": [{\"type\": \"home\",\"number\": \"212 555-1234\"},{\"type\": \"office\",\"number\": \"646 555-4567\"}],\"children\": [],\"spouse\": null}";

    LMI::describe(std::cout, string.c_str());

    return 0;
}
