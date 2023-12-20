#include"playlist.h"



struct Playlist *Playlist_new(char *name){
    struct Playlist *playlist=(struct Playlist*) malloc(sizeof(struct Playlist));
    playlist->Name=name;
    playlist->head=NULL;
    playlist->tail=NULL;
    playlist->nTracks=0;
    playlist->TotalDuree=0;
    playlist->current=NULL;
    playlist->current_duree=0;

    return playlist;


    
}



void Playlist_append(struct Playlist **pl,struct Track *tr){
    struct TrackNode *tracknode = TrackNode_new(tr);

    if((*pl)->head==NULL) {
      

        (*pl)->head=tracknode;
        (*pl)->tail=tracknode;
        (*pl)->nTracks++;
        (*pl)->TotalDuree+=tracknode->track->Duree;

    }
    
   else if((*pl)->head!=NULL) {
        tracknode->nextTrackNode=(*pl)->head;
        (*pl)->head->prevTrackNode=tracknode;
        (*pl)->head=tracknode;
        (*pl)->TotalDuree+=tracknode->track->Duree;
        (*pl)->nTracks++;
        

       
    }
}

 void Playlist_delete(struct Playlist **pl,char *title){

        struct TrackNode *search_node=(*pl)->head;

        while (search_node!=NULL) {
           
            if(search_node->track->Title==title) {

                if(search_node->prevTrackNode==NULL) {
                    search_node->nextTrackNode->prevTrackNode=NULL;
                    (*pl)->head=search_node->nextTrackNode;
                }
                else if(search_node->nextTrackNode==NULL) {
                    search_node->prevTrackNode->nextTrackNode=NULL;
                    (*pl)->tail=search_node->prevTrackNode;
                }

                else {
                search_node->prevTrackNode->nextTrackNode=search_node->nextTrackNode;
                search_node->nextTrackNode->prevTrackNode=search_node->prevTrackNode;
                }

                (*pl)->nTracks--;
               (*pl)->TotalDuree-=search_node->track->Duree;

            }

            search_node=search_node->nextTrackNode;
            
        }

    }


    void Playlist_change_order(struct Playlist **pl, char *title, int order) {
       struct TrackNode *after=(*pl)->head;

       if(order>(*pl)->nTracks) {
           printf("your playlist have %d tracks, first possible place is 1\n",(*pl)->nTracks );

       }
      else {

          struct TrackNode *search_node=(*pl)->head;

        while (search_node!=NULL) {
            
           
            if(search_node->track->Title==title) {


                if(search_node->prevTrackNode==NULL) {
                    search_node->nextTrackNode->prevTrackNode=NULL;
                    (*pl)->head=search_node->nextTrackNode;

                }
                else if(search_node->nextTrackNode==NULL) {
                    search_node->prevTrackNode->nextTrackNode=NULL;
                    (*pl)->tail=search_node->prevTrackNode;

                }

                else {
                search_node->prevTrackNode->nextTrackNode=search_node->nextTrackNode;
                search_node->nextTrackNode->prevTrackNode=search_node->prevTrackNode;

                }

                break;


            }

            search_node=search_node->nextTrackNode;

        }

           for (int i=1; i<order; i++ ) {
               after=after->nextTrackNode;

           }
                       
            if (after==NULL) {

               search_node->prevTrackNode=(*pl)->tail;
               search_node->nextTrackNode=NULL;
               (*pl)->tail->nextTrackNode=search_node;
               (*pl)->tail=search_node;

           }

          else if (after->prevTrackNode==NULL) {
                 search_node->nextTrackNode=after;
                search_node->prevTrackNode=NULL;
                after->prevTrackNode=search_node;
                (*pl)->head=search_node;

           }


           else {

           search_node->nextTrackNode=after;
           search_node->prevTrackNode=after->prevTrackNode;
           after->prevTrackNode->nextTrackNode=search_node;
           after->prevTrackNode=search_node;

           }

        


  }


   }

    void Playlist_clear(struct Playlist *pl){
        pl->nTracks=0;
        pl->TotalDuree=0;
        pl->head=NULL;
        pl->tail=NULL;
        
    } 

    void Playlist_play(struct Playlist *pl) {

        printf("Name: %s\t\t",pl->Name);
        printf("# Tracks: %d\t\t",pl->nTracks);
        printf("Total Duration: %d\n",pl->TotalDuree);

   
     if(pl->head==NULL) {
        
            printf("EMPTY PLAYLIST\n");
        }

        else {
            pl->current=pl->head;
            while(pl->current) {
                Track_print(pl->current->track);
                pl->current=pl->current->nextTrackNode;
            }
        }

}

void Playlist_move(struct Playlist **pl1,struct Playlist **pl2, char *title) {
    struct TrackNode *search_node=(*pl1)->head;

      while (search_node!=NULL) {
            
           
            if(search_node->track->Title==title) {


                if(search_node->prevTrackNode==NULL) {
                    search_node->nextTrackNode->prevTrackNode=NULL;
                    (*pl1)->head=search_node->nextTrackNode;

                }
                else if(search_node->nextTrackNode==NULL) {
                    search_node->prevTrackNode->nextTrackNode=NULL;
                    (*pl1)->tail=search_node->prevTrackNode;

                }

                else {
                search_node->prevTrackNode->nextTrackNode=search_node->nextTrackNode;
                search_node->nextTrackNode->prevTrackNode=search_node->prevTrackNode;

                }

                (*pl1)->nTracks--;
                (*pl1)->TotalDuree-=search_node->track->Duree;
                break;


            }

            search_node=search_node->nextTrackNode;

        }

            Playlist_append(pl2,search_node->track);
    
}


void Playlist_shuffle(struct Playlist *pl) {
    int num;
    srand(time(NULL));
    num=rand()%pl->nTracks+1;

    for(int i=1; i<num; i++) {
        pl->head=pl->head->nextTrackNode;
    }
    printf("Shuffle.Now random music is playing in your list.\n"); 
    Track_print(pl->head->track);
}



 






