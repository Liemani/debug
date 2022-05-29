#include <iostream>
#include "FTServer.hpp"

using std::cout;
using std::endl;

const int portNumber = 81;

void FTServer_init(FTServer& ftServer);
VirtualServer* VirtualServer_new(void);
Location* Location_new(void);

int main(int argc, char* argv[]) {
    FTServer ftServer;

    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " <configuration file>" << endl;
        return 0;
    }
    else
        ftServer.initParseConfig(argv[1]);

    FTServer_init(ftServer);
    ftServer.run();

    return 0;
}

void FTServer_init(FTServer& ftServer) {
    FTServer_init(ftServer);
    ftServer._kqueue = kqueue();
    std::set<port_t> portsOpen;
    portsOpen.insert(portNumber);
    ftServer.initializeConnection(portsOpen, portsOpen.size());
}

void FTServer_init(FTServer& ftServer) {
    ftServer.appendVirtualServer(*VirtualServer_new());
}

VirtualServer* VirtualServer_new(void) {
    VirtualServer* newVirtualServer = new VirtualServer(portNumber, "localhost");
    newVirtualServer->appendLocation(Location_new());

    return newVirtualServer;
}

Location* Location_new(void) {
    Location* newLocation = new Location();

    newLocation->setRoute("/");
    newLocation->setRoot("/Users/bagjeonghun/git/debug/contents/webserv");
    newLocation->setAutoIndex(true);

    return newLocation;
}
