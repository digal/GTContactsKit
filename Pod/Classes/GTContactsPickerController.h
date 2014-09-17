//
//  GTContactsPickerController.h
//  GTContactsKit
//
//  The MIT License (MIT)
//
//  Copyright (c) 2014 Gianluca Tranchedone (@gtranchedone)
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of
//  this software and associated documentation files (the "Software"), to deal in
//  the Software without restriction, including without limitation the rights to
//  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
//  the Software, and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
//  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
//  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
//  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import <UIKit/UIKit.h>

@class GTPerson;
@class GTContactsPicker;

typedef NS_ENUM(NSInteger, GTContactsPickerStyle) {
    GTContactsPickerStyleDefault,
    GTContactsPickerStyleMail
};

@protocol GTContactsPickerControllerDelegate;

@interface GTContactsPickerController : UITableViewController <UISearchBarDelegate>

@property (nonatomic, weak) id<GTContactsPickerControllerDelegate> delegate;
@property (nonatomic, assign) BOOL allowsCancellation;

@property (nonatomic, copy) NSArray *contacts;
@property (nonatomic, strong) GTContactsPicker *contactsPicker;
@property (nonatomic, assign) GTContactsPickerStyle pickerStyle;

- (instancetype)initWithStyle:(UITableViewStyle)style pickerStyle:(GTContactsPickerStyle)pickerStyle;
- (void)selectContactAtIndex:(NSUInteger)index;
- (NSArray *)selectedContacts;

@end

@protocol GTContactsPickerControllerDelegate <NSObject>

@optional
- (void)contactsPickerController:(GTContactsPickerController *)controller didFinishWithContacts:(NSArray *)pickedContacts;

@end
