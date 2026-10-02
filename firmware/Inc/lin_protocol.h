#pragma once
#include <stddef.h>
#include <stdint.h>

typedef enum { LIN_CHECKSUM_CLASSIC=0, LIN_CHECKSUM_ENHANCED=1 } lin_checksum_mode_t;
typedef struct { uint8_t id; uint8_t pid; uint8_t data[8]; uint8_t len; uint8_t checksum; } lin_frame_t;

uint8_t lin_make_pid(uint8_t id);
int lin_validate_pid(uint8_t pid);
uint8_t lin_checksum(const uint8_t *data, uint8_t len, uint8_t pid, lin_checksum_mode_t mode);
int lin_encode_frame(lin_frame_t *frame, lin_checksum_mode_t mode);
int lin_decode_frame(const uint8_t *raw, size_t len, lin_checksum_mode_t mode, lin_frame_t *out);