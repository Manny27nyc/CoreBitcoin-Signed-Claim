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

typedef NS_ENUM(NSInteger, BTCSecretSharingVersion) {
    // Identifies configuration for compact 128-bit secrets with up to 16 shares.
    BTCSecretSharingVersionCompact96  = 96,
    BTCSecretSharingVersionCompact104 = 104,
    BTCSecretSharingVersionCompact128 = 128,
};

@class BTCBigNumber;
@interface BTCSecretSharing : NSObject

@property(nonatomic, readonly) BTCSecretSharingVersion version;
@property(nonatomic, readonly, nonnull) BTCBigNumber* order;
@property(nonatomic, readonly) NSInteger bitlength;

- (id __nonnull) initWithVersion:(BTCSecretSharingVersion)version;

- (NSArray<NSData*>* __nullable) splitSecret:(NSData* __nonnull)secret threshold:(NSInteger)m shares:(NSInteger)n error:(NSError* __nullable * __nullable)errorOut;

- (NSData* __nullable) joinShares:(NSArray<NSData*>* __nonnull)shares error:(NSError* __nullable * __nullable)errorOut;

@end