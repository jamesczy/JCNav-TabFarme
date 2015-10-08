//
//  UIDeviceIdent.h
//
//  Created by Christopher Jones
//

#import <Foundation/Foundation.h>
#import "UIKit/UIKit.h"


@interface UIDeviceIdent : NSObject

+ (NSString *) macaddress;
+ (NSString *) uniqueDeviceIdentifier;
+ (NSString *) uniqueGlobalDeviceIdentifier;
+ (NSString *) stringFromMD5:(NSString*)str;

@end
