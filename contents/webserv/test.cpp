#include <iostream>
#include "FTServer.hpp"

using std::cout;
using std::endl;

/*	template
#ifdef GROUND139
int main(void) {

	return 0;
}
#endif

*/

#define GROUND000
#ifdef GROUND000
int main(int argc, char* argv[]) {
    FTServer ftServer;

    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " <configuration file>" << endl;
        return 0;
    }

    ftServer.initParseConfig(argv[1]);
    ftServer.init();
    ftServer.run();

    return 0;
}
#endif
