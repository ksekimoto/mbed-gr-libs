
#ifndef OV7670_CONFIG_H
#define OV7670_CONFIG_H

#include "mbed.h"
#include "camera_config.h"
#include "ov7670_regs.h"
#include "sccb.h"

/* OV7670 camera input config */
static const char OV7670_InitRegTable[][2] = {
    { OV7670_REG_DBLV, 0x4a },  /* COM4 PLL 4x, default=0x0a */
    #if 0 /* 30fps(24MHz) */
    {OV7670_REG_CLKRC, 0x01},   /* CLKRC internal clock pre-scaler */
#else /* 60fps(48MHz) */
    {OV7670_REG_CLKRC, 0x00},   /* CLKRC internal clock pre-scaler */
#endif
    { OV7670_REG_TSLB, 0x04 },  /* OV */
    { OV7670_REG_COM7, 4 },     /* VGA - YUV:0, RGB:4, RAW:1 */
    /*
     * Set the hardware window.  These values from OV don't entirely
     * make sense - hstop is less than hstart.  But they work...
     */
    { OV7670_REG_HSTART, 0x13 },    /* [7:0] HREF start[7:0], [10:8] HREF[2:0] */
    { OV7670_REG_HSTOP, 0x01 },     /* [7:0] HREF end[7:0], [10:] HREF[5:3] */
    { OV7670_REG_HREF, 0xb6 },      /* [7:6] HREF edge offset, [5:3]->HREF end[2:0] [2:0]->HREF start[2:0] */
                                    /* 0x13->0x98+0x06=0x9e, 0x01->0x08+0x06=0x0e */
    { OV7670_REG_VSTART, 0x02 },
    { OV7670_REG_VSTOP, 0x7a },
    { OV7670_REG_VREF, 0x0a },

    { OV7670_REG_COM3, 0 },
    { OV7670_REG_COM14, 0 },
    /* Mystery scaling numbers */
    { OV7670_REG_SCALING_XSC, 0x3a },
    { OV7670_REG_SCALING_YSC, 0x35 },
    { 0x72, 0x11 },
    { 0x73, 0xf0 },
    { 0xa2, 0x02 },
    // { OV7670_REG_COM10, 0x0 },

    /* Gamma curve values, if format is raw, skip */
    { 0x7a, 0x20 },
    { 0x7b, 0x10 },
    { 0x7c, 0x1e },
    { 0x7d, 0x35 },
    { 0x7e, 0x5a },
    { 0x7f, 0x69 },
    { 0x80, 0x76 },
    { 0x81, 0x80 },
    { 0x82, 0x88 },
    { 0x83, 0x8f },
    { 0x84, 0x96 },
    { 0x85, 0xa3 },
    { 0x86, 0xaf },
    { 0x87, 0xc4 },
    { 0x88, 0xd7 },
    { 0x89, 0xe8 },

    /* AGC and AEC parameters.  Note we start by disabling those features,
       then turn them only after tweaking the values. */
    { OV7670_REG_COM8, OV7670_COM8_FASTAEC | OV7670_COM8_AECSTEP | OV7670_COM8_BFILT },
    { 0x01, 0x50 },
    { 0x02, 0x68 },
    { OV7670_REG_GAIN, 0 },
    { OV7670_REG_AECH, 0 },
    { OV7670_REG_COM4, 0x40 }, /* magic reserved bit */
    { OV7670_REG_COM9, 0x18 }, /* 4x gain + magic rsvd bit */
    // { OV7670_REG_BD50MAX, 0x05 },
    { OV7670_REG_BD60MAX, 0x07 },
    { OV7670_REG_AEW, 0x95 },
    { OV7670_REG_AEB, 0x33 },
    { OV7670_REG_VPT, 0xe3 },
    { OV7670_REG_HAECC1, 0x78 },
    { OV7670_REG_HAECC2, 0x68 },
    { 0xa1, 0x03 }, /* magic */
    { OV7670_REG_HAECC3, 0xd8 },
    { OV7670_REG_HAECC4, 0xd8 },
    { OV7670_REG_HAECC5, 0xf0 },
    { OV7670_REG_HAECC6, 0x90 },
    { OV7670_REG_HAECC7, 0x94 },
    { OV7670_REG_COM8, OV7670_COM8_FASTAEC|OV7670_COM8_AECSTEP|OV7670_COM8_BFILT|OV7670_COM8_AGC|OV7670_COM8_AEC },

    /* Almost all of these are magic "reserved" values.  */
    { OV7670_REG_COM5, 0x61 },
    { OV7670_REG_COM6, 0x4b },
    { 0x16, 0x02 },
    { OV7670_REG_MVFP, 0x07 },
    { 0x21, 0x02 },
    { 0x22, 0x91 },
    { 0x29, 0x07 },
    { 0x33, 0x0b },
    { 0x35, 0x0b },
    { 0x37, 0x1d },
    { 0x38, 0x71 },
    { 0x39, 0x2a },
    { OV7670_REG_COM12, 0x78 },
    { 0x4d, 0x40 },
    { 0x4e, 0x20 },
    { OV7670_REG_GFIX, 0 },
    { 0x6b, 0x0a }, // 0x4a -> 0x0a
    { 0x74, 0x10 },
    { 0x8d, 0x4f },
    { 0x8e, 0 },
    { 0x8f, 0 },
    { 0x90, 0 },
    { 0x91, 0 },
    { 0x92, 0x66 }, // added
    { 0x96, 0 },
    { 0x9a, 0x80 }, // 0x00 -> 0x80
    { 0xb0, 0x84 },
    { 0xb1, 0x0c },
    { 0xb2, 0x0e },
    { 0xb3, 0x82 },
    { 0xb8, 0x0a },

    /* More reserved magic, some of which tweaks white balance */
    { 0x43, 0x0a }, // 0x0a -> 0x14
    { 0x44, 0xf0 },
    { 0x45, 0x34 },
    { 0x46, 0x58 },
    { 0x47, 0x28 },
    { 0x48, 0x3a },
    { 0x59, 0x88 },
    { 0x5a, 0x88 },
    { 0x5b, 0x44 },
    { 0x5c, 0x67 },
    { 0x5d, 0x49 },
    { 0x5e, 0x0e },
    { 0x6c, 0x0a },
    { 0x6d, 0x55 },
    { 0x6e, 0x11 },
    { 0x6f, 0x9f }, /* "9e for advance AWB" */
    { 0x6a, 0x40 },
    { OV7670_REG_BLUE, 0x40 },
    { OV7670_REG_RED, 0x60 },   // 0x60 -> 0x40
    { OV7670_REG_COM8, OV7670_COM8_FASTAEC|OV7670_COM8_AECSTEP|OV7670_COM8_BFILT|OV7670_COM8_AGC|OV7670_COM8_AEC|OV7670_COM8_AWB },

    /* Matrix coefficients */
    { 0x4f, 0x80 },
    { 0x50, 0x80 },
    { 0x51, 0 },
    { 0x52, 0x22 },
    { 0x53, 0x5e },
    { 0x54, 0x80 },
    { 0x58, 0x9e },

    { OV7670_REG_COM16, OV7670_COM16_AWBGAIN },
    { OV7670_REG_EDGE, 0 },
    { 0x75, 0x05 }, // 0x05 -> 0x03
    { 0x76, 0xe1 },
    { 0x4c, 0 },
    { 0x77, 0x01 }, // 0x01 -> 0x00
    { OV7670_REG_COM13, 0xc3 }, // 0xc3 -> 0xc2
    { 0x4b, 0x09 },
    { 0xc9, 0x60 },
    { OV7670_REG_COM16, 0x38 },
    { 0x56, 0x40 },

    { 0x34, 0x11 },
    { OV7670_REG_COM11, OV7670_COM11_EXP|OV7670_COM11_HZAUTO_ON },  // 0x12 => 0x0a
    { 0xa4, 0x88 },
    { 0x96, 0 },
    { 0x97, 0x30 },
    { 0x98, 0x20 },
    { 0x99, 0x30 },
    { 0x9a, 0x84 },
    { 0x9b, 0x29 },
    { 0x9c, 0x03 },
    { 0x9d, 0x4c },
    { 0x9e, 0x3f },
    { 0x78, 0x04 },

    /* Extra-weird stuff.  Some sort of multiplexor register */
    { 0x79, 0x01 },
    { 0xc8, 0xf0 },
    { 0x79, 0x0f },
    { 0xc8, 0x00 },
    { 0x79, 0x10 },
    { 0xc8, 0x7e },
    { 0x79, 0x0a },
    { 0xc8, 0x80 },
    { 0x79, 0x0b },
    { 0xc8, 0x01 },
    { 0x79, 0x0c },
    { 0xc8, 0x0f },
    { 0x79, 0x0d },
    { 0xc8, 0x20 },
    { 0x79, 0x09 },
    { 0xc8, 0x80 },
    { 0x79, 0x02 },
    { 0xc8, 0xc0 },
    { 0x79, 0x03 },
    { 0xc8, 0x40 },
    { 0x79, 0x05 },
    { 0xc8, 0x30 },
    { 0x79, 0x26 },
    // application notes
    { 0x2d, 0x00 },     // ADVFL
    { 0x2e, 0x00 },     // ADVFH

};
#define SIZE_OV7670_InitRegTable    (sizeof(OV7670_InitRegTable)/sizeof(uint8_t))

static const char OV7670_InitRegTable_RGB565[][2] = {
    { OV7670_REG_COM7, OV7670_COM7_RGB }, /* Selects RGB mode */
    { OV7670_REG_RGB444, 0 },  /* No RGB444 please */
    { OV7670_REG_COM1, 0x0 },  /* CCIR601 */
    { OV7670_REG_COM15, OV7670_COM15_RGB565 },
    { OV7670_REG_COM9, 0x38 }, /* 16x gain ceiling; 0x8 is reserved bit */
    { 0x4f, 0xb3 },     /* "matrix coefficient 1" */
    { 0x50, 0xb3 },     /* "matrix coefficient 2" */
    { 0x51, 0    },     /* vb */
    { 0x52, 0x3d },     /* "matrix coefficient 4" */
    { 0x53, 0xa7 },     /* "matrix coefficient 5" */
    { 0x54, 0xe4 },     /* "matrix coefficient 6" */
    { OV7670_REG_COM13, OV7670_COM13_GAMMA|OV7670_COM13_UVSAT },
    { 0xff, 0xff },
};
#define SIZE_OV7670_InitRegTable_RGB565    (sizeof(OV7670_InitRegTable_RGB565)/sizeof(uint8_t))

static const char OV7670_InitRegTable_YCBCR422[][2] = {
    { OV7670_REG_COM7, 0x0 },  /* Selects YUV mode */
    { OV7670_REG_RGB444, 0 },  /* No RGB444 please */
    { OV7670_REG_COM1, 0 },    /* CCIR601 */
    { OV7670_REG_COM15, OV7670_COM15_R00FF },
    { OV7670_REG_COM9, 0x48 }, /* 32x gain ceiling; 0x8 is reserved bit */
    { 0x4f, 0x80 },     /* "matrix coefficient 1" */
    { 0x50, 0x80 },     /* "matrix coefficient 2" */
    { 0x51, 0    },     /* vb */
    { 0x52, 0x22 },     /* "matrix coefficient 4" */
    { 0x53, 0x5e },     /* "matrix coefficient 5" */
    { 0x54, 0x80 },     /* "matrix coefficient 6" */
    { OV7670_REG_COM13, OV7670_COM13_GAMMA|OV7670_COM13_UVSAT },
    { 0xff, 0xff },
};
#define SIZE_OV7670_InitRegTable_YCBCR422    (sizeof(OV7670_InitRegTable_YCBCR422)/sizeof(uint8_t))

static const char OV7670_InitRegTable_RAW[][2] = {
    { OV7670_REG_COM7, OV7670_COM7_BAYER },
    { OV7670_REG_COM13, 0x08 }, /* No gamma, magic rsvd bit */
    { OV7670_REG_COM16, 0x3d }, /* Edge enhancement, denoise */
    { OV7670_REG_REG76, 0xe1 }, /* Pix correction, magic rsvd */
    { 0xff, 0xff },
};
#define SIZE_OV7670_InitRegTable_RAW    (sizeof(OV7670_InitRegTable_RAW)/sizeof(uint8_t))

const char OV7670_sw_reset_cmd[2] = {0x12, 0x80};
#define SIZE_OV7670_sw_reset_cmd    (sizeof(OV7670_sw_reset_cmd)/sizeof(uint8_t))

#if 1
static int OV7670_reg_read(uint8_t reg, uint8_t *v) {
    return sccb_reg_read(OV7670_ADDR, reg, v);
}
#endif

#if 1
static int OV7670_reg_write(uint8_t reg, uint8_t v) {
    return sccb_reg_write(OV7670_ADDR, reg, v);
}
#endif

static int OV7670_reg_write_n(const uint8_t *tbl, size_t size) {
    return sccb_reg_write_n(OV7670_ADDR, tbl, size);
}

#if 1
static int OV7670_set_window(uint16_t hs, uint16_t vs, uint16_t hw, uint16_t vw) {
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
        ret = OV7670_reg_write_n((const uint8_t *)OV7670_InitRegTable, SIZE_OV7670_InitRegTable);
        if (ret != 0) {
            return false;
        }
        if (format == DisplayBase::VIDEO_EXTIN_FORMAT_RGB565) {
            ret = OV7670_reg_write_n((const uint8_t *)OV7670_InitRegTable_RGB565, SIZE_OV7670_InitRegTable_RGB565);
        } else if (format == DisplayBase::VIDEO_EXTIN_FORMAT_YCBCR422) {
            ret = OV7670_reg_write_n((const uint8_t *)OV7670_InitRegTable_YCBCR422, SIZE_OV7670_InitRegTable_YCBCR422);
        } else if (format == DisplayBase::VIDEO_EXTIN_FORMAT_BT601) {
            ret = OV7670_reg_write_n((const uint8_t *)OV7670_InitRegTable_RAW, SIZE_OV7670_InitRegTable_RAW);
        } else {
            ret = OV7670_reg_write_n((const uint8_t *)OV7670_InitRegTable_RGB565, SIZE_OV7670_InitRegTable_RGB565);
        }
        if (ret != 0) {
            return false;
        }
        // OV7670_set_window(0, 0, 640, 480);
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
    static bool SetExposure(bool bAuto, uint16_t usManualExposure, uint16_t usManualGain) {
        int ret;
        uint8_t v;

        /* COM8(AGC Enable/AEC Enable) */
        ret = OV7670_reg_read(OV7670_REG_COM8, &v);
        if (ret != 0) {
            return false;
        }
        if (bAuto) {
            v |= (uint8_t)0x05;
        } else {
            v &= (uint8_t)~0x05;
        }
        ret = OV7670_reg_write(OV7670_REG_COM8, v);
        if (ret != 0) {
            return false;
        }
        if (!bAuto) {
            /* AECH/AECL(exposure) */
            v = (uint8_t)((usManualExposure & 0x03C0) >> 2);    // [9:2]
            ret = OV7670_reg_write(OV7670_REG_AECH, v);
            if (ret != 0) {
                return false;
            }
            v = (uint8_t)((usManualExposure & 0xFC00) >> 10);
            ret = OV7670_reg_write(OV7670_REG_AECHH, v);
            if (ret != 0) {
                return false;
            }
            ret = OV7670_reg_read(OV7670_REG_COM1, &v);
            if (ret != 0) {
                return false;
            }
            v = (v & 0xfc) | (uint8_t)(usManualExposure & 0x0003);
            /* GAIN */
            v = (uint8_t)(usManualGain & 0x00FF);
            ret = OV7670_reg_write(OV7670_REG_GAIN, v);
            if (ret != 0) {
                return false;
            }
            ret = OV7670_reg_read(OV7670_REG_VREF, &v);
            if (ret != 0) {
                return false;
            }
            v = (v & 0x3F) | (uint8_t)((usManualGain & 0x0300) >> 2);
            ret = OV7670_reg_write(OV7670_REG_VREF, v);
            if (ret != 0) {
                return false;
            }
        }
        return true;
    }
};

#endif

