/*
 * sccb.h
 *
 */

#ifndef SAMPLE_PROGRAMS_SCCB_H_
#define SAMPLE_PROGRAMS_SCCB_H_

int sccb_write(int address, const char *data, int length) ;
int sccb_read(int address, char *data, int length) ;

#endif /* SAMPLE_PROGRAMS_SCCB_H_ */
