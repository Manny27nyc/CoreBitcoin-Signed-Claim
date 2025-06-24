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
// Oleg Andreev <oleganza@gmail.com>

#import "BTCProtocolSerialization+Tests.h"
#import "BTCData.h"

@implementation BTCProtocolSerialization (Tests)

+ (void) assertNumber:(uint64_t)number serializesToHex:(NSString*)hexForm {
    NSUInteger requiredLength = hexForm.length / 2;
    
    NSData* data = [BTCProtocolSerialization dataForVarInt:number];
    //NSLog(@"data = %@", data);
    NSAssert([data isEqualToData:BTCDataFromHex(hexForm)], @"Should encode correctly");
    uint64_t value = 0;
    NSUInteger len = [BTCProtocolSerialization readVarInt:&value fromData:data];
    NSAssert(len == requiredLength, @"Should read correct number of bytes");
    NSAssert(value == number, @"Should read original value");
    
    NSInputStream* stream = [NSInputStream inputStreamWithData:data];
    [stream open];
    len = [BTCProtocolSerialization readVarInt:&value fromStream:stream];
    [stream close];
    NSAssert(len == requiredLength, @"Should read 1 byte");
    NSAssert(value == number, @"Should read original value");
}

+ (void) runAllTests {
    [self assertNumber:0   serializesToHex:@"00"];
    [self assertNumber:252 serializesToHex:@"fc"];
    [self assertNumber:255ULL serializesToHex:@"fdff00"];
    [self assertNumber:12345ULL serializesToHex:@"fd3930"];
    [self assertNumber:65535ULL serializesToHex:@"fdffff"];
    [self assertNumber:65536ULL serializesToHex:@"fe00000100"];
    [self assertNumber:1234567890ULL serializesToHex:@"fed2029649"];
    [self assertNumber:1234567890123ULL serializesToHex:@"ffcb04fb711f010000"];
    [self assertNumber:UINT64_MAX serializesToHex:@"ffffffffffffffffff"];
}

@end
