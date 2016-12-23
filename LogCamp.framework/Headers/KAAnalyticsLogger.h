//
//  KAAnalyticsLogger.h
//  AnalyticsTest
//
//  Copyright (c) 2013 KAHUNA. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KAAnalyticsLogger : NSObject
{
@private
    NSString *_analyticsFilename;
    NSString *_eventsFileName;
    NSString *_sessionStartTime;
    NSString *_sessionEndTime;
    NSMutableString *_screens;
    NSMutableDictionary *_singleScreenData;
    NSMutableString *_wholeSessionString;
    BOOL _isLocationAvailable;
    NSString *_appId;
    NSString *_appKey;
    NSOperationQueue *_writeQueue;
    NSMutableDictionary *_timmedEventsDictionary;
   
}

@property (nonatomic,strong) NSString *eventsFileName;
@property (nonatomic,strong) NSString *analyticsFilename;
@property (nonatomic,strong) NSString *sessionStartTime;
@property (nonatomic,strong) NSString *sessionEndTime;
@property (nonatomic,strong) NSMutableString *screens;
@property (nonatomic,strong) NSMutableString *wholeSessionString;
@property (nonatomic,strong) NSMutableDictionary *singleScreenData;
@property (nonatomic,strong) NSString *appId;
@property (nonatomic,strong) NSString *appKey;
@property (nonatomic,strong) NSOperationQueue *writeQueue;
@property (nonatomic,strong) NSMutableDictionary *timmedEventsDictionary;
@property (nonatomic,unsafe_unretained) BOOL isLocationAvailable;


- (id)initWithAppId:(NSString*)appId:(NSString*)appKey;
- (void)startScreenDataWithScreenId:(NSString*)screenId;
- (void)endScreenData;
- (void)writeLattitude:(double)lattitude:(double)longitude;
- (void)createLogFile;
- (void)writeSessionEndTime;
- (void)logEvent:(NSString*)eventName parameters:(NSDictionary*)parameters;
- (void)logEvent:(NSString*)eventName withParameters:(NSDictionary*)parameters isTimedEvent:(BOOL)isTimmed;
- (void)endTimedEvent:(NSString*)eventName withParameters:(NSDictionary*)parameters;
//- (void)writeEventsJson:(NSString*)eventsJson;
@end
