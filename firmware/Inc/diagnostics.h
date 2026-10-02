#pragma once
#include <stdint.h>
typedef enum { DIAG_READ_STATUS=0x01, DIAG_READ_ERRORS=0x02, DIAG_CLEAR_ERRORS=0x03, DIAG_SET_ACTUATOR=0x10 } diag_cmd_t;
uint8_t diagnostics_handle(const uint8_t *req,uint8_t req_len,uint8_t *resp,uint8_t *resp_len,uint8_t *actuator_percent,uint16_t *fault_flags);