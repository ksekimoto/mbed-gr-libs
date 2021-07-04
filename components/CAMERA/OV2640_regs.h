/*
 * This file is part of the OpenMV project.
 * Copyright (c) 2013/2014 Ibrahim Abdelkader <i.abdalkader@gmail.com>
 * This work is licensed under the MIT license, see the file LICENSE for details.
 *
 * OV2640 register definitions.
 */

#ifndef __REG_REGS_H__
#define __REG_REGS_H__

/* DSP register bank FF=0x00*/

#define OV2640_QS                      0x44
#define OV2640_HSIZE                   0x51
#define OV2640_VSIZE                   0x52
#define OV2640_XOFFL                   0x53
#define OV2640_YOFFL                   0x54
#define OV2640_VHYX                    0x55
#define OV2640_DPRP                    0x56
#define OV2640_TEST                    0x57
#define OV2640_ZMOW                    0x5A
#define OV2640_ZMOH                    0x5B
#define OV2640_ZMHH                    0x5C
#define OV2640_BPADDR                  0x7C
#define OV2640_BPDATA                  0x7D
#define OV2640_SIZEL                   0x8C
#define OV2640_HSIZE8                  0xC0
#define OV2640_VSIZE8                  0xC1
#define OV2640_CTRL1                   0xC3
#define OV2640_MS_SP                   0xF0
#define OV2640_SS_ID                   0xF7
#define OV2640_SS_CTRL                 0xF7
#define OV2640_MC_AL                   0xFA
#define OV2640_MC_AH                   0xFB
#define OV2640_MC_D                    0xFC
#define OV2640_P_CMD                   0xFD
#define OV2640_P_STATUS                0xFE

#define OV2640_CTRLI                   0x50
#define OV2640_CTRLI_LP_DP             0x80
#define OV2640_CTRLI_ROUND             0x40

#define OV2640_CTRL0                   0xC2
#define OV2640_CTRL0_AEC_EN            0x80
#define OV2640_CTRL0_AEC_SEL           0x40
#define OV2640_CTRL0_STAT_SEL          0x20
#define OV2640_CTRL0_VFIRST            0x10
#define OV2640_CTRL0_YUV422            0x08
#define OV2640_CTRL0_YUV_EN            0x04
#define OV2640_CTRL0_RGB_EN            0x02
#define OV2640_CTRL0_RAW_EN            0x01

#define OV2640_CTRL2                   0x86
#define OV2640_CTRL2_DCW_EN            0x20
#define OV2640_CTRL2_SDE_EN            0x10
#define OV2640_CTRL2_UV_ADJ_EN         0x08
#define OV2640_CTRL2_UV_AVG_EN         0x04
#define OV2640_CTRL2_CMX_EN            0x01

#define OV2640_CTRL3                   0x87
#define OV2640_CTRL3_BPC_EN            0x80
#define OV2640_CTRL3_WPC_EN            0x40
#define OV2640_R_DVP_SP                0xD3
#define OV2640_R_DVP_SP_AUTO_MODE      0x80

#define OV2640_R_BYPASS                0x05
#define OV2640_R_BYPASS_DSP_EN         0x00
#define OV2640_R_BYPASS_DSP_BYPAS      0x01

#define OV2640_IMAGE_MODE              0xDA
#define OV2640_IMAGE_MODE_Y8_DVP_EN    0x40
#define OV2640_IMAGE_MODE_JPEG_EN      0x10
#define OV2640_IMAGE_MODE_YUV422       0x00
#define OV2640_IMAGE_MODE_RAW10        0x04
#define OV2640_IMAGE_MODE_RGB565       0x08
#define OV2640_IMAGE_MODE_HREF_VSYNC   0x02
#define OV2640_IMAGE_MODE_LBYTE_FIRST  0x01
#define OV2640_IMAGE_MODE_GET_FMT(x)   ((x)&0xC)

#define OV2640_RESET                   0xE0
#define OV2640_RESET_MICROC            0x40
#define OV2640_RESET_SCCB              0x20
#define OV2640_RESET_JPEG              0x10
#define OV2640_RESET_DVP               0x04
#define OV2640_RESET_IPU               0x02
#define OV2640_RESET_CIF               0x01

#define OV2640_MC_BIST                 0xF9
#define OV2640_MC_BIST_RESET           0x80
#define OV2640_MC_BIST_BOOT_ROM_SEL    0x40
#define OV2640_MC_BIST_12KB_SEL        0x20
#define OV2640_MC_BIST_12KB_MASK       0x30
#define OV2640_MC_BIST_512KB_SEL       0x08
#define OV2640_MC_BIST_512KB_MASK      0x0C
#define OV2640_MC_BIST_BUSY_BIT_R      0x02
#define OV2640_MC_BIST_MC_RES_ONE_SH_W 0x02
#define OV2640_MC_BIST_LAUNCH          0x01

#define OV2640_BANK_SEL                0xFF
#define OV2640_BANK_SEL_DSP            0x00
#define OV2640_BANK_SEL_SENSOR         0x01

/* Sensor register bank FF=0x01*/

#define OV2640_GAIN                0x00
#define OV2640_COM1                0x03
#define OV2640_REG_PID             0x0A
#define OV2640_REG_VER             0x0B
#define OV2640_COM4                0x0D
#define OV2640_AEC                 0x10

#define OV2640_CLKRC               0x11
#define OV2640_CLKRC_DOUBLE        0x80
#define OV2640_CLKRC_DIVIDER_MASK  0x3F

#define OV2640_COM10               0x15
#define OV2640_HSTART              0x17
#define OV2640_HSTOP               0x18
#define OV2640_VSTART              0x19
#define OV2640_VSTOP               0x1A
#define OV2640_MIDH                0x1C
#define OV2640_MIDL                0x1D
#define OV2640_AEW                 0x24
#define OV2640_AEB                 0x25
#define OV2640_REG2A               0x2A
#define OV2640_FRARL               0x2B
#define OV2640_ADDVSL              0x2D
#define OV2640_ADDVSH              0x2E
#define OV2640_YAVG                0x2F
#define OV2640_HSDY                0x30
#define OV2640_HEDY                0x31
#define OV2640_ARCOM2              0x34
#define OV2640_REG45               0x45
#define OV2640_FLL                 0x46
#define OV2640_FLH                 0x47
#define OV2640_COM19               0x48
#define OV2640_ZOOMS               0x49
#define OV2640_COM22               0x4B
#define OV2640_COM25               0x4E
#define OV2640_BD50                0x4F
#define OV2640_BD60                0x50
#define OV2640_REG5D               0x5D
#define OV2640_REG5E               0x5E
#define OV2640_REG5F               0x5F
#define OV2640_REG60               0x60
#define OV2640_HISTO_LOW           0x61
#define OV2640_HISTO_HIGH          0x62

#define OV2640_REG04               0x04
#define OV2640_REG04_DEFAULT       0x28
#define OV2640_REG04_HFLIP_IMG     0x80
#define OV2640_REG04_VFLIP_IMG     0x40
#define OV2640_REG04_VREF_EN       0x10
#define OV2640_REG04_HREF_EN       0x08
#define OV2640_REG04_SET(x)        (REG04_DEFAULT|x)

#define OV2640_REG08               0x08
#define OV2640_COM2                0x09
#define OV2640_COM2_STDBY          0x10
#define OV2640_COM2_OUT_DRIVE_1x   0x00
#define OV2640_COM2_OUT_DRIVE_2x   0x01
#define OV2640_COM2_OUT_DRIVE_3x   0x02
#define OV2640_COM2_OUT_DRIVE_4x   0x03

#define OV2640_COM3                0x0C
#define OV2640_COM3_DEFAULT        0x38
#define OV2640_COM3_BAND_50Hz      0x04
#define OV2640_COM3_BAND_60Hz      0x00
#define OV2640_COM3_BAND_AUTO      0x02
#define OV2640_COM3_BAND_SET(x)    (COM3_DEFAULT|x)

#define OV2640_COM7                0x12
#define OV2640_COM7_SRST           0x80
#define OV2640_COM7_RES_UXGA       0x00 /* UXGA */
#define OV2640_COM7_RES_SVGA       0x40 /* SVGA */
#define OV2640_COM7_RES_CIF        0x20 /* CIF  */
#define OV2640_COM7_ZOOM_EN        0x04 /* Enable Zoom */
#define OV2640_COM7_COLOR_BAR      0x02 /* Enable Color Bar Test */
#define OV2640_COM7_GET_RES(x)     ((x)&0x70)

#define OV2640_COM8                0x13
#define OV2640_COM8_DEFAULT        0xC0
#define OV2640_COM8_BNDF_EN        0x20 /* Enable Banding filter */
#define OV2640_COM8_AGC_EN         0x04 /* AGC Auto/Manual control selection */
#define OV2640_COM8_AEC_EN         0x01 /* Auto/Manual Exposure control */
#define OV2640_COM8_SET(x)         (COM8_DEFAULT|x)
#define OV2640_COM8_SET_AEC(r,x)   (((r)&0xFE)|((x)&1))

#define OV2640_COM9                0x14 /* AGC gain ceiling */
#define OV2640_COM9_DEFAULT        0x08
#define OV2640_COM9_AGC_GAIN_2x    0x00 /* AGC:    2x */
#define OV2640_COM9_AGC_GAIN_4x    0x01 /* AGC:    4x */
#define OV2640_COM9_AGC_GAIN_8x    0x02 /* AGC:    8x */
#define OV2640_COM9_AGC_GAIN_16x   0x03 /* AGC:   16x */
#define OV2640_COM9_AGC_GAIN_32x   0x04 /* AGC:   32x */
#define OV2640_COM9_AGC_GAIN_64x   0x05 /* AGC:   64x */
#define OV2640_COM9_AGC_GAIN_128x  0x06 /* AGC:  128x */
#define OV2640_COM9_AGC_SET(x)     (COM9_DEFAULT|(x<<5))

#define OV2640_CTRL1_AWB           0x08 /* Enable AWB */

#define OV2640_VV                  0x26
#define OV2640_VV_AGC_TH_SET(h,l)  ((h<<4)|(l&0x0F))

#define OV2640_REG32               0x32
#define OV2640_REG32_UXGA          0x36
#define OV2640_REG32_SVGA          0x09
#define OV2640_REG32_CIF           0x00

#define OV2640_BANK_SEL                0xFF
#define OV2640_BANK_SEL_DSP            0x00
#define OV2640_BANK_SEL_SENSOR         0x01

#define OV2640_RESET                   0xE0
#define OV2640_RESET_MICROC            0x40
#define OV2640_RESET_SCCB              0x20
#define OV2640_RESET_JPEG              0x10
#define OV2640_RESET_DVP               0x04
#define OV2640_RESET_IPU               0x02
#define OV2640_RESET_CIF               0x01

#endif //__REG_REGS_H__
