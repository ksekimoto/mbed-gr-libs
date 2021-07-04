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

#ifndef LIB_MBED_GR_LIBS_COMPONENTS_CAMERA_CAMERA_UTILS_H_
#define LIB_MBED_GR_LIBS_COMPONENTS_CAMERA_CAMERA_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

#define OV2640_ADDR 0x60
#define OV5640_ADDR 0x78
#define OV5642_ADDR 0x78
#define OV7670_ADDR 0x42
#define OV7725_ADDR 0x42
#define RASPI_ADDR  0x20

int sccb_write(int address, const char *data, int length) ;
int sccb_read(int address, char *data, int length) ;

int sccb_reg_read(uint8_t addr, uint8_t reg, uint8_t *v);
int sccb_reg_write(uint8_t addr, uint8_t reg, uint8_t v);
int sccb_reg_write_n(uint8_t addr, const uint8_t *tbl, size_t size);

int sccb2_reg_read(uint8_t addr, uint8_t reg1, uint8_t reg2, uint8_t *v);
int sccb2_reg_write(uint8_t addr, uint8_t reg1, uint8_t reg2, uint8_t v);
int sccb2_reg_write_n(uint8_t addr, const uint8_t *tbl, size_t size);

int RASPI_reg_write_n(const uint8_t *tbl, size_t size);

#ifdef __cplusplus
};
#endif

#endif /* LIB_MBED_GR_LIBS_COMPONENTS_CAMERA_CAMERA_UTILS_H_ */
