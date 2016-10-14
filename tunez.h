typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};

void print_list(struct node * );
struct node * insert_front(struct node *n, char name[256], char artist[256]);
struct node * free_list(struct node *n );
