#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tunez.h"

void print_list( song_node *n ) {
  while(n->next) {
    printf("song: %s, artist: %s\n", n->name, n->artist);
    n = n->next;
  }
}

song_node * insert_front(song_node *n, char name[256], char artist[256]){
  song_node *new = ( song_node *)malloc(sizeof(song_node));
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  new->next = n;
  return new;
}

song_node * free_list(song_node *n) {
  song_node *f = n;
  while ( n ) {
    n = n->next;
    free(f);
    f = n;    
  }
  return n;
}

// helper for search_song
song_node * search_in_node( song_node * n, char * name ){
  while (n){
    if (strcmp(name, n->name)) {
      n = n->next;
    } else {
      return n;
    }
  }
  return n;
}

// find pointer to song based on song name
song_node * search_song( song_node p[26], char * name ){  
  return 0;
}

// find first song of artist based on artist name
song_node * first_song_of( song_node n, char * artist){
  int i = 0;
  for ( i = 0; i < 26; i++ ){
    
  }
  return 0;
}

// find artist
song_node * search_artist( song_node p[26], char * artist ){
 
  return 0;
}

// helper of add_song, add new song_node to playlist
void add_song_node(song_node p[26], song_node * n) {
  
}

// create new song_node, pass to add_song_node
void add_song(char * name, char * artist){  
  song_node *n = ( song_node * )malloc(sizeof( song_node ));
  strcpy(n->name, name);
  strcpy(n->artist, artist);
  add_song_node(n);
  printf("new song %s by %s added\n",name,artist);
}


song_node * print_song( song_node *n ){
  printf("song: %s |", n->name);
  printf("artist: %s\n",n->artist);
}

// ------------------------------------------ //


int main(){
  printf("------RUN------\n");
  song_node *playlist[26];
  printf("playlist[26]\n");
  
  a->next = a2;
  
  printf("print_list\n");
  print_list(a);
  
  song_node *a0 = ( song_node * )malloc(sizeof( song_node ));
  
  printf("insert_front\n");
  char name[256] = "test song a";
  char artist[256] = "a";
  a0 = insert_front(a, name, artist);
  print_list(a0);
  char test[256] = "hello";
   
  free_list(a0);

  printf("------RUN END------\n");
}


