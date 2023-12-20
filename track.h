#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct Track{
	char *Title;
	char *Genre;
	char *Artist;
	int Duree;
};


struct Track *Track_new(char *title,char *genre,char *artist,int duree);

void Track_print(struct Track *tr);
