#include "diagnostics.h"
uint8_t diagnostics_handle(const uint8_t*r,uint8_t n,uint8_t*out,uint8_t*out_n,uint8_t*a,uint16_t*f){
    if(!r||!out||!out_n||!a||!f||n==0U)return 1U;
    *out_n=2U;out[0]=r[0];out[1]=0U;
    switch(r[0]){
      case DIAG_READ_STATUS: out[1]=0U;break;
      case DIAG_READ_ERRORS: out[1]=(uint8_t)(*f?1U:0U);break;
      case DIAG_CLEAR_ERRORS:*f=0U;break;
      case DIAG_SET_ACTUATOR: if(n<2U||r[1]>100U){out[1]=1U;break;}*a=r[1];break;
      default: out[1]=0x7FU;break;
    }
    return 0U;
}