
#ifndef OV7670_CONFIG_H
#define OV7670_CONFIG_H

#include "mbed.h"
#include "camera_config.h"
#include "ov7670_regs.h"
#include "sccb.h"

/* OV7670 camera input config */
static const char OV7670_InitRegTable[][2] = {
#if 0 /* 30fps(24MHz) */
    {0x11, 0x01}, /* CLKRC internal clock pre-scaler */
#else /* 60fps(48MHz) */
    {0x11, 0x00}, /* CLKRC internal clock pre-scaler */
#endif
    {OV7670_REG_COM7, OV7670_COM7_YUV},
    {OV7670_REG_RGB444, OV7670_RGB444_DISABLE},
    {OV7670_REG_COM15, OV7670_COM15_R00FF},

    {OV7670_REG_TSLB, 0x04},
    {OV7670_REG_TSLB, 0x14}, //この部分を有効にすると、UVの値を0x00固定できるので、
    {OV7670_REG_MANU, 0x00}, //グレースケールの画像が取得できる。
    {OV7670_REG_MANV, 0x00},

    {OV7670_REG_COM1, 0x00},
    {OV7670_REG_COM9, 0x18},     // 4x gain ceiling; 0x8 is reserved bit
    {0x4f, 0x80},         // "matrix coefficient 1"
    {0x50, 0x80},         // "matrix coefficient 2"
    {0x51, 0x00},         // vb
    {0x52, 0x22},         // "matrix coefficient 4"
    {0x53, 0x5e},         // "matrix coefficient 5"
    {0x54, 0x80},         // "matrix coefficient 6"
    {OV7670_REG_COM13, OV7670_COM13_GAMMA|OV7670_COM13_UVSAT|OV7670_COM13_UVSWAP},
};
#define SIZE_OV7670_InitRegTable    (sizeof(OV7670_InitRegTable)/sizeof(uint8_t))

static const char OV7670_InitRegTable_RGB565[][2] = {
#if 0 /* 30fps(24MHz) */
    {0x11, 0x01}, /* CLKRC internal clock pre-scaler */
#else /* 60fps(48MHz) */
    {0x11, 0x00}, /* CLKRC internal clock pre-scaler */
#endif
    {OV7670_REG_COM7, OV7670_COM7_RGB},
    {OV7670_REG_RGB444, OV7670_RGB444_DISABLE},
    {OV7670_REG_COM15, OV7670_COM15_R00FF|OV7670_COM15_RGB565},

    {OV7670_REG_TSLB, 0x04},

    {OV7670_REG_COM1, 0x00},
    {OV7670_REG_COM9, 0x38},      // 16x gain ceiling; 0x8 is reserved bit
    {0x4f, 0xb3},          // "matrix coefficient 1"
    {0x50, 0xb3},          // "matrix coefficient 2"
    {0x51, 0x00},          // vb
    {0x52, 0x3d},          // "matrix coefficient 4"
    {0x53, 0xa7},          // "matrix coefficient 5"
    {0x54, 0xe4},          // "matrix coefficient 6"
    {OV7670_REG_COM13, OV7670_COM13_GAMMA|OV7670_COM13_UVSAT},
};
#define SIZE_OV7670_InitRegTable_RGB565    (sizeof(OV7670_InitRegTable_RGB565)/sizeof(uint8_t))

static const char OV7670_InitRegTable_YCBCR422[][2] = {
#if 0 /* 30fps(24MHz) */
    {0x11, 0x01}, /* CLKRC internal clock pre-scaler */
#else /* 60fps(48MHz) */
    {0x11, 0x00}, /* CLKRC internal clock pre-scaler */
#endif
    {OV7670_REG_COM7, OV7670_COM7_YUV},
    {OV7670_REG_RGB444, OV7670_RGB444_DISABLE},
    {OV7670_REG_COM15, OV7670_COM15_R00FF},

    {OV7670_REG_TSLB, 0x04},
    // {OV7670_REG_TSLB, 0x14}, //この部分を有効にすると、UVの値を0x00固定できるので、
    // {OV7670_REG_MANU, 0x00}, //グレースケールの画像が取得できる。
    {OV7670_REG_MANV, 0x00},

    {OV7670_REG_COM1, 0x00},
    {OV7670_REG_COM9, 0x18},     // 4x gain ceiling; 0x8 is reserved bit
    {0x4f, 0x80},         // "matrix coefficient 1"
    {0x50, 0x80},         // "matrix coefficient 2"
    {0x51, 0x00},         // vb
    {0x52, 0x22},         // "matrix coefficient 4"
    {0x53, 0x5e},         // "matrix coefficient 5"
    {0x54, 0x80},         // "matrix coefficient 6"
    {OV7670_REG_COM13, OV7670_COM13_GAMMA|OV7670_COM13_UVSAT|OV7670_COM13_UVSWAP},
};
#define SIZE_OV7670_InitRegTable_YCBCR422    (sizeof(OV7670_InitRegTable_YCBCR422)/sizeof(uint8_t))

const char OV7670_sw_reset_cmd[2] = {0x12, 0x80};
#define SIZE_OV7670_sw_reset_cmd    (sizeof(OV7670_sw_reset_cmd)/sizeof(uint8_t))

#if 0
static int OV7670_reg_read(uint8_t reg, uint8_t *v) {
    return sccb_reg_read(OV7670_ADDR, reg, v);
}
#endif

#if 0
static int OV7670_reg_write(uint8_t reg, uint8_t v) {
    return sccb_reg_write(OV7670_ADDR, reg, v);
}
#endif

static int OV7670_reg_write_n(const uint8_t *tbl, size_t size) {
    return sccb_reg_write_n(OV7670_ADDR, tbl, size);
}

#if 0
static int OV7670_set_window(I2C *i2c, uint16_t hs, uint16_t vs, uint16_t hw, uint16_t vw) {
    uint16_t endx;
    uint16_t endy;
    uint8_t reg_vref;
    uint8_t reg_href;
    uint8_t v;
    int ret = 0;

    endx = hs + hw;
    endy = vs + vw + vw;

    ret = OV7670_reg_read(0x03, &reg_vref);
    if (ret != 0) {
        return ret;
    }
    reg_vref &= 0xf0;
    ret = OV7670_reg_read(0x32, &reg_href);
    if (ret != 0) {
        return ret;
    }
    reg_href &= 0xc0;
    v = (uint8_t)((uint16_t)reg_href | ((endx & 0x07) << 3) | (hs & 0x07));
    ret = OV7670_reg_write(0x32, v);
    if (ret != 0) {
        return ret;
    }
    v = (uint8_t)((hs & 0x07f8) >> 3);
    ret = OV7670_reg_write(0x17, v);
    if (ret != 0) {
        return ret;
    }
    v = (uint8_t)((endx & 0x07f8) >> 3);
    ret = OV7670_reg_write(0x18, v);
    if (ret != 0) {
        return ret;
    }
    v = (uint8_t)((uint16_t)reg_vref | ((endy & 0x03) << 2) | (vs & 0x03));
    ret = OV7670_reg_write(0x03, v);
    if (ret != 0) {
        return ret;
    }
    v = (uint8_t)(vs >> 2);
    ret = OV7670_reg_write(0x19, v);
    if (ret != 0) {
        return ret;
    }
    v = (uint8_t)(endy >> 2);
    ret = OV7670_reg_write(0x1a, v);
    return ret;
}
#endif

class OV7670_config : public camera_config {

public:

    /** Initialise
     *
     * @return true = success, false = failure
     */
    virtual bool Initialise(DisplayBase::video_extin_format_t format) {
        int ret;

        ret = OV7670_reg_write_n((const uint8_t *)OV7670_sw_reset_cmd, SIZE_OV7670_sw_reset_cmd);
        if (ret != 0) {
            return false;
        }
        ThisThread::sleep_for(10ms);

        if (format == DisplayBase::VIDEO_EXTIN_FORMAT_RGB565) {
            ret = OV7670_reg_write_n((const uint8_t *)OV7670_InitRegTable_RGB565, SIZE_OV7670_InitRegTable_RGB565);
        } else if (format == DisplayBase::VIDEO_EXTIN_FORMAT_YCBCR422) {
            ret = OV7670_reg_write_n((const uint8_t *)OV7670_InitRegTable_YCBCR422, SIZE_OV7670_InitRegTable_YCBCR422);
        } else {
            ret = OV7670_reg_write_n((const uint8_t *)OV7670_InitRegTable, SIZE_OV7670_InitRegTable);
        }
        if (ret != 0) {
            return false;
        }
        return true;
    }

    virtual bool Initialise() {
        return Initialise(DisplayBase::VIDEO_EXTIN_FORMAT_BT601);
    }

    virtual void SetExtInConfig(DisplayBase::video_ext_in_config_t * p_cfg, DisplayBase::video_extin_format_t format) {
        p_cfg->inp_format     = format;
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

    virtual void SetExtInConfig(DisplayBase::video_ext_in_config_t * p_cfg) {
        SetExtInConfig(p_cfg, DisplayBase::VIDEO_EXTIN_FORMAT_BT601);
    }

    /** Exposure and Gain Setting
     *
     * @param[in]      bAuto             : Automatic adjustment ON/OFF(AEC/AGC)
     * @param[in]      usManualExposure  : Exposure time at automatic adjustment OFF  (number of lines)
     * @param[in]      usManualGain      : Gain at automatic adjustment OFF �i0x00-0xFF)
     * @return true = success, false = failure
     */
    static bool SetExposure(bool bAuto, uint16_t usManualExposure, uint8_t usManualGain) {
        return true;
    }
};

#endif

