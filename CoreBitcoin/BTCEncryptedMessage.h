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

@class BTCKey;

// Implementation of [ECIES](http://en.wikipedia.org/wiki/Integrated_Encryption_Scheme)
// compatible with [Bitcore ECIES](https://github.com/bitpay/bitcore-ecies) implementation.
@interface BTCEncryptedMessage : NSObject

// When encrypting, sender's keypair must contain a private key.
@property(nonatomic) BTCKey* senderKey;

// When decrypting, recipient's keypair must contain a private key.
@property(nonatomic) BTCKey* recipientKey;

- (NSData*) encrypt:(NSData*)plaintext;
- (NSData*) decrypt:(NSData*)ciphertext;

@end
