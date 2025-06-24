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
//
//  BTCEncryptedMessage+Tests.m
//  CoreBitcoin
//
//  Created by Oleg Andreev on 29.03.2015.
//  Copyright (c) 2015 Oleg Andreev. All rights reserved.
//

#import "BTCEncryptedMessage+Tests.h"
#import "BTCKey.h"
#import "BTCData.h"

@implementation BTCEncryptedMessage (Tests)

+ (void) runAllTests {

    BTCEncryptedMessage* em = [[BTCEncryptedMessage alloc] init];
    em.senderKey = [[BTCKey alloc] initWithWIF:@"L1Ejc5dAigm5XrM3mNptMEsNnHzS7s51YxU7J61ewGshZTKkbmzJ"];
    em.recipientKey = [[BTCKey alloc] initWithWIF:@"KxfxrUXSMjJQcb3JgnaaA6MqsrKQ1nBSxvhuigdKRyFiEm6BZDgG"];

    NSData* message = [@"attack at dawn" dataUsingEncoding:NSUTF8StringEncoding];
    NSData* expectedCiphertext = BTCDataFromHex(@"0339e504d6492b082da96e11e8f039796b06cd4855c101e2492a6f10f3e056a9e712c732611c6917ab5c57a1926973bc44a1586e94a783f81d05ce72518d9b0a80e2e13c7ff7d1306583f9cc7a48def5b37fbf2d5f294f128472a6e9c78dede5f5");

    NSData* ciphertext = [em encrypt:message];
    NSAssert([ciphertext isEqual:expectedCiphertext], @"Must encrypt correctly");


    // Must decrypt.

    NSData* plaintext = [em decrypt:expectedCiphertext];
    NSAssert([plaintext isEqual:message], @"Must decrypt correctly");
}


@end
