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
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#endif

@interface BTCQRCode : NSObject

#if TARGET_OS_IPHONE
/*!
 * Returns a QR code image with a given size.
 * The `string` is typically a bitcoin address in Base58Check format.
 */
+ (UIImage*) imageForString:(NSString*)string size:(CGSize)size scale:(CGFloat)scale;

/*!
 * Returns a QR code image with a given size.
 * The `url` is typically a bitcoin payment request "bitcoin:<address>?amount=..."
 */
+ (UIImage*) imageForURL:(NSURL*)url size:(CGSize)size scale:(CGFloat)scale;

/*!
 * Returns a scanning view and retains a detection block.
 *
 * Block is called for every QR code detected. To stop recognition, remove view from the window.
 *
 * Block is released when view is removed from window.
 */
+ (UIView*) scannerViewWithBlock:(void(^)(NSString* message))detectionBlock;


/*!
 * Returns a scanning view and retains a detection block.
 *
 * Block is called for every QR code detected. To stop recognition, remove view from the window.
 *
 * Block is released when view is removed from window.
 *
 * The device position helps selecting the camera (front or back)
 */
+ (UIView*) scannerViewUsingDevice:(AVCaptureDevicePosition) devicePosition
                       orientation:(AVCaptureVideoOrientation) orientation
                             block:(void(^)(NSString* message))detectionBlock;
#endif

@end
