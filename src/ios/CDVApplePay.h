#import <UIKit/UIKit.h>
#import <Cordova/CDVPlugin.h>

#import <PassKit/PassKit.h>

typedef void (^ARAuthorizationBlock)(PKPaymentAuthorizationStatus);

@interface CDVApplePay : CDVPlugin <PKPaymentAuthorizationViewControllerDelegate>
{
    PKMerchantCapability merchantCapabilities;
    NSArray<NSString *> *supportedPaymentNetworks;
    NSString *clientSecret;
}

@property(nonatomic, strong) ARAuthorizationBlock paymentAuthorizationBlock;
@property(nonatomic, strong) NSString *paymentCallbackId;
@property(nonatomic, readwrite) BOOL paymentSucceeded;

- (void)makePaymentRequest:(CDVInvokedUrlCommand *)command;
- (void)canMakePayments:(CDVInvokedUrlCommand *)command;
- (void)completeLastTransaction:(CDVInvokedUrlCommand *)command;

@end
