#include"playlist.h"

int main () {
    
    //struct Track *tr = Track_new("Love Me Again", "Pop", "John Newman",197);
    //Track_print(tr);
    




    struct Playlist *pl = Playlist_new("Travel");
    //printf("Playlist was created now.\n");

    Playlist_append(&pl,Track_new("Tourner dans le vide", "Pop", "Indila", 190));
    Playlist_append(&pl,Track_new("Worlds Apart", "Sad", "Ash", 193));
    Playlist_append(&pl,Track_new("Mosaique", "Sad", "Ash", 190));
    Playlist_append(&pl,Track_new("Goodbye", "Strange", "Apparat", 190));
    Playlist_append(&pl,Track_new("Hotel California", "Pop", "Eagles", 190));
    Playlist_append(&pl,Track_new("C'est vraiment toi", "Rock", "Telephone", 190));

    //Playlist_change_order(&pl,"Mosaique",1);
    //Playlist_clear(pl);
    //Playlist_play(pl);
    //Playlist_shuffle(pl);

    struct Playlist *pl2 = Playlist_new("While Coding");

    printf("Second playlist was created.\n");

    Playlist_append(&pl2,Track_new("Mellohi", "Minecraft", "C418", 190));
    Playlist_append(&pl2,Track_new("Back to you", "Beat", "Goapele", 193));
    Playlist_append(&pl2,Track_new("My way", "Old", "Frank Sinatra", 190));


    //Playlist_play(pl2);

    Playlist_move(&pl,&pl2,"Mosaique");

    Playlist_play(pl);
    Playlist_play(pl2);


    // printf("salush\n");
    // Track_print(Playlist_shuffle(myplaylist));
   



    return 0;
}