#pragma once

#include "portable/online/ClientState.hh"

class ClientStateNetwork
    : public ClientState
    , public ClientState::Reader<ClientStateNetwork>
    , public ClientState::Writer<ClientStateNetwork>
    , public ServerStateReader<ClientStateNetwork>
    , public ServerStateModeReader<ClientStateNetwork>
    , public ClientStateWriter<ClientStateNetwork>::Network
    , public ClientStateModeWriter<ClientStateNetwork> {
public:
    ClientStateNetwork(const ClientPlatform &platform);
    ~ClientStateNetwork() override;
    bool needsSockets() override;
    ClientState &read(ClientReadHandler &handler) override;
    ClientState &write(const ClientStateIdleWriteInfo &writeInfo) override;
    ClientState &write(const ClientStateServerWriteInfo &writeInfo) override;
    ClientState &write(const ClientStateRoomWriteInfo &writeInfo) override;
};
