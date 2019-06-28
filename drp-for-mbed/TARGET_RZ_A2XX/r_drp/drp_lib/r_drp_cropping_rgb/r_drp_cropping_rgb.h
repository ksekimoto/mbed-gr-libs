/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
* Copyright (C) 2018 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/

/*******************************************************************************
* File Name    : r_drp_cropping_rgb.h
* Description  : This source code is the header file of
*              : r_drp_cropping_rgb.c
******************************************************************************/
#ifndef R_DRP_CROPPING_RGB
#define R_DRP_CROPPING_RGB

/*******************************************************************************
Global Typedef definitions
*******************************************************************************/
#ifdef BDL
typedef unsigned long long uint64_t;
typedef unsigned long uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef signed long long int64_t;
typedef signed long int32_t;
typedef signed short int16_t;
typedef signed char int8_t;
#else /* BDL */
#include <stdint.h>
#endif /* BDL */

/* Structure of interface parameters between CPU and DRP library. */
typedef struct
{
    uint32_t src;         /* Address of input image */
    uint32_t dst;         /* Address of output image */
    uint16_t src_width;   /* The horizontal size (pixels) of image */
    uint16_t src_height;  /* The vertical size (pixels) of image */
    uint16_t offset_x;    /* Offset of X-coordinate */
    uint16_t offset_y;    /* Offset of Y-coordinate */
    uint16_t dst_width;   /* The horizontal size (pixels) of output */
    uint16_t dst_height;  /* The vertical size (pixels) of output */
} r_drp_cropping_rgb_t;

/*******************************************************************************
Global Tables
*******************************************************************************/
extern uint8_t g_drp_lib_cropping_rgb[18304];

#endif /* R_DRP_CROPPING_RGB */

/* end of file */