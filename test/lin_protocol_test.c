#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../firmware/Inc/lin_protocol.h"
#include "../firmware/Inc/signal_db.h"
int main(void){
    assert(lin_make_pid(0x12U)==0x92U);
    assert(lin_validate_pid(lin_make_pid(0x22U))==0);
    uint8_t d[2]={0x34,0x12};uint8_t c=lin_checksum(d,2,lin_make_pid(0x22U),LIN_CHECKSUM_ENHANCED);assert(c==lin_checksum(d,2,lin_make_pid(0x22U),LIN_CHECKSUM_ENHANCED));
    lin_frame_t f={.id=0x13,.pid=lin_make_pid(0x13),.len=1,.data={55}};assert(lin_encode_frame(&f,LIN_CHECKSUM_ENHANCED)==0);
    uint8_t raw[4]={0x55,f.pid,55,f.checksum};lin_frame_t out={0};assert(lin_decode_frame(raw,sizeof(raw),LIN_CHECKSUM_ENHANCED,&out)==0);
    assert(out.id==0x13&&out.data[0]==55);
    puts("LIN protocol tests: PASS");return 0;
}