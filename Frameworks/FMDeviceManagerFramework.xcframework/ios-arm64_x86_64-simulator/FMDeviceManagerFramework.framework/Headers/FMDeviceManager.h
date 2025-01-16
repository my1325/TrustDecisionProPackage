//
//  FMDeviceManager.h
//  FMDeviceManager
//
//  
//

#define FM_SDK_VERSION @"4.3.1.3"

#import <Foundation/Foundation.h>

#ifdef __GNUC__
    #define DEPRECATED(func) func __attribute__ ((deprecated))
#elif defined(_MSC_VER)
    #define DEPRECATED(func) __declspec(deprecated) func
#else
    #pragma message("WARNING: You need to implement deprecated for this compiler")
    #define DEPRECATED(func) func
#endif

typedef void(^TDGetBlackBoxAsyncBlock)(NSString* blackBox);

typedef void(^TDErrorCodeBlock)(int errorCode, const char*errorMsg);

typedef struct FMDeviceManager_Void {
    
    void (*initWithOptions)(NSDictionary *);
    
    NSString *(*getBlackBox)(void);
    
    // manager->getBlackBoxAsync(^(NSString* blackBox){});
    void (*getBlackBoxAsync)(TDGetBlackBoxAsyncBlock block);
    
    // manager->setOnErrorCodeListener(^(int errorCode,const char* errorMsg){})
    void (*setOnErrorCodeListener)(TDErrorCodeBlock block);
    // DEPRECATED: This method is deprecated and should not be used.
    DEPRECATED(NSString *(*getInitStatus)(void));
    
    NSDictionary *(*getConfigInfo)(void);
    
} FMDeviceManager_t;

#ifdef SDKTYPE
#ifdef SAAS
@interface FMDeviceManager_SAAS : NSObject
#elif defined(ENTERPRISE)
@interface FMDeviceManager_ENTERPRISE : NSObject
#else
#error "error SDKTYPE"
#endif
#else
@interface FMDeviceManager : NSObject
#endif

+ (FMDeviceManager_t *) sharedManager;

@end

