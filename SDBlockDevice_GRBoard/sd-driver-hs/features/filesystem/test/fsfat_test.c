/* @file fsfat_test.c
 *
 * mbed Microcontroller Library
 * Copyright (c) 2006-2016 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * test support code implementation file.
 */

#include "fsfat_debug.h"
#include "fsfat_test.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>
#include <ctype.h>


#ifdef FSFAT_DEBUG
uint32_t fsfat_optDebug_g = 1;
uint32_t fsfat_optLogLevel_g = FSFAT_LOG_NONE; /*FSFAT_LOG_NONE|FSFAT_LOG_ERR|FSFAT_LOG_DEBUG|FSFAT_LOG_FENTRY; */
#endif

/* ruler for measuring text strings */
/*                                                                                                    1         1         1         1         1         1         1         1         1         1         2         2         2 */
/* 0        1         2         3         4         5         6         7         8         9         0         1         2         3         4         5         6         7         8         9         0         1         2 */
/* 1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890 */

const uint8_t fsfat_test_byte_data_table[FSFAT_TEST_BYTE_DATA_TABLE_SIZE] = {
    0x2d, 0xf3, 0x31, 0x4c, 0x11, 0x4f, 0xde, 0x0d, 0xbd, 0xbc, 0xa6, 0x78, 0x36, 0x5c, 0x1d, 0x28,
    0x5f, 0xa9, 0x10, 0x65, 0x54, 0x45, 0x21, 0x1a, 0x88, 0xfe, 0x76, 0x45, 0xb9, 0xac, 0x65, 0x9a,
    0x34, 0x9d, 0x73, 0x10, 0xb4, 0xa9, 0x2e, 0x90, 0x95, 0x68, 0xac, 0xfe, 0xc5, 0x2d, 0x15, 0x03,
    0x34, 0x70, 0xf1, 0x1d, 0x48, 0xa1, 0xa0, 0xed, 0x5c, 0x2f, 0xf5, 0x2b, 0xb9, 0x84, 0xbb, 0x45,
    0x32, 0xdd, 0xb1, 0x33, 0x95, 0x2a, 0xbc, 0x26, 0xf0, 0x89, 0xba, 0xf4, 0xbd, 0xf9, 0x5d, 0x2e,
    0x6e, 0x11, 0xc6, 0xa7, 0x78, 0xfc, 0xc9, 0x0e, 0x6b, 0x38, 0xba, 0x14, 0x1b, 0xab, 0x4c, 0x20,
    0x91, 0xe4, 0xb0, 0xf1, 0x2b, 0x14, 0x07, 0x6b, 0xb5, 0xcd, 0xe3, 0x49, 0x75, 0xac, 0xe8, 0x98,
    0xf1, 0x58, 0x8f, 0xd9, 0xc4, 0x8f, 0x00, 0x17, 0xb5, 0x06, 0x6a, 0x33, 0xbd, 0xa7, 0x40, 0x5a,
    0xbf, 0x49, 0xf7, 0x27, 0x1b, 0x4c, 0x3e, 0x6f, 0xe3, 0x08, 0x1f, 0xfd, 0xa6, 0xd4, 0xc7, 0x5f,
    0xa4, 0xa6, 0x82, 0xad, 0x19, 0xd5, 0x5c, 0xd8, 0x3a, 0x49, 0x85, 0xc9, 0x21, 0x83, 0xf6, 0xc6,
    0x84, 0xf9, 0x76, 0x89, 0xf3, 0x2d, 0x17, 0x50, 0x97, 0x38, 0x48, 0x9a, 0xe1, 0x82, 0xcd, 0xac,
    0xa8, 0x1d, 0xd7, 0x96, 0x5e, 0xb3, 0x08, 0xa8, 0x3a, 0xc7, 0x2b, 0x05, 0xaf, 0xdc, 0x16, 0xdf,
    0x48, 0x0f, 0x2a, 0x7e, 0x3a, 0x82, 0xd7, 0x80, 0xd6, 0x49, 0x27, 0x5d, 0xe3, 0x07, 0x62, 0xb3,
    0xc3, 0x6c, 0xba, 0xb2, 0xaa, 0x9f, 0xd9, 0x03, 0x0d, 0x27, 0xa8, 0xe0, 0xd6, 0xee, 0x79, 0x4b,
    0xd6, 0x97, 0x99, 0xb7, 0x11, 0xd6, 0x0d, 0x34, 0xae, 0x99, 0x4a, 0x93, 0x95, 0xd0, 0x5a, 0x34,
    0x19, 0xa2, 0x69, 0x57, 0xcf, 0x7c, 0x3d, 0x98, 0x88, 0x5d, 0x04, 0xf2, 0xd7, 0xac, 0xa5, 0x63
};


/* @brief  test utility function to delete the file identified by filename
 */
int32_t fsfat_test_delete(const char* filename)
{
    FSFAT_FENTRYLOG("%s:entered.\r\n", __func__);
    return remove(filename);
}


/* @brief   test utility function to create a file
 *
 * @param   filename    name of the file including path
 * @param   data        data to store in file
 * @param   len         number of bytes of data present in the data buffer.
 */
int32_t fsfat_test_create(const char* filename, const char* data, size_t len)
{
    int32_t ret = -1;
    FILE *fp = NULL;

    FSFAT_FENTRYLOG("%s:entered (filename=%s, len=%d).\n", __func__, filename, (int) len);
    fp = fopen(filename, "w+");
    if(fp == NULL){
        return ret;
    }
    ret = fwrite((const void*) data, len, 1, fp);
    if(ret < 0){
        fclose(fp);
        return ret;
    }
    fclose(fp);
    return ret;
}


/* @brief   support function for generating a kv_name
 * @param   name    buffer to hold kv name
 * @param   len     length of kv name to generate
 *
 */
int32_t fsfat_test_filename_gen(char* name, const size_t len)
{
    size_t i;
    uint32_t pos = 0;

    const char* buf = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!$-_@";
    const int buf_len = strlen(buf);
    FSFAT_FENTRYLOG("%s:entered\n", __func__);
    for(i = 0; i < len; i++)
    {
        pos = rand() % (buf_len);
        name[i] = buf[pos];
    }
    return 0;
}

