#pragma once
#include <stdint.h>
typedef struct { float cabin_temp_c; uint8_t switch_bits; uint8_t actuator_percent; uint8_t actuator_state; uint16_t fault_flags; } lin_signals_t;
void signal_db_init(lin_signals_t *s);
void signal_db_decode(uint8_t id,const uint8_t *data,uint8_t len,lin_signals_t *s);
uint8_t signal_db_encode(uint8_t id,const lin_signals_t *s,uint8_t *data);