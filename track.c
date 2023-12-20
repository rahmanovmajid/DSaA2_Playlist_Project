#include"track.h"


struct Track *Track_new(char *title,char *genre,char *artist,int duree){
    struct Track *track=(struct Track *)(malloc(sizeof(struct Track)));
    track->Title = title;
    track->Genre = genre;
    track->Artist = artist;
    track->Duree=duree;
    return track;
}

void Track_print(struct Track *tr) {

    printf("Title:%s\tArtist:%s\tGenre:%s\tDuree:%d\n",tr->Title,tr->Artist,tr->Genre,tr->Duree);

}

