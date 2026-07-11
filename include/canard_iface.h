#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>

// include the canard C++ APIs
#include <canard/publisher.h>
#include <canard/subscriber.h>
#include <canard/service_client.h>
#include <canard/service_server.h>
#include <canard/handler_list.h>
#include <canard/transfer_object.h>

// include the base canard API
#include <canard.h>

#define MY_NODE_ID 12

class CanardInterface : public Canard::Interface {
    // friend class CANSimNode;
    CanardInterface(uint8_t index) : Interface(index_) {}
public:
    void init(const char *iface_name);
    // implement required interface functions
    bool broadcast(const Canard::Transfer &bcast_transfer) override;
    bool request(uint8_t dest_node_id, const Canard::Transfer &req_transfer);
    bool respond (uint8_t dest_node_id, const Canard::Transfer &res_transfer);
    uint8_t get_node_id() const override { return canard.node_id; };
    void set_node_id(uint8_t node_id) {
        canardSetLocalNodeID(&canard, node_id);
    }

    static void should_accept_transfer(const CanardInstance* inst,
                                       size_t* out_data_type_signature,
                                       uint16_t data_type_id,
                                       CanardTransferType transfer_type,
                                       uint8_t source_node_id);

private:
    uint8_t index_;
    uint8_t memory_pool[2048];
    CanardInstance canard;
    CanardTxTransfer tx_transfer;

    // serial_iface;
};

