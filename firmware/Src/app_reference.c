#include "lin_protocol.h"
#include "lin_node.h"
void lin_reference_step(void){
    lin_node_t node;lin_node_init(&node);
    uint8_t raw_data[1]={65U};lin_frame_t frame={.id=0x13U,.pid=lin_make_pid(0x13U),.len=1U,.data={65U}};
    (void)lin_encode_frame(&frame,LIN_CHECKSUM_ENHANCED);
    lin_node_on_frame(&node,0x13U,raw_data,1U);
}