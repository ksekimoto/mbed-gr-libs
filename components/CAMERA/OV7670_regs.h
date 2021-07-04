/*
 * https://os.mbed.com/users/diasea/notebook/ov7670_FIFO_AL422B/
 */

#ifndef LIB_MBED_GR_LIBS_COMPONENTS_CAMERA_OV7670_REGS_H_
#define LIB_MBED_GR_LIBS_COMPONENTS_CAMERA_OV7670_REGS_H_

// size register
#define OV7670_REG_COM7                    0x12    /* Control 7 */
#define OV7670_REG_HSTART                  0x17    /* Horiz start high bits */
#define OV7670_REG_HSTOP                   0x18    /* Horiz stop high bits */
#define OV7670_REG_HREF                    0x32    /* HREF pieces */
#define OV7670_REG_VSTART                  0x19    /* Vert start high bits */
#define OV7670_REG_VSTOP                   0x1a    /* Vert stop high bits */
#define OV7670_REG_VREF                    0x03    /* Pieces of GAIN, VSTART, VSTOP */
#define OV7670_REG_COM3                    0x0c    /* Control 3 */
#define OV7670_REG_COM14                   0x3e    /* Control 14 */
#define OV7670_REG_SCALING_XSC             0x70
#define OV7670_REG_SCALING_YSC             0x71
#define OV7670_REG_SCALING_DCWCTR          0x72
#define OV7670_REG_SCALING_PCLK_DIV        0x73
#define OV7670_REG_SCALING_PCLK_DELAY      0xa2

// VGA setting
#define OV7670_COM7_VGA                    0x00
#define OV7670_HSTART_VGA                  0x13
#define OV7670_HSTOP_VGA                   0x01
#define OV7670_HREF_VGA                    0x36 //0xb6 0x36
#define OV7670_VSTART_VGA                  0x02
#define OV7670_VSTOP_VGA                   0x7a
#define OV7670_VREF_VGA                    0x0a
#define OV7670_COM3_VGA                    0x00
#define OV7670_COM14_VGA                   0x00
#define OV7670_SCALING_XSC_VGA             0x3a
#define OV7670_SCALING_YSC_VGA             0x35
#define OV7670_SCALING_DCWCTR_VGA          0x11
#define OV7670_SCALING_PCLK_DIV_VGA        0xf0
#define OV7670_SCALING_PCLK_DELAY_VGA      0x02

// QVGA setting
#define OV7670_COM7_QVGA                   0x00
#define OV7670_HSTART_QVGA                 0x16
#define OV7670_HSTOP_QVGA                  0x04
#define OV7670_HREF_QVGA                   0x00
#define OV7670_VSTART_QVGA                 0x02
#define OV7670_VSTOP_QVGA                  0x7a
#define OV7670_VREF_QVGA                   0x0a
#define OV7670_COM3_QVGA                   0x04
#define OV7670_COM14_QVGA                  0x19
#define OV7670_SCALING_XSC_QVGA            0x3a
#define OV7670_SCALING_YSC_QVGA            0x35
#define OV7670_SCALING_DCWCTR_QVGA         0x11
#define OV7670_SCALING_PCLK_DIV_QVGA       0xf1
#define OV7670_SCALING_PCLK_DELAY_QVGA     0x02

// QQVGA setting
#define OV7670_COM7_QQVGA                  0x00
#define OV7670_HSTART_QQVGA                0x16
#define OV7670_HSTOP_QQVGA                 0x04
#define OV7670_HREF_QQVGA                  0xa4  //0x24? 0xa4?
#define OV7670_VSTART_QQVGA                0x02
#define OV7670_VSTOP_QQVGA                 0x7a
#define OV7670_VREF_QQVGA                  0x0a
#define OV7670_COM3_QQVGA                  0x04
#define OV7670_COM14_QQVGA                 0x1a
#define OV7670_SCALING_XSC_QQVGA           0x3a
#define OV7670_SCALING_YSC_QQVGA           0x35
#define OV7670_SCALING_DCWCTR_QQVGA        0x22
#define OV7670_SCALING_PCLK_DIV_QQVGA      0xf2
#define OV7670_SCALING_PCLK_DELAY_QQVGA    0x02

// CIF setting no tested linux src 2.6.29-rc5 ov7670_soc.c
#define OV7670_COM7_CIF                    0x00
#define OV7670_HSTART_CIF                  0x15
#define OV7670_HSTOP_CIF                   0x0b
#define OV7670_HREF_CIF                    0xb6
#define OV7670_VSTART_CIF                  0x03
#define OV7670_VSTOP_CIF                   0x7b
#define OV7670_VREF_CIF                    0x02
#define OV7670_COM3_CIF                    0x08
#define OV7670_COM14_CIF                   0x11
#define OV7670_SCALING_XSC_CIF             0x3a
#define OV7670_SCALING_YSC_CIF             0x35
#define OV7670_SCALING_DCWCTR_CIF          0x11
#define OV7670_SCALING_PCLK_DIV_CIF        0xf1
#define OV7670_SCALING_PCLK_DELAY_CIF      0x02

// QCIF setting no tested no tested linux src 2.6.29-rc5 ov7670_soc.c
#define OV7670_COM7_QCIF                   0x00
#define OV7670_HSTART_QCIF                 0x39
#define OV7670_HSTOP_QCIF                  0x03
#define OV7670_HREF_QCIF                   0x80
#define OV7670_VSTART_QCIF                 0x03
#define OV7670_VSTOP_QCIF                  0x7b
#define OV7670_VREF_QCIF                   0x02
#define OV7670_COM3_QCIF                   0x0c
#define OV7670_COM14_QCIF                  0x11
#define OV7670_SCALING_XSC_QCIF            0x3a
#define OV7670_SCALING_YSC_QCIF            0x35
#define OV7670_SCALING_DCWCTR_QCIF         0x11
#define OV7670_SCALING_PCLK_DIV_QCIF       0xf1
#define OV7670_SCALING_PCLK_DELAY_QCIF     0x52

// YUV
#define OV7670_REG_COM13                   0x3d    /* Control 13 */
#define OV7670_REG_TSLB                    0x3a    /* lots of stuff */

#define OV7670_COM7_YUV                    0x00    /* YUV */
#define OV7670_COM13_UV                    0x00    /* U before V - w/TSLB */
#define OV7670_COM13_UVSWAP                0x01    /* V before U - w/TSLB */
#define OV7670_TSLB_VLAST                  0x00    /* YUYV  - see com13 */
#define OV7670_TSLB_ULAST                  0x00    /* YVYU  - see com13 */
#define OV7670_TSLB_YLAST                  0x08    /* UYVY or VYUY - see com13 */

// RGB
#define OV7670_COM7_RGB                    0x04    /* bits 0 and 2 - RGB format */

// RGB444
#define OV7670_REG_RGB444                  0x8c    /* RGB 444 control */
#define OV7670_REG_COM15                   0x40    /* Control 15 */

#define OV7670_RGB444_ENABLE               0x02    /* Turn on RGB444, overrides 5x5 */
#define OV7670_RGB444_XBGR                 0x00
#define OV7670_RGB444_BGRX                 0x01    /* Empty nibble at end */
#define OV7670_COM15_RGB444                0x10    /* RGB444 output */

// RGB555
#define OV7670_RGB444_DISABLE              0x00    /* Turn off RGB444, overrides 5x5 */
#define OV7670_COM15_RGB555                0x30    /* RGB555 output */

// RGB565
#define OV7670_COM15_RGB565                0x10    /* RGB565 output */

// Bayer RGB
#define OV7670_COM7_BAYER                  0x01    /* Bayer format */
#define OV7670_COM7_PBAYER                 0x05    /* "Processed bayer" */


// data format
#define OV7670_COM15_R10F0                 0x00    /* Data range 10 to F0 */
#define OV7670_COM15_R01FE                 0x80    /*            01 to FE */
#define OV7670_COM15_R00FF                 0xc0    /*            00 to FF */

// Night mode, flicker, banding /
#define OV7670_REG_COM11                   0x3b    /* Control 11 */
#define OV7670_COM11_NIGHT                 0x80    /* NIght mode enable */
#define OV7670_COM11_NIGHT_MIN_RATE_1_1    0x00    /* Normal mode same */
#define OV7670_COM11_NIGHT_MIN_RATE_1_2    0x20    /* Normal mode 1/2 */
#define OV7670_COM11_NIGHT_MIN_RATE_1_4    0x40    /* Normal mode 1/4 */
#define OV7670_COM11_NIGHT_MIN_RATE_1_8    0x60    /* Normal mode 1/5 */
#define OV7670_COM11_HZAUTO_ON             0x10    /* Auto detect 50/60 Hz on */
#define OV7670_COM11_HZAUTO_OFF            0x00    /* Auto detect 50/60 Hz off */
#define OV7670_COM11_60HZ                  0x00    /* Manual 60Hz select */
#define OV7670_COM11_50HZ                  0x08    /* Manual 50Hz select */
#define OV7670_COM11_EXP                   0x02

#define OV7670_REG_MTX1                    0x4f
#define OV7670_REG_MTX2                    0x50
#define OV7670_REG_MTX3                    0x51
#define OV7670_REG_MTX4                    0x52
#define OV7670_REG_MTX5                    0x53
#define OV7670_REG_MTX6                    0x54
#define OV7670_REG_BRIGHT                  0x55    /* Brightness */
#define OV7670_REG_CONTRAS                 0x56    /* Contrast control */
#define OV7670_REG_CONTRAS_CENTER          0x57
#define OV7670_REG_MTXS                    0x58
#define OV7670_REG_MANU                    0x67
#define OV7670_REG_MANV                    0x68
#define OV7670_REG_GFIX                    0x69    /* Fix gain control */
#define OV7670_REG_GGAIN                   0x6a
#define OV7670_REG_DBLV                    0x6b

#define OV7670_REG_COM9        0x14        // Control 9  - gain ceiling
#define OV7670_COM9_AGC_2X     0x00
#define OV7670_COM9_AGC_4X     0x10
#define OV7670_COM9_AGC_8X     0x20
#define OV7670_COM9_AGC_16X    0x30
#define OV7670_COM9_AGC_32X    0x40
#define OV7670_COM9_AGC_64X    0x50
#define OV7670_COM9_AGC_128X   0x60
#define OV7670_COM9_AGC_MASK   0x70
#define OV7670_COM9_FREEZE     0x01
#define OV7670_COM13_GAMMA     0x80    /* Gamma enable */
#define OV7670_COM13_UVSAT     0x40    /* UV saturation auto adjustment */
#define OV7670_REG_GAIN        0x00    /* Gain lower 8 bits (rest in vref) */
#define OV7670_REG_BLUE        0x01    /* blue gain */
#define OV7670_REG_RED         0x02    /* red gain */
#define OV7670_REG_COM1        0x04    /* Control 1 */
#define OV7670_COM1_CCIR656    0x40    /* CCIR656 enable */
#define OV7670_REG_BAVE        0x05    /* U/B Average level */
#define OV7670_REG_GbAVE       0x06    /* Y/Gb Average level */
#define OV7670_REG_AECHH       0x07    /* AEC MS 5 bits */
#define OV7670_REG_RAVE        0x08    /* V/R Average level */
#define OV7670_REG_COM2        0x09    /* Control 2 */
#define OV7670_COM2_SSLEEP     0x10    /* Soft sleep mode */
#define OV7670_REG_PID         0x0a    /* Product ID MSB */
#define OV7670_REG_VER         0x0b    /* Product ID LSB */
#define OV7670_COM3_SWAP       0x40    /* Byte swap */
#define OV7670_COM3_SCALEEN    0x08    /* Enable scaling */
#define OV7670_COM3_DCWEN      0x04    /* Enable downsamp/crop/window */
#define OV7670_REG_COM4        0x0d    /* Control 4 */
#define OV7670_REG_COM5        0x0e    /* All "reserved" */
#define OV7670_REG_COM6        0x0f    /* Control 6 */
#define OV7670_REG_AECH        0x10    /* More bits of AEC value */
#define OV7670_REG_CLKRC       0x11    /* Clocl control */
#define OV7670_CLK_EXT         0x40    /* Use external clock directly */
#define OV7670_CLK_SCALE       0x3f    /* Mask for internal clock scale */
#define OV7670_COM7_RESET      0x80    /* Register reset */
#define OV7670_COM7_FMT_MASK   0x38
#define OV7670_COM7_FMT_VGA    0x00
#define OV7670_COM7_FMT_CIF    0x20    /* CIF format */
#define OV7670_COM7_FMT_QVGA   0x10    /* QVGA format */
#define OV7670_COM7_FMT_QCIF   0x08    /* QCIF format */
#define OV7670_REG_COM8        0x13    /* Control 8 */
#define OV7670_COM8_FASTAEC    0x80    /* Enable fast AGC/AEC */
#define OV7670_COM8_AECSTEP    0x40    /* Unlimited AEC step size */
#define OV7670_COM8_BFILT      0x20    /* Band filter enable */
#define OV7670_COM8_AGC        0x04    /* Auto gain enable */
#define OV7670_COM8_AWB        0x02    /* White balance enable */
#define OV7670_COM8_AEC        0x01    /* Auto exposure enable */
#define OV7670_REG_COM9        0x14    /* Control 9  - gain ceiling */
#define OV7670_REG_COM10       0x15    /* Control 10 */
#define OV7670_COM10_HSYNC     0x40    /* HSYNC instead of HREF */
#define OV7670_COM10_PCLK_HB   0x20    /* Suppress PCLK on horiz blank */
#define OV7670_COM10_HREF_REV  0x08    /* Reverse HREF */
#define OV7670_COM10_VS_LEAD   0x04    /* VSYNC on clock leading edge */
#define OV7670_COM10_VS_NEG    0x02    /* VSYNC negative */
#define OV7670_COM10_HS_NEG    0x01    /* HSYNC negative */
#define OV7670_REG_PSHFT       0x1b    /* Pixel delay after HREF */
#define OV7670_REG_MIDH        0x1c    /* Manuf. ID high */
#define OV7670_REG_MIDL        0x1d    /* Manuf. ID low */
#define OV7670_REG_MVFP        0x1e    /* Mirror / vflip */
#define OV7670_MVFP_MIRROR     0x20    /* Mirror image */
#define OV7670_MVFP_FLIP       0x10    /* Vertical flip */
#define OV7670_REG_AEW         0x24    /* AGC upper limit */
#define OV7670_REG_AEB         0x25    /* AGC lower limit */
#define OV7670_REG_VPT         0x26    /* AGC/AEC fast mode op region */
#define OV7670_REG_HSYST       0x30    /* HSYNC rising edge delay */
#define OV7670_REG_HSYEN       0x31    /* HSYNC falling edge delay */
#define OV7670_REG_COM12       0x3c    /* Control 12 */
#define OV7670_COM12_HREF      0x80    /* HREF always */
#define OV7670_COM14_DCWEN     0x10    /* DCW/PCLK-scale enable */
#define OV7670_REG_EDGE        0x3f    /* Edge enhancement factor */
#define OV7670_REG_COM16       0x41    /* Control 16 */
#define OV7670_COM16_AWBGAIN   0x08    /* AWB gain enable */
#define OV7670_REG_COM17       0x42    /* Control 17 */
#define OV7670_COM17_AECWIN    0xc0    /* AEC window - must match COM4 */
#define OV7670_COM17_CBAR      0x08    /* DSP Color bar */
#define OV7670_REG_CMATRIX_BASE 0x4f
#define OV7670_CMATRIX_LEN         6
#define OV7670_REG_REG76       0x76    /* OV's name */
#define OV7670_R76_BLKPCOR     0x80    /* Black pixel correction enable */
#define OV7670_R76_WHTPCOR     0x40    /* White pixel correction enable */
#define OV7670_REG_HAECC1      0x9f    /* Hist AEC/AGC control 1 */
#define OV7670_REG_HAECC2      0xa0    /* Hist AEC/AGC control 2 */
#define OV7670_REG_BD50MAX     0xa5    /* 50hz banding step limit */
#define OV7670_REG_HAECC3      0xa6    /* Hist AEC/AGC control 3 */
#define OV7670_REG_HAECC4      0xa7    /* Hist AEC/AGC control 4 */
#define OV7670_REG_HAECC5      0xa8    /* Hist AEC/AGC control 5 */
#define OV7670_REG_HAECC6      0xa9    /* Hist AEC/AGC control 6 */
#define OV7670_REG_HAECC7      0xaa    /* Hist AEC/AGC control 7 */
#define OV7670_REG_BD60MAX     0xab    /* 60hz banding step limit */

#endif /* LIB_MBED_GR_LIBS_COMPONENTS_CAMERA_OV7670_REGS_H_ */
