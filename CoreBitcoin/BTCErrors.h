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

extern NSString* const BTCErrorDomain;

typedef NS_ENUM(NSUInteger, BTCErrorCode) {
    
    // Canonical pubkey/signature check errors
    BTCErrorNonCanonicalPublicKey            = 4001,
    BTCErrorNonCanonicalScriptSignature      = 4002,
    
    // Script verification errors
    BTCErrorScriptError                      = 5001,
    
    // BTCPriceSource errors
    BTCErrorUnsupportedCurrencyCode          = 6001,

    // BIP70 Payment Protocol errors
    BTCErrorPaymentRequestInvalidResponse    = 7001,
    BTCErrorPaymentRequestTooBig             = 7002,

    // Secret Sharing errors
    BTCErrorIncompatibleSecret               = 10001,
    BTCErrorInsufficientShares               = 10002,
    BTCErrorMalformedShare                   = 10003,
};