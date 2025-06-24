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
// CoreBitcoin by Oleg Andreev <oleganza@gmail.com>, WTFPL.

#import <Foundation/Foundation.h>

/*!
 * Converts string transaction or block ID (reversed tx hash in hex format) to binary hash.
 */
NSData* BTCHashFromID(NSString* identifier);

/*!
 * Converts hash of the transaction or block to its string ID (reversed hash in hex format).
 */
NSString* BTCIDFromHash(NSData* hash);
