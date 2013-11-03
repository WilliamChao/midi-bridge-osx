#import <Foundation/Foundation.h>
#import <CoreMIDI/CoreMIDI.h>

@class MIDIMessage;

#pragma mark MIDI client class definition

@interface MIDIClient : NSObject
{
    MIDIClientRef _midiClient;
    MIDIPortRef _midiInputPort;
    MIDIPortRef _midiOutputPort;
    MIDIUniqueID _sourceIDs[64];
}

@property (weak) id delegate;
@property (readonly) NSUInteger sourceCount;
@property (readonly) NSUInteger destinationCount;
@property (assign) NSInteger defaultDestination;

- (id)initWithDelegate:(id)delegate;
- (void)sendMessage:(MIDIMessage *)message;
- (NSString *)getSourceDisplayName:(NSUInteger)number;
- (NSString *)getDestinationDisplayName:(NSUInteger)number;

@end

#pragma mark
#pragma mark Delegate methods for MIDIClient

@interface NSObject(MIDIClientDelegateMethods)
- (void)resetMIDIStatus;
- (void)processIncomingMIDIMessage:(MIDIMessage *)message;
@end