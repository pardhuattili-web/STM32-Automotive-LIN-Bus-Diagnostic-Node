#!/usr/bin/env python3
def pid(frame_id):
    i=frame_id&0x3f
    p0=((i>>0)^(i>>1)^(i>>2)^(i>>4))&1
    p1=(~((i>>1)^(i>>3)^(i>>4)^(i>>5)))&1
    return i|(p0<<6)|(p1<<7)

def checksum(data,pid_value,enhanced=True):
    total=pid_value if enhanced else 0
    for b in data:
        total+=b
        if total>255: total=(total&255)+1
    return (~total)&255

if __name__=="__main__":
    fid=0x13; p=pid(fid); data=[65]; c=checksum(data,p)
    print(f"LIN demo: ID=0x{fid:02X} PID=0x{p:02X} DATA={data} CHECKSUM=0x{c:02X}")