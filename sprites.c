#include <stdint.h>

#define SPRITES_FRAME_COUNT 5
#define SPRITES_FRAME_WIDTH 8
#define SPRITES_FRAME_HEIGHT 8

/* Piskel data for "sprites" */

static const uint32_t sprites_data[5][64] = {
{
0xff000000, 0xff000000, 0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xffffffff, 0xff000000, 0xffffffff, 0xff000000, 0xff000000, 0xffffffff, 0xffffffff, 
0xff000000, 0xffffffff, 0xff000000, 0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xffffffff, 0xff000000, 0xffffffff, 0xff000000, 0xffffffff, 0xffffffff, 0xffffffff, 
0xff000000, 0xffffffff, 0xff0000ff, 0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff0000ff, 0xff0000ff, 0xff0000ff, 0xffffffff, 0xff000000, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff0000ff, 0xff0000ff, 0xff0000ff, 0xffffffff, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xffffffff, 0xffffffff, 0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff0fefff, 0xff000000, 0xff000000, 0xff0acaf0, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff0fefff, 0xff000000, 0xff0bd0e3, 0xff0fefff, 0xff0fefff, 0xff09c0e4, 0xff000000, 0xff0acaf0, 
0xff000000, 0xff000000, 0xff0fefff, 0xff0fefff, 0xff0fefff, 0xffc4c3c6, 0xffc3c2c5, 0xff000000, 
0xff000000, 0xffe1e1e1, 0xffc9c8cb, 0xff0de2ff, 0xffc2c1c4, 0xffcacaca, 0xffdbdadc, 0xffbebebe, 
0xffe8e7ea, 0xffffffff, 0xffffffff, 0xff0cd6ff, 0xffc4c3c6, 0xffe8e7ea, 0xffe8e7ea, 0xffe8e7ea, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffe8e7ea, 0xffe8e7ea, 0xffe8e7ea, 0xffd7d7d7, 
0xff000000, 0xffb6b6b6, 0xffd7d7d7, 0xffe8e7ea, 0xffe8e7ea, 0xffe8e7ea, 0xffd7d7d7, 0xff000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff4349d8, 0xff4349d8, 0xff3e44c9, 0xff000000, 
0xff000000, 0xff000000, 0xff575ee8, 0xff4349d8, 0xff4349d8, 0xff3e44c9, 0xff2f35bb, 0xff000000, 
0xff000000, 0xff4349d8, 0xff4349d8, 0xff4349d8, 0xff3e44c9, 0xff2f35bb, 0xff2228ac, 0xff000000, 
0xff000000, 0xff4349d8, 0xff4349d8, 0xff3e44c9, 0xff2f35bb, 0xff2228ac, 0xff000000, 0xff000000, 
0xff000000, 0xff4349d8, 0xff3e44c9, 0xff2f35bb, 0xff2228ac, 0xff13199a, 0xff000000, 0xff000000, 
0xff000000, 0xff3e44c9, 0xff2f35bb, 0xff2228ac, 0xff13199a, 0xff000000, 0xff000000, 0xff000000, 
0xff3e44c9, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff16f3ff, 0xff16f3ff, 0xff11e3f2, 0xff000000, 
0xff000000, 0xff000000, 0xff14f5ff, 0xff16f3ff, 0xff16f3ff, 0xff11e3f2, 0xff0fc7d2, 0xff000000, 
0xff000000, 0xff16f3ff, 0xff16f3ff, 0xff16f3ff, 0xff11e3f2, 0xff0fc7d2, 0xff0cc1cd, 0xff000000, 
0xff000000, 0xff16f3ff, 0xff16f3ff, 0xff11e3f2, 0xff0fc7d2, 0xff0cc1cd, 0xff000000, 0xff000000, 
0xff000000, 0xff16f3ff, 0xff11e3f2, 0xff0fc7d2, 0xff0cc1cd, 0xff0aa9b4, 0xff000000, 0xff000000, 
0xff000000, 0xff11e3f2, 0xff0fc7d2, 0xff0cc1cd, 0xff0aa9b4, 0xff000000, 0xff000000, 0xff000000, 
0xff11e3f2, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff47db56, 0xff47db56, 0xff2eb23b, 0xff000000, 
0xff000000, 0xff000000, 0xff57e866, 0xff47db56, 0xff47db56, 0xff2eb23b, 0xff20a32e, 0xff000000, 
0xff000000, 0xff47db56, 0xff47db56, 0xff47db56, 0xff2eb23b, 0xff20a32e, 0xff188323, 0xff000000, 
0xff000000, 0xff47db56, 0xff47db56, 0xff2eb23b, 0xff20a32e, 0xff188323, 0xff000000, 0xff000000, 
0xff000000, 0xff47db56, 0xff2eb23b, 0xff20a32e, 0xff188323, 0xff0e6f18, 0xff000000, 0xff000000, 
0xff000000, 0xff2eb23b, 0xff20a32e, 0xff188323, 0xff0e6f18, 0xff000000, 0xff000000, 0xff000000, 
0xff2eb23b, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
}
};
