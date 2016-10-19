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

struct song_node * search_list(struct song_node * n, char * name){
  while (n){
    if (! strcmp(name, n->name))
      n = n->next;
    else
      return n;
  }
  return n;
}

struct song_node * print_song(struct song_node *n){
  printf("song: %s\n", n->name);
}

int main(){
  struct song_node *a = (struct song_node *)malloc(sizeof(struct song_node));
  strcpy(a->name, "chasing ghosts");
  strcpy(a->artist, "atc");
  struct song_node *b = (struct song_node *)malloc(sizeof(struct song_node));
  strcpy(b->name, "runaway");
  strcpy(b->artist, "btc");
  struct song_node *c = (struct song_node *)malloc(sizeof(struct song_node));
  strcpy(c->name, "hello");
  strcpy(c->artist, "cdele");
  struct song_node *d = (struct song_node *)malloc(sizeof(struct song_node));
  struct song_node *addon = (struct song_node *)malloc(sizeof(struct song_node));

  a->next = b;
  b->next = c;
  c->next = d;
  d->next = NULL;

  printf("testing print list\n\n");
  print_list(a);
  
  printf("testing insert front\n");
  char name[256] = "hurhurhur";
  char artist[256] = "teehee";
  addon = insert_front(a, name, artist);
  printf("testing free\n");
  print_list(addon);
  
  printf("%d\n", free_list(addon));
}


