#include "lin_protocol.h"

uint8_t lin_make_pid(uint8_t id){
    id &= 0x3FU;
    uint8_t p0=((id>>0)^(id>>1)^(id>>2)^(id>>4))&1U;
    uint8_t p1=(~((id>>1)^(id>>3)^(id>>4)^(id>>5)))&1U;
    return (uint8_t)(id|(p0<<6)|(p1<<7));
}
int lin_validate_pid(uint8_t pid){ return lin_make_pid(pid&0x3FU)==pid ? 0 : -1; }

uint8_t lin_checksum(const uint8_t *data,uint8_t len,uint8_t pid,lin_checksum_mode_t mode){
    uint16_t sum=0;
    if(mode==LIN_CHECKSUM_ENHANCED) sum+=pid;
    for(uint8_t i=0;i<len;i++){sum+=data[i];if(sum>255U)sum=(sum&0xFFU)+1U;}
    return (uint8_t)(~sum);
}
int lin_encode_frame(lin_frame_t*f,lin_checksum_mode_t mode){
    if(!f||f->len>8U||lin_validate_pid(f->pid)!=0)return -1;
    f->checksum=lin_checksum(f->data,f->len,f->pid,mode); return 0;
}
int lin_decode_frame(const uint8_t*raw,size_t n,lin_checksum_mode_t mode,lin_frame_t*out){
    if(!raw||!out||n<3U||n>10U)return -1;
    if(lin_validate_pid(raw[1])!=0)return -2;
    out->pid=raw[1];out->id=raw[1]&0x3FU;out->len=(uint8_t)(n-3U);
    for(uint8_t i=0;i<out->len;i++)out->data[i]=raw[2U+i];
    out->checksum=raw[n-1U];
    return lin_checksum(out->data,out->len,out->pid,mode)==out->checksum?0:-3;
}