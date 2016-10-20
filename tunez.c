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

song_node * search_list( song_node * n, char * name ){
  while (n){
    if (! strcmp(name, n->name))
      printf("%s\n", n->name);
      n = n->next;
    else{
      return n;
    }
  }
  return n;
}

song_node * print_song( song_node *n ){
  printf("song: %s\n", n->name);
}


// ------------------------------------------ //


int main(){
  printf("------RUN------\n");
  
  song_node *a = ( song_node * )malloc(sizeof( song_node ));
  strcpy(a->name, "chasing ghosts");
  strcpy(a->artist, "atc");
  song_node *a2 = ( song_node * )malloc(sizeof( song_node ));
  strcpy(a2->name, "hello");
  strcpy(a2->artist, "adele");
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
  printf("search list test: %s\n", search_list(a0, test));
  
  free_list(a0);

  printf("------RUN END------\n");
}


