#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tunez.h"

/*
You should start by making your linked lists work with the following functionality:

    insert nodes at the front
    insert nodes in order
    print the entire list
    find and return a pointer to an individual song based on song name
    find and return a pointer to the first song of an artist based on artist name
    Return a pointer to random element in the list.
    remove a single node from the list
    free the entire list

Then create your array of linked lists for the full program and have the following functions:

    Add songs.
    Search for a song.
    Search for an artist.
    Print out all the entries under a certain letter.
    Print out all the songs of a certain artist
    Print out the entire library.
    Shuffle - print out a series of randomly chosen songs.
    Delete a song
    Delete all the nodes.
*/

// make a new song node
song_node * new_song_node(char * name, char * artist){
  song_node *n = ( song_node * )malloc(sizeof( song_node ));
  strcpy(n->name, name);
  strcpy(n->artist, artist);
  return n;
}

void print_song( song_node *n ){
  printf("song: %s |", n->name);
  printf("artist: %s\n",n->artist);
}

// print out linked list
void print_list( song_node *n ) {
  while(n) {
    print_song(n);
    n = n->next;
  }
}

song_node * insert_front(song_node *n, char name[256], char artist[256]){
  if (!n){
    strcpy(n->name, name);
    strcpy(n->artist, artist);
    n->next = NULL;
  }
  song_node *new = new_song_node(name,artist);
  new->next = n;
  return new;
}

song_node * insert_order(song_node *n, char name[256], char artist[256]){
   //if n is empty
  if (!n){
    song_node *new = new_song_node(name,artist);
    new->next = NULL;
    return new;
  }
  
  song_node *temp = (song_node *)malloc(sizeof(song_node *));
  temp = n->next;
  //temp and n will sandwich 
  //will stop when it hits the same or "lesser" artist
  while (strcmp(artist, n->artist) > 0 && n){
    n = n->next;
    temp = temp->next;
  }
  //same artist. check song
  while (n && strcmp(temp->artist, artist) == 0 && strcmp(name, temp->name) > 0){
    temp = temp->next;
    n = n->next;
  }
  
  //inserting the node
  song_node *new_node = new_song_node(name, artist);
  new_node->next = temp;
  n->next = new_node;
  return new_node;
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
song_node * first_song_of( song_node * n, char * artist){
  return 0;
}

// find artist, print out all songs of artist
void search_artist( song_node p[26], char * artist ){
  int init = artist[0];
  int ch = 'a';
  int i = 0;
  while (ch <= 'z') {
    if (ch == init){
      song_node *n = &p[i]; // locate link list head with same initial
      song_node *r = first_song_of(n, artist);
      while (! strcmp(r->artist,artist)){ // same artist
        print_song(r);
        r = r->next;
      }
      i++;
      ch++;
    }
  }
}

// helper of add_song, add new song_node to playlist
void add_song_node(song_node * p[26], song_node * n) {
  
}

// create new song_node, pass to add_song_node
void add_song(song_node * p[26], char * name, char * artist){  
  song_node * n = new_song_node(name,artist);
  add_song_node(p,n);
  printf("new song %s by %s added\n",name,artist);
}

song_node * free_list(song_node * n) {
  song_node *f = n;
  while ( n ) {
    n = n->next;
    free(f);
    f = n;    
  }
  return n;
}

void free_array(song_node * p[26]) {
  int i = 0;
  while (i < 26){
    free_list(p[i]);
    i++;
  }
}

// ------------------------------------------ //


int main(){
  printf("------RUN------\n");

  song_node * playlist[26];
  printf("playlist[26]\n");
  
  song_node *a = new_song_node("like a cat","aoa");
  playlist[0] = a;
  //first_song_of(a,"aoa");
  
  free_array(playlist);

  printf("------RUN END------\n");
}


