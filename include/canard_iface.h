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

// we are using the socketcan driver
#include <socketcan.h>

// include the headers for the generated DroneCAN messages from the
// dronecan_dsdlc compiler>
#include <dronecan_msgs.h>

#define MY_NODE_ID 12

