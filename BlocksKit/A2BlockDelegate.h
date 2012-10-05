//
//  A2BlockDelegate.h
//  A2DynamicDelegate
//
//  Created by Alexsander Akers on 11/30/11.
//  Copyright (c) 2011 Pandamonia LLC. All rights reserved.
//

#import "BKGlobals.h"

/** The A2BlockDelegate category extends features provided
 by A2DynamicDelegate to create custom block properties in
 a category on a delegating object and dynamically map them
 to delegate (`UIAlertViewDelegate`),
 data source (`UITableViewDataSource`), or other delegated
 protocol (`NSErrorRecoveryAttempting`) methods.
 
 Simply call one of the methods in the category on a class
 to add a block property to that class.
 
 These methods should be called in a category's `+load` method,
 before the application starts.
 */
@interface NSObject (A2BlockDelegate)

/** @name Data Source Properties */

/** Synthesizes a property with the given name and
 links it to the given selector in the data source
 protocol.
 
 A2DynamicDelegate assumes a protocol name `FooBarDataSource`
 for instances of class `FooBar`. The method will generate
 appropriate `setHandler:` and `handler` implementations for
 the given property name.
 
 @param propertyName A property name to synthesize. Must not be NULL.
 @param selector An encoded selector. Must not be NULL.
 */
+ (void) linkCategoryBlockProperty: (NSString *) propertyName withDataSourceMethod: (SEL) selector;

/** Synthesizes multiple properties and links them to
 the appropriate selector in the data source protocol.
 
 A2DynamicDelegate assumes a protocol name `FooBarDataSource`
 for instances of class `FooBar`. The method will generate
 appropriate `setHandler:` and `handler` implementations for
 each property name and selector name string pair.
 
 @param selectorsForPropertyNames A dictionary with property
 names as keys and selectors (as strings) as objects.
 */
+ (void) linkDataSourceMethods: (NSDictionary *) selectorsForPropertyNames;

/** @name Delegate Properties */

/** Synthesizes a property with the given name and
 links it to the given selector in the delegate protocol.
 
 A2DynamicDelegate assumes a protocol name `FooBarDelegate`
 for instances of class `FooBar`. The method will generate
 appropriate `setHandler:` and `handler` implementations for
 the given property name.
 
 @param propertyName A property name to synthesize. Must not be NULL.
 @param selector An encoded selector. Must not be NULL.
 */
+ (void) linkCategoryBlockProperty: (NSString *) propertyName withDelegateMethod: (SEL) selector;

/** Synthesizes multiple properties and links them to
 the appropriate selector in the delegate protocol.
 
 A2DynamicDelegate assumes a protocol name `FooBarDelegate`
 for instances of class `FooBar`. The method will generate
 appropriate `setHandler:` and `handler` implementations for
 each property name and selector name string pair.
 
 @param selectorsForPropertyNames A dictionary with property
 names as keys and selectors (as strings) as objects.
 */
+ (void) linkDelegateMethods: (NSDictionary *) selectorsForPropertyNames;

/** @name Other Protocol Properties */

/** Synthesizes a property with the given name and
 links it to the given selector in the given protocol.
 
 The method will generate appropriate `setHandler:`
 and `handler` implementations for the given property name.
 
 @param propertyName A property name to synthesize. Must not be NULL.
 @param protocol A protocol that declares the given selector. Must not be NULL.
 @param selector An encoded selector. Must not be NULL.
 */
+ (void) linkCategoryBlockProperty: (NSString *) propertyName withProtocol: (Protocol *) protocol method: (SEL) selector;

/** Synthesizes multiple properties and links them to
 the appropriate selector in the given protocol.
 
 The method will generate appropriate `setHandler:`
 and `handler` implementations for each property name and
 selector name string pair.
 
 @param protocol A protocol that declares all of the given
 selectors. Must not be NULL.
 @param selectorsForPropertyNames A dictionary with property
 names as keys and selectors (as strings) as objects.
 */
+ (void) linkProtocol: (Protocol *) protocol methods: (NSDictionary *) selectorsForPropertyNames;

/** @name Delegate replacement properties */

/** Registers a dynamic data source replacement using
 the property name `dataSource` and the protocol name
 `FooBarDataSource` for an instance of `FooBar`. */
+ (void) registerDynamicDataSource;

/** Registers a dynamic delegate replacement using
 the property name `delegate` and the protocol name
 `FooBarDelegate` for an instance of `FooBar`. */
+ (void) registerDynamicDelegate;

/** Registers a dynamic data source replacement using
 the given property name and the protocol name
 `FooBarDataSource` for an instance of `FooBar`.

 @param dataSourceName The name of the class' data
 source property. Must not be nil.
 */
+ (void) registerDynamicDataSourceNamed: (NSString *) dataSourceName;

/** Registers a dynamic delegate replacement using
 the given property name and the protocol name
 `FooBarDelegate` for an instance of `FooBar`.

 @param delegateName The name of the class'
 delegate property. Must not be nil.
 */
+ (void) registerDynamicDelegateNamed: (NSString *) delegateName;

/** Registers a dynamic protocol implementation replacement
 using the given property name and the given protocol.

 @param delegateName The name of the class' delegation
 protocol property, such as `safeDelegate`. Must not be nil.
 @param protocol A properly encoded protocol. Must not
 be NULL.
 */
+ (void) registerDynamicDelegateNamed: (NSString *) delegateName forProtocol: (Protocol *) protocol;

@end
