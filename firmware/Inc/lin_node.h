#pragma once
#include <stdint.h>
#include "signal_db.h"
typedef enum { LIN_NODE_IDLE, LIN_NODE_HEADER, LIN_NODE_RESPONSE, LIN_NODE_ERROR } lin_node_state_t;
typedef struct { lin_node_state_t state; uint32_t rx_errors; uint32_t timeout_errors; lin_signals_t signals; uint8_t fault_injection; } lin_node_t;
void lin_node_init(lin_node_t *node);
void lin_node_on_frame(lin_node_t *node,uint8_t id,const uint8_t *data,uint8_t len);