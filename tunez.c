#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
You should start by making your linked lists work with the following functionality:
insert song_nodes at the front
insert song_nodes in order
print the entire list
find and return a pointer to an individual song based on song name
find and return a pointer to the first song of an artist based on artist name
Return a pointer to random element in the list.
remove a single song_node from the list
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
Files you should have:
A .c file that contains the main function you use to test all your work
At least one set of .h/.c files
For example, you can put your struct definition and your linked list headers in a .h file
You may also want to set up a .h/.c set for the playlist specific functions and a separate set for the linked list functions.
A makefile that will compile all the parts of your code and generate a single executable program
*/
struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

void print_list(struct song_node * n);
struct song_node * insert_front(struct song_node *n, char name[256], char artist[256]);
struct song_node * free_list(struct song_node *n );


void print_list(struct song_node *n ) {
  while(n->next) {
    printf("song: %s, artist: %s\n", n->name, n->artist);
    n = n->next;
  }
}


struct song_node * insert_front(struct song_node *n, char name[256], char artist[256]){
  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  new->next = n;
  return new;
}

struct song_node * free_list(struct song_node *n) {
  struct song_node *f = n;
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


