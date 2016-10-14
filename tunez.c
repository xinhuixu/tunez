#include <stdio.h>
#include <stdlib.h>
#include "tunez.h"
#include <string.h>

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
Files you should have:
A .c file that contains the main function you use to test all your work
At least one set of .h/.c files
For example, you can put your struct definition and your linked list headers in a .h file
You may also want to set up a .h/.c set for the playlist specific functions and a separate set for the linked list functions.
A makefile that will compile all the parts of your code and generate a single executable program
*/




void print_list( struct node *n ) {

  printf("[ ");
  
  while(n) {
    printf("The song name is: %s, artist is %s", n->name, n->artist);
    n = n->next;
  }
  printf("]\n");
}


struct node * insert_front(struct node *n, char name[256], char artist[256]); {
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->next = n;
  new->name = d;
  new->artist = artist;
  return new;
}

struct node * free_list(struct node *n) {
  struct node *f = n;
  while ( n ) {
    n = n->next;
    free(f);
    f = n;    
  }
  return n;
}

//find and return a pointer to an individual song based on song name

struct node * search_list(struct node * n, char * name){
  while (n){
    if (! strcmp(*name, n->i))
      n = n->next;
    return n;
  }
  return n;
}


