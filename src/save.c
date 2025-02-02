#include "save.h"

struct SaveBlock save_data;

void memcpy8(volatile unsigned char *dst, const volatile unsigned char *src, size_t length) {
    for (;length > 0;--length) *dst++ = *src++;
}

void memset8(volatile unsigned char *dst, unsigned char val, size_t length) {
    for (;length > 0;--length) *dst++ = val;
}

void init_sram() {
	flash_init(FLASH_SIZE_64KB);

	read_save_block();

	// Clear if magic is invalid or different save version
	if (save_data.magic != 0xdeadbeef || save_data.save_version != SAVE_VERSION) {
		memset32((u32*)&save_data, 0x00, sizeof(save_data) / 4);
		save_data.magic = 0xdeadbeef;
		save_data.save_version = SAVE_VERSION;
		write_save_block();
	}
}

void read_save_block() {
	flash_read(SAVE_BLOCK_ADDR, (u8*)&save_data, sizeof(save_data));
}

void write_save_block() {
	flash_write(SAVE_BLOCK_ADDR, (u8*)&save_data, sizeof(save_data));
}

struct SaveLevelData *obtain_level_data(u16 level_id) {
	return &save_data.saved_levels[level_id];
}

