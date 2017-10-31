//
//  KALogger.h
//  AnalyticsTest
//
//  Created by Kahuna Systems Pvt Ltd. on 08/04/13.
//  Copyright (c) 2013 KAHUNA. All rights reserved.
//

//V1.5
#import <Foundation/Foundation.h>

typedef void(^KAAPIResponseParser)(NSString *dictStr, NSError *error);

@interface KALogger : NSObject

@property (nonatomic,strong) NSString *KLoggerURL;

/*
 Pass App Id And App Key to start session
*/

+ (void)startSessionWithAppId:(NSString*)appId andAppKey:(NSString*)appKey andServerUrl:(NSString*)loggerUrl;




/*
 Starts monitoring time spent on perticular screen by using this method
 Need to pass screen Id for this method,
 A developer can decided screen id for each screen
*/

+ (void)startScreenDataWithScreenId:(NSString*)screenId;





/*
 Ends monitoring time spent on perticular screen 
 it will end the last monitoring started screen 
*/

+ (void)endScreenData;





/*
 Writes lattitude and longitude information
 */

+ (void)writeLattitude:(double)latitude andLongitude:(double)longitude;




/*
 User can log any perticuler event using this method need to pass parameter event name
 
 e.g. [KLogger logEvent:@"Serach"];
 
 */

+ (void)logEvent:(NSString*)eventName;




/*
 User can log any perticuler event using this method need to pass parameter event name
 
 e.g.
 
 NSDictionary *searchParameters = [NSDictionary dictionaryWithObjectsAndKeys:@"Parks", @"Search Term",@"Winston Park", @"Park Name",nil];
 [KALogger logEvent:@"Search" withParameters:searchParameters];;
*/

+ (void)logEvent:(NSString*)eventName withParameters:(NSDictionary*)parameters;




/*
 If user want to track time spent on event
 e.g Need to find information on maximum time spent on reading some book
 which twitter users tweets peoples reading most
 */
+ (void)logEvent:(NSString*)eventName withParameters:(NSDictionary*)parameters isTimedEvent:(BOOL)isTimmed;





/*
    User can end perticuler event also can pass any extra parameters if required
 */

+ (void)endTimedEvent:(NSString*)eventName withParameters:(NSDictionary*)parameters;




/*
 User can set log Level using this Method

 If you set the log level to LOG_LEVEL_ERROR, then you will only see KLogError statements. e.g. KLogError("Internal Error");
 
 If you set the log level to LOG_LEVEL_WARN, then you will only see KLogError and KLogWarn statements.
     e.g KLogWarn(@"test warn");
 
 If you set the log level to LOG_LEVEL_INFO, you'll see Error, Warn and Info statements.
     e.g. KLogInfo(@"test info");
 
  If you set the log level to LOG_LEVEL_VERBOSE, you'll see all KLog statements.
     e.g. KLog(@"test log");
 
 If you set the log level to LOG_LEVEL_OFF, you won't see any KLog statements.
*/

+ (void)setLogLevel:(int)logLevel;

/*
 For Objective-C based projects you can directly use KLog("Message");
 For Swift based projects you need to use below method as #defines not supported in swift
 */

+ (void)log:(NSString*)message;


/*
 To add ratings / feedback
 @param rating : Number value from 1-5
 @param summary : Summary details of rating
 @param comment : Comment added by user
 @param userID : user id added this comment E.g. it can be email id or actual user id
 @param userName : username of the use it can be email or user name
 @param imagePaths : Array of images that can be uploaded with rating / feedback
 @return Webservice response
 */
+ (NSString*)addRatings:(NSNumber*)rating summary:(NSString*)summary comment:(NSString*)comment userId:(NSString*)userId username:(NSString*)userName imagePaths:(NSArray*)imagePaths;


/*
  @return App Current Ratings Details
 */
+ (NSString*)getCurrentAppAverageRating;

/*
 Used to Register device token
 */
+ (NSString*)registerDeviceToken:(NSString*)deviceToken;

/*
 Send Logs To Server
 @param request : Request String
 @param response : Response String
 @param path : URL Path
 @param userName : Username
 @param appID : AppID
 */
+ (void)sendDeviceLogsToServerWithRequest:(NSString*)request
                             withResponse:(NSString*)response
                                  urlPath:(NSString*)path
                                 userName:(NSString*)userName
                                errorCode:(NSNumber*)code
                               completion:(KAAPIResponseParser)completionBlock;
/*
 Send Logs To Server
 @param ServiceType : Service Type
 @param responseStatus : Response Status
 @param mobileRequestStartTime : Mobile Request Start Time
 @param mobileResponseReceiveTime : Mobile Response Start Time
 @param mobileServiceParseTime : Mobile Service Parsing Time
 @param serverRequestReceiveTime : Server Request Recieve Time
 @param serverResponseStartTime : Server Response Start Time
 */
+ (void)sendTimeStampLogsToServerForServiceType:(NSString*)serviceType
                                 responseStatus:(NSString*)responseStatus
                         mobileRequestStartTime:(NSString*)mobileReqStartTime
                      mobileResponseReceiveTime:(NSString*)mobileResponseReceiveTime
                         mobileServiceParseTime:(NSString*)mobileServiceParseTime
                       serverRequestReceiveTime:(NSString*)serverRequestReceiveTime
                        serverResponseStartTime:(NSString*)serverResponseStartTime
                                     completion:(KAAPIResponseParser)completionBlock;

/*
 Enable / Disable Device Logs
 Default Value: True
 */
+ (void)enableServiceLogs:(BOOL)result;

/*Enable / Disable profile / time stamp logs
 Default Value: False
 */
+ (void)enableProfileLogs:(BOOL)result;

@end
