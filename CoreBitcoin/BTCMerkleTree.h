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

@interface BTCMerkleTree : NSObject

// Returns the merkle root of the tree, a 256-bit hash.
@property(nonatomic, readonly) NSData* merkleRoot;

// Returns YES if the merkle tree has duplicate items in the tail that cause merkle root collision.
// See also CVE-2012-2459.
@property(nonatomic, readonly) BOOL hasTailDuplicates;

// Builds a merkle tree based on raw hashes.
- (id) initWithHashes:(NSArray*)hashes;

// Builds a merkle tree based on transaction hashes.
- (id) initWithTransactions:(NSArray* /* [BTCTransaction] */)transactions;

// Builds a merkle tree based on BTCHash256 hashes of each NSData item.
- (id) initWithDataItems:(NSArray* /* [NSData] */)dataItems;

@end
