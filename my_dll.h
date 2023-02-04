// =================== Support Code =================
// Doubly Linked List ( Team DLL ).
//
// - Implement each of the functions to create a working DLL that represents a hockey team.
// - Do not change any of the function declarations
//   - (i.e. team_t* create_team() should not have additional arguments)
// - You should not have any 'printf' statements in your functions. 
//   - (You may consider using these printf statements to debug,
//     but they should be removed from your final version)
//   - (You may write helper functions to help you debug your code such as print_list etc)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H

// Create a player data structure to store data within
// our Team DLL. In our case, we will store a hockey player in each player struct.
// rosterNum is the player's roster number; roster numbers are always greater than 0
// The longest player name ever used in the NHL is 14 characters, so you can 
// assume the longest name you'll have to deal with is at most 20 character long
// we are only using family names.
typedef struct player {
	int rosterNum;
	char* name;
	struct player* next;
  	struct player* previous;
} player_t;

// Create a Team data structure that is a doubly linked list
// Our Team DLL holds a pointer to the first player node in our Team dll called head,
// and a pointer to the last player node in our Team called tail.
// It also keeps count of how many active players we have on our Team
typedef struct Team {
	int activePlayers;		// count keeps track of how many active players are on the Team.
	player_t* head;		// head points to the first player node in our DLL.
    player_t* tail;          //tail points to the last player node in our DLL.
} team_t;

// Creates a Team 
// Returns a pointer to a newly created Team.
// The Team should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The Team fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
team_t* create_team(){
	// Modify the body of this function as needed.
	team_t* myTeam= (team_t*)malloc(sizeof(team_t));
    if (myTeam == NULL) {
        return NULL;
    }

    myTeam->activePlayers = 0;
    myTeam->head = NULL;
    myTeam->tail = NULL;

	return myTeam; // Note: This line is a 'filler' so the code compiles.
}



// Team DLL Empty
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

    return -1; // Note: This line is a 'filler' so the code compiles.
}

// push a new player to the front of the DLL ( before the first player in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new player)
// (i.e. the memory allocation for a new player failed).
int team_push_front(team_t* t, int roster, char* name){

    if (t == NULL) {
        return -1;
    }

    player_t* newPlayer = (player_t*)malloc(sizeof(player_t));
    if (newPlayer == NULL) {
        return 0;
    }
    newPlayer->rosterNum = roster;
    newPlayer->name = name;
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
   
    return 1; // Note: This line is a 'filler' so the code compiles.
}

// push a new player to the end of the team DLL (after the last player in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new player)
// (i.e. the memory allocation for a new player failed).
int team_push_back(team_t* t, int roster, char* name){
	// TODO: Implement me!!
    if (t == NULL) {
        return -1;
    }

    player_t* newPlayer = (player_t*)malloc(sizeof(player_t));
    if (newPlayer == NULL) {
        return 0;
    }
    newPlayer->rosterNum = roster;
    newPlayer->name = name;
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

	return 1; // Note: This line is a 'filler' so the code compiles.
}

// Returns the first player in the DLL and also removes it from the team.
// Returns NULL if the Team is NULL. 
// Returns NULL on failure, i.e. there is no one to pop from the team.
// Assume roster numbers are always greater than zero
player_t* team_pop_front(team_t* t){
	// TODO: Implement me!!
	
	return NULL; // Note: This line is a 'filler' so the code compiles.
}

// Returns the last player in the Team, and also removes it from the list.
// Returns NULL if the Team is NULL. 
// Returns NULL on failure, i.e. there is no one to pop from the Team.
// Assume roster numbers are always greater than zero
player_t* team_pop_back(team_t* t){
	// TODO: Implement me!!
	
	return NULL; // Note: This line is a 'filler' so the code compiles.
}

// Inserts a new player before the player at the specified position.
// Returns -1 if the list is NULL
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new player
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent of calling push_back).
int team_insert(team_t* t, int pos, int roster, char* name){
	// TODO: Implement me!!
	
	return 99999; // Note: This line is a 'filler' so the code compiles.
}

// Returns the roster number of the player at position pos starting at 0 
// ( 0 being the first item )
// Returns -1 if the list is NULL
//  (does not remove the item)
// Returns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Assume roster numbers are always greater than zero
int team_list_get(team_t* t, int pos){
	// TODO: Implement me!!
	
	return 99999; // Note: This line is a 'filler' so the code compiles.
}

// Removes the player at position pos starting at 0 ( 0 being the first item )
// Returns NULL if the list is NULL
// Returns NULL on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Assume no negative numbers in the list or the number zero.
// Otherwise returns the roster number of the player removed.
player_t* team_list_remove(team_t* t, int pos){
	// TODO: Implement me!!
	
	return NULL; // Note: This line is a 'filler' so the code compiles.
}

// Team Size
// Returns -1 if the Team is NULL.
// Queries the current size of a team
int team_size(team_t* t){
	// TODO: Implement me!!
	
	return 99999; // Note: This line is a 'filler' so the code compiles.
}

// BONUS function - not required for HW
// no extra credit is given for this function
// Team DLL Sort
// sorts the team by roster number, putting the players in order
// with the smallest roster number at the head of the list, 
// in ascending order
// only work on this if you're all done with everything else tested!!
void team_sort(team_t* t){

    // OPTIONAL

}

// Free Team DLL
// Removes a Team and all of its players (...and their names!!...) from memory.
// This should be called before the program terminates.
void free_team(team_t* t){
	// TODO: Implement me!!
	
}



#endif
