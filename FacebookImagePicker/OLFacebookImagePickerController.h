//
//  FacebookImagePickerController.h
//  FacebookImagePicker
//
//  Created by Deon Botha on 16/12/2013.
//  Copyright (c) 2013 Deon Botha. All rights reserved.
//

#import <UIKit/UIKit.h>
@import FBSDKCoreKit;
@class OLFacebookImagePickerController;
@class OLFacebookImage;

@protocol OLFacebookImagePickerControllerDelegate <NSObject>

- (void)facebookImagePicker:(OLFacebookImagePickerController *)imagePicker didFailWithError:(NSError *)error;
- (void)facebookImagePicker:(OLFacebookImagePickerController *)imagePicker didFinishPickingImages:(NSArray/*<OLFacebookImage>*/ *)images;
- (void)facebookImagePickerDidCancelPickingImages:(OLFacebookImagePickerController *)imagePicker;
@optional
- (void)facebookImagePicker:(OLFacebookImagePickerController *)imagePicker didSelectImage:(OLFacebookImage *)image;
- (BOOL)facebookImagePicker:(OLFacebookImagePickerController *)imagePicker shouldSelectImage:(OLFacebookImage *)image;
@end


/**
 The OLFacebookImagePickerController class provides a simple UI for a user to pick photos from their Facebook account. It
 provides an image picker interface that matches the iOS SDK's UIImagePickerController. It takes care of all
 authentication with Facebook as and when necessary. It will automatically renew auth tokens or prompt
 the user to re-authorize the app if needed. You need to have set up your application correctly to work with Facebook as per
 https://developers.facebook.com/docs/ios/getting-started
 */
@interface OLFacebookImagePickerController : UINavigationController

- (id)initWithAccessToken:  (NSString *)tokenString
              permissions:    (NSArray *)permissions
      declinedPermissions:    (NSArray *)declinedPermissions
       expiredPermissions: (NSArray *)expiredPermissions
                    appID:    (NSString *)appID
                   userID:    (NSString *)userID
           expirationDate:    (NSDate *)expirationDate
              refreshDate:    (NSDate *)refreshDate
 dataAccessExpirationDate: (NSDate *)dataAccessExpirationDate;

- (id)initWithDefaultAccessToken:(FBSDKAccessToken *)accessToken;
/**
 The image picker’s delegate object.
 */
@property (nonatomic, weak) id <UINavigationControllerDelegate, OLFacebookImagePickerControllerDelegate> delegate;

/**
 Holds the currently user selected images in the picker UI. Setting this property will result in the corresponding images in the picker UI updating.
 */
@property (nonatomic, copy) NSArray/*<OLFacebookImage>*/ *selected;

@property (nonatomic, assign) BOOL shouldDisplayLogoutButton;

@end
