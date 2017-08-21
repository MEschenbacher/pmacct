#ifndef _CHECKSUM_H_
#define _CHECKSUM_H_

#if (!defined __CHECKSUM_C)
#else
#endif
int in_cksum(void *, int);
u_int16_t fletcher_checksum(u_char *, const size_t, const uint16_t);

#endif /* _CHECKSUM_H_ */
