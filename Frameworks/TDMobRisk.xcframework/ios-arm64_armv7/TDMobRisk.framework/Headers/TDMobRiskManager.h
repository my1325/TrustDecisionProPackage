//
//  TDMobRiskManager.h
//  TDMobRisk
//

#import <Foundation/Foundation.h>

#define TDMOBRISK_SDK_VERSION @"4.3.1.3"

typedef enum {
    
    TDLivenessShowStylePush,

    TDLivenessShowStylePresent,
    
} TDLivenessShowStyle;

typedef enum {
    
    // The Captcha is verified successfully, and a valid validateToken can be obtained at this time;
    TDShowCaptchaResultTypeSuccess,
    // If the Captcha fails, you can get the error code errorCode and errorMsg, and check the cause according to the `Error code` in the document;
    TDShowCaptchaResultTypeFailed,
    // The Captcha window pop-up is successful, waiting to be verified;
    TDShowCaptchaResultTypeReady,
    
} TDShowCaptchaResultType;

typedef void(^TDGetBlackBoxAsyncBlock)(NSString* blackBox);

typedef void(^TDErrorCodeBlock)(int errorCode, const char*errorMsg);

typedef struct _TDShowCaptchaResultStruct{
    
    // return result type
    const TDShowCaptchaResultType resultType;
    // After returning successfully, the token of the Captcha returned
    char* const validateToken;
    // After the return fails, the returned error code can be checked according to the document
    const NSInteger errorCode;
    // Return error message after failure
    char* const errorMsg;
    
}TDShowCaptchaResultStruct;

typedef void(^TDShowCaptchaBlock)(TDShowCaptchaResultStruct resultStruct);

typedef enum {
    
    // The Liveness is verified successfully;
    TDLivenessResultTypeSuccess,
    // If the Liveness fails, you can get the error code errorCode and errorMsg, and check the cause according to the `Error code` in the document;
    TDLivenessResultTypeFailed,
    // The Liveness window pop-up is successful, waiting to be verified;
    TDLivenessResultTypeReady,
    
} TDLivenessResultType;

typedef struct _TDLivenessResultStruct{
    // return result type
    const TDLivenessResultType resultType;
    // the seqId of the Liveness returned
    char* const seqId;
    // After the return fails, the returned error code can be checked according to the document
    const NSInteger errorCode;
    // Return error message after failure
    char* const errorMsg;
    // liveness score when success
    double score;
    // best image string
    char* const bestImageString;
    // liveness detection ID
    char* const livenessId;
    
}TDLivenessResultStruct;

typedef void(^TDShowLivenessBlock)(TDLivenessResultStruct resultStruct);

typedef struct _TDAPISignResult{
    // sign
    char* sign;
    // After the return fails, the returned error code can be checked according to the document
    int code;
    // Return error message after failure
    char* msg;
}TDAPISignResult;


typedef struct _tdMobRiskVoid {
/**
 * Initialization method
 * @param options Initialization parameters，please see the document for details.
 */
void (*initWithOptions)(NSDictionary *);
/**
 * get blackBox sync, you should make sure that method calls after initWithOptions.
 */
NSString *(*getBlackBox)(void);
/**
* get blackBox async, you should make sure that method calls after initWithOptions.
  @usage: manager->getBlackBoxAsync(^(NSString* blackBox){});
*/
void (*getBlackBoxAsync)(TDGetBlackBoxAsyncBlock block);
/**
* listen error code, use it before initWithOptions
  @usage: manager->setOnErrorCodeListener(^(int errorCode,const char* errorMsg){})
*/
void (*setOnErrorCodeListener)(TDErrorCodeBlock block);
/**
 * Display Captcha window
 * @usage: manager->showCaptcha(self.view,^(TDShowCaptchaResultStruct resultStruct) {
 * });
 * @param superView The parent view where the popup is displayed, UIView type
 * @param block result callback block
 */
void (*showCaptcha)(id superView,TDShowCaptchaBlock block);
    
/**
 * Display Captcha window
 * @usage: manager->showCaptcha(self.view,^(TDShowCaptchaResultStruct resultStruct) {
 * });
 * @param superView The parent view where the popup is displayed, UIView type
 * @param sceneToken scene token
 * @param block result callback block
 */
void (*showCaptchaWithToken)(id superView,NSString* sceneToken,TDShowCaptchaBlock block);
    
/**
 * Display Liveness window, will use [targetVC.navigationController pushViewController:lvctl animated:YES]; to show
 * @usage: manager->showLiveness(self,^(TDLivenessResultStruct resultStruct) {
 * });
 * @param targetVC The parent view where the popup is displayed, UIViewController type
 * @param block result callback block
*/
void (*showLiveness)(id targetVC,TDShowLivenessBlock block);
    
/**
* Display Liveness window
* @usage: manager->showLivenessWithShowStyle(self,nil,TDLivenessShowStylePresent,^(TDLivenessResultStruct resultStruct) {
* });
* @param targetVC The parent view where the popup is displayed, UIViewController type
* @param license auth license,can be nil
* @param showStyle TDLivenessShowStylePush or TDLivenessShowStylePresent
* @param block result callback block
*/
void (*showLivenessWithShowStyle)(id targetVC,NSString* _Nullable license,TDLivenessShowStyle showStyle,TDShowLivenessBlock block);

/**
* upload probe data
*/
void (*upload)(void);
    
/**
* start
*/
NSString* (*start)(void);
    
/**
* stop
*/
BOOL (*stop)(void);
    
/**
* getEid
*/
NSString* (*getEid)(void);
    
/**
 * Sign the queryDictionary parameter dictionary under the path
 * @usage: const char* sign = manager->sign(@"login");
 * @param path: network request path, such as: @"login"
*/
TDAPISignResult (*sign)(NSString *path);
    
/**
* get sdkVersion
*/
NSString *(*getSDKVersion)(void);

} TDMobRiskManager_t;

@interface TDMobRiskManager : NSObject
/**
 * get  a singleton object
 */
+ (TDMobRiskManager_t *)sharedManager;

@end
