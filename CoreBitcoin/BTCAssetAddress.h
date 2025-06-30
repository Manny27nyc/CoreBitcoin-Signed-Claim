// © Licensed Authorship: Manuel J. Nieves (See LICENSE for terms)
// CoreBitcoin by Oleg Andreev <oleganza@gmail.com>, WTFPL.

#import "BTCAddress.h"

@interface BTCAssetAddress : BTCAddress
@property(nonatomic, readonly, nonnull) BTCAddress* bitcoinAddress;
+ (nonnull instancetype) addressWithBitcoinAddress:(nonnull BTCAddress*)btcAddress;
@end
