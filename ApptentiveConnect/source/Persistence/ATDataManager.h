//
//  ATDataManager.h
//  ApptentiveConnect
//
//  Created by Andrew Wooster on 5/12/13.
//  Copyright (c) 2013 Apptentive, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

// Used to indicate a database upgrade or check was in progress and didn't complete.
extern NSString *const ATDataManagerUpgradeCanaryKey;

@interface ATDataManager : NSObject
@property (nonatomic, retain, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property (nonatomic, retain, readonly) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, retain, readonly) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, readonly) BOOL didRemovePersistentStore;
@property (nonatomic, readonly) BOOL didFailToMigrateStore;
@property (nonatomic, readonly) BOOL didMigrateStore;

- (id)initWithModelName:(NSString *)modelName inBundle:(NSBundle *)bundle storagePath:(NSString *)path;

- (NSURL *)persistentStoreURL;
- (BOOL)setupAndVerify;
@end
