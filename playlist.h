#include"tracknode.h"

struct Playlist{

	char *Name;
	struct TrackNode *head;
	struct TrackNode *tail;
	int nTracks;
	int TotalDuree;
	struct TrackNode *current;
	int current_duree;
};



struct Playlist *Playlist_new(char *name);	 


void Playlist_append(struct Playlist **pl,struct Track *tr); 

void Playlist_delete(struct Playlist **pl,char *title);

void Playlist_change_order(struct Playlist **pl, char *title, int order);

void Playlist_clear(struct Playlist *pl);

void Playlist_play(struct Playlist *pl);

void Playlist_move(struct Playlist **pl1,struct Playlist **pl2, char * title);

void Playlist_shuffle(struct Playlist *pl);

