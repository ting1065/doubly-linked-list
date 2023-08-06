// ==================================================
// Doubly Linked List
//
// Create a working DLL that represents a hockey team.
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H

// define a struct for the nodes of the DLL to represent a hockey player
typedef struct player {
    int rosterNum;
    char* name;
    struct player* next;
    struct player* previous;
} player_t;

// define a struct for the DLL to represent the whole hockey team
typedef struct Team {
    int activePlayers;		// count keeps track of how many active players are on the Team.
    player_t* head;		// head points to the first player node in our DLL.
    player_t* tail;          //tail points to the last player node in our DLL.
} team_t;

// Creates a Team 
// Returns a pointer to a newly created Team.
// Returns NULL if we could not allocate memory.
team_t* create_team(){

    team_t* myTeam= (team_t*)malloc(sizeof(team_t));
    if (myTeam == NULL) {
        return NULL;
    }

    myTeam->activePlayers = 0;
    myTeam->head = NULL;
    myTeam->tail = NULL;

    return myTeam;
}



// Check if the team is empty
// Returns -1 if the team is NULL.
// Returns 1 if true (The team is completely empty)
// Returns 0 if false (the team DLL has at least one player enqueued)
int team_empty(team_t* t){

    if (t == NULL) {
        return -1;
    }
    else if (t->activePlayers == 0) {
        return 1;
    }
    else if (t->activePlayers > 0){
        return 0;
    }

    return -1; 
}

// push a new player to the front of the DLL ( before the first player in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure
int team_push_front(team_t* t, int roster, char* name){

    if (t == NULL) {
        return -1;
    }

    player_t* newPlayer = (player_t*)malloc(sizeof(player_t));
    if (newPlayer == NULL) {
        return 0;
    }
    newPlayer->rosterNum = roster;

    int nameSize = strlen(name);
    newPlayer->name = (char*)malloc(sizeof(char) * (nameSize+1));
    if (newPlayer->name == NULL) {
        return 0;
    }
    strcpy(newPlayer->name, name);

    newPlayer->next = t->head;
    newPlayer->previous = NULL;

    if (t->head != NULL) {
        t->head->previous = newPlayer;
    }
    
    t->head = newPlayer;
    if (t->activePlayers == 0) {
        t->tail = newPlayer;
    }

    t->activePlayers++;
   
    return 1;
}

// push a new player to the end of the team DLL (after the last player in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure
int team_push_back(team_t* t, int roster, char* name){
	
    if (t == NULL) {
        return -1;
    }

    player_t* newPlayer = (player_t*)malloc(sizeof(player_t));
    if (newPlayer == NULL) {
        return 0;
    }
    newPlayer->rosterNum = roster;

    int nameSize = strlen(name);
    newPlayer->name = (char*)malloc(sizeof(char) * (nameSize+1));
    if (newPlayer->name == NULL) {
        return 0;
    }
    strcpy(newPlayer->name, name);

    newPlayer->next = NULL;
    newPlayer->previous = t->tail;

    if (t->tail != NULL) {
        t->tail->next = newPlayer;
    }

    t->tail = newPlayer;
    if (t->activePlayers == 0) {
        t->head = newPlayer;
    }

    t->activePlayers++;

    return 1;
}

// Returns the first player in the DLL and also removes it from the team.
// Returns NULL if the Team is NULL. 
// Returns NULL on failure, i.e. there is no one to pop from the team.
player_t* team_pop_front(team_t* t){
    
    if (t == NULL) {
        return NULL;
    }

    if (t->activePlayers == 0) {
        return NULL;
    }

    player_t* temp;
    temp = t->head;
    t->head = t->head->next;

    if (t->activePlayers == 1) {
        t->tail = NULL;
    }
    else {
        t->head->previous = NULL;
    }
	
    t->activePlayers--;

    return temp;
}

// Returns the last player in the Team, and also removes it from the list.
// Returns NULL if the Team is NULL. 
// Returns NULL on failure.
player_t* team_pop_back(team_t* t){
    
    if (t == NULL) {
        return NULL;
    }
	
    if (t->activePlayers == 0) {
        return NULL;
    }

    player_t* temp;
    temp = t->tail;
    t->tail = t->tail->previous;
      
    if (t->activePlayers == 1) {
        t->head = NULL;
    }
    else {
        t->tail->next = NULL;
    }

    t->activePlayers--;
    
    return temp;
}

// Inserts a new player before the player at the specified position.
// Returns -1 if the list is NULL
// Returns 1 on success
// Retruns 0 on failure:
int team_insert(team_t* t, int pos, int roster, char* name){
    
    if (t == NULL) {
        return -1;
    }

    if (pos < 0 || t->activePlayers < pos) {
        return 0;
    }

    if (pos == t->activePlayers) {
        team_push_back(t, roster, name);
        return 1;
    }

    player_t* newPlayer = (player_t*)malloc(sizeof(player_t));
    if (newPlayer == NULL) {
        return 0;
    }
    newPlayer->rosterNum = roster;

    int nameSize = strlen(name);
    newPlayer->name = (char*)malloc(sizeof(char) * (nameSize + 1));
    if (newPlayer->name == NULL) {
        return 0;
    }
    strcpy(newPlayer->name, name);
    
    player_t* iterator = t->head;
    int i;
    for (i=0; i<pos; i++) {
        iterator = iterator->next;
    }

    newPlayer->next = iterator;
    if (t->activePlayers == 0) {
        newPlayer->previous = NULL;
        t->tail = newPlayer;
    }
    else {
        newPlayer->previous = iterator->previous;
        if (iterator->previous != NULL) {
            iterator->previous->next = newPlayer;
        }
        iterator->previous = newPlayer;
    }

    if (pos == 0) {
        t->head = newPlayer;
    }

    t->activePlayers++;
        
    return 1;
}

// Returns the roster number of the player at position pos starting at 0 
// Returns -1 if the list is NULL
// Returns 0 on failure:
int team_list_get(team_t* t, int pos){
    
    if (t == NULL) {
        return -1;
    }

    if (pos < 0 || t->activePlayers - 1 < pos) {
        return 0;
    }

    player_t* iterator = t->head;
    int i;
    for (i=0; i<pos; i++) {
        iterator = iterator->next;
    }

    return iterator->rosterNum;
}

// Removes the player at position pos starting at 0
// Returns NULL if the list is NULL
// Returns NULL on failure:
player_t* team_list_remove(team_t* t, int pos){
    
    if (t == NULL) {
        return NULL;
    }

    if (pos < 0 || t->activePlayers - 1 < pos) {
        return NULL;
    }

    player_t* iterator = t->head;
    int i;
    for (i=0; i<pos; i++) {
        iterator = iterator->next;
    }

    if (iterator == NULL) {
        return NULL;
    }

    if (iterator->previous != NULL) {
        iterator->previous->next = iterator->next;
    }
    else {
        t->head = iterator->next;
    }

    if (iterator->next != NULL) {
        iterator->next->previous = iterator->previous;
    }
    else {
        t->tail = iterator->previous;
    }

    t->activePlayers--;

    return iterator;
}

// Team Size
// Returns -1 if the Team is NULL.
// Queries the current size of a team
int team_size(team_t* t){
    
    if (t == NULL) {
        return -1;
    }

    return t->activePlayers;
}

//Helper function
//free_player(player_t* p)
//Removes a play and its name from memory.
void free_player(player_t* p) {
    if (p == NULL) {
        return;
    }
    
    if (p->name != NULL) {
        
        free(p->name);
    }

    free(p);
}

// Free Team DLL
// Removes a Team and all of its players (...and their names!!...) from memory.
// This should be called before the program terminates.
void free_team(team_t* t){
    
    if (t == NULL) {
        return;
    }

    player_t* iterator = t->head;
    while (t->head != NULL) {
        iterator = iterator->next;
        free_player(t->head);
        t->head = iterator;
    }
    
    free(t);
}



#endif
