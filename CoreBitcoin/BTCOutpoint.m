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

#import "BTCOutpoint.h"
#import "BTCTransaction.h"
#import "BTCHashID.h"

@implementation BTCOutpoint

- (id) initWithHash:(NSData*)hash index:(uint32_t)index {
    if (hash.length != 32) return nil;
    if (self = [super init]) {
        _txHash = hash;
        _index = index;
    }
    return self;
}

- (id) initWithTxID:(NSString*)txid index:(uint32_t)index {
    NSData* hash = BTCHashFromID(txid);
    return [self initWithHash:hash index:index];
}

- (NSString*) txID {
    return BTCIDFromHash(self.txHash);
}

- (void) setTxID:(NSString *)txID {
    self.txHash = BTCHashFromID(txID);
}

- (NSUInteger) hash {
    const NSUInteger* words = _txHash.bytes;
    return words[0] + self.index;
}

- (BOOL) isEqual:(BTCOutpoint*)object {
    return [self.txHash isEqual:object.txHash] && self.index == object.index;
}

- (id) copyWithZone:(NSZone *)zone {
    return [[BTCOutpoint alloc] initWithHash:_txHash index:_index];
}

@end
