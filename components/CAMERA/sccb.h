/*
 * sccb.h
 *
 */

#ifndef _SCCB_H_
#define _SCCB_H_

// #ifdef __cplusplus
// extern "C" {
// #endif

int sccb_write(int address, const char *data, int length) ;
int sccb_read(int address, char *data, int length) ;

// #ifdef __cplusplus
// };
// #endif

#endif /* _SCCB_H_ */
