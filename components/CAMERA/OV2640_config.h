
#ifndef OV2640_CONFIG_H
#define OV2640_CONFIG_H

#include "mbed.h"
#include "camera_config.h"
#include "ov2640_regs.h"
#include "sccb.h"

static const char OV2640_InitRegTable[][2] = {
    //{0xff, 0x01},   // Table 13
    //{0x12, 0x80},   // COM7, SRST
    //delay(1ms)

    { 0xff, 0x00 },   // Table 12
    { 0x2c, 0xff },   // RSVD
    { 0x2e, 0xdf },   // VSYNC Pulse width LSB 8 bits
    { 0xff, 0x01 },
    { 0x3c, 0x32 },   // ??
    { 0x11, 0x00 },   // CLKRC Clock divider=0
    { 0x09, 0x02 },   // COM2 2x
    { 0x04, 0xa8 },   // REG04 v flip and h mirro
    { 0x13, 0xe5 },   // COM8
    { 0x14, 0x48 },   // COM9 8x
    { 0x15, 0x00 },   // COM10
    { 0x2c, 0x0c },   // RSVD
    { 0x33, 0x78 },   // RSVD
    { 0x3a, 0x33 },   // ??
    { 0x3b, 0xfb },   // ??
    { 0x3e, 0x00 },   // ??
    { 0x43, 0x11 },   // ??
    { 0x16, 0x10 },
    { 0x39, 0x92 },   //test 92
    { 0x23, 0x00 },
    { 0x36, 0x1a },
    { 0x07, 0xc0 },
    { 0x4c, 0x00 },
    { 0x48, 0x00 },
    { 0x5b, 0x00 },
    { 0x4a, 0x81 },
    { 0x21, 0x99 },
    { 0x24, 0x40 },
    { 0x25, 0x38 },
    { 0x26, 0x82 },
    { 0x5c, 0x00 },
    { 0x63, 0x00 },
    { 0x46, 0x22 },   // FLL
    { 0x0c, 0x3c },
    { 0x61, 0x70 },
    { 0x62, 0x80 },
    { 0x7c, 0x05 },
    { 0x20, 0x80 },
    { 0x28, 0x30 },
    { 0x6c, 0x00 },
    { 0x6d, 0x80 },
    { 0x6e, 0x00 },
    { 0x70, 0x02 },
    { 0x71, 0x94 },
    { 0x73, 0xc1 },
    { 0x5a, 0x57 },
    { 0x37, 0xc0 },
    { 0x4f, 0xca },   // 50Hz Banding AEC 8 LSBs
    { 0x50, 0xa8 },   // 60Hz Banging AEC 8 LSBs
    { 0x5a, 0x23 },
    { 0x6d, 0x00 },
    { 0x3d, 0x38 },
    { 0xff, 0x00 },
    { 0xe5, 0x7f },
    { 0xf9, 0xc0 },
    { 0x41, 0x24 },
    { 0xe0, 0x14 },   // OV2640_RESET JPEG, DVP
    { 0x76, 0xff },
    { 0x33, 0xa0 },
    { 0x42, 0x20 },
    { 0x43, 0x18 },
    { 0x4c, 0x00 },
    { 0x87, 0xd5 },
    { 0x88, 0x3f },
    { 0xd9, 0x10 },
    { 0xd3, 0x82 },
    { 0xc8, 0x08 },
    { 0xc9, 0x80 },
    { 0x7c, 0x00 },
    { 0x7d, 0x00 },
    { 0x7c, 0x03 },
    { 0x7d, 0x48 },
    { 0x7d, 0x48 },
    { 0x7c, 0x08 },
    { 0x7d, 0x20 },
    { 0x7d, 0x10 },
    { 0x7d, 0x0e },

    { 0x90, 0x00 },
    { 0x91, 0x0e },
    { 0x91, 0x1a },
    { 0x91, 0x31 },
    { 0x91, 0x5a },
    { 0x91, 0x69 },
    { 0x91, 0x75 },
    { 0x91, 0x7e },
    { 0x91, 0x88 },
    { 0x91, 0x8f },
    { 0x91, 0x96 },
    { 0x91, 0xa3 },
    { 0x91, 0xaf },
    { 0x91, 0xc4 },
    { 0x91, 0xd7 },
    { 0x91, 0xe8 },
    { 0x91, 0x20 },

    { 0x92, 0x00 },
    { 0x93, 0x06 },
    { 0x93, 0xe3 },
    { 0x93, 0x05 },
    { 0x93, 0x05 },
    { 0x93, 0x00 },
    { 0x93, 0x04 },
    { 0x93, 0x00 },
    { 0x93, 0x00 },
    { 0x93, 0x00 },
    { 0x93, 0x00 },
    { 0x93, 0x00 },
    { 0x93, 0x00 },
    { 0x93, 0x00 },

    { 0x96, 0x00 },
    { 0x97, 0x08 },
    { 0x97, 0x19 },
    { 0x97, 0x02 },
    { 0x97, 0x0c },
    { 0x97, 0x24 },
    { 0x97, 0x30 },
    { 0x97, 0x28 },
    { 0x97, 0x26 },
    { 0x97, 0x02 },
    { 0x97, 0x98 },
    { 0x97, 0x80 },
    { 0x97, 0x00 },
    { 0x97, 0x00 },

    { 0xc3, 0xed },
    { 0xa4, 0x00 },
    { 0xa8, 0x00 },
    { 0xc5, 0x11 },
    { 0xc6, 0x51 },
    { 0xbf, 0x80 },
    { 0xc7, 0x10 },
    { 0xb6, 0x66 },
    { 0xb8, 0xa5 },
    { 0xb7, 0x64 },
    { 0xb9, 0x7c },
    { 0xb3, 0xaf },
    { 0xb4, 0x97 },
    { 0xb5, 0xff },
    { 0xb0, 0xc5 },
    { 0xb1, 0x94 },
    { 0xb2, 0x0f },
    { 0xc4, 0x5c },

    { 0x5a, 0xc8 },
    { 0x5b, 0x96 },
    { 0x5c, 0x00 },

    { 0xc3, 0xed },
    { 0x7f, 0x00 },

    { 0xe5, 0x1f },
    { 0xdd, 0x7f },
    { 0x05, 0x00 },
#if 0   //color bar
    {   0xff, 0x01},
    {   0x12, 0x02},
#endif
    { OV2640_BANK_SEL, OV2640_BANK_SEL_DSP },
    { OV2640_RESET, OV2640_RESET_DVP },
    { 0xC2, 0x0C },   // CTRO0 YUV422, YUV_EN
    { 0xD7, 0x01 },
    { 0xDA, 0x01 },   // IMAGE_MODE_LBYTE_FIRST
    { 0xE1, 0x67 },
    { OV2640_RESET, 0x00 },
    { 0x00, 0x00 }
};
#define SIZE_OV2640_InitRegTable    (sizeof(OV2640_InitRegTable)/sizeof(uint8_t))

static const char OV2640_svga_config[][2] = { { 0xff, 0x01 },   //bank sel
    { 0x35, 0xda },   //[SVGA]:
    { 0x22, 0x1a },   //[SVGA]:
    { 0x37, 0xc3 },   //[SVGA]:
    { 0x34, 0xc0 },   //[SVGA]:
    { 0x06, 0x88 },   //[SVGA]:
    { 0x0d, 0x87 },   //[SVGA]:
    { 0x0e, 0x41 },   //[SVGA]:
    { 0x42, 0x03 },   //[SVGA]:
    { 0x3d, 0x34 },   //[SVGA]:
    { 0x12, 0x40 },   //[SVGA]:  COM7,COM7_RES_SVGA  SVGA
    { 0x03, 0x0f },   //[SVGA]:  COM1,0x0F
    { 0x17, 0x11 },   //[SVGA]:HSTART
    { 0x18, 0x43 },   //[SVGA]:HSTOP
    { 0x19, 0x00 },   //[SVGA]:VSTART
    { 0x1a, 0x4b },   //[SVGA]:VSTOP
    { 0x32, 0x09 },   //[SVGA]:REG32

    { 0xff, 0x00 },   //bank sel
    { 0xc0, 0x64 },   //[SVGA]:HSIZE8 SVGA_HSIZE>>3
    { 0xc1, 0x4b },   //[SVGA]:VSIZE8 SVGA_VSIZE>>3
    { 0x8c, 0x00 },   //[SVGA]:SIZEL
    { 0x86, 0x3d },   //[SVGA]:CTRL2
    { 0x50, 0x00 },   //[SVGA]:CTRLI
    { 0x51, 0xc8 },   //[SVGA]:HSIZE (200)
    { 0x52, 0x96 },   //[SVGA]:VSIZE (150)
    { 0x53, 0x00 },   //[SVGA]:XOFFL (0)
    { 0x54, 0x00 },   //[SVGA]:YOFFL (0)
    { 0x55, 0x00 },   //[SVGA]:VHYX  (0)
    { 0xd3, 0x02 },   //[SVGA]:R_DVP_SP
};
#define SIZE_OV2640_svga_config    (sizeof(OV2640_svga_config)/sizeof(uint8_t))

static uint8_t OV2640_sw_reset_cmd[2] = {0x12, 0x80};
#define SIZE_OV2640_sw_reset_cmd    (sizeof(OV2640_sw_reset_cmd)/sizeof(uint8_t))

static uint8_t OV2640_change_tbl[2] = {0xff, 0x01};
#define SIZE_OV2640_change_tbl    (sizeof(OV2640_change_tbl)/sizeof(uint8_t))

static int OV2640_reg_read(uint8_t reg, uint8_t *v) {
    return sccb_reg_read(OV2640_ADDR, reg, v);
}

static int OV2640_reg_write(uint8_t reg, uint8_t v) {
    return sccb_reg_write(OV2640_ADDR, reg, v);
}

static int OV2640_reg_write_n(const uint8_t *tbl, size_t size) {
    return sccb_reg_write_n(OV2640_ADDR, tbl, size);
}

class OV2640_config : public camera_config {
public:

    /** Initialise
     *
     * @return true = success, false = failure
     */
    virtual bool Initialise() {
        /* OV2640 camera input config */
        int ret;

        ret = OV2640_reg_write_n((const uint8_t *)OV2640_change_tbl, SIZE_OV2640_change_tbl);
        if (ret != 0) {
            return false;
        }
        ret = OV2640_reg_write_n((const uint8_t *)OV2640_sw_reset_cmd, SIZE_OV2640_sw_reset_cmd);
        if (ret != 0) {
            return false;
        }
        ThisThread::sleep_for(1ms);

        ret = OV2640_reg_write_n((const uint8_t *)OV2640_InitRegTable, SIZE_OV2640_InitRegTable);
        if (ret != 0) {
            return false;
        }
        ret = OV2640_reg_write_n((const uint8_t *)OV2640_svga_config, SIZE_OV2640_svga_config);
        if (ret != 0) {
            return false;
        }
        return true;
    }

    virtual void SetExtInConfig(DisplayBase::video_ext_in_config_t * p_cfg) {
        p_cfg->inp_format     = DisplayBase::VIDEO_EXTIN_FORMAT_BT601; /* BT601 8bit YCbCr format */
        p_cfg->inp_pxd_edge   = DisplayBase::EDGE_RISING;              /* Clock edge select for capturing data          */
        p_cfg->inp_vs_edge    = DisplayBase::EDGE_RISING;              /* Clock edge select for capturing Vsync signals */
        p_cfg->inp_hs_edge    = DisplayBase::EDGE_RISING;              /* Clock edge select for capturing Hsync signals */
        p_cfg->inp_endian_on  = DisplayBase::OFF;                      /* External input bit endian change on/off       */
        p_cfg->inp_swap_on    = DisplayBase::OFF;                      /* External input B/R signal swap on/off         */
        p_cfg->inp_vs_inv     = DisplayBase::SIG_POL_NOT_INVERTED;     /* External input DV_VSYNC inversion control     */
        p_cfg->inp_hs_inv     = DisplayBase::SIG_POL_NOT_INVERTED;     /* External input DV_HSYNC inversion control     */
        p_cfg->inp_f525_625   = DisplayBase::EXTIN_LINE_525;           /* Number of lines for BT.656 external input */
        p_cfg->inp_h_pos      = DisplayBase::EXTIN_H_POS_YCBYCR;       /* Y/Cb/Y/Cr data string start timing to Hsync reference */
        p_cfg->cap_vs_pos     = 4+21;                                  /* Capture start position from Vsync */
        p_cfg->cap_hs_pos     = 68;                                    /* Capture start position form Hsync */
        p_cfg->cap_width      = 640;                                   /* Capture width Max */
        p_cfg->cap_height     = 480;                                   /* Capture height Max */
    }

    /** Exposure and Gain Setting
     *
     * @param[in]      bAuto             : Automatic adjustment ON/OFF(AEC/AGC)
     * @param[in]      usManualExposure  : Exposure time at automatic adjustment OFF  (number of lines)
     * @param[in]      usManualGain      : Gain at automatic adjustment OFF �i0x00-0xFF)
     * @return true = success, false = failure
     */
    static bool SetExposure(bool bAuto, uint16_t usManualExposure, uint8_t usManualGain) {
        int ret;
        uint8_t v;
        /* COM8(AGC Enable/AEC Enable) */
        ret = OV2640_reg_read(0x13, &v);
        if (ret != 0) {
            return false;
        }
        if (bAuto) {
            v |= (uint8_t)0x05;
        } else {
            v &= (uint8_t)~0x05;
        }
        ret = OV2640_reg_write(0x13, v);
        if (ret != 0) {
            return false;
        }
        if (!bAuto) {
            /* AECH/AECL(exposure) */
            /* AEC[1:0] */
            ret = OV2640_reg_read(0x04, &v);
            if (ret != 0) {
                return false;
            }
            v &= 0xfc;
            v |= (uint8_t)(usManualExposure & 0x0003);
            ret = OV2640_reg_write(0x04, v);
            if (ret != 0) {
                return false;
            }
            /* AEC[9:2] */
            v = (uint8_t)((usManualExposure >> 2) & 0x00ff);
            ret = OV2640_reg_write(0x10, v);
            if (ret != 0) {
                return false;
            }
            /* AEC[15:10] + AGC[9:8] */
            v = (uint8_t)((usManualExposure >> 10) & 0x003f) + (uint8_t)(((usManualGain >> 8) & 0x03) << 6);
            ret = OV2640_reg_write(0x45, v);
            if (ret != 0) {
                return false;
            }
            /* AGC[7:0] */
            v = (uint8_t)(usManualGain & 0xff);
            ret = OV2640_reg_write(0x00, v);
            if (ret != 0) {
                return false;
            }
        }
        return true;
    }
};

#endif

