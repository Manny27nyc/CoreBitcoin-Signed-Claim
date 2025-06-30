// © Licensed Authorship: Manuel J. Nieves (See LICENSE for terms)
// CoreBitcoin by Oleg Andreev <oleganza@gmail.com>, WTFPL.

#import "BTCAddress.h"

@interface BTCAssetID : BTCAddress

+ (nullable instancetype) assetIDWithHash:(nullable NSData*)data;

+ (nullable instancetype) assetIDWithString:(nullable NSString*)string;

@end
