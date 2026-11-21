#include "ClientStateNetwork.hh"

ClientStateNetwork::ClientStateNetwork(const ClientPlatform &platform) : ClientState(platform, nullptr) {
    platform.socket.close();
}

ClientStateNetwork::~ClientStateNetwork() {}

bool ClientStateNetwork::needsSockets() {
    return true;
}