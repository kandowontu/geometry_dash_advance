#include "main.h"
#include "../graphics/includes.h"
#include "metatiles.h"

const COLOR blockPalette[] = {
    0x7C00, 0x7C00, 0x6800, 0x5400, 0x3C00, 0x2800, 0x1400, 0x0000, 0x7D4A, 0x7EB5, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0
    0x0000, 0x7C00, 0x6800, 0x5400, 0x3C00, 0x2800, 0x1400, 0x0000, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 1
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 2
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 3
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 4
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 5
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 6
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x0000, // 7
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 8
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 9
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // a
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // b
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // c
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // d
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x4FF3, 0x03E0, 0x001F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // e
};

const COLOR spritePalette[] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x0000, // 0
    0x0000, 0x0000, 0x7FFF, 0x7E9F, 0x7DDF, 0x7C9F, 0x2CAB, 0x7DEF, 0x3BFF, 0x27DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 1
    0x0000, 0x0000, 0x7FFF, 0x33EB, 0x1BE5, 0x0380, 0x0960, 0x7DEF, 0x7FEE, 0x7FE3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 2
    0x0000, 0x0000, 0x7FFF, 0x7FEE, 0x7F47, 0x7E47, 0x2D22, 0x7DEF, 0x7E3F, 0x7D5F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 3
    0x0000, 0x0000, 0x7FFF, 0x23FF, 0x27DF, 0x2B9F, 0x0D4B, 0x7DEF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 4
    0x0000, 0x0000, 0x7FFF, 0x3A3F, 0x199F, 0x001F, 0x088B, 0x7DEF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 5
    0x0000, 0x0000, 0x7FFF, 0x1F5F, 0x02BF, 0x019F, 0x00EB, 0x7DEF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 6
    0x0000, 0x0000, 0x13BF, 0x0B5F, 0x02DE, 0x025B, 0x0613, 0x01D2, 0x023D, 0x01FC, 0x0196, 0x0150, 0x00CC, 0x0000, 0x0000, 0x0000, // 7
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 8
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 9
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // a
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // b
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // c
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // d
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // e
    0x7C00, 0x7C00, 0x6800, 0x5400, 0x3C00, 0x2800, 0x1400, 0x0000, 0x7D4A, 0x7EB5, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // f
};

const COLOR menu_palette[] = {
    0x7C00, 0x7C00, 0x6800, 0x5400, 0x3C00, 0x2800, 0x1400, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x540A, 0x3C10, 0x2815, 0x141A, 0x0000, // 0
    0x0000, 0x0000, 0x2800, 0x27D8, 0x16CC, 0x09A7, 0x73EA, 0x56A0, 0x35A1, 0x03E0, 0x7FE0, 0x7FFF, 0x13FF, 0x02DF, 0x0000, 0x0000, // 1
    0x0000, 0x0000, 0x5294, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 2
    0x0000, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7C1F, 0x0000, 0x0000, // 3
};

const COLOR icon_kit_palette[] = {
    0x4A52, 0x0000, 0x2529, 0x27D8, 0x16CC, 0x09A7, 0x73EA, 0x56A0, 0x35A1, 0x03E0, 0x7FE0, 0x7FFF, 0x13FF, 0x02DF, 0x0000, 0x0000, // 0
    0x0000, 0x0000, 0x2529, 0x7EDF, 0x7E1F, 0x5D31, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, // 1
    0x0000, 0x0000, 0x13FF, 0x02DF, 0x01DE, 0x0198, 0x7FFF, 0x6739, 0x5294, 0x3DEF, 0x7FE0, 0x7725, 0x5983, 0x0000, 0x0000, 0x0000, // 2
    0x0000, 0x0000, 0x031F, 0x017C, 0x03EC, 0x7E40, 0x03FF, 0x7C1F, 0x00BC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 3
    0x0000, 0x0000, 0x7FFF, 0x6F7B, 0x4A52, 0x4210, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 4
    0x0000, 0x0000, 0x7FFF, 0x7FE0, 0x7725, 0x4210, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 5
    0x7C1F, 0x0000, 0x294A, 0x675F, 0x3DFF, 0x1CFF, 0x001F, 0x0012, 0x000E, 0x000A, 0x0407, 0x2415, 0x2950, 0x18CF, 0x108A, 0x0000, // 6 reds
    0x7C1F, 0x0000, 0x294A, 0x3ADF, 0x227F, 0x01FF, 0x013F, 0x0135, 0x2594, 0x1D2E, 0x14CA, 0x00D2, 0x10CC, 0x00AB, 0x0089, 0x0000, // 7 oranges
    0x7C1F, 0x0000, 0x294A, 0x5FFF, 0x3FDF, 0x03FF, 0x01EF, 0x4F7F, 0x02DF, 0x0192, 0x08CA, 0x3A99, 0x25F4, 0x1D4D, 0x150A, 0x0000, // 8 yellows
    0x7C1F, 0x0000, 0x294A, 0x4FF7, 0x37F6, 0x03EF, 0x03E0, 0x1BFA, 0x02A9, 0x024C, 0x26A0, 0x3FE0, 0x0240, 0x0180, 0x0100, 0x0000, // 9 greens
    0x7C1F, 0x0000, 0x294A, 0x6FF7, 0x73F2, 0x5FE0, 0x7FE0, 0x57EF, 0x4688, 0x31A6, 0x2545, 0x3240, 0x3DE0, 0x3180, 0x2100, 0x0000, // a cyans
    0x7C1F, 0x0000, 0x294A, 0x7FF3, 0x7F00, 0x7DE0, 0x7C00, 0x5520, 0x4800, 0x3820, 0x2420, 0x4980, 0x3520, 0x24C0, 0x1CA0, 0x0000, // b blues
    0x7C1F, 0x0000, 0x294A, 0x7ED7, 0x7DEF, 0x7C0F, 0x480C, 0x7E16, 0x5409, 0x4427, 0x3027, 0x4529, 0x512D, 0x3CEA, 0x30A8, 0x0000, // c purples
    0x7C1F, 0x0000, 0x294A, 0x7EDF, 0x3C1F, 0x3012, 0x200C, 0x7C1F, 0x7C16, 0x3C0F, 0x1809, 0x7DFE, 0x5575, 0x4110, 0x2CCB, 0x0000, // d pinks
    0x7C1F, 0x0000, 0x294A, 0x7EEE, 0x560A, 0x3946, 0x28E4, 0x7FFF, 0x6F7B, 0x56B5, 0x4210, 0x2D6B, 0x2108, 0x0000, 0x0000, 0x0000, // e blues and grayscales
    0x0000, 0x0000, 0x7FFF, 0x294a, 0x2108, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // f palette kit background
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x0000, // 10 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x0000, // 11
    0x0000, 0x0000, 0x0000, 0x27D8, 0x16CC, 0x09A7, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 12
    0x0000, 0x0000, 0x0000, 0x5294, 0x3DEF, 0x2529, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 13
};

const COLOR menu_spr_palette[] = {
    0x0000, 0x0000, 0x13FF, 0x02DF, 0x01DE, 0x0198, 0x5294, 0x35AD, 0x2D6B, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0
    0x0000, 0x0000, 0x7FFF, 0x5294, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 1
    0x0000, 0x7C00, 0x2800, 0x03E0, 0x7FE0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 2
};

const SCR_ENTRY square_background_tilemap[] = {
    0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0003,0x0001,
    0x0001,0x0001,0x0001,0x0001,0x0001,0x0004,0x0001,0x0001,
    0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0005,
    0x0003,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,0x0008,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x000A,
    0x0008,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,0x0008,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x000A,
    0x0008,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,0x0008,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x000A,
    0x0008,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,0x000B,0x000C,
    0x000C,0x000C,0x000C,0x000C,0x000C,0x000D,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x000A,
    0x0008,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x000E,0x000F,0x000F,0x000F,0x000F,0x0010,0x0011,0x0012,
    0x0012,0x0012,0x0012,0x0012,0x0012,0x0013,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x000A,
    0x0008,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0000,0x0000,0x0014,0x0006,0x0006,0x0015,0x0008,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0016,0x0017,0x0017,
    0x0017,0x0017,0x0017,0x0017,0x0017,0x0017,0x0017,0x0018,
    0x0008,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0006,0x0019,0x0014,0x0006,0x0006,0x0007,0x0008,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x001A,0x001B,0x001B,
    0x001B,0x001B,0x001B,0x001B,0x001B,0x001B,0x001B,0x001C,
    0x0008,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x001D,0x001E,0x001F,0x0020,0x0020,0x0021,0x0008,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x000A,
    0x0022,0x000F,0x000F,0x000F,0x000F,0x000F,0x000F,0x0010,
    0x0023,0x0023,0x0023,0x0023,0x0023,0x0024,0x0008,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x000A,
    0x0008,0x0006,0x0006,0x0006,0x0025,0x0026,0x0006,0x0015,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,0x0008,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x000A,
    0x0008,0x0006,0x0006,0x0006,0x0027,0x0026,0x0006,0x0007,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,0x0008,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x000A,
    0x0008,0x0006,0x0006,0x0006,0x0027,0x0028,0x0029,0x002A,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,0x002B,0x002C,
    0x002C,0x002C,0x002C,0x002C,0x002C,0x002D,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x000A,
    0x0008,0x0006,0x0006,0x0006,0x0027,0x0026,0x0006,0x0007,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,0x0008,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x002E,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x000A,
    0x002F,0x0017,0x0017,0x0017,0x0030,0x0031,0x0017,0x0032,
    0x0033,0x000C,0x000C,0x000C,0x000C,0x0034,0x0008,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x000A,
    0x0008,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0015,
    0x0012,0x0012,0x0012,0x0012,0x0012,0x0035,0x0008,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x000A,
    0x0008,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,0x0008,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0036,0x000C,0x000C,
    0x000C,0x000C,0x000C,0x000C,0x000C,0x000C,0x000C,0x0037,
    0x0008,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,0x0008,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x001A,0x001B,0x001B,
    0x001B,0x001B,0x001B,0x001B,0x0038,0x0039,0x0012,0x003A,
    0x0008,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,0x0008,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x003B,0x003C,0x0006,0x000A,
    0x0008,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,0x0008,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x003B,0x003D,0x003E,0x003F,
    0x0008,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0040,0x0041,0x0041,0x0042,0x0041,0x0043,0x0044,0x0045,
    0x0041,0x0041,0x0041,0x0041,0x0041,0x0046,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x003B,0x003C,0x0006,0x000A,
    0x0008,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0006,0x0006,0x0006,0x0047,0x0006,0x0006,0x0006,0x0009,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x003B,0x0048,0x000F,0x0049,
    0x0022,0x000F,0x000F,0x000F,0x000F,0x000F,0x000F,0x0010,
    0x0006,0x0006,0x0006,0x0047,0x0006,0x0006,0x0006,0x0009,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x003B,0x003C,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0015,
    0x0006,0x0006,0x0006,0x0047,0x0006,0x0006,0x0006,0x0009,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x003B,0x003C,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x004C,0x004A,0x004A,0x004B,0x004C,0x004A,0x004A,0x004D,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x004E,0x004F,0x004F,
    0x004F,0x004F,0x004F,0x004F,0x0050,0x003C,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0051,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x003B,0x003C,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0052,
    0x003E,0x003E,0x003E,0x003E,0x003E,0x0053,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x003B,0x003C,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0051,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x003B,0x003C,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0051,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x003B,0x003C,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0051,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x003B,0x003C,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0051,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0009,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x003B,0x003C,0x0006,0x0006,
    0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0007,
    0x001D,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0054,
    0x0020,0x0020,0x0020,0x0020,0x0020,0x0055,0x0020,0x0020,
    0x0020,0x0020,0x0020,0x0020,0x001E,0x0056,0x0020,0x0020,
    0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0021
};


// This is all the color black for transition purposes
const COLOR black_buffer[] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    
};

u16 animated_sprite_timer = 0;

void run_animated_sprites() {
    u32 pad_particle_id = (animated_sprite_timer & 0b1111) << 1;
    memcpy32(&tile_mem_obj[0][PAD_PARTICLE_VRAM_ID], &animated_sprites[pad_particle_id], (sizeof(TILE) / sizeof(u32)) * 2);
    memcpy32(&tile_mem_obj[0][PAD_PARTICLE_VRAM_ID + 2], &animated_sprites[pad_particle_id + 32], (sizeof(TILE) / sizeof(u32)) * 2);

    u32 coin_id = (animated_sprite_timer >> 3) & 0b11;
    memcpy32(&tile_mem_obj[0][COIN_VRAM_ID], &animated_sprites[(coin_id << 4) + COIN_OFFSET], (sizeof(TILE) / sizeof(u32)) * 16);
    
    u32 orb_particle_id = (((animated_sprite_timer >> 2) & 0b1111) << 4);
    memcpy32(&tile_mem_obj[0][ORB_PARTICLE_VRAM_ID], &animated_sprites[orb_particle_id + ORB_OFFSET], (sizeof(TILE) / sizeof(u32)) * 16);

    animated_sprite_timer += 1;
}

void tile_h_flip(u8 *pointer) {
    u8 *tile_ptr = pointer;
    u8 *dst_ptr = tile_ptr + sizeof(TILE);

    // Each byte holds 2 pixels
    for (s32 x = 0; x < 4; x++) {
        u8 dst_x = 3 - x;
        for (s32 y = 0; y < 8; y++) {
            // Get byte and swap nybbles, then put it in the mirrored x pos
            u8 orig_value = tile_ptr[x + (y << 2)];
            u8 final_value = (orig_value << 4) | (orig_value >> 4);
            dst_ptr[dst_x + (y << 2)] = final_value;
        }
    }
}

void tile_v_flip(u8 *pointer) {
    u8 *tile_ptr = pointer;
    u8 *dst_ptr = tile_ptr + sizeof(TILE);

    // Each byte holds 2 pixels
    for (s32 x = 0; x < 4; x++) {
        for (s32 y = 0; y < 8; y++) {
            u8 dst_y = 7 - y;
            // Copy a 4 byte row into the mirrored y pos
            memcpy32(&dst_ptr[dst_y << 2], &tile_ptr[y << 2], 1);
        }
    }
}

ARM_CODE void deoccupy_chr_slots() {
    // If an object has been loaded in this frame, return to avoid desyncs
    if (loaded_object_buffer_offset > 0) return;

    for (s32 i = 0; i < MAX_OBJECTS; i++) {
        u8 was_occupied = chr_slots[i].occupied;
        u32 rom_offset = chr_slots[i].rom_offset;
        u32 vram_offset = chr_slots[i].vram_offset;
        u8 tile_num = chr_slots[i].tile_num;

        // If the slot is already deocuppied (that is, by no existing object updating the occupation), then proceed to setup unloading.
        // Also check if the slot has already been unloaded
        if (!was_occupied && rom_offset != 0xffffffff) {
            unloaded_object_buffer[unloaded_object_buffer_offset] = i;     
            unloaded_object_buffer_offset++;

            // Mark has unloaded here
            chr_slots[i].rom_offset = 0xffffffff;
            next_free_tile_id -= tile_num;

            // Start moving the VRAM offset of objects with an offset greater than this object's offset. Note this is only for OAM objects,
            // actual CHR needs to be updated on the next frame to avoid a single frame of garbage
            for (s32 j = 0; j < MAX_OBJECTS; j++) {
                u32 curr_vram_offset = chr_slots[j].vram_offset;
                // If this object's VRAM offset is greater than the unloaded object's, then it needs to be moved
                if (curr_vram_offset > vram_offset) {
                    chr_slots[j].vram_offset -= tile_num;
                }
            }
            
            chr_slots[i].occupied = FALSE;

            // Only one can be unloaded in a single frame to avoid issues
            return;
        }

        // Deoccupy, objects that are still loaded and use this slot will occupy it back later on this frame
        chr_slots[i].occupied = FALSE;
    }
}

ARM_CODE void load_chr_in_buffer() {
    // Iterate through the buffer
    for (s32 i = loaded_object_buffer_offset; i > 0; i--) {
        s16 slot_id = loaded_object_buffer[i - 1];
        u8 object_slot = chr_slots[slot_id].object_slot;

        struct Object object = object_buffer[object_slot].object;

        u32 rom_offset = chr_slots[slot_id].rom_offset;
        u32 vram_offset = chr_slots[slot_id].vram_offset;
        u8 tile_num = chr_slots[slot_id].tile_num;
        
        // If the object that uses this slot is a block or an slab, then allow changing the chr from a metatile ID
        if (object.type == BASIC_BLOCK_OBJ || object.type == BASIC_SLAB_OBJ) {
            u16 metatile_ID = object.attrib3;
            TILE *tile_ptr = (TILE *) &blockset;

            // An slab is only two tiles big
            s32 num_tiles = object.type == BASIC_SLAB_OBJ ? 2 : 4;
            for (s32 tile = 0; tile < num_tiles; tile++) {
                SCR_ENTRY tile_id = metatiles[metatile_ID][tile];

                // Copy tile into buffer
                memcpy32(vram_copy_buffer, &tile_ptr[tile_id & SE_ID_MASK], (sizeof(TILE) / sizeof(u32)));

                // Flip horizontally if it should be flipped
                if (tile_id & SE_HFLIP) {
                    tile_h_flip(vram_copy_buffer);

                    // Copy back to the start of the buffer
                    memcpy32(vram_copy_buffer, &vram_copy_buffer[sizeof(TILE)], (sizeof(TILE) / sizeof(u32)));
                }

                // Flip vertically if it should be flipped
                if (tile_id & SE_VFLIP) {
                    tile_v_flip(vram_copy_buffer);

                    // Copy back to the start of the buffer
                    memcpy32(vram_copy_buffer, &vram_copy_buffer[sizeof(TILE)], (sizeof(TILE) / sizeof(u32)));
                }

                // Copy to VRAM this tile
                memcpy32(&tile_mem_obj[0][vram_offset + tile], vram_copy_buffer, (sizeof(TILE) / sizeof(u32)));
            }
        } else {
            // Copy to VRAM from ROM
            memcpy32(&tile_mem_obj[0][vram_offset], &sprites_chr[rom_offset], tile_num * (sizeof(TILE) / sizeof(u32)));
        }
    }

    loaded_object_buffer_offset = 0;
}

ARM_CODE void unload_chr_in_buffer() {
    // Iterate through the buffer
    for (s32 i = unloaded_object_buffer_offset; i > 0; i--) {
        s16 slot_id = unloaded_object_buffer[i - 1];
        u32 vram_offset = chr_slots[slot_id].vram_offset;
        u8 tile_num = chr_slots[slot_id].tile_num;

        u16 old_vram_offset = vram_offset + tile_num;

        s16 tiles_to_copy = old_next_free_tile_id - vram_offset;

        // Failsafe in case this becomes negative and moves the entire VRAM a bunch of times
        if (tiles_to_copy < 0) tiles_to_copy = 0;

        // Move left the tiles after this object 
        memcpy32(&tile_mem_obj[0][vram_offset], &tile_mem_obj[0][old_vram_offset], tiles_to_copy * (sizeof(TILE) / sizeof(u32)));
    }

    unloaded_object_buffer_offset = 0;
}

const u8 player_color_mirror_lut[] = {
    0x2, 0xc,
    0x3, 0xc,
    0x4, 0xb,
    0x5, 0xa,
    0x6, 0x9,
    0x7, 0x8,
    0x6, 0x7,
};

ARM_CODE void flip_player_colors(u8 *dst, u8 *src, u8 tile_num) {
    for (s32 curr_tile = 0; curr_tile < tile_num; curr_tile++) {
        for (u32 byte = 0; byte < sizeof(TILE); byte++) {
            s32 index = (curr_tile << 5) + byte;
            
            // Get byte
            u32 tile_byte = src[index];

            u32 left_pixel = obtain_flipped_pixel(tile_byte >> 4);
            
            u32 right_pixel = obtain_flipped_pixel(tile_byte & 0b1111);
            
            // Remove glow pixels if disabled
            if (!save_data.glow_enabled) {
                if (left_pixel == 15) left_pixel = 0;
                if (right_pixel == 15) right_pixel = 0;
            }

            // Set new byte
            dst[index] = (left_pixel << 4) | right_pixel;
        }
    }

}
ARM_CODE void remove_glow_pixels(u8 *dst, u8 *src, u8 tile_num) {
    for (s32 curr_tile = 0; curr_tile < tile_num; curr_tile++) {
        for (u32 byte = 0; byte < sizeof(TILE); byte++) {
            s32 index = (curr_tile << 5) + byte;
            
            // Get byte
            u32 tile_byte = src[index];

            u32 left_pixel = tile_byte >> 4;
            
            u32 right_pixel = tile_byte & 0b1111;
            
            // Remove glow pixels if disabled
            if (left_pixel == 15) left_pixel = 0;
            if (right_pixel == 15) right_pixel = 0;

            // Set new byte
            dst[index] = (left_pixel << 4) | right_pixel;
        }
    }
}

ARM_CODE u32 obtain_flipped_pixel(u32 pixel) {
    for (u32 i = 0; i < sizeof(player_color_mirror_lut) ; i += 2) {
        // Get first byte of table entry
        u8 lut_pixel = player_color_mirror_lut[i];

        // If a match is found, return the second byte
        if (pixel == lut_pixel) {
            return player_color_mirror_lut[i + 1];
        }
        
        // Now get the second byte
        lut_pixel = player_color_mirror_lut[i + 1];

        // If a match is found, return the first byte
        if (pixel == lut_pixel) {
            return player_color_mirror_lut[i];
        }
    }

    // Not found
    return pixel;
}

void copy_pulsing_sprite() {
    u32 index = 0;
    switch (qran() & 0b11) {
        case 0:
            index = PULSING_CIRCUNFERENCE_INDEX;
            break;
        case 1:
            index = PULSING_CIRCLE_INDEX;
            break;
        case 2:
        case 3:
            index = PULSING_FACE_INDEX;
            break;
    }

    memcpy32(&tile_mem_obj[0][PULSING_VRAM_ID], &sprites_chr[index], (sizeof(TILE) / sizeof(u32)) * 4);
}


const TILE *icon_kit[] = {
    cubes,
    ships,
    balls,
    ufos,
    waves,
};

u16 *icon_selection_table[] = {
    &save_data.cube_selected,
    &save_data.ship_selected,
    &save_data.ball_selected,
    &save_data.ufo_selected,
    &save_data.wave_selected
};

u16 *color_selection_table[] = {
    &save_data.p1_col_selected,
    &save_data.p2_col_selected,
    &save_data.glow_col_selected
};

void upload_player_chr(u32 gamemode, u32 player_id) {
    u16 icon_selected = *icon_selection_table[gamemode];

    // Get lower nybble, this is inside the row of icons
    u32 lower = (icon_selected & 0b111) << 1;

    // Get the rest of bits, shift twice to get the proper even 16 tile line
    u32 higher = (icon_selected & ~0b111) << 2;

    u32 index = higher | lower;

    if (player_id == ID_PLAYER_1) {
        // Copy player sprite into VRAM
        if (save_data.glow_enabled) {
            memcpy32(&tile_mem_obj[0][0], &icon_kit[gamemode][index], PLAYER_CHR_SIZE);
            memcpy32(&tile_mem_obj[0][2], &icon_kit[gamemode][index + 0x10], PLAYER_CHR_SIZE);
        } else {
            // Flip colors
            remove_glow_pixels(vram_copy_buffer, (u8*)(&icon_kit[gamemode][index]), 2);
            memcpy32(&tile_mem_obj[0][0], vram_copy_buffer, PLAYER_CHR_SIZE);
            
            remove_glow_pixels(vram_copy_buffer, (u8*)(&icon_kit[gamemode][index + 0x10]), 2);
            memcpy32(&tile_mem_obj[0][2], vram_copy_buffer, PLAYER_CHR_SIZE);
        }
    } else {
        // Flip colors
        flip_player_colors(vram_copy_buffer, (u8*)(&icon_kit[gamemode][index]), 2);
        memcpy32(&tile_mem_obj[0][4], vram_copy_buffer, PLAYER_CHR_SIZE);
        
        flip_player_colors(vram_copy_buffer, (u8*)(&icon_kit[gamemode][index + 0x10]), 2);
        memcpy32(&tile_mem_obj[0][6], vram_copy_buffer, PLAYER_CHR_SIZE);
    }
}
