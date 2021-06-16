/*
 * sccb.c
 *
 */

#include "mbed.h"
#include "sccb.h"

#define SCCB_CLK_WAIT   50
#define SCCB_WAIT_1     2
#define SCCB_WAIT_2     10
#define SCCB_WAIT_3     80

void sccb_wait(int us) {
    wait_us(us);
}

void sccb_start(void) {
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
    // sda: low
    pinSCL = 0;
    sccb_wait(SCCB_CLK_WAIT);
}

void sccb_stop(void) {
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

void sccb_noack(void) {
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

int sccb_write_byte(unsigned char m_data) {
    DigitalOut pinSCL(I2C_SCL);
    DigitalInOut pinSDA(I2C_SDA, PIN_INPUT, OpenDrain, 0);
    pinSDA.output();

    unsigned char j;
    int sccb_state = 1;

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
        sccb_wait(SCCB_WAIT_1);

    }
    //sccb_wait(SCCB_CLK_WAIT);
    pinSDA.input();
    sccb_wait(SCCB_WAIT_1);
    pinSCL = 1;
    sccb_wait(SCCB_WAIT_3);
    if (pinSDA != 0) {
        sccb_state = 0; // NG
    } else {
        sccb_state = 1; // OK
    }
    pinSCL = 0;
    sccb_wait(SCCB_CLK_WAIT);
    pinSDA.output();
    return sccb_state;
}

unsigned char sccb_read_byte(void) {
    DigitalOut pinSCL(I2C_SCL);
    DigitalInOut pinSDA(I2C_SDA, PIN_INPUT, OpenDrain, 0);

    unsigned char data, j;
    data = 0x00;

    pinSDA.input();
    sccb_wait(SCCB_CLK_WAIT);
    for (j = 8; j > 0; j--) {
        //sccb_wait(100);
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
// NG: 1
int sccb_write(int address, const char *data, int length) {
    int ret = 1;
    sccb_start();
    ret = sccb_write_byte((unsigned char) address);
    if (ret == 0) {
        sccb_stop();
        return 1;
    }
    sccb_wait(SCCB_WAIT_2);
    int i;
    for (i = 0; i < length; i++) {
        ret = sccb_write_byte((unsigned char) *data++);
        if (ret == 0) {
            sccb_stop();
            return 1;
        }
    }
    sccb_stop();
    return 0;
}

// OK: 0
// NG: 1
int sccb_read(int address, char *data, int length) {
    int ret = 0;
    address += 1;
    sccb_start();
    ret = sccb_write_byte((unsigned char) address);
    if (ret == 0) {
        sccb_stop();
        return 1;
    }
    sccb_wait(SCCB_WAIT_2);
    int i;
    for (i = 0; i < length; i++) {
        *data++ = (char)sccb_read_byte();
    }
    sccb_noack();
    sccb_stop();
    return 0;
}
