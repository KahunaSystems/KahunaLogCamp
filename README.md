# KahunaLogCamp

![LogCamp](http://www.kahuna-mobihub.com/templates/ja_puresite/images/logo-trans.png)

LogCamp is analytics and logger library written in Objective-C

## Installation

### CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for Cocoa projects. 

```ruby
pod 'LogCamp', :git => 'https://github.com/PrasadPotale/KahunaLogCamp.git', :tag => ‘3.2.7’
```

## Add Logcamp To Project

### Swift Code:

```swift
KALogger.startSessionWithAppId("APP_ID", andAppKey: "APP_KEY", andServerUrl: "SERVER_URL")
```

#### Note:

Add ```swift#import <LogCamp/KahunaAnalytics.h>``` into PROJECT_NAME-Bridging-Header.h file

### Objective-C Code:

```swift
[KALogger startSessionWithAppId:@"APP_ID" andAppKey:@"APP_KEY" andServerUrl:@"SERVER_URL"];
```

By default it will use LogCamp API server url.

## Add Web Service Logs

To log webservice failure's

```swift
KALogger.sendDeviceLogsToServerWithRequest("WEBSERVICE_REQUEST_JSON_STRING", withResponse: "WEBSERVICE_RESPONSE_JSON_STRING", urlPath: "WEBSERVICE_URL", userName: "USERNAME / EMAIL", errorCode: ERROR_CODE)

E.g. :  KALogger.sendDeviceLogsToServerWithRequest("Sample Request Format", withResponse: "Sample Response Format", urlPath: "http://google.com", userName: "John@email.com", errorCode: NSNumber(double:5.0))
```

## Add TIME STAMP / PROFILER LOGS

To log timestamp details of webservice

```swift
KALogger.sendTimeStampLogsToServerForServiceType("SERVICE_TYPE", responseStatus: "SUCCESS / FAILURE / UNKNOWN", mobileRequestStartTime: "2016-11-16T17:03:45", mobileResponseReceiveTime: "2016-11-16T17:03:45", mobileServiceParseTime: "2016-11-16T17:03:45", serverRequestReceiveTime: "2016-11-16T17:03:45", serverResponseStartTime: "2016-11-16T17:03:45")
 
 E.g. :   KALogger.sendTimeStampLogsToServerForServiceType("Login", responseStatus: "Success", mobileRequestStartTime: "2016-11-16T17:03:45", mobileResponseReceiveTime: "2016-11-16T17:03:49", mobileServiceParseTime: "2016-11-16T17:03:49", serverRequestReceiveTime: "2016-11-16T17:03:45", serverResponseStartTime: "2016-11-16T17:03:47")
 ```
 
## Add Ratings / Feedback

Can be used to add Ratings to app or send feedback, issue screenshots

```swift
KALogger.addRatings(RATINGS_NUMBER, summary: "RATINGS_SUMMARY", comment: "RATINGS_COMMENT", userId: "USERID / USEREMAIL", username: "USERNAME", imagePaths: ARRAY_OF_IMAGES)
 
 E.g. KALogger.addRatings(NSNumber(double: 4.0), summary: "Test Ratings", comment: "Test Comment", userId: "user@email.com", username: "Test User", imagePaths: ["image local directory path"])
  ```
 
## Add Events

To track specific events into app, E.g. User Added Item into Cart, User Clicked on Social Login Etc.

 ```swift
 KALogger.logEvent("EVENT_NAME", withParameters: ["Key1":"Value1", "Key2":"Value2"])
   ```

## Add Logs

To add logs use

 ```swift
KALogger.log("Test Message")
   ```

In Objective-C
 ```swift
KLog("Test Message");
   ```
