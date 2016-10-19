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

//find and return a pointer to an individual song based on song name

song_node * search_list( song_node * n, char * name ){
  while (n){
    if (! strcmp(name, n->name))
      n = n->next;
    else
      return n;
  }
  return n;
}

song_node * print_song( song_node *n ){
  printf("song: %s\n", n->name);
}

int main(){
  printf("------RUN------\n");
  song_node *a = ( song_node * )malloc(sizeof( song_node ));
  strcpy(a->name, "chasing ghosts");
  strcpy(a->artist, "atc");
  song_node *b = ( song_node * )malloc(sizeof( song_node ));
  strcpy(b->name, "runaway");
  strcpy(b->artist, "btc");
  song_node *c = ( song_node * )malloc(sizeof( song_node ));
  strcpy(c->name, "hello");
  strcpy(c->artist, "cdele");
  song_node *d = ( song_node * )malloc(sizeof( song_node ));
   song_node *addon = ( song_node * )malloc(sizeof( song_node ));

  a->next = b;
  b->next = c;
  c->next = d;
  d->next = NULL;

  printf("testing print list\n");
  print_list(a);
  
  printf("testing insert front\n");
  char name[256] = "hurhurhur";
  char artist[256] = "teehee";
  addon = insert_front(a, name, artist);
  print_list(addon);
  free_list(addon);
}


