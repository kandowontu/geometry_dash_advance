#include <tonc.h>
#include "../levels/includes.h"
#include "libsavgba/gba_flash.h"

#pragma once

#define SAVE_BLOCK_ADDR 0
#define SAVE_VERSION 1

struct SaveLevelData {
    u8 completed;
    u8 normal_progress;
    u8 practice_progress;
    u8 coin1;
    u8 coin2;
    u8 coin3;
    u32 attempts;
    u32 jumps;
};

struct SaveBlock {
    u32 magic;
    u32 save_version;
    u16 cube_selected;
    u16 ship_selected;
    u16 ball_selected;
    u16 ufo_selected;
    u16 wave_selected;

    struct SaveLevelData saved_levels[LEVEL_COUNT];
};

extern struct SaveBlock save_data;

void memcpy8(volatile unsigned char *dst, const volatile unsigned char *src, size_t length);
void memset8(volatile unsigned char *dst, unsigned char val, size_t length);
void init_sram();
void read_save_block();
void write_save_block();

struct SaveLevelData *obtain_level_data(u16 level_id);