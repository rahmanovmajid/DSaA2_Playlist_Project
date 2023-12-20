#include"tracknode.h"



struct TrackNode *TrackNode_new(struct Track *track){

    struct TrackNode *node=(struct TrackNode*)malloc(sizeof(struct TrackNode));
    node->track = track;
    node->prevTrackNode = NULL;
    node->nextTrackNode = NULL; 

    return node;


}