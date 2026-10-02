#include "signal_db.h"
void signal_db_init(lin_signals_t*s){if(!s)return;*s=(lin_signals_t){0,0,0,0,0};}
void signal_db_decode(uint8_t id,const uint8_t*d,uint8_t n,lin_signals_t*s){
    if(!d||!s)return;
    if(id==0x12U&&n>=1U)s->switch_bits=d[0];
    else if(id==0x13U&&n>=1U)s->actuator_percent=d[0]>100U?100U:d[0];
}
uint8_t signal_db_encode(uint8_t id,const lin_signals_t*s,uint8_t*d){
    if(!s||!d)return 0;
    if(id==0x22U){int v=(int)(s->cabin_temp_c*100.0f);d[0]=(uint8_t)(v>>8);d[1]=(uint8_t)v;return 2;}
    if(id==0x23U){d[0]=s->actuator_state;return 1;}
    if(id==0x24U){d[0]=(uint8_t)(s->fault_flags>>8);d[1]=(uint8_t)s->fault_flags;return 2;}
    return 0;
}