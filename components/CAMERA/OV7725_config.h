
#ifndef OV7725_CONFIG_H
#define OV7725_CONFIG_H

#include "mbed.h"
#include "camera_config.h"
#include "sccb.h"
#include "OV7725_regs.h"

/* OV7725 camera input config */
static const char OV7725_InitRegTable[][2] = {
    { OV7725_COM4, 0x41 }, /* COM4 PLL 4x, Full Window, default=0x41 */
    { OV7725_COM6, 0xC5 }, /* COM6 ??? */
#if 0 /* 30fps(24MHz) */
    {   0x11, 0x01}, /* CLKRC internal clock pre-scaler */
#else /* 60fps(48MHz) */
    { OV7725_CLKRC, 0x00 }, /* CLKRC  internal clock pre-scaler*/
#endif
    // COM7 0x12 - 0x80 GBR422, YUV
    { OV7725_COM9, 0x1F },      /* COM9 Drop VSYNC/HREF default=0x4a */
    { OV7725_COM10, 0x40 },     /* COM10 HSYNC default=0x00 */
    { OV7725_HSTART, 0x22 },    /* HSTART 0x23:VGA, 0x3F:QVGA, [1:0]->HREF[5:4] */
    { OV7725_HSIZE, 0xA4 },     /* HSIZE 0xA0:VGA, 0x60:QVGA, [1:0]->HREF[1:0] */
    { OV7725_VSTART, 0x07 },    /* VSTRT 0x07:VGA, 0x03:QVGA, [0]->HREF[6] */
    { OV7725_VSIZE, 0xF0 },     /* VSIZE 0xf0:VGA, 0x78:QVGA, [0]->HREF[2] */
    { OV7725_BDBASE, 0x99 },    /* BDBase */
    { OV7725_DBSTEP, 0x02 },    /* BDMStep */
    { OV7725_AEW, 0x60 },       /* AEW */
    { OV7725_AEB, 0x50 },       /* AEB */
    { OV7725_VPT, 0xA1 },       /* VPT */
    { OV7725_HOUTSIZE, 0xA0 },  /* HOutSize */
    { OV7725_EXHCH, 0x00 },     /* EXHCH EXHCH, default=0x00 */
    { OV7725_EXHCL, 0x00 },     /* EXHCL EXHCH, default=0x00 */
    { OV7725_VOUTSIZE, 0xF0 },  /* VOutSize */
    { OV7725_HREF, 0x00 },      /* HREF */
    { OV7725_DM_LNL, 0x01 },    /* DM_LNL */
    { OV7725_COM12, 0x03 },     /* COM12 */
    { OV7725_TGT_B, 0x7F },     /* TGT_B */
    { OV7725_FIXGAIN, 0x09 },   /* FixGain */
    { OV7725_AWB_CTRL0, 0xE0 }, /* AWB_Ctrl0 */
    { OV7725_DSP_CTRL1, 0xFF }, /* DSP_Ctrl1 */
    { OV7725_DSP_CTRL2, 0x20 }, /* DSP_Ctrl2 */
    { OV7725_DSP_CTRL3, 0x00 }, /* DSP_Ctrl3 */
    { OV7725_DSP_CTRL4, 0x48 }, /* DSP_Ctrl4 [1:0] 00: YUV or RGB */
    { OV7725_AWB_CTRL3, 0xAA }, /* AWBCtrl3 */
    { 0x7E, 0x04 }, /* GAM1 */
    { 0x7F, 0x0E }, /* GAM2 */
    { 0x80, 0x20 }, /* GAM3 */
    { 0x81, 0x43 }, /* GAM4 */
    { 0x82, 0x53 }, /* GAM5 */
    { 0x83, 0x61 }, /* GAM6 */
    { 0x84, 0x6D }, /* GAM7 */
    { 0x85, 0x76 }, /* GAM8 */
    { 0x86, 0x7E }, /* GAM9 */
    { 0x87, 0x86 }, /* GAM10 */
    { 0x88, 0x94 }, /* GAM11 */
    { 0x89, 0xA1 }, /* GAM12 */
    { 0x8A, 0xBA }, /* GAM13 */
    { 0x8B, 0xCF }, /* GAM14 */
    { 0x8C, 0xE3 }, /* GAM15 */
    { 0x8D, 0x26 }, /* SLOP */
    { 0x90, 0x05 }, /* EDGE1 */
    { 0x91, 0x01 }, /* DNSOff */
    { 0x92, 0x05 }, /* EDGE2 */
    { 0x93, 0x00 }, /* EDGE3 */
    { 0x94, 0x80 }, /* MTX1 */
    { 0x95, 0x7B }, /* MTX2 */
    { 0x96, 0x06 }, /* MTX3 */
    { 0x97, 0x1E }, /* MTX4 */
    { 0x98, 0x69 }, /* MTX5 */
    { 0x99, 0x86 }, /* MTX6 */
    { 0x9A, 0x1E }, /* MTX_Ctrl */
    { 0x9B, 0x00 }, /* BRIGHT */
    { 0x9C, 0x20 }, /* CNST */
    { 0x9E, 0x81 }, /* UVADJ0 */
    { 0xA6, 0x04 }, /* SDE */
};
#define SIZE_OV7725_InitRegTable    (sizeof(OV7725_InitRegTable)/sizeof(uint8_t))

static const char OV7725_sw_reset_cmd[2] = { 0x12, 0x80 };
#define SIZE_OV7725_sw_reset_cmd    (sizeof(OV7725_sw_reset_cmd)/sizeof(uint8_t))

static int OV7725_reg_read(uint8_t reg, uint8_t *v) {
    return sccb_reg_read(OV7725_ADDR, reg, v);
}

static int OV7725_reg_write(uint8_t reg, uint8_t v) {
    return sccb_reg_write(OV7725_ADDR, reg, v);
}

static int OV7725_reg_write_n(const uint8_t *tbl, size_t size) {
    return sccb_reg_write_n(OV7725_ADDR, tbl, size);
}

class OV7725_config : public camera_config {

public:

    /** Initialise
     *
     * @return true = success, false = failure
     */
    virtual bool Initialise() {
        int ret;

        ret = OV7725_reg_write_n((const uint8_t *)OV7725_sw_reset_cmd, SIZE_OV7725_sw_reset_cmd);
        if (ret != 0) {
            return false;
        }
        ThisThread::sleep_for(10ms);

        ret = OV7725_reg_write_n((const uint8_t *)OV7725_InitRegTable, SIZE_OV7725_InitRegTable);
        if (ret != 0) {
            return false;
        }
        return true;
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
        int ret;
        uint8_t v;

        /* COM8(AGC Enable/AEC Enable) */
        ret = OV7725_reg_read(0x13, &v);
        if (ret != 0) {
            return false;
        }
        if (bAuto) {
            v |= (uint8_t)0x05;
        } else {
            v &= (uint8_t)~0x05;
        }
        ret = OV7725_reg_write(0x13, v);
        if (ret != 0) {
            return false;
        }
        if (!bAuto) {
            /* AECH/AECL(exposure) */
            v = (uint8_t)((usManualExposure & 0xFF00) >> 8);
            ret = OV7725_reg_write(0x08, v);
            if (ret != 0) {
                return false;
            }
            v = (uint8_t)(usManualExposure & 0x00FF);
            ret = OV7725_reg_write(0x10, v);
            if (ret != 0) {
                return false;
            }
            /* GAIN */
            v = usManualGain;
            ret = OV7725_reg_write(0x00, v);
            if (ret != 0) {
                return false;
            }
        }
        return true;
    }
};

#endif

