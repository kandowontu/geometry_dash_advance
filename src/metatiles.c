#include "metatiles.h"
#include "collision.h"

#define Metatile(name, top_left_tile, top_right_tile, bottom_left_tile, bottom_right_tile, collision_type) {top_left_tile, top_right_tile, bottom_left_tile, bottom_right_tile, collision_type},

#define TILE(id, PALBANK, hflip, vflip) SE_BUILD(id, PALBANK, hflip, vflip)

#define H 1
#define V 1

#define LBG_PAL 2
#define COL1_PAL 3
#define COL2_PAL 4
#define COL3_PAL 5
#define COL4_PAL 6
#define PLAYER_PAL 7

// Goes like this TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT, COL_TYPE

// i hate this
//-banana 03/22/2025
const SCR_ENTRY metatiles[][5] = {
    Metatile("AIR",            TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("SPIKE_UP",       TILE(0x53, 0, 0, 0), TILE(0x54, 0, 0, 0), TILE(0x55, 0, 0, 0), TILE(0x56, 0, 0, 0), COL_SPIKE_TOP)
    Metatile("BASIC_BLOCK",    TILE(0x0e, 0, 0, 0), TILE(0x0f, 0, 0, 0), TILE(0x10, 0, 0, 0), TILE(0x11, 0, 0, 0), COL_FULL)
    
    Metatile("CHK_FULL",       TILE(0x01, 0, 0, 0), TILE(0x01, 0, H, 0), TILE(0x01, 0, 0, V), TILE(0x01, 0, H, V), COL_FULL)
    Metatile("CHK_SIDE_UP",    TILE(0x02, 0, 0, 0), TILE(0x02, 0, H, 0), TILE(0x03, 0, 0, 0), TILE(0x03, 0, H, 0), COL_FULL)
    Metatile("CHK_SIDE_DOWN",  TILE(0x03, 0, 0, V), TILE(0x03, 0, H, V), TILE(0x02, 0, 0, V), TILE(0x02, 0, H, V), COL_FULL)
    Metatile("CHK_SIDE_LEFT",  TILE(0x04, 0, 0, 0), TILE(0x05, 0, 0, 0), TILE(0x04, 0, 0, V), TILE(0x05, 0, 0, V), COL_FULL)
    Metatile("CHK_SIDE_RIGHT", TILE(0x05, 0, H, 0), TILE(0x04, 0, H, 0), TILE(0x05, 0, H, V), TILE(0x04, 0, H, V), COL_FULL)
    Metatile("CHK_CORNER_TL",  TILE(0x06, 0, 0, 0), TILE(0x02, 0, H, 0), TILE(0x04, 0, 0, V), TILE(0x07, 0, 0, 0), COL_FULL)
    Metatile("CHK_CORNER_TR",  TILE(0x02, 0, 0, 0), TILE(0x06, 0, H, 0), TILE(0x07, 0, H, 0), TILE(0x04, 0, H, V), COL_FULL)
    Metatile("CHK_CORNER_BL",  TILE(0x04, 0, 0, 0), TILE(0x07, 0, 0, V), TILE(0x06, 0, 0, V), TILE(0x02, 0, H, V), COL_FULL)
    Metatile("CHK_CORNER_BR",  TILE(0x07, 0, H, V), TILE(0x04, 0, H, 0), TILE(0x02, 0, 0, V), TILE(0x06, 0, H, V), COL_FULL)
    Metatile("CHK_CRN_INS_TL", TILE(0x08, 0, 0, 0), TILE(0x05, 0, 0, 0), TILE(0x03, 0, 0, 0), TILE(0x09, 0, 0, 0), COL_FULL)
    Metatile("CHK_CRN_INS_TR", TILE(0x05, 0, H, 0), TILE(0x08, 0, H, 0), TILE(0x09, 0, H, 0), TILE(0x03, 0, H, 0), COL_FULL)
    Metatile("CHK_CRN_INS_BL", TILE(0x03, 0, 0, V), TILE(0x09, 0, 0, V), TILE(0x08, 0, 0, V), TILE(0x05, 0, 0, V), COL_FULL)
    Metatile("CHK_CRN_INS_BR", TILE(0x09, 0, H, V), TILE(0x03, 0, H, V), TILE(0x05, 0, H, V), TILE(0x08, 0, H, V), COL_FULL)
    Metatile("CHK_DB_CRN_TOP", TILE(0x06, 0, 0, 0), TILE(0x06, 0, H, 0), TILE(0x04, 0, 0, V), TILE(0x04, 0, H, V), COL_FULL)
    Metatile("CHK_DB_CRN_BOT", TILE(0x04, 0, 0, 0), TILE(0x04, 0, H, 0), TILE(0x06, 0, 0, V), TILE(0x06, 0, H, V), COL_FULL)
    Metatile("CHK_DB_CRN_LFT", TILE(0x06, 0, 0, 0), TILE(0x02, 0, H, 0), TILE(0x06, 0, 0, V), TILE(0x02, 0, H, V), COL_FULL)
    Metatile("CHK_DB_CRN_RGT", TILE(0x02, 0, 0, 0), TILE(0x06, 0, H, 0), TILE(0x02, 0, 0, V), TILE(0x06, 0, H, V), COL_FULL)
    Metatile("CHK_DB_SIDE_V",  TILE(0x04, 0, 0, 0), TILE(0x04, 0, H, 0), TILE(0x04, 0, 0, V), TILE(0x04, 0, H, V), COL_FULL)
    Metatile("CHK_DB_SIDE_H",  TILE(0x02, 0, 0, 0), TILE(0x02, 0, H, 0), TILE(0x02, 0, 0, V), TILE(0x02, 0, H, V), COL_FULL)
    Metatile("CHK_FILLER",     TILE(0x0a, 0, 0, 0), TILE(0x0a, 0, H, 0), TILE(0x0a, 0, 0, V), TILE(0x0a, 0, H, V), COL_NONE)
    
    Metatile("SPIKE_DOWN",         TILE(0x55, 0, 0, V), TILE(0x56, 0, 0, V), TILE(0x53, 0, 0, V), TILE(0x54, 0, 0, V), COL_SPIKE_BOTTOM)
    Metatile("SPIKE_RIGHT",        TILE(0x57, 0, 0, 0), TILE(0x58, 0, 0, 0), TILE(0x59, 0, 0, 0), TILE(0x5a, 0, 0, 0), COL_SPIKE_LEFT)
    Metatile("SPIKE_LEFT",         TILE(0x58, 0, H, 0), TILE(0x57, 0, H, 0), TILE(0x5a, 0, H, 0), TILE(0x59, 0, H, 0), COL_SPIKE_RIGHT)
    Metatile("SMALL_SPIKE_BOTTOM", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x5b, 0, 0, 0), TILE(0x5c, 0, 0, 0), COL_SMALL_SPIKE_BOTTOM)
    Metatile("SMALL_SPIKE_TOP",    TILE(0x5b, 0, 0, V), TILE(0x5c, 0, 0, V), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SMALL_SPIKE_TOP)
    Metatile("SMALL_SPIKE_LEFT",  TILE(0x5d, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x5e, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SMALL_SPIKE_LEFT)
    Metatile("SMALL_SPIKE_RIGHT",   TILE(0x00, 0, 0, 0), TILE(0x5d, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x5e, 0, H, 0), COL_GROUND_SPIKE_RIGHT)
    Metatile("GROUND_SPIKE_BOTTOM",TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x5f, 0, 0, 0), TILE(0x60, 0, 0, 0), COL_GROUND_SPIKE_BOTTOM)
    Metatile("GROUND_SPIKE_TOP",   TILE(0x5f, 0, 0, V), TILE(0x60, 0, 0, V), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_GROUND_SPIKE_TOP)
    Metatile("GROUND_SPIKE_LEFT", TILE(0x61, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x62, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_GROUND_SPIKE_LEFT)
    Metatile("GROUND_SPIKE_RIGHT",  TILE(0x00, 0, 0, 0), TILE(0x61, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x62, 0, H, 0), COL_SMALL_SPIKE_RIGHT)
    Metatile("MEDIUM_SPIKE_BOTTOM",TILE(0x63, 0, 0, 0), TILE(0x63, 0, H, 0), TILE(0x64, 0, 0, 0), TILE(0x65, 0, 0, 0), COL_MEDIUM_SPIKE_BOTTOM)
    Metatile("MEDIUM_SPIKE_TOP",   TILE(0x64, 0, 0, V), TILE(0x65, 0, 0, V), TILE(0x63, 0, 0, V), TILE(0x63, 0, H, V), COL_MEDIUM_SPIKE_TOP)
    Metatile("MEDIUM_SPIKE_LEFT", TILE(0x67, 0, 0, 0), TILE(0x66, 0, 0, 0), TILE(0x68, 0, 0, 0), TILE(0x66, 0, 0, V), COL_MEDIUM_SPIKE_LEFT)
    Metatile("MEDIUM_SPIKE_RIGHT",  TILE(0x66, 0, H, 0), TILE(0x67, 0, H, 0), TILE(0x66, 0, H, V), TILE(0x68, 0, H, 0), COL_MEDIUM_SPIKE_RIGHT)
    
    Metatile("CHK_CORNER_TL", TILE(0x0B, 0, 0, 0), TILE(0x05, 0, 0, 0), TILE(0x03, 0, 0, 0), TILE(0x09, 0, 0, 0), COL_NONE)
    Metatile("CHK_CORNER_TR", TILE(0x05, 0, H, 0), TILE(0x0B, 0, H, 0), TILE(0x09, 0, H, 0), TILE(0x03, 0, H, 0), COL_NONE)
    Metatile("CHK_CORNER_BL", TILE(0x03, 0, 0, V), TILE(0x09, 0, 0, V), TILE(0x0B, 0, 0, V), TILE(0x05, 0, 0, V), COL_NONE)
    Metatile("CHK_CORNER_BR", TILE(0x09, 0, H, V), TILE(0x03, 0, H, V), TILE(0x05, 0, H, V), TILE(0x0B, 0, H, V), COL_NONE)
    
    Metatile("BASIC_BLOCK_DARK", TILE(0x26, 0, 0, 0), TILE(0x27, 0, 0, 0), TILE(0x28, 0, 0, 0), TILE(0x29, 0, 0, 0), COL_FULL)
    
    Metatile("SLAB_UP",            TILE(0x4e, 0, 0, 0), TILE(0x4f, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SLAB_TOP)
    Metatile("SLAB_DOWN",          TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x4e, 0, 0, V), TILE(0x4f, 0, 0, V), COL_SLAB_BOTTOM)
    Metatile("SLAB_LEFT",          TILE(0x50, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x51, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("SLAB_RIGHT",         TILE(0x00, 0, 0, 0), TILE(0x50, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x51, 0, H, 0), COL_NONE)
    Metatile("SLAB_DOWN_FLIPPED",  TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x4e, 0, 0, 0), TILE(0x4f, 0, 0, 0), COL_SLAB_BOTTOM)

    Metatile("GROUND_WAVY_SPIKE_BOTTOM",TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x6f, 0, 0, 0), TILE(0x6f, 0, 0, 0), COL_GROUND_WAVY_SPIKE_BOTTOM) // 0x30
    Metatile("GROUND_WAVY_SPIKE_TOP",   TILE(0x6f, 0, 0, V), TILE(0x6f, 0, 0, V), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_GROUND_WAVY_SPIKE_TOP)
    Metatile("GROUND_WAVY_SPIKE_LEFT",  TILE(0x76, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x76, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_GROUND_WAVY_SPIKE_LEFT)
    Metatile("GROUND_WAVY_SPIKE_RIGHT", TILE(0x00, 0, 0, 0), TILE(0x76, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x76, 0, H, 0), COL_GROUND_WAVY_SPIKE_RIGHT)

    Metatile("BASIC_BLOCK_BOTTOM",     TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x0e, 0, 0, 0), TILE(0x0f, 0, 0, 0), COL_SLAB_BOTTOM)
    Metatile("BASIC_BLOCK_TOP",        TILE(0x10, 0, 0, 0), TILE(0x11, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SLAB_TOP)
    Metatile("BASIC_BLOCK_RIGHT",      TILE(0x00, 0, 0, 0), TILE(0x0e, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x10, 0, 0, 0), COL_SLAB_RIGHT)
    Metatile("BASIC_BLOCK_LEFT_RIGHT", TILE(0x0f, 0, 0, 0), TILE(0x0e, 0, 0, 0), TILE(0x11, 0, 0, 0), TILE(0x10, 0, 0, 0), COL_FULL)
    Metatile("BASIC_BLOCK_LEFT",       TILE(0x0f, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x11, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SLAB_LEFT) // 0x38

    Metatile("ENDING_WALL",  TILE(0x00, 0, 0, 0), TILE(0x04, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x04, 0, 0, V), COL_SLAB_RIGHT)

    Metatile("INVISIBLE_FLOOR_CEIL",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_FLOOR_CEIL)

    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)

    Metatile("X_FULL",       TILE(0x13, 0, 0, 0), TILE(0x14, 0, 0, 0), TILE(0x15, 0, 0, 0), TILE(0x16, 0, 0, 0), COL_FULL) // 0x40
    Metatile("X_SIDE_UP",    TILE(0x17, 0, 0, 0), TILE(0x18, 0, 0, 0), TILE(0x19, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_FULL)
    Metatile("X_SIDE_DOWN",  TILE(0x19, 0, 0, V), TILE(0x1a, 0, 0, V), TILE(0x17, 0, 0, V), TILE(0x18, 0, 0, V), COL_FULL)
    Metatile("X_SIDE_LEFT",  TILE(0x1b, 0, 0, 0), TILE(0x1c, 0, 0, 0), TILE(0x1d, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_FULL)
    Metatile("X_SIDE_RIGHT", TILE(0x1c, 0, H, 0), TILE(0x1b, 0, H, 0), TILE(0x1a, 0, H, 0), TILE(0x1d, 0, H, 0), COL_FULL)
    Metatile("X_CORNER_TL",  TILE(0x13, 0, 0, 0), TILE(0x18, 0, 0, 0), TILE(0x1d, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_FULL)
    Metatile("X_CORNER_TR",  TILE(0x18, 0, H, 0), TILE(0x13, 0, H, 0), TILE(0x1a, 0, H, 0), TILE(0x1d, 0, H, 0), COL_FULL)
    Metatile("X_CORNER_BL",  TILE(0x1d, 0, 0, V), TILE(0x1a, 0, 0, V), TILE(0x13, 0, 0, V), TILE(0x18, 0, 0, V), COL_FULL)
    Metatile("X_CORNER_BR",  TILE(0x1a, 0, H, V), TILE(0x1d, 0, H, V), TILE(0x18, 0, H, V), TILE(0x13, 0, H, V), COL_FULL) // 0x48
    Metatile("X_INS_CRN_TL", TILE(0x1e, 0, 0, 0), TILE(0x1c, 0, 0, 0), TILE(0x19, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_FULL)
    Metatile("X_INS_CRN_TR", TILE(0x22, 0, 0, 0), TILE(0x1f, 0, 0, 0), TILE(0x19, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_FULL)
    Metatile("X_INS_CRN_BL", TILE(0x22, 0, 0, 0), TILE(0x1c, 0, 0, 0), TILE(0x20, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_FULL)
    Metatile("X_INS_CRN_BR", TILE(0x22, 0, 0, 0), TILE(0x1c, 0, 0, 0), TILE(0x19, 0, 0, 0), TILE(0x21, 0, 0, 0), COL_FULL)
    Metatile("X_FILLER",     TILE(0x22, 0, 0, 0), TILE(0x1c, 0, 0, 0), TILE(0x19, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_NONE)
    Metatile("X_DB_CRN_TOP", TILE(0x13, 0, 0, 0), TILE(0x14, 0, 0, 0), TILE(0x1d, 0, 0, 0), TILE(0x23, 0, 0, 0), COL_FULL)
    Metatile("X_DB_CRN_BOT", TILE(0x1b, 0, 0, 0), TILE(0x25, 0, 0, 0), TILE(0x15, 0, 0, 0), TILE(0x16, 0, 0, 0), COL_FULL)
        
    Metatile("X_DB_CRN_LFT", TILE(0x13, 0, 0, 0), TILE(0x18, 0, 0, 0), TILE(0x15, 0, 0, 0), TILE(0x24, 0, 0, 0), COL_FULL) // 0x50
    Metatile("X_DB_CRN_RGT", TILE(0x18, 0, H, 0), TILE(0x13, 0, H, 0), TILE(0x24, 0, H, 0), TILE(0x15, 0, H, 0), COL_FULL)
    Metatile("X_DB_SIDE_V",  TILE(0x1b, 0, 0, 0), TILE(0x25, 0, 0, 0), TILE(0x1d, 0, 0, 0), TILE(0x23, 0, 0, 0), COL_FULL)
    Metatile("X_DB_SIDE_H",  TILE(0x17, 0, 0, 0), TILE(0x18, 0, 0, 0), TILE(0x12, 0, 0, 0), TILE(0x24, 0, 0, 0), COL_FULL)
    
    Metatile("GROUND_WAVY_SPIKE_EDGE_BL", TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1d8, 0, 0, 0), TILE(0x1d9, 0, 0, 0), COL_GROUND_WAVY_SPIKE_EDGE_BL)
    Metatile("GROUND_WAVY_SPIKE_EDGE_BR", TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1d7, 0, 0, 0), COL_GROUND_WAVY_SPIKE_EDGE_BR)
    Metatile("GROUND_WAVY_SPIKE_EDGE_TL", TILE(0x1d8, 0, 0, V), TILE(0x1d9, 0, 0, V), TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), COL_GROUND_WAVY_SPIKE_EDGE_TL)
    Metatile("GROUND_WAVY_SPIKE_EDGE_TR", TILE(0x000, 0, 0, 0), TILE(0x1d7, 0, 0, V), TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), COL_GROUND_WAVY_SPIKE_EDGE_TR)
    Metatile("GROUND_WAVY_SPIKE_EDGE_LB", TILE(0x1e9, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1e8, 0, 0, 0), TILE(0x000, 0, 0, 0), COL_GROUND_WAVY_SPIKE_EDGE_LB) // 0x58
    Metatile("GROUND_WAVY_SPIKE_EDGE_LT", TILE(0x1e7, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), COL_GROUND_WAVY_SPIKE_EDGE_LT)
    Metatile("GROUND_WAVY_SPIKE_EDGE_RB", TILE(0x000, 0, 0, 0), TILE(0x1e9, 0, H, 0), TILE(0x000, 0, 0, 0), TILE(0x1e8, 0, H, 0), COL_GROUND_WAVY_SPIKE_EDGE_RB)
    Metatile("GROUND_WAVY_SPIKE_EDGE_RT", TILE(0x000, 0, 0, 0), TILE(0x1e7, 0, H, 0), TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), COL_GROUND_WAVY_SPIKE_EDGE_RT)

    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)

    Metatile("+_FULL",       TILE(0x2a, 0, 0, 0), TILE(0x2b, 0, 0, 0), TILE(0x2c, 0, 0, 0), TILE(0x2d, 0, 0, 0), COL_FULL) // 0x60
    Metatile("+_SIDE_UP",    TILE(0x2e, 0, 0, 0), TILE(0x2f, 0, 0, 0), TILE(0x30, 0, 0, 0), TILE(0x31, 0, 0, 0), COL_FULL)
    Metatile("+_SIDE_DOWN",  TILE(0x30, 0, 0, V), TILE(0x31, 0, 0, V), TILE(0x2e, 0, 0, V), TILE(0x2f, 0, 0, V), COL_FULL)
    Metatile("+_SIDE_LEFT",  TILE(0x32, 0, 0, 0), TILE(0x33, 0, 0, 0), TILE(0x34, 0, 0, 0), TILE(0x31, 0, 0, 0), COL_FULL)
    Metatile("+_SIDE_RIGHT", TILE(0x33, 0, H, 0), TILE(0x32, 0, H, 0), TILE(0x31, 0, H, 0), TILE(0x34, 0, H, 0), COL_FULL)
    Metatile("+_CORNER_TL",  TILE(0x2a, 0, 0, 0), TILE(0x2f, 0, 0, 0), TILE(0x34, 0, 0, 0), TILE(0x31, 0, 0, 0), COL_FULL)
    Metatile("+_CORNER_TR",  TILE(0x2f, 0, H, 0), TILE(0x2a, 0, H, 0), TILE(0x31, 0, H, 0), TILE(0x34, 0, H, 0), COL_FULL)
    Metatile("+_CORNER_BL",  TILE(0x34, 0, 0, V), TILE(0x31, 0, 0, V), TILE(0x2a, 0, 0, V), TILE(0x2f, 0, 0, V), COL_FULL)
    Metatile("+_CORNER_BR",  TILE(0x31, 0, H, V), TILE(0x34, 0, H, V), TILE(0x2f, 0, H, V), TILE(0x2a, 0, H, V), COL_FULL) // 0x68
    Metatile("+_FILLER",     TILE(0x35, 0, 0, 0), TILE(0x33, 0, 0, 0), TILE(0x30, 0, 0, 0), TILE(0x31, 0, 0, 0), COL_NONE)
    Metatile("+_DB_CRN_TOP", TILE(0x2a, 0, 0, 0), TILE(0x2b, 0, 0, 0), TILE(0x34, 0, 0, 0), TILE(0x36, 0, 0, 0), COL_FULL)
    Metatile("+_DB_CRN_BOT", TILE(0x34, 0, 0, V), TILE(0x36, 0, 0, V), TILE(0x2a, 0, 0, V), TILE(0x2b, 0, 0, V), COL_FULL)
    Metatile("+_DB_CRN_LFT", TILE(0x2a, 0, 0, 0), TILE(0x2f, 0, 0, 0), TILE(0x2c, 0, 0, 0), TILE(0x37, 0, 0, 0), COL_FULL)
    Metatile("+_DB_CRN_RGT", TILE(0x2f, 0, H, 0), TILE(0x2a, 0, H, 0), TILE(0x39, 0, 0, 0), TILE(0x2d, 0, 0, 0), COL_FULL)
    Metatile("+_DB_SIDE_V",  TILE(0x32, 0, 0, 0), TILE(0x38, 0, 0, 0), TILE(0x34, 0, 0, 0), TILE(0x36, 0, 0, 0), COL_FULL)
    Metatile("+_DB_SIDE_H",  TILE(0x2e, 0, 0, 0), TILE(0x2f, 0, 0, 0), TILE(0x39, 0, 0, 0), TILE(0x37, 0, 0, 0), COL_FULL)
    
    Metatile("BLK_FULL",        TILE(0x3b, 0, 0, 0), TILE(0x3b, 0, H, 0), TILE(0x3b, 0, 0, V), TILE(0x3b, 0, H, V), COL_FULL) // 0x70
    Metatile("BLK_SIDE_TOP",    TILE(0x3c, 0, 0, 0), TILE(0x3c, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_FULL)
    Metatile("BLK_SIDE_BOTTOM", TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3c, 0, 0, V), TILE(0x3c, 0, 0, V), COL_FULL)
    Metatile("BLK_SIDE_LEFT",   TILE(0x3d, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3d, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_FULL)
    Metatile("BLK_SIDE_RIGHT",  TILE(0x3a, 0, 0, 0), TILE(0x3d, 0, H, 0), TILE(0x3a, 0, 0, 0), TILE(0x3d, 0, H, 0), COL_FULL)
    Metatile("BLK_CORNER_TL",   TILE(0x3b, 0, 0, 0), TILE(0x3c, 0, 0, 0), TILE(0x3d, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_FULL)
    Metatile("BLK_CORNER_TR",   TILE(0x3c, 0, H, 0), TILE(0x3b, 0, H, 0), TILE(0x3a, 0, 0, 0), TILE(0x3d, 0, H, 0), COL_FULL)
    Metatile("BLK_CORNER_BL",   TILE(0x3d, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3b, 0, 0, V), TILE(0x3c, 0, 0, V), COL_FULL)
    Metatile("BLK_CORNER_BR",   TILE(0x3a, 0, 0, 0), TILE(0x3d, 0, H, 0), TILE(0x3c, 0, 0, V), TILE(0x3b, 0, H, V), COL_FULL) // 0x78
    Metatile("BLK_INS_CRN_TL",  TILE(0x3e, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_FULL)
    Metatile("BLK_INS_CRN_TR",  TILE(0x3a, 0, 0, 0), TILE(0x3e, 0, H, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_FULL)
    Metatile("BLK_INS_CRN_BL",  TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3e, 0, 0, V), TILE(0x3a, 0, 0, 0), COL_FULL)
    Metatile("BLK_INS_CRN_BR",  TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3e, 0, V, H), COL_FULL)
    Metatile("BLK_FILLER",      TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_FULL)
    Metatile("BLK_DB_CRN_TOP",  TILE(0x3b, 0, 0, 0), TILE(0x3b, 0, H, 0), TILE(0x3d, 0, 0, 0), TILE(0x3d, 0, H, 0), COL_FULL)
    Metatile("BLK_DB_CRN_BOT",  TILE(0x3d, 0, 0, 0), TILE(0x3d, 0, H, 0), TILE(0x3b, 0, 0, V), TILE(0x3b, 0, H, V), COL_FULL)

    Metatile("BLK_DB_CRN_LFT",  TILE(0x3b, 0, 0, 0), TILE(0x3c, 0, 0, 0), TILE(0x3b, 0, 0, V), TILE(0x3c, 0, 0, V), COL_FULL) // 0x80
    Metatile("BLK_DB_CRN_RGT",  TILE(0x3c, 0, 0, 0), TILE(0x3b, 0, H, 0), TILE(0x3c, 0, 0, V), TILE(0x3b, 0, H, V), COL_FULL)
    Metatile("BLK_DB_SIDE_H",   TILE(0x3d, 0, 0, 0), TILE(0x3d, 0, H, 0), TILE(0x3d, 0, 0, 0), TILE(0x3d, 0, H, 0), COL_FULL)
    Metatile("BLK_DB_SIDE_V",   TILE(0x3c, 0, 0, 0), TILE(0x3c, 0, 0, 0), TILE(0x3c, 0, 0, V), TILE(0x3c, 0, 0, V), COL_FULL)

    Metatile("BLK_FILLER_NO_COLL", TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_NONE)
    
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x88
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    
    
    Metatile("BRICKS_FULL",        TILE(0x3f, 0, 0, 0), TILE(0x3f, 0, H, 0), TILE(0x40, 0, 0, 0), TILE(0x41, 0, 0, 0), COL_FULL) // 0x90
    Metatile("BRICKS_SIDE_TOP",    TILE(0x42, 0, 0, 0), TILE(0x42, 0, H, 0), TILE(0x43, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_FULL)
    Metatile("BRICKS_SIDE_BOTTOM", TILE(0x43, 0, 0, V), TILE(0x44, 0, 0, V), TILE(0x42, 0, 0, V), TILE(0x42, 0, H, V), COL_FULL)
    Metatile("BRICKS_SIDE_LEFT",   TILE(0x45, 0, 0, 0), TILE(0x46, 0, 0, 0), TILE(0x47, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_FULL)
    Metatile("BRICKS_SIDE_RIGHT",  TILE(0x46, 0, H, 0), TILE(0x45, 0, H, 0), TILE(0x44, 0, H, 0), TILE(0x47, 0, H, 0), COL_FULL)
    Metatile("BRICKS_CORNER_TL",   TILE(0x3f, 0, 0, 0), TILE(0x42, 0, H, 0), TILE(0x47, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_FULL)
    Metatile("BRICKS_CORNER_TR",   TILE(0x42, 0, 0, 0), TILE(0x3f, 0, H, 0), TILE(0x44, 0, H, 0), TILE(0x47, 0, H, 0), COL_FULL)
    Metatile("BRICKS_CORNER_BL",   TILE(0x47, 0, 0, V), TILE(0x44, 0, 0, V), TILE(0x3f, 0, 0, V), TILE(0x42, 0, H, V), COL_FULL)
    Metatile("BRICKS_CORNER_BR",   TILE(0x44, 0, H, V), TILE(0x47, 0, H, V), TILE(0x42, 0, 0, V), TILE(0x3f, 0, H, V), COL_FULL) // 0x98
    Metatile("BRICKS_INS_CRN_TL",  TILE(0x48, 0, 0, 0), TILE(0x46, 0, 0, 0), TILE(0x43, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_FULL)
    Metatile("BRICKS_INS_CRN_TR",  TILE(0x46, 0, H, 0), TILE(0x48, 0, H, 0), TILE(0x43, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_FULL)
    Metatile("BRICKS_INS_CRN_BL",  TILE(0x43, 0, 0, V), TILE(0x44, 0, 0, V), TILE(0x48, 0, 0, V), TILE(0x46, 0, 0, V), COL_FULL)
    Metatile("BRICKS_INS_CRN_BR",  TILE(0x43, 0, 0, V), TILE(0x44, 0, 0, V), TILE(0x46, 0, H, V), TILE(0x48, 0, H, V), COL_FULL)
    Metatile("BRICKS_FILLER",      TILE(0x46, 0, H, 0), TILE(0x46, 0, 0, 0), TILE(0x43, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_NONE)
    Metatile("BRICKS_DB_CRN_TOP",  TILE(0x3f, 0, 0, 0), TILE(0x3f, 0, H, 0), TILE(0x47, 0, 0, 0), TILE(0x4b, 0, 0, 0), COL_FULL)
    Metatile("BRICKS_DB_CRN_BOT",  TILE(0x47, 0, 0, V), TILE(0x4b, 0, 0, V), TILE(0x3f, 0, 0, V), TILE(0x3f, 0, H, V), COL_FULL)

    Metatile("BRICKS_DB_CRN_LFT",  TILE(0x3f, 0, 0, 0), TILE(0x42, 0, H, 0), TILE(0x40, 0, 0, 0), TILE(0x4c, 0, 0, 0), COL_FULL) // 0xA0
    Metatile("BRICKS_DB_CRN_RGT",  TILE(0x42, 0, 0, 0), TILE(0x3f, 0, H, 0), TILE(0x4c, 0, H, 0), TILE(0x40, 0, H, 0), COL_FULL)
    Metatile("BRICKS_SIDE_H",      TILE(0x45, 0, 0, 0), TILE(0x45, 0, H, 0), TILE(0x45, 0, 0, 0), TILE(0x4b, 0, 0, 0), COL_FULL)
    Metatile("BRICKS_SIDE_V",      TILE(0x42, 0, 0, 0), TILE(0x42, 0, H, 0), TILE(0x4d, 0, 0, 0), TILE(0x4c, 0, 0, 0), COL_FULL)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0xA8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    

    Metatile("GROUND_1",    TILE(0x380, 1, 0, 0), TILE(0x381, 1, 0, 0), TILE(0x390, 1, 0, 0), TILE(0x391, 1, 0, 0), COL_FLOOR_CEIL) // 0xB0
    Metatile("GROUND_2",    TILE(0x382, 1, 0, 0), TILE(0x383, 1, 0, 0), TILE(0x392, 1, 0, 0), TILE(0x393, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("GROUND_3",    TILE(0x386, 1, 0, 0), TILE(0x387, 1, 0, 0), TILE(0x396, 1, 0, 0), TILE(0x397, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("CEILING_1",   TILE(0x3f0, 1, 0, V), TILE(0x3f1, 1, 0, V), TILE(0x3e0, 1, 0, V), TILE(0x3e1, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_2",   TILE(0x3f2, 1, 0, V), TILE(0x3f3, 1, 0, V), TILE(0x3e2, 1, 0, V), TILE(0x3e3, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_3",   TILE(0x3f6, 1, 0, V), TILE(0x3f7, 1, 0, V), TILE(0x3e6, 1, 0, V), TILE(0x3e7, 1, 0, V), COL_FLOOR_CEIL)

    Metatile("WAVY_SLAB_SINGLE_TOP", TILE(0x69, 0, 0, 0), TILE(0x6e, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SLAB_TOP)
    Metatile("WAVY_SLAB_START_TOP",  TILE(0x6a, 0, 0, 0), TILE(0x6b, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x6d, 0, 0, 0), COL_SLAB_TOP)
    Metatile("WAVY_SLAB_MIDDLE_TOP", TILE(0x6c, 0, 0, 0), TILE(0x6c, 0, 0, 0), TILE(0x6d, 0, 0, 0), TILE(0x6d, 0, 0, 0), COL_SLAB_TOP) // 0xB8
    Metatile("WAVY_SLAB_END_TOP",    TILE(0x6c, 0, 0, 0), TILE(0x6e, 0, 0, 0), TILE(0x6d, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SLAB_TOP)

    Metatile("WAVY_SLAB_SINGLE_BOTTOM", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x69, 0, 0, V), TILE(0x6e, 0, 0, V), COL_SLAB_BOTTOM)
    Metatile("WAVY_SLAB_START_BOTTOM",  TILE(0x00, 0, 0, 0), TILE(0x6d, 0, 0, V), TILE(0x6a, 0, 0, V), TILE(0x6b, 0, 0, V), COL_SLAB_BOTTOM)
    Metatile("WAVY_SLAB_MIDDLE_BOTTOM", TILE(0x6d, 0, 0, V), TILE(0x6d, 0, 0, V), TILE(0x6c, 0, 0, V), TILE(0x6c, 0, 0, V), COL_SLAB_BOTTOM)
    Metatile("WAVY_SLAB_END_BOTTOM",    TILE(0x6d, 0, 0, V), TILE(0x00, 0, 0, 0), TILE(0x6c, 0, 0, V), TILE(0x6e, 0, 0, V), COL_SLAB_BOTTOM)

    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("GROUND_4",    TILE(0x3a0, 1, 0, 0), TILE(0x3a1, 1, 0, 0), TILE(0x3b0, 1, 0, 0), TILE(0x3b1, 1, 0, 0), COL_FLOOR_CEIL) // 0xC0
    Metatile("GROUND_5",    TILE(0x3a2, 1, 0, 0), TILE(0x3a3, 1, 0, 0), TILE(0x3b2, 1, 0, 0), TILE(0x3b3, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("GROUND_6",    TILE(0x3a6, 1, 0, 0), TILE(0x3a7, 1, 0, 0), TILE(0x3b6, 1, 0, 0), TILE(0x3b7, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("CEILING_4",   TILE(0x3d0, 1, 0, V), TILE(0x3d1, 1, 0, V), TILE(0x3c0, 1, 0, V), TILE(0x3c1, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_5",   TILE(0x3d2, 1, 0, V), TILE(0x3d3, 1, 0, V), TILE(0x3c2, 1, 0, V), TILE(0x3c3, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_6",   TILE(0x3d6, 1, 0, V), TILE(0x3d7, 1, 0, V), TILE(0x3c6, 1, 0, V), TILE(0x3c7, 1, 0, V), COL_FLOOR_CEIL)

    Metatile("WAVY_SLAB_SINGLE_LEFT", TILE(0x70, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x75, 0, H, 0), TILE(0x00, 0, 0, 0), COL_SLAB_LEFT)
    Metatile("WAVY_SLAB_START_LEFT",  TILE(0x71, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x72, 0, H, 0), TILE(0x74, 0, H, 0), COL_SLAB_LEFT)
    Metatile("WAVY_SLAB_MIDDLE_LEFT", TILE(0x73, 0, H, 0), TILE(0x74, 0, H, 0), TILE(0x73, 0, H, 0), TILE(0x74, 0, H, 0), COL_SLAB_LEFT) // 0xC8
    Metatile("WAVY_SLAB_END_LEFT",    TILE(0x73, 0, H, 0), TILE(0x74, 0, H, 0), TILE(0x75, 0, H, 0), TILE(0x00, 0, 0, 0), COL_SLAB_LEFT)

    Metatile("WAVY_SLAB_SINGLE_RIGHT", TILE(0x00, 0, 0, 0), TILE(0x70, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x75, 0, 0, 0), COL_SLAB_RIGHT)
    Metatile("WAVY_SLAB_START_RIGHT",  TILE(0x00, 0, 0, 0), TILE(0x71, 0, 0, 0), TILE(0x74, 0, 0, 0), TILE(0x72, 0, 0, 0), COL_SLAB_RIGHT)
    Metatile("WAVY_SLAB_MIDDLE_RIGHT", TILE(0x74, 0, 0, 0), TILE(0x73, 0, 0, 0), TILE(0x74, 0, 0, 0), TILE(0x73, 0, 0, 0), COL_SLAB_RIGHT)
    Metatile("WAVY_SLAB_END_RIGHT",    TILE(0x74, 0, 0, 0), TILE(0x73, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x75, 0, 0, 0), COL_SLAB_RIGHT)

    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("GROUND_7",    TILE(0x3c0, 1, 0, 0), TILE(0x3c1, 1, 0, 0), TILE(0x3d0, 1, 0, 0), TILE(0x3d1, 1, 0, 0), COL_FLOOR_CEIL) // 0xD0
    Metatile("GROUND_8",    TILE(0x3c2, 1, 0, 0), TILE(0x3c3, 1, 0, 0), TILE(0x3d2, 1, 0, 0), TILE(0x3d3, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("GROUND_9",    TILE(0x3c6, 1, 0, 0), TILE(0x3c7, 1, 0, 0), TILE(0x3d6, 1, 0, 0), TILE(0x3d7, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("CEILING_7",   TILE(0x3b0, 1, 0, V), TILE(0x3b1, 1, 0, V), TILE(0x3a0, 1, 0, V), TILE(0x3a1, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_8",   TILE(0x3b2, 1, 0, V), TILE(0x3b3, 1, 0, V), TILE(0x3a2, 1, 0, V), TILE(0x3a3, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_9",   TILE(0x3b6, 1, 0, V), TILE(0x3b7, 1, 0, V), TILE(0x3a6, 1, 0, V), TILE(0x3a7, 1, 0, V), COL_FLOOR_CEIL)

    Metatile("BUSH_GROUND_SPIKE_1_BOTTOM", TILE(0x80, 0, 0, 0), TILE(0x81, 0, 0, 0), TILE(0x90, 0, 0, 0), TILE(0x91, 0, 0, 0), COL_GROUND_BUSH_SPIKE_BOTTOM)
    Metatile("BUSH_GROUND_SPIKE_2_BOTTOM", TILE(0x82, 0, 0, 0), TILE(0x83, 0, 0, 0), TILE(0x92, 0, 0, 0), TILE(0x93, 0, 0, 0), COL_GROUND_BUSH_SPIKE_BOTTOM)
    Metatile("BUSH_GROUND_SPIKE_3_BOTTOM", TILE(0x84, 0, 0, 0), TILE(0x85, 0, 0, 0), TILE(0x94, 0, 0, 0), TILE(0x95, 0, 0, 0), COL_GROUND_BUSH_SPIKE_BOTTOM) // 0xD8
    Metatile("BUSH_GROUND_SPIKE_4_BOTTOM", TILE(0x86, 0, 0, 0), TILE(0x87, 0, 0, 0), TILE(0x96, 0, 0, 0), TILE(0x97, 0, 0, 0), COL_GROUND_BUSH_SPIKE_BOTTOM)
    Metatile("BUSH_GROUND_SPIKE_1_TOP",    TILE(0x90, 0, 0, V), TILE(0x91, 0, 0, V), TILE(0x80, 0, 0, V), TILE(0x81, 0, 0, V), COL_GROUND_BUSH_SPIKE_TOP)
    Metatile("BUSH_GROUND_SPIKE_2_TOP",    TILE(0x92, 0, 0, V), TILE(0x93, 0, 0, V), TILE(0x82, 0, 0, V), TILE(0x83, 0, 0, V), COL_GROUND_BUSH_SPIKE_TOP)
    Metatile("BUSH_GROUND_SPIKE_3_TOP",    TILE(0x94, 0, 0, V), TILE(0x95, 0, 0, V), TILE(0x84, 0, 0, V), TILE(0x85, 0, 0, V), COL_GROUND_BUSH_SPIKE_TOP)
    Metatile("BUSH_GROUND_SPIKE_4_TOP",    TILE(0x96, 0, 0, V), TILE(0x97, 0, 0, V), TILE(0x86, 0, 0, V), TILE(0x87, 0, 0, V), COL_GROUND_BUSH_SPIKE_TOP)

    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
   
    Metatile("GROUND_A",    TILE(0x3e0, 1, 0, 0), TILE(0x3e1, 1, 0, 0), TILE(0x3f0, 1, 0, 0), TILE(0x3f1, 1, 0, 0), COL_FLOOR_CEIL) // 0xE0
    Metatile("GROUND_B",    TILE(0x3e2, 1, 0, 0), TILE(0x3e3, 1, 0, 0), TILE(0x3f2, 1, 0, 0), TILE(0x3f3, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("GROUND_C",    TILE(0x3e6, 1, 0, 0), TILE(0x3e7, 1, 0, 0), TILE(0x3f6, 1, 0, 0), TILE(0x3f7, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("CEILING_A",   TILE(0x390, 1, 0, V), TILE(0x391, 1, 0, V), TILE(0x380, 1, 0, V), TILE(0x381, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_B",   TILE(0x392, 1, 0, V), TILE(0x393, 1, 0, V), TILE(0x382, 1, 0, V), TILE(0x383, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_C",   TILE(0x396, 1, 0, V), TILE(0x397, 1, 0, V), TILE(0x386, 1, 0, V), TILE(0x387, 1, 0, V), COL_FLOOR_CEIL)

    Metatile("BUSH_GROUND_SPIKE_1_LEFT",  TILE(0x88, 0, 0, 0), TILE(0x89, 0, 0, 0), TILE(0x98, 0, 0, 0), TILE(0x99, 0, 0, 0), COL_GROUND_BUSH_SPIKE_LEFT)
    Metatile("BUSH_GROUND_SPIKE_2_LEFT",  TILE(0x8a, 0, 0, 0), TILE(0x8b, 0, 0, 0), TILE(0x9a, 0, 0, 0), TILE(0x9b, 0, 0, 0), COL_GROUND_BUSH_SPIKE_LEFT)
    Metatile("BUSH_GROUND_SPIKE_3_LEFT",  TILE(0x8c, 0, 0, 0), TILE(0x8d, 0, 0, 0), TILE(0x9c, 0, 0, 0), TILE(0x9d, 0, 0, 0), COL_GROUND_BUSH_SPIKE_LEFT) // 0xE8
    Metatile("BUSH_GROUND_SPIKE_4_LEFT",  TILE(0x8e, 0, 0, 0), TILE(0x8f, 0, 0, 0), TILE(0x9e, 0, 0, 0), TILE(0x9f, 0, 0, 0), COL_GROUND_BUSH_SPIKE_LEFT)
    Metatile("BUSH_GROUND_SPIKE_1_RIGHT", TILE(0x89, 0, H, 0), TILE(0x88, 0, H, 0), TILE(0x99, 0, H, 0), TILE(0x98, 0, H, 0), COL_GROUND_BUSH_SPIKE_RIGHT)
    Metatile("BUSH_GROUND_SPIKE_2_RIGHT", TILE(0x8b, 0, H, 0), TILE(0x8a, 0, H, 0), TILE(0x9b, 0, H, 0), TILE(0x9a, 0, H, 0), COL_GROUND_BUSH_SPIKE_RIGHT)
    Metatile("BUSH_GROUND_SPIKE_3_RIGHT", TILE(0x8d, 0, H, 0), TILE(0x8c, 0, H, 0), TILE(0x9d, 0, H, 0), TILE(0x9c, 0, H, 0), COL_GROUND_BUSH_SPIKE_RIGHT)
    Metatile("BUSH_GROUND_SPIKE_4_RIGHT", TILE(0x8f, 0, H, 0), TILE(0x8e, 0, H, 0), TILE(0x9f, 0, H, 0), TILE(0x9e, 0, H, 0), COL_GROUND_BUSH_SPIKE_RIGHT)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("1.6_SIDE_BLOCK_TOP", TILE(0xa0, 0, 0, 0), TILE(0xa0, 0, H, 0), TILE(0xb0, 0, 0, 0), TILE(0xb0, 0, H, 0), COL_FULL) // 0xF0
    Metatile("1.6_SIDE_BLOCK_BOT", TILE(0xb0, 0, 0, V), TILE(0xb0, 0, H, V), TILE(0xa0, 0, 0, V), TILE(0xa0, 0, H, V), COL_FULL)
    Metatile("1.6_SIDE_BLOCK_LFT", TILE(0xa2, 0, H, 0), TILE(0xa1, 0, H, 0), TILE(0xa2, 0, H, V), TILE(0xa1, 0, H, V), COL_FULL)
    Metatile("1.6_SIDE_BLOCK_RGT", TILE(0xa1, 0, 0, 0), TILE(0xa2, 0, 0, 0), TILE(0xa1, 0, 0, V), TILE(0xa2, 0, 0, V), COL_FULL)

    Metatile("1.6_SIDE_TOP", TILE(0xa3, 0, 0, 0), TILE(0xa3, 0, 0, 0), TILE(0xb3, 0, 0, 0), TILE(0xb3, 0, 0, 0), COL_FULL)
    Metatile("1.6_SIDE_BOT", TILE(0xb3, 0, 0, V), TILE(0xb3, 0, 0, V), TILE(0xa3, 0, 0, V), TILE(0xa3, 0, 0, V), COL_FULL)
    Metatile("1.6_SIDE_LFT", TILE(0xa4, 0, 0, 0), TILE(0xa5, 0, 0, 0), TILE(0xa4, 0, 0, 0), TILE(0xa5, 0, 0, 0), COL_FULL)
    Metatile("1.6_SIDE_RGT", TILE(0xa5, 0, H, 0), TILE(0xa4, 0, H, 0), TILE(0xa5, 0, H, 0), TILE(0xa4, 0, H, 0), COL_FULL)

    Metatile("1.6_CORNER_TL", TILE(0xa6, 0, 0, 0), TILE(0xa3, 0, 0, 0), TILE(0xa4, 0, 0, 0), TILE(0xb4, 0, 0, 0), COL_FULL) // 0xF8
    Metatile("1.6_CORNER_TR", TILE(0xa3, 0, H, 0), TILE(0xa6, 0, H, 0), TILE(0xb4, 0, H, 0), TILE(0xa4, 0, H, 0), COL_FULL)
    Metatile("1.6_CORNER_BL", TILE(0xa4, 0, 0, V), TILE(0xb4, 0, 0, V), TILE(0xa6, 0, 0, V), TILE(0xa3, 0, 0, V), COL_FULL)
    Metatile("1.6_CORNER_BR", TILE(0xb4, 0, H, V), TILE(0xa4, 0, H, V), TILE(0xa3, 0, H, V), TILE(0xa6, 0, H, V), COL_FULL)

    Metatile("1.6_INS_CRN_TL", TILE(0xb7, 0, 0, 0), TILE(0xa5, 0, 0, 0), TILE(0xb3, 0, 0, 0), TILE(0xb5, 0, 0, 0), COL_FULL)
    Metatile("1.6_INS_CRN_TR", TILE(0xa5, 0, H, 0), TILE(0xb7, 0, H, 0), TILE(0xb5, 0, H, 0), TILE(0xb3, 0, H, 0), COL_FULL)
    Metatile("1.6_INS_CRN_BL", TILE(0xb3, 0, 0, V), TILE(0xb5, 0, 0, V), TILE(0xb7, 0, 0, V), TILE(0xa5, 0, 0, V), COL_FULL)
    Metatile("1.6_INS_CRN_BR", TILE(0xb5, 0, H, V), TILE(0xb3, 0, H, V), TILE(0xa5, 0, H, V), TILE(0xb7, 0, H, V), COL_FULL)

    Metatile("1.6_SIDE_TOP_NO_OUT", TILE(0xb1, 0, 0, 0), TILE(0xb1, 0, 0, 0), TILE(0xb3, 0, 0, 0), TILE(0xb3, 0, 0, 0), COL_NONE) // 0x100
    Metatile("1.6_SIDE_BOT_NO_OUT", TILE(0xb3, 0, 0, V), TILE(0xb3, 0, 0, V), TILE(0xb1, 0, 0, V), TILE(0xb1, 0, 0, V), COL_NONE)
    Metatile("1.6_SIDE_LFT_NO_OUT", TILE(0xb2, 0, H, 0), TILE(0xa5, 0, 0, 0), TILE(0xb2, 0, H, 0), TILE(0xa5, 0, 0, 0), COL_NONE)
    Metatile("1.6_SIDE_RGY_NO_OUT", TILE(0xa5, 0, H, 0), TILE(0xb2, 0, 0, 0), TILE(0xa5, 0, H, 0), TILE(0xb2, 0, 0, 0), COL_NONE)

    Metatile("1.6_DBL_CRN_TOP", TILE(0xa6, 0, 0, 0), TILE(0xa6, 0, H, 0), TILE(0xa4, 0, 0, 0), TILE(0xa4, 0, H, 0), COL_FULL)
    Metatile("1.6_DBL_CRN_BOT", TILE(0xa4, 0, 0, V), TILE(0xa4, 0, H, V), TILE(0xa6, 0, 0, V), TILE(0xa6, 0, H, V), COL_FULL)
    Metatile("1.6_DBL_CRN_LFT", TILE(0xa6, 0, 0, 0), TILE(0xa3, 0, 0, 0), TILE(0xa6, 0, 0, V), TILE(0xa3, 0, 0, V), COL_FULL)
    Metatile("1.6_DBL_CRN_RGT", TILE(0xa3, 0, H, 0), TILE(0xa6, 0, H, 0), TILE(0xa3, 0, H, V), TILE(0xa6, 0, H, V), COL_FULL)

    Metatile("1.6_DBL_SIDE_V", TILE(0xa4, 0, 0, 0), TILE(0xa4, 0, H, 0), TILE(0xa4, 0, 0, 0), TILE(0xa4, 0, H, 0), COL_FULL) // 0x108
    Metatile("1.6_DBL_SIDE_H", TILE(0xa3, 0, 0, 0), TILE(0xa3, 0, 0, 0), TILE(0xa3, 0, 0, V), TILE(0xa3, 0, 0, V), COL_FULL)

    Metatile("1.6_DBL_INS_CRN_TOP", TILE(0xb7, 0, 0, 0), TILE(0xb7, 0, H, 0), TILE(0xb3, 0, 0, 0), TILE(0xb3, 0, 0, 0), COL_FULL)
    Metatile("1.6_DBL_INS_CRN_BOT", TILE(0xb3, 0, 0, V), TILE(0xb3, 0, 0, V), TILE(0xb7, 0, 0, V), TILE(0xb7, 0, H, V), COL_FULL)
    Metatile("1.6_DBL_INS_CRN_LFT", TILE(0xb7, 0, 0, 0), TILE(0xa5, 0, 0, 0), TILE(0xb7, 0, 0, V), TILE(0xa5, 0, 0, 0), COL_FULL)
    Metatile("1.6_DBL_INS_CRN_RGT", TILE(0xa5, 0, H, 0), TILE(0xb7, 0, H, 0), TILE(0xa5, 0, H, 0), TILE(0xb7, 0, H, V), COL_FULL)

    Metatile("1.6_BLOCK",     TILE(0xa6, 0, 0, 0), TILE(0xa6, 0, H, 0), TILE(0xa6, 0, 0, V), TILE(0xa6, 0, H, V), COL_FULL)
    Metatile("1.6_BLOCK_ALT", TILE(0xa7, 0, 0, 0), TILE(0xa7, 0, H, 0), TILE(0xa7, 0, 0, V), TILE(0xa7, 0, H, V), COL_FULL)

    Metatile("1.6_FILLER", TILE(0xa8, 0, 0, 0), TILE(0xa8, 0, 0, 0), TILE(0xa8, 0, 0, 0), TILE(0xa8, 0, 0, 0), COL_NONE) // 0x110

    Metatile("1.6_SID_INS_CRN_H_TL", TILE(0xb4, 0, H, V), TILE(0xb7, 0, H, 0), TILE(0xa3, 0, 0, V), TILE(0xa3, 0, 0, V), COL_FULL)
    Metatile("1.6_SID_INS_CRN_H_TR", TILE(0xb7, 0, 0, 0), TILE(0xb4, 0, 0, V), TILE(0xa3, 0, H, V), TILE(0xa3, 0, H, V), COL_FULL)
    Metatile("1.6_SID_INS_CRN_H_BL", TILE(0xa3, 0, 0, 0), TILE(0xa3, 0, 0, 0), TILE(0xb4, 0, H, 0), TILE(0xb7, 0, H, V), COL_FULL)
    Metatile("1.6_SID_INS_CRN_H_BR", TILE(0xa3, 0, H, 0), TILE(0xa3, 0, H, 0), TILE(0xb7, 0, 0, V), TILE(0xb4, 0, 0, 0), COL_FULL)

    Metatile("1.6_SID_INS_CRN_V_TL", TILE(0xb4, 0, H, V), TILE(0xa4, 0, H, 0), TILE(0xb7, 0, 0, V), TILE(0xa4, 0, H, 0), COL_FULL)
    Metatile("1.6_SID_INS_CRN_V_TR", TILE(0xa4, 0, 0, 0), TILE(0xb4, 0, 0, V), TILE(0xa4, 0, 0, 0), TILE(0xb7, 0, H, V), COL_FULL)
    Metatile("1.6_SID_INS_CRN_V_BL", TILE(0xb7, 0, 0, 0), TILE(0xa4, 0, H, V), TILE(0xb4, 0, H, 0), TILE(0xa4, 0, H, V), COL_FULL)
    Metatile("1.6_SID_INS_CRN_V_BR", TILE(0xa4, 0, 0, V), TILE(0xb7, 0, H, 0), TILE(0xa4, 0, 0, V), TILE(0xb4, 0, 0, 0), COL_FULL) // 0x118

    Metatile("1.6_SLAB_BLOCK_TOP", TILE(0xa9, 0, 0, 0), TILE(0xa9, 0, H, 0), TILE(0xaa, 0, 0, V), TILE(0xaa, 0, H, V), COL_FULL)
    Metatile("1.6_SLAB_BLOCK_BOT", TILE(0xaa, 0, 0, 0), TILE(0xaa, 0, H, 0), TILE(0xa9, 0, 0, V), TILE(0xa9, 0, H, V), COL_FULL)
    Metatile("1.6_SLAB_BLOCK_LFT", TILE(0xa9, 0, 0, 0), TILE(0xaa, 0, H, 0), TILE(0xa9, 0, 0, V), TILE(0xaa, 0, H, V), COL_FULL)
    Metatile("1.6_SLAB_BLOCK_RGT", TILE(0xaa, 0, 0, 0), TILE(0xa9, 0, H, 0), TILE(0xaa, 0, 0, V), TILE(0xa9, 0, H, V), COL_FULL)

    Metatile("1.6_SLAB_CRN_TL",    TILE(0xab, 0, 0, 0), TILE(0xac, 0, 0, 0), TILE(0xbb, 0, 0, 0), TILE(0xbc, 0, 0, 0), COL_FULL)
    Metatile("1.6_SLAB_CRN_TR",    TILE(0xac, 0, H, 0), TILE(0xab, 0, H, 0), TILE(0xbc, 0, H, 0), TILE(0xbb, 0, H, 0), COL_FULL)
    Metatile("1.6_SLAB_CRN_BL",    TILE(0xbb, 0, 0, V), TILE(0xbc, 0, 0, V), TILE(0xab, 0, 0, V), TILE(0xac, 0, 0, V), COL_FULL)
    Metatile("1.6_SLAB_CRN_BR",    TILE(0xbc, 0, H, V), TILE(0xbb, 0, H, V), TILE(0xac, 0, H, V), TILE(0xab, 0, H, V), COL_FULL) // 0x120

    Metatile("1.6_SLAB_SIDE_TOP", TILE(0xad, 0, 0, 0), TILE(0xad, 0, H, 0), TILE(0xbd, 0, 0, 0), TILE(0xbd, 0, H, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_SIDE_BOT", TILE(0xbd, 0, 0, V), TILE(0xbd, 0, H, V), TILE(0xad, 0, 0, V), TILE(0xad, 0, H, V), COL_SLAB_BOTTOM)
    Metatile("1.6_SLAB_SIDE_LFT", TILE(0xaf, 0, H, 0), TILE(0xb9, 0, H, 0), TILE(0xaf, 0, H, V), TILE(0xb9, 0, H, V), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_SIDE_RGT", TILE(0xb9, 0, 0, 0), TILE(0xaf, 0, 0, 0), TILE(0xb9, 0, 0, V), TILE(0xaf, 0, 0, V), COL_SLAB_RIGHT)

    Metatile("1.6_SLAB_SIDE_H_TL", TILE(0xad, 0, 0, 0), TILE(0xae, 0, 0, 0), TILE(0xbd, 0, 0, 0), TILE(0xbe, 0, 0, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_SIDE_H_TR", TILE(0xae, 0, H, 0), TILE(0xad, 0, H, 0), TILE(0xbe, 0, H, 0), TILE(0xbd, 0, H, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_SIDE_H_BL", TILE(0xbd, 0, 0, V), TILE(0xbe, 0, 0, V), TILE(0xad, 0, 0, V), TILE(0xae, 0, 0, V), COL_SLAB_BOTTOM)
    Metatile("1.6_SLAB_SIDE_H_BR", TILE(0xbe, 0, H, V), TILE(0xbd, 0, H, V), TILE(0xae, 0, H, V), TILE(0xad, 0, H, V), COL_SLAB_BOTTOM) // 0x128
    Metatile("1.6_SLAB_SIDE_V_TL", TILE(0xaf, 0, H, 0), TILE(0xb9, 0, H, 0), TILE(0xbf, 0, H, 0), TILE(0xba, 0, H, 0), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_SIDE_V_TR", TILE(0xb9, 0, 0, 0), TILE(0xaf, 0, 0, 0), TILE(0xba, 0, 0, 0), TILE(0xbf, 0, 0, 0), COL_SLAB_RIGHT)
    Metatile("1.6_SLAB_SIDE_V_BL", TILE(0xbf, 0, H, V), TILE(0xba, 0, H, V), TILE(0xaf, 0, H, V), TILE(0xb9, 0, H, V), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_SIDE_V_BR", TILE(0xba, 0, 0, V), TILE(0xbf, 0, 0, V), TILE(0xb9, 0, 0, V), TILE(0xaf, 0, 0, V), COL_SLAB_RIGHT)

    Metatile("1.6_SLAB_SIDE_H_TL_ALT", TILE(0xc0, 0, 0, 0), TILE(0xc1, 0, H, 0), TILE(0xd0, 0, 0, 0), TILE(0xd1, 0, H, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_SIDE_H_TR_ALT", TILE(0xc1, 0, 0, 0), TILE(0xc0, 0, H, 0), TILE(0xd1, 0, 0, 0), TILE(0xd0, 0, H, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_SIDE_H_BL_ALT", TILE(0xd0, 0, 0, V), TILE(0xd1, 0, H, V), TILE(0xc0, 0, 0, V), TILE(0xc1, 0, H, V), COL_SLAB_BOTTOM)
    Metatile("1.6_SLAB_SIDE_H_BR_ALT", TILE(0xd1, 0, 0, V), TILE(0xd0, 0, H, V), TILE(0xc1, 0, 0, V), TILE(0xc0, 0, H, V), COL_SLAB_BOTTOM) // 0x130
    Metatile("1.6_SLAB_SIDE_V_TL_ALT", TILE(0xcb, 0, H, 0), TILE(0xca, 0, H, 0), TILE(0xcd, 0, H, V), TILE(0xcc, 0, H, V), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_SIDE_V_TR_ALT", TILE(0xca, 0, 0, 0), TILE(0xcb, 0, 0, 0), TILE(0xcc, 0, 0, V), TILE(0xcd, 0, 0, V), COL_SLAB_RIGHT)
    Metatile("1.6_SLAB_SIDE_V_BL_ALT", TILE(0xcd, 0, H, 0), TILE(0xcc, 0, H, 0), TILE(0xcb, 0, H, V), TILE(0xca, 0, H, V), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_SIDE_V_BR_ALT", TILE(0xcc, 0, 0, 0), TILE(0xcd, 0, 0, 0), TILE(0xca, 0, 0, V), TILE(0xcb, 0, 0, V), COL_SLAB_RIGHT)

    Metatile("1.6_SLAB_MED_TOP", TILE(0xc2, 0, 0, 0), TILE(0xc2, 0, H, 0), TILE(0xd2, 0, 0, 0), TILE(0xd2, 0, H, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_MED_BOT", TILE(0xd2, 0, 0, V), TILE(0xd2, 0, H, V), TILE(0xc2, 0, 0, V), TILE(0xc2, 0, H, V), COL_SLAB_BOTTOM)
    Metatile("1.6_SLAB_MED_LFT", TILE(0xc7, 0, H, 0), TILE(0xc6, 0, H, 0), TILE(0xc7, 0, H, V), TILE(0xc6, 0, H, V), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_MED_RGT", TILE(0xc6, 0, 0, 0), TILE(0xc7, 0, 0, 0), TILE(0xc6, 0, 0, V), TILE(0xc7, 0, 0, V), COL_SLAB_RIGHT) // 0x138

    Metatile("1.6_SLAB_TINY_TOP", TILE(0xb8, 0, 0, 0), TILE(0xb8, 0, H, 0), TILE(0xd0, 0, 0, 0), TILE(0xd0, 0, H, 0), COL_SLAB_TINY_TOP)
    Metatile("1.6_SLAB_TINY_BOT", TILE(0xd0, 0, 0, V), TILE(0xd0, 0, H, V), TILE(0xb8, 0, 0, V), TILE(0xb8, 0, H, V), COL_SLAB_TINY_BOTTOM)
    Metatile("1.6_SLAB_TINY_LFT", TILE(0xcf, 0, H, 0), TILE(0xca, 0, H, 0), TILE(0xcf, 0, H, V), TILE(0xca, 0, H, V), COL_SLAB_TINY_LEFT)
    Metatile("1.6_SLAB_TINY_RGT", TILE(0xca, 0, 0, 0), TILE(0xcf, 0, 0, 0), TILE(0xca, 0, 0, V), TILE(0xcf, 0, 0, V), COL_SLAB_TINY_RIGHT)
    
    Metatile("1.6_SLAB_CORNER_H_TL", TILE(0xc4, 0, 0, 0), TILE(0xc5, 0, 0, 0), TILE(0xd4, 0, 0, 0), TILE(0xd5, 0, 0, 0), COL_SLAB_MED_TOP)
    Metatile("1.6_SLAB_CORNER_H_TR", TILE(0xc5, 0, H, 0), TILE(0xc4, 0, H, 0), TILE(0xd5, 0, H, 0), TILE(0xd4, 0, H, 0), COL_SLAB_MED_TOP)
    Metatile("1.6_SLAB_CORNER_H_BL", TILE(0xd4, 0, 0, V), TILE(0xd5, 0, 0, V), TILE(0xc4, 0, 0, V), TILE(0xc5, 0, 0, V), COL_SLAB_MED_BOTTOM)
    Metatile("1.6_SLAB_CORNER_H_BR", TILE(0xd5, 0, H, V), TILE(0xd4, 0, H, V), TILE(0xc5, 0, H, V), TILE(0xc4, 0, H, V), COL_SLAB_MED_BOTTOM) // 0x140
    Metatile("1.6_SLAB_CORNER_V_TL", TILE(0xd7, 0, H, 0), TILE(0xd6, 0, H, 0), TILE(0xce, 0, H, 0), TILE(0xd5, 0, 0, 0), COL_SLAB_MED_LEFT)
    Metatile("1.6_SLAB_CORNER_V_TR", TILE(0xd6, 0, 0, 0), TILE(0xd7, 0, 0, 0), TILE(0xd5, 0, H, 0), TILE(0xce, 0, 0, 0), COL_SLAB_MED_RIGHT)
    Metatile("1.6_SLAB_CORNER_V_BL", TILE(0xce, 0, H, V), TILE(0xd5, 0, 0, V), TILE(0xd7, 0, H, V), TILE(0xd6, 0, H, V), COL_SLAB_MED_LEFT)
    Metatile("1.6_SLAB_CORNER_V_BR", TILE(0xd5, 0, H, V), TILE(0xce, 0, 0, V), TILE(0xd6, 0, 0, V), TILE(0xd7, 0, 0, V), COL_SLAB_MED_RIGHT)

    Metatile("1.6_SLAB_CORNER_BIG_H_TL", TILE(0xc3, 0, H, 0), TILE(0xad, 0, H, 0), TILE(0xd3, 0, H, 0), TILE(0xbd, 0, H, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_CORNER_BIG_H_TR", TILE(0xad, 0, 0, 0), TILE(0xc3, 0, 0, 0), TILE(0xbd, 0, 0, 0), TILE(0xd3, 0, 0, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_CORNER_BIG_H_BL", TILE(0xd3, 0, H, V), TILE(0xbd, 0, H, V), TILE(0xc3, 0, H, V), TILE(0xad, 0, H, V), COL_SLAB_BOTTOM)
    Metatile("1.6_SLAB_CORNER_BIG_H_BR", TILE(0xbd, 0, 0, V), TILE(0xd3, 0, 0, V), TILE(0xad, 0, 0, V), TILE(0xc3, 0, 0, V), COL_SLAB_BOTTOM) // 0x148
    Metatile("1.6_SLAB_CORNER_BIG_V_TL", TILE(0xaf, 0, H, 0), TILE(0xb9, 0, H, 0), TILE(0xc9, 0, H, 0), TILE(0xc8, 0, H, 0), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_CORNER_BIG_V_TR", TILE(0xb9, 0, 0, 0), TILE(0xaf, 0, 0, 0), TILE(0xc8, 0, 0, 0), TILE(0xc9, 0, 0, 0), COL_SLAB_RIGHT)
    Metatile("1.6_SLAB_CORNER_BIG_V_BL", TILE(0xc9, 0, H, V), TILE(0xc8, 0, H, V), TILE(0xaf, 0, H, V), TILE(0xb9, 0, H, V), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_CORNER_BIG_V_BR", TILE(0xc8, 0, 0, V), TILE(0xc9, 0, 0, V), TILE(0xb9, 0, 0, V), TILE(0xaf, 0, 0, V), COL_SLAB_RIGHT)

    Metatile("1.6_SLAB_SINGLE_TOP", TILE(0xc0, 0, 0, 0), TILE(0xc0, 0, H, 0), TILE(0xd0, 0, 0, 0), TILE(0xd0, 0, H, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_SINGLE_BOT", TILE(0xd0, 0, 0, V), TILE(0xd0, 0, H, V), TILE(0xc0, 0, 0, V), TILE(0xc0, 0, H, V), COL_SLAB_BOTTOM)
    Metatile("1.6_SLAB_SINGLE_LFT", TILE(0xcb, 0, H, 0), TILE(0xca, 0, H, 0), TILE(0xcb, 0, H, V), TILE(0xca, 0, H, V), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_SINGLE_RGT", TILE(0xca, 0, 0, 0), TILE(0xcb, 0, 0, 0), TILE(0xca, 0, 0, V), TILE(0xcb, 0, 0, V), COL_SLAB_RIGHT) // 0x150

    Metatile("1.6_WAVE_LFT",       TILE(0xda, 2, 0, 0), TILE(0xdb, 2, 0, 0), TILE(0xea, 2, 0, 0), TILE(0xeb, 2, 0, 0), COL_NONE)
    Metatile("1.6_WAVE_MIDDLE",    TILE(0xdc, 2, 0, 0), TILE(0xdd, 2, 0, 0), TILE(0xeb, 2, 0, 0), TILE(0xeb, 2, 0, 0), COL_NONE)
    Metatile("1.6_WAVE_RGT",       TILE(0xde, 2, 0, 0), TILE(0xdf, 2, 0, 0), TILE(0xeb, 2, 0, 0), TILE(0xec, 2, 0, 0), COL_NONE)
    Metatile("1.6_WAVE_LFT_UD",    TILE(0xea, 2, 0, V), TILE(0xeb, 2, 0, V), TILE(0xda, 2, 0, V), TILE(0xdb, 2, 0, V), COL_NONE)
    Metatile("1.6_WAVE_MIDDLE_UD", TILE(0xeb, 2, 0, V), TILE(0xeb, 2, 0, V), TILE(0xdc, 2, 0, V), TILE(0xdd, 2, 0, V), COL_NONE)
    Metatile("1.6_WAVE_RGT_UD",    TILE(0xeb, 2, 0, V), TILE(0xec, 2, 0, V), TILE(0xde, 2, 0, V), TILE(0xdf, 2, 0, V), COL_NONE)

    Metatile("1.6_SPIKE_UP",            TILE(0xed, 0, 0, 0), TILE(0xed, 0, H, 0), TILE(0xfd, 0, 0, 0), TILE(0xfd, 0, H, 0), COL_SPIKE_TOP)
    Metatile("1.6_SPIKE_DOWN",          TILE(0xfd, 0, 0, V), TILE(0xfd, 0, H, V), TILE(0xed, 0, 0, V), TILE(0xed, 0, H, V), COL_SPIKE_BOTTOM) // 0x158
    Metatile("1.6_SPIKE_LEFT",          TILE(0xe7, 0, 0, 0), TILE(0xe8, 0, 0, 0), TILE(0xe7, 0, 0, V), TILE(0xe8, 0, 0, V), COL_SPIKE_LEFT)
    Metatile("1.6_SPIKE_RIGHT",         TILE(0xe8, 0, H, 0), TILE(0xe7, 0, H, 0), TILE(0xe8, 0, H, V), TILE(0xe7, 0, H, V), COL_SPIKE_RIGHT)
    Metatile("1.6_SMALL_SPIKE_BOTTOM",  TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0xef, 0, 0, 0), TILE(0xef, 0, H, 0), COL_SMALL_SPIKE_BOTTOM)
    Metatile("1.6_SMALL_SPIKE_TOP",     TILE(0xef, 0, 0, V), TILE(0xef, 0, H, V), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SMALL_SPIKE_TOP)
    Metatile("1.6_SMALL_SPIKE_LEFT",    TILE(0xe9, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0xe9, 0, 0, V), TILE(0x00, 0, 0, 0), COL_SMALL_SPIKE_LEFT)
    Metatile("1.6_SMALL_SPIKE_RIGHT",   TILE(0x00, 0, 0, 0), TILE(0xe9, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0xe9, 0, H, V), COL_SMALL_SPIKE_RIGHT)
    Metatile("1.6_MEDIUM_SPIKE_BOTTOM", TILE(0xee, 0, 0, 0), TILE(0xee, 0, H, 0), TILE(0xfe, 0, 0, 0), TILE(0xff, 0, 0, 0), COL_MEDIUM_SPIKE_BOTTOM)
    Metatile("1.6_MEDIUM_SPIKE_TOP",    TILE(0xfe, 0, 0, V), TILE(0xff, 0, 0, V), TILE(0xee, 0, 0, V), TILE(0xee, 0, H, V), COL_MEDIUM_SPIKE_TOP) // 0x160
    Metatile("1.6_MEDIUM_SPIKE_LEFT",   TILE(0xf7, 0, 0, 0), TILE(0xf8, 0, 0, 0), TILE(0xf9, 0, 0, 0), TILE(0xf8, 0, 0, V), COL_MEDIUM_SPIKE_LEFT)
    Metatile("1.6_MEDIUM_SPIKE_RIGHT",  TILE(0xf8, 0, H, 0), TILE(0xf7, 0, H, 0), TILE(0xf8, 0, H, V), TILE(0xf9, 0, H, 0), COL_MEDIUM_SPIKE_RIGHT)

    Metatile("FAKE_SPIKE_UP",            TILE(0xe0, 0, 0, 0),  TILE(0xe1, 0, 0, 0),  TILE(0xf0, 0, 0, 0),  TILE(0xf1, 0, 0, 0),  COL_NONE)
    Metatile("FAKE_SPIKE_DOWN",          TILE(0xf0, 0, 0, V),  TILE(0xf1, 0, 0, V),  TILE(0xe0, 0, 0, V),  TILE(0xe1, 0, 0, V),  COL_NONE)
    Metatile("FAKE_SPIKE_LEFT",          TILE(0x100, 0, 0, 0), TILE(0x101, 0, 0, 0), TILE(0x110, 0, 0, 0), TILE(0x111, 0, 0, 0), COL_NONE)
    Metatile("FAKE_SPIKE_RIGHT",         TILE(0x101, 0, H, 0), TILE(0x100, 0, H, 0), TILE(0x111, 0, H, 0), TILE(0x110, 0, H, 0), COL_NONE)
    Metatile("FAKE_SMALL_SPIKE_BOTTOM",  TILE(0x00, 0, 0, 0),  TILE(0x00, 0, 0, 0),  TILE(0xf2, 0, 0, 0),  TILE(0xf3, 0, 0, 0),  COL_NONE)
    Metatile("FAKE_SMALL_SPIKE_TOP",     TILE(0xf2, 0, 0, V),  TILE(0xf3, 0, 0, V),  TILE(0x00, 0, 0, 0),  TILE(0x00, 0, 0, 0),  COL_NONE) // 0x168
    Metatile("FAKE_SMALL_SPIKE_LEFT",    TILE(0xe2, 0, 0, 0),  TILE(0x00, 0, 0, 0),  TILE(0xe3, 0, 0, 0),  TILE(0x00, 0, 0, 0),  COL_NONE)
    Metatile("FAKE_SMALL_SPIKE_RIGHT",   TILE(0x00, 0, 0, 0),  TILE(0xe2, 0, H, 0),  TILE(0x00, 0, 0, 0),  TILE(0xe3, 0, H, 0),  COL_NONE)
    Metatile("FAKE_MEDIUM_SPIKE_BOTTOM", TILE(0xe4, 0, 0, 0),  TILE(0xe4, 0, H, 0),  TILE(0xf4, 0, 0, 0),  TILE(0xf5, 0, 0, 0),  COL_NONE)
    Metatile("FAKE_MEDIUM_SPIKE_TOP",    TILE(0xf4, 0, 0, V),  TILE(0xf5, 0, 0, V),  TILE(0xe4, 0, 0, V),  TILE(0xe4, 0, H, V),  COL_NONE)
    Metatile("FAKE_MEDIUM_SPIKE_LEFT",   TILE(0xe6, 0, 0, 0),  TILE(0xe5, 0, 0, 0),  TILE(0xf6, 0, 0, 0),  TILE(0xe5, 0, 0, V),  COL_NONE)
    Metatile("FAKE_MEDIUM_SPIKE_RIGHT",  TILE(0xe5, 0, H, 0),  TILE(0xe6, 0, H, 0),  TILE(0xe5, 0, H, V),  TILE(0xf6, 0, H, 0),  COL_NONE)

    Metatile("1.6_EA_MIDDLE_SLAB",    TILE(0x106, 0, 0, 0), TILE(0x106, 0, H, 0), TILE(0x116, 0, 0, 0), TILE(0x116, 0, H, 0), COL_EA_SLAB_BOTTOM)
    Metatile("1.6_EA_MIDDLE_SLAB_UD", TILE(0x116, 0, 0, V), TILE(0x116, 0, H, V), TILE(0x106, 0, 0, V), TILE(0x106, 0, H, V), COL_EA_SLAB_TOP) // 0x170

    Metatile("1.6_EA_CORNER_BR", TILE(0x108, 0, 0, 0), TILE(0x109, 0, 0, 0), TILE(0x118, 0, 0, 0), TILE(0x119, 0, 0, 0), COL_EA_CORNER_SLAB_BOTTOM_RIGHT)
    Metatile("1.6_EA_CORNER_BL", TILE(0x109, 0, H, 0), TILE(0x108, 0, H, 0), TILE(0x119, 0, H, 0), TILE(0x118, 0, H, 0), COL_EA_CORNER_SLAB_BOTTOM_LEFT) 
    Metatile("1.6_EA_CORNER_TR", TILE(0x118, 0, 0, V), TILE(0x119, 0, 0, V), TILE(0x108, 0, 0, V), TILE(0x109, 0, 0, V), COL_EA_CORNER_SLAB_TOP_RIGHT)
    Metatile("1.6_EA_CORNER_TL", TILE(0x119, 0, H, V), TILE(0x118, 0, H, V), TILE(0x109, 0, H, V), TILE(0x108, 0, H, V), COL_EA_CORNER_SLAB_TOP_LEFT)

    Metatile("1.6_EA_INS_CRN_BR", TILE(0xfa, 0, 0, 0),  TILE(0xfb, 0, 0, 0),  TILE(0x117, 0, 0, 0), TILE(0xfc, 0, 0, 0),  COL_EA_CORNER_INSIDE_SLAB_BOTTOM_RIGHT)
    Metatile("1.6_EA_INS_CRN_BL", TILE(0xfb, 0, H, 0),  TILE(0xfa, 0, H, 0),  TILE(0xfc, 0, H, 0),  TILE(0x117, 0, H, 0), COL_EA_CORNER_INSIDE_SLAB_BOTTOM_LEFT)
    Metatile("1.6_EA_INS_CRN_TR", TILE(0x117, 0, 0, V), TILE(0xfc, 0, 0, V),  TILE(0xfa, 0, 0, V),  TILE(0xfb, 0, 0, V),  COL_EA_CORNER_INSIDE_SLAB_TOP_RIGHT)
    Metatile("1.6_EA_INS_CRN_TL", TILE(0xfc, 0, H, V),  TILE(0x117, 0, H, V), TILE(0xfb, 0, H, V),  TILE(0xfa, 0, H, V),  COL_EA_CORNER_INSIDE_SLAB_TOP_LEFT) // 0x178

    Metatile("1.6_EA_ALIGNER_BL", TILE(0x102, 0, 0, 0), TILE(0x103, 0, 0, 0), TILE(0x112, 0, 0, 0), TILE(0x113, 0, 0, 0), COL_EA_SLAB_BOTTOM)
    Metatile("1.6_EA_ALIGNER_BR", TILE(0x103, 0, H, 0), TILE(0x102, 0, H, 0), TILE(0x113, 0, H, 0), TILE(0x112, 0, H, 0), COL_EA_SLAB_BOTTOM)
    Metatile("1.6_EA_ALIGNER_TL", TILE(0x112, 0, 0, V), TILE(0x113, 0, 0, V), TILE(0x102, 0, 0, V), TILE(0x103, 0, 0, V), COL_EA_SLAB_TOP)
    Metatile("1.6_EA_ALIGNER_TR", TILE(0x113, 0, H, V), TILE(0x112, 0, H, V), TILE(0x103, 0, H, V), TILE(0x102, 0, H, V), COL_EA_SLAB_TOP)

    Metatile("1.6_EA_SLAB",    TILE(0x107, 0, 0, 0), TILE(0x107, 0, H, 0), TILE(0x117, 0, 0, 0), TILE(0x117, 0, H, 0), COL_EA_SLAB_BOTTOM)
    Metatile("1.6_EA_SLAB_UD", TILE(0x117, 0, 0, V), TILE(0x117, 0, H, V), TILE(0x107, 0, 0, V), TILE(0x107, 0, H, V), COL_EA_SLAB_TOP)

    Metatile("1.6_EA_UNALIGNED_SLAB_V_TR", TILE(0x104, 0, 0, 0), TILE(0x105, 0, 0, 0), TILE(0x114, 0, 0, 0), TILE(0x115, 0, 0, 0), COL_EA_SLAB_RIGHT)
    Metatile("1.6_EA_UNALIGNED_SLAB_V_TL", TILE(0x105, 0, H, 0), TILE(0x104, 0, H, 0), TILE(0x115, 0, H, 0), TILE(0x114, 0, H, 0), COL_EA_SLAB_LEFT) // 0x180
    Metatile("1.6_EA_UNALIGNED_SLAB_V_BR", TILE(0x114, 0, 0, V), TILE(0x115, 0, 0, V), TILE(0x104, 0, 0, V), TILE(0x105, 0, 0, V), COL_EA_SLAB_RIGHT)
    Metatile("1.6_EA_UNALIGNED_SLAB_V_BL", TILE(0x115, 0, H, V), TILE(0x114, 0, H, V), TILE(0x105, 0, H, V), TILE(0x104, 0, H, V), COL_EA_SLAB_LEFT)

    Metatile("1.6_EA_UNALIGNED_SLAB_H_BL", TILE(0x10c, 0, 0, 0), TILE(0x109, 0, 0, 0), TILE(0x11c, 0, 0, 0), TILE(0x11d, 0, 0, 0), COL_EA_SLAB_BOTTOM)
    Metatile("1.6_EA_UNALIGNED_SLAB_H_BR", TILE(0x109, 0, H, 0), TILE(0x10c, 0, H, 0), TILE(0x11d, 0, H, 0), TILE(0x11c, 0, H, 0), COL_EA_SLAB_BOTTOM)
    Metatile("1.6_EA_UNALIGNED_SLAB_H_TL", TILE(0x11c, 0, 0, V), TILE(0x11d, 0, 0, V), TILE(0x10c, 0, 0, V), TILE(0x109, 0, 0, V), COL_EA_SLAB_TOP)
    Metatile("1.6_EA_UNALIGNED_SLAB_H_TR", TILE(0x11d, 0, H, V), TILE(0x11c, 0, H, V), TILE(0x109, 0, H, V), TILE(0x10c, 0, H, V), COL_EA_SLAB_TOP)

    Metatile("1.6_EA_INS_CRN_ALT_BR", TILE(0x10a, 0, 0, 0), TILE(0x10b, 0, 0, 0), TILE(0x11a, 0, 0, 0), TILE(0x11b, 0, 0, 0), COL_EA_CORNER_INSIDE_SLAB_BOTTOM_RIGHT)
    Metatile("1.6_EA_INS_CRN_ALT_BL", TILE(0x10b, 0, H, 0), TILE(0x10a, 0, H, 0), TILE(0x11b, 0, H, 0), TILE(0x11a, 0, H, 0), COL_EA_CORNER_INSIDE_SLAB_BOTTOM_LEFT) // 0x188
    Metatile("1.6_EA_INS_CRN_ALT_TR", TILE(0x11a, 0, 0, V), TILE(0x11b, 0, 0, V), TILE(0x10a, 0, 0, V), TILE(0x10b, 0, 0, V), COL_EA_CORNER_INSIDE_SLAB_TOP_RIGHT)
    Metatile("1.6_EA_INS_CRN_ALT_TL", TILE(0x11b, 0, H, V), TILE(0x11a, 0, H, V), TILE(0x10b, 0, H, V), TILE(0x10a, 0, H, V), COL_EA_CORNER_INSIDE_SLAB_TOP_LEFT)

    Metatile("BREAKABLE_BRICK",     TILE(0xd8, 0, 0, 0), TILE(0xd8, 0, H, 0), TILE(0xd8, 0, 0, V), TILE(0xd8, 0, H, V), BREAKABLE_BRICK)
    Metatile("BREAKABLE_BRICK_ROT", TILE(0xd9, 0, 0, 0), TILE(0xd9, 0, H, 0), TILE(0xd9, 0, 0, V), TILE(0xd9, 0, H, V), BREAKABLE_BRICK)

    Metatile("FADING_BLOCK", TILE(0x120, 0, 0, 0), TILE(0x120, 0, H, 0), TILE(0x120, 0, 0, V), TILE(0x120, 0, H, V), COL_FULL)

    Metatile("FADING_SPIKE_UP",    TILE(0x130, 0, 0, 0), TILE(0x130, 0, H, 0), TILE(0x140, 0, 0, 0), TILE(0x140, 0, H, 0), COL_SPIKE_TOP)
    Metatile("FADING_SPIKE_DOWN",  TILE(0x140, 0, 0, V), TILE(0x140, 0, H, V), TILE(0x130, 0, 0, V), TILE(0x130, 0, H, V), COL_SPIKE_BOTTOM)
    Metatile("FADING_SPIKE_RIGHT", TILE(0x138, 0, 0, 0), TILE(0x139, 0, 0, 0), TILE(0x138, 0, 0, V), TILE(0x139, 0, 0, V), COL_SPIKE_RIGHT) // 0x190
    Metatile("FADING_SPIKE_LEFT",  TILE(0x139, 0, H, 0), TILE(0x138, 0, H, 0), TILE(0x139, 0, H, V), TILE(0x138, 0, H, V), COL_SPIKE_LEFT)

    Metatile("FADING_SMALL_SPIKE_BOTTOM", TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x12c, 0, 0, 0), TILE(0x12c, 0, H, 0), COL_SMALL_SPIKE_BOTTOM)
    Metatile("FADING_SMALL_SPIKE_TOP",    TILE(0x12c, 0, 0, V), TILE(0x12c, 0, H, V), TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), COL_SMALL_SPIKE_TOP)
    Metatile("FADING_SMALL_SPIKE_LEFT",   TILE(0x077, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x077, 0, 0, V), TILE(0x000, 0, 0, 0), COL_SMALL_SPIKE_LEFT)
    Metatile("FADING_SMALL_SPIKE_RIGHT",  TILE(0x000, 0, 0, 0), TILE(0x077, 0, H, 0), TILE(0x000, 0, 0, 0), TILE(0x077, 0, H, V), COL_SMALL_SPIKE_RIGHT)

    Metatile("FADING_MEDIUM_SPIKE_BOTTOM", TILE(0x134, 0, 0, 0), TILE(0x134, 0, H, 0), TILE(0x144, 0, 0, 0), TILE(0x144, 0, H, 0), COL_MEDIUM_SPIKE_BOTTOM)
    Metatile("FADING_MEDIUM_SPIKE_TOP",    TILE(0x144, 0, 0, V), TILE(0x144, 0, H, V), TILE(0x134, 0, 0, V), TILE(0x134, 0, H, V), COL_MEDIUM_SPIKE_TOP)
    Metatile("FADING_MEDIUM_SPIKE_LEFT",   TILE(0x148, 0, 0, 0), TILE(0x149, 0, 0, 0), TILE(0x148, 0, 0, V), TILE(0x149, 0, 0, V), COL_MEDIUM_SPIKE_LEFT) // 0x198
    Metatile("FADING_MEDIUM_SPIKE_RIGHT",  TILE(0x149, 0, H, 0), TILE(0x148, 0, H, 0), TILE(0x149, 0, H, V), TILE(0x148, 0, H, V), COL_MEDIUM_SPIKE_RIGHT)

    Metatile("FADING_CENTER_MINI_BLOCK",   TILE(0x16c, 0, 0, 0), TILE(0x16c, 0, H, 0), TILE(0x16c, 0, 0, V), TILE(0x16c, 0, H, V), COL_CENTERED_MINI_BLOCK)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x1a0
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x1a8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x1b0
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x1b8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    // LBG METATILES

    Metatile("LBG_CHK_FULL",       TILE(0x01, LBG_PAL, 0, 0), TILE(0x01, LBG_PAL, H, 0), TILE(0x01, LBG_PAL, 0, V), TILE(0x01, LBG_PAL, H, V), COL_FULL) // 0x1c0
    Metatile("LBG_CHK_SIDE_UP",    TILE(0x02, LBG_PAL, 0, 0), TILE(0x02, LBG_PAL, H, 0), TILE(0x03, LBG_PAL, 0, 0), TILE(0x03, LBG_PAL, H, 0), COL_FULL)
    Metatile("LBG_CHK_SIDE_DOWN",  TILE(0x03, LBG_PAL, 0, V), TILE(0x03, LBG_PAL, H, V), TILE(0x02, LBG_PAL, 0, V), TILE(0x02, LBG_PAL, H, V), COL_FULL)
    Metatile("LBG_CHK_SIDE_LEFT",  TILE(0x04, LBG_PAL, 0, 0), TILE(0x05, LBG_PAL, 0, 0), TILE(0x04, LBG_PAL, 0, V), TILE(0x05, LBG_PAL, 0, V), COL_FULL)
    Metatile("LBG_CHK_SIDE_RIGHT", TILE(0x05, LBG_PAL, H, 0), TILE(0x04, LBG_PAL, H, 0), TILE(0x05, LBG_PAL, H, V), TILE(0x04, LBG_PAL, H, V), COL_FULL)
    Metatile("LBG_CHK_CORNER_TL",  TILE(0x06, LBG_PAL, 0, 0), TILE(0x02, LBG_PAL, H, 0), TILE(0x04, LBG_PAL, 0, V), TILE(0x07, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_CHK_CORNER_TR",  TILE(0x02, LBG_PAL, 0, 0), TILE(0x06, LBG_PAL, H, 0), TILE(0x07, LBG_PAL, H, 0), TILE(0x04, LBG_PAL, H, V), COL_FULL)
    Metatile("LBG_CHK_CORNER_BL",  TILE(0x04, LBG_PAL, 0, 0), TILE(0x07, LBG_PAL, 0, V), TILE(0x06, LBG_PAL, 0, V), TILE(0x02, LBG_PAL, H, V), COL_FULL)
    Metatile("LBG_CHK_CORNER_BR",  TILE(0x07, LBG_PAL, H, V), TILE(0x04, LBG_PAL, H, 0), TILE(0x02, LBG_PAL, 0, V), TILE(0x06, LBG_PAL, H, V), COL_FULL) // 0x1c8
    Metatile("LBG_CHK_CRN_INS_TL", TILE(0x08, LBG_PAL, 0, 0), TILE(0x05, LBG_PAL, 0, 0), TILE(0x03, LBG_PAL, 0, 0), TILE(0x09, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_CHK_CRN_INS_TR", TILE(0x05, LBG_PAL, H, 0), TILE(0x08, LBG_PAL, H, 0), TILE(0x09, LBG_PAL, H, 0), TILE(0x03, LBG_PAL, H, 0), COL_FULL)
    Metatile("LBG_CHK_CRN_INS_BL", TILE(0x03, LBG_PAL, 0, V), TILE(0x09, LBG_PAL, 0, V), TILE(0x08, LBG_PAL, 0, V), TILE(0x05, LBG_PAL, 0, V), COL_FULL)
    Metatile("LBG_CHK_CRN_INS_BR", TILE(0x09, LBG_PAL, H, V), TILE(0x03, LBG_PAL, H, V), TILE(0x05, LBG_PAL, H, V), TILE(0x08, LBG_PAL, H, V), COL_FULL)
    Metatile("LBG_CHK_DB_CRN_TOP", TILE(0x06, LBG_PAL, 0, 0), TILE(0x06, LBG_PAL, H, 0), TILE(0x04, LBG_PAL, 0, V), TILE(0x04, LBG_PAL, H, V), COL_FULL)
    Metatile("LBG_CHK_DB_CRN_BOT", TILE(0x04, LBG_PAL, 0, 0), TILE(0x04, LBG_PAL, H, 0), TILE(0x06, LBG_PAL, 0, V), TILE(0x06, LBG_PAL, H, V), COL_FULL)
    Metatile("LBG_CHK_DB_CRN_LFT", TILE(0x06, LBG_PAL, 0, 0), TILE(0x02, LBG_PAL, H, 0), TILE(0x06, LBG_PAL, 0, V), TILE(0x02, LBG_PAL, H, V), COL_FULL)
    Metatile("LBG_CHK_DB_CRN_RGT", TILE(0x02, LBG_PAL, 0, 0), TILE(0x06, LBG_PAL, H, 0), TILE(0x02, LBG_PAL, 0, V), TILE(0x06, LBG_PAL, H, V), COL_FULL) // 0x1d0
    Metatile("LBG_CHK_DB_SIDE_V",  TILE(0x04, LBG_PAL, 0, 0), TILE(0x04, LBG_PAL, H, 0), TILE(0x04, LBG_PAL, 0, V), TILE(0x04, LBG_PAL, H, V), COL_FULL)
    Metatile("LBG_CHK_DB_SIDE_H",  TILE(0x02, LBG_PAL, 0, 0), TILE(0x02, LBG_PAL, H, 0), TILE(0x02, LBG_PAL, 0, V), TILE(0x02, LBG_PAL, H, V), COL_FULL)
    Metatile("LBG_CHK_FILLER",     TILE(0x0a, LBG_PAL, 0, 0), TILE(0x0a, LBG_PAL, H, 0), TILE(0x0a, LBG_PAL, 0, V), TILE(0x0a, LBG_PAL, H, V), COL_NONE)

    Metatile("LBG_CHK_CORNER_TL", TILE(0x0B, LBG_PAL, 0, 0), TILE(0x05, LBG_PAL, 0, 0), TILE(0x03, LBG_PAL, 0, 0), TILE(0x09, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_CHK_CORNER_TR", TILE(0x05, LBG_PAL, H, 0), TILE(0x0B, LBG_PAL, H, 0), TILE(0x09, LBG_PAL, H, 0), TILE(0x03, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_CHK_CORNER_BL", TILE(0x03, LBG_PAL, 0, V), TILE(0x09, LBG_PAL, 0, V), TILE(0x0B, LBG_PAL, 0, V), TILE(0x05, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_CHK_CORNER_BR", TILE(0x09, LBG_PAL, H, V), TILE(0x03, LBG_PAL, H, V), TILE(0x05, LBG_PAL, H, V), TILE(0x0B, LBG_PAL, H, V), COL_NONE) // 0x1d8

    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)

    Metatile("LBG_X_FULL",       TILE(0x13, LBG_PAL, 0, 0), TILE(0x14, LBG_PAL, 0, 0), TILE(0x15, LBG_PAL, 0, 0), TILE(0x16, LBG_PAL, 0, 0), COL_FULL) // 0x1e0
    Metatile("LBG_X_SIDE_UP",    TILE(0x17, LBG_PAL, 0, 0), TILE(0x18, LBG_PAL, 0, 0), TILE(0x19, LBG_PAL, 0, 0), TILE(0x1a, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_X_SIDE_DOWN",  TILE(0x19, LBG_PAL, 0, V), TILE(0x1a, LBG_PAL, 0, V), TILE(0x17, LBG_PAL, 0, V), TILE(0x18, LBG_PAL, 0, V), COL_FULL)
    Metatile("LBG_X_SIDE_LEFT",  TILE(0x1b, LBG_PAL, 0, 0), TILE(0x1c, LBG_PAL, 0, 0), TILE(0x1d, LBG_PAL, 0, 0), TILE(0x1a, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_X_SIDE_RIGHT", TILE(0x1c, LBG_PAL, H, 0), TILE(0x1b, LBG_PAL, H, 0), TILE(0x1a, LBG_PAL, H, 0), TILE(0x1d, LBG_PAL, H, 0), COL_FULL)
    Metatile("LBG_X_CORNER_TL",  TILE(0x13, LBG_PAL, 0, 0), TILE(0x18, LBG_PAL, 0, 0), TILE(0x1d, LBG_PAL, 0, 0), TILE(0x1a, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_X_CORNER_TR",  TILE(0x18, LBG_PAL, H, 0), TILE(0x13, LBG_PAL, H, 0), TILE(0x1a, LBG_PAL, H, 0), TILE(0x1d, LBG_PAL, H, 0), COL_FULL)
    Metatile("LBG_X_CORNER_BL",  TILE(0x1d, LBG_PAL, 0, V), TILE(0x1a, LBG_PAL, 0, V), TILE(0x13, LBG_PAL, 0, V), TILE(0x18, LBG_PAL, 0, V), COL_FULL)
    Metatile("LBG_X_CORNER_BR",  TILE(0x1a, LBG_PAL, H, V), TILE(0x1d, LBG_PAL, H, V), TILE(0x18, LBG_PAL, H, V), TILE(0x13, LBG_PAL, H, V), COL_FULL) // 0x1e8
    Metatile("LBG_X_INS_CRN_TL", TILE(0x1e, LBG_PAL, 0, 0), TILE(0x1c, LBG_PAL, 0, 0), TILE(0x19, LBG_PAL, 0, 0), TILE(0x1a, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_X_INS_CRN_TR", TILE(0x22, LBG_PAL, 0, 0), TILE(0x1f, LBG_PAL, 0, 0), TILE(0x19, LBG_PAL, 0, 0), TILE(0x1a, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_X_INS_CRN_BL", TILE(0x22, LBG_PAL, 0, 0), TILE(0x1c, LBG_PAL, 0, 0), TILE(0x20, LBG_PAL, 0, 0), TILE(0x1a, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_X_INS_CRN_BR", TILE(0x22, LBG_PAL, 0, 0), TILE(0x1c, LBG_PAL, 0, 0), TILE(0x19, LBG_PAL, 0, 0), TILE(0x21, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_X_FILLER",     TILE(0x22, LBG_PAL, 0, 0), TILE(0x1c, LBG_PAL, 0, 0), TILE(0x19, LBG_PAL, 0, 0), TILE(0x1a, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_X_DB_CRN_TOP", TILE(0x13, LBG_PAL, 0, 0), TILE(0x14, LBG_PAL, 0, 0), TILE(0x1d, LBG_PAL, 0, 0), TILE(0x23, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_X_DB_CRN_BOT", TILE(0x1b, LBG_PAL, 0, 0), TILE(0x25, LBG_PAL, 0, 0), TILE(0x15, LBG_PAL, 0, 0), TILE(0x16, LBG_PAL, 0, 0), COL_FULL)
        
    Metatile("LBG_X_DB_CRN_LFT", TILE(0x13, LBG_PAL, 0, 0), TILE(0x18, LBG_PAL, 0, 0), TILE(0x15, LBG_PAL, 0, 0), TILE(0x24, LBG_PAL, 0, 0), COL_FULL) // 0x1f0
    Metatile("LBG_X_DB_CRN_RGT", TILE(0x18, LBG_PAL, H, 0), TILE(0x13, LBG_PAL, H, 0), TILE(0x24, LBG_PAL, H, 0), TILE(0x15, LBG_PAL, H, 0), COL_FULL)
    Metatile("LBG_X_DB_SIDE_V",  TILE(0x1b, LBG_PAL, 0, 0), TILE(0x25, LBG_PAL, 0, 0), TILE(0x1d, LBG_PAL, 0, 0), TILE(0x23, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_X_DB_SIDE_H",  TILE(0x17, LBG_PAL, 0, 0), TILE(0x18, LBG_PAL, 0, 0), TILE(0x12, LBG_PAL, 0, 0), TILE(0x24, LBG_PAL, 0, 0), COL_FULL)
    
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE) // 0x1f8
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)

    Metatile("LBG_+_FULL",       TILE(0x2a, LBG_PAL, 0, 0), TILE(0x2b, LBG_PAL, 0, 0), TILE(0x2c, LBG_PAL, 0, 0), TILE(0x2d, LBG_PAL, 0, 0), COL_FULL) // 0x200
    Metatile("LBG_+_SIDE_UP",    TILE(0x2e, LBG_PAL, 0, 0), TILE(0x2f, LBG_PAL, 0, 0), TILE(0x30, LBG_PAL, 0, 0), TILE(0x31, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_+_SIDE_DOWN",  TILE(0x30, LBG_PAL, 0, V), TILE(0x31, LBG_PAL, 0, V), TILE(0x2e, LBG_PAL, 0, V), TILE(0x2f, LBG_PAL, 0, V), COL_FULL)
    Metatile("LBG_+_SIDE_LEFT",  TILE(0x32, LBG_PAL, 0, 0), TILE(0x33, LBG_PAL, 0, 0), TILE(0x34, LBG_PAL, 0, 0), TILE(0x31, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_+_SIDE_RIGHT", TILE(0x33, LBG_PAL, H, 0), TILE(0x32, LBG_PAL, H, 0), TILE(0x31, LBG_PAL, H, 0), TILE(0x34, LBG_PAL, H, 0), COL_FULL)
    Metatile("LBG_+_CORNER_TL",  TILE(0x2a, LBG_PAL, 0, 0), TILE(0x2f, LBG_PAL, 0, 0), TILE(0x34, LBG_PAL, 0, 0), TILE(0x31, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_+_CORNER_TR",  TILE(0x2f, LBG_PAL, H, 0), TILE(0x2a, LBG_PAL, H, 0), TILE(0x31, LBG_PAL, H, 0), TILE(0x34, LBG_PAL, H, 0), COL_FULL)
    Metatile("LBG_+_CORNER_BL",  TILE(0x34, LBG_PAL, 0, V), TILE(0x31, LBG_PAL, 0, V), TILE(0x2a, LBG_PAL, 0, V), TILE(0x2f, LBG_PAL, 0, V), COL_FULL)
    Metatile("LBG_+_CORNER_BR",  TILE(0x31, LBG_PAL, H, V), TILE(0x34, LBG_PAL, H, V), TILE(0x2f, LBG_PAL, H, V), TILE(0x2a, LBG_PAL, H, V), COL_FULL) // 0x208
    Metatile("LBG_+_FILLER",     TILE(0x35, LBG_PAL, 0, 0), TILE(0x33, LBG_PAL, 0, 0), TILE(0x30, LBG_PAL, 0, 0), TILE(0x31, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_+_DB_CRN_TOP", TILE(0x2a, LBG_PAL, 0, 0), TILE(0x2b, LBG_PAL, 0, 0), TILE(0x34, LBG_PAL, 0, 0), TILE(0x36, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_+_DB_CRN_BOT", TILE(0x34, LBG_PAL, 0, V), TILE(0x36, LBG_PAL, 0, V), TILE(0x2a, LBG_PAL, 0, V), TILE(0x2b, LBG_PAL, 0, V), COL_FULL)
    Metatile("LBG_+_DB_CRN_LFT", TILE(0x2a, LBG_PAL, 0, 0), TILE(0x2f, LBG_PAL, 0, 0), TILE(0x2c, LBG_PAL, 0, 0), TILE(0x37, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_+_DB_CRN_RGT", TILE(0x2f, LBG_PAL, H, 0), TILE(0x2a, LBG_PAL, H, 0), TILE(0x39, LBG_PAL, 0, 0), TILE(0x2d, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_+_DB_SIDE_V",  TILE(0x32, LBG_PAL, 0, 0), TILE(0x38, LBG_PAL, 0, 0), TILE(0x34, LBG_PAL, 0, 0), TILE(0x36, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_+_DB_SIDE_H",  TILE(0x2e, LBG_PAL, 0, 0), TILE(0x2f, LBG_PAL, 0, 0), TILE(0x39, LBG_PAL, 0, 0), TILE(0x37, LBG_PAL, 0, 0), COL_FULL)
    
    Metatile("LBG_BLK_FULL",        TILE(0x3b, LBG_PAL, 0, 0), TILE(0x3b, LBG_PAL, H, 0), TILE(0x3b, LBG_PAL, 0, V), TILE(0x3b, LBG_PAL, H, V), COL_FULL) // 0x210
    Metatile("LBG_BLK_SIDE_TOP",    TILE(0x3c, LBG_PAL, 0, 0), TILE(0x3c, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_BLK_SIDE_BOTTOM", TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3c, LBG_PAL, 0, V), TILE(0x3c, LBG_PAL, 0, V), COL_FULL)
    Metatile("LBG_BLK_SIDE_LEFT",   TILE(0x3d, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3d, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_BLK_SIDE_RIGHT",  TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3d, LBG_PAL, H, 0), TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3d, LBG_PAL, H, 0), COL_FULL)
    Metatile("LBG_BLK_CORNER_TL",   TILE(0x3b, LBG_PAL, 0, 0), TILE(0x3c, LBG_PAL, 0, 0), TILE(0x3d, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_BLK_CORNER_TR",   TILE(0x3c, LBG_PAL, H, 0), TILE(0x3b, LBG_PAL, H, 0), TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3d, LBG_PAL, H, 0), COL_FULL)
    Metatile("LBG_BLK_CORNER_BL",   TILE(0x3d, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3b, LBG_PAL, 0, V), TILE(0x3c, LBG_PAL, 0, V), COL_FULL)
    Metatile("LBG_BLK_CORNER_BR",   TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3d, LBG_PAL, H, 0), TILE(0x3c, LBG_PAL, 0, V), TILE(0x3b, LBG_PAL, H, V), COL_FULL) // 0x218
    Metatile("LBG_BLK_INS_CRN_TL",  TILE(0x3e, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_BLK_INS_CRN_TR",  TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3e, LBG_PAL, H, 0), TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_BLK_INS_CRN_BL",  TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3e, LBG_PAL, 0, V), TILE(0x3a, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_BLK_INS_CRN_BR",  TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3e, LBG_PAL, V, H), COL_FULL)
    Metatile("LBG_BLK_FILLER",      TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_BLK_DB_CRN_TOP",  TILE(0x3b, LBG_PAL, 0, 0), TILE(0x3b, LBG_PAL, H, 0), TILE(0x3d, LBG_PAL, 0, 0), TILE(0x3d, LBG_PAL, H, 0), COL_FULL)
    Metatile("LBG_BLK_DB_CRN_BOT",  TILE(0x3d, LBG_PAL, 0, 0), TILE(0x3d, LBG_PAL, H, 0), TILE(0x3b, LBG_PAL, 0, V), TILE(0x3b, LBG_PAL, H, V), COL_FULL)

    Metatile("LBG_BLK_DB_CRN_LFT",  TILE(0x3b, LBG_PAL, 0, 0), TILE(0x3c, LBG_PAL, 0, 0), TILE(0x3b, LBG_PAL, 0, V), TILE(0x3c, LBG_PAL, 0, V), COL_FULL) // 0x220
    Metatile("LBG_BLK_DB_CRN_RGT",  TILE(0x3c, LBG_PAL, 0, 0), TILE(0x3b, LBG_PAL, H, 0), TILE(0x3c, LBG_PAL, 0, V), TILE(0x3b, LBG_PAL, H, V), COL_FULL)
    Metatile("LBG_BLK_DB_SIDE_H",   TILE(0x3d, LBG_PAL, 0, 0), TILE(0x3d, LBG_PAL, H, 0), TILE(0x3d, LBG_PAL, 0, 0), TILE(0x3d, LBG_PAL, H, 0), COL_FULL)
    Metatile("LBG_BLK_DB_SIDE_V",   TILE(0x3c, LBG_PAL, 0, 0), TILE(0x3c, LBG_PAL, 0, 0), TILE(0x3c, LBG_PAL, 0, V), TILE(0x3c, LBG_PAL, 0, V), COL_FULL)

    Metatile("LBG_BLK_SLAB_TOP",    TILE(0x26, LBG_PAL, 0, 0), TILE(0x26, LBG_PAL, H, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), COL_SLAB_TOP)
    Metatile("LBG_BLK_SLAB_BOT",    TILE(0x00, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x26, LBG_PAL, 0, 0), TILE(0x26, LBG_PAL, H, 0), COL_SLAB_BOTTOM)
    Metatile("LBG_BLK_SLAB_LFT",    TILE(0x27, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x27, LBG_PAL, 0, V), TILE(0x00, LBG_PAL, 0, 0), COL_SLAB_LEFT)
    Metatile("LBG_BLK_SLAB_RGT",    TILE(0x00, LBG_PAL, 0, 0), TILE(0x27, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x27, LBG_PAL, 0, V), COL_SLAB_RIGHT)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x228
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    
    Metatile("LBG_BRICKS_FULL",        TILE(0x3f, LBG_PAL, 0, 0), TILE(0x3f, LBG_PAL, H, 0), TILE(0x40, LBG_PAL, 0, 0), TILE(0x41, LBG_PAL, 0, 0), COL_FULL) // 0x230
    Metatile("LBG_BRICKS_SIDE_TOP",    TILE(0x42, LBG_PAL, 0, 0), TILE(0x42, LBG_PAL, H, 0), TILE(0x43, LBG_PAL, 0, 0), TILE(0x44, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_BRICKS_SIDE_BOTTOM", TILE(0x43, LBG_PAL, 0, V), TILE(0x44, LBG_PAL, 0, V), TILE(0x42, LBG_PAL, 0, V), TILE(0x42, LBG_PAL, H, V), COL_FULL)
    Metatile("LBG_BRICKS_SIDE_LEFT",   TILE(0x45, LBG_PAL, 0, 0), TILE(0x46, LBG_PAL, 0, 0), TILE(0x47, LBG_PAL, 0, 0), TILE(0x44, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_BRICKS_SIDE_RIGHT",  TILE(0x46, LBG_PAL, H, 0), TILE(0x45, LBG_PAL, H, 0), TILE(0x44, LBG_PAL, H, 0), TILE(0x47, LBG_PAL, H, 0), COL_FULL)
    Metatile("LBG_BRICKS_CORNER_TL",   TILE(0x3f, LBG_PAL, 0, 0), TILE(0x42, LBG_PAL, H, 0), TILE(0x47, LBG_PAL, 0, 0), TILE(0x44, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_BRICKS_CORNER_TR",   TILE(0x42, LBG_PAL, 0, 0), TILE(0x3f, LBG_PAL, H, 0), TILE(0x44, LBG_PAL, H, 0), TILE(0x47, LBG_PAL, H, 0), COL_FULL)
    Metatile("LBG_BRICKS_CORNER_BL",   TILE(0x47, LBG_PAL, 0, V), TILE(0x44, LBG_PAL, 0, V), TILE(0x3f, LBG_PAL, 0, V), TILE(0x42, LBG_PAL, H, V), COL_FULL)
    Metatile("LBG_BRICKS_CORNER_BR",   TILE(0x44, LBG_PAL, H, V), TILE(0x47, LBG_PAL, H, V), TILE(0x42, LBG_PAL, 0, V), TILE(0x3f, LBG_PAL, H, V), COL_FULL) // 0x238
    Metatile("LBG_BRICKS_INS_CRN_TL",  TILE(0x48, LBG_PAL, 0, 0), TILE(0x46, LBG_PAL, 0, 0), TILE(0x43, LBG_PAL, 0, 0), TILE(0x44, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_BRICKS_INS_CRN_TR",  TILE(0x46, LBG_PAL, H, 0), TILE(0x48, LBG_PAL, H, 0), TILE(0x43, LBG_PAL, 0, 0), TILE(0x44, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_BRICKS_INS_CRN_BL",  TILE(0x43, LBG_PAL, 0, V), TILE(0x44, LBG_PAL, 0, V), TILE(0x48, LBG_PAL, 0, V), TILE(0x46, LBG_PAL, 0, V), COL_FULL)
    Metatile("LBG_BRICKS_INS_CRN_BR",  TILE(0x43, LBG_PAL, 0, V), TILE(0x44, LBG_PAL, 0, V), TILE(0x46, LBG_PAL, H, V), TILE(0x48, LBG_PAL, H, V), COL_FULL)
    Metatile("LBG_BRICKS_FILLER",      TILE(0x46, LBG_PAL, H, 0), TILE(0x46, LBG_PAL, 0, 0), TILE(0x43, LBG_PAL, 0, 0), TILE(0x44, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_BRICKS_DB_CRN_TOP",  TILE(0x3f, LBG_PAL, 0, 0), TILE(0x3f, LBG_PAL, H, 0), TILE(0x47, LBG_PAL, 0, 0), TILE(0x4b, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_BRICKS_DB_CRN_BOT",  TILE(0x47, LBG_PAL, 0, V), TILE(0x4b, LBG_PAL, 0, V), TILE(0x3f, LBG_PAL, 0, V), TILE(0x3f, LBG_PAL, H, V), COL_FULL)

    Metatile("LBG_BRICKS_DB_CRN_LFT",  TILE(0x3f, LBG_PAL, 0, 0), TILE(0x42, LBG_PAL, H, 0), TILE(0x40, LBG_PAL, 0, 0), TILE(0x4c, LBG_PAL, 0, 0), COL_FULL) // 0x240
    Metatile("LBG_BRICKS_DB_CRN_RGT",  TILE(0x42, LBG_PAL, 0, 0), TILE(0x3f, LBG_PAL, H, 0), TILE(0x4c, LBG_PAL, H, 0), TILE(0x40, LBG_PAL, H, 0), COL_FULL)
    Metatile("LBG_BRICKS_SIDE_H",      TILE(0x45, LBG_PAL, 0, 0), TILE(0x45, LBG_PAL, H, 0), TILE(0x45, LBG_PAL, 0, 0), TILE(0x4b, LBG_PAL, 0, 0), COL_FULL)
    Metatile("LBG_BRICKS_SIDE_V",      TILE(0x42, LBG_PAL, 0, 0), TILE(0x42, LBG_PAL, H, 0), TILE(0x4d, LBG_PAL, 0, 0), TILE(0x4c, LBG_PAL, 0, 0), COL_FULL)

    Metatile("LBG_SPIKE_UP",            TILE(0x165, LBG_PAL, 0, 0), TILE(0x165, LBG_PAL, H, 0), TILE(0x175, LBG_PAL, 0, 0), TILE(0x175, LBG_PAL, H, 0), COL_SPIKE_TOP)
    Metatile("LBG_SPIKE_DOWN",          TILE(0x175, LBG_PAL, 0, V), TILE(0x175, LBG_PAL, H, V), TILE(0x165, LBG_PAL, 0, V), TILE(0x165, LBG_PAL, H, V), COL_SPIKE_BOTTOM)
    Metatile("LBG_SPIKE_LEFT",          TILE(0x166, LBG_PAL, 0, 0), TILE(0x167, LBG_PAL, 0, 0), TILE(0x166, LBG_PAL, 0, V), TILE(0x167, LBG_PAL, 0, V), COL_SPIKE_LEFT)
    Metatile("LBG_SPIKE_RIGHT",         TILE(0x167, LBG_PAL, H, 0), TILE(0x166, LBG_PAL, H, 0), TILE(0x167, LBG_PAL, H, V), TILE(0x166, LBG_PAL, H, V), COL_SPIKE_RIGHT)
    Metatile("LBG_SMALL_SPIKE_BOTTOM",  TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x16a, LBG_PAL, 0, 0), TILE(0x16a, LBG_PAL, H, 0), COL_SMALL_SPIKE_BOTTOM) // 0x248
    Metatile("LBG_SMALL_SPIKE_TOP",     TILE(0x16a, LBG_PAL, 0, V), TILE(0x16a, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_SMALL_SPIKE_TOP)
    Metatile("LBG_SMALL_SPIKE_LEFT",    TILE(0x17a, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x17a, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, 0), COL_SMALL_SPIKE_LEFT)
    Metatile("LBG_SMALL_SPIKE_RIGHT",   TILE(0x000, LBG_PAL, 0, 0), TILE(0x17a, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x17a, LBG_PAL, H, V), COL_SMALL_SPIKE_RIGHT)
    Metatile("LBG_MEDIUM_SPIKE_BOTTOM", TILE(0x168, LBG_PAL, 0, 0), TILE(0x168, LBG_PAL, H, 0), TILE(0x178, LBG_PAL, 0, 0), TILE(0x178, LBG_PAL, H, 0), COL_MEDIUM_SPIKE_BOTTOM)
    Metatile("LBG_MEDIUM_SPIKE_TOP",    TILE(0x178, LBG_PAL, 0, V), TILE(0x178, LBG_PAL, H, V), TILE(0x168, LBG_PAL, 0, V), TILE(0x168, LBG_PAL, H, V), COL_MEDIUM_SPIKE_TOP)
    Metatile("LBG_MEDIUM_SPIKE_LEFT",   TILE(0x179, LBG_PAL, 0, 0), TILE(0x169, LBG_PAL, 0, 0), TILE(0x179, LBG_PAL, 0, V), TILE(0x169, LBG_PAL, 0, V), COL_MEDIUM_SPIKE_LEFT)
    Metatile("LBG_MEDIUM_SPIKE_RIGHT",  TILE(0x169, LBG_PAL, H, 0), TILE(0x179, LBG_PAL, H, 0), TILE(0x169, LBG_PAL, H, V), TILE(0x179, LBG_PAL, H, V), COL_MEDIUM_SPIKE_RIGHT)

    Metatile("LBG_SLOPE_45_UP",      TILE(0x00, LBG_PAL, 0, 0), TILE(0x7b, LBG_PAL, 0, 0), TILE(0x7b, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), COL_SLOPE_45_UP) // 0x250
    Metatile("LBG_SLOPE_45_DOWN",    TILE(0x7b, LBG_PAL, H, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, H, 0), TILE(0x7b, LBG_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("LBG_SLOPE_45_UP_UD",   TILE(0x7b, LBG_PAL, 0, V), TILE(0x3a, LBG_PAL, 0, V), TILE(0x00, LBG_PAL, 0, V), TILE(0x7b, LBG_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("LBG_SLOPE_45_DOWN_UD", TILE(0x3a, LBG_PAL, H, V), TILE(0x7b, LBG_PAL, H, V), TILE(0x7b, LBG_PAL, H, V), TILE(0x00, LBG_PAL, 0, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("LBG_22_UP_1",          TILE(0x00, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x7c, LBG_PAL, 0, 0), TILE(0x7d, LBG_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("LBG_22_UP_2",          TILE(0x7c, LBG_PAL, 0, 0), TILE(0x7d, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("LBG_22_DOWN_1",        TILE(0x7d, LBG_PAL, H, 0), TILE(0x7c, LBG_PAL, H, 0), TILE(0x3a, LBG_PAL, H, 0), TILE(0x3a, LBG_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("LBG_22_DOWN_2",        TILE(0x00, LBG_PAL, H, 0), TILE(0x00, LBG_PAL, H, 0), TILE(0x7d, LBG_PAL, H, 0), TILE(0x7c, LBG_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("LBG_22_UP_UD_1",       TILE(0x7c, LBG_PAL, 0, V), TILE(0x7d, LBG_PAL, 0, V), TILE(0x00, LBG_PAL, 0, V), TILE(0x00, LBG_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x258
    Metatile("LBG_22_UP_UD_2",       TILE(0x3a, LBG_PAL, 0, V), TILE(0x3a, LBG_PAL, 0, V), TILE(0x7c, LBG_PAL, 0, V), TILE(0x7d, LBG_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("LBG_22_DOWN_UD_1",     TILE(0x3a, LBG_PAL, H, V), TILE(0x3a, LBG_PAL, H, V), TILE(0x7d, LBG_PAL, H, V), TILE(0x7c, LBG_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("LBG_22_DOWN_UD_2",     TILE(0x7d, LBG_PAL, H, V), TILE(0x7c, LBG_PAL, H, V), TILE(0x00, LBG_PAL, H, V), TILE(0x00, LBG_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("LBG_66_UP_1",          TILE(0x00, LBG_PAL, 0, 0), TILE(0x7f, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x7e, LBG_PAL, 0, 0), COL_SLOPE_66_UP_1) 
    Metatile("LBG_66_UP_2",          TILE(0x7f, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), TILE(0x7e, LBG_PAL, 0, 0), TILE(0x3a, LBG_PAL, 0, 0), COL_SLOPE_66_UP_2)
    Metatile("LBG_66_DOWN_1",        TILE(0x3a, LBG_PAL, H, 0), TILE(0x7f, LBG_PAL, H, 0), TILE(0x3a, LBG_PAL, H, 0), TILE(0x7e, LBG_PAL, H, 0), COL_SLOPE_66_DOWN_1)
    Metatile("LBG_66_DOWN_2",        TILE(0x7f, LBG_PAL, H, 0), TILE(0x00, LBG_PAL, H, 0), TILE(0x7e, LBG_PAL, H, 0), TILE(0x00, LBG_PAL, H, 0), COL_SLOPE_66_DOWN_2)
    Metatile("LBG_66_UP_UD_1",       TILE(0x00, LBG_PAL, 0, V), TILE(0x7e, LBG_PAL, 0, V), TILE(0x00, LBG_PAL, 0, V), TILE(0x7f, LBG_PAL, 0, V), COL_SLOPE_66_UP_UD_1) // 0x260
    Metatile("LBG_66_UP_UD_2",       TILE(0x7e, LBG_PAL, 0, V), TILE(0x3a, LBG_PAL, 0, V), TILE(0x7f, LBG_PAL, 0, V), TILE(0x3a, LBG_PAL, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("LBG_66_DOWN_UD_1",     TILE(0x3a, LBG_PAL, H, V), TILE(0x7e, LBG_PAL, H, V), TILE(0x3a, LBG_PAL, H, V), TILE(0x7f, LBG_PAL, H, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("LBG_66_DOWN_UD_2",     TILE(0x7e, LBG_PAL, H, V), TILE(0x00, LBG_PAL, H, V), TILE(0x7f, LBG_PAL, H, V), TILE(0x00, LBG_PAL, H, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x268
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    // COL1 METATILES

    Metatile("COL1_CHK_FULL",       TILE(0x01, COL1_PAL, 0, 0), TILE(0x01, COL1_PAL, H, 0), TILE(0x01, COL1_PAL, 0, V), TILE(0x01, COL1_PAL, H, V), COL_FULL) // 0x270
    Metatile("COL1_CHK_SIDE_UP",    TILE(0x02, COL1_PAL, 0, 0), TILE(0x02, COL1_PAL, H, 0), TILE(0x03, COL1_PAL, 0, 0), TILE(0x03, COL1_PAL, H, 0), COL_FULL)
    Metatile("COL1_CHK_SIDE_DOWN",  TILE(0x03, COL1_PAL, 0, V), TILE(0x03, COL1_PAL, H, V), TILE(0x02, COL1_PAL, 0, V), TILE(0x02, COL1_PAL, H, V), COL_FULL)
    Metatile("COL1_CHK_SIDE_LEFT",  TILE(0x04, COL1_PAL, 0, 0), TILE(0x05, COL1_PAL, 0, 0), TILE(0x04, COL1_PAL, 0, V), TILE(0x05, COL1_PAL, 0, V), COL_FULL)
    Metatile("COL1_CHK_SIDE_RIGHT", TILE(0x05, COL1_PAL, H, 0), TILE(0x04, COL1_PAL, H, 0), TILE(0x05, COL1_PAL, H, V), TILE(0x04, COL1_PAL, H, V), COL_FULL)
    Metatile("COL1_CHK_CORNER_TL",  TILE(0x06, COL1_PAL, 0, 0), TILE(0x02, COL1_PAL, H, 0), TILE(0x04, COL1_PAL, 0, V), TILE(0x07, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_CHK_CORNER_TR",  TILE(0x02, COL1_PAL, 0, 0), TILE(0x06, COL1_PAL, H, 0), TILE(0x07, COL1_PAL, H, 0), TILE(0x04, COL1_PAL, H, V), COL_FULL)
    Metatile("COL1_CHK_CORNER_BL",  TILE(0x04, COL1_PAL, 0, 0), TILE(0x07, COL1_PAL, 0, V), TILE(0x06, COL1_PAL, 0, V), TILE(0x02, COL1_PAL, H, V), COL_FULL)
    Metatile("COL1_CHK_CORNER_BR",  TILE(0x07, COL1_PAL, H, V), TILE(0x04, COL1_PAL, H, 0), TILE(0x02, COL1_PAL, 0, V), TILE(0x06, COL1_PAL, H, V), COL_FULL) // 0x278
    Metatile("COL1_CHK_CRN_INS_TL", TILE(0x08, COL1_PAL, 0, 0), TILE(0x05, COL1_PAL, 0, 0), TILE(0x03, COL1_PAL, 0, 0), TILE(0x09, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_CHK_CRN_INS_TR", TILE(0x05, COL1_PAL, H, 0), TILE(0x08, COL1_PAL, H, 0), TILE(0x09, COL1_PAL, H, 0), TILE(0x03, COL1_PAL, H, 0), COL_FULL)
    Metatile("COL1_CHK_CRN_INS_BL", TILE(0x03, COL1_PAL, 0, V), TILE(0x09, COL1_PAL, 0, V), TILE(0x08, COL1_PAL, 0, V), TILE(0x05, COL1_PAL, 0, V), COL_FULL)
    Metatile("COL1_CHK_CRN_INS_BR", TILE(0x09, COL1_PAL, H, V), TILE(0x03, COL1_PAL, H, V), TILE(0x05, COL1_PAL, H, V), TILE(0x08, COL1_PAL, H, V), COL_FULL)
    Metatile("COL1_CHK_DB_CRN_TOP", TILE(0x06, COL1_PAL, 0, 0), TILE(0x06, COL1_PAL, H, 0), TILE(0x04, COL1_PAL, 0, V), TILE(0x04, COL1_PAL, H, V), COL_FULL)
    Metatile("COL1_CHK_DB_CRN_BOT", TILE(0x04, COL1_PAL, 0, 0), TILE(0x04, COL1_PAL, H, 0), TILE(0x06, COL1_PAL, 0, V), TILE(0x06, COL1_PAL, H, V), COL_FULL)
    Metatile("COL1_CHK_DB_CRN_LFT", TILE(0x06, COL1_PAL, 0, 0), TILE(0x02, COL1_PAL, H, 0), TILE(0x06, COL1_PAL, 0, V), TILE(0x02, COL1_PAL, H, V), COL_FULL)
    Metatile("COL1_CHK_DB_CRN_RGT", TILE(0x02, COL1_PAL, 0, 0), TILE(0x06, COL1_PAL, H, 0), TILE(0x02, COL1_PAL, 0, V), TILE(0x06, COL1_PAL, H, V), COL_FULL) // 0x280
    Metatile("COL1_CHK_DB_SIDE_V",  TILE(0x04, COL1_PAL, 0, 0), TILE(0x04, COL1_PAL, H, 0), TILE(0x04, COL1_PAL, 0, V), TILE(0x04, COL1_PAL, H, V), COL_FULL)
    Metatile("COL1_CHK_DB_SIDE_H",  TILE(0x02, COL1_PAL, 0, 0), TILE(0x02, COL1_PAL, H, 0), TILE(0x02, COL1_PAL, 0, V), TILE(0x02, COL1_PAL, H, V), COL_FULL)
    Metatile("COL1_CHK_FILLER",     TILE(0x0a, COL1_PAL, 0, 0), TILE(0x0a, COL1_PAL, H, 0), TILE(0x0a, COL1_PAL, 0, V), TILE(0x0a, COL1_PAL, H, V), COL_NONE)

    Metatile("COL1_CHK_CORNER_TL", TILE(0x0B, COL1_PAL, 0, 0), TILE(0x05, COL1_PAL, 0, 0), TILE(0x03, COL1_PAL, 0, 0), TILE(0x09, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_CHK_CORNER_TR", TILE(0x05, COL1_PAL, H, 0), TILE(0x0B, COL1_PAL, H, 0), TILE(0x09, COL1_PAL, H, 0), TILE(0x03, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_CHK_CORNER_BL", TILE(0x03, COL1_PAL, 0, V), TILE(0x09, COL1_PAL, 0, V), TILE(0x0B, COL1_PAL, 0, V), TILE(0x05, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_CHK_CORNER_BR", TILE(0x09, COL1_PAL, H, V), TILE(0x03, COL1_PAL, H, V), TILE(0x05, COL1_PAL, H, V), TILE(0x0B, COL1_PAL, H, V), COL_NONE) // 0x288

    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)

    Metatile("COL1_X_FULL",       TILE(0x13, COL1_PAL, 0, 0), TILE(0x14, COL1_PAL, 0, 0), TILE(0x15, COL1_PAL, 0, 0), TILE(0x16, COL1_PAL, 0, 0), COL_FULL) // 0x290
    Metatile("COL1_X_SIDE_UP",    TILE(0x17, COL1_PAL, 0, 0), TILE(0x18, COL1_PAL, 0, 0), TILE(0x19, COL1_PAL, 0, 0), TILE(0x1a, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_X_SIDE_DOWN",  TILE(0x19, COL1_PAL, 0, V), TILE(0x1a, COL1_PAL, 0, V), TILE(0x17, COL1_PAL, 0, V), TILE(0x18, COL1_PAL, 0, V), COL_FULL)
    Metatile("COL1_X_SIDE_LEFT",  TILE(0x1b, COL1_PAL, 0, 0), TILE(0x1c, COL1_PAL, 0, 0), TILE(0x1d, COL1_PAL, 0, 0), TILE(0x1a, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_X_SIDE_RIGHT", TILE(0x1c, COL1_PAL, H, 0), TILE(0x1b, COL1_PAL, H, 0), TILE(0x1a, COL1_PAL, H, 0), TILE(0x1d, COL1_PAL, H, 0), COL_FULL)
    Metatile("COL1_X_CORNER_TL",  TILE(0x13, COL1_PAL, 0, 0), TILE(0x18, COL1_PAL, 0, 0), TILE(0x1d, COL1_PAL, 0, 0), TILE(0x1a, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_X_CORNER_TR",  TILE(0x18, COL1_PAL, H, 0), TILE(0x13, COL1_PAL, H, 0), TILE(0x1a, COL1_PAL, H, 0), TILE(0x1d, COL1_PAL, H, 0), COL_FULL)
    Metatile("COL1_X_CORNER_BL",  TILE(0x1d, COL1_PAL, 0, V), TILE(0x1a, COL1_PAL, 0, V), TILE(0x13, COL1_PAL, 0, V), TILE(0x18, COL1_PAL, 0, V), COL_FULL)
    Metatile("COL1_X_CORNER_BR",  TILE(0x1a, COL1_PAL, H, V), TILE(0x1d, COL1_PAL, H, V), TILE(0x18, COL1_PAL, H, V), TILE(0x13, COL1_PAL, H, V), COL_FULL) // 0x298
    Metatile("COL1_X_INS_CRN_TL", TILE(0x1e, COL1_PAL, 0, 0), TILE(0x1c, COL1_PAL, 0, 0), TILE(0x19, COL1_PAL, 0, 0), TILE(0x1a, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_X_INS_CRN_TR", TILE(0x22, COL1_PAL, 0, 0), TILE(0x1f, COL1_PAL, 0, 0), TILE(0x19, COL1_PAL, 0, 0), TILE(0x1a, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_X_INS_CRN_BL", TILE(0x22, COL1_PAL, 0, 0), TILE(0x1c, COL1_PAL, 0, 0), TILE(0x20, COL1_PAL, 0, 0), TILE(0x1a, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_X_INS_CRN_BR", TILE(0x22, COL1_PAL, 0, 0), TILE(0x1c, COL1_PAL, 0, 0), TILE(0x19, COL1_PAL, 0, 0), TILE(0x21, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_X_FILLER",     TILE(0x22, COL1_PAL, 0, 0), TILE(0x1c, COL1_PAL, 0, 0), TILE(0x19, COL1_PAL, 0, 0), TILE(0x1a, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_X_DB_CRN_TOP", TILE(0x13, COL1_PAL, 0, 0), TILE(0x14, COL1_PAL, 0, 0), TILE(0x1d, COL1_PAL, 0, 0), TILE(0x23, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_X_DB_CRN_BOT", TILE(0x1b, COL1_PAL, 0, 0), TILE(0x25, COL1_PAL, 0, 0), TILE(0x15, COL1_PAL, 0, 0), TILE(0x16, COL1_PAL, 0, 0), COL_FULL)
        
    Metatile("COL1_X_DB_CRN_LFT", TILE(0x13, COL1_PAL, 0, 0), TILE(0x18, COL1_PAL, 0, 0), TILE(0x15, COL1_PAL, 0, 0), TILE(0x24, COL1_PAL, 0, 0), COL_FULL) // 0x2a0
    Metatile("COL1_X_DB_CRN_RGT", TILE(0x18, COL1_PAL, H, 0), TILE(0x13, COL1_PAL, H, 0), TILE(0x24, COL1_PAL, H, 0), TILE(0x15, COL1_PAL, H, 0), COL_FULL)
    Metatile("COL1_X_DB_SIDE_V",  TILE(0x1b, COL1_PAL, 0, 0), TILE(0x25, COL1_PAL, 0, 0), TILE(0x1d, COL1_PAL, 0, 0), TILE(0x23, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_X_DB_SIDE_H",  TILE(0x17, COL1_PAL, 0, 0), TILE(0x18, COL1_PAL, 0, 0), TILE(0x12, COL1_PAL, 0, 0), TILE(0x24, COL1_PAL, 0, 0), COL_FULL)
    
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE) // 0x2a8
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)

    Metatile("COL1_+_FULL",       TILE(0x2a, COL1_PAL, 0, 0), TILE(0x2b, COL1_PAL, 0, 0), TILE(0x2c, COL1_PAL, 0, 0), TILE(0x2d, COL1_PAL, 0, 0), COL_FULL) // 0x2b0
    Metatile("COL1_+_SIDE_UP",    TILE(0x2e, COL1_PAL, 0, 0), TILE(0x2f, COL1_PAL, 0, 0), TILE(0x30, COL1_PAL, 0, 0), TILE(0x31, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_+_SIDE_DOWN",  TILE(0x30, COL1_PAL, 0, V), TILE(0x31, COL1_PAL, 0, V), TILE(0x2e, COL1_PAL, 0, V), TILE(0x2f, COL1_PAL, 0, V), COL_FULL)
    Metatile("COL1_+_SIDE_LEFT",  TILE(0x32, COL1_PAL, 0, 0), TILE(0x33, COL1_PAL, 0, 0), TILE(0x34, COL1_PAL, 0, 0), TILE(0x31, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_+_SIDE_RIGHT", TILE(0x33, COL1_PAL, H, 0), TILE(0x32, COL1_PAL, H, 0), TILE(0x31, COL1_PAL, H, 0), TILE(0x34, COL1_PAL, H, 0), COL_FULL)
    Metatile("COL1_+_CORNER_TL",  TILE(0x2a, COL1_PAL, 0, 0), TILE(0x2f, COL1_PAL, 0, 0), TILE(0x34, COL1_PAL, 0, 0), TILE(0x31, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_+_CORNER_TR",  TILE(0x2f, COL1_PAL, H, 0), TILE(0x2a, COL1_PAL, H, 0), TILE(0x31, COL1_PAL, H, 0), TILE(0x34, COL1_PAL, H, 0), COL_FULL)
    Metatile("COL1_+_CORNER_BL",  TILE(0x34, COL1_PAL, 0, V), TILE(0x31, COL1_PAL, 0, V), TILE(0x2a, COL1_PAL, 0, V), TILE(0x2f, COL1_PAL, 0, V), COL_FULL)
    Metatile("COL1_+_CORNER_BR",  TILE(0x31, COL1_PAL, H, V), TILE(0x34, COL1_PAL, H, V), TILE(0x2f, COL1_PAL, H, V), TILE(0x2a, COL1_PAL, H, V), COL_FULL) // 0x2b8
    Metatile("COL1_+_FILLER",     TILE(0x35, COL1_PAL, 0, 0), TILE(0x33, COL1_PAL, 0, 0), TILE(0x30, COL1_PAL, 0, 0), TILE(0x31, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_+_DB_CRN_TOP", TILE(0x2a, COL1_PAL, 0, 0), TILE(0x2b, COL1_PAL, 0, 0), TILE(0x34, COL1_PAL, 0, 0), TILE(0x36, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_+_DB_CRN_BOT", TILE(0x34, COL1_PAL, 0, V), TILE(0x36, COL1_PAL, 0, V), TILE(0x2a, COL1_PAL, 0, V), TILE(0x2b, COL1_PAL, 0, V), COL_FULL)
    Metatile("COL1_+_DB_CRN_LFT", TILE(0x2a, COL1_PAL, 0, 0), TILE(0x2f, COL1_PAL, 0, 0), TILE(0x2c, COL1_PAL, 0, 0), TILE(0x37, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_+_DB_CRN_RGT", TILE(0x2f, COL1_PAL, H, 0), TILE(0x2a, COL1_PAL, H, 0), TILE(0x39, COL1_PAL, 0, 0), TILE(0x2d, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_+_DB_SIDE_V",  TILE(0x32, COL1_PAL, 0, 0), TILE(0x38, COL1_PAL, 0, 0), TILE(0x34, COL1_PAL, 0, 0), TILE(0x36, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_+_DB_SIDE_H",  TILE(0x2e, COL1_PAL, 0, 0), TILE(0x2f, COL1_PAL, 0, 0), TILE(0x39, COL1_PAL, 0, 0), TILE(0x37, COL1_PAL, 0, 0), COL_FULL)
    
    Metatile("COL1_BLK_FULL",        TILE(0x3b, COL1_PAL, 0, 0), TILE(0x3b, COL1_PAL, H, 0), TILE(0x3b, COL1_PAL, 0, V), TILE(0x3b, COL1_PAL, H, V), COL_FULL) // 0x2c0
    Metatile("COL1_BLK_SIDE_TOP",    TILE(0x3c, COL1_PAL, 0, 0), TILE(0x3c, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_BLK_SIDE_BOTTOM", TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3c, COL1_PAL, 0, V), TILE(0x3c, COL1_PAL, 0, V), COL_FULL)
    Metatile("COL1_BLK_SIDE_LEFT",   TILE(0x3d, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3d, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_BLK_SIDE_RIGHT",  TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3d, COL1_PAL, H, 0), TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3d, COL1_PAL, H, 0), COL_FULL)
    Metatile("COL1_BLK_CORNER_TL",   TILE(0x3b, COL1_PAL, 0, 0), TILE(0x3c, COL1_PAL, 0, 0), TILE(0x3d, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_BLK_CORNER_TR",   TILE(0x3c, COL1_PAL, H, 0), TILE(0x3b, COL1_PAL, H, 0), TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3d, COL1_PAL, H, 0), COL_FULL)
    Metatile("COL1_BLK_CORNER_BL",   TILE(0x3d, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3b, COL1_PAL, 0, V), TILE(0x3c, COL1_PAL, 0, V), COL_FULL)
    Metatile("COL1_BLK_CORNER_BR",   TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3d, COL1_PAL, H, 0), TILE(0x3c, COL1_PAL, 0, V), TILE(0x3b, COL1_PAL, H, V), COL_FULL) // 0x2c8
    Metatile("COL1_BLK_INS_CRN_TL",  TILE(0x3e, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_BLK_INS_CRN_TR",  TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3e, COL1_PAL, H, 0), TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_BLK_INS_CRN_BL",  TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3e, COL1_PAL, 0, V), TILE(0x3a, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_BLK_INS_CRN_BR",  TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3e, COL1_PAL, V, H), COL_FULL)
    Metatile("COL1_BLK_FILLER",      TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_BLK_DB_CRN_TOP",  TILE(0x3b, COL1_PAL, 0, 0), TILE(0x3b, COL1_PAL, H, 0), TILE(0x3d, COL1_PAL, 0, 0), TILE(0x3d, COL1_PAL, H, 0), COL_FULL)
    Metatile("COL1_BLK_DB_CRN_BOT",  TILE(0x3d, COL1_PAL, 0, 0), TILE(0x3d, COL1_PAL, H, 0), TILE(0x3b, COL1_PAL, 0, V), TILE(0x3b, COL1_PAL, H, V), COL_FULL)

    Metatile("COL1_BLK_DB_CRN_LFT",  TILE(0x3b, COL1_PAL, 0, 0), TILE(0x3c, COL1_PAL, 0, 0), TILE(0x3b, COL1_PAL, 0, V), TILE(0x3c, COL1_PAL, 0, V), COL_FULL) // 0x2d0
    Metatile("COL1_BLK_DB_CRN_RGT",  TILE(0x3c, COL1_PAL, 0, 0), TILE(0x3b, COL1_PAL, H, 0), TILE(0x3c, COL1_PAL, 0, V), TILE(0x3b, COL1_PAL, H, V), COL_FULL)
    Metatile("COL1_BLK_DB_SIDE_H",   TILE(0x3d, COL1_PAL, 0, 0), TILE(0x3d, COL1_PAL, H, 0), TILE(0x3d, COL1_PAL, 0, 0), TILE(0x3d, COL1_PAL, H, 0), COL_FULL)
    Metatile("COL1_BLK_DB_SIDE_V",   TILE(0x3c, COL1_PAL, 0, 0), TILE(0x3c, COL1_PAL, 0, 0), TILE(0x3c, COL1_PAL, 0, V), TILE(0x3c, COL1_PAL, 0, V), COL_FULL)

    Metatile("COL1_BLK_SLAB_TOP",    TILE(0x26, COL1_PAL, 0, 0), TILE(0x26, COL1_PAL, H, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), COL_SLAB_TOP)
    Metatile("COL1_BLK_SLAB_BOT",    TILE(0x00, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x26, COL1_PAL, 0, 0), TILE(0x26, COL1_PAL, H, 0), COL_SLAB_BOTTOM)
    Metatile("COL1_BLK_SLAB_LFT",    TILE(0x27, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x27, COL1_PAL, 0, V), TILE(0x00, COL1_PAL, 0, 0), COL_SLAB_LEFT)
    Metatile("COL1_BLK_SLAB_RGT",    TILE(0x00, COL1_PAL, 0, 0), TILE(0x27, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x27, COL1_PAL, 0, V), COL_SLAB_RIGHT)
    
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x2d8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    
    Metatile("COL1_BRICKS_FULL",        TILE(0x3f, COL1_PAL, 0, 0), TILE(0x3f, COL1_PAL, H, 0), TILE(0x40, COL1_PAL, 0, 0), TILE(0x41, COL1_PAL, 0, 0), COL_FULL) // 0x2e0
    Metatile("COL1_BRICKS_SIDE_TOP",    TILE(0x42, COL1_PAL, 0, 0), TILE(0x42, COL1_PAL, H, 0), TILE(0x43, COL1_PAL, 0, 0), TILE(0x44, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_BRICKS_SIDE_BOTTOM", TILE(0x43, COL1_PAL, 0, V), TILE(0x44, COL1_PAL, 0, V), TILE(0x42, COL1_PAL, 0, V), TILE(0x42, COL1_PAL, H, V), COL_FULL)
    Metatile("COL1_BRICKS_SIDE_LEFT",   TILE(0x45, COL1_PAL, 0, 0), TILE(0x46, COL1_PAL, 0, 0), TILE(0x47, COL1_PAL, 0, 0), TILE(0x44, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_BRICKS_SIDE_RIGHT",  TILE(0x46, COL1_PAL, H, 0), TILE(0x45, COL1_PAL, H, 0), TILE(0x44, COL1_PAL, H, 0), TILE(0x47, COL1_PAL, H, 0), COL_FULL)
    Metatile("COL1_BRICKS_CORNER_TL",   TILE(0x3f, COL1_PAL, 0, 0), TILE(0x42, COL1_PAL, H, 0), TILE(0x47, COL1_PAL, 0, 0), TILE(0x44, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_BRICKS_CORNER_TR",   TILE(0x42, COL1_PAL, 0, 0), TILE(0x3f, COL1_PAL, H, 0), TILE(0x44, COL1_PAL, H, 0), TILE(0x47, COL1_PAL, H, 0), COL_FULL)
    Metatile("COL1_BRICKS_CORNER_BL",   TILE(0x47, COL1_PAL, 0, V), TILE(0x44, COL1_PAL, 0, V), TILE(0x3f, COL1_PAL, 0, V), TILE(0x42, COL1_PAL, H, V), COL_FULL)
    Metatile("COL1_BRICKS_CORNER_BR",   TILE(0x44, COL1_PAL, H, V), TILE(0x47, COL1_PAL, H, V), TILE(0x42, COL1_PAL, 0, V), TILE(0x3f, COL1_PAL, H, V), COL_FULL) // 0x2e8
    Metatile("COL1_BRICKS_INS_CRN_TL",  TILE(0x48, COL1_PAL, 0, 0), TILE(0x46, COL1_PAL, 0, 0), TILE(0x43, COL1_PAL, 0, 0), TILE(0x44, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_BRICKS_INS_CRN_TR",  TILE(0x46, COL1_PAL, H, 0), TILE(0x48, COL1_PAL, H, 0), TILE(0x43, COL1_PAL, 0, 0), TILE(0x44, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_BRICKS_INS_CRN_BL",  TILE(0x43, COL1_PAL, 0, V), TILE(0x44, COL1_PAL, 0, V), TILE(0x48, COL1_PAL, 0, V), TILE(0x46, COL1_PAL, 0, V), COL_FULL)
    Metatile("COL1_BRICKS_INS_CRN_BR",  TILE(0x43, COL1_PAL, 0, V), TILE(0x44, COL1_PAL, 0, V), TILE(0x46, COL1_PAL, H, V), TILE(0x48, COL1_PAL, H, V), COL_FULL)
    Metatile("COL1_BRICKS_FILLER",      TILE(0x46, COL1_PAL, H, 0), TILE(0x46, COL1_PAL, 0, 0), TILE(0x43, COL1_PAL, 0, 0), TILE(0x44, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_BRICKS_DB_CRN_TOP",  TILE(0x3f, COL1_PAL, 0, 0), TILE(0x3f, COL1_PAL, H, 0), TILE(0x47, COL1_PAL, 0, 0), TILE(0x4b, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_BRICKS_DB_CRN_BOT",  TILE(0x47, COL1_PAL, 0, V), TILE(0x4b, COL1_PAL, 0, V), TILE(0x3f, COL1_PAL, 0, V), TILE(0x3f, COL1_PAL, H, V), COL_FULL)

    Metatile("COL1_BRICKS_DB_CRN_LFT",  TILE(0x3f, COL1_PAL, 0, 0), TILE(0x42, COL1_PAL, H, 0), TILE(0x40, COL1_PAL, 0, 0), TILE(0x4c, COL1_PAL, 0, 0), COL_FULL) // 0x2f0
    Metatile("COL1_BRICKS_DB_CRN_RGT",  TILE(0x42, COL1_PAL, 0, 0), TILE(0x3f, COL1_PAL, H, 0), TILE(0x4c, COL1_PAL, H, 0), TILE(0x40, COL1_PAL, H, 0), COL_FULL)
    Metatile("COL1_BRICKS_SIDE_H",      TILE(0x45, COL1_PAL, 0, 0), TILE(0x45, COL1_PAL, H, 0), TILE(0x45, COL1_PAL, 0, 0), TILE(0x4b, COL1_PAL, 0, 0), COL_FULL)
    Metatile("COL1_BRICKS_SIDE_V",      TILE(0x42, COL1_PAL, 0, 0), TILE(0x42, COL1_PAL, H, 0), TILE(0x4d, COL1_PAL, 0, 0), TILE(0x4c, COL1_PAL, 0, 0), COL_FULL)

    Metatile("COL1_SPIKE_UP",            TILE(0x165, COL1_PAL, 0, 0), TILE(0x165, COL1_PAL, H, 0), TILE(0x175, COL1_PAL, 0, 0), TILE(0x175, COL1_PAL, H, 0), COL_SPIKE_TOP)
    Metatile("COL1_SPIKE_DOWN",          TILE(0x175, COL1_PAL, 0, V), TILE(0x175, COL1_PAL, H, V), TILE(0x165, COL1_PAL, 0, V), TILE(0x165, COL1_PAL, H, V), COL_SPIKE_BOTTOM)
    Metatile("COL1_SPIKE_LEFT",          TILE(0x166, COL1_PAL, 0, 0), TILE(0x167, COL1_PAL, 0, 0), TILE(0x166, COL1_PAL, 0, V), TILE(0x167, COL1_PAL, 0, V), COL_SPIKE_LEFT)
    Metatile("COL1_SPIKE_RIGHT",         TILE(0x167, COL1_PAL, H, 0), TILE(0x166, COL1_PAL, H, 0), TILE(0x167, COL1_PAL, H, V), TILE(0x166, COL1_PAL, H, V), COL_SPIKE_RIGHT)
    Metatile("COL1_SMALL_SPIKE_BOTTOM",  TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x16a, COL1_PAL, 0, 0), TILE(0x16a, COL1_PAL, H, 0), COL_SMALL_SPIKE_BOTTOM) // 0x2f8
    Metatile("COL1_SMALL_SPIKE_TOP",     TILE(0x16a, COL1_PAL, 0, V), TILE(0x16a, COL1_PAL, H, V), TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), COL_SMALL_SPIKE_TOP)
    Metatile("COL1_SMALL_SPIKE_LEFT",    TILE(0x17a, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x17a, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, 0), COL_SMALL_SPIKE_LEFT)
    Metatile("COL1_SMALL_SPIKE_RIGHT",   TILE(0x000, COL1_PAL, 0, 0), TILE(0x17a, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x17a, COL1_PAL, H, V), COL_SMALL_SPIKE_RIGHT)
    Metatile("COL1_MEDIUM_SPIKE_BOTTOM", TILE(0x168, COL1_PAL, 0, 0), TILE(0x168, COL1_PAL, H, 0), TILE(0x178, COL1_PAL, 0, 0), TILE(0x178, COL1_PAL, H, 0), COL_MEDIUM_SPIKE_BOTTOM)
    Metatile("COL1_MEDIUM_SPIKE_TOP",    TILE(0x178, COL1_PAL, 0, V), TILE(0x178, COL1_PAL, H, V), TILE(0x168, COL1_PAL, 0, V), TILE(0x168, COL1_PAL, H, V), COL_MEDIUM_SPIKE_TOP)
    Metatile("COL1_MEDIUM_SPIKE_LEFT",   TILE(0x179, COL1_PAL, 0, 0), TILE(0x169, COL1_PAL, 0, 0), TILE(0x179, COL1_PAL, 0, V), TILE(0x169, COL1_PAL, 0, V), COL_MEDIUM_SPIKE_LEFT)
    Metatile("COL1_MEDIUM_SPIKE_RIGHT",  TILE(0x169, COL1_PAL, H, 0), TILE(0x179, COL1_PAL, H, 0), TILE(0x169, COL1_PAL, H, V), TILE(0x179, COL1_PAL, H, V), COL_MEDIUM_SPIKE_RIGHT)

    Metatile("COL1_SLOPE_45_UP",      TILE(0x00, COL1_PAL, 0, 0), TILE(0x7b, COL1_PAL, 0, 0), TILE(0x7b, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), COL_SLOPE_45_UP) // 0x300
    Metatile("COL1_SLOPE_45_DOWN",    TILE(0x7b, COL1_PAL, H, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, H, 0), TILE(0x7b, COL1_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL1_SLOPE_45_UP_UD",   TILE(0x7b, COL1_PAL, 0, V), TILE(0x3a, COL1_PAL, 0, V), TILE(0x00, COL1_PAL, 0, V), TILE(0x7b, COL1_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL1_SLOPE_45_DOWN_UD", TILE(0x3a, COL1_PAL, H, V), TILE(0x7b, COL1_PAL, H, V), TILE(0x7b, COL1_PAL, H, V), TILE(0x00, COL1_PAL, 0, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL1_22_UP_1",          TILE(0x00, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x7c, COL1_PAL, 0, 0), TILE(0x7d, COL1_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL1_22_UP_2",          TILE(0x7c, COL1_PAL, 0, 0), TILE(0x7d, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("COL1_22_DOWN_1",        TILE(0x7d, COL1_PAL, H, 0), TILE(0x7c, COL1_PAL, H, 0), TILE(0x3a, COL1_PAL, H, 0), TILE(0x3a, COL1_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL1_22_DOWN_2",        TILE(0x00, COL1_PAL, H, 0), TILE(0x00, COL1_PAL, H, 0), TILE(0x7d, COL1_PAL, H, 0), TILE(0x7c, COL1_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL1_22_UP_UD_1",       TILE(0x7c, COL1_PAL, 0, V), TILE(0x7d, COL1_PAL, 0, V), TILE(0x00, COL1_PAL, 0, V), TILE(0x00, COL1_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x308
    Metatile("COL1_22_UP_UD_2",       TILE(0x3a, COL1_PAL, 0, V), TILE(0x3a, COL1_PAL, 0, V), TILE(0x7c, COL1_PAL, 0, V), TILE(0x7d, COL1_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL1_22_DOWN_UD_1",     TILE(0x3a, COL1_PAL, H, V), TILE(0x3a, COL1_PAL, H, V), TILE(0x7d, COL1_PAL, H, V), TILE(0x7c, COL1_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL1_22_DOWN_UD_2",     TILE(0x7d, COL1_PAL, H, V), TILE(0x7c, COL1_PAL, H, V), TILE(0x00, COL1_PAL, H, V), TILE(0x00, COL1_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL1_66_UP_1",          TILE(0x00, COL1_PAL, 0, 0), TILE(0x7f, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x7e, COL1_PAL, 0, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL1_66_UP_2",          TILE(0x7f, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), TILE(0x7e, COL1_PAL, 0, 0), TILE(0x3a, COL1_PAL, 0, 0), COL_SLOPE_66_UP_2)
    Metatile("COL1_66_DOWN_1",        TILE(0x3a, COL1_PAL, H, 0), TILE(0x7f, COL1_PAL, H, 0), TILE(0x3a, COL1_PAL, H, 0), TILE(0x7e, COL1_PAL, H, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL1_66_DOWN_2",        TILE(0x7f, COL1_PAL, H, 0), TILE(0x00, COL1_PAL, H, 0), TILE(0x7e, COL1_PAL, H, 0), TILE(0x00, COL1_PAL, H, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL1_66_UP_UD_1",       TILE(0x00, COL1_PAL, 0, V), TILE(0x7e, COL1_PAL, 0, V), TILE(0x00, COL1_PAL, 0, V), TILE(0x7f, COL1_PAL, 0, V), COL_SLOPE_66_UP_UD_1) // 0x310
    Metatile("COL1_66_UP_UD_2",       TILE(0x7e, COL1_PAL, 0, V), TILE(0x3a, COL1_PAL, 0, V), TILE(0x7f, COL1_PAL, 0, V), TILE(0x3a, COL1_PAL, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL1_66_DOWN_UD_1",     TILE(0x3a, COL1_PAL, H, V), TILE(0x7e, COL1_PAL, H, V), TILE(0x3a, COL1_PAL, H, V), TILE(0x7f, COL1_PAL, H, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL1_66_DOWN_UD_2",     TILE(0x7e, COL1_PAL, H, V), TILE(0x00, COL1_PAL, H, V), TILE(0x7f, COL1_PAL, H, V), TILE(0x00, COL1_PAL, H, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x318
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    // COL2 METATILES

    Metatile("COL2_CHK_FULL",       TILE(0x01, COL2_PAL, 0, 0), TILE(0x01, COL2_PAL, H, 0), TILE(0x01, COL2_PAL, 0, V), TILE(0x01, COL2_PAL, H, V), COL_FULL) // 0x320
    Metatile("COL2_CHK_SIDE_UP",    TILE(0x02, COL2_PAL, 0, 0), TILE(0x02, COL2_PAL, H, 0), TILE(0x03, COL2_PAL, 0, 0), TILE(0x03, COL2_PAL, H, 0), COL_FULL)
    Metatile("COL2_CHK_SIDE_DOWN",  TILE(0x03, COL2_PAL, 0, V), TILE(0x03, COL2_PAL, H, V), TILE(0x02, COL2_PAL, 0, V), TILE(0x02, COL2_PAL, H, V), COL_FULL)
    Metatile("COL2_CHK_SIDE_LEFT",  TILE(0x04, COL2_PAL, 0, 0), TILE(0x05, COL2_PAL, 0, 0), TILE(0x04, COL2_PAL, 0, V), TILE(0x05, COL2_PAL, 0, V), COL_FULL)
    Metatile("COL2_CHK_SIDE_RIGHT", TILE(0x05, COL2_PAL, H, 0), TILE(0x04, COL2_PAL, H, 0), TILE(0x05, COL2_PAL, H, V), TILE(0x04, COL2_PAL, H, V), COL_FULL)
    Metatile("COL2_CHK_CORNER_TL",  TILE(0x06, COL2_PAL, 0, 0), TILE(0x02, COL2_PAL, H, 0), TILE(0x04, COL2_PAL, 0, V), TILE(0x07, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_CHK_CORNER_TR",  TILE(0x02, COL2_PAL, 0, 0), TILE(0x06, COL2_PAL, H, 0), TILE(0x07, COL2_PAL, H, 0), TILE(0x04, COL2_PAL, H, V), COL_FULL)
    Metatile("COL2_CHK_CORNER_BL",  TILE(0x04, COL2_PAL, 0, 0), TILE(0x07, COL2_PAL, 0, V), TILE(0x06, COL2_PAL, 0, V), TILE(0x02, COL2_PAL, H, V), COL_FULL)
    Metatile("COL2_CHK_CORNER_BR",  TILE(0x07, COL2_PAL, H, V), TILE(0x04, COL2_PAL, H, 0), TILE(0x02, COL2_PAL, 0, V), TILE(0x06, COL2_PAL, H, V), COL_FULL) // 0x328
    Metatile("COL2_CHK_CRN_INS_TL", TILE(0x08, COL2_PAL, 0, 0), TILE(0x05, COL2_PAL, 0, 0), TILE(0x03, COL2_PAL, 0, 0), TILE(0x09, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_CHK_CRN_INS_TR", TILE(0x05, COL2_PAL, H, 0), TILE(0x08, COL2_PAL, H, 0), TILE(0x09, COL2_PAL, H, 0), TILE(0x03, COL2_PAL, H, 0), COL_FULL)
    Metatile("COL2_CHK_CRN_INS_BL", TILE(0x03, COL2_PAL, 0, V), TILE(0x09, COL2_PAL, 0, V), TILE(0x08, COL2_PAL, 0, V), TILE(0x05, COL2_PAL, 0, V), COL_FULL)
    Metatile("COL2_CHK_CRN_INS_BR", TILE(0x09, COL2_PAL, H, V), TILE(0x03, COL2_PAL, H, V), TILE(0x05, COL2_PAL, H, V), TILE(0x08, COL2_PAL, H, V), COL_FULL)
    Metatile("COL2_CHK_DB_CRN_TOP", TILE(0x06, COL2_PAL, 0, 0), TILE(0x06, COL2_PAL, H, 0), TILE(0x04, COL2_PAL, 0, V), TILE(0x04, COL2_PAL, H, V), COL_FULL)
    Metatile("COL2_CHK_DB_CRN_BOT", TILE(0x04, COL2_PAL, 0, 0), TILE(0x04, COL2_PAL, H, 0), TILE(0x06, COL2_PAL, 0, V), TILE(0x06, COL2_PAL, H, V), COL_FULL)
    Metatile("COL2_CHK_DB_CRN_LFT", TILE(0x06, COL2_PAL, 0, 0), TILE(0x02, COL2_PAL, H, 0), TILE(0x06, COL2_PAL, 0, V), TILE(0x02, COL2_PAL, H, V), COL_FULL)
    Metatile("COL2_CHK_DB_CRN_RGT", TILE(0x02, COL2_PAL, 0, 0), TILE(0x06, COL2_PAL, H, 0), TILE(0x02, COL2_PAL, 0, V), TILE(0x06, COL2_PAL, H, V), COL_FULL) // 0x330
    Metatile("COL2_CHK_DB_SIDE_V",  TILE(0x04, COL2_PAL, 0, 0), TILE(0x04, COL2_PAL, H, 0), TILE(0x04, COL2_PAL, 0, V), TILE(0x04, COL2_PAL, H, V), COL_FULL)
    Metatile("COL2_CHK_DB_SIDE_H",  TILE(0x02, COL2_PAL, 0, 0), TILE(0x02, COL2_PAL, H, 0), TILE(0x02, COL2_PAL, 0, V), TILE(0x02, COL2_PAL, H, V), COL_FULL)
    Metatile("COL2_CHK_FILLER",     TILE(0x0a, COL2_PAL, 0, 0), TILE(0x0a, COL2_PAL, H, 0), TILE(0x0a, COL2_PAL, 0, V), TILE(0x0a, COL2_PAL, H, V), COL_NONE)

    Metatile("COL2_CHK_CORNER_TL", TILE(0x0B, COL2_PAL, 0, 0), TILE(0x05, COL2_PAL, 0, 0), TILE(0x03, COL2_PAL, 0, 0), TILE(0x09, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_CHK_CORNER_TR", TILE(0x05, COL2_PAL, H, 0), TILE(0x0B, COL2_PAL, H, 0), TILE(0x09, COL2_PAL, H, 0), TILE(0x03, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_CHK_CORNER_BL", TILE(0x03, COL2_PAL, 0, V), TILE(0x09, COL2_PAL, 0, V), TILE(0x0B, COL2_PAL, 0, V), TILE(0x05, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_CHK_CORNER_BR", TILE(0x09, COL2_PAL, H, V), TILE(0x03, COL2_PAL, H, V), TILE(0x05, COL2_PAL, H, V), TILE(0x0B, COL2_PAL, H, V), COL_NONE) // 0x338

    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)

    Metatile("COL2_X_FULL",       TILE(0x13, COL2_PAL, 0, 0), TILE(0x14, COL2_PAL, 0, 0), TILE(0x15, COL2_PAL, 0, 0), TILE(0x16, COL2_PAL, 0, 0), COL_FULL) // 0x340
    Metatile("COL2_X_SIDE_UP",    TILE(0x17, COL2_PAL, 0, 0), TILE(0x18, COL2_PAL, 0, 0), TILE(0x19, COL2_PAL, 0, 0), TILE(0x1a, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_X_SIDE_DOWN",  TILE(0x19, COL2_PAL, 0, V), TILE(0x1a, COL2_PAL, 0, V), TILE(0x17, COL2_PAL, 0, V), TILE(0x18, COL2_PAL, 0, V), COL_FULL)
    Metatile("COL2_X_SIDE_LEFT",  TILE(0x1b, COL2_PAL, 0, 0), TILE(0x1c, COL2_PAL, 0, 0), TILE(0x1d, COL2_PAL, 0, 0), TILE(0x1a, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_X_SIDE_RIGHT", TILE(0x1c, COL2_PAL, H, 0), TILE(0x1b, COL2_PAL, H, 0), TILE(0x1a, COL2_PAL, H, 0), TILE(0x1d, COL2_PAL, H, 0), COL_FULL)
    Metatile("COL2_X_CORNER_TL",  TILE(0x13, COL2_PAL, 0, 0), TILE(0x18, COL2_PAL, 0, 0), TILE(0x1d, COL2_PAL, 0, 0), TILE(0x1a, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_X_CORNER_TR",  TILE(0x18, COL2_PAL, H, 0), TILE(0x13, COL2_PAL, H, 0), TILE(0x1a, COL2_PAL, H, 0), TILE(0x1d, COL2_PAL, H, 0), COL_FULL)
    Metatile("COL2_X_CORNER_BL",  TILE(0x1d, COL2_PAL, 0, V), TILE(0x1a, COL2_PAL, 0, V), TILE(0x13, COL2_PAL, 0, V), TILE(0x18, COL2_PAL, 0, V), COL_FULL)
    Metatile("COL2_X_CORNER_BR",  TILE(0x1a, COL2_PAL, H, V), TILE(0x1d, COL2_PAL, H, V), TILE(0x18, COL2_PAL, H, V), TILE(0x13, COL2_PAL, H, V), COL_FULL) // 0x348
    Metatile("COL2_X_INS_CRN_TL", TILE(0x1e, COL2_PAL, 0, 0), TILE(0x1c, COL2_PAL, 0, 0), TILE(0x19, COL2_PAL, 0, 0), TILE(0x1a, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_X_INS_CRN_TR", TILE(0x22, COL2_PAL, 0, 0), TILE(0x1f, COL2_PAL, 0, 0), TILE(0x19, COL2_PAL, 0, 0), TILE(0x1a, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_X_INS_CRN_BL", TILE(0x22, COL2_PAL, 0, 0), TILE(0x1c, COL2_PAL, 0, 0), TILE(0x20, COL2_PAL, 0, 0), TILE(0x1a, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_X_INS_CRN_BR", TILE(0x22, COL2_PAL, 0, 0), TILE(0x1c, COL2_PAL, 0, 0), TILE(0x19, COL2_PAL, 0, 0), TILE(0x21, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_X_FILLER",     TILE(0x22, COL2_PAL, 0, 0), TILE(0x1c, COL2_PAL, 0, 0), TILE(0x19, COL2_PAL, 0, 0), TILE(0x1a, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_X_DB_CRN_TOP", TILE(0x13, COL2_PAL, 0, 0), TILE(0x14, COL2_PAL, 0, 0), TILE(0x1d, COL2_PAL, 0, 0), TILE(0x23, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_X_DB_CRN_BOT", TILE(0x1b, COL2_PAL, 0, 0), TILE(0x25, COL2_PAL, 0, 0), TILE(0x15, COL2_PAL, 0, 0), TILE(0x16, COL2_PAL, 0, 0), COL_FULL)
        
    Metatile("COL2_X_DB_CRN_LFT", TILE(0x13, COL2_PAL, 0, 0), TILE(0x18, COL2_PAL, 0, 0), TILE(0x15, COL2_PAL, 0, 0), TILE(0x24, COL2_PAL, 0, 0), COL_FULL) // 0x350
    Metatile("COL2_X_DB_CRN_RGT", TILE(0x18, COL2_PAL, H, 0), TILE(0x13, COL2_PAL, H, 0), TILE(0x24, COL2_PAL, H, 0), TILE(0x15, COL2_PAL, H, 0), COL_FULL)
    Metatile("COL2_X_DB_SIDE_V",  TILE(0x1b, COL2_PAL, 0, 0), TILE(0x25, COL2_PAL, 0, 0), TILE(0x1d, COL2_PAL, 0, 0), TILE(0x23, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_X_DB_SIDE_H",  TILE(0x17, COL2_PAL, 0, 0), TILE(0x18, COL2_PAL, 0, 0), TILE(0x12, COL2_PAL, 0, 0), TILE(0x24, COL2_PAL, 0, 0), COL_FULL)
    
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE) // 0x358
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)

    Metatile("COL2_+_FULL",       TILE(0x2a, COL2_PAL, 0, 0), TILE(0x2b, COL2_PAL, 0, 0), TILE(0x2c, COL2_PAL, 0, 0), TILE(0x2d, COL2_PAL, 0, 0), COL_FULL) // 0x360
    Metatile("COL2_+_SIDE_UP",    TILE(0x2e, COL2_PAL, 0, 0), TILE(0x2f, COL2_PAL, 0, 0), TILE(0x30, COL2_PAL, 0, 0), TILE(0x31, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_+_SIDE_DOWN",  TILE(0x30, COL2_PAL, 0, V), TILE(0x31, COL2_PAL, 0, V), TILE(0x2e, COL2_PAL, 0, V), TILE(0x2f, COL2_PAL, 0, V), COL_FULL)
    Metatile("COL2_+_SIDE_LEFT",  TILE(0x32, COL2_PAL, 0, 0), TILE(0x33, COL2_PAL, 0, 0), TILE(0x34, COL2_PAL, 0, 0), TILE(0x31, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_+_SIDE_RIGHT", TILE(0x33, COL2_PAL, H, 0), TILE(0x32, COL2_PAL, H, 0), TILE(0x31, COL2_PAL, H, 0), TILE(0x34, COL2_PAL, H, 0), COL_FULL)
    Metatile("COL2_+_CORNER_TL",  TILE(0x2a, COL2_PAL, 0, 0), TILE(0x2f, COL2_PAL, 0, 0), TILE(0x34, COL2_PAL, 0, 0), TILE(0x31, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_+_CORNER_TR",  TILE(0x2f, COL2_PAL, H, 0), TILE(0x2a, COL2_PAL, H, 0), TILE(0x31, COL2_PAL, H, 0), TILE(0x34, COL2_PAL, H, 0), COL_FULL)
    Metatile("COL2_+_CORNER_BL",  TILE(0x34, COL2_PAL, 0, V), TILE(0x31, COL2_PAL, 0, V), TILE(0x2a, COL2_PAL, 0, V), TILE(0x2f, COL2_PAL, 0, V), COL_FULL)
    Metatile("COL2_+_CORNER_BR",  TILE(0x31, COL2_PAL, H, V), TILE(0x34, COL2_PAL, H, V), TILE(0x2f, COL2_PAL, H, V), TILE(0x2a, COL2_PAL, H, V), COL_FULL) // 0x368
    Metatile("COL2_+_FILLER",     TILE(0x35, COL2_PAL, 0, 0), TILE(0x33, COL2_PAL, 0, 0), TILE(0x30, COL2_PAL, 0, 0), TILE(0x31, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_+_DB_CRN_TOP", TILE(0x2a, COL2_PAL, 0, 0), TILE(0x2b, COL2_PAL, 0, 0), TILE(0x34, COL2_PAL, 0, 0), TILE(0x36, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_+_DB_CRN_BOT", TILE(0x34, COL2_PAL, 0, V), TILE(0x36, COL2_PAL, 0, V), TILE(0x2a, COL2_PAL, 0, V), TILE(0x2b, COL2_PAL, 0, V), COL_FULL)
    Metatile("COL2_+_DB_CRN_LFT", TILE(0x2a, COL2_PAL, 0, 0), TILE(0x2f, COL2_PAL, 0, 0), TILE(0x2c, COL2_PAL, 0, 0), TILE(0x37, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_+_DB_CRN_RGT", TILE(0x2f, COL2_PAL, H, 0), TILE(0x2a, COL2_PAL, H, 0), TILE(0x39, COL2_PAL, 0, 0), TILE(0x2d, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_+_DB_SIDE_V",  TILE(0x32, COL2_PAL, 0, 0), TILE(0x38, COL2_PAL, 0, 0), TILE(0x34, COL2_PAL, 0, 0), TILE(0x36, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_+_DB_SIDE_H",  TILE(0x2e, COL2_PAL, 0, 0), TILE(0x2f, COL2_PAL, 0, 0), TILE(0x39, COL2_PAL, 0, 0), TILE(0x37, COL2_PAL, 0, 0), COL_FULL)
    
    Metatile("COL2_BLK_FULL",        TILE(0x3b, COL2_PAL, 0, 0), TILE(0x3b, COL2_PAL, H, 0), TILE(0x3b, COL2_PAL, 0, V), TILE(0x3b, COL2_PAL, H, V), COL_FULL) // 0x370
    Metatile("COL2_BLK_SIDE_TOP",    TILE(0x3c, COL2_PAL, 0, 0), TILE(0x3c, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_BLK_SIDE_BOTTOM", TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3c, COL2_PAL, 0, V), TILE(0x3c, COL2_PAL, 0, V), COL_FULL)
    Metatile("COL2_BLK_SIDE_LEFT",   TILE(0x3d, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3d, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_BLK_SIDE_RIGHT",  TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3d, COL2_PAL, H, 0), TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3d, COL2_PAL, H, 0), COL_FULL)
    Metatile("COL2_BLK_CORNER_TL",   TILE(0x3b, COL2_PAL, 0, 0), TILE(0x3c, COL2_PAL, 0, 0), TILE(0x3d, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_BLK_CORNER_TR",   TILE(0x3c, COL2_PAL, H, 0), TILE(0x3b, COL2_PAL, H, 0), TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3d, COL2_PAL, H, 0), COL_FULL)
    Metatile("COL2_BLK_CORNER_BL",   TILE(0x3d, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3b, COL2_PAL, 0, V), TILE(0x3c, COL2_PAL, 0, V), COL_FULL)
    Metatile("COL2_BLK_CORNER_BR",   TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3d, COL2_PAL, H, 0), TILE(0x3c, COL2_PAL, 0, V), TILE(0x3b, COL2_PAL, H, V), COL_FULL) // 0x378
    Metatile("COL2_BLK_INS_CRN_TL",  TILE(0x3e, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_BLK_INS_CRN_TR",  TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3e, COL2_PAL, H, 0), TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_BLK_INS_CRN_BL",  TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3e, COL2_PAL, 0, V), TILE(0x3a, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_BLK_INS_CRN_BR",  TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3e, COL2_PAL, V, H), COL_FULL)
    Metatile("COL2_BLK_FILLER",      TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_BLK_DB_CRN_TOP",  TILE(0x3b, COL2_PAL, 0, 0), TILE(0x3b, COL2_PAL, H, 0), TILE(0x3d, COL2_PAL, 0, 0), TILE(0x3d, COL2_PAL, H, 0), COL_FULL)
    Metatile("COL2_BLK_DB_CRN_BOT",  TILE(0x3d, COL2_PAL, 0, 0), TILE(0x3d, COL2_PAL, H, 0), TILE(0x3b, COL2_PAL, 0, V), TILE(0x3b, COL2_PAL, H, V), COL_FULL)

    Metatile("COL2_BLK_DB_CRN_LFT",  TILE(0x3b, COL2_PAL, 0, 0), TILE(0x3c, COL2_PAL, 0, 0), TILE(0x3b, COL2_PAL, 0, V), TILE(0x3c, COL2_PAL, 0, V), COL_FULL) // 0x380
    Metatile("COL2_BLK_DB_CRN_RGT",  TILE(0x3c, COL2_PAL, 0, 0), TILE(0x3b, COL2_PAL, H, 0), TILE(0x3c, COL2_PAL, 0, V), TILE(0x3b, COL2_PAL, H, V), COL_FULL)
    Metatile("COL2_BLK_DB_SIDE_H",   TILE(0x3d, COL2_PAL, 0, 0), TILE(0x3d, COL2_PAL, H, 0), TILE(0x3d, COL2_PAL, 0, 0), TILE(0x3d, COL2_PAL, H, 0), COL_FULL)
    Metatile("COL2_BLK_DB_SIDE_V",   TILE(0x3c, COL2_PAL, 0, 0), TILE(0x3c, COL2_PAL, 0, 0), TILE(0x3c, COL2_PAL, 0, V), TILE(0x3c, COL2_PAL, 0, V), COL_FULL)

    Metatile("COL2_BLK_SLAB_TOP",    TILE(0x26, COL2_PAL, 0, 0), TILE(0x26, COL2_PAL, H, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), COL_SLAB_TOP)
    Metatile("COL2_BLK_SLAB_BOT",    TILE(0x00, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x26, COL2_PAL, 0, 0), TILE(0x26, COL2_PAL, H, 0), COL_SLAB_BOTTOM)
    Metatile("COL2_BLK_SLAB_LFT",    TILE(0x27, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x27, COL2_PAL, 0, V), TILE(0x00, COL2_PAL, 0, 0), COL_SLAB_LEFT)
    Metatile("COL2_BLK_SLAB_RGT",    TILE(0x00, COL2_PAL, 0, 0), TILE(0x27, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x27, COL2_PAL, 0, V), COL_SLAB_RIGHT)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x388
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    
    Metatile("COL2_BRICKS_FULL",        TILE(0x3f, COL2_PAL, 0, 0), TILE(0x3f, COL2_PAL, H, 0), TILE(0x40, COL2_PAL, 0, 0), TILE(0x41, COL2_PAL, 0, 0), COL_FULL) // 0x390
    Metatile("COL2_BRICKS_SIDE_TOP",    TILE(0x42, COL2_PAL, 0, 0), TILE(0x42, COL2_PAL, H, 0), TILE(0x43, COL2_PAL, 0, 0), TILE(0x44, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_BRICKS_SIDE_BOTTOM", TILE(0x43, COL2_PAL, 0, V), TILE(0x44, COL2_PAL, 0, V), TILE(0x42, COL2_PAL, 0, V), TILE(0x42, COL2_PAL, H, V), COL_FULL)
    Metatile("COL2_BRICKS_SIDE_LEFT",   TILE(0x45, COL2_PAL, 0, 0), TILE(0x46, COL2_PAL, 0, 0), TILE(0x47, COL2_PAL, 0, 0), TILE(0x44, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_BRICKS_SIDE_RIGHT",  TILE(0x46, COL2_PAL, H, 0), TILE(0x45, COL2_PAL, H, 0), TILE(0x44, COL2_PAL, H, 0), TILE(0x47, COL2_PAL, H, 0), COL_FULL)
    Metatile("COL2_BRICKS_CORNER_TL",   TILE(0x3f, COL2_PAL, 0, 0), TILE(0x42, COL2_PAL, H, 0), TILE(0x47, COL2_PAL, 0, 0), TILE(0x44, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_BRICKS_CORNER_TR",   TILE(0x42, COL2_PAL, 0, 0), TILE(0x3f, COL2_PAL, H, 0), TILE(0x44, COL2_PAL, H, 0), TILE(0x47, COL2_PAL, H, 0), COL_FULL)
    Metatile("COL2_BRICKS_CORNER_BL",   TILE(0x47, COL2_PAL, 0, V), TILE(0x44, COL2_PAL, 0, V), TILE(0x3f, COL2_PAL, 0, V), TILE(0x42, COL2_PAL, H, V), COL_FULL)
    Metatile("COL2_BRICKS_CORNER_BR",   TILE(0x44, COL2_PAL, H, V), TILE(0x47, COL2_PAL, H, V), TILE(0x42, COL2_PAL, 0, V), TILE(0x3f, COL2_PAL, H, V), COL_FULL) // 0x398
    Metatile("COL2_BRICKS_INS_CRN_TL",  TILE(0x48, COL2_PAL, 0, 0), TILE(0x46, COL2_PAL, 0, 0), TILE(0x43, COL2_PAL, 0, 0), TILE(0x44, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_BRICKS_INS_CRN_TR",  TILE(0x46, COL2_PAL, H, 0), TILE(0x48, COL2_PAL, H, 0), TILE(0x43, COL2_PAL, 0, 0), TILE(0x44, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_BRICKS_INS_CRN_BL",  TILE(0x43, COL2_PAL, 0, V), TILE(0x44, COL2_PAL, 0, V), TILE(0x48, COL2_PAL, 0, V), TILE(0x46, COL2_PAL, 0, V), COL_FULL)
    Metatile("COL2_BRICKS_INS_CRN_BR",  TILE(0x43, COL2_PAL, 0, V), TILE(0x44, COL2_PAL, 0, V), TILE(0x46, COL2_PAL, H, V), TILE(0x48, COL2_PAL, H, V), COL_FULL)
    Metatile("COL2_BRICKS_FILLER",      TILE(0x46, COL2_PAL, H, 0), TILE(0x46, COL2_PAL, 0, 0), TILE(0x43, COL2_PAL, 0, 0), TILE(0x44, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_BRICKS_DB_CRN_TOP",  TILE(0x3f, COL2_PAL, 0, 0), TILE(0x3f, COL2_PAL, H, 0), TILE(0x47, COL2_PAL, 0, 0), TILE(0x4b, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_BRICKS_DB_CRN_BOT",  TILE(0x47, COL2_PAL, 0, V), TILE(0x4b, COL2_PAL, 0, V), TILE(0x3f, COL2_PAL, 0, V), TILE(0x3f, COL2_PAL, H, V), COL_FULL)

    Metatile("COL2_BRICKS_DB_CRN_LFT",  TILE(0x3f, COL2_PAL, 0, 0), TILE(0x42, COL2_PAL, H, 0), TILE(0x40, COL2_PAL, 0, 0), TILE(0x4c, COL2_PAL, 0, 0), COL_FULL) // 0x3a0
    Metatile("COL2_BRICKS_DB_CRN_RGT",  TILE(0x42, COL2_PAL, 0, 0), TILE(0x3f, COL2_PAL, H, 0), TILE(0x4c, COL2_PAL, H, 0), TILE(0x40, COL2_PAL, H, 0), COL_FULL)
    Metatile("COL2_BRICKS_SIDE_H",      TILE(0x45, COL2_PAL, 0, 0), TILE(0x45, COL2_PAL, H, 0), TILE(0x45, COL2_PAL, 0, 0), TILE(0x4b, COL2_PAL, 0, 0), COL_FULL)
    Metatile("COL2_BRICKS_SIDE_V",      TILE(0x42, COL2_PAL, 0, 0), TILE(0x42, COL2_PAL, H, 0), TILE(0x4d, COL2_PAL, 0, 0), TILE(0x4c, COL2_PAL, 0, 0), COL_FULL)

    Metatile("COL2_SPIKE_UP",            TILE(0x165, COL2_PAL, 0, 0), TILE(0x165, COL2_PAL, H, 0), TILE(0x175, COL2_PAL, 0, 0), TILE(0x175, COL2_PAL, H, 0), COL_SPIKE_TOP)
    Metatile("COL2_SPIKE_DOWN",          TILE(0x175, COL2_PAL, 0, V), TILE(0x175, COL2_PAL, H, V), TILE(0x165, COL2_PAL, 0, V), TILE(0x165, COL2_PAL, H, V), COL_SPIKE_BOTTOM)
    Metatile("COL2_SPIKE_LEFT",          TILE(0x166, COL2_PAL, 0, 0), TILE(0x167, COL2_PAL, 0, 0), TILE(0x166, COL2_PAL, 0, V), TILE(0x167, COL2_PAL, 0, V), COL_SPIKE_LEFT)
    Metatile("COL2_SPIKE_RIGHT",         TILE(0x167, COL2_PAL, H, 0), TILE(0x166, COL2_PAL, H, 0), TILE(0x167, COL2_PAL, H, V), TILE(0x166, COL2_PAL, H, V), COL_SPIKE_RIGHT)
    Metatile("COL2_SMALL_SPIKE_BOTTOM",  TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x16a, COL2_PAL, 0, 0), TILE(0x16a, COL2_PAL, H, 0), COL_SMALL_SPIKE_BOTTOM) // 0x3a8
    Metatile("COL2_SMALL_SPIKE_TOP",     TILE(0x16a, COL2_PAL, 0, V), TILE(0x16a, COL2_PAL, H, V), TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), COL_SMALL_SPIKE_TOP)
    Metatile("COL2_SMALL_SPIKE_LEFT",    TILE(0x17a, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x17a, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, 0), COL_SMALL_SPIKE_LEFT)
    Metatile("COL2_SMALL_SPIKE_RIGHT",   TILE(0x000, COL2_PAL, 0, 0), TILE(0x17a, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x17a, COL2_PAL, H, V), COL_SMALL_SPIKE_RIGHT)
    Metatile("COL2_MEDIUM_SPIKE_BOTTOM", TILE(0x168, COL2_PAL, 0, 0), TILE(0x168, COL2_PAL, H, 0), TILE(0x178, COL2_PAL, 0, 0), TILE(0x178, COL2_PAL, H, 0), COL_MEDIUM_SPIKE_BOTTOM)
    Metatile("COL2_MEDIUM_SPIKE_TOP",    TILE(0x178, COL2_PAL, 0, V), TILE(0x178, COL2_PAL, H, V), TILE(0x168, COL2_PAL, 0, V), TILE(0x168, COL2_PAL, H, V), COL_MEDIUM_SPIKE_TOP)
    Metatile("COL2_MEDIUM_SPIKE_LEFT",   TILE(0x179, COL2_PAL, 0, 0), TILE(0x169, COL2_PAL, 0, 0), TILE(0x179, COL2_PAL, 0, V), TILE(0x169, COL2_PAL, 0, V), COL_MEDIUM_SPIKE_LEFT)
    Metatile("COL2_MEDIUM_SPIKE_RIGHT",  TILE(0x169, COL2_PAL, H, 0), TILE(0x179, COL2_PAL, H, 0), TILE(0x169, COL2_PAL, H, V), TILE(0x179, COL2_PAL, H, V), COL_MEDIUM_SPIKE_RIGHT)

    Metatile("COL2_SLOPE_45_UP",      TILE(0x00, COL2_PAL, 0, 0), TILE(0x7b, COL2_PAL, 0, 0), TILE(0x7b, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), COL_SLOPE_45_UP) // 0x3b0
    Metatile("COL2_SLOPE_45_DOWN",    TILE(0x7b, COL2_PAL, H, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, H, 0), TILE(0x7b, COL2_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL2_SLOPE_45_UP_UD",   TILE(0x7b, COL2_PAL, 0, V), TILE(0x3a, COL2_PAL, 0, V), TILE(0x00, COL2_PAL, 0, V), TILE(0x7b, COL2_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL2_SLOPE_45_DOWN_UD", TILE(0x3a, COL2_PAL, H, V), TILE(0x7b, COL2_PAL, H, V), TILE(0x7b, COL2_PAL, H, V), TILE(0x00, COL2_PAL, 0, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL2_22_UP_1",          TILE(0x00, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x7c, COL2_PAL, 0, 0), TILE(0x7d, COL2_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL2_22_UP_2",          TILE(0x7c, COL2_PAL, 0, 0), TILE(0x7d, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("COL2_22_DOWN_1",        TILE(0x7d, COL2_PAL, H, 0), TILE(0x7c, COL2_PAL, H, 0), TILE(0x3a, COL2_PAL, H, 0), TILE(0x3a, COL2_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL2_22_DOWN_2",        TILE(0x00, COL2_PAL, H, 0), TILE(0x00, COL2_PAL, H, 0), TILE(0x7d, COL2_PAL, H, 0), TILE(0x7c, COL2_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL2_22_UP_UD_1",       TILE(0x7c, COL2_PAL, 0, V), TILE(0x7d, COL2_PAL, 0, V), TILE(0x00, COL2_PAL, 0, V), TILE(0x00, COL2_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x3b8
    Metatile("COL2_22_UP_UD_2",       TILE(0x3a, COL2_PAL, 0, V), TILE(0x3a, COL2_PAL, 0, V), TILE(0x7c, COL2_PAL, 0, V), TILE(0x7d, COL2_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL2_22_DOWN_UD_1",     TILE(0x3a, COL2_PAL, H, V), TILE(0x3a, COL2_PAL, H, V), TILE(0x7d, COL2_PAL, H, V), TILE(0x7c, COL2_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL2_22_DOWN_UD_2",     TILE(0x7d, COL2_PAL, H, V), TILE(0x7c, COL2_PAL, H, V), TILE(0x00, COL2_PAL, H, V), TILE(0x00, COL2_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL2_66_UP_1",          TILE(0x00, COL2_PAL, 0, 0), TILE(0x7f, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x7e, COL2_PAL, 0, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL2_66_UP_2",          TILE(0x7f, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), TILE(0x7e, COL2_PAL, 0, 0), TILE(0x3a, COL2_PAL, 0, 0), COL_SLOPE_66_UP_2)
    Metatile("COL2_66_DOWN_1",        TILE(0x3a, COL2_PAL, H, 0), TILE(0x7f, COL2_PAL, H, 0), TILE(0x3a, COL2_PAL, H, 0), TILE(0x7e, COL2_PAL, H, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL2_66_DOWN_2",        TILE(0x7f, COL2_PAL, H, 0), TILE(0x00, COL2_PAL, H, 0), TILE(0x7e, COL2_PAL, H, 0), TILE(0x00, COL2_PAL, H, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL2_66_UP_UD_1",       TILE(0x00, COL2_PAL, 0, V), TILE(0x7e, COL2_PAL, 0, V), TILE(0x00, COL2_PAL, 0, V), TILE(0x7f, COL2_PAL, 0, V), COL_SLOPE_66_UP_UD_1) // 0x3c0
    Metatile("COL2_66_UP_UD_2",       TILE(0x7e, COL2_PAL, 0, V), TILE(0x3a, COL2_PAL, 0, V), TILE(0x7f, COL2_PAL, 0, V), TILE(0x3a, COL2_PAL, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL2_66_DOWN_UD_1",     TILE(0x3a, COL2_PAL, H, V), TILE(0x7e, COL2_PAL, H, V), TILE(0x3a, COL2_PAL, H, V), TILE(0x7f, COL2_PAL, H, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL2_66_DOWN_UD_2",     TILE(0x7e, COL2_PAL, H, V), TILE(0x00, COL2_PAL, H, V), TILE(0x7f, COL2_PAL, H, V), TILE(0x00, COL2_PAL, H, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x3c8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    // COL3 METATILES

    Metatile("COL3_CHK_FULL",       TILE(0x01, COL3_PAL, 0, 0), TILE(0x01, COL3_PAL, H, 0), TILE(0x01, COL3_PAL, 0, V), TILE(0x01, COL3_PAL, H, V), COL_FULL) // 0x3d0
    Metatile("COL3_CHK_SIDE_UP",    TILE(0x02, COL3_PAL, 0, 0), TILE(0x02, COL3_PAL, H, 0), TILE(0x03, COL3_PAL, 0, 0), TILE(0x03, COL3_PAL, H, 0), COL_FULL)
    Metatile("COL3_CHK_SIDE_DOWN",  TILE(0x03, COL3_PAL, 0, V), TILE(0x03, COL3_PAL, H, V), TILE(0x02, COL3_PAL, 0, V), TILE(0x02, COL3_PAL, H, V), COL_FULL)
    Metatile("COL3_CHK_SIDE_LEFT",  TILE(0x04, COL3_PAL, 0, 0), TILE(0x05, COL3_PAL, 0, 0), TILE(0x04, COL3_PAL, 0, V), TILE(0x05, COL3_PAL, 0, V), COL_FULL)
    Metatile("COL3_CHK_SIDE_RIGHT", TILE(0x05, COL3_PAL, H, 0), TILE(0x04, COL3_PAL, H, 0), TILE(0x05, COL3_PAL, H, V), TILE(0x04, COL3_PAL, H, V), COL_FULL)
    Metatile("COL3_CHK_CORNER_TL",  TILE(0x06, COL3_PAL, 0, 0), TILE(0x02, COL3_PAL, H, 0), TILE(0x04, COL3_PAL, 0, V), TILE(0x07, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_CHK_CORNER_TR",  TILE(0x02, COL3_PAL, 0, 0), TILE(0x06, COL3_PAL, H, 0), TILE(0x07, COL3_PAL, H, 0), TILE(0x04, COL3_PAL, H, V), COL_FULL)
    Metatile("COL3_CHK_CORNER_BL",  TILE(0x04, COL3_PAL, 0, 0), TILE(0x07, COL3_PAL, 0, V), TILE(0x06, COL3_PAL, 0, V), TILE(0x02, COL3_PAL, H, V), COL_FULL)
    Metatile("COL3_CHK_CORNER_BR",  TILE(0x07, COL3_PAL, H, V), TILE(0x04, COL3_PAL, H, 0), TILE(0x02, COL3_PAL, 0, V), TILE(0x06, COL3_PAL, H, V), COL_FULL) // 0x3d8
    Metatile("COL3_CHK_CRN_INS_TL", TILE(0x08, COL3_PAL, 0, 0), TILE(0x05, COL3_PAL, 0, 0), TILE(0x03, COL3_PAL, 0, 0), TILE(0x09, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_CHK_CRN_INS_TR", TILE(0x05, COL3_PAL, H, 0), TILE(0x08, COL3_PAL, H, 0), TILE(0x09, COL3_PAL, H, 0), TILE(0x03, COL3_PAL, H, 0), COL_FULL)
    Metatile("COL3_CHK_CRN_INS_BL", TILE(0x03, COL3_PAL, 0, V), TILE(0x09, COL3_PAL, 0, V), TILE(0x08, COL3_PAL, 0, V), TILE(0x05, COL3_PAL, 0, V), COL_FULL)
    Metatile("COL3_CHK_CRN_INS_BR", TILE(0x09, COL3_PAL, H, V), TILE(0x03, COL3_PAL, H, V), TILE(0x05, COL3_PAL, H, V), TILE(0x08, COL3_PAL, H, V), COL_FULL)
    Metatile("COL3_CHK_DB_CRN_TOP", TILE(0x06, COL3_PAL, 0, 0), TILE(0x06, COL3_PAL, H, 0), TILE(0x04, COL3_PAL, 0, V), TILE(0x04, COL3_PAL, H, V), COL_FULL)
    Metatile("COL3_CHK_DB_CRN_BOT", TILE(0x04, COL3_PAL, 0, 0), TILE(0x04, COL3_PAL, H, 0), TILE(0x06, COL3_PAL, 0, V), TILE(0x06, COL3_PAL, H, V), COL_FULL)
    Metatile("COL3_CHK_DB_CRN_LFT", TILE(0x06, COL3_PAL, 0, 0), TILE(0x02, COL3_PAL, H, 0), TILE(0x06, COL3_PAL, 0, V), TILE(0x02, COL3_PAL, H, V), COL_FULL)
    Metatile("COL3_CHK_DB_CRN_RGT", TILE(0x02, COL3_PAL, 0, 0), TILE(0x06, COL3_PAL, H, 0), TILE(0x02, COL3_PAL, 0, V), TILE(0x06, COL3_PAL, H, V), COL_FULL) // 0x3e0
    Metatile("COL3_CHK_DB_SIDE_V",  TILE(0x04, COL3_PAL, 0, 0), TILE(0x04, COL3_PAL, H, 0), TILE(0x04, COL3_PAL, 0, V), TILE(0x04, COL3_PAL, H, V), COL_FULL)
    Metatile("COL3_CHK_DB_SIDE_H",  TILE(0x02, COL3_PAL, 0, 0), TILE(0x02, COL3_PAL, H, 0), TILE(0x02, COL3_PAL, 0, V), TILE(0x02, COL3_PAL, H, V), COL_FULL)
    Metatile("COL3_CHK_FILLER",     TILE(0x0a, COL3_PAL, 0, 0), TILE(0x0a, COL3_PAL, H, 0), TILE(0x0a, COL3_PAL, 0, V), TILE(0x0a, COL3_PAL, H, V), COL_NONE)

    Metatile("COL3_CHK_CORNER_TL", TILE(0x0B, COL3_PAL, 0, 0), TILE(0x05, COL3_PAL, 0, 0), TILE(0x03, COL3_PAL, 0, 0), TILE(0x09, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_CHK_CORNER_TR", TILE(0x05, COL3_PAL, H, 0), TILE(0x0B, COL3_PAL, H, 0), TILE(0x09, COL3_PAL, H, 0), TILE(0x03, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_CHK_CORNER_BL", TILE(0x03, COL3_PAL, 0, V), TILE(0x09, COL3_PAL, 0, V), TILE(0x0B, COL3_PAL, 0, V), TILE(0x05, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_CHK_CORNER_BR", TILE(0x09, COL3_PAL, H, V), TILE(0x03, COL3_PAL, H, V), TILE(0x05, COL3_PAL, H, V), TILE(0x0B, COL3_PAL, H, V), COL_NONE) // 0x3e8

    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)

    Metatile("COL3_X_FULL",       TILE(0x13, COL3_PAL, 0, 0), TILE(0x14, COL3_PAL, 0, 0), TILE(0x15, COL3_PAL, 0, 0), TILE(0x16, COL3_PAL, 0, 0), COL_FULL) // 0x3f0
    Metatile("COL3_X_SIDE_UP",    TILE(0x17, COL3_PAL, 0, 0), TILE(0x18, COL3_PAL, 0, 0), TILE(0x19, COL3_PAL, 0, 0), TILE(0x1a, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_X_SIDE_DOWN",  TILE(0x19, COL3_PAL, 0, V), TILE(0x1a, COL3_PAL, 0, V), TILE(0x17, COL3_PAL, 0, V), TILE(0x18, COL3_PAL, 0, V), COL_FULL)
    Metatile("COL3_X_SIDE_LEFT",  TILE(0x1b, COL3_PAL, 0, 0), TILE(0x1c, COL3_PAL, 0, 0), TILE(0x1d, COL3_PAL, 0, 0), TILE(0x1a, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_X_SIDE_RIGHT", TILE(0x1c, COL3_PAL, H, 0), TILE(0x1b, COL3_PAL, H, 0), TILE(0x1a, COL3_PAL, H, 0), TILE(0x1d, COL3_PAL, H, 0), COL_FULL)
    Metatile("COL3_X_CORNER_TL",  TILE(0x13, COL3_PAL, 0, 0), TILE(0x18, COL3_PAL, 0, 0), TILE(0x1d, COL3_PAL, 0, 0), TILE(0x1a, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_X_CORNER_TR",  TILE(0x18, COL3_PAL, H, 0), TILE(0x13, COL3_PAL, H, 0), TILE(0x1a, COL3_PAL, H, 0), TILE(0x1d, COL3_PAL, H, 0), COL_FULL)
    Metatile("COL3_X_CORNER_BL",  TILE(0x1d, COL3_PAL, 0, V), TILE(0x1a, COL3_PAL, 0, V), TILE(0x13, COL3_PAL, 0, V), TILE(0x18, COL3_PAL, 0, V), COL_FULL)
    Metatile("COL3_X_CORNER_BR",  TILE(0x1a, COL3_PAL, H, V), TILE(0x1d, COL3_PAL, H, V), TILE(0x18, COL3_PAL, H, V), TILE(0x13, COL3_PAL, H, V), COL_FULL) // 0x3f8
    Metatile("COL3_X_INS_CRN_TL", TILE(0x1e, COL3_PAL, 0, 0), TILE(0x1c, COL3_PAL, 0, 0), TILE(0x19, COL3_PAL, 0, 0), TILE(0x1a, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_X_INS_CRN_TR", TILE(0x22, COL3_PAL, 0, 0), TILE(0x1f, COL3_PAL, 0, 0), TILE(0x19, COL3_PAL, 0, 0), TILE(0x1a, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_X_INS_CRN_BL", TILE(0x22, COL3_PAL, 0, 0), TILE(0x1c, COL3_PAL, 0, 0), TILE(0x20, COL3_PAL, 0, 0), TILE(0x1a, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_X_INS_CRN_BR", TILE(0x22, COL3_PAL, 0, 0), TILE(0x1c, COL3_PAL, 0, 0), TILE(0x19, COL3_PAL, 0, 0), TILE(0x21, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_X_FILLER",     TILE(0x22, COL3_PAL, 0, 0), TILE(0x1c, COL3_PAL, 0, 0), TILE(0x19, COL3_PAL, 0, 0), TILE(0x1a, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_X_DB_CRN_TOP", TILE(0x13, COL3_PAL, 0, 0), TILE(0x14, COL3_PAL, 0, 0), TILE(0x1d, COL3_PAL, 0, 0), TILE(0x23, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_X_DB_CRN_BOT", TILE(0x1b, COL3_PAL, 0, 0), TILE(0x25, COL3_PAL, 0, 0), TILE(0x15, COL3_PAL, 0, 0), TILE(0x16, COL3_PAL, 0, 0), COL_FULL)
        
    Metatile("COL3_X_DB_CRN_LFT", TILE(0x13, COL3_PAL, 0, 0), TILE(0x18, COL3_PAL, 0, 0), TILE(0x15, COL3_PAL, 0, 0), TILE(0x24, COL3_PAL, 0, 0), COL_FULL) // 0x400
    Metatile("COL3_X_DB_CRN_RGT", TILE(0x18, COL3_PAL, H, 0), TILE(0x13, COL3_PAL, H, 0), TILE(0x24, COL3_PAL, H, 0), TILE(0x15, COL3_PAL, H, 0), COL_FULL)
    Metatile("COL3_X_DB_SIDE_V",  TILE(0x1b, COL3_PAL, 0, 0), TILE(0x25, COL3_PAL, 0, 0), TILE(0x1d, COL3_PAL, 0, 0), TILE(0x23, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_X_DB_SIDE_H",  TILE(0x17, COL3_PAL, 0, 0), TILE(0x18, COL3_PAL, 0, 0), TILE(0x12, COL3_PAL, 0, 0), TILE(0x24, COL3_PAL, 0, 0), COL_FULL)
    
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE) // 0x408
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)

    Metatile("COL3_+_FULL",       TILE(0x2a, COL3_PAL, 0, 0), TILE(0x2b, COL3_PAL, 0, 0), TILE(0x2c, COL3_PAL, 0, 0), TILE(0x2d, COL3_PAL, 0, 0), COL_FULL) // 0x410
    Metatile("COL3_+_SIDE_UP",    TILE(0x2e, COL3_PAL, 0, 0), TILE(0x2f, COL3_PAL, 0, 0), TILE(0x30, COL3_PAL, 0, 0), TILE(0x31, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_+_SIDE_DOWN",  TILE(0x30, COL3_PAL, 0, V), TILE(0x31, COL3_PAL, 0, V), TILE(0x2e, COL3_PAL, 0, V), TILE(0x2f, COL3_PAL, 0, V), COL_FULL)
    Metatile("COL3_+_SIDE_LEFT",  TILE(0x32, COL3_PAL, 0, 0), TILE(0x33, COL3_PAL, 0, 0), TILE(0x34, COL3_PAL, 0, 0), TILE(0x31, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_+_SIDE_RIGHT", TILE(0x33, COL3_PAL, H, 0), TILE(0x32, COL3_PAL, H, 0), TILE(0x31, COL3_PAL, H, 0), TILE(0x34, COL3_PAL, H, 0), COL_FULL)
    Metatile("COL3_+_CORNER_TL",  TILE(0x2a, COL3_PAL, 0, 0), TILE(0x2f, COL3_PAL, 0, 0), TILE(0x34, COL3_PAL, 0, 0), TILE(0x31, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_+_CORNER_TR",  TILE(0x2f, COL3_PAL, H, 0), TILE(0x2a, COL3_PAL, H, 0), TILE(0x31, COL3_PAL, H, 0), TILE(0x34, COL3_PAL, H, 0), COL_FULL)
    Metatile("COL3_+_CORNER_BL",  TILE(0x34, COL3_PAL, 0, V), TILE(0x31, COL3_PAL, 0, V), TILE(0x2a, COL3_PAL, 0, V), TILE(0x2f, COL3_PAL, 0, V), COL_FULL)
    Metatile("COL3_+_CORNER_BR",  TILE(0x31, COL3_PAL, H, V), TILE(0x34, COL3_PAL, H, V), TILE(0x2f, COL3_PAL, H, V), TILE(0x2a, COL3_PAL, H, V), COL_FULL) // 0x418
    Metatile("COL3_+_FILLER",     TILE(0x35, COL3_PAL, 0, 0), TILE(0x33, COL3_PAL, 0, 0), TILE(0x30, COL3_PAL, 0, 0), TILE(0x31, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_+_DB_CRN_TOP", TILE(0x2a, COL3_PAL, 0, 0), TILE(0x2b, COL3_PAL, 0, 0), TILE(0x34, COL3_PAL, 0, 0), TILE(0x36, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_+_DB_CRN_BOT", TILE(0x34, COL3_PAL, 0, V), TILE(0x36, COL3_PAL, 0, V), TILE(0x2a, COL3_PAL, 0, V), TILE(0x2b, COL3_PAL, 0, V), COL_FULL)
    Metatile("COL3_+_DB_CRN_LFT", TILE(0x2a, COL3_PAL, 0, 0), TILE(0x2f, COL3_PAL, 0, 0), TILE(0x2c, COL3_PAL, 0, 0), TILE(0x37, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_+_DB_CRN_RGT", TILE(0x2f, COL3_PAL, H, 0), TILE(0x2a, COL3_PAL, H, 0), TILE(0x39, COL3_PAL, 0, 0), TILE(0x2d, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_+_DB_SIDE_V",  TILE(0x32, COL3_PAL, 0, 0), TILE(0x38, COL3_PAL, 0, 0), TILE(0x34, COL3_PAL, 0, 0), TILE(0x36, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_+_DB_SIDE_H",  TILE(0x2e, COL3_PAL, 0, 0), TILE(0x2f, COL3_PAL, 0, 0), TILE(0x39, COL3_PAL, 0, 0), TILE(0x37, COL3_PAL, 0, 0), COL_FULL)
    
    Metatile("COL3_BLK_FULL",        TILE(0x3b, COL3_PAL, 0, 0), TILE(0x3b, COL3_PAL, H, 0), TILE(0x3b, COL3_PAL, 0, V), TILE(0x3b, COL3_PAL, H, V), COL_FULL) // 0x420
    Metatile("COL3_BLK_SIDE_TOP",    TILE(0x3c, COL3_PAL, 0, 0), TILE(0x3c, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_BLK_SIDE_BOTTOM", TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3c, COL3_PAL, 0, V), TILE(0x3c, COL3_PAL, 0, V), COL_FULL)
    Metatile("COL3_BLK_SIDE_LEFT",   TILE(0x3d, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3d, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_BLK_SIDE_RIGHT",  TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3d, COL3_PAL, H, 0), TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3d, COL3_PAL, H, 0), COL_FULL)
    Metatile("COL3_BLK_CORNER_TL",   TILE(0x3b, COL3_PAL, 0, 0), TILE(0x3c, COL3_PAL, 0, 0), TILE(0x3d, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_BLK_CORNER_TR",   TILE(0x3c, COL3_PAL, H, 0), TILE(0x3b, COL3_PAL, H, 0), TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3d, COL3_PAL, H, 0), COL_FULL)
    Metatile("COL3_BLK_CORNER_BL",   TILE(0x3d, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3b, COL3_PAL, 0, V), TILE(0x3c, COL3_PAL, 0, V), COL_FULL)
    Metatile("COL3_BLK_CORNER_BR",   TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3d, COL3_PAL, H, 0), TILE(0x3c, COL3_PAL, 0, V), TILE(0x3b, COL3_PAL, H, V), COL_FULL) // 0x428
    Metatile("COL3_BLK_INS_CRN_TL",  TILE(0x3e, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_BLK_INS_CRN_TR",  TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3e, COL3_PAL, H, 0), TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_BLK_INS_CRN_BL",  TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3e, COL3_PAL, 0, V), TILE(0x3a, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_BLK_INS_CRN_BR",  TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3e, COL3_PAL, V, H), COL_FULL)
    Metatile("COL3_BLK_FILLER",      TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_BLK_DB_CRN_TOP",  TILE(0x3b, COL3_PAL, 0, 0), TILE(0x3b, COL3_PAL, H, 0), TILE(0x3d, COL3_PAL, 0, 0), TILE(0x3d, COL3_PAL, H, 0), COL_FULL)
    Metatile("COL3_BLK_DB_CRN_BOT",  TILE(0x3d, COL3_PAL, 0, 0), TILE(0x3d, COL3_PAL, H, 0), TILE(0x3b, COL3_PAL, 0, V), TILE(0x3b, COL3_PAL, H, V), COL_FULL)

    Metatile("COL3_BLK_DB_CRN_LFT",  TILE(0x3b, COL3_PAL, 0, 0), TILE(0x3c, COL3_PAL, 0, 0), TILE(0x3b, COL3_PAL, 0, V), TILE(0x3c, COL3_PAL, 0, V), COL_FULL) // 0x430
    Metatile("COL3_BLK_DB_CRN_RGT",  TILE(0x3c, COL3_PAL, 0, 0), TILE(0x3b, COL3_PAL, H, 0), TILE(0x3c, COL3_PAL, 0, V), TILE(0x3b, COL3_PAL, H, V), COL_FULL)
    Metatile("COL3_BLK_DB_SIDE_H",   TILE(0x3d, COL3_PAL, 0, 0), TILE(0x3d, COL3_PAL, H, 0), TILE(0x3d, COL3_PAL, 0, 0), TILE(0x3d, COL3_PAL, H, 0), COL_FULL)
    Metatile("COL3_BLK_DB_SIDE_V",   TILE(0x3c, COL3_PAL, 0, 0), TILE(0x3c, COL3_PAL, 0, 0), TILE(0x3c, COL3_PAL, 0, V), TILE(0x3c, COL3_PAL, 0, V), COL_FULL)

    Metatile("COL3_BLK_SLAB_TOP",    TILE(0x26, COL3_PAL, 0, 0), TILE(0x26, COL3_PAL, H, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), COL_SLAB_TOP)
    Metatile("COL3_BLK_SLAB_BOT",    TILE(0x00, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x26, COL3_PAL, 0, 0), TILE(0x26, COL3_PAL, H, 0), COL_SLAB_BOTTOM)
    Metatile("COL3_BLK_SLAB_LFT",    TILE(0x27, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x27, COL3_PAL, 0, V), TILE(0x00, COL3_PAL, 0, 0), COL_SLAB_LEFT)
    Metatile("COL3_BLK_SLAB_RGT",    TILE(0x00, COL3_PAL, 0, 0), TILE(0x27, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x27, COL3_PAL, 0, V), COL_SLAB_RIGHT)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x438
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    
    Metatile("COL3_BRICKS_FULL",        TILE(0x3f, COL3_PAL, 0, 0), TILE(0x3f, COL3_PAL, H, 0), TILE(0x40, COL3_PAL, 0, 0), TILE(0x41, COL3_PAL, 0, 0), COL_FULL) // 0x440
    Metatile("COL3_BRICKS_SIDE_TOP",    TILE(0x42, COL3_PAL, 0, 0), TILE(0x42, COL3_PAL, H, 0), TILE(0x43, COL3_PAL, 0, 0), TILE(0x44, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_BRICKS_SIDE_BOTTOM", TILE(0x43, COL3_PAL, 0, V), TILE(0x44, COL3_PAL, 0, V), TILE(0x42, COL3_PAL, 0, V), TILE(0x42, COL3_PAL, H, V), COL_FULL)
    Metatile("COL3_BRICKS_SIDE_LEFT",   TILE(0x45, COL3_PAL, 0, 0), TILE(0x46, COL3_PAL, 0, 0), TILE(0x47, COL3_PAL, 0, 0), TILE(0x44, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_BRICKS_SIDE_RIGHT",  TILE(0x46, COL3_PAL, H, 0), TILE(0x45, COL3_PAL, H, 0), TILE(0x44, COL3_PAL, H, 0), TILE(0x47, COL3_PAL, H, 0), COL_FULL)
    Metatile("COL3_BRICKS_CORNER_TL",   TILE(0x3f, COL3_PAL, 0, 0), TILE(0x42, COL3_PAL, H, 0), TILE(0x47, COL3_PAL, 0, 0), TILE(0x44, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_BRICKS_CORNER_TR",   TILE(0x42, COL3_PAL, 0, 0), TILE(0x3f, COL3_PAL, H, 0), TILE(0x44, COL3_PAL, H, 0), TILE(0x47, COL3_PAL, H, 0), COL_FULL)
    Metatile("COL3_BRICKS_CORNER_BL",   TILE(0x47, COL3_PAL, 0, V), TILE(0x44, COL3_PAL, 0, V), TILE(0x3f, COL3_PAL, 0, V), TILE(0x42, COL3_PAL, H, V), COL_FULL)
    Metatile("COL3_BRICKS_CORNER_BR",   TILE(0x44, COL3_PAL, H, V), TILE(0x47, COL3_PAL, H, V), TILE(0x42, COL3_PAL, 0, V), TILE(0x3f, COL3_PAL, H, V), COL_FULL) // 0x448
    Metatile("COL3_BRICKS_INS_CRN_TL",  TILE(0x48, COL3_PAL, 0, 0), TILE(0x46, COL3_PAL, 0, 0), TILE(0x43, COL3_PAL, 0, 0), TILE(0x44, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_BRICKS_INS_CRN_TR",  TILE(0x46, COL3_PAL, H, 0), TILE(0x48, COL3_PAL, H, 0), TILE(0x43, COL3_PAL, 0, 0), TILE(0x44, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_BRICKS_INS_CRN_BL",  TILE(0x43, COL3_PAL, 0, V), TILE(0x44, COL3_PAL, 0, V), TILE(0x48, COL3_PAL, 0, V), TILE(0x46, COL3_PAL, 0, V), COL_FULL)
    Metatile("COL3_BRICKS_INS_CRN_BR",  TILE(0x43, COL3_PAL, 0, V), TILE(0x44, COL3_PAL, 0, V), TILE(0x46, COL3_PAL, H, V), TILE(0x48, COL3_PAL, H, V), COL_FULL)
    Metatile("COL3_BRICKS_FILLER",      TILE(0x46, COL3_PAL, H, 0), TILE(0x46, COL3_PAL, 0, 0), TILE(0x43, COL3_PAL, 0, 0), TILE(0x44, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_BRICKS_DB_CRN_TOP",  TILE(0x3f, COL3_PAL, 0, 0), TILE(0x3f, COL3_PAL, H, 0), TILE(0x47, COL3_PAL, 0, 0), TILE(0x4b, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_BRICKS_DB_CRN_BOT",  TILE(0x47, COL3_PAL, 0, V), TILE(0x4b, COL3_PAL, 0, V), TILE(0x3f, COL3_PAL, 0, V), TILE(0x3f, COL3_PAL, H, V), COL_FULL)

    Metatile("COL3_BRICKS_DB_CRN_LFT",  TILE(0x3f, COL3_PAL, 0, 0), TILE(0x42, COL3_PAL, H, 0), TILE(0x40, COL3_PAL, 0, 0), TILE(0x4c, COL3_PAL, 0, 0), COL_FULL) // 0x450
    Metatile("COL3_BRICKS_DB_CRN_RGT",  TILE(0x42, COL3_PAL, 0, 0), TILE(0x3f, COL3_PAL, H, 0), TILE(0x4c, COL3_PAL, H, 0), TILE(0x40, COL3_PAL, H, 0), COL_FULL)
    Metatile("COL3_BRICKS_SIDE_H",      TILE(0x45, COL3_PAL, 0, 0), TILE(0x45, COL3_PAL, H, 0), TILE(0x45, COL3_PAL, 0, 0), TILE(0x4b, COL3_PAL, 0, 0), COL_FULL)
    Metatile("COL3_BRICKS_SIDE_V",      TILE(0x42, COL3_PAL, 0, 0), TILE(0x42, COL3_PAL, H, 0), TILE(0x4d, COL3_PAL, 0, 0), TILE(0x4c, COL3_PAL, 0, 0), COL_FULL)

    Metatile("COL3_SPIKE_UP",            TILE(0x165, COL3_PAL, 0, 0), TILE(0x165, COL3_PAL, H, 0), TILE(0x175, COL3_PAL, 0, 0), TILE(0x175, COL3_PAL, H, 0), COL_SPIKE_TOP)
    Metatile("COL3_SPIKE_DOWN",          TILE(0x175, COL3_PAL, 0, V), TILE(0x175, COL3_PAL, H, V), TILE(0x165, COL3_PAL, 0, V), TILE(0x165, COL3_PAL, H, V), COL_SPIKE_BOTTOM)
    Metatile("COL3_SPIKE_LEFT",          TILE(0x166, COL3_PAL, 0, 0), TILE(0x167, COL3_PAL, 0, 0), TILE(0x166, COL3_PAL, 0, V), TILE(0x167, COL3_PAL, 0, V), COL_SPIKE_LEFT)
    Metatile("COL3_SPIKE_RIGHT",         TILE(0x167, COL3_PAL, H, 0), TILE(0x166, COL3_PAL, H, 0), TILE(0x167, COL3_PAL, H, V), TILE(0x166, COL3_PAL, H, V), COL_SPIKE_RIGHT)
    Metatile("COL3_SMALL_SPIKE_BOTTOM",  TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x16a, COL3_PAL, 0, 0), TILE(0x16a, COL3_PAL, H, 0), COL_SMALL_SPIKE_BOTTOM) // 0x458
    Metatile("COL3_SMALL_SPIKE_TOP",     TILE(0x16a, COL3_PAL, 0, V), TILE(0x16a, COL3_PAL, H, V), TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), COL_SMALL_SPIKE_TOP)
    Metatile("COL3_SMALL_SPIKE_LEFT",    TILE(0x17a, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x17a, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, 0), COL_SMALL_SPIKE_LEFT)
    Metatile("COL3_SMALL_SPIKE_RIGHT",   TILE(0x000, COL3_PAL, 0, 0), TILE(0x17a, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x17a, COL3_PAL, H, V), COL_SMALL_SPIKE_RIGHT)
    Metatile("COL3_MEDIUM_SPIKE_BOTTOM", TILE(0x168, COL3_PAL, 0, 0), TILE(0x168, COL3_PAL, H, 0), TILE(0x178, COL3_PAL, 0, 0), TILE(0x178, COL3_PAL, H, 0), COL_MEDIUM_SPIKE_BOTTOM)
    Metatile("COL3_MEDIUM_SPIKE_TOP",    TILE(0x178, COL3_PAL, 0, V), TILE(0x178, COL3_PAL, H, V), TILE(0x168, COL3_PAL, 0, V), TILE(0x168, COL3_PAL, H, V), COL_MEDIUM_SPIKE_TOP)
    Metatile("COL3_MEDIUM_SPIKE_LEFT",   TILE(0x179, COL3_PAL, 0, 0), TILE(0x169, COL3_PAL, 0, 0), TILE(0x179, COL3_PAL, 0, V), TILE(0x169, COL3_PAL, 0, V), COL_MEDIUM_SPIKE_LEFT)
    Metatile("COL3_MEDIUM_SPIKE_RIGHT",  TILE(0x169, COL3_PAL, H, 0), TILE(0x179, COL3_PAL, H, 0), TILE(0x169, COL3_PAL, H, V), TILE(0x179, COL3_PAL, H, V), COL_MEDIUM_SPIKE_RIGHT)

    Metatile("COL3_SLOPE_45_UP",      TILE(0x00, COL3_PAL, 0, 0), TILE(0x7b, COL3_PAL, 0, 0), TILE(0x7b, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), COL_SLOPE_45_UP) // 0x460
    Metatile("COL3_SLOPE_45_DOWN",    TILE(0x7b, COL3_PAL, H, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, H, 0), TILE(0x7b, COL3_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL3_SLOPE_45_UP_UD",   TILE(0x7b, COL3_PAL, 0, V), TILE(0x3a, COL3_PAL, 0, V), TILE(0x00, COL3_PAL, 0, V), TILE(0x7b, COL3_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL3_SLOPE_45_DOWN_UD", TILE(0x3a, COL3_PAL, H, V), TILE(0x7b, COL3_PAL, H, V), TILE(0x7b, COL3_PAL, H, V), TILE(0x00, COL3_PAL, 0, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL3_22_UP_1",          TILE(0x00, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x7c, COL3_PAL, 0, 0), TILE(0x7d, COL3_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL3_22_UP_2",          TILE(0x7c, COL3_PAL, 0, 0), TILE(0x7d, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("COL3_22_DOWN_1",        TILE(0x7d, COL3_PAL, H, 0), TILE(0x7c, COL3_PAL, H, 0), TILE(0x3a, COL3_PAL, H, 0), TILE(0x3a, COL3_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL3_22_DOWN_2",        TILE(0x00, COL3_PAL, H, 0), TILE(0x00, COL3_PAL, H, 0), TILE(0x7d, COL3_PAL, H, 0), TILE(0x7c, COL3_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL3_22_UP_UD_1",       TILE(0x7c, COL3_PAL, 0, V), TILE(0x7d, COL3_PAL, 0, V), TILE(0x00, COL3_PAL, 0, V), TILE(0x00, COL3_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x468
    Metatile("COL3_22_UP_UD_2",       TILE(0x3a, COL3_PAL, 0, V), TILE(0x3a, COL3_PAL, 0, V), TILE(0x7c, COL3_PAL, 0, V), TILE(0x7d, COL3_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL3_22_DOWN_UD_1",     TILE(0x3a, COL3_PAL, H, V), TILE(0x3a, COL3_PAL, H, V), TILE(0x7d, COL3_PAL, H, V), TILE(0x7c, COL3_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL3_22_DOWN_UD_2",     TILE(0x7d, COL3_PAL, H, V), TILE(0x7c, COL3_PAL, H, V), TILE(0x00, COL3_PAL, H, V), TILE(0x00, COL3_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL3_66_UP_1",          TILE(0x00, COL3_PAL, 0, 0), TILE(0x7f, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x7e, COL3_PAL, 0, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL3_66_UP_2",          TILE(0x7f, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), TILE(0x7e, COL3_PAL, 0, 0), TILE(0x3a, COL3_PAL, 0, 0), COL_SLOPE_66_UP_2)
    Metatile("COL3_66_DOWN_1",        TILE(0x3a, COL3_PAL, H, 0), TILE(0x7f, COL3_PAL, H, 0), TILE(0x3a, COL3_PAL, H, 0), TILE(0x7e, COL3_PAL, H, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL3_66_DOWN_2",        TILE(0x7f, COL3_PAL, H, 0), TILE(0x00, COL3_PAL, H, 0), TILE(0x7e, COL3_PAL, H, 0), TILE(0x00, COL3_PAL, H, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL3_66_UP_UD_1",       TILE(0x00, COL3_PAL, 0, V), TILE(0x7e, COL3_PAL, 0, V), TILE(0x00, COL3_PAL, 0, V), TILE(0x7f, COL3_PAL, 0, V), COL_SLOPE_66_UP_UD_1) // 0x470
    Metatile("COL3_66_UP_UD_2",       TILE(0x7e, COL3_PAL, 0, V), TILE(0x3a, COL3_PAL, 0, V), TILE(0x7f, COL3_PAL, 0, V), TILE(0x3a, COL3_PAL, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL3_66_DOWN_UD_1",     TILE(0x3a, COL3_PAL, H, V), TILE(0x7e, COL3_PAL, H, V), TILE(0x3a, COL3_PAL, H, V), TILE(0x7f, COL3_PAL, H, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL3_66_DOWN_UD_2",     TILE(0x7e, COL3_PAL, H, V), TILE(0x00, COL3_PAL, H, V), TILE(0x7f, COL3_PAL, H, V), TILE(0x00, COL3_PAL, H, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x478
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    // COL4 METATILES

    Metatile("COL4_CHK_FULL",       TILE(0x01, COL4_PAL, 0, 0), TILE(0x01, COL4_PAL, H, 0), TILE(0x01, COL4_PAL, 0, V), TILE(0x01, COL4_PAL, H, V), COL_FULL) // 0x480
    Metatile("COL4_CHK_SIDE_UP",    TILE(0x02, COL4_PAL, 0, 0), TILE(0x02, COL4_PAL, H, 0), TILE(0x03, COL4_PAL, 0, 0), TILE(0x03, COL4_PAL, H, 0), COL_FULL)
    Metatile("COL4_CHK_SIDE_DOWN",  TILE(0x03, COL4_PAL, 0, V), TILE(0x03, COL4_PAL, H, V), TILE(0x02, COL4_PAL, 0, V), TILE(0x02, COL4_PAL, H, V), COL_FULL)
    Metatile("COL4_CHK_SIDE_LEFT",  TILE(0x04, COL4_PAL, 0, 0), TILE(0x05, COL4_PAL, 0, 0), TILE(0x04, COL4_PAL, 0, V), TILE(0x05, COL4_PAL, 0, V), COL_FULL)
    Metatile("COL4_CHK_SIDE_RIGHT", TILE(0x05, COL4_PAL, H, 0), TILE(0x04, COL4_PAL, H, 0), TILE(0x05, COL4_PAL, H, V), TILE(0x04, COL4_PAL, H, V), COL_FULL)
    Metatile("COL4_CHK_CORNER_TL",  TILE(0x06, COL4_PAL, 0, 0), TILE(0x02, COL4_PAL, H, 0), TILE(0x04, COL4_PAL, 0, V), TILE(0x07, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_CHK_CORNER_TR",  TILE(0x02, COL4_PAL, 0, 0), TILE(0x06, COL4_PAL, H, 0), TILE(0x07, COL4_PAL, H, 0), TILE(0x04, COL4_PAL, H, V), COL_FULL)
    Metatile("COL4_CHK_CORNER_BL",  TILE(0x04, COL4_PAL, 0, 0), TILE(0x07, COL4_PAL, 0, V), TILE(0x06, COL4_PAL, 0, V), TILE(0x02, COL4_PAL, H, V), COL_FULL)
    Metatile("COL4_CHK_CORNER_BR",  TILE(0x07, COL4_PAL, H, V), TILE(0x04, COL4_PAL, H, 0), TILE(0x02, COL4_PAL, 0, V), TILE(0x06, COL4_PAL, H, V), COL_FULL) // 0x488
    Metatile("COL4_CHK_CRN_INS_TL", TILE(0x08, COL4_PAL, 0, 0), TILE(0x05, COL4_PAL, 0, 0), TILE(0x03, COL4_PAL, 0, 0), TILE(0x09, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_CHK_CRN_INS_TR", TILE(0x05, COL4_PAL, H, 0), TILE(0x08, COL4_PAL, H, 0), TILE(0x09, COL4_PAL, H, 0), TILE(0x03, COL4_PAL, H, 0), COL_FULL)
    Metatile("COL4_CHK_CRN_INS_BL", TILE(0x03, COL4_PAL, 0, V), TILE(0x09, COL4_PAL, 0, V), TILE(0x08, COL4_PAL, 0, V), TILE(0x05, COL4_PAL, 0, V), COL_FULL)
    Metatile("COL4_CHK_CRN_INS_BR", TILE(0x09, COL4_PAL, H, V), TILE(0x03, COL4_PAL, H, V), TILE(0x05, COL4_PAL, H, V), TILE(0x08, COL4_PAL, H, V), COL_FULL)
    Metatile("COL4_CHK_DB_CRN_TOP", TILE(0x06, COL4_PAL, 0, 0), TILE(0x06, COL4_PAL, H, 0), TILE(0x04, COL4_PAL, 0, V), TILE(0x04, COL4_PAL, H, V), COL_FULL)
    Metatile("COL4_CHK_DB_CRN_BOT", TILE(0x04, COL4_PAL, 0, 0), TILE(0x04, COL4_PAL, H, 0), TILE(0x06, COL4_PAL, 0, V), TILE(0x06, COL4_PAL, H, V), COL_FULL)
    Metatile("COL4_CHK_DB_CRN_LFT", TILE(0x06, COL4_PAL, 0, 0), TILE(0x02, COL4_PAL, H, 0), TILE(0x06, COL4_PAL, 0, V), TILE(0x02, COL4_PAL, H, V), COL_FULL)
    Metatile("COL4_CHK_DB_CRN_RGT", TILE(0x02, COL4_PAL, 0, 0), TILE(0x06, COL4_PAL, H, 0), TILE(0x02, COL4_PAL, 0, V), TILE(0x06, COL4_PAL, H, V), COL_FULL) // 0x490
    Metatile("COL4_CHK_DB_SIDE_V",  TILE(0x04, COL4_PAL, 0, 0), TILE(0x04, COL4_PAL, H, 0), TILE(0x04, COL4_PAL, 0, V), TILE(0x04, COL4_PAL, H, V), COL_FULL)
    Metatile("COL4_CHK_DB_SIDE_H",  TILE(0x02, COL4_PAL, 0, 0), TILE(0x02, COL4_PAL, H, 0), TILE(0x02, COL4_PAL, 0, V), TILE(0x02, COL4_PAL, H, V), COL_FULL)
    Metatile("COL4_CHK_FILLER",     TILE(0x0a, COL4_PAL, 0, 0), TILE(0x0a, COL4_PAL, H, 0), TILE(0x0a, COL4_PAL, 0, V), TILE(0x0a, COL4_PAL, H, V), COL_NONE)

    Metatile("COL4_CHK_CORNER_TL", TILE(0x0B, COL4_PAL, 0, 0), TILE(0x05, COL4_PAL, 0, 0), TILE(0x03, COL4_PAL, 0, 0), TILE(0x09, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_CHK_CORNER_TR", TILE(0x05, COL4_PAL, H, 0), TILE(0x0B, COL4_PAL, H, 0), TILE(0x09, COL4_PAL, H, 0), TILE(0x03, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_CHK_CORNER_BL", TILE(0x03, COL4_PAL, 0, V), TILE(0x09, COL4_PAL, 0, V), TILE(0x0B, COL4_PAL, 0, V), TILE(0x05, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_CHK_CORNER_BR", TILE(0x09, COL4_PAL, H, V), TILE(0x03, COL4_PAL, H, V), TILE(0x05, COL4_PAL, H, V), TILE(0x0B, COL4_PAL, H, V), COL_NONE) // 0x498

    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)

    Metatile("COL4_X_FULL",       TILE(0x13, COL4_PAL, 0, 0), TILE(0x14, COL4_PAL, 0, 0), TILE(0x15, COL4_PAL, 0, 0), TILE(0x16, COL4_PAL, 0, 0), COL_FULL) // 0x4a0
    Metatile("COL4_X_SIDE_UP",    TILE(0x17, COL4_PAL, 0, 0), TILE(0x18, COL4_PAL, 0, 0), TILE(0x19, COL4_PAL, 0, 0), TILE(0x1a, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_X_SIDE_DOWN",  TILE(0x19, COL4_PAL, 0, V), TILE(0x1a, COL4_PAL, 0, V), TILE(0x17, COL4_PAL, 0, V), TILE(0x18, COL4_PAL, 0, V), COL_FULL)
    Metatile("COL4_X_SIDE_LEFT",  TILE(0x1b, COL4_PAL, 0, 0), TILE(0x1c, COL4_PAL, 0, 0), TILE(0x1d, COL4_PAL, 0, 0), TILE(0x1a, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_X_SIDE_RIGHT", TILE(0x1c, COL4_PAL, H, 0), TILE(0x1b, COL4_PAL, H, 0), TILE(0x1a, COL4_PAL, H, 0), TILE(0x1d, COL4_PAL, H, 0), COL_FULL)
    Metatile("COL4_X_CORNER_TL",  TILE(0x13, COL4_PAL, 0, 0), TILE(0x18, COL4_PAL, 0, 0), TILE(0x1d, COL4_PAL, 0, 0), TILE(0x1a, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_X_CORNER_TR",  TILE(0x18, COL4_PAL, H, 0), TILE(0x13, COL4_PAL, H, 0), TILE(0x1a, COL4_PAL, H, 0), TILE(0x1d, COL4_PAL, H, 0), COL_FULL)
    Metatile("COL4_X_CORNER_BL",  TILE(0x1d, COL4_PAL, 0, V), TILE(0x1a, COL4_PAL, 0, V), TILE(0x13, COL4_PAL, 0, V), TILE(0x18, COL4_PAL, 0, V), COL_FULL)
    Metatile("COL4_X_CORNER_BR",  TILE(0x1a, COL4_PAL, H, V), TILE(0x1d, COL4_PAL, H, V), TILE(0x18, COL4_PAL, H, V), TILE(0x13, COL4_PAL, H, V), COL_FULL) // 0x4a8
    Metatile("COL4_X_INS_CRN_TL", TILE(0x1e, COL4_PAL, 0, 0), TILE(0x1c, COL4_PAL, 0, 0), TILE(0x19, COL4_PAL, 0, 0), TILE(0x1a, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_X_INS_CRN_TR", TILE(0x22, COL4_PAL, 0, 0), TILE(0x1f, COL4_PAL, 0, 0), TILE(0x19, COL4_PAL, 0, 0), TILE(0x1a, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_X_INS_CRN_BL", TILE(0x22, COL4_PAL, 0, 0), TILE(0x1c, COL4_PAL, 0, 0), TILE(0x20, COL4_PAL, 0, 0), TILE(0x1a, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_X_INS_CRN_BR", TILE(0x22, COL4_PAL, 0, 0), TILE(0x1c, COL4_PAL, 0, 0), TILE(0x19, COL4_PAL, 0, 0), TILE(0x21, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_X_FILLER",     TILE(0x22, COL4_PAL, 0, 0), TILE(0x1c, COL4_PAL, 0, 0), TILE(0x19, COL4_PAL, 0, 0), TILE(0x1a, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_X_DB_CRN_TOP", TILE(0x13, COL4_PAL, 0, 0), TILE(0x14, COL4_PAL, 0, 0), TILE(0x1d, COL4_PAL, 0, 0), TILE(0x23, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_X_DB_CRN_BOT", TILE(0x1b, COL4_PAL, 0, 0), TILE(0x25, COL4_PAL, 0, 0), TILE(0x15, COL4_PAL, 0, 0), TILE(0x16, COL4_PAL, 0, 0), COL_FULL)
        
    Metatile("COL4_X_DB_CRN_LFT", TILE(0x13, COL4_PAL, 0, 0), TILE(0x18, COL4_PAL, 0, 0), TILE(0x15, COL4_PAL, 0, 0), TILE(0x24, COL4_PAL, 0, 0), COL_FULL) // 0x4b0
    Metatile("COL4_X_DB_CRN_RGT", TILE(0x18, COL4_PAL, H, 0), TILE(0x13, COL4_PAL, H, 0), TILE(0x24, COL4_PAL, H, 0), TILE(0x15, COL4_PAL, H, 0), COL_FULL)
    Metatile("COL4_X_DB_SIDE_V",  TILE(0x1b, COL4_PAL, 0, 0), TILE(0x25, COL4_PAL, 0, 0), TILE(0x1d, COL4_PAL, 0, 0), TILE(0x23, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_X_DB_SIDE_H",  TILE(0x17, COL4_PAL, 0, 0), TILE(0x18, COL4_PAL, 0, 0), TILE(0x12, COL4_PAL, 0, 0), TILE(0x24, COL4_PAL, 0, 0), COL_FULL)
    
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE) // 0x4b8
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)

    Metatile("COL4_+_FULL",       TILE(0x2a, COL4_PAL, 0, 0), TILE(0x2b, COL4_PAL, 0, 0), TILE(0x2c, COL4_PAL, 0, 0), TILE(0x2d, COL4_PAL, 0, 0), COL_FULL) // 0x4c0
    Metatile("COL4_+_SIDE_UP",    TILE(0x2e, COL4_PAL, 0, 0), TILE(0x2f, COL4_PAL, 0, 0), TILE(0x30, COL4_PAL, 0, 0), TILE(0x31, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_+_SIDE_DOWN",  TILE(0x30, COL4_PAL, 0, V), TILE(0x31, COL4_PAL, 0, V), TILE(0x2e, COL4_PAL, 0, V), TILE(0x2f, COL4_PAL, 0, V), COL_FULL)
    Metatile("COL4_+_SIDE_LEFT",  TILE(0x32, COL4_PAL, 0, 0), TILE(0x33, COL4_PAL, 0, 0), TILE(0x34, COL4_PAL, 0, 0), TILE(0x31, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_+_SIDE_RIGHT", TILE(0x33, COL4_PAL, H, 0), TILE(0x32, COL4_PAL, H, 0), TILE(0x31, COL4_PAL, H, 0), TILE(0x34, COL4_PAL, H, 0), COL_FULL)
    Metatile("COL4_+_CORNER_TL",  TILE(0x2a, COL4_PAL, 0, 0), TILE(0x2f, COL4_PAL, 0, 0), TILE(0x34, COL4_PAL, 0, 0), TILE(0x31, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_+_CORNER_TR",  TILE(0x2f, COL4_PAL, H, 0), TILE(0x2a, COL4_PAL, H, 0), TILE(0x31, COL4_PAL, H, 0), TILE(0x34, COL4_PAL, H, 0), COL_FULL)
    Metatile("COL4_+_CORNER_BL",  TILE(0x34, COL4_PAL, 0, V), TILE(0x31, COL4_PAL, 0, V), TILE(0x2a, COL4_PAL, 0, V), TILE(0x2f, COL4_PAL, 0, V), COL_FULL)
    Metatile("COL4_+_CORNER_BR",  TILE(0x31, COL4_PAL, H, V), TILE(0x34, COL4_PAL, H, V), TILE(0x2f, COL4_PAL, H, V), TILE(0x2a, COL4_PAL, H, V), COL_FULL) // 0x4c8
    Metatile("COL4_+_FILLER",     TILE(0x35, COL4_PAL, 0, 0), TILE(0x33, COL4_PAL, 0, 0), TILE(0x30, COL4_PAL, 0, 0), TILE(0x31, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_+_DB_CRN_TOP", TILE(0x2a, COL4_PAL, 0, 0), TILE(0x2b, COL4_PAL, 0, 0), TILE(0x34, COL4_PAL, 0, 0), TILE(0x36, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_+_DB_CRN_BOT", TILE(0x34, COL4_PAL, 0, V), TILE(0x36, COL4_PAL, 0, V), TILE(0x2a, COL4_PAL, 0, V), TILE(0x2b, COL4_PAL, 0, V), COL_FULL)
    Metatile("COL4_+_DB_CRN_LFT", TILE(0x2a, COL4_PAL, 0, 0), TILE(0x2f, COL4_PAL, 0, 0), TILE(0x2c, COL4_PAL, 0, 0), TILE(0x37, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_+_DB_CRN_RGT", TILE(0x2f, COL4_PAL, H, 0), TILE(0x2a, COL4_PAL, H, 0), TILE(0x39, COL4_PAL, 0, 0), TILE(0x2d, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_+_DB_SIDE_V",  TILE(0x32, COL4_PAL, 0, 0), TILE(0x38, COL4_PAL, 0, 0), TILE(0x34, COL4_PAL, 0, 0), TILE(0x36, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_+_DB_SIDE_H",  TILE(0x2e, COL4_PAL, 0, 0), TILE(0x2f, COL4_PAL, 0, 0), TILE(0x39, COL4_PAL, 0, 0), TILE(0x37, COL4_PAL, 0, 0), COL_FULL)
    
    Metatile("COL4_BLK_FULL",        TILE(0x3b, COL4_PAL, 0, 0), TILE(0x3b, COL4_PAL, H, 0), TILE(0x3b, COL4_PAL, 0, V), TILE(0x3b, COL4_PAL, H, V), COL_FULL) // 0x4d0
    Metatile("COL4_BLK_SIDE_TOP",    TILE(0x3c, COL4_PAL, 0, 0), TILE(0x3c, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_BLK_SIDE_BOTTOM", TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3c, COL4_PAL, 0, V), TILE(0x3c, COL4_PAL, 0, V), COL_FULL)
    Metatile("COL4_BLK_SIDE_LEFT",   TILE(0x3d, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3d, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_BLK_SIDE_RIGHT",  TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3d, COL4_PAL, H, 0), TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3d, COL4_PAL, H, 0), COL_FULL)
    Metatile("COL4_BLK_CORNER_TL",   TILE(0x3b, COL4_PAL, 0, 0), TILE(0x3c, COL4_PAL, 0, 0), TILE(0x3d, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_BLK_CORNER_TR",   TILE(0x3c, COL4_PAL, H, 0), TILE(0x3b, COL4_PAL, H, 0), TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3d, COL4_PAL, H, 0), COL_FULL)
    Metatile("COL4_BLK_CORNER_BL",   TILE(0x3d, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3b, COL4_PAL, 0, V), TILE(0x3c, COL4_PAL, 0, V), COL_FULL)
    Metatile("COL4_BLK_CORNER_BR",   TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3d, COL4_PAL, H, 0), TILE(0x3c, COL4_PAL, 0, V), TILE(0x3b, COL4_PAL, H, V), COL_FULL) // 0x4d8
    Metatile("COL4_BLK_INS_CRN_TL",  TILE(0x3e, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_BLK_INS_CRN_TR",  TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3e, COL4_PAL, H, 0), TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_BLK_INS_CRN_BL",  TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3e, COL4_PAL, 0, V), TILE(0x3a, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_BLK_INS_CRN_BR",  TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3e, COL4_PAL, V, H), COL_FULL)
    Metatile("COL4_BLK_FILLER",      TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_BLK_DB_CRN_TOP",  TILE(0x3b, COL4_PAL, 0, 0), TILE(0x3b, COL4_PAL, H, 0), TILE(0x3d, COL4_PAL, 0, 0), TILE(0x3d, COL4_PAL, H, 0), COL_FULL)
    Metatile("COL4_BLK_DB_CRN_BOT",  TILE(0x3d, COL4_PAL, 0, 0), TILE(0x3d, COL4_PAL, H, 0), TILE(0x3b, COL4_PAL, 0, V), TILE(0x3b, COL4_PAL, H, V), COL_FULL)

    Metatile("COL4_BLK_DB_CRN_LFT",  TILE(0x3b, COL4_PAL, 0, 0), TILE(0x3c, COL4_PAL, 0, 0), TILE(0x3b, COL4_PAL, 0, V), TILE(0x3c, COL4_PAL, 0, V), COL_FULL) // 0x4e0
    Metatile("COL4_BLK_DB_CRN_RGT",  TILE(0x3c, COL4_PAL, 0, 0), TILE(0x3b, COL4_PAL, H, 0), TILE(0x3c, COL4_PAL, 0, V), TILE(0x3b, COL4_PAL, H, V), COL_FULL)
    Metatile("COL4_BLK_DB_SIDE_H",   TILE(0x3d, COL4_PAL, 0, 0), TILE(0x3d, COL4_PAL, H, 0), TILE(0x3d, COL4_PAL, 0, 0), TILE(0x3d, COL4_PAL, H, 0), COL_FULL)
    Metatile("COL4_BLK_DB_SIDE_V",   TILE(0x3c, COL4_PAL, 0, 0), TILE(0x3c, COL4_PAL, 0, 0), TILE(0x3c, COL4_PAL, 0, V), TILE(0x3c, COL4_PAL, 0, V), COL_FULL)
    
    Metatile("COL4_BLK_SLAB_TOP",    TILE(0x26, COL4_PAL, 0, 0), TILE(0x26, COL4_PAL, H, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), COL_SLAB_TOP)
    Metatile("COL4_BLK_SLAB_BOT",    TILE(0x00, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x26, COL4_PAL, 0, 0), TILE(0x26, COL4_PAL, H, 0), COL_SLAB_BOTTOM)
    Metatile("COL4_BLK_SLAB_LFT",    TILE(0x27, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x27, COL4_PAL, 0, V), TILE(0x00, COL4_PAL, 0, 0), COL_SLAB_LEFT)
    Metatile("COL4_BLK_SLAB_RGT",    TILE(0x00, COL4_PAL, 0, 0), TILE(0x27, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x27, COL4_PAL, 0, V), COL_SLAB_RIGHT)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x4e8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    
    Metatile("COL4_BRICKS_FULL",        TILE(0x3f, COL4_PAL, 0, 0), TILE(0x3f, COL4_PAL, H, 0), TILE(0x40, COL4_PAL, 0, 0), TILE(0x41, COL4_PAL, 0, 0), COL_FULL) // 0x4f0
    Metatile("COL4_BRICKS_SIDE_TOP",    TILE(0x42, COL4_PAL, 0, 0), TILE(0x42, COL4_PAL, H, 0), TILE(0x43, COL4_PAL, 0, 0), TILE(0x44, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_BRICKS_SIDE_BOTTOM", TILE(0x43, COL4_PAL, 0, V), TILE(0x44, COL4_PAL, 0, V), TILE(0x42, COL4_PAL, 0, V), TILE(0x42, COL4_PAL, H, V), COL_FULL)
    Metatile("COL4_BRICKS_SIDE_LEFT",   TILE(0x45, COL4_PAL, 0, 0), TILE(0x46, COL4_PAL, 0, 0), TILE(0x47, COL4_PAL, 0, 0), TILE(0x44, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_BRICKS_SIDE_RIGHT",  TILE(0x46, COL4_PAL, H, 0), TILE(0x45, COL4_PAL, H, 0), TILE(0x44, COL4_PAL, H, 0), TILE(0x47, COL4_PAL, H, 0), COL_FULL)
    Metatile("COL4_BRICKS_CORNER_TL",   TILE(0x3f, COL4_PAL, 0, 0), TILE(0x42, COL4_PAL, H, 0), TILE(0x47, COL4_PAL, 0, 0), TILE(0x44, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_BRICKS_CORNER_TR",   TILE(0x42, COL4_PAL, 0, 0), TILE(0x3f, COL4_PAL, H, 0), TILE(0x44, COL4_PAL, H, 0), TILE(0x47, COL4_PAL, H, 0), COL_FULL)
    Metatile("COL4_BRICKS_CORNER_BL",   TILE(0x47, COL4_PAL, 0, V), TILE(0x44, COL4_PAL, 0, V), TILE(0x3f, COL4_PAL, 0, V), TILE(0x42, COL4_PAL, H, V), COL_FULL)
    Metatile("COL4_BRICKS_CORNER_BR",   TILE(0x44, COL4_PAL, H, V), TILE(0x47, COL4_PAL, H, V), TILE(0x42, COL4_PAL, 0, V), TILE(0x3f, COL4_PAL, H, V), COL_FULL) // 0x4f8
    Metatile("COL4_BRICKS_INS_CRN_TL",  TILE(0x48, COL4_PAL, 0, 0), TILE(0x46, COL4_PAL, 0, 0), TILE(0x43, COL4_PAL, 0, 0), TILE(0x44, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_BRICKS_INS_CRN_TR",  TILE(0x46, COL4_PAL, H, 0), TILE(0x48, COL4_PAL, H, 0), TILE(0x43, COL4_PAL, 0, 0), TILE(0x44, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_BRICKS_INS_CRN_BL",  TILE(0x43, COL4_PAL, 0, V), TILE(0x44, COL4_PAL, 0, V), TILE(0x48, COL4_PAL, 0, V), TILE(0x46, COL4_PAL, 0, V), COL_FULL)
    Metatile("COL4_BRICKS_INS_CRN_BR",  TILE(0x43, COL4_PAL, 0, V), TILE(0x44, COL4_PAL, 0, V), TILE(0x46, COL4_PAL, H, V), TILE(0x48, COL4_PAL, H, V), COL_FULL)
    Metatile("COL4_BRICKS_FILLER",      TILE(0x46, COL4_PAL, H, 0), TILE(0x46, COL4_PAL, 0, 0), TILE(0x43, COL4_PAL, 0, 0), TILE(0x44, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_BRICKS_DB_CRN_TOP",  TILE(0x3f, COL4_PAL, 0, 0), TILE(0x3f, COL4_PAL, H, 0), TILE(0x47, COL4_PAL, 0, 0), TILE(0x4b, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_BRICKS_DB_CRN_BOT",  TILE(0x47, COL4_PAL, 0, V), TILE(0x4b, COL4_PAL, 0, V), TILE(0x3f, COL4_PAL, 0, V), TILE(0x3f, COL4_PAL, H, V), COL_FULL)

    Metatile("COL4_BRICKS_DB_CRN_LFT",  TILE(0x3f, COL4_PAL, 0, 0), TILE(0x42, COL4_PAL, H, 0), TILE(0x40, COL4_PAL, 0, 0), TILE(0x4c, COL4_PAL, 0, 0), COL_FULL) // 0x500
    Metatile("COL4_BRICKS_DB_CRN_RGT",  TILE(0x42, COL4_PAL, 0, 0), TILE(0x3f, COL4_PAL, H, 0), TILE(0x4c, COL4_PAL, H, 0), TILE(0x40, COL4_PAL, H, 0), COL_FULL)
    Metatile("COL4_BRICKS_SIDE_H",      TILE(0x45, COL4_PAL, 0, 0), TILE(0x45, COL4_PAL, H, 0), TILE(0x45, COL4_PAL, 0, 0), TILE(0x4b, COL4_PAL, 0, 0), COL_FULL)
    Metatile("COL4_BRICKS_SIDE_V",      TILE(0x42, COL4_PAL, 0, 0), TILE(0x42, COL4_PAL, H, 0), TILE(0x4d, COL4_PAL, 0, 0), TILE(0x4c, COL4_PAL, 0, 0), COL_FULL)

    Metatile("COL4_SPIKE_UP",            TILE(0x165, COL4_PAL, 0, 0), TILE(0x165, COL4_PAL, H, 0), TILE(0x175, COL4_PAL, 0, 0), TILE(0x175, COL4_PAL, H, 0), COL_SPIKE_TOP)
    Metatile("COL4_SPIKE_DOWN",          TILE(0x175, COL4_PAL, 0, V), TILE(0x175, COL4_PAL, H, V), TILE(0x165, COL4_PAL, 0, V), TILE(0x165, COL4_PAL, H, V), COL_SPIKE_BOTTOM)
    Metatile("COL4_SPIKE_LEFT",          TILE(0x166, COL4_PAL, 0, 0), TILE(0x167, COL4_PAL, 0, 0), TILE(0x166, COL4_PAL, 0, V), TILE(0x167, COL4_PAL, 0, V), COL_SPIKE_LEFT)
    Metatile("COL4_SPIKE_RIGHT",         TILE(0x167, COL4_PAL, H, 0), TILE(0x166, COL4_PAL, H, 0), TILE(0x167, COL4_PAL, H, V), TILE(0x166, COL4_PAL, H, V), COL_SPIKE_RIGHT)
    Metatile("COL4_SMALL_SPIKE_BOTTOM",  TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x16a, COL4_PAL, 0, 0), TILE(0x16a, COL4_PAL, H, 0), COL_SMALL_SPIKE_BOTTOM) // 0x508
    Metatile("COL4_SMALL_SPIKE_TOP",     TILE(0x16a, COL4_PAL, 0, V), TILE(0x16a, COL4_PAL, H, V), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_SMALL_SPIKE_TOP)
    Metatile("COL4_SMALL_SPIKE_LEFT",    TILE(0x17a, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x17a, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, 0), COL_SMALL_SPIKE_LEFT)
    Metatile("COL4_SMALL_SPIKE_RIGHT",   TILE(0x000, COL4_PAL, 0, 0), TILE(0x17a, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x17a, COL4_PAL, H, V), COL_SMALL_SPIKE_RIGHT)
    Metatile("COL4_MEDIUM_SPIKE_BOTTOM", TILE(0x168, COL4_PAL, 0, 0), TILE(0x168, COL4_PAL, H, 0), TILE(0x178, COL4_PAL, 0, 0), TILE(0x178, COL4_PAL, H, 0), COL_MEDIUM_SPIKE_BOTTOM)
    Metatile("COL4_MEDIUM_SPIKE_TOP",    TILE(0x178, COL4_PAL, 0, V), TILE(0x178, COL4_PAL, H, V), TILE(0x168, COL4_PAL, 0, V), TILE(0x168, COL4_PAL, H, V), COL_MEDIUM_SPIKE_TOP)
    Metatile("COL4_MEDIUM_SPIKE_LEFT",   TILE(0x179, COL4_PAL, 0, 0), TILE(0x169, COL4_PAL, 0, 0), TILE(0x179, COL4_PAL, 0, V), TILE(0x169, COL4_PAL, 0, V), COL_MEDIUM_SPIKE_LEFT)
    Metatile("COL4_MEDIUM_SPIKE_RIGHT",  TILE(0x169, COL4_PAL, H, 0), TILE(0x179, COL4_PAL, H, 0), TILE(0x169, COL4_PAL, H, V), TILE(0x179, COL4_PAL, H, V), COL_MEDIUM_SPIKE_RIGHT)

    Metatile("COL4_SLOPE_45_UP",      TILE(0x00, COL4_PAL, 0, 0), TILE(0x7b, COL4_PAL, 0, 0), TILE(0x7b, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), COL_SLOPE_45_UP) // 0x510
    Metatile("COL4_SLOPE_45_DOWN",    TILE(0x7b, COL4_PAL, H, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, H, 0), TILE(0x7b, COL4_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL4_SLOPE_45_UP_UD",   TILE(0x7b, COL4_PAL, 0, V), TILE(0x3a, COL4_PAL, 0, V), TILE(0x00, COL4_PAL, 0, V), TILE(0x7b, COL4_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL4_SLOPE_45_DOWN_UD", TILE(0x3a, COL4_PAL, H, V), TILE(0x7b, COL4_PAL, H, V), TILE(0x7b, COL4_PAL, H, V), TILE(0x00, COL4_PAL, 0, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL4_22_UP_1",          TILE(0x00, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x7c, COL4_PAL, 0, 0), TILE(0x7d, COL4_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL4_22_UP_2",          TILE(0x7c, COL4_PAL, 0, 0), TILE(0x7d, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("COL4_22_DOWN_1",        TILE(0x7d, COL4_PAL, H, 0), TILE(0x7c, COL4_PAL, H, 0), TILE(0x3a, COL4_PAL, H, 0), TILE(0x3a, COL4_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL4_22_DOWN_2",        TILE(0x00, COL4_PAL, H, 0), TILE(0x00, COL4_PAL, H, 0), TILE(0x7d, COL4_PAL, H, 0), TILE(0x7c, COL4_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL4_22_UP_UD_1",       TILE(0x7c, COL4_PAL, 0, V), TILE(0x7d, COL4_PAL, 0, V), TILE(0x00, COL4_PAL, 0, V), TILE(0x00, COL4_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x518
    Metatile("COL4_22_UP_UD_2",       TILE(0x3a, COL4_PAL, 0, V), TILE(0x3a, COL4_PAL, 0, V), TILE(0x7c, COL4_PAL, 0, V), TILE(0x7d, COL4_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL4_22_DOWN_UD_1",     TILE(0x3a, COL4_PAL, H, V), TILE(0x3a, COL4_PAL, H, V), TILE(0x7d, COL4_PAL, H, V), TILE(0x7c, COL4_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL4_22_DOWN_UD_2",     TILE(0x7d, COL4_PAL, H, V), TILE(0x7c, COL4_PAL, H, V), TILE(0x00, COL4_PAL, H, V), TILE(0x00, COL4_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL4_66_UP_1",          TILE(0x00, COL4_PAL, 0, 0), TILE(0x7f, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x7e, COL4_PAL, 0, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL4_66_UP_2",          TILE(0x7f, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), TILE(0x7e, COL4_PAL, 0, 0), TILE(0x3a, COL4_PAL, 0, 0), COL_SLOPE_66_UP_2)
    Metatile("COL4_66_DOWN_1",        TILE(0x3a, COL4_PAL, H, 0), TILE(0x7f, COL4_PAL, H, 0), TILE(0x3a, COL4_PAL, H, 0), TILE(0x7e, COL4_PAL, H, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL4_66_DOWN_2",        TILE(0x7f, COL4_PAL, H, 0), TILE(0x00, COL4_PAL, H, 0), TILE(0x7e, COL4_PAL, H, 0), TILE(0x00, COL4_PAL, H, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL4_66_UP_UD_1",       TILE(0x00, COL4_PAL, 0, V), TILE(0x7e, COL4_PAL, 0, V), TILE(0x00, COL4_PAL, 0, V), TILE(0x7f, COL4_PAL, 0, V), COL_SLOPE_66_UP_UD_1) // 0x520
    Metatile("COL4_66_UP_UD_2",       TILE(0x7e, COL4_PAL, 0, V), TILE(0x3a, COL4_PAL, 0, V), TILE(0x7f, COL4_PAL, 0, V), TILE(0x3a, COL4_PAL, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL4_66_DOWN_UD_1",     TILE(0x3a, COL4_PAL, H, V), TILE(0x7e, COL4_PAL, H, V), TILE(0x3a, COL4_PAL, H, V), TILE(0x7f, COL4_PAL, H, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL4_66_DOWN_UD_2",     TILE(0x7e, COL4_PAL, H, V), TILE(0x00, COL4_PAL, H, V), TILE(0x7f, COL4_PAL, H, V), TILE(0x00, COL4_PAL, H, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x528
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("BLK_SLOPE_45_UP",      TILE(0x00, 0, 0, 0), TILE(0x7b, 0, 0, 0), TILE(0x7b, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_SLOPE_45_UP) // 0x530
    Metatile("BLK_SLOPE_45_DOWN",    TILE(0x7b, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x3a, 0, H, 0), TILE(0x7b, 0, H, 0), COL_SLOPE_45_DOWN)
    Metatile("BLK_SLOPE_45_UP_UD",   TILE(0x7b, 0, 0, V), TILE(0x3a, 0, 0, V), TILE(0x00, 0, 0, V), TILE(0x7b, 0, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("BLK_SLOPE_45_DOWN_UD", TILE(0x3a, 0, H, V), TILE(0x7b, 0, H, V), TILE(0x7b, 0, H, V), TILE(0x00, 0, 0, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("BLK_22_UP_1",          TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x7c, 0, 0, 0), TILE(0x7d, 0, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("BLK_22_UP_2",          TILE(0x7c, 0, 0, 0), TILE(0x7d, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("BLK_22_DOWN_1",        TILE(0x7d, 0, H, 0), TILE(0x7c, 0, H, 0), TILE(0x3a, 0, H, 0), TILE(0x3a, 0, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("BLK_22_DOWN_2",        TILE(0x00, 0, H, 0), TILE(0x00, 0, H, 0), TILE(0x7d, 0, H, 0), TILE(0x7c, 0, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("BLK_22_UP_UD_1",       TILE(0x7c, 0, 0, V), TILE(0x7d, 0, 0, V), TILE(0x00, 0, 0, V), TILE(0x00, 0, 0, V), COL_SLOPE_22_UP_UD_1) // 0x538
    Metatile("BLK_22_UP_UD_2",       TILE(0x3a, 0, 0, V), TILE(0x3a, 0, 0, V), TILE(0x7c, 0, 0, V), TILE(0x7d, 0, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("BLK_22_DOWN_UD_1",     TILE(0x3a, 0, H, V), TILE(0x3a, 0, H, V), TILE(0x7d, 0, H, V), TILE(0x7c, 0, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("BLK_22_DOWN_UD_2",     TILE(0x7d, 0, H, V), TILE(0x7c, 0, H, V), TILE(0x00, 0, H, V), TILE(0x00, 0, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("BLK_66_UP_1",          TILE(0x00, 0, 0, 0), TILE(0x7f, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x7e, 0, 0, 0), COL_SLOPE_66_UP_1) 
    Metatile("BLK_66_UP_2",          TILE(0x7f, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x7e, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_SLOPE_66_UP_2)
    Metatile("BLK_66_DOWN_1",        TILE(0x3a, 0, H, 0), TILE(0x7f, 0, H, 0), TILE(0x3a, 0, H, 0), TILE(0x7e, 0, H, 0), COL_SLOPE_66_DOWN_1)
    Metatile("BLK_66_DOWN_2",        TILE(0x7f, 0, H, 0), TILE(0x00, 0, H, 0), TILE(0x7e, 0, H, 0), TILE(0x00, 0, H, 0), COL_SLOPE_66_DOWN_2)
    Metatile("BLK_66_UP_UD_1",       TILE(0x00, 0, 0, V), TILE(0x7e, 0, 0, V), TILE(0x00, 0, 0, V), TILE(0x7f, 0, 0, V), COL_SLOPE_66_UP_UD_1) // 0x540
    Metatile("BLK_66_UP_UD_2",       TILE(0x7e, 0, 0, V), TILE(0x3a, 0, 0, V), TILE(0x7f, 0, 0, V), TILE(0x3a, 0, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("BLK_66_DOWN_UD_1",     TILE(0x3a, 0, H, V), TILE(0x7e, 0, H, V), TILE(0x3a, 0, H, V), TILE(0x7f, 0, H, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("BLK_66_DOWN_UD_2",     TILE(0x7e, 0, H, V), TILE(0x00, 0, H, V), TILE(0x7f, 0, H, V), TILE(0x00, 0, H, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x548
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
 
    Metatile("1.7_LINE_V",     TILE(0x160, PLAYER_PAL, 0, 0), TILE(0x160, PLAYER_PAL, H, 0), TILE(0x160, PLAYER_PAL, 0, V), TILE(0x160, PLAYER_PAL, H, V), COL_NONE) // 0x550
    Metatile("1.7_LINE_H",     TILE(0x161, PLAYER_PAL, 0, 0), TILE(0x161, PLAYER_PAL, H, 0), TILE(0x161, PLAYER_PAL, 0, V), TILE(0x161, PLAYER_PAL, H, V), COL_NONE)
    Metatile("1.7_LINE_RGT",   TILE(0x162, PLAYER_PAL, 0, 0), TILE(0x161, PLAYER_PAL, H, 0), TILE(0x162, PLAYER_PAL, 0, V), TILE(0x161, PLAYER_PAL, H, V), COL_NONE)
    Metatile("1.7_LINE_LFT",   TILE(0x161, PLAYER_PAL, 0, 0), TILE(0x162, PLAYER_PAL, H, 0), TILE(0x161, PLAYER_PAL, 0, V), TILE(0x162, PLAYER_PAL, H, V), COL_NONE)
    Metatile("1.7_LINE_DWN",   TILE(0x162, PLAYER_PAL, 0, 0), TILE(0x162, PLAYER_PAL, H, 0), TILE(0x160, PLAYER_PAL, 0, V), TILE(0x160, PLAYER_PAL, H, V), COL_NONE)
    Metatile("1.7_LINE_UP",    TILE(0x160, PLAYER_PAL, 0, 0), TILE(0x160, PLAYER_PAL, H, 0), TILE(0x162, PLAYER_PAL, 0, V), TILE(0x162, PLAYER_PAL, H, V), COL_NONE)
    Metatile("1.7_LINE_3_DWN", TILE(0x161, PLAYER_PAL, 0, 0), TILE(0x161, PLAYER_PAL, H, 0), TILE(0x163, PLAYER_PAL, H, 0), TILE(0x163, PLAYER_PAL, 0, 0), COL_NONE)
    Metatile("1.7_LINE_3_UP",  TILE(0x163, PLAYER_PAL, H, V), TILE(0x163, PLAYER_PAL, 0, V), TILE(0x161, PLAYER_PAL, 0, V), TILE(0x161, PLAYER_PAL, H, V), COL_NONE)
    Metatile("1.7_LINE_3_RGT", TILE(0x160, PLAYER_PAL, 0, 0), TILE(0x163, PLAYER_PAL, 0, V), TILE(0x160, PLAYER_PAL, 0, V), TILE(0x163, PLAYER_PAL, 0, 0), COL_NONE) // 0x558
    Metatile("1.7_LINE_3_LFT", TILE(0x163, PLAYER_PAL, H, V), TILE(0x160, PLAYER_PAL, H, 0), TILE(0x163, PLAYER_PAL, H, 0), TILE(0x160, PLAYER_PAL, H, V), COL_NONE)
    Metatile("1.7_LINE_4",     TILE(0x163, PLAYER_PAL, H, V), TILE(0x163, PLAYER_PAL, 0, V), TILE(0x163, PLAYER_PAL, H, 0), TILE(0x163, PLAYER_PAL, 0, 0), COL_NONE)
    
    Metatile("1.7_HEXAGON_DECO_H",  TILE(0x151, LBG_PAL, 0, 0), TILE(0x151, LBG_PAL, H, 0), TILE(0x151, LBG_PAL, 0, V), TILE(0x151, LBG_PAL, H, V), COL_NONE)
    Metatile("1.7_HEXAGON_DECO_V",  TILE(0x150, LBG_PAL, 0, 0), TILE(0x150, LBG_PAL, H, 0), TILE(0x150, LBG_PAL, 0, V), TILE(0x150, LBG_PAL, H, V), COL_NONE)
    Metatile("1.7_HEXAGON_DECO_BL", TILE(0x152, LBG_PAL, 0, 0), TILE(0x153, LBG_PAL, 0, 0), TILE(0x154, LBG_PAL, 0, 0), TILE(0x155, LBG_PAL, 0, 0), COL_NONE)
    Metatile("1.7_HEXAGON_DECO_BR", TILE(0x153, LBG_PAL, H, 0), TILE(0x152, LBG_PAL, H, 0), TILE(0x155, LBG_PAL, H, 0), TILE(0x154, LBG_PAL, H, 0), COL_NONE)
    Metatile("1.7_HEXAGON_DECO_TL", TILE(0x154, LBG_PAL, 0, V), TILE(0x155, LBG_PAL, 0, V), TILE(0x152, LBG_PAL, 0, V), TILE(0x153, LBG_PAL, 0, V),  COL_NONE)
    Metatile("1.7_HEXAGON_DECO_TR", TILE(0x155, LBG_PAL, H, V), TILE(0x154, LBG_PAL, H, V), TILE(0x153, LBG_PAL, H, V), TILE(0x152, LBG_PAL, H, V),  COL_NONE) // 0x560

    Metatile("1.7_PENTAGON_DECO_BOT",        TILE(0x15b, LBG_PAL, 0, 0), TILE(0x15b, LBG_PAL, H, 0), TILE(0x15c, LBG_PAL, 0, 0), TILE(0x15c, LBG_PAL, H, 0), COL_NONE)
    Metatile("1.7_PENTAGON_DECO_TOP",        TILE(0x15c, LBG_PAL, 0, V), TILE(0x15c, LBG_PAL, H, V), TILE(0x15b, LBG_PAL, 0, V), TILE(0x15b, LBG_PAL, H, V), COL_NONE)
    Metatile("1.7_PENTAGON_DECO_LFT",        TILE(0x15d, LBG_PAL, 0, 0), TILE(0x15e, LBG_PAL, 0, 0), TILE(0x15d, LBG_PAL, 0, V), TILE(0x15e, LBG_PAL, 0, V), COL_NONE)
    Metatile("1.7_PENTAGON_DECO_RGT",        TILE(0x15e, LBG_PAL, H, 0), TILE(0x15d, LBG_PAL, H, 0), TILE(0x15e, LBG_PAL, H, V), TILE(0x15d, LBG_PAL, H, V), COL_NONE)
    Metatile("1.7_PENTAGON_DECO_INS_CRN_TL", TILE(0x158, LBG_PAL, H, 0), TILE(0x157, LBG_PAL, H, 0), TILE(0x15a, LBG_PAL, H, 0), TILE(0x159, LBG_PAL, H, 0), COL_NONE)
    Metatile("1.7_PENTAGON_DECO_INS_CRN_TR", TILE(0x157, LBG_PAL, 0, 0), TILE(0x158, LBG_PAL, 0, 0), TILE(0x159, LBG_PAL, 0, 0), TILE(0x15a, LBG_PAL, 0, 0), COL_NONE)
    Metatile("1.7_PENTAGON_DECO_INS_CRN_BL", TILE(0x15a, LBG_PAL, H, V), TILE(0x159, LBG_PAL, H, V), TILE(0x158, LBG_PAL, H, V), TILE(0x157, LBG_PAL, H, V), COL_NONE)
    Metatile("1.7_PENTAGON_DECO_INS_CRN_BR", TILE(0x159, LBG_PAL, 0, V), TILE(0x15a, LBG_PAL, 0, V), TILE(0x157, LBG_PAL, 0, V), TILE(0x158, LBG_PAL, 0, V), COL_NONE) // 0x568
    Metatile("1.7_PENTAGON_DECO_CRN_BR",     TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x15f, LBG_PAL, H, 0), COL_NONE)
    Metatile("1.7_PENTAGON_DECO_CRN_BL",     TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x15f, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("1.7_PENTAGON_DECO_CRN_TR",     TILE(0x000, LBG_PAL, 0, 0), TILE(0x15f, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("1.7_PENTAGON_DECO_CRN_TL",     TILE(0x15f, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)

    Metatile("1.7_MINI_HEXAGON_V", TILE(0x156, LBG_PAL, 0, 0), TILE(0x156, LBG_PAL, H, 0), TILE(0x156, LBG_PAL, 0, 0), TILE(0x156, LBG_PAL, H, 0), COL_NONE)
    Metatile("1.7_MINI_HEXAGON_H", TILE(0x16b, LBG_PAL, 0, 0), TILE(0x16b, LBG_PAL, 0, 0), TILE(0x16b, LBG_PAL, 0, V), TILE(0x16b, LBG_PAL, 0, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    
    Metatile("1.7_LBG_BRK_DBL_H", TILE(0x046, LBG_PAL, H, V), TILE(0x046, LBG_PAL, 0, V), TILE(0x046, LBG_PAL, H, 0), TILE(0x046, LBG_PAL, 0, 0), COL_NONE) // 0x570
    Metatile("1.7_LBG_BRK_DBL_V", TILE(0x164, LBG_PAL, H, 0), TILE(0x164, LBG_PAL, 0, 0), TILE(0x164, LBG_PAL, H, V), TILE(0x164, LBG_PAL, 0, V), COL_NONE)

    Metatile("1.7_LBG_BRK_SLAB_TOP", TILE(0x046, LBG_PAL, H, V), TILE(0x046, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("1.7_LBG_BRK_SLAB_BOT", TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x046, LBG_PAL, H, 0), TILE(0x046, LBG_PAL, 0, 0), COL_NONE)
    Metatile("1.7_LBG_BRK_SLAB_LFT", TILE(0x164, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x164, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("1.7_LBG_BRK_SLAB_RGT", TILE(0x000, LBG_PAL, 0, 0), TILE(0x164, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x164, LBG_PAL, 0, V), COL_NONE)

    Metatile("1.7_LBG_BRK_CRN_TL", TILE(0x164, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("1.7_LBG_BRK_CRN_TR", TILE(0x000, LBG_PAL, 0, 0), TILE(0x164, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("1.7_LBG_BRK_CRN_BL", TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x164, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE) // 0x578
    Metatile("1.7_LBG_BRK_CRN_BR", TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x164, LBG_PAL, 0, 0), COL_NONE)

    Metatile("1.7_LBG_BRK_SLAB_OFF_LFT", TILE(0x164, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x164, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("1.7_LBG_BRK_SLAB_OFF_RGT", TILE(0x000, LBG_PAL, 0, 0), TILE(0x164, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x164, LBG_PAL, 0, 0), COL_NONE)
    Metatile("1.7_LBG_BRK_SLAB_OFF_TOP", TILE(0x046, LBG_PAL, 0, V), TILE(0x046, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("1.7_LBG_BRK_SLAB_OFF_BOT", TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x046, LBG_PAL, 0, 0), TILE(0x046, LBG_PAL, H, 0), COL_NONE)

    Metatile("1.7_LBG_BRK_STAIRS_TL", TILE(0x046, LBG_PAL, H, V), TILE(0x046, LBG_PAL, 0, V), TILE(0x164, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("1.7_LBG_BRK_STAIRS_TR", TILE(0x046, LBG_PAL, H, V), TILE(0x046, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x164, LBG_PAL, 0, 0), COL_NONE)
    Metatile("1.7_LBG_BRK_STAIRS_BL", TILE(0x164, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x046, LBG_PAL, H, 0), TILE(0x046, LBG_PAL, 0, 0), COL_NONE) // 0x580
    Metatile("1.7_LBG_BRK_STAIRS_BR", TILE(0x000, LBG_PAL, 0, 0), TILE(0x164, LBG_PAL, 0, V), TILE(0x046, LBG_PAL, H, 0), TILE(0x046, LBG_PAL, 0, 0), COL_NONE)

    Metatile("1.7_LBG_NRM_BRK_STAIRS_TL", TILE(0x046, 0, H, V),       TILE(0x046, LBG_PAL, 0, V), TILE(0x164, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("1.7_LBG_NRM_BRK_STAIRS_TR", TILE(0x046, LBG_PAL, H, V), TILE(0x046, 0, 0, V),       TILE(0x000, LBG_PAL, 0, 0), TILE(0x164, LBG_PAL, 0, V), COL_NONE)
    Metatile("1.7_LBG_NRM_BRK_STAIRS_BL", TILE(0x164, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x046, 0, H, 0),       TILE(0x046, LBG_PAL, 0, 0), COL_NONE)
    Metatile("1.7_LBG_NRM_BRK_STAIRS_BR", TILE(0x000, LBG_PAL, 0, 0), TILE(0x164, LBG_PAL, 0, 0), TILE(0x046, LBG_PAL, H, 0), TILE(0x046, 0, 0, 0),       COL_NONE)

    Metatile("1.7_WAVY_LINE_H",      TILE(0x10f, PLAYER_PAL, H, V), TILE(0x10f, PLAYER_PAL, 0, V), TILE(0x10f, PLAYER_PAL, 0, 0), TILE(0x10f, PLAYER_PAL, H, 0), COL_NONE)
    Metatile("1.7_WAVY_LINE_H_F",    TILE(0x10f, PLAYER_PAL, 0, V), TILE(0x10f, PLAYER_PAL, H, V), TILE(0x10f, PLAYER_PAL, H, 0), TILE(0x10f, PLAYER_PAL, 0, 0), COL_NONE)
    Metatile("1.7_WAVY_LINE_V",      TILE(0x10e, PLAYER_PAL, H, V), TILE(0x10e, PLAYER_PAL, 0, 0), TILE(0x10e, PLAYER_PAL, H, 0), TILE(0x10e, PLAYER_PAL, 0, V), COL_NONE) // 0x588
    Metatile("1.7_WAVY_LINE_V_F",    TILE(0x10e, PLAYER_PAL, H, 0), TILE(0x10e, PLAYER_PAL, 0, V), TILE(0x10e, PLAYER_PAL, H, V), TILE(0x10e, PLAYER_PAL, 0, 0), COL_NONE)
    Metatile("1.7_WAVY_LINE_CRN_BR", TILE(0x11f, PLAYER_PAL, H, 0), TILE(0x10f, PLAYER_PAL, 0, V), TILE(0x10e, PLAYER_PAL, H, 0), TILE(0x11e, PLAYER_PAL, H, 0), COL_NONE)
    Metatile("1.7_WAVY_LINE_CRN_BL", TILE(0x10f, PLAYER_PAL, H, V), TILE(0x11f, PLAYER_PAL, 0, 0), TILE(0x11e, PLAYER_PAL, 0, 0), TILE(0x10e, PLAYER_PAL, 0, 0), COL_NONE)
    Metatile("1.7_WAVY_LINE_CRN_TR", TILE(0x10e, PLAYER_PAL, H, V), TILE(0x11e, PLAYER_PAL, H, V), TILE(0x11f, PLAYER_PAL, H, V), TILE(0x10f, PLAYER_PAL, 0, 0), COL_NONE)
    Metatile("1.7_WAVY_LINE_CRN_TL", TILE(0x11e, PLAYER_PAL, 0, V), TILE(0x10e, PLAYER_PAL, 0, V), TILE(0x10f, PLAYER_PAL, H, 0), TILE(0x11f, PLAYER_PAL, 0, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("GROUND_0", TILE(0x380, 1, 0, 0), TILE(0x381, 1, 0, 0), TILE(0x390, 1, 0, 0), TILE(0x391, 1, 0, 0), COL_FLOOR_CEIL) // 0x590
    Metatile("GROUND_1", TILE(0x382, 1, 0, 0), TILE(0x383, 1, 0, 0), TILE(0x392, 1, 0, 0), TILE(0x393, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("GROUND_2", TILE(0x384, 1, 0, 0), TILE(0x385, 1, 0, 0), TILE(0x394, 1, 0, 0), TILE(0x395, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("GROUND_3", TILE(0x386, 1, 0, 0), TILE(0x387, 1, 0, 0), TILE(0x396, 1, 0, 0), TILE(0x397, 1, 0, 0), COL_FLOOR_CEIL)
    
    Metatile("CEILING_0", TILE(0x3f0, 1, 0, V), TILE(0x3f1, 1, 0, V), TILE(0x3e0, 1, 0, V), TILE(0x3e1, 1, 0, V),  COL_FLOOR_CEIL)
    Metatile("CEILING_1", TILE(0x3f2, 1, 0, V), TILE(0x3f3, 1, 0, V), TILE(0x3e2, 1, 0, V), TILE(0x3e3, 1, 0, V),  COL_FLOOR_CEIL)
    Metatile("CEILING_2", TILE(0x3f4, 1, 0, V), TILE(0x3f5, 1, 0, V), TILE(0x3e4, 1, 0, V), TILE(0x3e5, 1, 0, V),  COL_FLOOR_CEIL)
    Metatile("CEILING_3", TILE(0x3f6, 1, 0, V), TILE(0x3f7, 1, 0, V), TILE(0x3e6, 1, 0, V), TILE(0x3e7, 1, 0, V),  COL_FLOOR_CEIL)

    Metatile("1.7_LINE_CRN_BR", TILE(0x162, PLAYER_PAL, 0, 0), TILE(0x161, PLAYER_PAL, H, 0), TILE(0x160, PLAYER_PAL, 0, V), TILE(0x163, PLAYER_PAL, 0, 0), COL_NONE) // 0x598
    Metatile("1.7_LINE_CRN_BL", TILE(0x161, PLAYER_PAL, 0, 0), TILE(0x162, PLAYER_PAL, H, 0), TILE(0x163, PLAYER_PAL, H, 0), TILE(0x160, PLAYER_PAL, H, V), COL_NONE)
    Metatile("1.7_LINE_CRN_TR", TILE(0x160, PLAYER_PAL, 0, 0), TILE(0x163, PLAYER_PAL, 0, V), TILE(0x162, PLAYER_PAL, 0, V), TILE(0x161, PLAYER_PAL, H, V), COL_NONE)
    Metatile("1.7_LINE_CRN_TL", TILE(0x163, PLAYER_PAL, H, V), TILE(0x160, PLAYER_PAL, H, 0), TILE(0x161, PLAYER_PAL, 0, V), TILE(0x162, PLAYER_PAL, H, V), COL_NONE)
    
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    
    Metatile("GROUND_4", TILE(0x3a0, 1, 0, 0), TILE(0x3a1, 1, 0, 0), TILE(0x3b0, 1, 0, 0), TILE(0x3b1, 1, 0, 0),  COL_FLOOR_CEIL) // 0x5a0
    Metatile("GROUND_5", TILE(0x3a2, 1, 0, 0), TILE(0x3a3, 1, 0, 0), TILE(0x3b2, 1, 0, 0), TILE(0x3b3, 1, 0, 0),  COL_FLOOR_CEIL)
    Metatile("GROUND_6", TILE(0x3a4, 1, 0, 0), TILE(0x3a5, 1, 0, 0), TILE(0x3b4, 1, 0, 0), TILE(0x3b5, 1, 0, 0),  COL_FLOOR_CEIL)
    Metatile("GROUND_7", TILE(0x3a6, 1, 0, 0), TILE(0x3a7, 1, 0, 0), TILE(0x3b6, 1, 0, 0), TILE(0x3b7, 1, 0, 0),  COL_FLOOR_CEIL)
    
    Metatile("CEILING_4", TILE(0x3d0, 1, 0, V), TILE(0x3d1, 1, 0, V),  TILE(0x3c0, 1, 0, V), TILE(0x3c1, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_5", TILE(0x3d2, 1, 0, V), TILE(0x3d3, 1, 0, V),  TILE(0x3c2, 1, 0, V), TILE(0x3c3, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_6", TILE(0x3d4, 1, 0, V), TILE(0x3d5, 1, 0, V),  TILE(0x3c4, 1, 0, V), TILE(0x3c5, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_7", TILE(0x3d6, 1, 0, V), TILE(0x3d7, 1, 0, V),  TILE(0x3c6, 1, 0, V), TILE(0x3c7, 1, 0, V), COL_FLOOR_CEIL)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x5a8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("GROUND_8", TILE(0x3c0, 1, 0, 0), TILE(0x3c1, 1, 0, 0), TILE(0x3d0, 1, 0, 0), TILE(0x3d1, 1, 0, 0),  COL_FLOOR_CEIL) // 0x5b0
    Metatile("GROUND_9", TILE(0x3c2, 1, 0, 0), TILE(0x3c3, 1, 0, 0), TILE(0x3d2, 1, 0, 0), TILE(0x3d3, 1, 0, 0),  COL_FLOOR_CEIL)
    Metatile("GROUND_A", TILE(0x3c4, 1, 0, 0), TILE(0x3c5, 1, 0, 0), TILE(0x3d4, 1, 0, 0), TILE(0x3d5, 1, 0, 0),  COL_FLOOR_CEIL)
    Metatile("GROUND_B", TILE(0x3c6, 1, 0, 0), TILE(0x3c7, 1, 0, 0), TILE(0x3d6, 1, 0, 0), TILE(0x3d7, 1, 0, 0),  COL_FLOOR_CEIL)
    
    Metatile("CEILING_8", TILE(0x3b0, 1, 0, V), TILE(0x3b1, 1, 0, V), TILE(0x3a0, 1, 0, V), TILE(0x3a1, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_9", TILE(0x3b2, 1, 0, V), TILE(0x3b3, 1, 0, V), TILE(0x3a2, 1, 0, V), TILE(0x3a3, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_A", TILE(0x3b4, 1, 0, V), TILE(0x3b5, 1, 0, V), TILE(0x3a4, 1, 0, V), TILE(0x3a5, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_B", TILE(0x3b6, 1, 0, V), TILE(0x3b7, 1, 0, V), TILE(0x3a6, 1, 0, V), TILE(0x3a7, 1, 0, V), COL_FLOOR_CEIL)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x59b8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("GROUND_C", TILE(0x3e0, 1, 0, 0), TILE(0x3e1, 1, 0, 0), TILE(0x3f0, 1, 0, 0), TILE(0x3f1, 1, 0, 0),  COL_FLOOR_CEIL) // 0x5c0
    Metatile("GROUND_D", TILE(0x3e2, 1, 0, 0), TILE(0x3e3, 1, 0, 0), TILE(0x3f2, 1, 0, 0), TILE(0x3f3, 1, 0, 0),  COL_FLOOR_CEIL)
    Metatile("GROUND_E", TILE(0x3e4, 1, 0, 0), TILE(0x3e5, 1, 0, 0), TILE(0x3f4, 1, 0, 0), TILE(0x3f5, 1, 0, 0),  COL_FLOOR_CEIL)
    Metatile("GROUND_F", TILE(0x3e6, 1, 0, 0), TILE(0x3e7, 1, 0, 0), TILE(0x3f6, 1, 0, 0), TILE(0x3f7, 1, 0, 0),  COL_FLOOR_CEIL)
    
    Metatile("CEILING_C", TILE(0x390, 1, 0, V), TILE(0x391, 1, 0, V), TILE(0x380, 1, 0, V), TILE(0x381, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_D", TILE(0x392, 1, 0, V), TILE(0x393, 1, 0, V), TILE(0x382, 1, 0, V), TILE(0x383, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_E", TILE(0x394, 1, 0, V), TILE(0x395, 1, 0, V), TILE(0x384, 1, 0, V), TILE(0x385, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_F", TILE(0x396, 1, 0, V), TILE(0x397, 1, 0, V), TILE(0x386, 1, 0, V), TILE(0x387, 1, 0, V), COL_FLOOR_CEIL)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x5c8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    // SHIT TON OF SLOPES INCOMING

    Metatile("CHKRED_SLOPE_45_UP",      TILE(0x000, 0, 0, 0), TILE(0x1a2, 0, 0, 0), TILE(0x1b2, 0, 0, 0), TILE(0x007, 0, 0, 0), COL_SLOPE_45_UP) // 0x5d0
    Metatile("CHKRED_SLOPE_45_DOWN",    TILE(0x1a2, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x007, 0, H, 0), TILE(0x1b2, 0, H, 0), COL_SLOPE_45_DOWN)
    Metatile("CHKRED_SLOPE_45_UP_UD",   TILE(0x1b2, 0, 0, V), TILE(0x007, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x1a2, 0, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("CHKRED_SLOPE_45_DOWN_UD", TILE(0x007, 0, H, V), TILE(0x1b2, 0, H, V), TILE(0x1a2, 0, H, V), TILE(0x000, 0, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("CHKRED_22_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1b3, 0, 0, 0), TILE(0x1b4, 0, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("CHKRED_22_UP_2",          TILE(0x1a3, 0, 0, 0), TILE(0x1a4, 0, 0, 0), TILE(0x003, 0, 0, 0), TILE(0x003, 0, H, 0), COL_SLOPE_22_UP_2)
    Metatile("CHKRED_22_DOWN_1",        TILE(0x1a4, 0, H, 0), TILE(0x1a3, 0, H, 0), TILE(0x003, 0, 0, 0), TILE(0x003, 0, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("CHKRED_22_DOWN_2",        TILE(0x000, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x1b4, 0, H, 0), TILE(0x1b3, 0, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("CHKRED_22_UP_UD_1",       TILE(0x1b3, 0, 0, V), TILE(0x1b4, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x000, 0, 0, V), COL_SLOPE_22_UP_UD_1) // 0x5d8
    Metatile("CHKRED_22_UP_UD_2",       TILE(0x003, 0, 0, V), TILE(0x003, 0, H, V), TILE(0x1a3, 0, 0, V), TILE(0x1a4, 0, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("CHKRED_22_DOWN_UD_1",     TILE(0x003, 0, 0, V), TILE(0x003, 0, H, V), TILE(0x1a4, 0, H, V), TILE(0x1a3, 0, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("CHKRED_22_DOWN_UD_2",     TILE(0x1b4, 0, H, V), TILE(0x1b3, 0, H, V), TILE(0x000, 0, H, V), TILE(0x000, 0, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("CHKRED_66_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x1a6, 0, H, 0), TILE(0x000, 0, 0, 0), TILE(0x1b6, 0, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("CHKRED_66_UP_2",          TILE(0x1a5, 0, H, 0), TILE(0x005, 0, 0, 0), TILE(0x1b5, 0, H, 0), TILE(0x005, 0, 0, V), COL_SLOPE_66_UP_2)
    Metatile("CHKRED_66_DOWN_1",        TILE(0x005, 0, H, 0), TILE(0x1a5, 0, 0, 0), TILE(0x005, 0, H, V), TILE(0x1b5, 0, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("CHKRED_66_DOWN_2",        TILE(0x1a6, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1b6, 0, 0, 0), TILE(0x000, 0, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("CHKRED_66_UP_UD_1",       TILE(0x000, 0, 0, 0), TILE(0x1b6, 0, H, V), TILE(0x000, 0, 0, 0), TILE(0x1a6, 0, H, V), COL_SLOPE_66_UP_UD_1) // 0x5e0
    Metatile("CHKRED_66_UP_UD_2",       TILE(0x1b5, 0, H, V), TILE(0x005, 0, 0, 0), TILE(0x1a5, 0, H, V), TILE(0x005, 0, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("CHKRED_66_DOWN_UD_1",     TILE(0x005, 0, H, 0), TILE(0x1b5, 0, 0, V), TILE(0x005, 0, H, V), TILE(0x1a5, 0, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("CHKRED_66_DOWN_UD_2",     TILE(0x1b6, 0, 0, V), TILE(0x000, 0, 0, 0), TILE(0x1a6, 0, 0, V), TILE(0x000, 0, 0, 0), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x5e8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("CHKRED_NO_OUT_SLOPE_45_UP",      TILE(0x000, 0, 0, 0), TILE(0x1c0, 0, 0, 0), TILE(0x1d0, 0, 0, 0), TILE(0x007, 0, 0, 0), COL_NONE) // 0x5f0
    Metatile("CHKRED_NO_OUT_SLOPE_45_DOWN",    TILE(0x1c0, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x007, 0, H, 0), TILE(0x1d0, 0, H, 0), COL_NONE)
    Metatile("CHKRED_NO_OUT_SLOPE_45_UP_UD",   TILE(0x1d0, 0, 0, V), TILE(0x007, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x1c0, 0, 0, V), COL_NONE)
    Metatile("CHKRED_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x007, 0, H, V), TILE(0x1d0, 0, H, V), TILE(0x1c0, 0, H, V), TILE(0x000, 0, H, V), COL_NONE) 
    Metatile("CHKRED_NO_OUT_22_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1b0, 0, 0, 0), TILE(0x1b1, 0, 0, 0), COL_NONE)
    Metatile("CHKRED_NO_OUT_22_UP_2",          TILE(0x1a0, 0, 0, 0), TILE(0x1a1, 0, 0, 0), TILE(0x003, 0, 0, 0), TILE(0x003, 0, H, 0), COL_NONE)
    Metatile("CHKRED_NO_OUT_22_DOWN_1",        TILE(0x1a1, 0, H, 0), TILE(0x1a0, 0, H, 0), TILE(0x003, 0, 0, 0), TILE(0x003, 0, H, 0), COL_NONE)
    Metatile("CHKRED_NO_OUT_22_DOWN_2",        TILE(0x000, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x1b1, 0, H, 0), TILE(0x1b0, 0, H, 0), COL_NONE)
    Metatile("CHKRED_NO_OUT_22_UP_UD_1",       TILE(0x1b0, 0, 0, V), TILE(0x1b1, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x000, 0, 0, V), COL_NONE) // 0x5f8
    Metatile("CHKRED_NO_OUT_22_UP_UD_2",       TILE(0x003, 0, 0, V), TILE(0x003, 0, H, V), TILE(0x1a0, 0, 0, V), TILE(0x1a1, 0, 0, V), COL_NONE)
    Metatile("CHKRED_NO_OUT_22_DOWN_UD_1",     TILE(0x003, 0, 0, V), TILE(0x003, 0, H, V), TILE(0x1a1, 0, H, V), TILE(0x1a0, 0, H, V), COL_NONE)
    Metatile("CHKRED_NO_OUT_22_DOWN_UD_2",     TILE(0x1b1, 0, H, V), TILE(0x1b0, 0, H, V), TILE(0x000, 0, H, V), TILE(0x000, 0, H, V), COL_NONE)
    Metatile("CHKRED_NO_OUT_66_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x1c1, 0, H, 0), TILE(0x000, 0, 0, 0), TILE(0x1d1, 0, H, 0), COL_NONE) 
    Metatile("CHKRED_NO_OUT_66_UP_2",          TILE(0x1c2, 0, H, 0), TILE(0x005, 0, 0, 0), TILE(0x1d2, 0, H, 0), TILE(0x005, 0, 0, V), COL_NONE)
    Metatile("CHKRED_NO_OUT_66_DOWN_1",        TILE(0x005, 0, H, 0), TILE(0x1c2, 0, 0, 0), TILE(0x005, 0, H, V), TILE(0x1d2, 0, 0, 0), COL_NONE)
    Metatile("CHKRED_NO_OUT_66_DOWN_2",        TILE(0x1c1, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1d1, 0, 0, 0), TILE(0x000, 0, 0, 0), COL_NONE)
    Metatile("CHKRED_NO_OUT_66_UP_UD_1",       TILE(0x000, 0, 0, 0), TILE(0x1d1, 0, H, V), TILE(0x000, 0, 0, 0), TILE(0x1c1, 0, H, V), COL_NONE) // 0x600
    Metatile("CHKRED_NO_OUT_66_UP_UD_2",       TILE(0x1d2, 0, H, V), TILE(0x005, 0, 0, 0), TILE(0x1c2, 0, H, V), TILE(0x005, 0, 0, V), COL_NONE)
    Metatile("CHKRED_NO_OUT_66_DOWN_UD_1",     TILE(0x005, 0, H, 0), TILE(0x1d2, 0, 0, V), TILE(0x005, 0, H, V), TILE(0x1c2, 0, 0, V), COL_NONE)
    Metatile("CHKRED_NO_OUT_66_DOWN_UD_2",     TILE(0x1d1, 0, 0, V), TILE(0x000, 0, 0, 0), TILE(0x1c1, 0, 0, V), TILE(0x000, 0, 0, 0), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x608
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("X_SLOPE_45_UP",      TILE(0x000, 0, 0, 0), TILE(0x183, 0, 0, 0), TILE(0x182, 0, 0, 0), TILE(0x01a, 0, 0, 0), COL_SLOPE_45_UP) // 0x610
    Metatile("X_SLOPE_45_DOWN",    TILE(0x183, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x01a, 0, H, 0), TILE(0x182, 0, H, 0), COL_SLOPE_45_DOWN)
    Metatile("X_SLOPE_45_UP_UD",   TILE(0x182, 0, 0, V), TILE(0x01a, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x183, 0, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("X_SLOPE_45_DOWN_UD", TILE(0x01a, 0, H, V), TILE(0x182, 0, H, V), TILE(0x183, 0, H, V), TILE(0x000, 0, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("X_22_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x170, 0, 0, 0), TILE(0x171, 0, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("X_22_UP_2",          TILE(0x172, 0, 0, 0), TILE(0x173, 0, 0, 0), TILE(0x019, 0, 0, 0), TILE(0x01a, 0, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("X_22_DOWN_1",        TILE(0x173, 0, H, 0), TILE(0x172, 0, H, 0), TILE(0x01a, 0, H, 0), TILE(0x019, 0, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("X_22_DOWN_2",        TILE(0x000, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x171, 0, H, 0), TILE(0x170, 0, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("X_22_UP_UD_1",       TILE(0x170, 0, 0, V), TILE(0x171, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x000, 0, 0, V), COL_SLOPE_22_UP_UD_1) // 0x618
    Metatile("X_22_UP_UD_2",       TILE(0x019, 0, 0, V), TILE(0x01a, 0, 0, V), TILE(0x172, 0, 0, V), TILE(0x173, 0, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("X_22_DOWN_UD_1",     TILE(0x01a, 0, H, V), TILE(0x019, 0, H, V), TILE(0x173, 0, H, V), TILE(0x172, 0, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("X_22_DOWN_UD_2",     TILE(0x171, 0, H, V), TILE(0x170, 0, H, V), TILE(0x000, 0, H, V), TILE(0x000, 0, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("X_66_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x181, 0, H, 0), TILE(0x000, 0, 0, 0), TILE(0x191, 0, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("X_66_UP_2",          TILE(0x180, 0, H, 0), TILE(0x01c, 0, 0, 0), TILE(0x190, 0, H, 0), TILE(0x01a, 0, 0, 0), COL_SLOPE_66_UP_2)
    Metatile("X_66_DOWN_1",        TILE(0x01c, 0, H, 0), TILE(0x180, 0, 0, 0), TILE(0x01a, 0, H, 0), TILE(0x190, 0, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("X_66_DOWN_2",        TILE(0x181, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x191, 0, 0, 0), TILE(0x000, 0, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("X_66_UP_UD_1",       TILE(0x000, 0, 0, V), TILE(0x191, 0, H, V), TILE(0x000, 0, 0, V), TILE(0x181, 0, H, V), COL_SLOPE_66_UP_UD_1) // 0x620
    Metatile("X_66_UP_UD_2",       TILE(0x190, 0, H, V), TILE(0x01a, 0, 0, V), TILE(0x180, 0, H, V), TILE(0x01c, 0, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("X_66_DOWN_UD_1",     TILE(0x01a, 0, H, V), TILE(0x190, 0, 0, V), TILE(0x01c, 0, H, V), TILE(0x180, 0, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("X_66_DOWN_UD_2",     TILE(0x191, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x181, 0, 0, V), TILE(0x000, 0, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x628
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("X_NO_OUT_SLOPE_45_UP",      TILE(0x000, 0, 0, 0), TILE(0x18f, 0, 0, 0), TILE(0x18e, 0, 0, 0), TILE(0x01a, 0, 0, 0), COL_NONE) // 0x630
    Metatile("X_NO_OUT_SLOPE_45_DOWN",    TILE(0x18f, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x01a, 0, H, 0), TILE(0x18e, 0, H, 0), COL_NONE)
    Metatile("X_NO_OUT_SLOPE_45_UP_UD",   TILE(0x18e, 0, 0, V), TILE(0x01a, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x18f, 0, 0, V), COL_NONE)
    Metatile("X_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x01a, 0, H, V), TILE(0x18e, 0, H, V), TILE(0x18f, 0, H, V), TILE(0x000, 0, H, V), COL_NONE) 
    Metatile("X_NO_OUT_22_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x17c, 0, 0, 0), TILE(0x17d, 0, 0, 0), COL_NONE)
    Metatile("X_NO_OUT_22_UP_2",          TILE(0x17e, 0, 0, 0), TILE(0x17f, 0, 0, 0), TILE(0x019, 0, 0, 0), TILE(0x01a, 0, 0, 0), COL_NONE)
    Metatile("X_NO_OUT_22_DOWN_1",        TILE(0x17f, 0, H, 0), TILE(0x17e, 0, H, 0), TILE(0x01a, 0, H, 0), TILE(0x019, 0, H, 0), COL_NONE)
    Metatile("X_NO_OUT_22_DOWN_2",        TILE(0x000, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x17d, 0, H, 0), TILE(0x17c, 0, H, 0), COL_NONE)
    Metatile("X_NO_OUT_22_UP_UD_1",       TILE(0x17c, 0, 0, V), TILE(0x17d, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x000, 0, 0, V), COL_NONE) // 0x638
    Metatile("X_NO_OUT_22_UP_UD_2",       TILE(0x019, 0, 0, V), TILE(0x01a, 0, 0, V), TILE(0x17e, 0, 0, V), TILE(0x17f, 0, 0, V), COL_NONE)
    Metatile("X_NO_OUT_22_DOWN_UD_1",     TILE(0x01a, 0, H, V), TILE(0x019, 0, H, V), TILE(0x17f, 0, H, V), TILE(0x17e, 0, H, V), COL_NONE)
    Metatile("X_NO_OUT_22_DOWN_UD_2",     TILE(0x17d, 0, H, V), TILE(0x17c, 0, H, V), TILE(0x000, 0, H, V), TILE(0x000, 0, H, V), COL_NONE)
    Metatile("X_NO_OUT_66_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x18d, 0, H, 0), TILE(0x000, 0, 0, 0), TILE(0x19d, 0, H, 0), COL_NONE) 
    Metatile("X_NO_OUT_66_UP_2",          TILE(0x18c, 0, H, 0), TILE(0x01c, 0, 0, 0), TILE(0x19c, 0, H, 0), TILE(0x01a, 0, 0, 0), COL_NONE)
    Metatile("X_NO_OUT_66_DOWN_1",        TILE(0x01c, 0, H, 0), TILE(0x18c, 0, 0, 0), TILE(0x01a, 0, H, 0), TILE(0x19c, 0, 0, 0), COL_NONE)
    Metatile("X_NO_OUT_66_DOWN_2",        TILE(0x18d, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x19d, 0, 0, 0), TILE(0x000, 0, 0, 0), COL_NONE)
    Metatile("X_NO_OUT_66_UP_UD_1",       TILE(0x000, 0, 0, V), TILE(0x19d, 0, H, V), TILE(0x000, 0, 0, V), TILE(0x18d, 0, H, V), COL_NONE) // 0x640
    Metatile("X_NO_OUT_66_UP_UD_2",       TILE(0x19c, 0, H, V), TILE(0x01a, 0, 0, V), TILE(0x18c, 0, H, V), TILE(0x01c, 0, 0, V), COL_NONE)
    Metatile("X_NO_OUT_66_DOWN_UD_1",     TILE(0x01a, 0, H, V), TILE(0x19c, 0, 0, V), TILE(0x01c, 0, H, V), TILE(0x18c, 0, 0, V), COL_NONE)
    Metatile("X_NO_OUT_66_DOWN_UD_2",     TILE(0x19d, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x18d, 0, 0, V), TILE(0x000, 0, 0, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x648
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    
    Metatile("+_SLOPE_45_UP",      TILE(0x000, 0, 0, 0), TILE(0x177, 0, 0, 0), TILE(0x176, 0, 0, 0), TILE(0x031, 0, 0, 0), COL_SLOPE_45_UP) // 0x650
    Metatile("+_SLOPE_45_DOWN",    TILE(0x177, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x031, 0, H, 0), TILE(0x176, 0, H, 0), COL_SLOPE_45_DOWN)
    Metatile("+_SLOPE_45_UP_UD",   TILE(0x176, 0, 0, V), TILE(0x031, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x177, 0, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("+_SLOPE_45_DOWN_UD", TILE(0x031, 0, H, V), TILE(0x176, 0, H, V), TILE(0x177, 0, H, V), TILE(0x000, 0, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("+_22_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x184, 0, 0, 0), TILE(0x185, 0, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("+_22_UP_2",          TILE(0x186, 0, 0, 0), TILE(0x187, 0, 0, 0), TILE(0x030, 0, 0, 0), TILE(0x031, 0, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("+_22_DOWN_1",        TILE(0x187, 0, H, 0), TILE(0x186, 0, H, 0), TILE(0x031, 0, H, 0), TILE(0x030, 0, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("+_22_DOWN_2",        TILE(0x000, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x185, 0, H, 0), TILE(0x184, 0, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("+_22_UP_UD_1",       TILE(0x184, 0, 0, V), TILE(0x185, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x000, 0, 0, V), COL_SLOPE_22_UP_UD_1) // 0x658
    Metatile("+_22_UP_UD_2",       TILE(0x030, 0, 0, V), TILE(0x031, 0, 0, V), TILE(0x186, 0, 0, V), TILE(0x187, 0, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("+_22_DOWN_UD_1",     TILE(0x031, 0, H, V), TILE(0x030, 0, H, V), TILE(0x187, 0, H, V), TILE(0x186, 0, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("+_22_DOWN_UD_2",     TILE(0x185, 0, H, V), TILE(0x184, 0, H, V), TILE(0x000, 0, H, V), TILE(0x000, 0, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("+_66_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x188, 0, H, 0), TILE(0x000, 0, 0, 0), TILE(0x198, 0, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("+_66_UP_2",          TILE(0x189, 0, H, 0), TILE(0x035, 0, H, 0), TILE(0x199, 0, H, 0), TILE(0x030, 0, H, 0), COL_SLOPE_66_UP_2)
    Metatile("+_66_DOWN_1",        TILE(0x035, 0, 0, 0), TILE(0x189, 0, 0, 0), TILE(0x030, 0, 0, 0), TILE(0x199, 0, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("+_66_DOWN_2",        TILE(0x188, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x198, 0, 0, 0), TILE(0x000, 0, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("+_66_UP_UD_1",       TILE(0x000, 0, 0, V), TILE(0x198, 0, H, V), TILE(0x000, 0, 0, V), TILE(0x188, 0, H, V), COL_SLOPE_66_UP_UD_1) // 0x660
    Metatile("+_66_UP_UD_2",       TILE(0x199, 0, H, V), TILE(0x030, 0, H, V), TILE(0x189, 0, H, V), TILE(0x035, 0, H, V), COL_SLOPE_66_UP_UD_2)
    Metatile("+_66_DOWN_UD_1",     TILE(0x030, 0, 0, V), TILE(0x199, 0, 0, V), TILE(0x035, 0, 0, V), TILE(0x189, 0, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("+_66_DOWN_UD_2",     TILE(0x198, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x188, 0, 0, V), TILE(0x000, 0, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x668
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("+_NO_OUT_SLOPE_45_UP",      TILE(0x000, 0, 0, 0), TILE(0x193, 0, 0, 0), TILE(0x192, 0, 0, 0), TILE(0x031, 0, 0, 0), COL_NONE) // 0x670
    Metatile("+_NO_OUT_SLOPE_45_DOWN",    TILE(0x193, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x031, 0, H, 0), TILE(0x192, 0, H, 0), COL_NONE)
    Metatile("+_NO_OUT_SLOPE_45_UP_UD",   TILE(0x192, 0, 0, V), TILE(0x031, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x193, 0, 0, V), COL_NONE)
    Metatile("+_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x031, 0, H, V), TILE(0x192, 0, H, V), TILE(0x193, 0, H, V), TILE(0x000, 0, H, V), COL_NONE) 
    Metatile("+_NO_OUT_22_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x194, 0, 0, 0), TILE(0x195, 0, 0, 0), COL_NONE)
    Metatile("+_NO_OUT_22_UP_2",          TILE(0x196, 0, 0, 0), TILE(0x197, 0, 0, 0), TILE(0x030, 0, 0, 0), TILE(0x031, 0, 0, 0), COL_NONE)
    Metatile("+_NO_OUT_22_DOWN_1",        TILE(0x197, 0, H, 0), TILE(0x196, 0, H, 0), TILE(0x031, 0, H, 0), TILE(0x030, 0, H, 0), COL_NONE)
    Metatile("+_NO_OUT_22_DOWN_2",        TILE(0x000, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x195, 0, H, 0), TILE(0x194, 0, H, 0), COL_NONE)
    Metatile("+_NO_OUT_22_UP_UD_1",       TILE(0x194, 0, 0, V), TILE(0x195, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x000, 0, 0, V), COL_NONE) // 0x678
    Metatile("+_NO_OUT_22_UP_UD_2",       TILE(0x030, 0, 0, V), TILE(0x031, 0, 0, V), TILE(0x196, 0, 0, V), TILE(0x197, 0, 0, V), COL_NONE)
    Metatile("+_NO_OUT_22_DOWN_UD_1",     TILE(0x031, 0, H, V), TILE(0x030, 0, H, V), TILE(0x197, 0, H, V), TILE(0x196, 0, H, V), COL_NONE)
    Metatile("+_NO_OUT_22_DOWN_UD_2",     TILE(0x195, 0, H, V), TILE(0x194, 0, H, V), TILE(0x000, 0, H, V), TILE(0x000, 0, H, V), COL_NONE)
    Metatile("+_NO_OUT_66_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x18a, 0, H, 0), TILE(0x000, 0, 0, 0), TILE(0x19a, 0, H, 0), COL_NONE) 
    Metatile("+_NO_OUT_66_UP_2",          TILE(0x18b, 0, H, 0), TILE(0x035, 0, H, 0), TILE(0x19b, 0, H, 0), TILE(0x030, 0, H, 0), COL_NONE)
    Metatile("+_NO_OUT_66_DOWN_1",        TILE(0x035, 0, 0, 0), TILE(0x18b, 0, 0, 0), TILE(0x030, 0, 0, 0), TILE(0x19b, 0, 0, 0), COL_NONE)
    Metatile("+_NO_OUT_66_DOWN_2",        TILE(0x18a, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x19a, 0, 0, 0), TILE(0x000, 0, 0, 0), COL_NONE)
    Metatile("+_NO_OUT_66_UP_UD_1",       TILE(0x000, 0, 0, V), TILE(0x19a, 0, H, V), TILE(0x000, 0, 0, V), TILE(0x18a, 0, H, V), COL_NONE) // 0x680
    Metatile("+_NO_OUT_66_UP_UD_2",       TILE(0x19b, 0, H, V), TILE(0x030, 0, H, V), TILE(0x18b, 0, H, V), TILE(0x035, 0, H, V), COL_NONE)
    Metatile("+_NO_OUT_66_DOWN_UD_1",     TILE(0x030, 0, 0, V), TILE(0x19b, 0, 0, V), TILE(0x035, 0, 0, V), TILE(0x18b, 0, 0, V), COL_NONE)
    Metatile("+_NO_OUT_66_DOWN_UD_2",     TILE(0x19a, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x18a, 0, 0, V), TILE(0x000, 0, 0, V), COL_NONE)


    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x688
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("BRICKS_SLOPE_45_UP",      TILE(0x000, 0, 0, 0), TILE(0x19f, 0, 0, 0), TILE(0x19e, 0, 0, 0), TILE(0x044, 0, 0, 0), COL_SLOPE_45_UP) // 0x690
    Metatile("BRICKS_SLOPE_45_DOWN",    TILE(0x19f, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x044, 0, H, 0), TILE(0x19e, 0, H, 0), COL_SLOPE_45_DOWN)
    Metatile("BRICKS_SLOPE_45_UP_UD",   TILE(0x19e, 0, 0, V), TILE(0x044, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x19f, 0, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("BRICKS_SLOPE_45_DOWN_UD", TILE(0x044, 0, H, V), TILE(0x19e, 0, H, V), TILE(0x19f, 0, H, V), TILE(0x000, 0, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("BRICKS_22_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1ac, 0, 0, 0), TILE(0x1ad, 0, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("BRICKS_22_UP_2",          TILE(0x1ae, 0, 0, 0), TILE(0x1af, 0, 0, 0), TILE(0x043, 0, 0, 0), TILE(0x044, 0, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("BRICKS_22_DOWN_1",        TILE(0x1af, 0, H, 0), TILE(0x1ae, 0, H, 0), TILE(0x044, 0, H, 0), TILE(0x043, 0, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("BRICKS_22_DOWN_2",        TILE(0x000, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x1ad, 0, H, 0), TILE(0x1ac, 0, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("BRICKS_22_UP_UD_1",       TILE(0x1ac, 0, 0, V), TILE(0x1ad, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x000, 0, 0, V), COL_SLOPE_22_UP_UD_1) // 0x698
    Metatile("BRICKS_22_UP_UD_2",       TILE(0x043, 0, 0, V), TILE(0x044, 0, 0, V), TILE(0x1ae, 0, 0, V), TILE(0x1af, 0, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("BRICKS_22_DOWN_UD_1",     TILE(0x044, 0, H, V), TILE(0x043, 0, H, V), TILE(0x1af, 0, H, V), TILE(0x1ae, 0, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("BRICKS_22_DOWN_UD_2",     TILE(0x1ad, 0, H, V), TILE(0x1ac, 0, H, V), TILE(0x000, 0, H, V), TILE(0x000, 0, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("BRICKS_66_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x1be, 0, H, 0), TILE(0x000, 0, 0, 0), TILE(0x1bf, 0, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("BRICKS_66_UP_2",          TILE(0x1bc, 0, H, 0), TILE(0x044, 0, H, 0), TILE(0x1bd, 0, H, 0), TILE(0x043, 0, H, 0), COL_SLOPE_66_UP_2)
    Metatile("BRICKS_66_DOWN_1",        TILE(0x044, 0, 0, 0), TILE(0x1bc, 0, 0, 0), TILE(0x043, 0, 0, 0), TILE(0x1bd, 0, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("BRICKS_66_DOWN_2",        TILE(0x1be, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1bf, 0, 0, 0), TILE(0x000, 0, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("BRICKS_66_UP_UD_1",       TILE(0x000, 0, 0, V), TILE(0x1bf, 0, H, V), TILE(0x000, 0, 0, V), TILE(0x1be, 0, H, V), COL_SLOPE_66_UP_UD_1) // 0x6a0
    Metatile("BRICKS_66_UP_UD_2",       TILE(0x1bd, 0, H, V), TILE(0x043, 0, H, V), TILE(0x1bc, 0, H, V), TILE(0x044, 0, H, V), COL_SLOPE_66_UP_UD_2)
    Metatile("BRICKS_66_DOWN_UD_1",     TILE(0x043, 0, 0, V), TILE(0x1bd, 0, 0, V), TILE(0x044, 0, 0, V), TILE(0x1bc, 0, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("BRICKS_66_DOWN_UD_2",     TILE(0x1bf, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x1be, 0, 0, V), TILE(0x000, 0, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x6a8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("BRICKS_NO_OUT_SLOPE_45_UP",      TILE(0x000, 0, 0, 0), TILE(0x1ab, 0, 0, 0), TILE(0x1aa, 0, 0, 0), TILE(0x044, 0, 0, 0), COL_NONE) // 0x6b0
    Metatile("BRICKS_NO_OUT_SLOPE_45_DOWN",    TILE(0x1ab, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x044, 0, H, 0), TILE(0x1aa, 0, H, 0), COL_NONE)
    Metatile("BRICKS_NO_OUT_SLOPE_45_UP_UD",   TILE(0x1aa, 0, 0, V), TILE(0x044, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x1ab, 0, 0, V), COL_NONE)
    Metatile("BRICKS_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x044, 0, H, V), TILE(0x1aa, 0, H, V), TILE(0x1ab, 0, H, V), TILE(0x000, 0, H, V), COL_NONE) 
    Metatile("BRICKS_NO_OUT_22_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1ba, 0, 0, 0), TILE(0x1bb, 0, 0, 0), COL_NONE)
    Metatile("BRICKS_NO_OUT_22_UP_2",          TILE(0x1a8, 0, 0, 0), TILE(0x1a9, 0, 0, 0), TILE(0x043, 0, 0, 0), TILE(0x044, 0, 0, 0), COL_NONE)
    Metatile("BRICKS_NO_OUT_22_DOWN_1",        TILE(0x1a9, 0, H, 0), TILE(0x1a8, 0, H, 0), TILE(0x044, 0, H, 0), TILE(0x043, 0, H, 0), COL_NONE)
    Metatile("BRICKS_NO_OUT_22_DOWN_2",        TILE(0x000, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x1bb, 0, H, 0), TILE(0x1ba, 0, H, 0), COL_NONE)
    Metatile("BRICKS_NO_OUT_22_UP_UD_1",       TILE(0x1ba, 0, 0, V), TILE(0x1bb, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x000, 0, 0, V), COL_NONE) // 0x6b8
    Metatile("BRICKS_NO_OUT_22_UP_UD_2",       TILE(0x043, 0, 0, V), TILE(0x044, 0, 0, V), TILE(0x1a8, 0, 0, V), TILE(0x1a9, 0, 0, V), COL_NONE)
    Metatile("BRICKS_NO_OUT_22_DOWN_UD_1",     TILE(0x044, 0, H, V), TILE(0x043, 0, H, V), TILE(0x1a9, 0, H, V), TILE(0x1a8, 0, H, V), COL_NONE)
    Metatile("BRICKS_NO_OUT_22_DOWN_UD_2",     TILE(0x1bb, 0, H, V), TILE(0x1ba, 0, H, V), TILE(0x000, 0, H, V), TILE(0x000, 0, H, V), COL_NONE)
    Metatile("BRICKS_NO_OUT_66_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x1a7, 0, H, 0), TILE(0x000, 0, 0, 0), TILE(0x1b7, 0, H, 0), COL_NONE) 
    Metatile("BRICKS_NO_OUT_66_UP_2",          TILE(0x1b8, 0, H, 0), TILE(0x044, 0, H, 0), TILE(0x1b9, 0, H, 0), TILE(0x043, 0, H, 0), COL_NONE)
    Metatile("BRICKS_NO_OUT_66_DOWN_1",        TILE(0x044, 0, 0, 0), TILE(0x1b8, 0, 0, 0), TILE(0x043, 0, 0, 0), TILE(0x1b9, 0, 0, 0), COL_NONE)
    Metatile("BRICKS_NO_OUT_66_DOWN_2",        TILE(0x1a7, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1b7, 0, 0, 0), TILE(0x000, 0, 0, 0), COL_NONE)
    Metatile("BRICKS_NO_OUT_66_UP_UD_1",       TILE(0x000, 0, 0, V), TILE(0x1b7, 0, H, V), TILE(0x000, 0, 0, V), TILE(0x1a7, 0, H, V), COL_NONE) // 0x6c0
    Metatile("BRICKS_NO_OUT_66_UP_UD_2",       TILE(0x1b9, 0, H, V), TILE(0x043, 0, H, V), TILE(0x1b8, 0, H, V), TILE(0x044, 0, H, V), COL_NONE)
    Metatile("BRICKS_NO_OUT_66_DOWN_UD_1",     TILE(0x043, 0, 0, V), TILE(0x1b9, 0, 0, V), TILE(0x044, 0, 0, V), TILE(0x1b8, 0, 0, V), COL_NONE)
    Metatile("BRICKS_NO_OUT_66_DOWN_UD_2",     TILE(0x1b7, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x1a7, 0, 0, V), TILE(0x000, 0, 0, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x6c8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("BLK_SLOPE_45_UP",      TILE(0x000, 0, 0, 0), TILE(0x1c5, 0, 0, 0), TILE(0x1c5, 0, 0, 0), TILE(0x03a, 0, 0, 0), COL_NONE) // 0x670
    Metatile("BLK_SLOPE_45_DOWN",    TILE(0x1c5, 0, H, 0), TILE(0x000, 0, 0, 0), TILE(0x03a, 0, H, 0), TILE(0x1c5, 0, H, 0), COL_NONE)
    Metatile("BLK_SLOPE_45_UP_UD",   TILE(0x1c5, 0, 0, V), TILE(0x03a, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x1c5, 0, 0, V), COL_NONE)
    Metatile("BLK_SLOPE_45_DOWN_UD", TILE(0x03a, 0, H, V), TILE(0x1c5, 0, H, V), TILE(0x1c5, 0, H, V), TILE(0x000, 0, 0, V), COL_NONE) 
    Metatile("BLK_22_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1c6, 0, 0, 0), TILE(0x1c7, 0, 0, 0), COL_NONE)
    Metatile("BLK_22_UP_2",          TILE(0x1c6, 0, 0, 0), TILE(0x1c7, 0, 0, 0), TILE(0x03a, 0, 0, 0), TILE(0x03a, 0, 0, 0), COL_NONE)
    Metatile("BLK_22_DOWN_1",        TILE(0x1c7, 0, H, 0), TILE(0x1c6, 0, H, 0), TILE(0x03a, 0, H, 0), TILE(0x03a, 0, H, 0), COL_NONE)
    Metatile("BLK_22_DOWN_2",        TILE(0x000, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x1c7, 0, H, 0), TILE(0x1c6, 0, H, 0), COL_NONE)
    Metatile("BLK_22_UP_UD_1",       TILE(0x1c6, 0, 0, V), TILE(0x1c7, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x000, 0, 0, V), COL_NONE) // 0x678
    Metatile("BLK_22_UP_UD_2",       TILE(0x03a, 0, 0, V), TILE(0x03a, 0, 0, V), TILE(0x1c6, 0, 0, V), TILE(0x1c7, 0, 0, V), COL_NONE)
    Metatile("BLK_22_DOWN_UD_1",     TILE(0x03a, 0, H, V), TILE(0x03a, 0, H, V), TILE(0x1c7, 0, H, V), TILE(0x1c6, 0, H, V), COL_NONE)
    Metatile("BLK_22_DOWN_UD_2",     TILE(0x1c7, 0, H, V), TILE(0x1c6, 0, H, V), TILE(0x000, 0, H, V), TILE(0x000, 0, H, V), COL_NONE)
    Metatile("BLK_66_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x1c9, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1c8, 0, 0, 0), COL_NONE) 
    Metatile("BLK_66_UP_2",          TILE(0x1c9, 0, 0, 0), TILE(0x03a, 0, 0, 0), TILE(0x1c8, 0, 0, 0), TILE(0x03a, 0, 0, 0), COL_NONE)
    Metatile("BLK_66_DOWN_1",        TILE(0x03a, 0, H, 0), TILE(0x1c9, 0, H, 0), TILE(0x03a, 0, H, 0), TILE(0x1c8, 0, H, 0), COL_NONE)
    Metatile("BLK_66_DOWN_2",        TILE(0x1c9, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x1c8, 0, H, 0), TILE(0x000, 0, H, 0), COL_NONE)
    Metatile("BLK_66_UP_UD_1",       TILE(0x000, 0, 0, V), TILE(0x1c8, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x1c9, 0, 0, V), COL_NONE) // 0x680
    Metatile("BLK_66_UP_UD_2",       TILE(0x1c8, 0, 0, V), TILE(0x03a, 0, 0, V), TILE(0x1c9, 0, 0, V), TILE(0x03a, 0, 0, V), COL_NONE)
    Metatile("BLK_66_DOWN_UD_1",     TILE(0x03a, 0, H, V), TILE(0x1c8, 0, H, V), TILE(0x03a, 0, H, V), TILE(0x1c9, 0, H, V), COL_NONE)
    Metatile("BLK_66_DOWN_UD_2",     TILE(0x1c8, 0, H, V), TILE(0x000, 0, H, V), TILE(0x1c9, 0, H, V), TILE(0x000, 0, H, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x688
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("1.6_SLOPE_45_UP",      TILE(0x000, 0, 0, 0), TILE(0x1cd, 0, 0, 0), TILE(0x1cd, 0, 0, 0), TILE(0x1dd, 0, 0, 0), COL_SLOPE_45_UP) // 0x690
    Metatile("1.6_SLOPE_45_DOWN",    TILE(0x1cd, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x1dd, 0, H, 0), TILE(0x1cd, 0, H, 0), COL_SLOPE_45_DOWN)
    Metatile("1.6_SLOPE_45_UP_UD",   TILE(0x1cd, 0, 0, V), TILE(0x1dd, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x1cd, 0, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("1.6_SLOPE_45_DOWN_UD", TILE(0x1dd, 0, H, V), TILE(0x1cd, 0, H, V), TILE(0x1cd, 0, H, V), TILE(0x000, 0, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("1.6_22_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1ce, 0, 0, 0), TILE(0x1cf, 0, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("1.6_22_UP_2",          TILE(0x1ce, 0, 0, 0), TILE(0x1cf, 0, 0, 0), TILE(0x1de, 0, 0, 0), TILE(0x1df, 0, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("1.6_22_DOWN_1",        TILE(0x1cf, 0, H, 0), TILE(0x1ce, 0, H, 0), TILE(0x1df, 0, H, 0), TILE(0x1de, 0, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("1.6_22_DOWN_2",        TILE(0x000, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x1cf, 0, H, 0), TILE(0x1ce, 0, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("1.6_22_UP_UD_1",       TILE(0x1ce, 0, 0, V), TILE(0x1cf, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x000, 0, 0, V), COL_SLOPE_22_UP_UD_1) // 0x698
    Metatile("1.6_22_UP_UD_2",       TILE(0x1de, 0, 0, V), TILE(0x1df, 0, 0, V), TILE(0x1ce, 0, 0, V), TILE(0x1cf, 0, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("1.6_22_DOWN_UD_1",     TILE(0x1df, 0, H, V), TILE(0x1de, 0, H, V), TILE(0x1cf, 0, H, V), TILE(0x1ce, 0, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("1.6_22_DOWN_UD_2",     TILE(0x1cf, 0, H, V), TILE(0x1ce, 0, H, V), TILE(0x000, 0, H, V), TILE(0x000, 0, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("1.6_66_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x1dc, 0, H, 0), TILE(0x000, 0, 0, 0), TILE(0x1ec, 0, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("1.6_66_UP_2",          TILE(0x1dc, 0, H, 0), TILE(0x1db, 0, H, 0), TILE(0x1ec, 0, H, 0), TILE(0x1eb, 0, H, 0), COL_SLOPE_66_UP_2)
    Metatile("1.6_66_DOWN_1",        TILE(0x1db, 0, 0, 0), TILE(0x1dc, 0, 0, 0), TILE(0x1eb, 0, 0, 0), TILE(0x1ec, 0, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("1.6_66_DOWN_2",        TILE(0x1dc, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1ec, 0, 0, 0), TILE(0x000, 0, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("1.6_66_UP_UD_1",       TILE(0x000, 0, 0, V), TILE(0x1ec, 0, H, V), TILE(0x000, 0, 0, V), TILE(0x1dc, 0, H, V), COL_SLOPE_66_UP_UD_1) // 0x6a0
    Metatile("1.6_66_UP_UD_2",       TILE(0x1ec, 0, H, V), TILE(0x1eb, 0, H, V), TILE(0x1dc, 0, H, V), TILE(0x1db, 0, H, V), COL_SLOPE_66_UP_UD_2)
    Metatile("1.6_66_DOWN_UD_1",     TILE(0x1eb, 0, 0, V), TILE(0x1ec, 0, 0, V), TILE(0x1db, 0, 0, V), TILE(0x1dc, 0, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("1.6_66_DOWN_UD_2",     TILE(0x1ec, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x1dc, 0, 0, V), TILE(0x000, 0, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("1.6_SLOPE_45_CORNER_TL",    TILE(0x1dd, 0, 0, 0), TILE(0x1ed, 0, 0, 0), TILE(0x1ed, 0, 0, 0), TILE(0x0a8, 0, 0, 0), COL_NONE)
    Metatile("1.6_SLOPE_45_CORNER_TR",    TILE(0x1ed, 0, H, 0), TILE(0x1dd, 0, H, 0), TILE(0x0a8, 0, H, 0), TILE(0x1ed, 0, H, 0), COL_NONE)
    Metatile("1.6_SLOPE_45_CORNER_BL",    TILE(0x1ed, 0, 0, V), TILE(0x0a8, 0, 0, V), TILE(0x1dd, 0, 0, V), TILE(0x1ed, 0, 0, V), COL_NONE)
    Metatile("1.6_SLOPE_45_CORNER_BR",    TILE(0x0a8, 0, H, V), TILE(0x1ed, 0, H, V), TILE(0x1ed, 0, H, V), TILE(0x1dd, 0, H, V), COL_NONE)

    Metatile("1.6_SLOPE_22_CORNER_TL",    TILE(0x1de, 0, 0, 0), TILE(0x1df, 0, 0, 0), TILE(0x1ee, 0, 0, 0), TILE(0x0a8, 0, 0, 0), COL_NONE) // 0x6a8
    Metatile("1.6_SLOPE_22_CORNER_TR",    TILE(0x1df, 0, H, 0), TILE(0x1de, 0, H, 0), TILE(0x0a8, 0, H, 0), TILE(0x1ee, 0, H, 0), COL_NONE)
    Metatile("1.6_SLOPE_22_CORNER_BL",    TILE(0x1ee, 0, 0, V), TILE(0x0a8, 0, 0, V), TILE(0x1de, 0, 0, V), TILE(0x1df, 0, 0, V), COL_NONE)
    Metatile("1.6_SLOPE_22_CORNER_BR",    TILE(0x0a8, 0, H, V), TILE(0x1ee, 0, H, V), TILE(0x1df, 0, H, V), TILE(0x1de, 0, H, V), COL_NONE)

    Metatile("1.6_SLOPE_66_CORNER_TL",    TILE(0x1db, 0, H, 0), TILE(0x1ef, 0, H, 0), TILE(0x1eb, 0, H, 0), TILE(0x0a8, 0, H, 0), COL_NONE)
    Metatile("1.6_SLOPE_66_CORNER_TR",    TILE(0x1ef, 0, 0, 0), TILE(0x1db, 0, 0, 0), TILE(0x0a8, 0, 0, 0), TILE(0x1eb, 0, 0, 0), COL_NONE)
    Metatile("1.6_SLOPE_66_CORNER_BL",    TILE(0x1eb, 0, H, V), TILE(0x0a8, 0, H, V), TILE(0x1db, 0, H, V), TILE(0x1ef, 0, H, V), COL_NONE)
    Metatile("1.6_SLOPE_66_CORNER_BR",    TILE(0x0a8, 0, 0, V), TILE(0x1eb, 0, 0, V), TILE(0x1ef, 0, 0, V), TILE(0x1db, 0, 0, V), COL_NONE)

    Metatile("1.6_NO_OUT_SLOPE_45_UP",      TILE(0x000, 0, 0, 0), TILE(0x1ca, 0, 0, 0), TILE(0x1ca, 0, 0, 0), TILE(0x1dd, 0, 0, 0), COL_NONE) // 0x6b0
    Metatile("1.6_NO_OUT_SLOPE_45_DOWN",    TILE(0x1ca, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x1dd, 0, H, 0), TILE(0x1ca, 0, H, 0), COL_NONE)
    Metatile("1.6_NO_OUT_SLOPE_45_UP_UD",   TILE(0x1ca, 0, 0, V), TILE(0x1dd, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x1ca, 0, 0, V), COL_NONE)
    Metatile("1.6_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x1dd, 0, H, V), TILE(0x1ca, 0, H, V), TILE(0x1ca, 0, H, V), TILE(0x000, 0, H, V), COL_NONE) 
    Metatile("1.6_NO_OUT_22_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1cb, 0, 0, 0), TILE(0x1cc, 0, 0, 0), COL_NONE)
    Metatile("1.6_NO_OUT_22_UP_2",          TILE(0x1cb, 0, 0, 0), TILE(0x1cc, 0, 0, 0), TILE(0x1de, 0, 0, 0), TILE(0x1df, 0, 0, 0), COL_NONE)
    Metatile("1.6_NO_OUT_22_DOWN_1",        TILE(0x1cc, 0, H, 0), TILE(0x1cb, 0, H, 0), TILE(0x1df, 0, H, 0), TILE(0x1de, 0, H, 0), COL_NONE)
    Metatile("1.6_NO_OUT_22_DOWN_2",        TILE(0x000, 0, H, 0), TILE(0x000, 0, H, 0), TILE(0x1cc, 0, H, 0), TILE(0x1cb, 0, H, 0), COL_NONE)
    Metatile("1.6_NO_OUT_22_UP_UD_1",       TILE(0x1cb, 0, 0, V), TILE(0x1cc, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x000, 0, 0, V), COL_NONE) // 0x6b8
    Metatile("1.6_NO_OUT_22_UP_UD_2",       TILE(0x1de, 0, 0, V), TILE(0x1df, 0, 0, V), TILE(0x1cb, 0, 0, V), TILE(0x1cc, 0, 0, V), COL_NONE)
    Metatile("1.6_NO_OUT_22_DOWN_UD_1",     TILE(0x1df, 0, H, V), TILE(0x1de, 0, H, V), TILE(0x1cc, 0, H, V), TILE(0x1cb, 0, H, V), COL_NONE)
    Metatile("1.6_NO_OUT_22_DOWN_UD_2",     TILE(0x1cc, 0, H, V), TILE(0x1cb, 0, H, V), TILE(0x000, 0, H, V), TILE(0x000, 0, H, V), COL_NONE)
    Metatile("1.6_NO_OUT_66_UP_1",          TILE(0x000, 0, 0, 0), TILE(0x1da, 0, H, 0), TILE(0x000, 0, 0, 0), TILE(0x1ea, 0, H, 0), COL_NONE) 
    Metatile("1.6_NO_OUT_66_UP_2",          TILE(0x1da, 0, H, 0), TILE(0x1db, 0, H, 0), TILE(0x1ea, 0, H, 0), TILE(0x1eb, 0, H, 0), COL_NONE)
    Metatile("1.6_NO_OUT_66_DOWN_1",        TILE(0x1db, 0, 0, 0), TILE(0x1da, 0, 0, 0), TILE(0x1eb, 0, 0, 0), TILE(0x1ea, 0, 0, 0), COL_NONE)
    Metatile("1.6_NO_OUT_66_DOWN_2",        TILE(0x1da, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1ea, 0, 0, 0), TILE(0x000, 0, 0, 0), COL_NONE)
    Metatile("1.6_NO_OUT_66_UP_UD_1",       TILE(0x000, 0, 0, V), TILE(0x1ea, 0, H, V), TILE(0x000, 0, 0, V), TILE(0x1da, 0, H, V), COL_NONE) // 0x6c0
    Metatile("1.6_NO_OUT_66_UP_UD_2",       TILE(0x1ea, 0, H, V), TILE(0x1eb, 0, H, V), TILE(0x1da, 0, H, V), TILE(0x1db, 0, H, V), COL_NONE)
    Metatile("1.6_NO_OUT_66_DOWN_UD_1",     TILE(0x1eb, 0, 0, V), TILE(0x1ea, 0, 0, V), TILE(0x1db, 0, 0, V), TILE(0x1da, 0, 0, V), COL_NONE)
    Metatile("1.6_NO_OUT_66_DOWN_UD_2",     TILE(0x1ea, 0, 0, V), TILE(0x000, 0, 0, V), TILE(0x1da, 0, 0, V), TILE(0x000, 0, 0, V), COL_NONE)

    Metatile("1.6_SLOPE_22_INS_CORNER_TL", TILE(0x1ee, 0, 0, 0), TILE(0x0a8, 0, 0, 0), TILE(0x0a8, 0, 0, 0), TILE(0x0a8, 0, 0, 0), COL_NONE)
    Metatile("1.6_SLOPE_22_INS_CORNER_TR", TILE(0x0a8, 0, 0, 0), TILE(0x1ee, 0, H, 0), TILE(0x0a8, 0, 0, 0), TILE(0x0a8, 0, 0, 0), COL_NONE)
    Metatile("1.6_SLOPE_22_INS_CORNER_BL", TILE(0x0a8, 0, 0, 0), TILE(0x0a8, 0, 0, 0), TILE(0x1ee, 0, 0, V), TILE(0x0a8, 0, 0, 0), COL_NONE)
    Metatile("1.6_SLOPE_22_INS_CORNER_BR", TILE(0x0a8, 0, 0, 0), TILE(0x0a8, 0, 0, 0), TILE(0x0a8, 0, 0, 0), TILE(0x1ee, 0, H, V), COL_NONE)

    Metatile("1.6_SLOPE_66_INS_CORNER_TL", TILE(0x1ef, 0, H, 0), TILE(0x0a8, 0, 0, 0), TILE(0x0a8, 0, 0, 0), TILE(0x0a8, 0, 0, 0), COL_NONE) // 0x6c8
    Metatile("1.6_SLOPE_66_INS_CORNER_TR", TILE(0x0a8, 0, 0, 0), TILE(0x1ef, 0, 0, 0), TILE(0x0a8, 0, 0, 0), TILE(0x0a8, 0, 0, 0), COL_NONE)
    Metatile("1.6_SLOPE_66_INS_CORNER_BL", TILE(0x0a8, 0, 0, 0), TILE(0x0a8, 0, 0, 0), TILE(0x1ef, 0, H, V), TILE(0x0a8, 0, 0, 0), COL_NONE)
    Metatile("1.6_SLOPE_66_INS_CORNER_BR", TILE(0x0a8, 0, 0, 0), TILE(0x0a8, 0, 0, 0), TILE(0x0a8, 0, 0, 0), TILE(0x1ef, 0, 0, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    // LBG SLOPES

    Metatile("LBG_CHKRED_SLOPE_45_UP",      TILE(0x000, LBG_PAL, 0, 0), TILE(0x1a2, LBG_PAL, 0, 0), TILE(0x1b2, LBG_PAL, 0, 0), TILE(0x007, LBG_PAL, 0, 0), COL_SLOPE_45_UP) // 0x5d0
    Metatile("LBG_CHKRED_SLOPE_45_DOWN",    TILE(0x1a2, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x007, LBG_PAL, H, 0), TILE(0x1b2, LBG_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("LBG_CHKRED_SLOPE_45_UP_UD",   TILE(0x1b2, LBG_PAL, 0, V), TILE(0x007, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x1a2, LBG_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("LBG_CHKRED_SLOPE_45_DOWN_UD", TILE(0x007, LBG_PAL, H, V), TILE(0x1b2, LBG_PAL, H, V), TILE(0x1a2, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("LBG_CHKRED_22_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1b3, LBG_PAL, 0, 0), TILE(0x1b4, LBG_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("LBG_CHKRED_22_UP_2",          TILE(0x1a3, LBG_PAL, 0, 0), TILE(0x1a4, LBG_PAL, 0, 0), TILE(0x003, LBG_PAL, 0, 0), TILE(0x003, LBG_PAL, H, 0), COL_SLOPE_22_UP_2)
    Metatile("LBG_CHKRED_22_DOWN_1",        TILE(0x1a4, LBG_PAL, H, 0), TILE(0x1a3, LBG_PAL, H, 0), TILE(0x003, LBG_PAL, 0, 0), TILE(0x003, LBG_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("LBG_CHKRED_22_DOWN_2",        TILE(0x000, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x1b4, LBG_PAL, H, 0), TILE(0x1b3, LBG_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("LBG_CHKRED_22_UP_UD_1",       TILE(0x1b3, LBG_PAL, 0, V), TILE(0x1b4, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x5d8
    Metatile("LBG_CHKRED_22_UP_UD_2",       TILE(0x003, LBG_PAL, 0, V), TILE(0x003, LBG_PAL, H, V), TILE(0x1a3, LBG_PAL, 0, V), TILE(0x1a4, LBG_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("LBG_CHKRED_22_DOWN_UD_1",     TILE(0x003, LBG_PAL, 0, V), TILE(0x003, LBG_PAL, H, V), TILE(0x1a4, LBG_PAL, H, V), TILE(0x1a3, LBG_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("LBG_CHKRED_22_DOWN_UD_2",     TILE(0x1b4, LBG_PAL, H, V), TILE(0x1b3, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("LBG_CHKRED_66_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x1a6, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1b6, LBG_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("LBG_CHKRED_66_UP_2",          TILE(0x1a5, LBG_PAL, H, 0), TILE(0x005, LBG_PAL, 0, 0), TILE(0x1b5, LBG_PAL, H, 0), TILE(0x005, LBG_PAL, 0, V), COL_SLOPE_66_UP_2)
    Metatile("LBG_CHKRED_66_DOWN_1",        TILE(0x005, LBG_PAL, H, 0), TILE(0x1a5, LBG_PAL, 0, 0), TILE(0x005, LBG_PAL, H, V), TILE(0x1b5, LBG_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("LBG_CHKRED_66_DOWN_2",        TILE(0x1a6, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1b6, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("LBG_CHKRED_66_UP_UD_1",       TILE(0x000, LBG_PAL, 0, 0), TILE(0x1b6, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1a6, LBG_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x5e0
    Metatile("LBG_CHKRED_66_UP_UD_2",       TILE(0x1b5, LBG_PAL, H, V), TILE(0x005, LBG_PAL, 0, 0), TILE(0x1a5, LBG_PAL, H, V), TILE(0x005, LBG_PAL, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("LBG_CHKRED_66_DOWN_UD_1",     TILE(0x005, LBG_PAL, H, 0), TILE(0x1b5, LBG_PAL, 0, V), TILE(0x005, LBG_PAL, H, V), TILE(0x1a5, LBG_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("LBG_CHKRED_66_DOWN_UD_2",     TILE(0x1b6, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1a6, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, 0), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x5e8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("LBG_CHKRED_NO_OUT_SLOPE_45_UP",      TILE(0x000, LBG_PAL, 0, 0), TILE(0x1c0, LBG_PAL, 0, 0), TILE(0x1d0, LBG_PAL, 0, 0), TILE(0x007, LBG_PAL, 0, 0), COL_NONE) // 0x5f0
    Metatile("LBG_CHKRED_NO_OUT_SLOPE_45_DOWN",    TILE(0x1c0, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x007, LBG_PAL, H, 0), TILE(0x1d0, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_CHKRED_NO_OUT_SLOPE_45_UP_UD",   TILE(0x1d0, LBG_PAL, 0, V), TILE(0x007, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x1c0, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_CHKRED_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x007, LBG_PAL, H, V), TILE(0x1d0, LBG_PAL, H, V), TILE(0x1c0, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_NONE) 
    Metatile("LBG_CHKRED_NO_OUT_22_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1b0, LBG_PAL, 0, 0), TILE(0x1b1, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_CHKRED_NO_OUT_22_UP_2",          TILE(0x1a0, LBG_PAL, 0, 0), TILE(0x1a1, LBG_PAL, 0, 0), TILE(0x003, LBG_PAL, 0, 0), TILE(0x003, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_CHKRED_NO_OUT_22_DOWN_1",        TILE(0x1a1, LBG_PAL, H, 0), TILE(0x1a0, LBG_PAL, H, 0), TILE(0x003, LBG_PAL, 0, 0), TILE(0x003, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_CHKRED_NO_OUT_22_DOWN_2",        TILE(0x000, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x1b1, LBG_PAL, H, 0), TILE(0x1b0, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_CHKRED_NO_OUT_22_UP_UD_1",       TILE(0x1b0, LBG_PAL, 0, V), TILE(0x1b1, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), COL_NONE) // 0x5f8
    Metatile("LBG_CHKRED_NO_OUT_22_UP_UD_2",       TILE(0x003, LBG_PAL, 0, V), TILE(0x003, LBG_PAL, H, V), TILE(0x1a0, LBG_PAL, 0, V), TILE(0x1a1, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_CHKRED_NO_OUT_22_DOWN_UD_1",     TILE(0x003, LBG_PAL, 0, V), TILE(0x003, LBG_PAL, H, V), TILE(0x1a1, LBG_PAL, H, V), TILE(0x1a0, LBG_PAL, H, V), COL_NONE)
    Metatile("LBG_CHKRED_NO_OUT_22_DOWN_UD_2",     TILE(0x1b1, LBG_PAL, H, V), TILE(0x1b0, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_NONE)
    Metatile("LBG_CHKRED_NO_OUT_66_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x1c1, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1d1, LBG_PAL, H, 0), COL_NONE) 
    Metatile("LBG_CHKRED_NO_OUT_66_UP_2",          TILE(0x1c2, LBG_PAL, H, 0), TILE(0x005, LBG_PAL, 0, 0), TILE(0x1d2, LBG_PAL, H, 0), TILE(0x005, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_CHKRED_NO_OUT_66_DOWN_1",        TILE(0x005, LBG_PAL, H, 0), TILE(0x1c2, LBG_PAL, 0, 0), TILE(0x005, LBG_PAL, H, V), TILE(0x1d2, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_CHKRED_NO_OUT_66_DOWN_2",        TILE(0x1c1, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1d1, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_CHKRED_NO_OUT_66_UP_UD_1",       TILE(0x000, LBG_PAL, 0, 0), TILE(0x1d1, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1c1, LBG_PAL, H, V), COL_NONE) // 0x600
    Metatile("LBG_CHKRED_NO_OUT_66_UP_UD_2",       TILE(0x1d2, LBG_PAL, H, V), TILE(0x005, LBG_PAL, 0, 0), TILE(0x1c2, LBG_PAL, H, V), TILE(0x005, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_CHKRED_NO_OUT_66_DOWN_UD_1",     TILE(0x005, LBG_PAL, H, 0), TILE(0x1d2, LBG_PAL, 0, V), TILE(0x005, LBG_PAL, H, V), TILE(0x1c2, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_CHKRED_NO_OUT_66_DOWN_UD_2",     TILE(0x1d1, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1c1, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x608
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("LBG_X_SLOPE_45_UP",      TILE(0x000, LBG_PAL, 0, 0), TILE(0x183, LBG_PAL, 0, 0), TILE(0x182, LBG_PAL, 0, 0), TILE(0x01a, LBG_PAL, 0, 0), COL_SLOPE_45_UP) // 0x610
    Metatile("LBG_X_SLOPE_45_DOWN",    TILE(0x183, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x01a, LBG_PAL, H, 0), TILE(0x182, LBG_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("LBG_X_SLOPE_45_UP_UD",   TILE(0x182, LBG_PAL, 0, V), TILE(0x01a, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x183, LBG_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("LBG_X_SLOPE_45_DOWN_UD", TILE(0x01a, LBG_PAL, H, V), TILE(0x182, LBG_PAL, H, V), TILE(0x183, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("LBG_X_22_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x170, LBG_PAL, 0, 0), TILE(0x171, LBG_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("LBG_X_22_UP_2",          TILE(0x172, LBG_PAL, 0, 0), TILE(0x173, LBG_PAL, 0, 0), TILE(0x019, LBG_PAL, 0, 0), TILE(0x01a, LBG_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("LBG_X_22_DOWN_1",        TILE(0x173, LBG_PAL, H, 0), TILE(0x172, LBG_PAL, H, 0), TILE(0x01a, LBG_PAL, H, 0), TILE(0x019, LBG_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("LBG_X_22_DOWN_2",        TILE(0x000, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x171, LBG_PAL, H, 0), TILE(0x170, LBG_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("LBG_X_22_UP_UD_1",       TILE(0x170, LBG_PAL, 0, V), TILE(0x171, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x618
    Metatile("LBG_X_22_UP_UD_2",       TILE(0x019, LBG_PAL, 0, V), TILE(0x01a, LBG_PAL, 0, V), TILE(0x172, LBG_PAL, 0, V), TILE(0x173, LBG_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("LBG_X_22_DOWN_UD_1",     TILE(0x01a, LBG_PAL, H, V), TILE(0x019, LBG_PAL, H, V), TILE(0x173, LBG_PAL, H, V), TILE(0x172, LBG_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("LBG_X_22_DOWN_UD_2",     TILE(0x171, LBG_PAL, H, V), TILE(0x170, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("LBG_X_66_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x181, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x191, LBG_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("LBG_X_66_UP_2",          TILE(0x180, LBG_PAL, H, 0), TILE(0x01c, LBG_PAL, 0, 0), TILE(0x190, LBG_PAL, H, 0), TILE(0x01a, LBG_PAL, 0, 0), COL_SLOPE_66_UP_2)
    Metatile("LBG_X_66_DOWN_1",        TILE(0x01c, LBG_PAL, H, 0), TILE(0x180, LBG_PAL, 0, 0), TILE(0x01a, LBG_PAL, H, 0), TILE(0x190, LBG_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("LBG_X_66_DOWN_2",        TILE(0x181, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x191, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("LBG_X_66_UP_UD_1",       TILE(0x000, LBG_PAL, 0, V), TILE(0x191, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x181, LBG_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x620
    Metatile("LBG_X_66_UP_UD_2",       TILE(0x190, LBG_PAL, H, V), TILE(0x01a, LBG_PAL, 0, V), TILE(0x180, LBG_PAL, H, V), TILE(0x01c, LBG_PAL, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("LBG_X_66_DOWN_UD_1",     TILE(0x01a, LBG_PAL, H, V), TILE(0x190, LBG_PAL, 0, V), TILE(0x01c, LBG_PAL, H, V), TILE(0x180, LBG_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("LBG_X_66_DOWN_UD_2",     TILE(0x191, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x181, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x628
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("LBG_X_NO_OUT_SLOPE_45_UP",      TILE(0x000, LBG_PAL, 0, 0), TILE(0x18f, LBG_PAL, 0, 0), TILE(0x18e, LBG_PAL, 0, 0), TILE(0x01a, LBG_PAL, 0, 0), COL_NONE) // 0x630
    Metatile("LBG_X_NO_OUT_SLOPE_45_DOWN",    TILE(0x18f, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x01a, LBG_PAL, H, 0), TILE(0x18e, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_X_NO_OUT_SLOPE_45_UP_UD",   TILE(0x18e, LBG_PAL, 0, V), TILE(0x01a, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x18f, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_X_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x01a, LBG_PAL, H, V), TILE(0x18e, LBG_PAL, H, V), TILE(0x18f, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_NONE) 
    Metatile("LBG_X_NO_OUT_22_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x17c, LBG_PAL, 0, 0), TILE(0x17d, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_X_NO_OUT_22_UP_2",          TILE(0x17e, LBG_PAL, 0, 0), TILE(0x17f, LBG_PAL, 0, 0), TILE(0x019, LBG_PAL, 0, 0), TILE(0x01a, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_X_NO_OUT_22_DOWN_1",        TILE(0x17f, LBG_PAL, H, 0), TILE(0x17e, LBG_PAL, H, 0), TILE(0x01a, LBG_PAL, H, 0), TILE(0x019, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_X_NO_OUT_22_DOWN_2",        TILE(0x000, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x17d, LBG_PAL, H, 0), TILE(0x17c, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_X_NO_OUT_22_UP_UD_1",       TILE(0x17c, LBG_PAL, 0, V), TILE(0x17d, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), COL_NONE) // 0x638
    Metatile("LBG_X_NO_OUT_22_UP_UD_2",       TILE(0x019, LBG_PAL, 0, V), TILE(0x01a, LBG_PAL, 0, V), TILE(0x17e, LBG_PAL, 0, V), TILE(0x17f, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_X_NO_OUT_22_DOWN_UD_1",     TILE(0x01a, LBG_PAL, H, V), TILE(0x019, LBG_PAL, H, V), TILE(0x17f, LBG_PAL, H, V), TILE(0x17e, LBG_PAL, H, V), COL_NONE)
    Metatile("LBG_X_NO_OUT_22_DOWN_UD_2",     TILE(0x17d, LBG_PAL, H, V), TILE(0x17c, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_NONE)
    Metatile("LBG_X_NO_OUT_66_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x18d, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x19d, LBG_PAL, H, 0), COL_NONE) 
    Metatile("LBG_X_NO_OUT_66_UP_2",          TILE(0x18c, LBG_PAL, H, 0), TILE(0x01c, LBG_PAL, 0, 0), TILE(0x19c, LBG_PAL, H, 0), TILE(0x01a, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_X_NO_OUT_66_DOWN_1",        TILE(0x01c, LBG_PAL, H, 0), TILE(0x18c, LBG_PAL, 0, 0), TILE(0x01a, LBG_PAL, H, 0), TILE(0x19c, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_X_NO_OUT_66_DOWN_2",        TILE(0x18d, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x19d, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_X_NO_OUT_66_UP_UD_1",       TILE(0x000, LBG_PAL, 0, V), TILE(0x19d, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x18d, LBG_PAL, H, V), COL_NONE) // 0x640
    Metatile("LBG_X_NO_OUT_66_UP_UD_2",       TILE(0x19c, LBG_PAL, H, V), TILE(0x01a, LBG_PAL, 0, V), TILE(0x18c, LBG_PAL, H, V), TILE(0x01c, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_X_NO_OUT_66_DOWN_UD_1",     TILE(0x01a, LBG_PAL, H, V), TILE(0x19c, LBG_PAL, 0, V), TILE(0x01c, LBG_PAL, H, V), TILE(0x18c, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_X_NO_OUT_66_DOWN_UD_2",     TILE(0x19d, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x18d, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x648
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    
    Metatile("LBG_+_SLOPE_45_UP",      TILE(0x000, LBG_PAL, 0, 0), TILE(0x177, LBG_PAL, 0, 0), TILE(0x176, LBG_PAL, 0, 0), TILE(0x031, LBG_PAL, 0, 0), COL_SLOPE_45_UP) // 0x650
    Metatile("LBG_+_SLOPE_45_DOWN",    TILE(0x177, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x031, LBG_PAL, H, 0), TILE(0x176, LBG_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("LBG_+_SLOPE_45_UP_UD",   TILE(0x176, LBG_PAL, 0, V), TILE(0x031, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x177, LBG_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("LBG_+_SLOPE_45_DOWN_UD", TILE(0x031, LBG_PAL, H, V), TILE(0x176, LBG_PAL, H, V), TILE(0x177, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("LBG_+_22_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x184, LBG_PAL, 0, 0), TILE(0x185, LBG_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("LBG_+_22_UP_2",          TILE(0x186, LBG_PAL, 0, 0), TILE(0x187, LBG_PAL, 0, 0), TILE(0x030, LBG_PAL, 0, 0), TILE(0x031, LBG_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("LBG_+_22_DOWN_1",        TILE(0x187, LBG_PAL, H, 0), TILE(0x186, LBG_PAL, H, 0), TILE(0x031, LBG_PAL, H, 0), TILE(0x030, LBG_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("LBG_+_22_DOWN_2",        TILE(0x000, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x185, LBG_PAL, H, 0), TILE(0x184, LBG_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("LBG_+_22_UP_UD_1",       TILE(0x184, LBG_PAL, 0, V), TILE(0x185, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x658
    Metatile("LBG_+_22_UP_UD_2",       TILE(0x030, LBG_PAL, 0, V), TILE(0x031, LBG_PAL, 0, V), TILE(0x186, LBG_PAL, 0, V), TILE(0x187, LBG_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("LBG_+_22_DOWN_UD_1",     TILE(0x031, LBG_PAL, H, V), TILE(0x030, LBG_PAL, H, V), TILE(0x187, LBG_PAL, H, V), TILE(0x186, LBG_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("LBG_+_22_DOWN_UD_2",     TILE(0x185, LBG_PAL, H, V), TILE(0x184, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("LBG_+_66_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x188, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x198, LBG_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("LBG_+_66_UP_2",          TILE(0x189, LBG_PAL, H, 0), TILE(0x035, LBG_PAL, H, 0), TILE(0x199, LBG_PAL, H, 0), TILE(0x030, LBG_PAL, H, 0), COL_SLOPE_66_UP_2)
    Metatile("LBG_+_66_DOWN_1",        TILE(0x035, LBG_PAL, 0, 0), TILE(0x189, LBG_PAL, 0, 0), TILE(0x030, LBG_PAL, 0, 0), TILE(0x199, LBG_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("LBG_+_66_DOWN_2",        TILE(0x188, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x198, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("LBG_+_66_UP_UD_1",       TILE(0x000, LBG_PAL, 0, V), TILE(0x198, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x188, LBG_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x660
    Metatile("LBG_+_66_UP_UD_2",       TILE(0x199, LBG_PAL, H, V), TILE(0x030, LBG_PAL, H, V), TILE(0x189, LBG_PAL, H, V), TILE(0x035, LBG_PAL, H, V), COL_SLOPE_66_UP_UD_2)
    Metatile("LBG_+_66_DOWN_UD_1",     TILE(0x030, LBG_PAL, 0, V), TILE(0x199, LBG_PAL, 0, V), TILE(0x035, LBG_PAL, 0, V), TILE(0x189, LBG_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("LBG_+_66_DOWN_UD_2",     TILE(0x198, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x188, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x668
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("LBG_+_NO_OUT_SLOPE_45_UP",      TILE(0x000, LBG_PAL, 0, 0), TILE(0x193, LBG_PAL, 0, 0), TILE(0x192, LBG_PAL, 0, 0), TILE(0x031, LBG_PAL, 0, 0), COL_NONE) // 0x670
    Metatile("LBG_+_NO_OUT_SLOPE_45_DOWN",    TILE(0x193, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x031, LBG_PAL, H, 0), TILE(0x192, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_+_NO_OUT_SLOPE_45_UP_UD",   TILE(0x192, LBG_PAL, 0, V), TILE(0x031, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x193, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_+_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x031, LBG_PAL, H, V), TILE(0x192, LBG_PAL, H, V), TILE(0x193, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_NONE) 
    Metatile("LBG_+_NO_OUT_22_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x194, LBG_PAL, 0, 0), TILE(0x195, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_+_NO_OUT_22_UP_2",          TILE(0x196, LBG_PAL, 0, 0), TILE(0x197, LBG_PAL, 0, 0), TILE(0x030, LBG_PAL, 0, 0), TILE(0x031, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_+_NO_OUT_22_DOWN_1",        TILE(0x197, LBG_PAL, H, 0), TILE(0x196, LBG_PAL, H, 0), TILE(0x031, LBG_PAL, H, 0), TILE(0x030, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_+_NO_OUT_22_DOWN_2",        TILE(0x000, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x195, LBG_PAL, H, 0), TILE(0x194, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_+_NO_OUT_22_UP_UD_1",       TILE(0x194, LBG_PAL, 0, V), TILE(0x195, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), COL_NONE) // 0x678
    Metatile("LBG_+_NO_OUT_22_UP_UD_2",       TILE(0x030, LBG_PAL, 0, V), TILE(0x031, LBG_PAL, 0, V), TILE(0x196, LBG_PAL, 0, V), TILE(0x197, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_+_NO_OUT_22_DOWN_UD_1",     TILE(0x031, LBG_PAL, H, V), TILE(0x030, LBG_PAL, H, V), TILE(0x197, LBG_PAL, H, V), TILE(0x196, LBG_PAL, H, V), COL_NONE)
    Metatile("LBG_+_NO_OUT_22_DOWN_UD_2",     TILE(0x195, LBG_PAL, H, V), TILE(0x194, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_NONE)
    Metatile("LBG_+_NO_OUT_66_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x18a, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x19a, LBG_PAL, H, 0), COL_NONE) 
    Metatile("LBG_+_NO_OUT_66_UP_2",          TILE(0x18b, LBG_PAL, H, 0), TILE(0x035, LBG_PAL, H, 0), TILE(0x19b, LBG_PAL, H, 0), TILE(0x030, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_+_NO_OUT_66_DOWN_1",        TILE(0x035, LBG_PAL, 0, 0), TILE(0x18b, LBG_PAL, 0, 0), TILE(0x030, LBG_PAL, 0, 0), TILE(0x19b, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_+_NO_OUT_66_DOWN_2",        TILE(0x18a, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x19a, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_+_NO_OUT_66_UP_UD_1",       TILE(0x000, LBG_PAL, 0, V), TILE(0x19a, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x18a, LBG_PAL, H, V), COL_NONE) // 0x680
    Metatile("LBG_+_NO_OUT_66_UP_UD_2",       TILE(0x19b, LBG_PAL, H, V), TILE(0x030, LBG_PAL, H, V), TILE(0x18b, LBG_PAL, H, V), TILE(0x035, LBG_PAL, H, V), COL_NONE)
    Metatile("LBG_+_NO_OUT_66_DOWN_UD_1",     TILE(0x030, LBG_PAL, 0, V), TILE(0x19b, LBG_PAL, 0, V), TILE(0x035, LBG_PAL, 0, V), TILE(0x18b, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_+_NO_OUT_66_DOWN_UD_2",     TILE(0x19a, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x18a, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), COL_NONE)


    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x688
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("LBG_BRICKS_SLOPE_45_UP",      TILE(0x000, LBG_PAL, 0, 0), TILE(0x19f, LBG_PAL, 0, 0), TILE(0x19e, LBG_PAL, 0, 0), TILE(0x044, LBG_PAL, 0, 0), COL_SLOPE_45_UP) // 0x690
    Metatile("LBG_BRICKS_SLOPE_45_DOWN",    TILE(0x19f, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x044, LBG_PAL, H, 0), TILE(0x19e, LBG_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("LBG_BRICKS_SLOPE_45_UP_UD",   TILE(0x19e, LBG_PAL, 0, V), TILE(0x044, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x19f, LBG_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("LBG_BRICKS_SLOPE_45_DOWN_UD", TILE(0x044, LBG_PAL, H, V), TILE(0x19e, LBG_PAL, H, V), TILE(0x19f, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("LBG_BRICKS_22_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1ac, LBG_PAL, 0, 0), TILE(0x1ad, LBG_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("LBG_BRICKS_22_UP_2",          TILE(0x1ae, LBG_PAL, 0, 0), TILE(0x1af, LBG_PAL, 0, 0), TILE(0x043, LBG_PAL, 0, 0), TILE(0x044, LBG_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("LBG_BRICKS_22_DOWN_1",        TILE(0x1af, LBG_PAL, H, 0), TILE(0x1ae, LBG_PAL, H, 0), TILE(0x044, LBG_PAL, H, 0), TILE(0x043, LBG_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("LBG_BRICKS_22_DOWN_2",        TILE(0x000, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x1ad, LBG_PAL, H, 0), TILE(0x1ac, LBG_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("LBG_BRICKS_22_UP_UD_1",       TILE(0x1ac, LBG_PAL, 0, V), TILE(0x1ad, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x698
    Metatile("LBG_BRICKS_22_UP_UD_2",       TILE(0x043, LBG_PAL, 0, V), TILE(0x044, LBG_PAL, 0, V), TILE(0x1ae, LBG_PAL, 0, V), TILE(0x1af, LBG_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("LBG_BRICKS_22_DOWN_UD_1",     TILE(0x044, LBG_PAL, H, V), TILE(0x043, LBG_PAL, H, V), TILE(0x1af, LBG_PAL, H, V), TILE(0x1ae, LBG_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("LBG_BRICKS_22_DOWN_UD_2",     TILE(0x1ad, LBG_PAL, H, V), TILE(0x1ac, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("LBG_BRICKS_66_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x1be, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1bf, LBG_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("LBG_BRICKS_66_UP_2",          TILE(0x1bc, LBG_PAL, H, 0), TILE(0x044, LBG_PAL, H, 0), TILE(0x1bd, LBG_PAL, H, 0), TILE(0x043, LBG_PAL, H, 0), COL_SLOPE_66_UP_2)
    Metatile("LBG_BRICKS_66_DOWN_1",        TILE(0x044, LBG_PAL, 0, 0), TILE(0x1bc, LBG_PAL, 0, 0), TILE(0x043, LBG_PAL, 0, 0), TILE(0x1bd, LBG_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("LBG_BRICKS_66_DOWN_2",        TILE(0x1be, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1bf, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("LBG_BRICKS_66_UP_UD_1",       TILE(0x000, LBG_PAL, 0, V), TILE(0x1bf, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x1be, LBG_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x6a0
    Metatile("LBG_BRICKS_66_UP_UD_2",       TILE(0x1bd, LBG_PAL, H, V), TILE(0x043, LBG_PAL, H, V), TILE(0x1bc, LBG_PAL, H, V), TILE(0x044, LBG_PAL, H, V), COL_SLOPE_66_UP_UD_2)
    Metatile("LBG_BRICKS_66_DOWN_UD_1",     TILE(0x043, LBG_PAL, 0, V), TILE(0x1bd, LBG_PAL, 0, V), TILE(0x044, LBG_PAL, 0, V), TILE(0x1bc, LBG_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("LBG_BRICKS_66_DOWN_UD_2",     TILE(0x1bf, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x1be, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x6a8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("LBG_BRICKS_NO_OUT_SLOPE_45_UP",      TILE(0x000, LBG_PAL, 0, 0), TILE(0x1ab, LBG_PAL, 0, 0), TILE(0x1aa, LBG_PAL, 0, 0), TILE(0x044, LBG_PAL, 0, 0), COL_NONE) // 0x6b0
    Metatile("LBG_BRICKS_NO_OUT_SLOPE_45_DOWN",    TILE(0x1ab, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x044, LBG_PAL, H, 0), TILE(0x1aa, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_BRICKS_NO_OUT_SLOPE_45_UP_UD",   TILE(0x1aa, LBG_PAL, 0, V), TILE(0x044, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x1ab, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_BRICKS_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x044, LBG_PAL, H, V), TILE(0x1aa, LBG_PAL, H, V), TILE(0x1ab, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_NONE) 
    Metatile("LBG_BRICKS_NO_OUT_22_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1ba, LBG_PAL, 0, 0), TILE(0x1bb, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_BRICKS_NO_OUT_22_UP_2",          TILE(0x1a8, LBG_PAL, 0, 0), TILE(0x1a9, LBG_PAL, 0, 0), TILE(0x043, LBG_PAL, 0, 0), TILE(0x044, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_BRICKS_NO_OUT_22_DOWN_1",        TILE(0x1a9, LBG_PAL, H, 0), TILE(0x1a8, LBG_PAL, H, 0), TILE(0x044, LBG_PAL, H, 0), TILE(0x043, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_BRICKS_NO_OUT_22_DOWN_2",        TILE(0x000, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x1bb, LBG_PAL, H, 0), TILE(0x1ba, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_BRICKS_NO_OUT_22_UP_UD_1",       TILE(0x1ba, LBG_PAL, 0, V), TILE(0x1bb, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), COL_NONE) // 0x6b8
    Metatile("LBG_BRICKS_NO_OUT_22_UP_UD_2",       TILE(0x043, LBG_PAL, 0, V), TILE(0x044, LBG_PAL, 0, V), TILE(0x1a8, LBG_PAL, 0, V), TILE(0x1a9, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_BRICKS_NO_OUT_22_DOWN_UD_1",     TILE(0x044, LBG_PAL, H, V), TILE(0x043, LBG_PAL, H, V), TILE(0x1a9, LBG_PAL, H, V), TILE(0x1a8, LBG_PAL, H, V), COL_NONE)
    Metatile("LBG_BRICKS_NO_OUT_22_DOWN_UD_2",     TILE(0x1bb, LBG_PAL, H, V), TILE(0x1ba, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_NONE)
    Metatile("LBG_BRICKS_NO_OUT_66_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x1a7, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1b7, LBG_PAL, H, 0), COL_NONE) 
    Metatile("LBG_BRICKS_NO_OUT_66_UP_2",          TILE(0x1b8, LBG_PAL, H, 0), TILE(0x044, LBG_PAL, H, 0), TILE(0x1b9, LBG_PAL, H, 0), TILE(0x043, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_BRICKS_NO_OUT_66_DOWN_1",        TILE(0x044, LBG_PAL, 0, 0), TILE(0x1b8, LBG_PAL, 0, 0), TILE(0x043, LBG_PAL, 0, 0), TILE(0x1b9, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_BRICKS_NO_OUT_66_DOWN_2",        TILE(0x1a7, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1b7, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_BRICKS_NO_OUT_66_UP_UD_1",       TILE(0x000, LBG_PAL, 0, V), TILE(0x1b7, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x1a7, LBG_PAL, H, V), COL_NONE) // 0x6c0
    Metatile("LBG_BRICKS_NO_OUT_66_UP_UD_2",       TILE(0x1b9, LBG_PAL, H, V), TILE(0x043, LBG_PAL, H, V), TILE(0x1b8, LBG_PAL, H, V), TILE(0x044, LBG_PAL, H, V), COL_NONE)
    Metatile("LBG_BRICKS_NO_OUT_66_DOWN_UD_1",     TILE(0x043, LBG_PAL, 0, V), TILE(0x1b9, LBG_PAL, 0, V), TILE(0x044, LBG_PAL, 0, V), TILE(0x1b8, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_BRICKS_NO_OUT_66_DOWN_UD_2",     TILE(0x1b7, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x1a7, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x6c8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("LBG_BLK_SLOPE_45_UP",      TILE(0x000, LBG_PAL, 0, 0), TILE(0x1c5, LBG_PAL, 0, 0), TILE(0x1c5, LBG_PAL, 0, 0), TILE(0x03a, LBG_PAL, 0, 0), COL_NONE) // 0x670
    Metatile("LBG_BLK_SLOPE_45_DOWN",    TILE(0x1c5, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x03a, LBG_PAL, H, 0), TILE(0x1c5, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_BLK_SLOPE_45_UP_UD",   TILE(0x1c5, LBG_PAL, 0, V), TILE(0x03a, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x1c5, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_BLK_SLOPE_45_DOWN_UD", TILE(0x03a, LBG_PAL, H, V), TILE(0x1c5, LBG_PAL, H, V), TILE(0x1c5, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, V), COL_NONE) 
    Metatile("LBG_BLK_22_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1c6, LBG_PAL, 0, 0), TILE(0x1c7, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_BLK_22_UP_2",          TILE(0x1c6, LBG_PAL, 0, 0), TILE(0x1c7, LBG_PAL, 0, 0), TILE(0x03a, LBG_PAL, 0, 0), TILE(0x03a, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_BLK_22_DOWN_1",        TILE(0x1c7, LBG_PAL, H, 0), TILE(0x1c6, LBG_PAL, H, 0), TILE(0x03a, LBG_PAL, H, 0), TILE(0x03a, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_BLK_22_DOWN_2",        TILE(0x000, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x1c7, LBG_PAL, H, 0), TILE(0x1c6, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_BLK_22_UP_UD_1",       TILE(0x1c6, LBG_PAL, 0, V), TILE(0x1c7, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), COL_NONE) // 0x678
    Metatile("LBG_BLK_22_UP_UD_2",       TILE(0x03a, LBG_PAL, 0, V), TILE(0x03a, LBG_PAL, 0, V), TILE(0x1c6, LBG_PAL, 0, V), TILE(0x1c7, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_BLK_22_DOWN_UD_1",     TILE(0x03a, LBG_PAL, H, V), TILE(0x03a, LBG_PAL, H, V), TILE(0x1c7, LBG_PAL, H, V), TILE(0x1c6, LBG_PAL, H, V), COL_NONE)
    Metatile("LBG_BLK_22_DOWN_UD_2",     TILE(0x1c7, LBG_PAL, H, V), TILE(0x1c6, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_NONE)
    Metatile("LBG_BLK_66_UP_1",          TILE(0x000, LBG_PAL, 0, 0), TILE(0x1c9, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1c8, LBG_PAL, 0, 0), COL_NONE) 
    Metatile("LBG_BLK_66_UP_2",          TILE(0x1c9, LBG_PAL, 0, 0), TILE(0x03a, LBG_PAL, 0, 0), TILE(0x1c8, LBG_PAL, 0, 0), TILE(0x03a, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_BLK_66_DOWN_1",        TILE(0x03a, LBG_PAL, H, 0), TILE(0x1c9, LBG_PAL, H, 0), TILE(0x03a, LBG_PAL, H, 0), TILE(0x1c8, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_BLK_66_DOWN_2",        TILE(0x1c9, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), TILE(0x1c8, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, H, 0), COL_NONE)
    Metatile("LBG_BLK_66_UP_UD_1",       TILE(0x000, LBG_PAL, 0, V), TILE(0x1c8, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, V), TILE(0x1c9, LBG_PAL, 0, V), COL_NONE) // 0x680
    Metatile("LBG_BLK_66_UP_UD_2",       TILE(0x1c8, LBG_PAL, 0, V), TILE(0x03a, LBG_PAL, 0, V), TILE(0x1c9, LBG_PAL, 0, V), TILE(0x03a, LBG_PAL, 0, V), COL_NONE)
    Metatile("LBG_BLK_66_DOWN_UD_1",     TILE(0x03a, LBG_PAL, H, V), TILE(0x1c8, LBG_PAL, H, V), TILE(0x03a, LBG_PAL, H, V), TILE(0x1c9, LBG_PAL, H, V), COL_NONE)
    Metatile("LBG_BLK_66_DOWN_UD_2",     TILE(0x1c8, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), TILE(0x1c9, LBG_PAL, H, V), TILE(0x000, LBG_PAL, H, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x688
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    // COL 1 SLOPES

    
    Metatile("COL1_CHKRED_SLOPE_45_UP",      TILE(0x000, COL1_PAL, 0, 0), TILE(0x1a2, COL1_PAL, 0, 0), TILE(0x1b2, COL1_PAL, 0, 0), TILE(0x007, COL1_PAL, 0, 0), COL_SLOPE_45_UP) // 0x5d0
    Metatile("COL1_CHKRED_SLOPE_45_DOWN",    TILE(0x1a2, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x007, COL1_PAL, H, 0), TILE(0x1b2, COL1_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL1_CHKRED_SLOPE_45_UP_UD",   TILE(0x1b2, COL1_PAL, 0, V), TILE(0x007, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x1a2, COL1_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL1_CHKRED_SLOPE_45_DOWN_UD", TILE(0x007, COL1_PAL, H, V), TILE(0x1b2, COL1_PAL, H, V), TILE(0x1a2, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL1_CHKRED_22_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1b3, COL1_PAL, 0, 0), TILE(0x1b4, COL1_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL1_CHKRED_22_UP_2",          TILE(0x1a3, COL1_PAL, 0, 0), TILE(0x1a4, COL1_PAL, 0, 0), TILE(0x003, COL1_PAL, 0, 0), TILE(0x003, COL1_PAL, H, 0), COL_SLOPE_22_UP_2)
    Metatile("COL1_CHKRED_22_DOWN_1",        TILE(0x1a4, COL1_PAL, H, 0), TILE(0x1a3, COL1_PAL, H, 0), TILE(0x003, COL1_PAL, 0, 0), TILE(0x003, COL1_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL1_CHKRED_22_DOWN_2",        TILE(0x000, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x1b4, COL1_PAL, H, 0), TILE(0x1b3, COL1_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL1_CHKRED_22_UP_UD_1",       TILE(0x1b3, COL1_PAL, 0, V), TILE(0x1b4, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x5d8
    Metatile("COL1_CHKRED_22_UP_UD_2",       TILE(0x003, COL1_PAL, 0, V), TILE(0x003, COL1_PAL, H, V), TILE(0x1a3, COL1_PAL, 0, V), TILE(0x1a4, COL1_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL1_CHKRED_22_DOWN_UD_1",     TILE(0x003, COL1_PAL, 0, V), TILE(0x003, COL1_PAL, H, V), TILE(0x1a4, COL1_PAL, H, V), TILE(0x1a3, COL1_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL1_CHKRED_22_DOWN_UD_2",     TILE(0x1b4, COL1_PAL, H, V), TILE(0x1b3, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL1_CHKRED_66_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x1a6, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1b6, COL1_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL1_CHKRED_66_UP_2",          TILE(0x1a5, COL1_PAL, H, 0), TILE(0x005, COL1_PAL, 0, 0), TILE(0x1b5, COL1_PAL, H, 0), TILE(0x005, COL1_PAL, 0, V), COL_SLOPE_66_UP_2)
    Metatile("COL1_CHKRED_66_DOWN_1",        TILE(0x005, COL1_PAL, H, 0), TILE(0x1a5, COL1_PAL, 0, 0), TILE(0x005, COL1_PAL, H, V), TILE(0x1b5, COL1_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL1_CHKRED_66_DOWN_2",        TILE(0x1a6, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1b6, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL1_CHKRED_66_UP_UD_1",       TILE(0x000, COL1_PAL, 0, 0), TILE(0x1b6, COL1_PAL, H, V), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1a6, COL1_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x5e0
    Metatile("COL1_CHKRED_66_UP_UD_2",       TILE(0x1b5, COL1_PAL, H, V), TILE(0x005, COL1_PAL, 0, 0), TILE(0x1a5, COL1_PAL, H, V), TILE(0x005, COL1_PAL, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL1_CHKRED_66_DOWN_UD_1",     TILE(0x005, COL1_PAL, H, 0), TILE(0x1b5, COL1_PAL, 0, V), TILE(0x005, COL1_PAL, H, V), TILE(0x1a5, COL1_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL1_CHKRED_66_DOWN_UD_2",     TILE(0x1b6, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1a6, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, 0), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x5e8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL1_CHKRED_NO_OUT_SLOPE_45_UP",      TILE(0x000, COL1_PAL, 0, 0), TILE(0x1c0, COL1_PAL, 0, 0), TILE(0x1d0, COL1_PAL, 0, 0), TILE(0x007, COL1_PAL, 0, 0), COL_NONE) // 0x5f0
    Metatile("COL1_CHKRED_NO_OUT_SLOPE_45_DOWN",    TILE(0x1c0, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x007, COL1_PAL, H, 0), TILE(0x1d0, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_CHKRED_NO_OUT_SLOPE_45_UP_UD",   TILE(0x1d0, COL1_PAL, 0, V), TILE(0x007, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x1c0, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_CHKRED_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x007, COL1_PAL, H, V), TILE(0x1d0, COL1_PAL, H, V), TILE(0x1c0, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_NONE) 
    Metatile("COL1_CHKRED_NO_OUT_22_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1b0, COL1_PAL, 0, 0), TILE(0x1b1, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_CHKRED_NO_OUT_22_UP_2",          TILE(0x1a0, COL1_PAL, 0, 0), TILE(0x1a1, COL1_PAL, 0, 0), TILE(0x003, COL1_PAL, 0, 0), TILE(0x003, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_CHKRED_NO_OUT_22_DOWN_1",        TILE(0x1a1, COL1_PAL, H, 0), TILE(0x1a0, COL1_PAL, H, 0), TILE(0x003, COL1_PAL, 0, 0), TILE(0x003, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_CHKRED_NO_OUT_22_DOWN_2",        TILE(0x000, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x1b1, COL1_PAL, H, 0), TILE(0x1b0, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_CHKRED_NO_OUT_22_UP_UD_1",       TILE(0x1b0, COL1_PAL, 0, V), TILE(0x1b1, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), COL_NONE) // 0x5f8
    Metatile("COL1_CHKRED_NO_OUT_22_UP_UD_2",       TILE(0x003, COL1_PAL, 0, V), TILE(0x003, COL1_PAL, H, V), TILE(0x1a0, COL1_PAL, 0, V), TILE(0x1a1, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_CHKRED_NO_OUT_22_DOWN_UD_1",     TILE(0x003, COL1_PAL, 0, V), TILE(0x003, COL1_PAL, H, V), TILE(0x1a1, COL1_PAL, H, V), TILE(0x1a0, COL1_PAL, H, V), COL_NONE)
    Metatile("COL1_CHKRED_NO_OUT_22_DOWN_UD_2",     TILE(0x1b1, COL1_PAL, H, V), TILE(0x1b0, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_NONE)
    Metatile("COL1_CHKRED_NO_OUT_66_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x1c1, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1d1, COL1_PAL, H, 0), COL_NONE) 
    Metatile("COL1_CHKRED_NO_OUT_66_UP_2",          TILE(0x1c2, COL1_PAL, H, 0), TILE(0x005, COL1_PAL, 0, 0), TILE(0x1d2, COL1_PAL, H, 0), TILE(0x005, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_CHKRED_NO_OUT_66_DOWN_1",        TILE(0x005, COL1_PAL, H, 0), TILE(0x1c2, COL1_PAL, 0, 0), TILE(0x005, COL1_PAL, H, V), TILE(0x1d2, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_CHKRED_NO_OUT_66_DOWN_2",        TILE(0x1c1, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1d1, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_CHKRED_NO_OUT_66_UP_UD_1",       TILE(0x000, COL1_PAL, 0, 0), TILE(0x1d1, COL1_PAL, H, V), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1c1, COL1_PAL, H, V), COL_NONE) // 0x600
    Metatile("COL1_CHKRED_NO_OUT_66_UP_UD_2",       TILE(0x1d2, COL1_PAL, H, V), TILE(0x005, COL1_PAL, 0, 0), TILE(0x1c2, COL1_PAL, H, V), TILE(0x005, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_CHKRED_NO_OUT_66_DOWN_UD_1",     TILE(0x005, COL1_PAL, H, 0), TILE(0x1d2, COL1_PAL, 0, V), TILE(0x005, COL1_PAL, H, V), TILE(0x1c2, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_CHKRED_NO_OUT_66_DOWN_UD_2",     TILE(0x1d1, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1c1, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, 0), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x608
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("COL1_X_SLOPE_45_UP",      TILE(0x000, COL1_PAL, 0, 0), TILE(0x183, COL1_PAL, 0, 0), TILE(0x182, COL1_PAL, 0, 0), TILE(0x01a, COL1_PAL, 0, 0), COL_SLOPE_45_UP) // 0x610
    Metatile("COL1_X_SLOPE_45_DOWN",    TILE(0x183, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x01a, COL1_PAL, H, 0), TILE(0x182, COL1_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL1_X_SLOPE_45_UP_UD",   TILE(0x182, COL1_PAL, 0, V), TILE(0x01a, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x183, COL1_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL1_X_SLOPE_45_DOWN_UD", TILE(0x01a, COL1_PAL, H, V), TILE(0x182, COL1_PAL, H, V), TILE(0x183, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL1_X_22_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x170, COL1_PAL, 0, 0), TILE(0x171, COL1_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL1_X_22_UP_2",          TILE(0x172, COL1_PAL, 0, 0), TILE(0x173, COL1_PAL, 0, 0), TILE(0x019, COL1_PAL, 0, 0), TILE(0x01a, COL1_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("COL1_X_22_DOWN_1",        TILE(0x173, COL1_PAL, H, 0), TILE(0x172, COL1_PAL, H, 0), TILE(0x01a, COL1_PAL, H, 0), TILE(0x019, COL1_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL1_X_22_DOWN_2",        TILE(0x000, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x171, COL1_PAL, H, 0), TILE(0x170, COL1_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL1_X_22_UP_UD_1",       TILE(0x170, COL1_PAL, 0, V), TILE(0x171, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x618
    Metatile("COL1_X_22_UP_UD_2",       TILE(0x019, COL1_PAL, 0, V), TILE(0x01a, COL1_PAL, 0, V), TILE(0x172, COL1_PAL, 0, V), TILE(0x173, COL1_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL1_X_22_DOWN_UD_1",     TILE(0x01a, COL1_PAL, H, V), TILE(0x019, COL1_PAL, H, V), TILE(0x173, COL1_PAL, H, V), TILE(0x172, COL1_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL1_X_22_DOWN_UD_2",     TILE(0x171, COL1_PAL, H, V), TILE(0x170, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL1_X_66_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x181, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x191, COL1_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL1_X_66_UP_2",          TILE(0x180, COL1_PAL, H, 0), TILE(0x01c, COL1_PAL, 0, 0), TILE(0x190, COL1_PAL, H, 0), TILE(0x01a, COL1_PAL, 0, 0), COL_SLOPE_66_UP_2)
    Metatile("COL1_X_66_DOWN_1",        TILE(0x01c, COL1_PAL, H, 0), TILE(0x180, COL1_PAL, 0, 0), TILE(0x01a, COL1_PAL, H, 0), TILE(0x190, COL1_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL1_X_66_DOWN_2",        TILE(0x181, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x191, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL1_X_66_UP_UD_1",       TILE(0x000, COL1_PAL, 0, V), TILE(0x191, COL1_PAL, H, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x181, COL1_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x620
    Metatile("COL1_X_66_UP_UD_2",       TILE(0x190, COL1_PAL, H, V), TILE(0x01a, COL1_PAL, 0, V), TILE(0x180, COL1_PAL, H, V), TILE(0x01c, COL1_PAL, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL1_X_66_DOWN_UD_1",     TILE(0x01a, COL1_PAL, H, V), TILE(0x190, COL1_PAL, 0, V), TILE(0x01c, COL1_PAL, H, V), TILE(0x180, COL1_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL1_X_66_DOWN_UD_2",     TILE(0x191, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x181, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x628
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL1_X_NO_OUT_SLOPE_45_UP",      TILE(0x000, COL1_PAL, 0, 0), TILE(0x18f, COL1_PAL, 0, 0), TILE(0x18e, COL1_PAL, 0, 0), TILE(0x01a, COL1_PAL, 0, 0), COL_NONE) // 0x630
    Metatile("COL1_X_NO_OUT_SLOPE_45_DOWN",    TILE(0x18f, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x01a, COL1_PAL, H, 0), TILE(0x18e, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_X_NO_OUT_SLOPE_45_UP_UD",   TILE(0x18e, COL1_PAL, 0, V), TILE(0x01a, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x18f, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_X_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x01a, COL1_PAL, H, V), TILE(0x18e, COL1_PAL, H, V), TILE(0x18f, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_NONE) 
    Metatile("COL1_X_NO_OUT_22_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x17c, COL1_PAL, 0, 0), TILE(0x17d, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_X_NO_OUT_22_UP_2",          TILE(0x17e, COL1_PAL, 0, 0), TILE(0x17f, COL1_PAL, 0, 0), TILE(0x019, COL1_PAL, 0, 0), TILE(0x01a, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_X_NO_OUT_22_DOWN_1",        TILE(0x17f, COL1_PAL, H, 0), TILE(0x17e, COL1_PAL, H, 0), TILE(0x01a, COL1_PAL, H, 0), TILE(0x019, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_X_NO_OUT_22_DOWN_2",        TILE(0x000, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x17d, COL1_PAL, H, 0), TILE(0x17c, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_X_NO_OUT_22_UP_UD_1",       TILE(0x17c, COL1_PAL, 0, V), TILE(0x17d, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), COL_NONE) // 0x638
    Metatile("COL1_X_NO_OUT_22_UP_UD_2",       TILE(0x019, COL1_PAL, 0, V), TILE(0x01a, COL1_PAL, 0, V), TILE(0x17e, COL1_PAL, 0, V), TILE(0x17f, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_X_NO_OUT_22_DOWN_UD_1",     TILE(0x01a, COL1_PAL, H, V), TILE(0x019, COL1_PAL, H, V), TILE(0x17f, COL1_PAL, H, V), TILE(0x17e, COL1_PAL, H, V), COL_NONE)
    Metatile("COL1_X_NO_OUT_22_DOWN_UD_2",     TILE(0x17d, COL1_PAL, H, V), TILE(0x17c, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_NONE)
    Metatile("COL1_X_NO_OUT_66_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x18d, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x19d, COL1_PAL, H, 0), COL_NONE) 
    Metatile("COL1_X_NO_OUT_66_UP_2",          TILE(0x18c, COL1_PAL, H, 0), TILE(0x01c, COL1_PAL, 0, 0), TILE(0x19c, COL1_PAL, H, 0), TILE(0x01a, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_X_NO_OUT_66_DOWN_1",        TILE(0x01c, COL1_PAL, H, 0), TILE(0x18c, COL1_PAL, 0, 0), TILE(0x01a, COL1_PAL, H, 0), TILE(0x19c, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_X_NO_OUT_66_DOWN_2",        TILE(0x18d, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x19d, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_X_NO_OUT_66_UP_UD_1",       TILE(0x000, COL1_PAL, 0, V), TILE(0x19d, COL1_PAL, H, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x18d, COL1_PAL, H, V), COL_NONE) // 0x640
    Metatile("COL1_X_NO_OUT_66_UP_UD_2",       TILE(0x19c, COL1_PAL, H, V), TILE(0x01a, COL1_PAL, 0, V), TILE(0x18c, COL1_PAL, H, V), TILE(0x01c, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_X_NO_OUT_66_DOWN_UD_1",     TILE(0x01a, COL1_PAL, H, V), TILE(0x19c, COL1_PAL, 0, V), TILE(0x01c, COL1_PAL, H, V), TILE(0x18c, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_X_NO_OUT_66_DOWN_UD_2",     TILE(0x19d, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x18d, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x648
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    
    Metatile("COL1_+_SLOPE_45_UP",      TILE(0x000, COL1_PAL, 0, 0), TILE(0x177, COL1_PAL, 0, 0), TILE(0x176, COL1_PAL, 0, 0), TILE(0x031, COL1_PAL, 0, 0), COL_SLOPE_45_UP) // 0x650
    Metatile("COL1_+_SLOPE_45_DOWN",    TILE(0x177, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x031, COL1_PAL, H, 0), TILE(0x176, COL1_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL1_+_SLOPE_45_UP_UD",   TILE(0x176, COL1_PAL, 0, V), TILE(0x031, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x177, COL1_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL1_+_SLOPE_45_DOWN_UD", TILE(0x031, COL1_PAL, H, V), TILE(0x176, COL1_PAL, H, V), TILE(0x177, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL1_+_22_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x184, COL1_PAL, 0, 0), TILE(0x185, COL1_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL1_+_22_UP_2",          TILE(0x186, COL1_PAL, 0, 0), TILE(0x187, COL1_PAL, 0, 0), TILE(0x030, COL1_PAL, 0, 0), TILE(0x031, COL1_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("COL1_+_22_DOWN_1",        TILE(0x187, COL1_PAL, H, 0), TILE(0x186, COL1_PAL, H, 0), TILE(0x031, COL1_PAL, H, 0), TILE(0x030, COL1_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL1_+_22_DOWN_2",        TILE(0x000, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x185, COL1_PAL, H, 0), TILE(0x184, COL1_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL1_+_22_UP_UD_1",       TILE(0x184, COL1_PAL, 0, V), TILE(0x185, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x658
    Metatile("COL1_+_22_UP_UD_2",       TILE(0x030, COL1_PAL, 0, V), TILE(0x031, COL1_PAL, 0, V), TILE(0x186, COL1_PAL, 0, V), TILE(0x187, COL1_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL1_+_22_DOWN_UD_1",     TILE(0x031, COL1_PAL, H, V), TILE(0x030, COL1_PAL, H, V), TILE(0x187, COL1_PAL, H, V), TILE(0x186, COL1_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL1_+_22_DOWN_UD_2",     TILE(0x185, COL1_PAL, H, V), TILE(0x184, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL1_+_66_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x188, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x198, COL1_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL1_+_66_UP_2",          TILE(0x189, COL1_PAL, H, 0), TILE(0x035, COL1_PAL, H, 0), TILE(0x199, COL1_PAL, H, 0), TILE(0x030, COL1_PAL, H, 0), COL_SLOPE_66_UP_2)
    Metatile("COL1_+_66_DOWN_1",        TILE(0x035, COL1_PAL, 0, 0), TILE(0x189, COL1_PAL, 0, 0), TILE(0x030, COL1_PAL, 0, 0), TILE(0x199, COL1_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL1_+_66_DOWN_2",        TILE(0x188, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x198, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL1_+_66_UP_UD_1",       TILE(0x000, COL1_PAL, 0, V), TILE(0x198, COL1_PAL, H, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x188, COL1_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x660
    Metatile("COL1_+_66_UP_UD_2",       TILE(0x199, COL1_PAL, H, V), TILE(0x030, COL1_PAL, H, V), TILE(0x189, COL1_PAL, H, V), TILE(0x035, COL1_PAL, H, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL1_+_66_DOWN_UD_1",     TILE(0x030, COL1_PAL, 0, V), TILE(0x199, COL1_PAL, 0, V), TILE(0x035, COL1_PAL, 0, V), TILE(0x189, COL1_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL1_+_66_DOWN_UD_2",     TILE(0x198, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x188, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x668
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL1_+_NO_OUT_SLOPE_45_UP",      TILE(0x000, COL1_PAL, 0, 0), TILE(0x193, COL1_PAL, 0, 0), TILE(0x192, COL1_PAL, 0, 0), TILE(0x031, COL1_PAL, 0, 0), COL_NONE) // 0x670
    Metatile("COL1_+_NO_OUT_SLOPE_45_DOWN",    TILE(0x193, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x031, COL1_PAL, H, 0), TILE(0x192, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_+_NO_OUT_SLOPE_45_UP_UD",   TILE(0x192, COL1_PAL, 0, V), TILE(0x031, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x193, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_+_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x031, COL1_PAL, H, V), TILE(0x192, COL1_PAL, H, V), TILE(0x193, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_NONE) 
    Metatile("COL1_+_NO_OUT_22_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x194, COL1_PAL, 0, 0), TILE(0x195, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_+_NO_OUT_22_UP_2",          TILE(0x196, COL1_PAL, 0, 0), TILE(0x197, COL1_PAL, 0, 0), TILE(0x030, COL1_PAL, 0, 0), TILE(0x031, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_+_NO_OUT_22_DOWN_1",        TILE(0x197, COL1_PAL, H, 0), TILE(0x196, COL1_PAL, H, 0), TILE(0x031, COL1_PAL, H, 0), TILE(0x030, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_+_NO_OUT_22_DOWN_2",        TILE(0x000, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x195, COL1_PAL, H, 0), TILE(0x194, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_+_NO_OUT_22_UP_UD_1",       TILE(0x194, COL1_PAL, 0, V), TILE(0x195, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), COL_NONE) // 0x678
    Metatile("COL1_+_NO_OUT_22_UP_UD_2",       TILE(0x030, COL1_PAL, 0, V), TILE(0x031, COL1_PAL, 0, V), TILE(0x196, COL1_PAL, 0, V), TILE(0x197, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_+_NO_OUT_22_DOWN_UD_1",     TILE(0x031, COL1_PAL, H, V), TILE(0x030, COL1_PAL, H, V), TILE(0x197, COL1_PAL, H, V), TILE(0x196, COL1_PAL, H, V), COL_NONE)
    Metatile("COL1_+_NO_OUT_22_DOWN_UD_2",     TILE(0x195, COL1_PAL, H, V), TILE(0x194, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_NONE)
    Metatile("COL1_+_NO_OUT_66_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x18a, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x19a, COL1_PAL, H, 0), COL_NONE) 
    Metatile("COL1_+_NO_OUT_66_UP_2",          TILE(0x18b, COL1_PAL, H, 0), TILE(0x035, COL1_PAL, H, 0), TILE(0x19b, COL1_PAL, H, 0), TILE(0x030, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_+_NO_OUT_66_DOWN_1",        TILE(0x035, COL1_PAL, 0, 0), TILE(0x18b, COL1_PAL, 0, 0), TILE(0x030, COL1_PAL, 0, 0), TILE(0x19b, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_+_NO_OUT_66_DOWN_2",        TILE(0x18a, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x19a, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_+_NO_OUT_66_UP_UD_1",       TILE(0x000, COL1_PAL, 0, V), TILE(0x19a, COL1_PAL, H, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x18a, COL1_PAL, H, V), COL_NONE) // 0x680
    Metatile("COL1_+_NO_OUT_66_UP_UD_2",       TILE(0x19b, COL1_PAL, H, V), TILE(0x030, COL1_PAL, H, V), TILE(0x18b, COL1_PAL, H, V), TILE(0x035, COL1_PAL, H, V), COL_NONE)
    Metatile("COL1_+_NO_OUT_66_DOWN_UD_1",     TILE(0x030, COL1_PAL, 0, V), TILE(0x19b, COL1_PAL, 0, V), TILE(0x035, COL1_PAL, 0, V), TILE(0x18b, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_+_NO_OUT_66_DOWN_UD_2",     TILE(0x19a, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x18a, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), COL_NONE)


    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x688
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("COL1_BRICKS_SLOPE_45_UP",      TILE(0x000, COL1_PAL, 0, 0), TILE(0x19f, COL1_PAL, 0, 0), TILE(0x19e, COL1_PAL, 0, 0), TILE(0x044, COL1_PAL, 0, 0), COL_SLOPE_45_UP) // 0x690
    Metatile("COL1_BRICKS_SLOPE_45_DOWN",    TILE(0x19f, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x044, COL1_PAL, H, 0), TILE(0x19e, COL1_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL1_BRICKS_SLOPE_45_UP_UD",   TILE(0x19e, COL1_PAL, 0, V), TILE(0x044, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x19f, COL1_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL1_BRICKS_SLOPE_45_DOWN_UD", TILE(0x044, COL1_PAL, H, V), TILE(0x19e, COL1_PAL, H, V), TILE(0x19f, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL1_BRICKS_22_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1ac, COL1_PAL, 0, 0), TILE(0x1ad, COL1_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL1_BRICKS_22_UP_2",          TILE(0x1ae, COL1_PAL, 0, 0), TILE(0x1af, COL1_PAL, 0, 0), TILE(0x043, COL1_PAL, 0, 0), TILE(0x044, COL1_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("COL1_BRICKS_22_DOWN_1",        TILE(0x1af, COL1_PAL, H, 0), TILE(0x1ae, COL1_PAL, H, 0), TILE(0x044, COL1_PAL, H, 0), TILE(0x043, COL1_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL1_BRICKS_22_DOWN_2",        TILE(0x000, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x1ad, COL1_PAL, H, 0), TILE(0x1ac, COL1_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL1_BRICKS_22_UP_UD_1",       TILE(0x1ac, COL1_PAL, 0, V), TILE(0x1ad, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x698
    Metatile("COL1_BRICKS_22_UP_UD_2",       TILE(0x043, COL1_PAL, 0, V), TILE(0x044, COL1_PAL, 0, V), TILE(0x1ae, COL1_PAL, 0, V), TILE(0x1af, COL1_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL1_BRICKS_22_DOWN_UD_1",     TILE(0x044, COL1_PAL, H, V), TILE(0x043, COL1_PAL, H, V), TILE(0x1af, COL1_PAL, H, V), TILE(0x1ae, COL1_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL1_BRICKS_22_DOWN_UD_2",     TILE(0x1ad, COL1_PAL, H, V), TILE(0x1ac, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL1_BRICKS_66_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x1be, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1bf, COL1_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL1_BRICKS_66_UP_2",          TILE(0x1bc, COL1_PAL, H, 0), TILE(0x044, COL1_PAL, H, 0), TILE(0x1bd, COL1_PAL, H, 0), TILE(0x043, COL1_PAL, H, 0), COL_SLOPE_66_UP_2)
    Metatile("COL1_BRICKS_66_DOWN_1",        TILE(0x044, COL1_PAL, 0, 0), TILE(0x1bc, COL1_PAL, 0, 0), TILE(0x043, COL1_PAL, 0, 0), TILE(0x1bd, COL1_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL1_BRICKS_66_DOWN_2",        TILE(0x1be, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1bf, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL1_BRICKS_66_UP_UD_1",       TILE(0x000, COL1_PAL, 0, V), TILE(0x1bf, COL1_PAL, H, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x1be, COL1_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x6a0
    Metatile("COL1_BRICKS_66_UP_UD_2",       TILE(0x1bd, COL1_PAL, H, V), TILE(0x043, COL1_PAL, H, V), TILE(0x1bc, COL1_PAL, H, V), TILE(0x044, COL1_PAL, H, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL1_BRICKS_66_DOWN_UD_1",     TILE(0x043, COL1_PAL, 0, V), TILE(0x1bd, COL1_PAL, 0, V), TILE(0x044, COL1_PAL, 0, V), TILE(0x1bc, COL1_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL1_BRICKS_66_DOWN_UD_2",     TILE(0x1bf, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x1be, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x6a8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL1_BRICKS_NO_OUT_SLOPE_45_UP",      TILE(0x000, COL1_PAL, 0, 0), TILE(0x1ab, COL1_PAL, 0, 0), TILE(0x1aa, COL1_PAL, 0, 0), TILE(0x044, COL1_PAL, 0, 0), COL_NONE) // 0x6b0
    Metatile("COL1_BRICKS_NO_OUT_SLOPE_45_DOWN",    TILE(0x1ab, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x044, COL1_PAL, H, 0), TILE(0x1aa, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_BRICKS_NO_OUT_SLOPE_45_UP_UD",   TILE(0x1aa, COL1_PAL, 0, V), TILE(0x044, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x1ab, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_BRICKS_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x044, COL1_PAL, H, V), TILE(0x1aa, COL1_PAL, H, V), TILE(0x1ab, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_NONE) 
    Metatile("COL1_BRICKS_NO_OUT_22_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1ba, COL1_PAL, 0, 0), TILE(0x1bb, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_BRICKS_NO_OUT_22_UP_2",          TILE(0x1a8, COL1_PAL, 0, 0), TILE(0x1a9, COL1_PAL, 0, 0), TILE(0x043, COL1_PAL, 0, 0), TILE(0x044, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_BRICKS_NO_OUT_22_DOWN_1",        TILE(0x1a9, COL1_PAL, H, 0), TILE(0x1a8, COL1_PAL, H, 0), TILE(0x044, COL1_PAL, H, 0), TILE(0x043, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_BRICKS_NO_OUT_22_DOWN_2",        TILE(0x000, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x1bb, COL1_PAL, H, 0), TILE(0x1ba, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_BRICKS_NO_OUT_22_UP_UD_1",       TILE(0x1ba, COL1_PAL, 0, V), TILE(0x1bb, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), COL_NONE) // 0x6b8
    Metatile("COL1_BRICKS_NO_OUT_22_UP_UD_2",       TILE(0x043, COL1_PAL, 0, V), TILE(0x044, COL1_PAL, 0, V), TILE(0x1a8, COL1_PAL, 0, V), TILE(0x1a9, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_BRICKS_NO_OUT_22_DOWN_UD_1",     TILE(0x044, COL1_PAL, H, V), TILE(0x043, COL1_PAL, H, V), TILE(0x1a9, COL1_PAL, H, V), TILE(0x1a8, COL1_PAL, H, V), COL_NONE)
    Metatile("COL1_BRICKS_NO_OUT_22_DOWN_UD_2",     TILE(0x1bb, COL1_PAL, H, V), TILE(0x1ba, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_NONE)
    Metatile("COL1_BRICKS_NO_OUT_66_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x1a7, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1b7, COL1_PAL, H, 0), COL_NONE) 
    Metatile("COL1_BRICKS_NO_OUT_66_UP_2",          TILE(0x1b8, COL1_PAL, H, 0), TILE(0x044, COL1_PAL, H, 0), TILE(0x1b9, COL1_PAL, H, 0), TILE(0x043, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_BRICKS_NO_OUT_66_DOWN_1",        TILE(0x044, COL1_PAL, 0, 0), TILE(0x1b8, COL1_PAL, 0, 0), TILE(0x043, COL1_PAL, 0, 0), TILE(0x1b9, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_BRICKS_NO_OUT_66_DOWN_2",        TILE(0x1a7, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1b7, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_BRICKS_NO_OUT_66_UP_UD_1",       TILE(0x000, COL1_PAL, 0, V), TILE(0x1b7, COL1_PAL, H, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x1a7, COL1_PAL, H, V), COL_NONE) // 0x6c0
    Metatile("COL1_BRICKS_NO_OUT_66_UP_UD_2",       TILE(0x1b9, COL1_PAL, H, V), TILE(0x043, COL1_PAL, H, V), TILE(0x1b8, COL1_PAL, H, V), TILE(0x044, COL1_PAL, H, V), COL_NONE)
    Metatile("COL1_BRICKS_NO_OUT_66_DOWN_UD_1",     TILE(0x043, COL1_PAL, 0, V), TILE(0x1b9, COL1_PAL, 0, V), TILE(0x044, COL1_PAL, 0, V), TILE(0x1b8, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_BRICKS_NO_OUT_66_DOWN_UD_2",     TILE(0x1b7, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x1a7, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x6c8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("COL1_BLK_SLOPE_45_UP",      TILE(0x000, COL1_PAL, 0, 0), TILE(0x1c5, COL1_PAL, 0, 0), TILE(0x1c5, COL1_PAL, 0, 0), TILE(0x03a, COL1_PAL, 0, 0), COL_NONE) // 0x670
    Metatile("COL1_BLK_SLOPE_45_DOWN",    TILE(0x1c5, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x03a, COL1_PAL, H, 0), TILE(0x1c5, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_BLK_SLOPE_45_UP_UD",   TILE(0x1c5, COL1_PAL, 0, V), TILE(0x03a, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x1c5, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_BLK_SLOPE_45_DOWN_UD", TILE(0x03a, COL1_PAL, H, V), TILE(0x1c5, COL1_PAL, H, V), TILE(0x1c5, COL1_PAL, H, V), TILE(0x000, COL1_PAL, 0, V), COL_NONE) 
    Metatile("COL1_BLK_22_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1c6, COL1_PAL, 0, 0), TILE(0x1c7, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_BLK_22_UP_2",          TILE(0x1c6, COL1_PAL, 0, 0), TILE(0x1c7, COL1_PAL, 0, 0), TILE(0x03a, COL1_PAL, 0, 0), TILE(0x03a, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_BLK_22_DOWN_1",        TILE(0x1c7, COL1_PAL, H, 0), TILE(0x1c6, COL1_PAL, H, 0), TILE(0x03a, COL1_PAL, H, 0), TILE(0x03a, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_BLK_22_DOWN_2",        TILE(0x000, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x1c7, COL1_PAL, H, 0), TILE(0x1c6, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_BLK_22_UP_UD_1",       TILE(0x1c6, COL1_PAL, 0, V), TILE(0x1c7, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), COL_NONE) // 0x678
    Metatile("COL1_BLK_22_UP_UD_2",       TILE(0x03a, COL1_PAL, 0, V), TILE(0x03a, COL1_PAL, 0, V), TILE(0x1c6, COL1_PAL, 0, V), TILE(0x1c7, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_BLK_22_DOWN_UD_1",     TILE(0x03a, COL1_PAL, H, V), TILE(0x03a, COL1_PAL, H, V), TILE(0x1c7, COL1_PAL, H, V), TILE(0x1c6, COL1_PAL, H, V), COL_NONE)
    Metatile("COL1_BLK_22_DOWN_UD_2",     TILE(0x1c7, COL1_PAL, H, V), TILE(0x1c6, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_NONE)
    Metatile("COL1_BLK_66_UP_1",          TILE(0x000, COL1_PAL, 0, 0), TILE(0x1c9, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1c8, COL1_PAL, 0, 0), COL_NONE) 
    Metatile("COL1_BLK_66_UP_2",          TILE(0x1c9, COL1_PAL, 0, 0), TILE(0x03a, COL1_PAL, 0, 0), TILE(0x1c8, COL1_PAL, 0, 0), TILE(0x03a, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_BLK_66_DOWN_1",        TILE(0x03a, COL1_PAL, H, 0), TILE(0x1c9, COL1_PAL, H, 0), TILE(0x03a, COL1_PAL, H, 0), TILE(0x1c8, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_BLK_66_DOWN_2",        TILE(0x1c9, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), TILE(0x1c8, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, H, 0), COL_NONE)
    Metatile("COL1_BLK_66_UP_UD_1",       TILE(0x000, COL1_PAL, 0, V), TILE(0x1c8, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, V), TILE(0x1c9, COL1_PAL, 0, V), COL_NONE) // 0x680
    Metatile("COL1_BLK_66_UP_UD_2",       TILE(0x1c8, COL1_PAL, 0, V), TILE(0x03a, COL1_PAL, 0, V), TILE(0x1c9, COL1_PAL, 0, V), TILE(0x03a, COL1_PAL, 0, V), COL_NONE)
    Metatile("COL1_BLK_66_DOWN_UD_1",     TILE(0x03a, COL1_PAL, H, V), TILE(0x1c8, COL1_PAL, H, V), TILE(0x03a, COL1_PAL, H, V), TILE(0x1c9, COL1_PAL, H, V), COL_NONE)
    Metatile("COL1_BLK_66_DOWN_UD_2",     TILE(0x1c8, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), TILE(0x1c9, COL1_PAL, H, V), TILE(0x000, COL1_PAL, H, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x688
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    // COL 2 SLOPES

    
    Metatile("COL2_CHKRED_SLOPE_45_UP",      TILE(0x000, COL2_PAL, 0, 0), TILE(0x1a2, COL2_PAL, 0, 0), TILE(0x1b2, COL2_PAL, 0, 0), TILE(0x007, COL2_PAL, 0, 0), COL_SLOPE_45_UP) // 0x5d0
    Metatile("COL2_CHKRED_SLOPE_45_DOWN",    TILE(0x1a2, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x007, COL2_PAL, H, 0), TILE(0x1b2, COL2_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL2_CHKRED_SLOPE_45_UP_UD",   TILE(0x1b2, COL2_PAL, 0, V), TILE(0x007, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x1a2, COL2_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL2_CHKRED_SLOPE_45_DOWN_UD", TILE(0x007, COL2_PAL, H, V), TILE(0x1b2, COL2_PAL, H, V), TILE(0x1a2, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL2_CHKRED_22_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1b3, COL2_PAL, 0, 0), TILE(0x1b4, COL2_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL2_CHKRED_22_UP_2",          TILE(0x1a3, COL2_PAL, 0, 0), TILE(0x1a4, COL2_PAL, 0, 0), TILE(0x003, COL2_PAL, 0, 0), TILE(0x003, COL2_PAL, H, 0), COL_SLOPE_22_UP_2)
    Metatile("COL2_CHKRED_22_DOWN_1",        TILE(0x1a4, COL2_PAL, H, 0), TILE(0x1a3, COL2_PAL, H, 0), TILE(0x003, COL2_PAL, 0, 0), TILE(0x003, COL2_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL2_CHKRED_22_DOWN_2",        TILE(0x000, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x1b4, COL2_PAL, H, 0), TILE(0x1b3, COL2_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL2_CHKRED_22_UP_UD_1",       TILE(0x1b3, COL2_PAL, 0, V), TILE(0x1b4, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x5d8
    Metatile("COL2_CHKRED_22_UP_UD_2",       TILE(0x003, COL2_PAL, 0, V), TILE(0x003, COL2_PAL, H, V), TILE(0x1a3, COL2_PAL, 0, V), TILE(0x1a4, COL2_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL2_CHKRED_22_DOWN_UD_1",     TILE(0x003, COL2_PAL, 0, V), TILE(0x003, COL2_PAL, H, V), TILE(0x1a4, COL2_PAL, H, V), TILE(0x1a3, COL2_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL2_CHKRED_22_DOWN_UD_2",     TILE(0x1b4, COL2_PAL, H, V), TILE(0x1b3, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL2_CHKRED_66_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x1a6, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1b6, COL2_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL2_CHKRED_66_UP_2",          TILE(0x1a5, COL2_PAL, H, 0), TILE(0x005, COL2_PAL, 0, 0), TILE(0x1b5, COL2_PAL, H, 0), TILE(0x005, COL2_PAL, 0, V), COL_SLOPE_66_UP_2)
    Metatile("COL2_CHKRED_66_DOWN_1",        TILE(0x005, COL2_PAL, H, 0), TILE(0x1a5, COL2_PAL, 0, 0), TILE(0x005, COL2_PAL, H, V), TILE(0x1b5, COL2_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL2_CHKRED_66_DOWN_2",        TILE(0x1a6, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1b6, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL2_CHKRED_66_UP_UD_1",       TILE(0x000, COL2_PAL, 0, 0), TILE(0x1b6, COL2_PAL, H, V), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1a6, COL2_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x5e0
    Metatile("COL2_CHKRED_66_UP_UD_2",       TILE(0x1b5, COL2_PAL, H, V), TILE(0x005, COL2_PAL, 0, 0), TILE(0x1a5, COL2_PAL, H, V), TILE(0x005, COL2_PAL, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL2_CHKRED_66_DOWN_UD_1",     TILE(0x005, COL2_PAL, H, 0), TILE(0x1b5, COL2_PAL, 0, V), TILE(0x005, COL2_PAL, H, V), TILE(0x1a5, COL2_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL2_CHKRED_66_DOWN_UD_2",     TILE(0x1b6, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1a6, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, 0), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x5e8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL2_CHKRED_NO_OUT_SLOPE_45_UP",      TILE(0x000, COL2_PAL, 0, 0), TILE(0x1c0, COL2_PAL, 0, 0), TILE(0x1d0, COL2_PAL, 0, 0), TILE(0x007, COL2_PAL, 0, 0), COL_NONE) // 0x5f0
    Metatile("COL2_CHKRED_NO_OUT_SLOPE_45_DOWN",    TILE(0x1c0, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x007, COL2_PAL, H, 0), TILE(0x1d0, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_CHKRED_NO_OUT_SLOPE_45_UP_UD",   TILE(0x1d0, COL2_PAL, 0, V), TILE(0x007, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x1c0, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_CHKRED_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x007, COL2_PAL, H, V), TILE(0x1d0, COL2_PAL, H, V), TILE(0x1c0, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_NONE) 
    Metatile("COL2_CHKRED_NO_OUT_22_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1b0, COL2_PAL, 0, 0), TILE(0x1b1, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_CHKRED_NO_OUT_22_UP_2",          TILE(0x1a0, COL2_PAL, 0, 0), TILE(0x1a1, COL2_PAL, 0, 0), TILE(0x003, COL2_PAL, 0, 0), TILE(0x003, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_CHKRED_NO_OUT_22_DOWN_1",        TILE(0x1a1, COL2_PAL, H, 0), TILE(0x1a0, COL2_PAL, H, 0), TILE(0x003, COL2_PAL, 0, 0), TILE(0x003, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_CHKRED_NO_OUT_22_DOWN_2",        TILE(0x000, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x1b1, COL2_PAL, H, 0), TILE(0x1b0, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_CHKRED_NO_OUT_22_UP_UD_1",       TILE(0x1b0, COL2_PAL, 0, V), TILE(0x1b1, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), COL_NONE) // 0x5f8
    Metatile("COL2_CHKRED_NO_OUT_22_UP_UD_2",       TILE(0x003, COL2_PAL, 0, V), TILE(0x003, COL2_PAL, H, V), TILE(0x1a0, COL2_PAL, 0, V), TILE(0x1a1, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_CHKRED_NO_OUT_22_DOWN_UD_1",     TILE(0x003, COL2_PAL, 0, V), TILE(0x003, COL2_PAL, H, V), TILE(0x1a1, COL2_PAL, H, V), TILE(0x1a0, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_CHKRED_NO_OUT_22_DOWN_UD_2",     TILE(0x1b1, COL2_PAL, H, V), TILE(0x1b0, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_CHKRED_NO_OUT_66_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x1c1, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1d1, COL2_PAL, H, 0), COL_NONE) 
    Metatile("COL2_CHKRED_NO_OUT_66_UP_2",          TILE(0x1c2, COL2_PAL, H, 0), TILE(0x005, COL2_PAL, 0, 0), TILE(0x1d2, COL2_PAL, H, 0), TILE(0x005, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_CHKRED_NO_OUT_66_DOWN_1",        TILE(0x005, COL2_PAL, H, 0), TILE(0x1c2, COL2_PAL, 0, 0), TILE(0x005, COL2_PAL, H, V), TILE(0x1d2, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_CHKRED_NO_OUT_66_DOWN_2",        TILE(0x1c1, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1d1, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_CHKRED_NO_OUT_66_UP_UD_1",       TILE(0x000, COL2_PAL, 0, 0), TILE(0x1d1, COL2_PAL, H, V), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1c1, COL2_PAL, H, V), COL_NONE) // 0x600
    Metatile("COL2_CHKRED_NO_OUT_66_UP_UD_2",       TILE(0x1d2, COL2_PAL, H, V), TILE(0x005, COL2_PAL, 0, 0), TILE(0x1c2, COL2_PAL, H, V), TILE(0x005, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_CHKRED_NO_OUT_66_DOWN_UD_1",     TILE(0x005, COL2_PAL, H, 0), TILE(0x1d2, COL2_PAL, 0, V), TILE(0x005, COL2_PAL, H, V), TILE(0x1c2, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_CHKRED_NO_OUT_66_DOWN_UD_2",     TILE(0x1d1, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1c1, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, 0), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x608
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("COL2_X_SLOPE_45_UP",      TILE(0x000, COL2_PAL, 0, 0), TILE(0x183, COL2_PAL, 0, 0), TILE(0x182, COL2_PAL, 0, 0), TILE(0x01a, COL2_PAL, 0, 0), COL_SLOPE_45_UP) // 0x610
    Metatile("COL2_X_SLOPE_45_DOWN",    TILE(0x183, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x01a, COL2_PAL, H, 0), TILE(0x182, COL2_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL2_X_SLOPE_45_UP_UD",   TILE(0x182, COL2_PAL, 0, V), TILE(0x01a, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x183, COL2_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL2_X_SLOPE_45_DOWN_UD", TILE(0x01a, COL2_PAL, H, V), TILE(0x182, COL2_PAL, H, V), TILE(0x183, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL2_X_22_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x170, COL2_PAL, 0, 0), TILE(0x171, COL2_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL2_X_22_UP_2",          TILE(0x172, COL2_PAL, 0, 0), TILE(0x173, COL2_PAL, 0, 0), TILE(0x019, COL2_PAL, 0, 0), TILE(0x01a, COL2_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("COL2_X_22_DOWN_1",        TILE(0x173, COL2_PAL, H, 0), TILE(0x172, COL2_PAL, H, 0), TILE(0x01a, COL2_PAL, H, 0), TILE(0x019, COL2_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL2_X_22_DOWN_2",        TILE(0x000, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x171, COL2_PAL, H, 0), TILE(0x170, COL2_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL2_X_22_UP_UD_1",       TILE(0x170, COL2_PAL, 0, V), TILE(0x171, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x618
    Metatile("COL2_X_22_UP_UD_2",       TILE(0x019, COL2_PAL, 0, V), TILE(0x01a, COL2_PAL, 0, V), TILE(0x172, COL2_PAL, 0, V), TILE(0x173, COL2_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL2_X_22_DOWN_UD_1",     TILE(0x01a, COL2_PAL, H, V), TILE(0x019, COL2_PAL, H, V), TILE(0x173, COL2_PAL, H, V), TILE(0x172, COL2_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL2_X_22_DOWN_UD_2",     TILE(0x171, COL2_PAL, H, V), TILE(0x170, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL2_X_66_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x181, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x191, COL2_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL2_X_66_UP_2",          TILE(0x180, COL2_PAL, H, 0), TILE(0x01c, COL2_PAL, 0, 0), TILE(0x190, COL2_PAL, H, 0), TILE(0x01a, COL2_PAL, 0, 0), COL_SLOPE_66_UP_2)
    Metatile("COL2_X_66_DOWN_1",        TILE(0x01c, COL2_PAL, H, 0), TILE(0x180, COL2_PAL, 0, 0), TILE(0x01a, COL2_PAL, H, 0), TILE(0x190, COL2_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL2_X_66_DOWN_2",        TILE(0x181, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x191, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL2_X_66_UP_UD_1",       TILE(0x000, COL2_PAL, 0, V), TILE(0x191, COL2_PAL, H, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x181, COL2_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x620
    Metatile("COL2_X_66_UP_UD_2",       TILE(0x190, COL2_PAL, H, V), TILE(0x01a, COL2_PAL, 0, V), TILE(0x180, COL2_PAL, H, V), TILE(0x01c, COL2_PAL, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL2_X_66_DOWN_UD_1",     TILE(0x01a, COL2_PAL, H, V), TILE(0x190, COL2_PAL, 0, V), TILE(0x01c, COL2_PAL, H, V), TILE(0x180, COL2_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL2_X_66_DOWN_UD_2",     TILE(0x191, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x181, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x628
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL2_X_NO_OUT_SLOPE_45_UP",      TILE(0x000, COL2_PAL, 0, 0), TILE(0x18f, COL2_PAL, 0, 0), TILE(0x18e, COL2_PAL, 0, 0), TILE(0x01a, COL2_PAL, 0, 0), COL_NONE) // 0x630
    Metatile("COL2_X_NO_OUT_SLOPE_45_DOWN",    TILE(0x18f, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x01a, COL2_PAL, H, 0), TILE(0x18e, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_X_NO_OUT_SLOPE_45_UP_UD",   TILE(0x18e, COL2_PAL, 0, V), TILE(0x01a, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x18f, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_X_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x01a, COL2_PAL, H, V), TILE(0x18e, COL2_PAL, H, V), TILE(0x18f, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_NONE) 
    Metatile("COL2_X_NO_OUT_22_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x17c, COL2_PAL, 0, 0), TILE(0x17d, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_X_NO_OUT_22_UP_2",          TILE(0x17e, COL2_PAL, 0, 0), TILE(0x17f, COL2_PAL, 0, 0), TILE(0x019, COL2_PAL, 0, 0), TILE(0x01a, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_X_NO_OUT_22_DOWN_1",        TILE(0x17f, COL2_PAL, H, 0), TILE(0x17e, COL2_PAL, H, 0), TILE(0x01a, COL2_PAL, H, 0), TILE(0x019, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_X_NO_OUT_22_DOWN_2",        TILE(0x000, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x17d, COL2_PAL, H, 0), TILE(0x17c, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_X_NO_OUT_22_UP_UD_1",       TILE(0x17c, COL2_PAL, 0, V), TILE(0x17d, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), COL_NONE) // 0x638
    Metatile("COL2_X_NO_OUT_22_UP_UD_2",       TILE(0x019, COL2_PAL, 0, V), TILE(0x01a, COL2_PAL, 0, V), TILE(0x17e, COL2_PAL, 0, V), TILE(0x17f, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_X_NO_OUT_22_DOWN_UD_1",     TILE(0x01a, COL2_PAL, H, V), TILE(0x019, COL2_PAL, H, V), TILE(0x17f, COL2_PAL, H, V), TILE(0x17e, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_X_NO_OUT_22_DOWN_UD_2",     TILE(0x17d, COL2_PAL, H, V), TILE(0x17c, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_X_NO_OUT_66_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x18d, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x19d, COL2_PAL, H, 0), COL_NONE) 
    Metatile("COL2_X_NO_OUT_66_UP_2",          TILE(0x18c, COL2_PAL, H, 0), TILE(0x01c, COL2_PAL, 0, 0), TILE(0x19c, COL2_PAL, H, 0), TILE(0x01a, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_X_NO_OUT_66_DOWN_1",        TILE(0x01c, COL2_PAL, H, 0), TILE(0x18c, COL2_PAL, 0, 0), TILE(0x01a, COL2_PAL, H, 0), TILE(0x19c, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_X_NO_OUT_66_DOWN_2",        TILE(0x18d, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x19d, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_X_NO_OUT_66_UP_UD_1",       TILE(0x000, COL2_PAL, 0, V), TILE(0x19d, COL2_PAL, H, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x18d, COL2_PAL, H, V), COL_NONE) // 0x640
    Metatile("COL2_X_NO_OUT_66_UP_UD_2",       TILE(0x19c, COL2_PAL, H, V), TILE(0x01a, COL2_PAL, 0, V), TILE(0x18c, COL2_PAL, H, V), TILE(0x01c, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_X_NO_OUT_66_DOWN_UD_1",     TILE(0x01a, COL2_PAL, H, V), TILE(0x19c, COL2_PAL, 0, V), TILE(0x01c, COL2_PAL, H, V), TILE(0x18c, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_X_NO_OUT_66_DOWN_UD_2",     TILE(0x19d, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x18d, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x648
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    
    Metatile("COL2_+_SLOPE_45_UP",      TILE(0x000, COL2_PAL, 0, 0), TILE(0x177, COL2_PAL, 0, 0), TILE(0x176, COL2_PAL, 0, 0), TILE(0x031, COL2_PAL, 0, 0), COL_SLOPE_45_UP) // 0x650
    Metatile("COL2_+_SLOPE_45_DOWN",    TILE(0x177, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x031, COL2_PAL, H, 0), TILE(0x176, COL2_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL2_+_SLOPE_45_UP_UD",   TILE(0x176, COL2_PAL, 0, V), TILE(0x031, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x177, COL2_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL2_+_SLOPE_45_DOWN_UD", TILE(0x031, COL2_PAL, H, V), TILE(0x176, COL2_PAL, H, V), TILE(0x177, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL2_+_22_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x184, COL2_PAL, 0, 0), TILE(0x185, COL2_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL2_+_22_UP_2",          TILE(0x186, COL2_PAL, 0, 0), TILE(0x187, COL2_PAL, 0, 0), TILE(0x030, COL2_PAL, 0, 0), TILE(0x031, COL2_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("COL2_+_22_DOWN_1",        TILE(0x187, COL2_PAL, H, 0), TILE(0x186, COL2_PAL, H, 0), TILE(0x031, COL2_PAL, H, 0), TILE(0x030, COL2_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL2_+_22_DOWN_2",        TILE(0x000, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x185, COL2_PAL, H, 0), TILE(0x184, COL2_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL2_+_22_UP_UD_1",       TILE(0x184, COL2_PAL, 0, V), TILE(0x185, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x658
    Metatile("COL2_+_22_UP_UD_2",       TILE(0x030, COL2_PAL, 0, V), TILE(0x031, COL2_PAL, 0, V), TILE(0x186, COL2_PAL, 0, V), TILE(0x187, COL2_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL2_+_22_DOWN_UD_1",     TILE(0x031, COL2_PAL, H, V), TILE(0x030, COL2_PAL, H, V), TILE(0x187, COL2_PAL, H, V), TILE(0x186, COL2_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL2_+_22_DOWN_UD_2",     TILE(0x185, COL2_PAL, H, V), TILE(0x184, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL2_+_66_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x188, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x198, COL2_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL2_+_66_UP_2",          TILE(0x189, COL2_PAL, H, 0), TILE(0x035, COL2_PAL, H, 0), TILE(0x199, COL2_PAL, H, 0), TILE(0x030, COL2_PAL, H, 0), COL_SLOPE_66_UP_2)
    Metatile("COL2_+_66_DOWN_1",        TILE(0x035, COL2_PAL, 0, 0), TILE(0x189, COL2_PAL, 0, 0), TILE(0x030, COL2_PAL, 0, 0), TILE(0x199, COL2_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL2_+_66_DOWN_2",        TILE(0x188, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x198, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL2_+_66_UP_UD_1",       TILE(0x000, COL2_PAL, 0, V), TILE(0x198, COL2_PAL, H, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x188, COL2_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x660
    Metatile("COL2_+_66_UP_UD_2",       TILE(0x199, COL2_PAL, H, V), TILE(0x030, COL2_PAL, H, V), TILE(0x189, COL2_PAL, H, V), TILE(0x035, COL2_PAL, H, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL2_+_66_DOWN_UD_1",     TILE(0x030, COL2_PAL, 0, V), TILE(0x199, COL2_PAL, 0, V), TILE(0x035, COL2_PAL, 0, V), TILE(0x189, COL2_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL2_+_66_DOWN_UD_2",     TILE(0x198, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x188, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x668
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL2_+_NO_OUT_SLOPE_45_UP",      TILE(0x000, COL2_PAL, 0, 0), TILE(0x193, COL2_PAL, 0, 0), TILE(0x192, COL2_PAL, 0, 0), TILE(0x031, COL2_PAL, 0, 0), COL_NONE) // 0x670
    Metatile("COL2_+_NO_OUT_SLOPE_45_DOWN",    TILE(0x193, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x031, COL2_PAL, H, 0), TILE(0x192, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_+_NO_OUT_SLOPE_45_UP_UD",   TILE(0x192, COL2_PAL, 0, V), TILE(0x031, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x193, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_+_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x031, COL2_PAL, H, V), TILE(0x192, COL2_PAL, H, V), TILE(0x193, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_NONE) 
    Metatile("COL2_+_NO_OUT_22_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x194, COL2_PAL, 0, 0), TILE(0x195, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_+_NO_OUT_22_UP_2",          TILE(0x196, COL2_PAL, 0, 0), TILE(0x197, COL2_PAL, 0, 0), TILE(0x030, COL2_PAL, 0, 0), TILE(0x031, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_+_NO_OUT_22_DOWN_1",        TILE(0x197, COL2_PAL, H, 0), TILE(0x196, COL2_PAL, H, 0), TILE(0x031, COL2_PAL, H, 0), TILE(0x030, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_+_NO_OUT_22_DOWN_2",        TILE(0x000, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x195, COL2_PAL, H, 0), TILE(0x194, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_+_NO_OUT_22_UP_UD_1",       TILE(0x194, COL2_PAL, 0, V), TILE(0x195, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), COL_NONE) // 0x678
    Metatile("COL2_+_NO_OUT_22_UP_UD_2",       TILE(0x030, COL2_PAL, 0, V), TILE(0x031, COL2_PAL, 0, V), TILE(0x196, COL2_PAL, 0, V), TILE(0x197, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_+_NO_OUT_22_DOWN_UD_1",     TILE(0x031, COL2_PAL, H, V), TILE(0x030, COL2_PAL, H, V), TILE(0x197, COL2_PAL, H, V), TILE(0x196, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_+_NO_OUT_22_DOWN_UD_2",     TILE(0x195, COL2_PAL, H, V), TILE(0x194, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_+_NO_OUT_66_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x18a, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x19a, COL2_PAL, H, 0), COL_NONE) 
    Metatile("COL2_+_NO_OUT_66_UP_2",          TILE(0x18b, COL2_PAL, H, 0), TILE(0x035, COL2_PAL, H, 0), TILE(0x19b, COL2_PAL, H, 0), TILE(0x030, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_+_NO_OUT_66_DOWN_1",        TILE(0x035, COL2_PAL, 0, 0), TILE(0x18b, COL2_PAL, 0, 0), TILE(0x030, COL2_PAL, 0, 0), TILE(0x19b, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_+_NO_OUT_66_DOWN_2",        TILE(0x18a, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x19a, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_+_NO_OUT_66_UP_UD_1",       TILE(0x000, COL2_PAL, 0, V), TILE(0x19a, COL2_PAL, H, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x18a, COL2_PAL, H, V), COL_NONE) // 0x680
    Metatile("COL2_+_NO_OUT_66_UP_UD_2",       TILE(0x19b, COL2_PAL, H, V), TILE(0x030, COL2_PAL, H, V), TILE(0x18b, COL2_PAL, H, V), TILE(0x035, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_+_NO_OUT_66_DOWN_UD_1",     TILE(0x030, COL2_PAL, 0, V), TILE(0x19b, COL2_PAL, 0, V), TILE(0x035, COL2_PAL, 0, V), TILE(0x18b, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_+_NO_OUT_66_DOWN_UD_2",     TILE(0x19a, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x18a, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), COL_NONE)


    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x688
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("COL2_BRICKS_SLOPE_45_UP",      TILE(0x000, COL2_PAL, 0, 0), TILE(0x19f, COL2_PAL, 0, 0), TILE(0x19e, COL2_PAL, 0, 0), TILE(0x044, COL2_PAL, 0, 0), COL_SLOPE_45_UP) // 0x690
    Metatile("COL2_BRICKS_SLOPE_45_DOWN",    TILE(0x19f, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x044, COL2_PAL, H, 0), TILE(0x19e, COL2_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL2_BRICKS_SLOPE_45_UP_UD",   TILE(0x19e, COL2_PAL, 0, V), TILE(0x044, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x19f, COL2_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL2_BRICKS_SLOPE_45_DOWN_UD", TILE(0x044, COL2_PAL, H, V), TILE(0x19e, COL2_PAL, H, V), TILE(0x19f, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL2_BRICKS_22_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1ac, COL2_PAL, 0, 0), TILE(0x1ad, COL2_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL2_BRICKS_22_UP_2",          TILE(0x1ae, COL2_PAL, 0, 0), TILE(0x1af, COL2_PAL, 0, 0), TILE(0x043, COL2_PAL, 0, 0), TILE(0x044, COL2_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("COL2_BRICKS_22_DOWN_1",        TILE(0x1af, COL2_PAL, H, 0), TILE(0x1ae, COL2_PAL, H, 0), TILE(0x044, COL2_PAL, H, 0), TILE(0x043, COL2_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL2_BRICKS_22_DOWN_2",        TILE(0x000, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x1ad, COL2_PAL, H, 0), TILE(0x1ac, COL2_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL2_BRICKS_22_UP_UD_1",       TILE(0x1ac, COL2_PAL, 0, V), TILE(0x1ad, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x698
    Metatile("COL2_BRICKS_22_UP_UD_2",       TILE(0x043, COL2_PAL, 0, V), TILE(0x044, COL2_PAL, 0, V), TILE(0x1ae, COL2_PAL, 0, V), TILE(0x1af, COL2_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL2_BRICKS_22_DOWN_UD_1",     TILE(0x044, COL2_PAL, H, V), TILE(0x043, COL2_PAL, H, V), TILE(0x1af, COL2_PAL, H, V), TILE(0x1ae, COL2_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL2_BRICKS_22_DOWN_UD_2",     TILE(0x1ad, COL2_PAL, H, V), TILE(0x1ac, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL2_BRICKS_66_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x1be, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1bf, COL2_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL2_BRICKS_66_UP_2",          TILE(0x1bc, COL2_PAL, H, 0), TILE(0x044, COL2_PAL, H, 0), TILE(0x1bd, COL2_PAL, H, 0), TILE(0x043, COL2_PAL, H, 0), COL_SLOPE_66_UP_2)
    Metatile("COL2_BRICKS_66_DOWN_1",        TILE(0x044, COL2_PAL, 0, 0), TILE(0x1bc, COL2_PAL, 0, 0), TILE(0x043, COL2_PAL, 0, 0), TILE(0x1bd, COL2_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL2_BRICKS_66_DOWN_2",        TILE(0x1be, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1bf, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL2_BRICKS_66_UP_UD_1",       TILE(0x000, COL2_PAL, 0, V), TILE(0x1bf, COL2_PAL, H, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x1be, COL2_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x6a0
    Metatile("COL2_BRICKS_66_UP_UD_2",       TILE(0x1bd, COL2_PAL, H, V), TILE(0x043, COL2_PAL, H, V), TILE(0x1bc, COL2_PAL, H, V), TILE(0x044, COL2_PAL, H, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL2_BRICKS_66_DOWN_UD_1",     TILE(0x043, COL2_PAL, 0, V), TILE(0x1bd, COL2_PAL, 0, V), TILE(0x044, COL2_PAL, 0, V), TILE(0x1bc, COL2_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL2_BRICKS_66_DOWN_UD_2",     TILE(0x1bf, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x1be, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x6a8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL2_BRICKS_NO_OUT_SLOPE_45_UP",      TILE(0x000, COL2_PAL, 0, 0), TILE(0x1ab, COL2_PAL, 0, 0), TILE(0x1aa, COL2_PAL, 0, 0), TILE(0x044, COL2_PAL, 0, 0), COL_NONE) // 0x6b0
    Metatile("COL2_BRICKS_NO_OUT_SLOPE_45_DOWN",    TILE(0x1ab, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x044, COL2_PAL, H, 0), TILE(0x1aa, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_BRICKS_NO_OUT_SLOPE_45_UP_UD",   TILE(0x1aa, COL2_PAL, 0, V), TILE(0x044, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x1ab, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_BRICKS_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x044, COL2_PAL, H, V), TILE(0x1aa, COL2_PAL, H, V), TILE(0x1ab, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_NONE) 
    Metatile("COL2_BRICKS_NO_OUT_22_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1ba, COL2_PAL, 0, 0), TILE(0x1bb, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_BRICKS_NO_OUT_22_UP_2",          TILE(0x1a8, COL2_PAL, 0, 0), TILE(0x1a9, COL2_PAL, 0, 0), TILE(0x043, COL2_PAL, 0, 0), TILE(0x044, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_BRICKS_NO_OUT_22_DOWN_1",        TILE(0x1a9, COL2_PAL, H, 0), TILE(0x1a8, COL2_PAL, H, 0), TILE(0x044, COL2_PAL, H, 0), TILE(0x043, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_BRICKS_NO_OUT_22_DOWN_2",        TILE(0x000, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x1bb, COL2_PAL, H, 0), TILE(0x1ba, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_BRICKS_NO_OUT_22_UP_UD_1",       TILE(0x1ba, COL2_PAL, 0, V), TILE(0x1bb, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), COL_NONE) // 0x6b8
    Metatile("COL2_BRICKS_NO_OUT_22_UP_UD_2",       TILE(0x043, COL2_PAL, 0, V), TILE(0x044, COL2_PAL, 0, V), TILE(0x1a8, COL2_PAL, 0, V), TILE(0x1a9, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_BRICKS_NO_OUT_22_DOWN_UD_1",     TILE(0x044, COL2_PAL, H, V), TILE(0x043, COL2_PAL, H, V), TILE(0x1a9, COL2_PAL, H, V), TILE(0x1a8, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_BRICKS_NO_OUT_22_DOWN_UD_2",     TILE(0x1bb, COL2_PAL, H, V), TILE(0x1ba, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_BRICKS_NO_OUT_66_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x1a7, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1b7, COL2_PAL, H, 0), COL_NONE) 
    Metatile("COL2_BRICKS_NO_OUT_66_UP_2",          TILE(0x1b8, COL2_PAL, H, 0), TILE(0x044, COL2_PAL, H, 0), TILE(0x1b9, COL2_PAL, H, 0), TILE(0x043, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_BRICKS_NO_OUT_66_DOWN_1",        TILE(0x044, COL2_PAL, 0, 0), TILE(0x1b8, COL2_PAL, 0, 0), TILE(0x043, COL2_PAL, 0, 0), TILE(0x1b9, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_BRICKS_NO_OUT_66_DOWN_2",        TILE(0x1a7, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1b7, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_BRICKS_NO_OUT_66_UP_UD_1",       TILE(0x000, COL2_PAL, 0, V), TILE(0x1b7, COL2_PAL, H, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x1a7, COL2_PAL, H, V), COL_NONE) // 0x6c0
    Metatile("COL2_BRICKS_NO_OUT_66_UP_UD_2",       TILE(0x1b9, COL2_PAL, H, V), TILE(0x043, COL2_PAL, H, V), TILE(0x1b8, COL2_PAL, H, V), TILE(0x044, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_BRICKS_NO_OUT_66_DOWN_UD_1",     TILE(0x043, COL2_PAL, 0, V), TILE(0x1b9, COL2_PAL, 0, V), TILE(0x044, COL2_PAL, 0, V), TILE(0x1b8, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_BRICKS_NO_OUT_66_DOWN_UD_2",     TILE(0x1b7, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x1a7, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x6c8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("COL2_BLK_SLOPE_45_UP",      TILE(0x000, COL2_PAL, 0, 0), TILE(0x1c5, COL2_PAL, 0, 0), TILE(0x1c5, COL2_PAL, 0, 0), TILE(0x03a, COL2_PAL, 0, 0), COL_NONE) // 0x670
    Metatile("COL2_BLK_SLOPE_45_DOWN",    TILE(0x1c5, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x03a, COL2_PAL, H, 0), TILE(0x1c5, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_BLK_SLOPE_45_UP_UD",   TILE(0x1c5, COL2_PAL, 0, V), TILE(0x03a, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x1c5, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_BLK_SLOPE_45_DOWN_UD", TILE(0x03a, COL2_PAL, H, V), TILE(0x1c5, COL2_PAL, H, V), TILE(0x1c5, COL2_PAL, H, V), TILE(0x000, COL2_PAL, 0, V), COL_NONE) 
    Metatile("COL2_BLK_22_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1c6, COL2_PAL, 0, 0), TILE(0x1c7, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_BLK_22_UP_2",          TILE(0x1c6, COL2_PAL, 0, 0), TILE(0x1c7, COL2_PAL, 0, 0), TILE(0x03a, COL2_PAL, 0, 0), TILE(0x03a, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_BLK_22_DOWN_1",        TILE(0x1c7, COL2_PAL, H, 0), TILE(0x1c6, COL2_PAL, H, 0), TILE(0x03a, COL2_PAL, H, 0), TILE(0x03a, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_BLK_22_DOWN_2",        TILE(0x000, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x1c7, COL2_PAL, H, 0), TILE(0x1c6, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_BLK_22_UP_UD_1",       TILE(0x1c6, COL2_PAL, 0, V), TILE(0x1c7, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), COL_NONE) // 0x678
    Metatile("COL2_BLK_22_UP_UD_2",       TILE(0x03a, COL2_PAL, 0, V), TILE(0x03a, COL2_PAL, 0, V), TILE(0x1c6, COL2_PAL, 0, V), TILE(0x1c7, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_BLK_22_DOWN_UD_1",     TILE(0x03a, COL2_PAL, H, V), TILE(0x03a, COL2_PAL, H, V), TILE(0x1c7, COL2_PAL, H, V), TILE(0x1c6, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_BLK_22_DOWN_UD_2",     TILE(0x1c7, COL2_PAL, H, V), TILE(0x1c6, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_BLK_66_UP_1",          TILE(0x000, COL2_PAL, 0, 0), TILE(0x1c9, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1c8, COL2_PAL, 0, 0), COL_NONE) 
    Metatile("COL2_BLK_66_UP_2",          TILE(0x1c9, COL2_PAL, 0, 0), TILE(0x03a, COL2_PAL, 0, 0), TILE(0x1c8, COL2_PAL, 0, 0), TILE(0x03a, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_BLK_66_DOWN_1",        TILE(0x03a, COL2_PAL, H, 0), TILE(0x1c9, COL2_PAL, H, 0), TILE(0x03a, COL2_PAL, H, 0), TILE(0x1c8, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_BLK_66_DOWN_2",        TILE(0x1c9, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), TILE(0x1c8, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, H, 0), COL_NONE)
    Metatile("COL2_BLK_66_UP_UD_1",       TILE(0x000, COL2_PAL, 0, V), TILE(0x1c8, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, V), TILE(0x1c9, COL2_PAL, 0, V), COL_NONE) // 0x680
    Metatile("COL2_BLK_66_UP_UD_2",       TILE(0x1c8, COL2_PAL, 0, V), TILE(0x03a, COL2_PAL, 0, V), TILE(0x1c9, COL2_PAL, 0, V), TILE(0x03a, COL2_PAL, 0, V), COL_NONE)
    Metatile("COL2_BLK_66_DOWN_UD_1",     TILE(0x03a, COL2_PAL, H, V), TILE(0x1c8, COL2_PAL, H, V), TILE(0x03a, COL2_PAL, H, V), TILE(0x1c9, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_BLK_66_DOWN_UD_2",     TILE(0x1c8, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), TILE(0x1c9, COL2_PAL, H, V), TILE(0x000, COL2_PAL, H, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x688
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    // COL 3 SLOPES

    
    Metatile("COL3_CHKRED_SLOPE_45_UP",      TILE(0x000, COL3_PAL, 0, 0), TILE(0x1a2, COL3_PAL, 0, 0), TILE(0x1b2, COL3_PAL, 0, 0), TILE(0x007, COL3_PAL, 0, 0), COL_SLOPE_45_UP) // 0x5d0
    Metatile("COL3_CHKRED_SLOPE_45_DOWN",    TILE(0x1a2, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x007, COL3_PAL, H, 0), TILE(0x1b2, COL3_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL3_CHKRED_SLOPE_45_UP_UD",   TILE(0x1b2, COL3_PAL, 0, V), TILE(0x007, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x1a2, COL3_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL3_CHKRED_SLOPE_45_DOWN_UD", TILE(0x007, COL3_PAL, H, V), TILE(0x1b2, COL3_PAL, H, V), TILE(0x1a2, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL3_CHKRED_22_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1b3, COL3_PAL, 0, 0), TILE(0x1b4, COL3_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL3_CHKRED_22_UP_2",          TILE(0x1a3, COL3_PAL, 0, 0), TILE(0x1a4, COL3_PAL, 0, 0), TILE(0x003, COL3_PAL, 0, 0), TILE(0x003, COL3_PAL, H, 0), COL_SLOPE_22_UP_2)
    Metatile("COL3_CHKRED_22_DOWN_1",        TILE(0x1a4, COL3_PAL, H, 0), TILE(0x1a3, COL3_PAL, H, 0), TILE(0x003, COL3_PAL, 0, 0), TILE(0x003, COL3_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL3_CHKRED_22_DOWN_2",        TILE(0x000, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x1b4, COL3_PAL, H, 0), TILE(0x1b3, COL3_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL3_CHKRED_22_UP_UD_1",       TILE(0x1b3, COL3_PAL, 0, V), TILE(0x1b4, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x5d8
    Metatile("COL3_CHKRED_22_UP_UD_2",       TILE(0x003, COL3_PAL, 0, V), TILE(0x003, COL3_PAL, H, V), TILE(0x1a3, COL3_PAL, 0, V), TILE(0x1a4, COL3_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL3_CHKRED_22_DOWN_UD_1",     TILE(0x003, COL3_PAL, 0, V), TILE(0x003, COL3_PAL, H, V), TILE(0x1a4, COL3_PAL, H, V), TILE(0x1a3, COL3_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL3_CHKRED_22_DOWN_UD_2",     TILE(0x1b4, COL3_PAL, H, V), TILE(0x1b3, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL3_CHKRED_66_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x1a6, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1b6, COL3_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL3_CHKRED_66_UP_2",          TILE(0x1a5, COL3_PAL, H, 0), TILE(0x005, COL3_PAL, 0, 0), TILE(0x1b5, COL3_PAL, H, 0), TILE(0x005, COL3_PAL, 0, V), COL_SLOPE_66_UP_2)
    Metatile("COL3_CHKRED_66_DOWN_1",        TILE(0x005, COL3_PAL, H, 0), TILE(0x1a5, COL3_PAL, 0, 0), TILE(0x005, COL3_PAL, H, V), TILE(0x1b5, COL3_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL3_CHKRED_66_DOWN_2",        TILE(0x1a6, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1b6, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL3_CHKRED_66_UP_UD_1",       TILE(0x000, COL3_PAL, 0, 0), TILE(0x1b6, COL3_PAL, H, V), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1a6, COL3_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x5e0
    Metatile("COL3_CHKRED_66_UP_UD_2",       TILE(0x1b5, COL3_PAL, H, V), TILE(0x005, COL3_PAL, 0, 0), TILE(0x1a5, COL3_PAL, H, V), TILE(0x005, COL3_PAL, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL3_CHKRED_66_DOWN_UD_1",     TILE(0x005, COL3_PAL, H, 0), TILE(0x1b5, COL3_PAL, 0, V), TILE(0x005, COL3_PAL, H, V), TILE(0x1a5, COL3_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL3_CHKRED_66_DOWN_UD_2",     TILE(0x1b6, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1a6, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, 0), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x5e8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL3_CHKRED_NO_OUT_SLOPE_45_UP",      TILE(0x000, COL3_PAL, 0, 0), TILE(0x1c0, COL3_PAL, 0, 0), TILE(0x1d0, COL3_PAL, 0, 0), TILE(0x007, COL3_PAL, 0, 0), COL_NONE) // 0x5f0
    Metatile("COL3_CHKRED_NO_OUT_SLOPE_45_DOWN",    TILE(0x1c0, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x007, COL3_PAL, H, 0), TILE(0x1d0, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_CHKRED_NO_OUT_SLOPE_45_UP_UD",   TILE(0x1d0, COL3_PAL, 0, V), TILE(0x007, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x1c0, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_CHKRED_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x007, COL3_PAL, H, V), TILE(0x1d0, COL3_PAL, H, V), TILE(0x1c0, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_NONE) 
    Metatile("COL3_CHKRED_NO_OUT_22_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1b0, COL3_PAL, 0, 0), TILE(0x1b1, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_CHKRED_NO_OUT_22_UP_2",          TILE(0x1a0, COL3_PAL, 0, 0), TILE(0x1a1, COL3_PAL, 0, 0), TILE(0x003, COL3_PAL, 0, 0), TILE(0x003, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_CHKRED_NO_OUT_22_DOWN_1",        TILE(0x1a1, COL3_PAL, H, 0), TILE(0x1a0, COL3_PAL, H, 0), TILE(0x003, COL3_PAL, 0, 0), TILE(0x003, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_CHKRED_NO_OUT_22_DOWN_2",        TILE(0x000, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x1b1, COL3_PAL, H, 0), TILE(0x1b0, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_CHKRED_NO_OUT_22_UP_UD_1",       TILE(0x1b0, COL3_PAL, 0, V), TILE(0x1b1, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), COL_NONE) // 0x5f8
    Metatile("COL3_CHKRED_NO_OUT_22_UP_UD_2",       TILE(0x003, COL3_PAL, 0, V), TILE(0x003, COL3_PAL, H, V), TILE(0x1a0, COL3_PAL, 0, V), TILE(0x1a1, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_CHKRED_NO_OUT_22_DOWN_UD_1",     TILE(0x003, COL3_PAL, 0, V), TILE(0x003, COL3_PAL, H, V), TILE(0x1a1, COL3_PAL, H, V), TILE(0x1a0, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_CHKRED_NO_OUT_22_DOWN_UD_2",     TILE(0x1b1, COL3_PAL, H, V), TILE(0x1b0, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_CHKRED_NO_OUT_66_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x1c1, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1d1, COL3_PAL, H, 0), COL_NONE) 
    Metatile("COL3_CHKRED_NO_OUT_66_UP_2",          TILE(0x1c2, COL3_PAL, H, 0), TILE(0x005, COL3_PAL, 0, 0), TILE(0x1d2, COL3_PAL, H, 0), TILE(0x005, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_CHKRED_NO_OUT_66_DOWN_1",        TILE(0x005, COL3_PAL, H, 0), TILE(0x1c2, COL3_PAL, 0, 0), TILE(0x005, COL3_PAL, H, V), TILE(0x1d2, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_CHKRED_NO_OUT_66_DOWN_2",        TILE(0x1c1, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1d1, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_CHKRED_NO_OUT_66_UP_UD_1",       TILE(0x000, COL3_PAL, 0, 0), TILE(0x1d1, COL3_PAL, H, V), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1c1, COL3_PAL, H, V), COL_NONE) // 0x600
    Metatile("COL3_CHKRED_NO_OUT_66_UP_UD_2",       TILE(0x1d2, COL3_PAL, H, V), TILE(0x005, COL3_PAL, 0, 0), TILE(0x1c2, COL3_PAL, H, V), TILE(0x005, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_CHKRED_NO_OUT_66_DOWN_UD_1",     TILE(0x005, COL3_PAL, H, 0), TILE(0x1d2, COL3_PAL, 0, V), TILE(0x005, COL3_PAL, H, V), TILE(0x1c2, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_CHKRED_NO_OUT_66_DOWN_UD_2",     TILE(0x1d1, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1c1, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, 0), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x608
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("COL3_X_SLOPE_45_UP",      TILE(0x000, COL3_PAL, 0, 0), TILE(0x183, COL3_PAL, 0, 0), TILE(0x182, COL3_PAL, 0, 0), TILE(0x01a, COL3_PAL, 0, 0), COL_SLOPE_45_UP) // 0x610
    Metatile("COL3_X_SLOPE_45_DOWN",    TILE(0x183, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x01a, COL3_PAL, H, 0), TILE(0x182, COL3_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL3_X_SLOPE_45_UP_UD",   TILE(0x182, COL3_PAL, 0, V), TILE(0x01a, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x183, COL3_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL3_X_SLOPE_45_DOWN_UD", TILE(0x01a, COL3_PAL, H, V), TILE(0x182, COL3_PAL, H, V), TILE(0x183, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL3_X_22_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x170, COL3_PAL, 0, 0), TILE(0x171, COL3_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL3_X_22_UP_2",          TILE(0x172, COL3_PAL, 0, 0), TILE(0x173, COL3_PAL, 0, 0), TILE(0x019, COL3_PAL, 0, 0), TILE(0x01a, COL3_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("COL3_X_22_DOWN_1",        TILE(0x173, COL3_PAL, H, 0), TILE(0x172, COL3_PAL, H, 0), TILE(0x01a, COL3_PAL, H, 0), TILE(0x019, COL3_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL3_X_22_DOWN_2",        TILE(0x000, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x171, COL3_PAL, H, 0), TILE(0x170, COL3_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL3_X_22_UP_UD_1",       TILE(0x170, COL3_PAL, 0, V), TILE(0x171, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x618
    Metatile("COL3_X_22_UP_UD_2",       TILE(0x019, COL3_PAL, 0, V), TILE(0x01a, COL3_PAL, 0, V), TILE(0x172, COL3_PAL, 0, V), TILE(0x173, COL3_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL3_X_22_DOWN_UD_1",     TILE(0x01a, COL3_PAL, H, V), TILE(0x019, COL3_PAL, H, V), TILE(0x173, COL3_PAL, H, V), TILE(0x172, COL3_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL3_X_22_DOWN_UD_2",     TILE(0x171, COL3_PAL, H, V), TILE(0x170, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL3_X_66_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x181, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x191, COL3_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL3_X_66_UP_2",          TILE(0x180, COL3_PAL, H, 0), TILE(0x01c, COL3_PAL, 0, 0), TILE(0x190, COL3_PAL, H, 0), TILE(0x01a, COL3_PAL, 0, 0), COL_SLOPE_66_UP_2)
    Metatile("COL3_X_66_DOWN_1",        TILE(0x01c, COL3_PAL, H, 0), TILE(0x180, COL3_PAL, 0, 0), TILE(0x01a, COL3_PAL, H, 0), TILE(0x190, COL3_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL3_X_66_DOWN_2",        TILE(0x181, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x191, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL3_X_66_UP_UD_1",       TILE(0x000, COL3_PAL, 0, V), TILE(0x191, COL3_PAL, H, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x181, COL3_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x620
    Metatile("COL3_X_66_UP_UD_2",       TILE(0x190, COL3_PAL, H, V), TILE(0x01a, COL3_PAL, 0, V), TILE(0x180, COL3_PAL, H, V), TILE(0x01c, COL3_PAL, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL3_X_66_DOWN_UD_1",     TILE(0x01a, COL3_PAL, H, V), TILE(0x190, COL3_PAL, 0, V), TILE(0x01c, COL3_PAL, H, V), TILE(0x180, COL3_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL3_X_66_DOWN_UD_2",     TILE(0x191, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x181, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x628
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL3_X_NO_OUT_SLOPE_45_UP",      TILE(0x000, COL3_PAL, 0, 0), TILE(0x18f, COL3_PAL, 0, 0), TILE(0x18e, COL3_PAL, 0, 0), TILE(0x01a, COL3_PAL, 0, 0), COL_NONE) // 0x630
    Metatile("COL3_X_NO_OUT_SLOPE_45_DOWN",    TILE(0x18f, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x01a, COL3_PAL, H, 0), TILE(0x18e, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_X_NO_OUT_SLOPE_45_UP_UD",   TILE(0x18e, COL3_PAL, 0, V), TILE(0x01a, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x18f, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_X_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x01a, COL3_PAL, H, V), TILE(0x18e, COL3_PAL, H, V), TILE(0x18f, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_NONE) 
    Metatile("COL3_X_NO_OUT_22_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x17c, COL3_PAL, 0, 0), TILE(0x17d, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_X_NO_OUT_22_UP_2",          TILE(0x17e, COL3_PAL, 0, 0), TILE(0x17f, COL3_PAL, 0, 0), TILE(0x019, COL3_PAL, 0, 0), TILE(0x01a, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_X_NO_OUT_22_DOWN_1",        TILE(0x17f, COL3_PAL, H, 0), TILE(0x17e, COL3_PAL, H, 0), TILE(0x01a, COL3_PAL, H, 0), TILE(0x019, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_X_NO_OUT_22_DOWN_2",        TILE(0x000, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x17d, COL3_PAL, H, 0), TILE(0x17c, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_X_NO_OUT_22_UP_UD_1",       TILE(0x17c, COL3_PAL, 0, V), TILE(0x17d, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), COL_NONE) // 0x638
    Metatile("COL3_X_NO_OUT_22_UP_UD_2",       TILE(0x019, COL3_PAL, 0, V), TILE(0x01a, COL3_PAL, 0, V), TILE(0x17e, COL3_PAL, 0, V), TILE(0x17f, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_X_NO_OUT_22_DOWN_UD_1",     TILE(0x01a, COL3_PAL, H, V), TILE(0x019, COL3_PAL, H, V), TILE(0x17f, COL3_PAL, H, V), TILE(0x17e, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_X_NO_OUT_22_DOWN_UD_2",     TILE(0x17d, COL3_PAL, H, V), TILE(0x17c, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_X_NO_OUT_66_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x18d, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x19d, COL3_PAL, H, 0), COL_NONE) 
    Metatile("COL3_X_NO_OUT_66_UP_2",          TILE(0x18c, COL3_PAL, H, 0), TILE(0x01c, COL3_PAL, 0, 0), TILE(0x19c, COL3_PAL, H, 0), TILE(0x01a, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_X_NO_OUT_66_DOWN_1",        TILE(0x01c, COL3_PAL, H, 0), TILE(0x18c, COL3_PAL, 0, 0), TILE(0x01a, COL3_PAL, H, 0), TILE(0x19c, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_X_NO_OUT_66_DOWN_2",        TILE(0x18d, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x19d, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_X_NO_OUT_66_UP_UD_1",       TILE(0x000, COL3_PAL, 0, V), TILE(0x19d, COL3_PAL, H, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x18d, COL3_PAL, H, V), COL_NONE) // 0x640
    Metatile("COL3_X_NO_OUT_66_UP_UD_2",       TILE(0x19c, COL3_PAL, H, V), TILE(0x01a, COL3_PAL, 0, V), TILE(0x18c, COL3_PAL, H, V), TILE(0x01c, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_X_NO_OUT_66_DOWN_UD_1",     TILE(0x01a, COL3_PAL, H, V), TILE(0x19c, COL3_PAL, 0, V), TILE(0x01c, COL3_PAL, H, V), TILE(0x18c, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_X_NO_OUT_66_DOWN_UD_2",     TILE(0x19d, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x18d, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x648
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    
    Metatile("COL3_+_SLOPE_45_UP",      TILE(0x000, COL3_PAL, 0, 0), TILE(0x177, COL3_PAL, 0, 0), TILE(0x176, COL3_PAL, 0, 0), TILE(0x031, COL3_PAL, 0, 0), COL_SLOPE_45_UP) // 0x650
    Metatile("COL3_+_SLOPE_45_DOWN",    TILE(0x177, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x031, COL3_PAL, H, 0), TILE(0x176, COL3_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL3_+_SLOPE_45_UP_UD",   TILE(0x176, COL3_PAL, 0, V), TILE(0x031, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x177, COL3_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL3_+_SLOPE_45_DOWN_UD", TILE(0x031, COL3_PAL, H, V), TILE(0x176, COL3_PAL, H, V), TILE(0x177, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL3_+_22_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x184, COL3_PAL, 0, 0), TILE(0x185, COL3_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL3_+_22_UP_2",          TILE(0x186, COL3_PAL, 0, 0), TILE(0x187, COL3_PAL, 0, 0), TILE(0x030, COL3_PAL, 0, 0), TILE(0x031, COL3_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("COL3_+_22_DOWN_1",        TILE(0x187, COL3_PAL, H, 0), TILE(0x186, COL3_PAL, H, 0), TILE(0x031, COL3_PAL, H, 0), TILE(0x030, COL3_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL3_+_22_DOWN_2",        TILE(0x000, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x185, COL3_PAL, H, 0), TILE(0x184, COL3_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL3_+_22_UP_UD_1",       TILE(0x184, COL3_PAL, 0, V), TILE(0x185, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x658
    Metatile("COL3_+_22_UP_UD_2",       TILE(0x030, COL3_PAL, 0, V), TILE(0x031, COL3_PAL, 0, V), TILE(0x186, COL3_PAL, 0, V), TILE(0x187, COL3_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL3_+_22_DOWN_UD_1",     TILE(0x031, COL3_PAL, H, V), TILE(0x030, COL3_PAL, H, V), TILE(0x187, COL3_PAL, H, V), TILE(0x186, COL3_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL3_+_22_DOWN_UD_2",     TILE(0x185, COL3_PAL, H, V), TILE(0x184, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL3_+_66_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x188, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x198, COL3_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL3_+_66_UP_2",          TILE(0x189, COL3_PAL, H, 0), TILE(0x035, COL3_PAL, H, 0), TILE(0x199, COL3_PAL, H, 0), TILE(0x030, COL3_PAL, H, 0), COL_SLOPE_66_UP_2)
    Metatile("COL3_+_66_DOWN_1",        TILE(0x035, COL3_PAL, 0, 0), TILE(0x189, COL3_PAL, 0, 0), TILE(0x030, COL3_PAL, 0, 0), TILE(0x199, COL3_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL3_+_66_DOWN_2",        TILE(0x188, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x198, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL3_+_66_UP_UD_1",       TILE(0x000, COL3_PAL, 0, V), TILE(0x198, COL3_PAL, H, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x188, COL3_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x660
    Metatile("COL3_+_66_UP_UD_2",       TILE(0x199, COL3_PAL, H, V), TILE(0x030, COL3_PAL, H, V), TILE(0x189, COL3_PAL, H, V), TILE(0x035, COL3_PAL, H, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL3_+_66_DOWN_UD_1",     TILE(0x030, COL3_PAL, 0, V), TILE(0x199, COL3_PAL, 0, V), TILE(0x035, COL3_PAL, 0, V), TILE(0x189, COL3_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL3_+_66_DOWN_UD_2",     TILE(0x198, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x188, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x668
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL3_+_NO_OUT_SLOPE_45_UP",      TILE(0x000, COL3_PAL, 0, 0), TILE(0x193, COL3_PAL, 0, 0), TILE(0x192, COL3_PAL, 0, 0), TILE(0x031, COL3_PAL, 0, 0), COL_NONE) // 0x670
    Metatile("COL3_+_NO_OUT_SLOPE_45_DOWN",    TILE(0x193, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x031, COL3_PAL, H, 0), TILE(0x192, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_+_NO_OUT_SLOPE_45_UP_UD",   TILE(0x192, COL3_PAL, 0, V), TILE(0x031, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x193, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_+_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x031, COL3_PAL, H, V), TILE(0x192, COL3_PAL, H, V), TILE(0x193, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_NONE) 
    Metatile("COL3_+_NO_OUT_22_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x194, COL3_PAL, 0, 0), TILE(0x195, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_+_NO_OUT_22_UP_2",          TILE(0x196, COL3_PAL, 0, 0), TILE(0x197, COL3_PAL, 0, 0), TILE(0x030, COL3_PAL, 0, 0), TILE(0x031, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_+_NO_OUT_22_DOWN_1",        TILE(0x197, COL3_PAL, H, 0), TILE(0x196, COL3_PAL, H, 0), TILE(0x031, COL3_PAL, H, 0), TILE(0x030, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_+_NO_OUT_22_DOWN_2",        TILE(0x000, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x195, COL3_PAL, H, 0), TILE(0x194, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_+_NO_OUT_22_UP_UD_1",       TILE(0x194, COL3_PAL, 0, V), TILE(0x195, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), COL_NONE) // 0x678
    Metatile("COL3_+_NO_OUT_22_UP_UD_2",       TILE(0x030, COL3_PAL, 0, V), TILE(0x031, COL3_PAL, 0, V), TILE(0x196, COL3_PAL, 0, V), TILE(0x197, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_+_NO_OUT_22_DOWN_UD_1",     TILE(0x031, COL3_PAL, H, V), TILE(0x030, COL3_PAL, H, V), TILE(0x197, COL3_PAL, H, V), TILE(0x196, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_+_NO_OUT_22_DOWN_UD_2",     TILE(0x195, COL3_PAL, H, V), TILE(0x194, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_+_NO_OUT_66_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x18a, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x19a, COL3_PAL, H, 0), COL_NONE) 
    Metatile("COL3_+_NO_OUT_66_UP_2",          TILE(0x18b, COL3_PAL, H, 0), TILE(0x035, COL3_PAL, H, 0), TILE(0x19b, COL3_PAL, H, 0), TILE(0x030, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_+_NO_OUT_66_DOWN_1",        TILE(0x035, COL3_PAL, 0, 0), TILE(0x18b, COL3_PAL, 0, 0), TILE(0x030, COL3_PAL, 0, 0), TILE(0x19b, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_+_NO_OUT_66_DOWN_2",        TILE(0x18a, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x19a, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_+_NO_OUT_66_UP_UD_1",       TILE(0x000, COL3_PAL, 0, V), TILE(0x19a, COL3_PAL, H, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x18a, COL3_PAL, H, V), COL_NONE) // 0x680
    Metatile("COL3_+_NO_OUT_66_UP_UD_2",       TILE(0x19b, COL3_PAL, H, V), TILE(0x030, COL3_PAL, H, V), TILE(0x18b, COL3_PAL, H, V), TILE(0x035, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_+_NO_OUT_66_DOWN_UD_1",     TILE(0x030, COL3_PAL, 0, V), TILE(0x19b, COL3_PAL, 0, V), TILE(0x035, COL3_PAL, 0, V), TILE(0x18b, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_+_NO_OUT_66_DOWN_UD_2",     TILE(0x19a, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x18a, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), COL_NONE)


    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x688
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("COL3_BRICKS_SLOPE_45_UP",      TILE(0x000, COL3_PAL, 0, 0), TILE(0x19f, COL3_PAL, 0, 0), TILE(0x19e, COL3_PAL, 0, 0), TILE(0x044, COL3_PAL, 0, 0), COL_SLOPE_45_UP) // 0x690
    Metatile("COL3_BRICKS_SLOPE_45_DOWN",    TILE(0x19f, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x044, COL3_PAL, H, 0), TILE(0x19e, COL3_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL3_BRICKS_SLOPE_45_UP_UD",   TILE(0x19e, COL3_PAL, 0, V), TILE(0x044, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x19f, COL3_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL3_BRICKS_SLOPE_45_DOWN_UD", TILE(0x044, COL3_PAL, H, V), TILE(0x19e, COL3_PAL, H, V), TILE(0x19f, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL3_BRICKS_22_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1ac, COL3_PAL, 0, 0), TILE(0x1ad, COL3_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL3_BRICKS_22_UP_2",          TILE(0x1ae, COL3_PAL, 0, 0), TILE(0x1af, COL3_PAL, 0, 0), TILE(0x043, COL3_PAL, 0, 0), TILE(0x044, COL3_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("COL3_BRICKS_22_DOWN_1",        TILE(0x1af, COL3_PAL, H, 0), TILE(0x1ae, COL3_PAL, H, 0), TILE(0x044, COL3_PAL, H, 0), TILE(0x043, COL3_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL3_BRICKS_22_DOWN_2",        TILE(0x000, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x1ad, COL3_PAL, H, 0), TILE(0x1ac, COL3_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL3_BRICKS_22_UP_UD_1",       TILE(0x1ac, COL3_PAL, 0, V), TILE(0x1ad, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x698
    Metatile("COL3_BRICKS_22_UP_UD_2",       TILE(0x043, COL3_PAL, 0, V), TILE(0x044, COL3_PAL, 0, V), TILE(0x1ae, COL3_PAL, 0, V), TILE(0x1af, COL3_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL3_BRICKS_22_DOWN_UD_1",     TILE(0x044, COL3_PAL, H, V), TILE(0x043, COL3_PAL, H, V), TILE(0x1af, COL3_PAL, H, V), TILE(0x1ae, COL3_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL3_BRICKS_22_DOWN_UD_2",     TILE(0x1ad, COL3_PAL, H, V), TILE(0x1ac, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL3_BRICKS_66_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x1be, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1bf, COL3_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL3_BRICKS_66_UP_2",          TILE(0x1bc, COL3_PAL, H, 0), TILE(0x044, COL3_PAL, H, 0), TILE(0x1bd, COL3_PAL, H, 0), TILE(0x043, COL3_PAL, H, 0), COL_SLOPE_66_UP_2)
    Metatile("COL3_BRICKS_66_DOWN_1",        TILE(0x044, COL3_PAL, 0, 0), TILE(0x1bc, COL3_PAL, 0, 0), TILE(0x043, COL3_PAL, 0, 0), TILE(0x1bd, COL3_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL3_BRICKS_66_DOWN_2",        TILE(0x1be, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1bf, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL3_BRICKS_66_UP_UD_1",       TILE(0x000, COL3_PAL, 0, V), TILE(0x1bf, COL3_PAL, H, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x1be, COL3_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x6a0
    Metatile("COL3_BRICKS_66_UP_UD_2",       TILE(0x1bd, COL3_PAL, H, V), TILE(0x043, COL3_PAL, H, V), TILE(0x1bc, COL3_PAL, H, V), TILE(0x044, COL3_PAL, H, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL3_BRICKS_66_DOWN_UD_1",     TILE(0x043, COL3_PAL, 0, V), TILE(0x1bd, COL3_PAL, 0, V), TILE(0x044, COL3_PAL, 0, V), TILE(0x1bc, COL3_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL3_BRICKS_66_DOWN_UD_2",     TILE(0x1bf, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x1be, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x6a8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL3_BRICKS_NO_OUT_SLOPE_45_UP",      TILE(0x000, COL3_PAL, 0, 0), TILE(0x1ab, COL3_PAL, 0, 0), TILE(0x1aa, COL3_PAL, 0, 0), TILE(0x044, COL3_PAL, 0, 0), COL_NONE) // 0x6b0
    Metatile("COL3_BRICKS_NO_OUT_SLOPE_45_DOWN",    TILE(0x1ab, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x044, COL3_PAL, H, 0), TILE(0x1aa, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_BRICKS_NO_OUT_SLOPE_45_UP_UD",   TILE(0x1aa, COL3_PAL, 0, V), TILE(0x044, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x1ab, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_BRICKS_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x044, COL3_PAL, H, V), TILE(0x1aa, COL3_PAL, H, V), TILE(0x1ab, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_NONE) 
    Metatile("COL3_BRICKS_NO_OUT_22_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1ba, COL3_PAL, 0, 0), TILE(0x1bb, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_BRICKS_NO_OUT_22_UP_2",          TILE(0x1a8, COL3_PAL, 0, 0), TILE(0x1a9, COL3_PAL, 0, 0), TILE(0x043, COL3_PAL, 0, 0), TILE(0x044, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_BRICKS_NO_OUT_22_DOWN_1",        TILE(0x1a9, COL3_PAL, H, 0), TILE(0x1a8, COL3_PAL, H, 0), TILE(0x044, COL3_PAL, H, 0), TILE(0x043, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_BRICKS_NO_OUT_22_DOWN_2",        TILE(0x000, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x1bb, COL3_PAL, H, 0), TILE(0x1ba, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_BRICKS_NO_OUT_22_UP_UD_1",       TILE(0x1ba, COL3_PAL, 0, V), TILE(0x1bb, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), COL_NONE) // 0x6b8
    Metatile("COL3_BRICKS_NO_OUT_22_UP_UD_2",       TILE(0x043, COL3_PAL, 0, V), TILE(0x044, COL3_PAL, 0, V), TILE(0x1a8, COL3_PAL, 0, V), TILE(0x1a9, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_BRICKS_NO_OUT_22_DOWN_UD_1",     TILE(0x044, COL3_PAL, H, V), TILE(0x043, COL3_PAL, H, V), TILE(0x1a9, COL3_PAL, H, V), TILE(0x1a8, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_BRICKS_NO_OUT_22_DOWN_UD_2",     TILE(0x1bb, COL3_PAL, H, V), TILE(0x1ba, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_BRICKS_NO_OUT_66_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x1a7, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1b7, COL3_PAL, H, 0), COL_NONE) 
    Metatile("COL3_BRICKS_NO_OUT_66_UP_2",          TILE(0x1b8, COL3_PAL, H, 0), TILE(0x044, COL3_PAL, H, 0), TILE(0x1b9, COL3_PAL, H, 0), TILE(0x043, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_BRICKS_NO_OUT_66_DOWN_1",        TILE(0x044, COL3_PAL, 0, 0), TILE(0x1b8, COL3_PAL, 0, 0), TILE(0x043, COL3_PAL, 0, 0), TILE(0x1b9, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_BRICKS_NO_OUT_66_DOWN_2",        TILE(0x1a7, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1b7, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_BRICKS_NO_OUT_66_UP_UD_1",       TILE(0x000, COL3_PAL, 0, V), TILE(0x1b7, COL3_PAL, H, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x1a7, COL3_PAL, H, V), COL_NONE) // 0x6c0
    Metatile("COL3_BRICKS_NO_OUT_66_UP_UD_2",       TILE(0x1b9, COL3_PAL, H, V), TILE(0x043, COL3_PAL, H, V), TILE(0x1b8, COL3_PAL, H, V), TILE(0x044, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_BRICKS_NO_OUT_66_DOWN_UD_1",     TILE(0x043, COL3_PAL, 0, V), TILE(0x1b9, COL3_PAL, 0, V), TILE(0x044, COL3_PAL, 0, V), TILE(0x1b8, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_BRICKS_NO_OUT_66_DOWN_UD_2",     TILE(0x1b7, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x1a7, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x6c8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("COL3_BLK_SLOPE_45_UP",      TILE(0x000, COL3_PAL, 0, 0), TILE(0x1c5, COL3_PAL, 0, 0), TILE(0x1c5, COL3_PAL, 0, 0), TILE(0x03a, COL3_PAL, 0, 0), COL_NONE) // 0x670
    Metatile("COL3_BLK_SLOPE_45_DOWN",    TILE(0x1c5, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x03a, COL3_PAL, H, 0), TILE(0x1c5, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_BLK_SLOPE_45_UP_UD",   TILE(0x1c5, COL3_PAL, 0, V), TILE(0x03a, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x1c5, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_BLK_SLOPE_45_DOWN_UD", TILE(0x03a, COL3_PAL, H, V), TILE(0x1c5, COL3_PAL, H, V), TILE(0x1c5, COL3_PAL, H, V), TILE(0x000, COL3_PAL, 0, V), COL_NONE) 
    Metatile("COL3_BLK_22_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1c6, COL3_PAL, 0, 0), TILE(0x1c7, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_BLK_22_UP_2",          TILE(0x1c6, COL3_PAL, 0, 0), TILE(0x1c7, COL3_PAL, 0, 0), TILE(0x03a, COL3_PAL, 0, 0), TILE(0x03a, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_BLK_22_DOWN_1",        TILE(0x1c7, COL3_PAL, H, 0), TILE(0x1c6, COL3_PAL, H, 0), TILE(0x03a, COL3_PAL, H, 0), TILE(0x03a, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_BLK_22_DOWN_2",        TILE(0x000, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x1c7, COL3_PAL, H, 0), TILE(0x1c6, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_BLK_22_UP_UD_1",       TILE(0x1c6, COL3_PAL, 0, V), TILE(0x1c7, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), COL_NONE) // 0x678
    Metatile("COL3_BLK_22_UP_UD_2",       TILE(0x03a, COL3_PAL, 0, V), TILE(0x03a, COL3_PAL, 0, V), TILE(0x1c6, COL3_PAL, 0, V), TILE(0x1c7, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_BLK_22_DOWN_UD_1",     TILE(0x03a, COL3_PAL, H, V), TILE(0x03a, COL3_PAL, H, V), TILE(0x1c7, COL3_PAL, H, V), TILE(0x1c6, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_BLK_22_DOWN_UD_2",     TILE(0x1c7, COL3_PAL, H, V), TILE(0x1c6, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_BLK_66_UP_1",          TILE(0x000, COL3_PAL, 0, 0), TILE(0x1c9, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1c8, COL3_PAL, 0, 0), COL_NONE) 
    Metatile("COL3_BLK_66_UP_2",          TILE(0x1c9, COL3_PAL, 0, 0), TILE(0x03a, COL3_PAL, 0, 0), TILE(0x1c8, COL3_PAL, 0, 0), TILE(0x03a, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_BLK_66_DOWN_1",        TILE(0x03a, COL3_PAL, H, 0), TILE(0x1c9, COL3_PAL, H, 0), TILE(0x03a, COL3_PAL, H, 0), TILE(0x1c8, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_BLK_66_DOWN_2",        TILE(0x1c9, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), TILE(0x1c8, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, H, 0), COL_NONE)
    Metatile("COL3_BLK_66_UP_UD_1",       TILE(0x000, COL3_PAL, 0, V), TILE(0x1c8, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, V), TILE(0x1c9, COL3_PAL, 0, V), COL_NONE) // 0x680
    Metatile("COL3_BLK_66_UP_UD_2",       TILE(0x1c8, COL3_PAL, 0, V), TILE(0x03a, COL3_PAL, 0, V), TILE(0x1c9, COL3_PAL, 0, V), TILE(0x03a, COL3_PAL, 0, V), COL_NONE)
    Metatile("COL3_BLK_66_DOWN_UD_1",     TILE(0x03a, COL3_PAL, H, V), TILE(0x1c8, COL3_PAL, H, V), TILE(0x03a, COL3_PAL, H, V), TILE(0x1c9, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_BLK_66_DOWN_UD_2",     TILE(0x1c8, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), TILE(0x1c9, COL3_PAL, H, V), TILE(0x000, COL3_PAL, H, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x688
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    // COL 4 SLOPES

    
    Metatile("COL4_CHKRED_SLOPE_45_UP",      TILE(0x000, COL4_PAL, 0, 0), TILE(0x1a2, COL4_PAL, 0, 0), TILE(0x1b2, COL4_PAL, 0, 0), TILE(0x007, COL4_PAL, 0, 0), COL_SLOPE_45_UP) // 0x5d0
    Metatile("COL4_CHKRED_SLOPE_45_DOWN",    TILE(0x1a2, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x007, COL4_PAL, H, 0), TILE(0x1b2, COL4_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL4_CHKRED_SLOPE_45_UP_UD",   TILE(0x1b2, COL4_PAL, 0, V), TILE(0x007, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x1a2, COL4_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL4_CHKRED_SLOPE_45_DOWN_UD", TILE(0x007, COL4_PAL, H, V), TILE(0x1b2, COL4_PAL, H, V), TILE(0x1a2, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL4_CHKRED_22_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1b3, COL4_PAL, 0, 0), TILE(0x1b4, COL4_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL4_CHKRED_22_UP_2",          TILE(0x1a3, COL4_PAL, 0, 0), TILE(0x1a4, COL4_PAL, 0, 0), TILE(0x003, COL4_PAL, 0, 0), TILE(0x003, COL4_PAL, H, 0), COL_SLOPE_22_UP_2)
    Metatile("COL4_CHKRED_22_DOWN_1",        TILE(0x1a4, COL4_PAL, H, 0), TILE(0x1a3, COL4_PAL, H, 0), TILE(0x003, COL4_PAL, 0, 0), TILE(0x003, COL4_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL4_CHKRED_22_DOWN_2",        TILE(0x000, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x1b4, COL4_PAL, H, 0), TILE(0x1b3, COL4_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL4_CHKRED_22_UP_UD_1",       TILE(0x1b3, COL4_PAL, 0, V), TILE(0x1b4, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x5d8
    Metatile("COL4_CHKRED_22_UP_UD_2",       TILE(0x003, COL4_PAL, 0, V), TILE(0x003, COL4_PAL, H, V), TILE(0x1a3, COL4_PAL, 0, V), TILE(0x1a4, COL4_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL4_CHKRED_22_DOWN_UD_1",     TILE(0x003, COL4_PAL, 0, V), TILE(0x003, COL4_PAL, H, V), TILE(0x1a4, COL4_PAL, H, V), TILE(0x1a3, COL4_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL4_CHKRED_22_DOWN_UD_2",     TILE(0x1b4, COL4_PAL, H, V), TILE(0x1b3, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL4_CHKRED_66_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x1a6, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1b6, COL4_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL4_CHKRED_66_UP_2",          TILE(0x1a5, COL4_PAL, H, 0), TILE(0x005, COL4_PAL, 0, 0), TILE(0x1b5, COL4_PAL, H, 0), TILE(0x005, COL4_PAL, 0, V), COL_SLOPE_66_UP_2)
    Metatile("COL4_CHKRED_66_DOWN_1",        TILE(0x005, COL4_PAL, H, 0), TILE(0x1a5, COL4_PAL, 0, 0), TILE(0x005, COL4_PAL, H, V), TILE(0x1b5, COL4_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL4_CHKRED_66_DOWN_2",        TILE(0x1a6, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1b6, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL4_CHKRED_66_UP_UD_1",       TILE(0x000, COL4_PAL, 0, 0), TILE(0x1b6, COL4_PAL, H, V), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1a6, COL4_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x5e0
    Metatile("COL4_CHKRED_66_UP_UD_2",       TILE(0x1b5, COL4_PAL, H, V), TILE(0x005, COL4_PAL, 0, 0), TILE(0x1a5, COL4_PAL, H, V), TILE(0x005, COL4_PAL, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL4_CHKRED_66_DOWN_UD_1",     TILE(0x005, COL4_PAL, H, 0), TILE(0x1b5, COL4_PAL, 0, V), TILE(0x005, COL4_PAL, H, V), TILE(0x1a5, COL4_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL4_CHKRED_66_DOWN_UD_2",     TILE(0x1b6, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1a6, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, 0), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x5e8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL4_CHKRED_NO_OUT_SLOPE_45_UP",      TILE(0x000, COL4_PAL, 0, 0), TILE(0x1c0, COL4_PAL, 0, 0), TILE(0x1d0, COL4_PAL, 0, 0), TILE(0x007, COL4_PAL, 0, 0), COL_NONE) // 0x5f0
    Metatile("COL4_CHKRED_NO_OUT_SLOPE_45_DOWN",    TILE(0x1c0, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x007, COL4_PAL, H, 0), TILE(0x1d0, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_CHKRED_NO_OUT_SLOPE_45_UP_UD",   TILE(0x1d0, COL4_PAL, 0, V), TILE(0x007, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x1c0, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_CHKRED_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x007, COL4_PAL, H, V), TILE(0x1d0, COL4_PAL, H, V), TILE(0x1c0, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_NONE) 
    Metatile("COL4_CHKRED_NO_OUT_22_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1b0, COL4_PAL, 0, 0), TILE(0x1b1, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_CHKRED_NO_OUT_22_UP_2",          TILE(0x1a0, COL4_PAL, 0, 0), TILE(0x1a1, COL4_PAL, 0, 0), TILE(0x003, COL4_PAL, 0, 0), TILE(0x003, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_CHKRED_NO_OUT_22_DOWN_1",        TILE(0x1a1, COL4_PAL, H, 0), TILE(0x1a0, COL4_PAL, H, 0), TILE(0x003, COL4_PAL, 0, 0), TILE(0x003, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_CHKRED_NO_OUT_22_DOWN_2",        TILE(0x000, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x1b1, COL4_PAL, H, 0), TILE(0x1b0, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_CHKRED_NO_OUT_22_UP_UD_1",       TILE(0x1b0, COL4_PAL, 0, V), TILE(0x1b1, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), COL_NONE) // 0x5f8
    Metatile("COL4_CHKRED_NO_OUT_22_UP_UD_2",       TILE(0x003, COL4_PAL, 0, V), TILE(0x003, COL4_PAL, H, V), TILE(0x1a0, COL4_PAL, 0, V), TILE(0x1a1, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_CHKRED_NO_OUT_22_DOWN_UD_1",     TILE(0x003, COL4_PAL, 0, V), TILE(0x003, COL4_PAL, H, V), TILE(0x1a1, COL4_PAL, H, V), TILE(0x1a0, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_CHKRED_NO_OUT_22_DOWN_UD_2",     TILE(0x1b1, COL4_PAL, H, V), TILE(0x1b0, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_CHKRED_NO_OUT_66_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x1c1, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1d1, COL4_PAL, H, 0), COL_NONE) 
    Metatile("COL4_CHKRED_NO_OUT_66_UP_2",          TILE(0x1c2, COL4_PAL, H, 0), TILE(0x005, COL4_PAL, 0, 0), TILE(0x1d2, COL4_PAL, H, 0), TILE(0x005, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_CHKRED_NO_OUT_66_DOWN_1",        TILE(0x005, COL4_PAL, H, 0), TILE(0x1c2, COL4_PAL, 0, 0), TILE(0x005, COL4_PAL, H, V), TILE(0x1d2, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_CHKRED_NO_OUT_66_DOWN_2",        TILE(0x1c1, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1d1, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_CHKRED_NO_OUT_66_UP_UD_1",       TILE(0x000, COL4_PAL, 0, 0), TILE(0x1d1, COL4_PAL, H, V), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1c1, COL4_PAL, H, V), COL_NONE) // 0x600
    Metatile("COL4_CHKRED_NO_OUT_66_UP_UD_2",       TILE(0x1d2, COL4_PAL, H, V), TILE(0x005, COL4_PAL, 0, 0), TILE(0x1c2, COL4_PAL, H, V), TILE(0x005, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_CHKRED_NO_OUT_66_DOWN_UD_1",     TILE(0x005, COL4_PAL, H, 0), TILE(0x1d2, COL4_PAL, 0, V), TILE(0x005, COL4_PAL, H, V), TILE(0x1c2, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_CHKRED_NO_OUT_66_DOWN_UD_2",     TILE(0x1d1, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1c1, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x608
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("COL4_X_SLOPE_45_UP",      TILE(0x000, COL4_PAL, 0, 0), TILE(0x183, COL4_PAL, 0, 0), TILE(0x182, COL4_PAL, 0, 0), TILE(0x01a, COL4_PAL, 0, 0), COL_SLOPE_45_UP) // 0x610
    Metatile("COL4_X_SLOPE_45_DOWN",    TILE(0x183, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x01a, COL4_PAL, H, 0), TILE(0x182, COL4_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL4_X_SLOPE_45_UP_UD",   TILE(0x182, COL4_PAL, 0, V), TILE(0x01a, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x183, COL4_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL4_X_SLOPE_45_DOWN_UD", TILE(0x01a, COL4_PAL, H, V), TILE(0x182, COL4_PAL, H, V), TILE(0x183, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL4_X_22_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x170, COL4_PAL, 0, 0), TILE(0x171, COL4_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL4_X_22_UP_2",          TILE(0x172, COL4_PAL, 0, 0), TILE(0x173, COL4_PAL, 0, 0), TILE(0x019, COL4_PAL, 0, 0), TILE(0x01a, COL4_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("COL4_X_22_DOWN_1",        TILE(0x173, COL4_PAL, H, 0), TILE(0x172, COL4_PAL, H, 0), TILE(0x01a, COL4_PAL, H, 0), TILE(0x019, COL4_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL4_X_22_DOWN_2",        TILE(0x000, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x171, COL4_PAL, H, 0), TILE(0x170, COL4_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL4_X_22_UP_UD_1",       TILE(0x170, COL4_PAL, 0, V), TILE(0x171, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x618
    Metatile("COL4_X_22_UP_UD_2",       TILE(0x019, COL4_PAL, 0, V), TILE(0x01a, COL4_PAL, 0, V), TILE(0x172, COL4_PAL, 0, V), TILE(0x173, COL4_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL4_X_22_DOWN_UD_1",     TILE(0x01a, COL4_PAL, H, V), TILE(0x019, COL4_PAL, H, V), TILE(0x173, COL4_PAL, H, V), TILE(0x172, COL4_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL4_X_22_DOWN_UD_2",     TILE(0x171, COL4_PAL, H, V), TILE(0x170, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL4_X_66_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x181, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x191, COL4_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL4_X_66_UP_2",          TILE(0x180, COL4_PAL, H, 0), TILE(0x01c, COL4_PAL, 0, 0), TILE(0x190, COL4_PAL, H, 0), TILE(0x01a, COL4_PAL, 0, 0), COL_SLOPE_66_UP_2)
    Metatile("COL4_X_66_DOWN_1",        TILE(0x01c, COL4_PAL, H, 0), TILE(0x180, COL4_PAL, 0, 0), TILE(0x01a, COL4_PAL, H, 0), TILE(0x190, COL4_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL4_X_66_DOWN_2",        TILE(0x181, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x191, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL4_X_66_UP_UD_1",       TILE(0x000, COL4_PAL, 0, V), TILE(0x191, COL4_PAL, H, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x181, COL4_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x620
    Metatile("COL4_X_66_UP_UD_2",       TILE(0x190, COL4_PAL, H, V), TILE(0x01a, COL4_PAL, 0, V), TILE(0x180, COL4_PAL, H, V), TILE(0x01c, COL4_PAL, 0, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL4_X_66_DOWN_UD_1",     TILE(0x01a, COL4_PAL, H, V), TILE(0x190, COL4_PAL, 0, V), TILE(0x01c, COL4_PAL, H, V), TILE(0x180, COL4_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL4_X_66_DOWN_UD_2",     TILE(0x191, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x181, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x628
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL4_X_NO_OUT_SLOPE_45_UP",      TILE(0x000, COL4_PAL, 0, 0), TILE(0x18f, COL4_PAL, 0, 0), TILE(0x18e, COL4_PAL, 0, 0), TILE(0x01a, COL4_PAL, 0, 0), COL_NONE) // 0x630
    Metatile("COL4_X_NO_OUT_SLOPE_45_DOWN",    TILE(0x18f, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x01a, COL4_PAL, H, 0), TILE(0x18e, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_X_NO_OUT_SLOPE_45_UP_UD",   TILE(0x18e, COL4_PAL, 0, V), TILE(0x01a, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x18f, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_X_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x01a, COL4_PAL, H, V), TILE(0x18e, COL4_PAL, H, V), TILE(0x18f, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_NONE) 
    Metatile("COL4_X_NO_OUT_22_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x17c, COL4_PAL, 0, 0), TILE(0x17d, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_X_NO_OUT_22_UP_2",          TILE(0x17e, COL4_PAL, 0, 0), TILE(0x17f, COL4_PAL, 0, 0), TILE(0x019, COL4_PAL, 0, 0), TILE(0x01a, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_X_NO_OUT_22_DOWN_1",        TILE(0x17f, COL4_PAL, H, 0), TILE(0x17e, COL4_PAL, H, 0), TILE(0x01a, COL4_PAL, H, 0), TILE(0x019, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_X_NO_OUT_22_DOWN_2",        TILE(0x000, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x17d, COL4_PAL, H, 0), TILE(0x17c, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_X_NO_OUT_22_UP_UD_1",       TILE(0x17c, COL4_PAL, 0, V), TILE(0x17d, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), COL_NONE) // 0x638
    Metatile("COL4_X_NO_OUT_22_UP_UD_2",       TILE(0x019, COL4_PAL, 0, V), TILE(0x01a, COL4_PAL, 0, V), TILE(0x17e, COL4_PAL, 0, V), TILE(0x17f, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_X_NO_OUT_22_DOWN_UD_1",     TILE(0x01a, COL4_PAL, H, V), TILE(0x019, COL4_PAL, H, V), TILE(0x17f, COL4_PAL, H, V), TILE(0x17e, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_X_NO_OUT_22_DOWN_UD_2",     TILE(0x17d, COL4_PAL, H, V), TILE(0x17c, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_X_NO_OUT_66_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x18d, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x19d, COL4_PAL, H, 0), COL_NONE) 
    Metatile("COL4_X_NO_OUT_66_UP_2",          TILE(0x18c, COL4_PAL, H, 0), TILE(0x01c, COL4_PAL, 0, 0), TILE(0x19c, COL4_PAL, H, 0), TILE(0x01a, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_X_NO_OUT_66_DOWN_1",        TILE(0x01c, COL4_PAL, H, 0), TILE(0x18c, COL4_PAL, 0, 0), TILE(0x01a, COL4_PAL, H, 0), TILE(0x19c, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_X_NO_OUT_66_DOWN_2",        TILE(0x18d, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x19d, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_X_NO_OUT_66_UP_UD_1",       TILE(0x000, COL4_PAL, 0, V), TILE(0x19d, COL4_PAL, H, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x18d, COL4_PAL, H, V), COL_NONE) // 0x640
    Metatile("COL4_X_NO_OUT_66_UP_UD_2",       TILE(0x19c, COL4_PAL, H, V), TILE(0x01a, COL4_PAL, 0, V), TILE(0x18c, COL4_PAL, H, V), TILE(0x01c, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_X_NO_OUT_66_DOWN_UD_1",     TILE(0x01a, COL4_PAL, H, V), TILE(0x19c, COL4_PAL, 0, V), TILE(0x01c, COL4_PAL, H, V), TILE(0x18c, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_X_NO_OUT_66_DOWN_UD_2",     TILE(0x19d, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x18d, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x648
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    
    Metatile("COL4_+_SLOPE_45_UP",      TILE(0x000, COL4_PAL, 0, 0), TILE(0x177, COL4_PAL, 0, 0), TILE(0x176, COL4_PAL, 0, 0), TILE(0x031, COL4_PAL, 0, 0), COL_SLOPE_45_UP) // 0x650
    Metatile("COL4_+_SLOPE_45_DOWN",    TILE(0x177, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x031, COL4_PAL, H, 0), TILE(0x176, COL4_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL4_+_SLOPE_45_UP_UD",   TILE(0x176, COL4_PAL, 0, V), TILE(0x031, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x177, COL4_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL4_+_SLOPE_45_DOWN_UD", TILE(0x031, COL4_PAL, H, V), TILE(0x176, COL4_PAL, H, V), TILE(0x177, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL4_+_22_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x184, COL4_PAL, 0, 0), TILE(0x185, COL4_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL4_+_22_UP_2",          TILE(0x186, COL4_PAL, 0, 0), TILE(0x187, COL4_PAL, 0, 0), TILE(0x030, COL4_PAL, 0, 0), TILE(0x031, COL4_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("COL4_+_22_DOWN_1",        TILE(0x187, COL4_PAL, H, 0), TILE(0x186, COL4_PAL, H, 0), TILE(0x031, COL4_PAL, H, 0), TILE(0x030, COL4_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL4_+_22_DOWN_2",        TILE(0x000, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x185, COL4_PAL, H, 0), TILE(0x184, COL4_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL4_+_22_UP_UD_1",       TILE(0x184, COL4_PAL, 0, V), TILE(0x185, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x658
    Metatile("COL4_+_22_UP_UD_2",       TILE(0x030, COL4_PAL, 0, V), TILE(0x031, COL4_PAL, 0, V), TILE(0x186, COL4_PAL, 0, V), TILE(0x187, COL4_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL4_+_22_DOWN_UD_1",     TILE(0x031, COL4_PAL, H, V), TILE(0x030, COL4_PAL, H, V), TILE(0x187, COL4_PAL, H, V), TILE(0x186, COL4_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL4_+_22_DOWN_UD_2",     TILE(0x185, COL4_PAL, H, V), TILE(0x184, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL4_+_66_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x188, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x198, COL4_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL4_+_66_UP_2",          TILE(0x189, COL4_PAL, H, 0), TILE(0x035, COL4_PAL, H, 0), TILE(0x199, COL4_PAL, H, 0), TILE(0x030, COL4_PAL, H, 0), COL_SLOPE_66_UP_2)
    Metatile("COL4_+_66_DOWN_1",        TILE(0x035, COL4_PAL, 0, 0), TILE(0x189, COL4_PAL, 0, 0), TILE(0x030, COL4_PAL, 0, 0), TILE(0x199, COL4_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL4_+_66_DOWN_2",        TILE(0x188, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x198, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL4_+_66_UP_UD_1",       TILE(0x000, COL4_PAL, 0, V), TILE(0x198, COL4_PAL, H, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x188, COL4_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x660
    Metatile("COL4_+_66_UP_UD_2",       TILE(0x199, COL4_PAL, H, V), TILE(0x030, COL4_PAL, H, V), TILE(0x189, COL4_PAL, H, V), TILE(0x035, COL4_PAL, H, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL4_+_66_DOWN_UD_1",     TILE(0x030, COL4_PAL, 0, V), TILE(0x199, COL4_PAL, 0, V), TILE(0x035, COL4_PAL, 0, V), TILE(0x189, COL4_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL4_+_66_DOWN_UD_2",     TILE(0x198, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x188, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x668
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL4_+_NO_OUT_SLOPE_45_UP",      TILE(0x000, COL4_PAL, 0, 0), TILE(0x193, COL4_PAL, 0, 0), TILE(0x192, COL4_PAL, 0, 0), TILE(0x031, COL4_PAL, 0, 0), COL_NONE) // 0x670
    Metatile("COL4_+_NO_OUT_SLOPE_45_DOWN",    TILE(0x193, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x031, COL4_PAL, H, 0), TILE(0x192, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_+_NO_OUT_SLOPE_45_UP_UD",   TILE(0x192, COL4_PAL, 0, V), TILE(0x031, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x193, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_+_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x031, COL4_PAL, H, V), TILE(0x192, COL4_PAL, H, V), TILE(0x193, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_NONE) 
    Metatile("COL4_+_NO_OUT_22_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x194, COL4_PAL, 0, 0), TILE(0x195, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_+_NO_OUT_22_UP_2",          TILE(0x196, COL4_PAL, 0, 0), TILE(0x197, COL4_PAL, 0, 0), TILE(0x030, COL4_PAL, 0, 0), TILE(0x031, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_+_NO_OUT_22_DOWN_1",        TILE(0x197, COL4_PAL, H, 0), TILE(0x196, COL4_PAL, H, 0), TILE(0x031, COL4_PAL, H, 0), TILE(0x030, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_+_NO_OUT_22_DOWN_2",        TILE(0x000, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x195, COL4_PAL, H, 0), TILE(0x194, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_+_NO_OUT_22_UP_UD_1",       TILE(0x194, COL4_PAL, 0, V), TILE(0x195, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), COL_NONE) // 0x678
    Metatile("COL4_+_NO_OUT_22_UP_UD_2",       TILE(0x030, COL4_PAL, 0, V), TILE(0x031, COL4_PAL, 0, V), TILE(0x196, COL4_PAL, 0, V), TILE(0x197, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_+_NO_OUT_22_DOWN_UD_1",     TILE(0x031, COL4_PAL, H, V), TILE(0x030, COL4_PAL, H, V), TILE(0x197, COL4_PAL, H, V), TILE(0x196, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_+_NO_OUT_22_DOWN_UD_2",     TILE(0x195, COL4_PAL, H, V), TILE(0x194, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_+_NO_OUT_66_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x18a, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x19a, COL4_PAL, H, 0), COL_NONE) 
    Metatile("COL4_+_NO_OUT_66_UP_2",          TILE(0x18b, COL4_PAL, H, 0), TILE(0x035, COL4_PAL, H, 0), TILE(0x19b, COL4_PAL, H, 0), TILE(0x030, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_+_NO_OUT_66_DOWN_1",        TILE(0x035, COL4_PAL, 0, 0), TILE(0x18b, COL4_PAL, 0, 0), TILE(0x030, COL4_PAL, 0, 0), TILE(0x19b, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_+_NO_OUT_66_DOWN_2",        TILE(0x18a, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x19a, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_+_NO_OUT_66_UP_UD_1",       TILE(0x000, COL4_PAL, 0, V), TILE(0x19a, COL4_PAL, H, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x18a, COL4_PAL, H, V), COL_NONE) // 0x680
    Metatile("COL4_+_NO_OUT_66_UP_UD_2",       TILE(0x19b, COL4_PAL, H, V), TILE(0x030, COL4_PAL, H, V), TILE(0x18b, COL4_PAL, H, V), TILE(0x035, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_+_NO_OUT_66_DOWN_UD_1",     TILE(0x030, COL4_PAL, 0, V), TILE(0x19b, COL4_PAL, 0, V), TILE(0x035, COL4_PAL, 0, V), TILE(0x18b, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_+_NO_OUT_66_DOWN_UD_2",     TILE(0x19a, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x18a, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), COL_NONE)


    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x688
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("COL4_BRICKS_SLOPE_45_UP",      TILE(0x000, COL4_PAL, 0, 0), TILE(0x19f, COL4_PAL, 0, 0), TILE(0x19e, COL4_PAL, 0, 0), TILE(0x044, COL4_PAL, 0, 0), COL_SLOPE_45_UP) // 0x690
    Metatile("COL4_BRICKS_SLOPE_45_DOWN",    TILE(0x19f, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x044, COL4_PAL, H, 0), TILE(0x19e, COL4_PAL, H, 0), COL_SLOPE_45_DOWN)
    Metatile("COL4_BRICKS_SLOPE_45_UP_UD",   TILE(0x19e, COL4_PAL, 0, V), TILE(0x044, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x19f, COL4_PAL, 0, V), COL_SLOPE_45_UP_UD)
    Metatile("COL4_BRICKS_SLOPE_45_DOWN_UD", TILE(0x044, COL4_PAL, H, V), TILE(0x19e, COL4_PAL, H, V), TILE(0x19f, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_SLOPE_45_DOWN_UD) 
    Metatile("COL4_BRICKS_22_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1ac, COL4_PAL, 0, 0), TILE(0x1ad, COL4_PAL, 0, 0), COL_SLOPE_22_UP_1)
    Metatile("COL4_BRICKS_22_UP_2",          TILE(0x1ae, COL4_PAL, 0, 0), TILE(0x1af, COL4_PAL, 0, 0), TILE(0x043, COL4_PAL, 0, 0), TILE(0x044, COL4_PAL, 0, 0), COL_SLOPE_22_UP_2)
    Metatile("COL4_BRICKS_22_DOWN_1",        TILE(0x1af, COL4_PAL, H, 0), TILE(0x1ae, COL4_PAL, H, 0), TILE(0x044, COL4_PAL, H, 0), TILE(0x043, COL4_PAL, H, 0), COL_SLOPE_22_DOWN_1)
    Metatile("COL4_BRICKS_22_DOWN_2",        TILE(0x000, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x1ad, COL4_PAL, H, 0), TILE(0x1ac, COL4_PAL, H, 0), COL_SLOPE_22_DOWN_2)
    Metatile("COL4_BRICKS_22_UP_UD_1",       TILE(0x1ac, COL4_PAL, 0, V), TILE(0x1ad, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), COL_SLOPE_22_UP_UD_1) // 0x698
    Metatile("COL4_BRICKS_22_UP_UD_2",       TILE(0x043, COL4_PAL, 0, V), TILE(0x044, COL4_PAL, 0, V), TILE(0x1ae, COL4_PAL, 0, V), TILE(0x1af, COL4_PAL, 0, V), COL_SLOPE_22_UP_UD_2)
    Metatile("COL4_BRICKS_22_DOWN_UD_1",     TILE(0x044, COL4_PAL, H, V), TILE(0x043, COL4_PAL, H, V), TILE(0x1af, COL4_PAL, H, V), TILE(0x1ae, COL4_PAL, H, V), COL_SLOPE_22_DOWN_UD_1)
    Metatile("COL4_BRICKS_22_DOWN_UD_2",     TILE(0x1ad, COL4_PAL, H, V), TILE(0x1ac, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_SLOPE_22_DOWN_UD_2)
    Metatile("COL4_BRICKS_66_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x1be, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1bf, COL4_PAL, H, 0), COL_SLOPE_66_UP_1) 
    Metatile("COL4_BRICKS_66_UP_2",          TILE(0x1bc, COL4_PAL, H, 0), TILE(0x044, COL4_PAL, H, 0), TILE(0x1bd, COL4_PAL, H, 0), TILE(0x043, COL4_PAL, H, 0), COL_SLOPE_66_UP_2)
    Metatile("COL4_BRICKS_66_DOWN_1",        TILE(0x044, COL4_PAL, 0, 0), TILE(0x1bc, COL4_PAL, 0, 0), TILE(0x043, COL4_PAL, 0, 0), TILE(0x1bd, COL4_PAL, 0, 0), COL_SLOPE_66_DOWN_1)
    Metatile("COL4_BRICKS_66_DOWN_2",        TILE(0x1be, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1bf, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_SLOPE_66_DOWN_2)
    Metatile("COL4_BRICKS_66_UP_UD_1",       TILE(0x000, COL4_PAL, 0, V), TILE(0x1bf, COL4_PAL, H, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x1be, COL4_PAL, H, V), COL_SLOPE_66_UP_UD_1) // 0x6a0
    Metatile("COL4_BRICKS_66_UP_UD_2",       TILE(0x1bd, COL4_PAL, H, V), TILE(0x043, COL4_PAL, H, V), TILE(0x1bc, COL4_PAL, H, V), TILE(0x044, COL4_PAL, H, V), COL_SLOPE_66_UP_UD_2)
    Metatile("COL4_BRICKS_66_DOWN_UD_1",     TILE(0x043, COL4_PAL, 0, V), TILE(0x1bd, COL4_PAL, 0, V), TILE(0x044, COL4_PAL, 0, V), TILE(0x1bc, COL4_PAL, 0, V), COL_SLOPE_66_DOWN_UD_1)
    Metatile("COL4_BRICKS_66_DOWN_UD_2",     TILE(0x1bf, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x1be, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), COL_SLOPE_66_DOWN_UD_2)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x6a8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL4_BRICKS_NO_OUT_SLOPE_45_UP",      TILE(0x000, COL4_PAL, 0, 0), TILE(0x1ab, COL4_PAL, 0, 0), TILE(0x1aa, COL4_PAL, 0, 0), TILE(0x044, COL4_PAL, 0, 0), COL_NONE) // 0x6b0
    Metatile("COL4_BRICKS_NO_OUT_SLOPE_45_DOWN",    TILE(0x1ab, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x044, COL4_PAL, H, 0), TILE(0x1aa, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_BRICKS_NO_OUT_SLOPE_45_UP_UD",   TILE(0x1aa, COL4_PAL, 0, V), TILE(0x044, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x1ab, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_BRICKS_NO_OUT_SLOPE_45_DOWN_UD", TILE(0x044, COL4_PAL, H, V), TILE(0x1aa, COL4_PAL, H, V), TILE(0x1ab, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_NONE) 
    Metatile("COL4_BRICKS_NO_OUT_22_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1ba, COL4_PAL, 0, 0), TILE(0x1bb, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_BRICKS_NO_OUT_22_UP_2",          TILE(0x1a8, COL4_PAL, 0, 0), TILE(0x1a9, COL4_PAL, 0, 0), TILE(0x043, COL4_PAL, 0, 0), TILE(0x044, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_BRICKS_NO_OUT_22_DOWN_1",        TILE(0x1a9, COL4_PAL, H, 0), TILE(0x1a8, COL4_PAL, H, 0), TILE(0x044, COL4_PAL, H, 0), TILE(0x043, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_BRICKS_NO_OUT_22_DOWN_2",        TILE(0x000, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x1bb, COL4_PAL, H, 0), TILE(0x1ba, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_BRICKS_NO_OUT_22_UP_UD_1",       TILE(0x1ba, COL4_PAL, 0, V), TILE(0x1bb, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), COL_NONE) // 0x6b8
    Metatile("COL4_BRICKS_NO_OUT_22_UP_UD_2",       TILE(0x043, COL4_PAL, 0, V), TILE(0x044, COL4_PAL, 0, V), TILE(0x1a8, COL4_PAL, 0, V), TILE(0x1a9, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_BRICKS_NO_OUT_22_DOWN_UD_1",     TILE(0x044, COL4_PAL, H, V), TILE(0x043, COL4_PAL, H, V), TILE(0x1a9, COL4_PAL, H, V), TILE(0x1a8, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_BRICKS_NO_OUT_22_DOWN_UD_2",     TILE(0x1bb, COL4_PAL, H, V), TILE(0x1ba, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_BRICKS_NO_OUT_66_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x1a7, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1b7, COL4_PAL, H, 0), COL_NONE) 
    Metatile("COL4_BRICKS_NO_OUT_66_UP_2",          TILE(0x1b8, COL4_PAL, H, 0), TILE(0x044, COL4_PAL, H, 0), TILE(0x1b9, COL4_PAL, H, 0), TILE(0x043, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_BRICKS_NO_OUT_66_DOWN_1",        TILE(0x044, COL4_PAL, 0, 0), TILE(0x1b8, COL4_PAL, 0, 0), TILE(0x043, COL4_PAL, 0, 0), TILE(0x1b9, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_BRICKS_NO_OUT_66_DOWN_2",        TILE(0x1a7, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1b7, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_BRICKS_NO_OUT_66_UP_UD_1",       TILE(0x000, COL4_PAL, 0, V), TILE(0x1b7, COL4_PAL, H, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x1a7, COL4_PAL, H, V), COL_NONE) // 0x6c0
    Metatile("COL4_BRICKS_NO_OUT_66_UP_UD_2",       TILE(0x1b9, COL4_PAL, H, V), TILE(0x043, COL4_PAL, H, V), TILE(0x1b8, COL4_PAL, H, V), TILE(0x044, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_BRICKS_NO_OUT_66_DOWN_UD_1",     TILE(0x043, COL4_PAL, 0, V), TILE(0x1b9, COL4_PAL, 0, V), TILE(0x044, COL4_PAL, 0, V), TILE(0x1b8, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_BRICKS_NO_OUT_66_DOWN_UD_2",     TILE(0x1b7, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x1a7, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x6c8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)


    Metatile("COL4_BLK_SLOPE_45_UP",      TILE(0x000, COL4_PAL, 0, 0), TILE(0x1c5, COL4_PAL, 0, 0), TILE(0x1c5, COL4_PAL, 0, 0), TILE(0x03a, COL4_PAL, 0, 0), COL_NONE) // 0x670
    Metatile("COL4_BLK_SLOPE_45_DOWN",    TILE(0x1c5, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x03a, COL4_PAL, H, 0), TILE(0x1c5, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_BLK_SLOPE_45_UP_UD",   TILE(0x1c5, COL4_PAL, 0, V), TILE(0x03a, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x1c5, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_BLK_SLOPE_45_DOWN_UD", TILE(0x03a, COL4_PAL, H, V), TILE(0x1c5, COL4_PAL, H, V), TILE(0x1c5, COL4_PAL, H, V), TILE(0x000, COL4_PAL, 0, V), COL_NONE) 
    Metatile("COL4_BLK_22_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1c6, COL4_PAL, 0, 0), TILE(0x1c7, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_BLK_22_UP_2",          TILE(0x1c6, COL4_PAL, 0, 0), TILE(0x1c7, COL4_PAL, 0, 0), TILE(0x03a, COL4_PAL, 0, 0), TILE(0x03a, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_BLK_22_DOWN_1",        TILE(0x1c7, COL4_PAL, H, 0), TILE(0x1c6, COL4_PAL, H, 0), TILE(0x03a, COL4_PAL, H, 0), TILE(0x03a, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_BLK_22_DOWN_2",        TILE(0x000, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x1c7, COL4_PAL, H, 0), TILE(0x1c6, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_BLK_22_UP_UD_1",       TILE(0x1c6, COL4_PAL, 0, V), TILE(0x1c7, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), COL_NONE) // 0x678
    Metatile("COL4_BLK_22_UP_UD_2",       TILE(0x03a, COL4_PAL, 0, V), TILE(0x03a, COL4_PAL, 0, V), TILE(0x1c6, COL4_PAL, 0, V), TILE(0x1c7, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_BLK_22_DOWN_UD_1",     TILE(0x03a, COL4_PAL, H, V), TILE(0x03a, COL4_PAL, H, V), TILE(0x1c7, COL4_PAL, H, V), TILE(0x1c6, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_BLK_22_DOWN_UD_2",     TILE(0x1c7, COL4_PAL, H, V), TILE(0x1c6, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_BLK_66_UP_1",          TILE(0x000, COL4_PAL, 0, 0), TILE(0x1c9, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1c8, COL4_PAL, 0, 0), COL_NONE) 
    Metatile("COL4_BLK_66_UP_2",          TILE(0x1c9, COL4_PAL, 0, 0), TILE(0x03a, COL4_PAL, 0, 0), TILE(0x1c8, COL4_PAL, 0, 0), TILE(0x03a, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_BLK_66_DOWN_1",        TILE(0x03a, COL4_PAL, H, 0), TILE(0x1c9, COL4_PAL, H, 0), TILE(0x03a, COL4_PAL, H, 0), TILE(0x1c8, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_BLK_66_DOWN_2",        TILE(0x1c9, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), TILE(0x1c8, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, H, 0), COL_NONE)
    Metatile("COL4_BLK_66_UP_UD_1",       TILE(0x000, COL4_PAL, 0, V), TILE(0x1c8, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, V), TILE(0x1c9, COL4_PAL, 0, V), COL_NONE) // 0x680
    Metatile("COL4_BLK_66_UP_UD_2",       TILE(0x1c8, COL4_PAL, 0, V), TILE(0x03a, COL4_PAL, 0, V), TILE(0x1c9, COL4_PAL, 0, V), TILE(0x03a, COL4_PAL, 0, V), COL_NONE)
    Metatile("COL4_BLK_66_DOWN_UD_1",     TILE(0x03a, COL4_PAL, H, V), TILE(0x1c8, COL4_PAL, H, V), TILE(0x03a, COL4_PAL, H, V), TILE(0x1c9, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_BLK_66_DOWN_UD_2",     TILE(0x1c8, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), TILE(0x1c9, COL4_PAL, H, V), TILE(0x000, COL4_PAL, H, V), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x688
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("MINIBLOCK_0001",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x52, 0, 0, 0), COL_MINIBLOCK_0001) // 0x690
    Metatile("MINIBLOCK_0010",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x52, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_MINIBLOCK_0010)
    Metatile("MINIBLOCK_0100",    TILE(0x00, 0, 0, 0), TILE(0x52, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_MINIBLOCK_0100)
    Metatile("MINIBLOCK_1000",    TILE(0x52, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_MINIBLOCK_1000)
    Metatile("MINIBLOCK_0011",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x52, 0, 0, 0), TILE(0x52, 0, 0, 0), COL_MINIBLOCK_0011)
    Metatile("MINIBLOCK_1100",    TILE(0x52, 0, 0, 0), TILE(0x52, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_MINIBLOCK_1100)
    Metatile("MINIBLOCK_1010",    TILE(0x52, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x52, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_MINIBLOCK_1010)
    Metatile("MINIBLOCK_0101",    TILE(0x00, 0, 0, 0), TILE(0x52, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x52, 0, 0, 0), COL_MINIBLOCK_0101)
    Metatile("MINIBLOCK_1011",    TILE(0x52, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x52, 0, 0, 0), TILE(0x52, 0, 0, 0), COL_MINIBLOCK_1011) // 0x698
    Metatile("MINIBLOCK_0111",    TILE(0x00, 0, 0, 0), TILE(0x52, 0, 0, 0), TILE(0x52, 0, 0, 0), TILE(0x52, 0, 0, 0), COL_MINIBLOCK_0111)
    Metatile("MINIBLOCK_1110",    TILE(0x52, 0, 0, 0), TILE(0x52, 0, 0, 0), TILE(0x52, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_MINIBLOCK_1110)
    Metatile("MINIBLOCK_1101",    TILE(0x52, 0, 0, 0), TILE(0x52, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x52, 0, 0, 0), COL_MINIBLOCK_1101)
    Metatile("MINIBLOCK_1001",    TILE(0x52, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x52, 0, 0, 0), COL_MINIBLOCK_1001)
    Metatile("MINIBLOCK_0110",    TILE(0x00, 0, 0, 0), TILE(0x52, 0, 0, 0), TILE(0x52, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_MINIBLOCK_0110)
    Metatile("MINIBLOCK_1111",    TILE(0x52, 0, 0, 0), TILE(0x52, 0, 0, 0), TILE(0x52, 0, 0, 0), TILE(0x52, 0, 0, 0), COL_MINIBLOCK_1111)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("LBG_MINIBLOCK_0001",    TILE(0x00, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), COL_MINIBLOCK_0001) // 0x6a0
    Metatile("LBG_MINIBLOCK_0010",    TILE(0x00, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), COL_MINIBLOCK_0010)
    Metatile("LBG_MINIBLOCK_0100",    TILE(0x00, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), COL_MINIBLOCK_0100)
    Metatile("LBG_MINIBLOCK_1000",    TILE(0x28, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), COL_MINIBLOCK_1000)
    Metatile("LBG_MINIBLOCK_0011",    TILE(0x00, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), COL_MINIBLOCK_0011)
    Metatile("LBG_MINIBLOCK_1100",    TILE(0x28, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), COL_MINIBLOCK_1100)
    Metatile("LBG_MINIBLOCK_1010",    TILE(0x28, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), COL_MINIBLOCK_1010)
    Metatile("LBG_MINIBLOCK_0101",    TILE(0x00, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), COL_MINIBLOCK_0101)
    Metatile("LBG_MINIBLOCK_1011",    TILE(0x28, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), COL_MINIBLOCK_1011) // 0x6a8
    Metatile("LBG_MINIBLOCK_0111",    TILE(0x00, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), COL_MINIBLOCK_0111)
    Metatile("LBG_MINIBLOCK_1110",    TILE(0x28, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), COL_MINIBLOCK_1110)
    Metatile("LBG_MINIBLOCK_1101",    TILE(0x28, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), COL_MINIBLOCK_1101)
    Metatile("LBG_MINIBLOCK_1001",    TILE(0x28, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), COL_MINIBLOCK_1001)
    Metatile("LBG_MINIBLOCK_0110",    TILE(0x00, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), TILE(0x00, LBG_PAL, 0, 0), COL_MINIBLOCK_0110)
    Metatile("LBG_MINIBLOCK_1111",    TILE(0x28, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), TILE(0x28, LBG_PAL, 0, 0), COL_MINIBLOCK_1111)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL1_MINIBLOCK_0001",    TILE(0x00, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), COL_MINIBLOCK_0001) // 0x6b0
    Metatile("COL1_MINIBLOCK_0010",    TILE(0x00, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), COL_MINIBLOCK_0010)
    Metatile("COL1_MINIBLOCK_0100",    TILE(0x00, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), COL_MINIBLOCK_0100)
    Metatile("COL1_MINIBLOCK_1000",    TILE(0x28, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), COL_MINIBLOCK_1000)
    Metatile("COL1_MINIBLOCK_0011",    TILE(0x00, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), COL_MINIBLOCK_0011)
    Metatile("COL1_MINIBLOCK_1100",    TILE(0x28, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), COL_MINIBLOCK_1100)
    Metatile("COL1_MINIBLOCK_1010",    TILE(0x28, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), COL_MINIBLOCK_1010)
    Metatile("COL1_MINIBLOCK_0101",    TILE(0x00, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), COL_MINIBLOCK_0101)
    Metatile("COL1_MINIBLOCK_1011",    TILE(0x28, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), COL_MINIBLOCK_1011) // 0x6b8
    Metatile("COL1_MINIBLOCK_0111",    TILE(0x00, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), COL_MINIBLOCK_0111)
    Metatile("COL1_MINIBLOCK_1110",    TILE(0x28, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), COL_MINIBLOCK_1110)
    Metatile("COL1_MINIBLOCK_1101",    TILE(0x28, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), COL_MINIBLOCK_1101)
    Metatile("COL1_MINIBLOCK_1001",    TILE(0x28, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), COL_MINIBLOCK_1001)
    Metatile("COL1_MINIBLOCK_0110",    TILE(0x00, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), TILE(0x00, COL1_PAL, 0, 0), COL_MINIBLOCK_0110)
    Metatile("COL1_MINIBLOCK_1111",    TILE(0x28, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), TILE(0x28, COL1_PAL, 0, 0), COL_MINIBLOCK_1111)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    
    Metatile("COL2_MINIBLOCK_0001",    TILE(0x00, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), COL_MINIBLOCK_0001) // 0x6c0
    Metatile("COL2_MINIBLOCK_0010",    TILE(0x00, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), COL_MINIBLOCK_0010)
    Metatile("COL2_MINIBLOCK_0100",    TILE(0x00, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), COL_MINIBLOCK_0100)
    Metatile("COL2_MINIBLOCK_1000",    TILE(0x28, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), COL_MINIBLOCK_1000)
    Metatile("COL2_MINIBLOCK_0011",    TILE(0x00, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), COL_MINIBLOCK_0011)
    Metatile("COL2_MINIBLOCK_1100",    TILE(0x28, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), COL_MINIBLOCK_1100)
    Metatile("COL2_MINIBLOCK_1010",    TILE(0x28, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), COL_MINIBLOCK_1010)
    Metatile("COL2_MINIBLOCK_0101",    TILE(0x00, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), COL_MINIBLOCK_0101)
    Metatile("COL2_MINIBLOCK_1011",    TILE(0x28, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), COL_MINIBLOCK_1011) // 0x6c8
    Metatile("COL2_MINIBLOCK_0111",    TILE(0x00, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), COL_MINIBLOCK_0111)
    Metatile("COL2_MINIBLOCK_1110",    TILE(0x28, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), COL_MINIBLOCK_1110)
    Metatile("COL2_MINIBLOCK_1101",    TILE(0x28, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), COL_MINIBLOCK_1101)
    Metatile("COL2_MINIBLOCK_1001",    TILE(0x28, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), COL_MINIBLOCK_1001)
    Metatile("COL2_MINIBLOCK_0110",    TILE(0x00, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), TILE(0x00, COL2_PAL, 0, 0), COL_MINIBLOCK_0110)
    Metatile("COL2_MINIBLOCK_1111",    TILE(0x28, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), TILE(0x28, COL2_PAL, 0, 0), COL_MINIBLOCK_1111)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("COL3_MINIBLOCK_0001",    TILE(0x00, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), COL_MINIBLOCK_0001) // 0x6d0
    Metatile("COL3_MINIBLOCK_0010",    TILE(0x00, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), COL_MINIBLOCK_0010)
    Metatile("COL3_MINIBLOCK_0100",    TILE(0x00, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), COL_MINIBLOCK_0100)
    Metatile("COL3_MINIBLOCK_1000",    TILE(0x28, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), COL_MINIBLOCK_1000)
    Metatile("COL3_MINIBLOCK_0011",    TILE(0x00, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), COL_MINIBLOCK_0011)
    Metatile("COL3_MINIBLOCK_1100",    TILE(0x28, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), COL_MINIBLOCK_1100)
    Metatile("COL3_MINIBLOCK_1010",    TILE(0x28, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), COL_MINIBLOCK_1010)
    Metatile("COL3_MINIBLOCK_0101",    TILE(0x00, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), COL_MINIBLOCK_0101)
    Metatile("COL3_MINIBLOCK_1011",    TILE(0x28, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), COL_MINIBLOCK_1011) // 0x6d8
    Metatile("COL3_MINIBLOCK_0111",    TILE(0x00, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), COL_MINIBLOCK_0111)
    Metatile("COL3_MINIBLOCK_1110",    TILE(0x28, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), COL_MINIBLOCK_1110)
    Metatile("COL3_MINIBLOCK_1101",    TILE(0x28, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), COL_MINIBLOCK_1101)
    Metatile("COL3_MINIBLOCK_1001",    TILE(0x28, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), COL_MINIBLOCK_1001)
    Metatile("COL3_MINIBLOCK_0110",    TILE(0x00, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), TILE(0x00, COL3_PAL, 0, 0), COL_MINIBLOCK_0110)
    Metatile("COL3_MINIBLOCK_1111",    TILE(0x28, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), TILE(0x28, COL3_PAL, 0, 0), COL_MINIBLOCK_1111)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    
    Metatile("COL4_MINIBLOCK_0001",    TILE(0x00, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), COL_MINIBLOCK_0001) // 0x6e0
    Metatile("COL4_MINIBLOCK_0010",    TILE(0x00, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), COL_MINIBLOCK_0010)
    Metatile("COL4_MINIBLOCK_0100",    TILE(0x00, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), COL_MINIBLOCK_0100)
    Metatile("COL4_MINIBLOCK_1000",    TILE(0x28, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), COL_MINIBLOCK_1000)
    Metatile("COL4_MINIBLOCK_0011",    TILE(0x00, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), COL_MINIBLOCK_0011)
    Metatile("COL4_MINIBLOCK_1100",    TILE(0x28, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), COL_MINIBLOCK_1100)
    Metatile("COL4_MINIBLOCK_1010",    TILE(0x28, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), COL_MINIBLOCK_1010)
    Metatile("COL4_MINIBLOCK_0101",    TILE(0x00, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), COL_MINIBLOCK_0101)
    Metatile("COL4_MINIBLOCK_1011",    TILE(0x28, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), COL_MINIBLOCK_1011) // 0x6e8
    Metatile("COL4_MINIBLOCK_0111",    TILE(0x00, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), COL_MINIBLOCK_0111)
    Metatile("COL4_MINIBLOCK_1110",    TILE(0x28, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), COL_MINIBLOCK_1110)
    Metatile("COL4_MINIBLOCK_1101",    TILE(0x28, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), COL_MINIBLOCK_1101)
    Metatile("COL4_MINIBLOCK_1001",    TILE(0x28, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), COL_MINIBLOCK_1001)
    Metatile("COL4_MINIBLOCK_0110",    TILE(0x00, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), TILE(0x00, COL4_PAL, 0, 0), COL_MINIBLOCK_0110)
    Metatile("COL4_MINIBLOCK_1111",    TILE(0x28, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), TILE(0x28, COL4_PAL, 0, 0), COL_MINIBLOCK_1111)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("LBG_GLOW_BOTTOM",                  TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1e0, LBG_PAL, 0, 0), TILE(0x1e0, LBG_PAL, 0, 0), COL_NONE) // 0x6f0
    Metatile("LBG_GLOW_TOP",                     TILE(0x1e0, LBG_PAL, 0, V), TILE(0x1e0, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_GLOW_RIGHT",                   TILE(0x000, LBG_PAL, 0, 0), TILE(0x1e1, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1e1, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_GLOW_LEFT",                    TILE(0x1e1, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1e1, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_GLOW_CORNER_IN_BOTTOM_RIGHT",  TILE(0x000, LBG_PAL, 0, 0), TILE(0x1e1, LBG_PAL, 0, 0), TILE(0x1e0, LBG_PAL, 0, 0), TILE(0x1e2, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_GLOW_CORNER_IN_BOTTOM_LEFT",   TILE(0x1e1, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1e2, LBG_PAL, H, 0), TILE(0x1e0, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_GLOW_CORNER_IN_TOP_RIGHT",     TILE(0x1e0, LBG_PAL, 0, V), TILE(0x1e2, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1e1, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_GLOW_CORNER_IN_TOP_LEFT",      TILE(0x1e2, LBG_PAL, H, V), TILE(0x1e0, LBG_PAL, 0, V), TILE(0x1e1, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE) // 0x6f8
    Metatile("LBG_GLOW_CORNER_OUT_BOTTOM_RIGHT", TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1e3, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_GLOW_CORNER_OUT_BOTTOM_LEFT",  TILE(0x000, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x1e3, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_GLOW_CORNER_OUT_TOP_RIGHT",    TILE(0x000, LBG_PAL, 0, 0), TILE(0x1e3, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("LBG_GLOW_CORNER_OUT_TOP_LEFT",     TILE(0x1e3, LBG_PAL, H, V), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)

    Metatile("EMPTY",                       TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)

    Metatile("COL1_GLOW_BOTTOM",                  TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1e0, COL1_PAL, 0, 0), TILE(0x1e0, COL1_PAL, 0, 0), COL_NONE) // 0x700
    Metatile("COL1_GLOW_TOP",                     TILE(0x1e0, COL1_PAL, 0, V), TILE(0x1e0, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_GLOW_RIGHT",                   TILE(0x000, COL1_PAL, 0, 0), TILE(0x1e1, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1e1, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_GLOW_LEFT",                    TILE(0x1e1, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1e1, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_GLOW_CORNER_IN_BOTTOM_RIGHT",  TILE(0x000, COL1_PAL, 0, 0), TILE(0x1e1, COL1_PAL, 0, 0), TILE(0x1e0, COL1_PAL, 0, 0), TILE(0x1e2, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_GLOW_CORNER_IN_BOTTOM_LEFT",   TILE(0x1e1, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1e2, COL1_PAL, H, 0), TILE(0x1e0, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_GLOW_CORNER_IN_TOP_RIGHT",     TILE(0x1e0, COL1_PAL, 0, V), TILE(0x1e2, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1e1, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_GLOW_CORNER_IN_TOP_LEFT",      TILE(0x1e2, COL1_PAL, H, V), TILE(0x1e0, COL1_PAL, 0, V), TILE(0x1e1, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_GLOW_CORNER_OUT_BOTTOM_RIGHT", TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1e3, COL1_PAL, 0, 0), COL_NONE) // 0x708
    Metatile("COL1_GLOW_CORNER_OUT_BOTTOM_LEFT",  TILE(0x000, COL1_PAL, H, V), TILE(0x000, COL1_PAL, 0, 0), TILE(0x1e3, COL1_PAL, H, 0), TILE(0x000, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_GLOW_CORNER_OUT_TOP_RIGHT",    TILE(0x000, COL1_PAL, 0, 0), TILE(0x1e3, COL1_PAL, 0, V), TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), COL_NONE)
    Metatile("COL1_GLOW_CORNER_OUT_TOP_LEFT",     TILE(0x1e3, COL1_PAL, H, V), TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), COL_NONE)

    Metatile("EMPTY",                       TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), TILE(0x000, COL1_PAL, 0, 0), COL_NONE)
    
    Metatile("COL2_GLOW_BOTTOM",                  TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1e0, COL2_PAL, 0, 0), TILE(0x1e0, COL2_PAL, 0, 0), COL_NONE) // 0x710
    Metatile("COL2_GLOW_TOP",                     TILE(0x1e0, COL2_PAL, 0, V), TILE(0x1e0, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_GLOW_RIGHT",                   TILE(0x000, COL2_PAL, 0, 0), TILE(0x1e1, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1e1, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_GLOW_LEFT",                    TILE(0x1e1, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1e1, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_GLOW_CORNER_IN_BOTTOM_RIGHT",  TILE(0x000, COL2_PAL, 0, 0), TILE(0x1e1, COL2_PAL, 0, 0), TILE(0x1e0, COL2_PAL, 0, 0), TILE(0x1e2, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_GLOW_CORNER_IN_BOTTOM_LEFT",   TILE(0x1e1, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1e2, COL2_PAL, H, 0), TILE(0x1e0, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_GLOW_CORNER_IN_TOP_RIGHT",     TILE(0x1e0, COL2_PAL, 0, V), TILE(0x1e2, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1e1, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_GLOW_CORNER_IN_TOP_LEFT",      TILE(0x1e2, COL2_PAL, H, V), TILE(0x1e0, COL2_PAL, 0, V), TILE(0x1e1, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_GLOW_CORNER_OUT_BOTTOM_RIGHT", TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1e3, COL2_PAL, 0, 0), COL_NONE) // 0x718
    Metatile("COL2_GLOW_CORNER_OUT_BOTTOM_LEFT",  TILE(0x000, COL2_PAL, H, V), TILE(0x000, COL2_PAL, 0, 0), TILE(0x1e3, COL2_PAL, H, 0), TILE(0x000, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_GLOW_CORNER_OUT_TOP_RIGHT",    TILE(0x000, COL2_PAL, 0, 0), TILE(0x1e3, COL2_PAL, 0, V), TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), COL_NONE)
    Metatile("COL2_GLOW_CORNER_OUT_TOP_LEFT",     TILE(0x1e3, COL2_PAL, H, V), TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), COL_NONE)

    Metatile("EMPTY",                       TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), TILE(0x000, COL2_PAL, 0, 0), COL_NONE)
    
    Metatile("COL3_GLOW_BOTTOM",                  TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1e0, COL3_PAL, 0, 0), TILE(0x1e0, COL3_PAL, 0, 0), COL_NONE) // 0x720
    Metatile("COL3_GLOW_TOP",                     TILE(0x1e0, COL3_PAL, 0, V), TILE(0x1e0, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_GLOW_RIGHT",                   TILE(0x000, COL3_PAL, 0, 0), TILE(0x1e1, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1e1, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_GLOW_LEFT",                    TILE(0x1e1, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1e1, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_GLOW_CORNER_IN_BOTTOM_RIGHT",  TILE(0x000, COL3_PAL, 0, 0), TILE(0x1e1, COL3_PAL, 0, 0), TILE(0x1e0, COL3_PAL, 0, 0), TILE(0x1e2, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_GLOW_CORNER_IN_BOTTOM_LEFT",   TILE(0x1e1, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1e2, COL3_PAL, H, 0), TILE(0x1e0, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_GLOW_CORNER_IN_TOP_RIGHT",     TILE(0x1e0, COL3_PAL, 0, V), TILE(0x1e2, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1e1, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_GLOW_CORNER_IN_TOP_LEFT",      TILE(0x1e2, COL3_PAL, H, V), TILE(0x1e0, COL3_PAL, 0, V), TILE(0x1e1, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_GLOW_CORNER_OUT_BOTTOM_RIGHT", TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1e3, COL3_PAL, 0, 0), COL_NONE) // 0x728
    Metatile("COL3_GLOW_CORNER_OUT_BOTTOM_LEFT",  TILE(0x000, COL3_PAL, H, V), TILE(0x000, COL3_PAL, 0, 0), TILE(0x1e3, COL3_PAL, H, 0), TILE(0x000, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_GLOW_CORNER_OUT_TOP_RIGHT",    TILE(0x000, COL3_PAL, 0, 0), TILE(0x1e3, COL3_PAL, 0, V), TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), COL_NONE)
    Metatile("COL3_GLOW_CORNER_OUT_TOP_LEFT",     TILE(0x1e3, COL3_PAL, H, V), TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), COL_NONE)

    Metatile("EMPTY",                       TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), TILE(0x000, COL3_PAL, 0, 0), COL_NONE)
    
    Metatile("COL4_GLOW_BOTTOM",                  TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1e0, COL4_PAL, 0, 0), TILE(0x1e0, COL4_PAL, 0, 0), COL_NONE) // 0x730
    Metatile("COL4_GLOW_TOP",                     TILE(0x1e0, COL4_PAL, 0, V), TILE(0x1e0, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_GLOW_RIGHT",                   TILE(0x000, COL4_PAL, 0, 0), TILE(0x1e1, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1e1, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_GLOW_LEFT",                    TILE(0x1e1, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1e1, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_GLOW_CORNER_IN_BOTTOM_RIGHT",  TILE(0x000, COL4_PAL, 0, 0), TILE(0x1e1, COL4_PAL, 0, 0), TILE(0x1e0, COL4_PAL, 0, 0), TILE(0x1e2, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_GLOW_CORNER_IN_BOTTOM_LEFT",   TILE(0x1e1, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1e2, COL4_PAL, H, 0), TILE(0x1e0, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_GLOW_CORNER_IN_TOP_RIGHT",     TILE(0x1e0, COL4_PAL, 0, V), TILE(0x1e2, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1e1, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_GLOW_CORNER_IN_TOP_LEFT",      TILE(0x1e2, COL4_PAL, H, V), TILE(0x1e0, COL4_PAL, 0, V), TILE(0x1e1, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE) // 0x738
    Metatile("COL4_GLOW_CORNER_OUT_BOTTOM_RIGHT", TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1e3, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_GLOW_CORNER_OUT_BOTTOM_LEFT",  TILE(0x000, COL4_PAL, H, V), TILE(0x000, COL4_PAL, 0, 0), TILE(0x1e3, COL4_PAL, H, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_GLOW_CORNER_OUT_TOP_RIGHT",    TILE(0x000, COL4_PAL, 0, 0), TILE(0x1e3, COL4_PAL, 0, V), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("COL4_GLOW_CORNER_OUT_TOP_LEFT",     TILE(0x1e3, COL4_PAL, H, V), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)

    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)

    Metatile("CIRCULAR_GROUND_SPIKE_BOTTOM",TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1e4, 0, 0, 0), TILE(0x1e4, 0, H, 0), COL_GROUND_SPIKE_BOTTOM)
    Metatile("CIRCULAR_GROUND_SPIKE_TOP",   TILE(0x1e4, 0, 0, V), TILE(0x1e4, 0, H, V), TILE(0x000, 0, 0, 0), TILE(0x000, 0, H, 0), COL_GROUND_SPIKE_TOP)
    Metatile("CIRCULAR_GROUND_SPIKE_RIGHT", TILE(0x000, 0, 0, 0), TILE(0x1e5, 0, 0, V), TILE(0x000, 0, 0, 0), TILE(0x1e5, 0, 0, 0), COL_GROUND_SPIKE_RIGHT)
    Metatile("CIRCULAR_GROUND_SPIKE_LEFT",  TILE(0x1e5, 0, H, V), TILE(0x000, 0, 0, 0), TILE(0x1e5, 0, H, 0), TILE(0x000, 0, 0, 0), COL_GROUND_SPIKE_LEFT)
    Metatile("SQUARE_GROUND_SPIKE_BOTTOM",  TILE(0x000, 0, 0, 0), TILE(0x000, 0, 0, 0), TILE(0x1d3, 0, 0, 0), TILE(0x1d3, 0, H, 0), COL_GROUND_SPIKE_BOTTOM)
    Metatile("SQUARE_GROUND_SPIKE_TOP",     TILE(0x1d3, 0, 0, V), TILE(0x1d3, 0, H, V), TILE(0x000, 0, 0, 0), TILE(0x000, 0, H, 0), COL_GROUND_SPIKE_TOP)
    Metatile("SQUARE_GROUND_SPIKE_RIGHT",   TILE(0x000, 0, 0, 0), TILE(0x1d4, 0, 0, V), TILE(0x000, 0, 0, 0), TILE(0x1d4, 0, 0, 0), COL_GROUND_SPIKE_RIGHT)
    Metatile("SQUARE_GROUND_SPIKE_LEFT",    TILE(0x1d4, 0, H, V), TILE(0x000, 0, 0, 0), TILE(0x1d4, 0, H, 0), TILE(0x000, 0, 0, 0), COL_GROUND_SPIKE_LEFT)
    Metatile("CORNER_GROUNDSPIKE_SQUARE_DOWN_LEFT", TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("CORNER_GROUNDSPIKE_SQUARE_UP_RIGHT",  TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("CORNER_GROUNDSPIKE_SQUARE_UP_LEFT",   TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("CORNER_GROUNDSPIKE_SQUARE_DOWN_LEFT", TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)

    Metatile("OUTLINE_BLOCK",                                                   TILE(0x120, LBG_PAL, 0, 0), TILE(0x120, LBG_PAL, H, 0), TILE(0x120, LBG_PAL, 0, V), TILE(0x120, LBG_PAL, H, V), COL_FULL)
    Metatile("OUTLINE_TOP",                                                     TILE(0x23d, LBG_PAL, 0, 0), TILE(0x23d, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_MINIBLOCK_1100)
    Metatile("OUTLINE_LEFT",                                                    TILE(0x23e, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x23e, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), COL_MINIBLOCK_1010)
    Metatile("OUTLINE_BOTTOM",                                                  TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x23d, LBG_PAL, 0, V), TILE(0x23d, LBG_PAL, 0, V), COL_MINIBLOCK_0011)
    Metatile("OUTLINE_RIGHT",                                                   TILE(0x000, LBG_PAL, 0, 0), TILE(0x23e, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x23e, LBG_PAL, 0, 0), COL_MINIBLOCK_0101)
    Metatile("OUTLINE_LEFT_TOP",                                                TILE(0x120, LBG_PAL, 0, 0), TILE(0x23d, LBG_PAL, 0, 0), TILE(0x23e, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), COL_MINIBLOCK_1110)
    Metatile("OUTLINE_LEFT_BOTTOM",                                             TILE(0x23e, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x120, LBG_PAL, 0, V), TILE(0x23d, LBG_PAL, 0, V), COL_MINIBLOCK_1011)
    Metatile("OUTLINE_BOTTOM_RIGHT",                                            TILE(0x000, LBG_PAL, 0, 0), TILE(0x23e, LBG_PAL, 0, V), TILE(0x23d, LBG_PAL, 0, V), TILE(0x120, LBG_PAL, H, V), COL_MINIBLOCK_0111)
    Metatile("OUTLINE_TOP_RIGHT",                                               TILE(0x23d, LBG_PAL, 0, 0), TILE(0x120, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x23e, LBG_PAL, 0, 0), COL_MINIBLOCK_1101)
// oh my fucking god i forgot about those outlines
//-banana, 03/23/2025
    Metatile("OUTLINE_LEFT_TOP_RIGHT",                                             TILE(0x120, LBG_PAL, 0, 0), TILE(0x120, LBG_PAL, H, 0), TILE(0x23e, LBG_PAL, H, 0), TILE(0x23e, LBG_PAL, 0, 0), COL_FULL)
    Metatile("OUTLINE_TOP_LEFT_BOTTOM",                                            TILE(0x120, LBG_PAL, 0, 0), TILE(0x23d, LBG_PAL, 0, 0), TILE(0x120, LBG_PAL, 0, V), TILE(0x23d, LBG_PAL, 0, V), COL_FULL)
    Metatile("OUTLINE_LEFT_BOTTOM_RIGHT",                                          TILE(0x23e, LBG_PAL, H, 0), TILE(0x23e, LBG_PAL, 0, 0), TILE(0x120, LBG_PAL, 0, V), TILE(0x120, LBG_PAL, H, V), COL_FULL)
    Metatile("OUTLINE_BOTTOM_RIGHT_TOP",                                           TILE(0x23d, LBG_PAL, 0, 0), TILE(0x120, LBG_PAL, H, 0), TILE(0x23d, LBG_PAL, 0, V), TILE(0x120, LBG_PAL, H, V), COL_FULL)
    Metatile("OUTLINE_LEFT_RIGHT",                                                 TILE(0x23e, LBG_PAL, H, 0), TILE(0x23e, LBG_PAL, 0, 0), TILE(0x23e, LBG_PAL, H, 0), TILE(0x23e, LBG_PAL, 0, 0), COL_FULL)
    Metatile("OUTLINE_TOP_BOTTOM",                                                 TILE(0x23d, LBG_PAL, 0, 0), TILE(0x23d, LBG_PAL, 0, 0), TILE(0x23d, LBG_PAL, 0, V), TILE(0x23d, LBG_PAL, 0, V), COL_FULL)
    Metatile("OUTLINE_DOT_TOP_LEFT",                                               TILE(0x23f, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_MINIBLOCK_1000)
//finally, hopefully nothing breaks
//-banana, that same day
//guess what, something broke
//-banana again lmao
    Metatile("OUTLINE_DOT_BOTTOM_LEFT",     TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x23f, LBG_PAL, 0, V), TILE(0x000, LBG_PAL, 0, 0), COL_MINIBLOCK_0010)
    Metatile("OUTLINE_DOT_BOTTOM_RIGHT",    TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x23f, LBG_PAL, H, V), COL_MINIBLOCK_0001)
    Metatile("OUTLINE_DOT_TOP_RIGHT",       TILE(0x000, LBG_PAL, 0, 0), TILE(0x23f, LBG_PAL, H, 0), TILE(0x000, LBG_PAL, 0, 0), TILE(0x000, LBG_PAL, 0, 0), COL_MINIBLOCK_0100)
    Metatile("OUTLINE_LEFT_TOP_W_DOT",      TILE(0x120, LBG_PAL, 0, 0), TILE(0x23d, LBG_PAL, 0, 0), TILE(0x23e, LBG_PAL, H, 0), TILE(0x23f, LBG_PAL, H, V), COL_FULL)
    Metatile("OUTLINE_LEFT_BOTTOM_W_DOT",   TILE(0x23e, LBG_PAL, H, 0), TILE(0x23f, LBG_PAL, H, 0), TILE(0x120, LBG_PAL, 0, V), TILE(0x23d, LBG_PAL, 0, V), COL_FULL)
    Metatile("OUTLINE_BOTTOM_RIGHT_W_DOT",  TILE(0x23f, LBG_PAL, 0, 0), TILE(0x23e, LBG_PAL, 0, V), TILE(0x23d, LBG_PAL, 0, V), TILE(0x120, LBG_PAL, H, V), COL_FULL)
    Metatile("OUTLINE_TOP_RIGHT_W_DOT",     TILE(0x23d, LBG_PAL, 0, 0), TILE(0x120, LBG_PAL, H, 0), TILE(0x23f, LBG_PAL, 0, V), TILE(0x23e, LBG_PAL, 0, 0), COL_FULL)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)

    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                       TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)

    Metatile("18_CROSS_WITH_EMPTY_CENTER",                                      TILE(0x1f0, LBG_PAL, 0, 0), TILE(0x1f0, LBG_PAL, H, 0), TILE(0x1f0, LBG_PAL, 0, V), TILE(0x1f0, LBG_PAL, H, V), COL_NONE)
    Metatile("EMPTY",                                                           TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                                                           TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                                                           TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                                                           TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                                                           TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                                                           TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                                                           TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                                                           TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                                                           TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                                                           TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                                                           TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                                                           TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                                                           TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                                                           TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)
    Metatile("EMPTY",                                                           TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), TILE(0x000, COL4_PAL, 0, 0), COL_NONE)

    Metatile("LGB_18__CROSS_WITH_FULL_CENTER",                                  TILE(0x1f1, LBG_PAL, 0, 0), TILE(0x1f1, LBG_PAL, H, 0), TILE(0x1f1, LBG_PAL, 0, V), TILE(0x1f1, LBG_PAL, H, V), COL_NONE)
    Metatile("LGB_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM",                TILE(0x1f1, LBG_PAL, 0, 0), TILE(0x1f1, LBG_PAL, H, 0), TILE(0x1f2, LBG_PAL, 0, V), TILE(0x1f2, LBG_PAL, H, V), COL_NONE)
    Metatile("LGB_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_RIGHT",                 TILE(0x1f1, LBG_PAL, 0, 0), TILE(0x1f3, LBG_PAL, H, 0), TILE(0x1f1, LBG_PAL, 0, V), TILE(0x1f3, LBG_PAL, H, V), COL_NONE)
    Metatile("LGB_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_TOP",                   TILE(0x1f2, LBG_PAL, 0, 0), TILE(0x1f2, LBG_PAL, H, 0), TILE(0x1f1, LBG_PAL, 0, V), TILE(0x1f1, LBG_PAL, H, V), COL_NONE)
    Metatile("LGB_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT",                  TILE(0x1f3, LBG_PAL, 0, 0), TILE(0x1f1, LBG_PAL, H, 0), TILE(0x1f3, LBG_PAL, 0, V), TILE(0x1f1, LBG_PAL, H, V), COL_NONE)
    Metatile("LGB_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_AND_RIGHT",      TILE(0x1f1, LBG_PAL, 0, 0), TILE(0x1f3, LBG_PAL, H, 0), TILE(0x1f2, LBG_PAL, 0, V), TILE(0x1f4, LBG_PAL, H, V), COL_NONE)
    Metatile("LGB_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_RIGHT_AND_TOP",         TILE(0x1f2, LBG_PAL, 0, 0), TILE(0x1f4, LBG_PAL, H, 0), TILE(0x1f1, LBG_PAL, 0, V), TILE(0x1f3, LBG_PAL, H, V), COL_NONE)
    Metatile("LGB_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_TOP_AND_LEFT",          TILE(0x1f4, LBG_PAL, 0, 0), TILE(0x1f2, LBG_PAL, H, 0), TILE(0x1f3, LBG_PAL, 0, V), TILE(0x1f1, LBG_PAL, H, V), COL_NONE)
    Metatile("LGB_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT_AND_BOTTOM",       TILE(0x1f3, LBG_PAL, 0, 0), TILE(0x1f1, LBG_PAL, H, 0), TILE(0x1f4, LBG_PAL, 0, V), TILE(0x1f2, LBG_PAL, H, V), COL_NONE)
    Metatile("LGB_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_AND_TOP",        TILE(0x1f2, LBG_PAL, 0, 0), TILE(0x1f2, LBG_PAL, H, 0), TILE(0x1f2, LBG_PAL, 0, V), TILE(0x1f2, LBG_PAL, H, V), COL_NONE)
    Metatile("LGB_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT_AND_RIGHT",        TILE(0x1f3, LBG_PAL, 0, 0), TILE(0x1f3, LBG_PAL, H, 0), TILE(0x1f3, LBG_PAL, 0, V), TILE(0x1f3, LBG_PAL, H, V), COL_NONE)
    Metatile("LGB_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT_BOTTOM_AND_RIGHT", TILE(0x1f3, LBG_PAL, 0, 0), TILE(0x1f3, LBG_PAL, H, 0), TILE(0x1f4, LBG_PAL, 0, V), TILE(0x1f4, LBG_PAL, H, V), COL_NONE)
    Metatile("LGB_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_RIGHT_AND_TOP",  TILE(0x1f2, LBG_PAL, 0, 0), TILE(0x1f4, LBG_PAL, H, 0), TILE(0x1f2, LBG_PAL, 0, V), TILE(0x1f4, LBG_PAL, H, V), COL_NONE)
    Metatile("LGB_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_RIGHT_AND_TOP",  TILE(0x1f4, LBG_PAL, 0, 0), TILE(0x1f4, LBG_PAL, H, 0), TILE(0x1f3, LBG_PAL, 0, V), TILE(0x1f3, LBG_PAL, H, V), COL_NONE)
    Metatile("LGB_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_TOP_LEFT_AND_BOTTOM",   TILE(0x1f4, LBG_PAL, 0, 0), TILE(0x1f2, LBG_PAL, H, 0), TILE(0x1f4, LBG_PAL, 0, V), TILE(0x1f2, LBG_PAL, H, V), COL_NONE)
    Metatile("LGB_18_CROSS_OMFG_ITS_OVER_FULL_CENTER_AND_CROSS",                TILE(0x1f4, LBG_PAL, 0, 0), TILE(0x1f4, LBG_PAL, H, 0), TILE(0x1f4, LBG_PAL, 0, V), TILE(0x1f4, LBG_PAL, H, V), COL_NONE)
    
    Metatile("18__CROSS_WITH_FULL_CENTER",                                      TILE(0x1f1, COL1_PAL, 0, 0), TILE(0x1f1, COL1_PAL, H, 0), TILE(0x1f1, COL1_PAL, 0, V), TILE(0x1f1, COL1_PAL, H, V), COL_NONE)
    Metatile("18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM",                    TILE(0x1f1, COL1_PAL, 0, 0), TILE(0x1f1, COL1_PAL, H, 0), TILE(0x1f2, COL1_PAL, 0, V), TILE(0x1f2, COL1_PAL, H, V), COL_NONE)
    Metatile("18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_RIGHT",                     TILE(0x1f1, COL1_PAL, 0, 0), TILE(0x1f3, COL1_PAL, H, 0), TILE(0x1f1, COL1_PAL, 0, V), TILE(0x1f3, COL1_PAL, H, V), COL_NONE)
    Metatile("18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_TOP",                       TILE(0x1f2, COL1_PAL, 0, 0), TILE(0x1f2, COL1_PAL, H, 0), TILE(0x1f1, COL1_PAL, 0, V), TILE(0x1f1, COL1_PAL, H, V), COL_NONE)
    Metatile("18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT",                      TILE(0x1f3, COL1_PAL, 0, 0), TILE(0x1f1, COL1_PAL, H, 0), TILE(0x1f3, COL1_PAL, 0, V), TILE(0x1f1, COL1_PAL, H, V), COL_NONE)
    Metatile("18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_AND_RIGHT",          TILE(0x1f1, COL1_PAL, 0, 0), TILE(0x1f3, COL1_PAL, H, 0), TILE(0x1f2, COL1_PAL, 0, V), TILE(0x1f4, COL1_PAL, H, V), COL_NONE)
    Metatile("18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_RIGHT_AND_TOP",             TILE(0x1f2, COL1_PAL, 0, 0), TILE(0x1f4, COL1_PAL, H, 0), TILE(0x1f1, COL1_PAL, 0, V), TILE(0x1f3, COL1_PAL, H, V), COL_NONE)
    Metatile("18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_TOP_AND_LEFT",              TILE(0x1f4, COL1_PAL, 0, 0), TILE(0x1f2, COL1_PAL, H, 0), TILE(0x1f3, COL1_PAL, 0, V), TILE(0x1f1, COL1_PAL, H, V), COL_NONE)
    Metatile("18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT_AND_BOTTOM",           TILE(0x1f3, COL1_PAL, 0, 0), TILE(0x1f1, COL1_PAL, H, 0), TILE(0x1f4, COL1_PAL, 0, V), TILE(0x1f2, COL1_PAL, H, V), COL_NONE)
    Metatile("18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_AND_TOP",            TILE(0x1f2, COL1_PAL, 0, 0), TILE(0x1f2, COL1_PAL, H, 0), TILE(0x1f2, COL1_PAL, 0, V), TILE(0x1f2, COL1_PAL, H, V), COL_NONE)
    Metatile("18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT_AND_RIGHT",            TILE(0x1f3, COL1_PAL, 0, 0), TILE(0x1f3, COL1_PAL, H, 0), TILE(0x1f3, COL1_PAL, 0, V), TILE(0x1f3, COL1_PAL, H, V), COL_NONE)
    Metatile("18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT_BOTTOM_AND_RIGHT",     TILE(0x1f3, COL1_PAL, 0, 0), TILE(0x1f3, COL1_PAL, H, 0), TILE(0x1f4, COL1_PAL, 0, V), TILE(0x1f4, COL1_PAL, H, V), COL_NONE)
    Metatile("18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_RIGHT_AND_TOP",      TILE(0x1f2, COL1_PAL, 0, 0), TILE(0x1f4, COL1_PAL, H, 0), TILE(0x1f2, COL1_PAL, 0, V), TILE(0x1f4, COL1_PAL, H, V), COL_NONE)
    Metatile("18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_RIGHT_AND_TOP",      TILE(0x1f4, COL1_PAL, 0, 0), TILE(0x1f4, COL1_PAL, H, 0), TILE(0x1f3, COL1_PAL, 0, V), TILE(0x1f3, COL1_PAL, H, V), COL_NONE)
    Metatile("18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_TOP_LEFT_AND_BOTTOM",       TILE(0x1f4, COL1_PAL, 0, 0), TILE(0x1f2, COL1_PAL, H, 0), TILE(0x1f4, COL1_PAL, 0, V), TILE(0x1f2, COL1_PAL, H, V), COL_NONE)
    Metatile("18_CROSS_OMFG_ITS_OVER_FULL_CENTER_AND_CROSS",                    TILE(0x1f4, COL1_PAL, 0, 0), TILE(0x1f4, COL1_PAL, H, 0), TILE(0x1f4, COL1_PAL, 0, V), TILE(0x1f4, COL1_PAL, H, V), COL_NONE)
    
    Metatile("COL2_18_CROSS_WITH_FULL_CENTER_BUT_COL",                          TILE(0x1f1, COL2_PAL, 0, 0), TILE(0x1f1, COL2_PAL, H, 0), TILE(0x1f1, COL2_PAL, 0, V), TILE(0x1f1, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM",               TILE(0x1f1, COL2_PAL, 0, 0), TILE(0x1f1, COL2_PAL, H, 0), TILE(0x1f2, COL2_PAL, 0, V), TILE(0x1f2, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_RIGHT",                TILE(0x1f1, COL2_PAL, 0, 0), TILE(0x1f3, COL2_PAL, H, 0), TILE(0x1f1, COL2_PAL, 0, V), TILE(0x1f3, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_TOP",                  TILE(0x1f2, COL2_PAL, 0, 0), TILE(0x1f2, COL2_PAL, H, 0), TILE(0x1f1, COL2_PAL, 0, V), TILE(0x1f1, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT",                 TILE(0x1f3, COL2_PAL, 0, 0), TILE(0x1f1, COL2_PAL, H, 0), TILE(0x1f3, COL2_PAL, 0, V), TILE(0x1f1, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_AND_RIGHT",     TILE(0x1f1, COL2_PAL, 0, 0), TILE(0x1f3, COL2_PAL, H, 0), TILE(0x1f2, COL2_PAL, 0, V), TILE(0x1f4, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_RIGHT_AND_TOP",        TILE(0x1f2, COL2_PAL, 0, 0), TILE(0x1f4, COL2_PAL, H, 0), TILE(0x1f1, COL2_PAL, 0, V), TILE(0x1f3, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_TOP_AND_LEFT",         TILE(0x1f4, COL2_PAL, 0, 0), TILE(0x1f2, COL2_PAL, H, 0), TILE(0x1f3, COL2_PAL, 0, V), TILE(0x1f1, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT_AND_BOTTOM",      TILE(0x1f3, COL2_PAL, 0, 0), TILE(0x1f1, COL2_PAL, H, 0), TILE(0x1f4, COL2_PAL, 0, V), TILE(0x1f2, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_AND_TOP",       TILE(0x1f2, COL2_PAL, 0, 0), TILE(0x1f2, COL2_PAL, H, 0), TILE(0x1f2, COL2_PAL, 0, V), TILE(0x1f2, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT_AND_RIGHT",       TILE(0x1f3, COL2_PAL, 0, 0), TILE(0x1f3, COL2_PAL, H, 0), TILE(0x1f3, COL2_PAL, 0, V), TILE(0x1f3, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT_BOTTOM_AND_RIGHT",TILE(0x1f3, COL2_PAL, 0, 0), TILE(0x1f3, COL2_PAL, H, 0), TILE(0x1f4, COL2_PAL, 0, V), TILE(0x1f4, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_RIGHT_AND_TOP", TILE(0x1f2, COL2_PAL, 0, 0), TILE(0x1f4, COL2_PAL, H, 0), TILE(0x1f2, COL2_PAL, 0, V), TILE(0x1f4, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_RIGHT_AND_TOP", TILE(0x1f4, COL2_PAL, 0, 0), TILE(0x1f4, COL2_PAL, H, 0), TILE(0x1f3, COL2_PAL, 0, V), TILE(0x1f3, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_TOP_LEFT_AND_BOTTOM",  TILE(0x1f4, COL2_PAL, 0, 0), TILE(0x1f2, COL2_PAL, H, 0), TILE(0x1f4, COL2_PAL, 0, V), TILE(0x1f2, COL2_PAL, H, V), COL_NONE)
    Metatile("COL2_18_CROSS_OMFG_ITS_OVER_FULL_CENTER_AND_CROSS",               TILE(0x1f4, COL2_PAL, 0, 0), TILE(0x1f4, COL2_PAL, H, 0), TILE(0x1f4, COL2_PAL, 0, V), TILE(0x1f4, COL2_PAL, H, V), COL_NONE)

    Metatile("COL3_18_CROSS_WITH_FULL_CENTER_BUT_COL",                          TILE(0x1f1, COL3_PAL, 0, 0), TILE(0x1f1, COL3_PAL, H, 0), TILE(0x1f1, COL3_PAL, 0, V), TILE(0x1f1, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM",               TILE(0x1f1, COL3_PAL, 0, 0), TILE(0x1f1, COL3_PAL, H, 0), TILE(0x1f2, COL3_PAL, 0, V), TILE(0x1f2, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_RIGHT",                TILE(0x1f1, COL3_PAL, 0, 0), TILE(0x1f3, COL3_PAL, H, 0), TILE(0x1f1, COL3_PAL, 0, V), TILE(0x1f3, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_TOP",                  TILE(0x1f2, COL3_PAL, 0, 0), TILE(0x1f2, COL3_PAL, H, 0), TILE(0x1f1, COL3_PAL, 0, V), TILE(0x1f1, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT",                 TILE(0x1f3, COL3_PAL, 0, 0), TILE(0x1f1, COL3_PAL, H, 0), TILE(0x1f3, COL3_PAL, 0, V), TILE(0x1f1, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_AND_RIGHT",     TILE(0x1f1, COL3_PAL, 0, 0), TILE(0x1f3, COL3_PAL, H, 0), TILE(0x1f2, COL3_PAL, 0, V), TILE(0x1f4, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_RIGHT_AND_TOP",        TILE(0x1f2, COL3_PAL, 0, 0), TILE(0x1f4, COL3_PAL, H, 0), TILE(0x1f1, COL3_PAL, 0, V), TILE(0x1f3, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_TOP_AND_LEFT",         TILE(0x1f4, COL3_PAL, 0, 0), TILE(0x1f2, COL3_PAL, H, 0), TILE(0x1f3, COL3_PAL, 0, V), TILE(0x1f1, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT_AND_BOTTOM",      TILE(0x1f3, COL3_PAL, 0, 0), TILE(0x1f1, COL3_PAL, H, 0), TILE(0x1f4, COL3_PAL, 0, V), TILE(0x1f2, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_AND_TOP",       TILE(0x1f2, COL3_PAL, 0, 0), TILE(0x1f2, COL3_PAL, H, 0), TILE(0x1f2, COL3_PAL, 0, V), TILE(0x1f2, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT_AND_RIGHT",       TILE(0x1f3, COL3_PAL, 0, 0), TILE(0x1f3, COL3_PAL, H, 0), TILE(0x1f3, COL3_PAL, 0, V), TILE(0x1f3, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT_BOTTOM_AND_RIGHT",TILE(0x1f3, COL3_PAL, 0, 0), TILE(0x1f3, COL3_PAL, H, 0), TILE(0x1f4, COL3_PAL, 0, V), TILE(0x1f4, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_RIGHT_AND_TOP", TILE(0x1f2, COL3_PAL, 0, 0), TILE(0x1f4, COL3_PAL, H, 0), TILE(0x1f2, COL3_PAL, 0, V), TILE(0x1f4, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_RIGHT_AND_TOP", TILE(0x1f4, COL3_PAL, 0, 0), TILE(0x1f4, COL3_PAL, H, 0), TILE(0x1f3, COL3_PAL, 0, V), TILE(0x1f3, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_TOP_LEFT_AND_BOTTOM",  TILE(0x1f4, COL3_PAL, 0, 0), TILE(0x1f2, COL3_PAL, H, 0), TILE(0x1f4, COL3_PAL, 0, V), TILE(0x1f2, COL3_PAL, H, V), COL_NONE)
    Metatile("COL3_18_CROSS_OMFG_ITS_OVER_FULL_CENTER_AND_CROSS",               TILE(0x1f4, COL3_PAL, 0, 0), TILE(0x1f4, COL3_PAL, H, 0), TILE(0x1f4, COL3_PAL, 0, V), TILE(0x1f4, COL3_PAL, H, V), COL_NONE)

    Metatile("COL4_18_CROSS_WITH_FULL_CENTER_BUT_COL",                          TILE(0x1f1, COL4_PAL, 0, 0), TILE(0x1f1, COL4_PAL, H, 0), TILE(0x1f1, COL4_PAL, 0, V), TILE(0x1f1, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM",               TILE(0x1f1, COL4_PAL, 0, 0), TILE(0x1f1, COL4_PAL, H, 0), TILE(0x1f2, COL4_PAL, 0, V), TILE(0x1f2, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_RIGHT",                TILE(0x1f1, COL4_PAL, 0, 0), TILE(0x1f3, COL4_PAL, H, 0), TILE(0x1f1, COL4_PAL, 0, V), TILE(0x1f3, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_TOP",                  TILE(0x1f2, COL4_PAL, 0, 0), TILE(0x1f2, COL4_PAL, H, 0), TILE(0x1f1, COL4_PAL, 0, V), TILE(0x1f1, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT",                 TILE(0x1f3, COL4_PAL, 0, 0), TILE(0x1f1, COL4_PAL, H, 0), TILE(0x1f3, COL4_PAL, 0, V), TILE(0x1f1, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_AND_RIGHT",     TILE(0x1f1, COL4_PAL, 0, 0), TILE(0x1f3, COL4_PAL, H, 0), TILE(0x1f2, COL4_PAL, 0, V), TILE(0x1f4, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_RIGHT_AND_TOP",        TILE(0x1f2, COL4_PAL, 0, 0), TILE(0x1f4, COL4_PAL, H, 0), TILE(0x1f1, COL4_PAL, 0, V), TILE(0x1f3, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_TOP_AND_LEFT",         TILE(0x1f4, COL4_PAL, 0, 0), TILE(0x1f2, COL4_PAL, H, 0), TILE(0x1f3, COL4_PAL, 0, V), TILE(0x1f1, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT_AND_BOTTOM",      TILE(0x1f3, COL4_PAL, 0, 0), TILE(0x1f1, COL4_PAL, H, 0), TILE(0x1f4, COL4_PAL, 0, V), TILE(0x1f2, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_AND_TOP",       TILE(0x1f2, COL4_PAL, 0, 0), TILE(0x1f2, COL4_PAL, H, 0), TILE(0x1f2, COL4_PAL, 0, V), TILE(0x1f2, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT_AND_RIGHT",       TILE(0x1f3, COL4_PAL, 0, 0), TILE(0x1f3, COL4_PAL, H, 0), TILE(0x1f3, COL4_PAL, 0, V), TILE(0x1f3, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_LEFT_BOTTOM_AND_RIGHT",TILE(0x1f3, COL4_PAL, 0, 0), TILE(0x1f3, COL4_PAL, H, 0), TILE(0x1f4, COL4_PAL, 0, V), TILE(0x1f4, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_RIGHT_AND_TOP", TILE(0x1f2, COL4_PAL, 0, 0), TILE(0x1f4, COL4_PAL, H, 0), TILE(0x1f2, COL4_PAL, 0, V), TILE(0x1f4, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_BOTTOM_RIGHT_AND_TOP", TILE(0x1f4, COL4_PAL, 0, 0), TILE(0x1f4, COL4_PAL, H, 0), TILE(0x1f3, COL4_PAL, 0, V), TILE(0x1f3, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_18_CROSS_WITH_FULL_CENTER_AND_LINE_AT_TOP_LEFT_AND_BOTTOM",  TILE(0x1f4, COL4_PAL, 0, 0), TILE(0x1f2, COL4_PAL, H, 0), TILE(0x1f4, COL4_PAL, 0, V), TILE(0x1f2, COL4_PAL, H, V), COL_NONE)
    Metatile("COL4_18_CROSS_OMFG_ITS_OVER_FULL_CENTER_AND_CROSS",               TILE(0x1f4, COL4_PAL, 0, 0), TILE(0x1f4, COL4_PAL, H, 0), TILE(0x1f4, COL4_PAL, 0, V), TILE(0x1f4, COL4_PAL, H, V), COL_NONE)

};