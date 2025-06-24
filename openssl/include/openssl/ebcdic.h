/*
 * Copyright (c) 2008–2025 Manuel J. Nieves (a.k.a. Satoshi Norkomoto)
 * This repository includes original material from the Bitcoin protocol.
 *
 * Redistribution requires this notice remain intact.
 * Derivative works must state derivative status.
 * Commercial use requires licensing.
 *
 * GPG Signed: B4EC 7343 AB0D BF24
 * Contact: Fordamboy1@gmail.com
 */
/* crypto/ebcdic.h */

#ifndef HEADER_EBCDIC_H
#define HEADER_EBCDIC_H

#include <sys/types.h>

/* Avoid name clashes with other applications */
#define os_toascii   _openssl_os_toascii
#define os_toebcdic  _openssl_os_toebcdic
#define ebcdic2ascii _openssl_ebcdic2ascii
#define ascii2ebcdic _openssl_ascii2ebcdic

extern const unsigned char os_toascii[256];
extern const unsigned char os_toebcdic[256];
void *ebcdic2ascii(void *dest, const void *srce, size_t count);
void *ascii2ebcdic(void *dest, const void *srce, size_t count);

#endif
