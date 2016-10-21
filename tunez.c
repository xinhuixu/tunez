#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tunez.h"
#include <time.h>

// make a new song node
song_node * new_song_node(char * name, char * artist){
  song_node *n = ( song_node * )malloc(sizeof( song_node ));
  strcpy(n->name, name);
  strcpy(n->artist, artist);
  n->next = NULL;
  return n;
}

int codeFor(char ch) {
  if (ch >= 'a' && ch <= 'z') {
      return ch - 'a';
   } else {
      return 99;
   }
}

int length( song_node * n ){
  int c = 0;
  while (n) {
    c++;
    n->next; 
  }
  return 0;
}

void print_song( song_node *n ){
  printf("song: %s | ", n->name);
  printf("artist: %s\n",n->artist);
}

// print out linked list
void print_list( song_node *n ) {
  while(n) {
    print_song(n);
    n = n->next;
  }
}

void print_letter(song_node * p[26], char c){
  print_list(p[codeFor(c)]);
}

song_node * insert_front(song_node *n, char name[256], char artist[256]){
  //if null
  if (!n){
    return new_song_node(name,artist);
  }
  song_node *new = new_song_node(name,artist);
  new->next = n;
  return new;
}

// insert song in order
song_node * insert_order(song_node *n, char name[256], char artist[256]){
   //if n is empty
  song_node *start = ( song_node * )malloc(sizeof( song_node ));
  start = n;
  if (!n || strcmp(artist, n->artist) < 0){
    return insert_front(n, name, artist); //will return front node
  }
  song_node *temp = (song_node *)malloc(sizeof(song_node *));
  temp = n->next;
  //temp and n will sandwich 
  //will stop when it hits the same or "lesser" artist
  while (n->next && strcmp(artist, n->artist) > 0){
    n = n->next;
    temp = temp->next;
  }
  //same artist. check song
  while (n->next && strcmp(temp->artist, artist) == 0 && strcmp(name, temp->name) > 0){
    temp = temp->next;
    n = n->next;
  }
  //inserting the node
  song_node *new_node = new_song_node(name, artist);
  new_node->next = temp;
  n->next = new_node;
  return start;
}

// remove single node from list
song_node * remove_node( song_node * n, song_node * rem){
  return 0;
}

// delete song
song_node * delete_song( song_node * p[26], char * name, char * artist){
  
}

// random element in list
song_node * random_node( song_node * n){
  //sranddev();
  song_node * j = n;
  srand(time(NULL));
  int r = rand() % length(j);
  printf("r: %d\n",r);
  while (r) {
    j = j->next;
    r--;
  }
  return j;
}

// shuffle k songs
void shuffle( song_node * p[26], int k){
  int i = 0;
  //sranddev();
  srand(time(NULL));
  int r = rand() % 26;
  while (i<k){
   song_node * j = random_node(p[r]);
   print_song(j);
   i++; 
  }
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
  return 0;
}

// find pointer to song based on song name
song_node * search_song( song_node * p[26], char * name ){  
  int i = 0;
  while (i<26){
    song_node * r = search_in_node(p[i], name);
    if (r) {
      return r;
    }
    i++;
  }
  printf(">>> song '%s' not found\n",name);
  return 0;
}

// find first song of artist based on artist name
song_node * search_artist_in_node( song_node * n, char * artist){
  while (n){
    if (strcmp(artist, n->artist)) {
      n = n->next;
    } else {
      return n;
    }
  }
  return n;
}

// find artist
song_node * search_artist( song_node * p[26], char * artist ){  
  song_node *start = ( song_node * )malloc(sizeof( song_node ));
  start = p[codeFor(artist[0])];
   while (start){
    if (strcmp(artist, start->artist) == 0)
      return start;
    start = start->next;
  }
  return start;
}

// find artist, print out all songs of artist
void print_artist( song_node * p[26], char * artist ){
  song_node *start = ( song_node * )malloc(sizeof( song_node ));
  // start = p[codeFor(artist[0])];
  // while (start->next){
  //   if (strcmp(artist, start->artist) == 0)
  //     printf("song: %s", start->name);
  //   start = start->next;
  // }
  start = search_artist(p, artist);
  if (! start)
    printf("artist not found");
  else
    while (strcmp(start->artist, artist) == 0){
      print_song(start);
      start = start->next;
    }
}

// create new song_node, pass to add_song_node
void add_song(song_node * p[26], char * name, char * artist){  
  //print codeFor(artist[0]);
  //printf("%d", codeFor(artist[0]));
  if (!p[codeFor(artist[0])]){
    p[codeFor(artist[0])] = insert_front(p[codeFor(artist[0])], name, artist);
  }
  else
    insert_order(p[codeFor(artist[0])], name, artist);
  printf("new song %s by %s added\n",name,artist);
}

// print out entire playlist

void print_array(song_node * p[26]){
  int i;
  for (i = 0; i< 26; i++)
       if (p[i] == NULL) 
        //print_list(p[i]);
        printf("yo\n");
}

song_node * free_list(song_node * n) {
  song_node *f =  ( song_node * )malloc(sizeof( song_node *));
  f = n;
  while ( n ) {
    n = n->next;
    free(f);
    f = n;    
  }
  return n;
  // song_node * hold = (song_node *)malloc(sizeof(song_node ));
  // hold = n;
  // while (n->next){
  //   n = n->next;
  //   free(hold);
  //   hold = n;
  // }
  // hold = n->next;
  // free(n);
  // //printf("%d\n", hold);
  // return hold;
  
}

void free_array(song_node * p[26]) {
  int i;
  for (i = 0; i < 25; i++){
    free_list(p[i]);
  }
}

// ------------------------------------------ //
// worked helper fxn tests will be deleted after testing

int main(){
  // printf("------RUN------\n");

  // song_node * playlist[26];
  // printf("playlist[26]\n");
  
  
  // song_node *a = new_song_node("good luck","aoa");
  // a->next = new_song_node("like a cat","aoa");

  // print_list(a);
  // printf("\n");
  // print_list(insert_order(insert_order(a, "mom", "aoa"), "yolo", "aoa"));
  // printf("\n");
  // add_song(playlist, "good luck", "aoa");
  // printf("%d\n", playlist[0] == 0);
  // printf("%d\n", playlist[1] == 0);
  // print_list(playlist[0]);
  //print_array(playlist);

  printf("------RUN------\n");
  song_node * playlist[26];
  printf("playlist[26]\n");
  printf("------------\n");
  // song_node *a = new_song_node("good luck","aoa");
  // playlist[0] = a;
  //print_list(a);
  printf("------------\n");
  add_song(playlist, "how people move","akmu"); 
  add_song(playlist, "like a cat","aoa"); 
  //print_list(a);
  printf("------------\n");
  printf(">>> searching for song 'like a cat'\n");
  print_song(search_song(playlist, "like a cat"));
  printf("------------\n");
  printf(">>> searching for artist 'aoa'\n");
  print_song(search_artist(playlist, "aoa"));
  printf(">>> searching for artist 'apink'\n");
  //  print_song(search_artist(playlist, "apink"));
  printf("------------\n");
  printf(">>> printing all song under letter '%c'\n",'a');
  print_letter(playlist,'a');
  printf("------------\n");
  printf(">>> printing all songs by '%s'\n","aoa");
  print_artist(playlist,"aoa");
  printf("------------\n");
  printf(">>> printing random node\n");
  print_song(random_node(playlist[0]));
  printf("------------\n");
  
  printf("------RUN END------\n");
}
