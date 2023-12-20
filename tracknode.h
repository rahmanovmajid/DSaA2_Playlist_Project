#include"track.h"


struct TrackNode{
	struct Track *track;
	struct TrackNode *prevTrackNode;
	struct TrackNode *nextTrackNode;
};


struct TrackNode *TrackNode_new(struct Track *track);
