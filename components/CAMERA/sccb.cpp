/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2021 Kentaro Sekimoto
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "mbed.h"
#include "camera_config.h"
#include "sccb.h"

#if defined(TARGET_RZ_A2M_EVB) || defined(TARGET_RZ_A2M_EVB_HF) || defined(TARGET_RZ_A2M_SBEV) || defined(TARGET_SEMB1402)
static I2C i2c_dv(PD_5, PD_4);
#else
static I2C i2c_dv(I2C_SDA, I2C_SCL);
#endif

int sccb_reg_read(uint8_t addr, uint8_t reg, uint8_t *v) {
    int ret = 0;
    ret = i2c_dv.write((int)addr, (const char *)&reg, 1);
    if (ret != 0) {
        return ret;
    }
    ret = i2c_dv.read((int)addr, (char *)v, 1);
    return ret;
}

int sccb_reg_write(uint8_t addr, uint8_t reg, uint8_t v) {
    int ret = 0;
    ret = i2c_dv.write((int)addr, (const char *)&reg, 1);
    if (ret != 0) {
        return ret;
    }
    ret = i2c_dv.write((int)addr, (const char *)&v, 1);
    return ret;
}

int sccb_reg_write_n(uint8_t addr, const uint8_t *tbl, size_t size) {
    int ret = 0;
    for (int i; i < (int)size; i += 2) {
        ret = i2c_dv.write((int)addr, (const char *)&tbl[i + 0], 1);
        if (ret != 0) {
            return ret;
        }
        ret = i2c_dv.write((int)addr, (const char *)&tbl[i + 1], 1);
        if (ret != 0) {
            return ret;
        }
    }
    return ret;
}

int sccb2_reg_read(uint8_t addr, uint8_t reg1, uint8_t reg2, uint8_t *v) {
    int ret = 0;
    ret = i2c_dv.write((int)addr, (const char *)&reg1, 1);
    if (ret != 0) {
        return ret;
    }
    ret = i2c_dv.write((int)addr, (const char *)&reg2, 1);
    if (ret != 0) {
        return ret;
    }
    ret = i2c_dv.read((int)addr, (char *)v, 1);
    return ret;
}

int sccb2_reg_write(uint8_t addr, uint8_t reg1, uint8_t reg2, uint8_t v) {
    int ret = 0;
    ret = i2c_dv.write((int)addr, (const char *)&reg1, 1);
    if (ret != 0) {
        return ret;
    }
    ret = i2c_dv.write((int)addr, (const char *)&reg2, 1);
    if (ret != 0) {
        return ret;
    }
    ret = i2c_dv.write((int)addr, (const char *)&v, 1);
    return ret;
}

int sccb2_reg_write_n(uint8_t addr, const uint8_t *tbl, size_t size) {
    int ret = 0;
    for (int i; i < (int)size; i += 3) {
        ret = i2c_dv.write((int)addr, (const char *)&tbl[i + 0], 1);
        if (ret != 0) {
            return ret;
        }
        ret = i2c_dv.write((int)addr, (const char *)&tbl[i + 1], 1);
        if (ret != 0) {
            return ret;
        }
        ret = i2c_dv.write((int)addr, (const char *)&tbl[i + 2], 1);
        if (ret != 0) {
            return ret;
        }
    }
    return ret;
}

int RASPI_reg_write_n(const uint8_t *tbl, size_t size) {
    return sccb2_reg_write_n((int)RASPI_ADDR, tbl, size);
}

#if 0
#define MHZ_COUNT       100
#define SCCB_CLK_WAIT   100
#define SCCB_CLK_1000   1000

static void sccb_wait(int us) {
    while (us-- > 0) {
        for (int i = 0; i < MHZ_COUNT; i++) {
            __asm__ __volatile__ ("nop");
        }
    }
}

static void sccb_start(void) {
    DigitalOut pinSCL(I2C_SCL);
    DigitalInOut pinSDA(I2C_SDA);
    pinSDA.output();

    // sda: ->high
    pinSDA = 1;
    sccb_wait(SCCB_CLK_WAIT);
    // scl: ->high, sda: high->low
    pinSCL = 1;
    sccb_wait(SCCB_CLK_WAIT);
    pinSDA = 0;
    sccb_wait(SCCB_CLK_WAIT);
    // scl: low
    pinSCL = 0;
    sccb_wait(SCCB_CLK_WAIT);
}

static void sccb_stop(void) {
    DigitalOut pinSCL(I2C_SCL);
    DigitalInOut pinSDA(I2C_SDA);
    pinSDA.output();

    pinSDA = 0;
    sccb_wait(SCCB_CLK_WAIT);
    pinSCL = 1;
    sccb_wait(SCCB_CLK_WAIT);
    pinSDA = 1;
    sccb_wait(SCCB_CLK_WAIT);
}

static void sccb_noack(void) {
    DigitalOut pinSCL(I2C_SCL);
    DigitalInOut pinSDA(I2C_SDA);
    pinSDA.output();

    pinSDA = 1;
    sccb_wait(SCCB_CLK_WAIT);

    pinSCL = 1;
    sccb_wait(SCCB_CLK_WAIT);

    pinSCL = 0;
    sccb_wait(SCCB_CLK_WAIT);

    pinSDA = 0;
    sccb_wait(SCCB_CLK_WAIT);
}

static int sccb_write_byte(unsigned char m_data) {
    DigitalOut pinSCL(I2C_SCL);
#if defined(USE_PULLUP)
    DigitalInOut pinSDA(I2C_SDA, PIN_INPUT, PullUp, 0);
#else
    // DigitalInOut pinSDA(I2C_SDA, PIN_INPUT, OpenDrain, 0);
    DigitalInOut pinSDA(I2C_SDA, PIN_INPUT, PullNone, 0);
#endif
    pinSDA.output();

    unsigned char j;
    int sccb_state = 0;

    for (j = 0; j < 8; j++) {
        if ((m_data << j) & 0x80) {
            pinSDA = 1;
        } else {
            pinSDA = 0;
        }
        sccb_wait(SCCB_CLK_WAIT);
        pinSCL = 1;
        sccb_wait(SCCB_CLK_WAIT);
        pinSCL = 0;
        sccb_wait(SCCB_CLK_WAIT);

    }
    sccb_wait(SCCB_CLK_WAIT);
    pinSDA.input();
    sccb_wait(SCCB_CLK_WAIT);
    pinSCL = 1;
    sccb_wait(SCCB_CLK_1000);
    if (pinSDA != 0) {
#if defined(USE_NO_ERROR)
        sccb_state =  0;
#else
        sccb_state = -1; // NG
#endif
    } else {
        sccb_state = 0;  // OK
    }
    pinSCL = 0;
    sccb_wait(SCCB_CLK_WAIT);
    pinSDA.output();
    return sccb_state;
}

static unsigned char sccb_read_byte(void) {
    DigitalOut pinSCL(I2C_SCL);
#if defined(USE_PULLUP)
    DigitalInOut pinSDA(I2C_SDA, PIN_INPUT, PullUp, 0);
#else
    // DigitalInOut pinSDA(I2C_SDA, PIN_INPUT, OpenDrain, 0);
    DigitalInOut pinSDA(I2C_SDA, PIN_INPUT, PullNone, 0);
#endif

    unsigned char data, j;
    data = 0x00;

    pinSDA.input();
    sccb_wait(SCCB_CLK_WAIT);
    for (j = 8; j > 0; j--) {
        sccb_wait(SCCB_CLK_WAIT);
        pinSCL = 1;
        sccb_wait(SCCB_CLK_WAIT);
        data <<= 1;
        if (pinSDA != 0) {
            data += 1;
        }
        pinSCL = 0;
        sccb_wait(SCCB_CLK_WAIT);
    }
    pinSDA.output();
    return(data);
}

// OK: 0
// NG: -1
int sccb_write(int address, const char *data, int length) {
    int ret = 0;
    sccb_start();
    ret = sccb_write_byte((unsigned char) address);
    if (ret != 0) {
        sccb_stop();
#if defined(USE_NO_ERROR)
        return 0;
#else
        return -1;
#endif
    }
    sccb_wait(SCCB_CLK_WAIT);
    int i;
    for (i = 0; i < length; i++) {
        ret = sccb_write_byte((unsigned char) *data++);
        if (ret != 0) {
            sccb_stop();
#if defined(USE_NO_ERROR)
            return 0;
#else
            return -1;
#endif
        }
        sccb_wait(SCCB_CLK_WAIT);
    }
    sccb_stop();
    return 0;
}

// OK: 0
// NG: -1
int sccb_read(int address, char *data, int length) {
    int ret = 0;
    address += 1;
    sccb_start();
    ret = sccb_write_byte((unsigned char) address);
    if (ret != 0) {
        sccb_stop();
#if defined(USE_NO_ERROR)
        return 0;
#else
        return -1;
#endif
    }
    sccb_wait(SCCB_CLK_WAIT);
    int i;
    for (i = 0; i < length; i++) {
        *data++ = (char)sccb_read_byte();
        sccb_wait(SCCB_CLK_WAIT);
    }
    sccb_noack();
    sccb_stop();
    return 0;
}

#endif
