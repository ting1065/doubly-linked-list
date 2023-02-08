// Note: This is not an exhaustive test suite, but gives you the idea
//       of some tests you might want to create.
//       Adding more tests and slowly making them more and more complicated
//       as you develop your library is recommended.
// 
// Compile this assignment with: gcc -g -Wall dll_test.c -o dll_test
//
// Run with: ./dll_test
// Then run with valgrind ./dll_test
// And don't forget valgrind -s ./dll_test!
//
// Comment out tests that you're not ready to run yet
// add them back in as you finish functions.
// You can also add tests as you go to make sure
// the functions you have written are working.
//
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free
#include <string.h> //for strings

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.


// A sample collection of tests for your program
// We will be adding our own to test your program.


// Tests creation and deletion of list
// Ideally does not cause any segfaults, and this
// is considered passing.
// Dll should also be empty.
int unitTest0(int status){
    int passed = 0;
    team_t* test = create_team();
    if(team_empty(test)){
    	passed = 1;
    }
    free_team(test);

    return passed;
}

// Tests push_front and size functions with 1 player
int unitTest1(int status){
    int passed = 0;
    team_t* test = create_team();
    char player[20] = "Pettersson";
    team_push_front(test, 40, player);
    if(1==team_size(test)){
       passed = 1;
    }else{
    	passed = 0;
    }
    free_team(test);

    return passed;
}


// Tests push_back and size functions with 1 player
int unitTest2(int status){
    int passed = 0;
    team_t* test = create_team();
    char player[20] = "Horvat";

    team_push_back(test, 142, player);
    if(1==team_size(test)){
       passed = 1;
    }else{
       passed = 0;
    }
    free_team(test);

    return passed;
}


//NOTE: tests 3 and onward will segfault until
//    you are returning a player node.  
// Tests push back and pop_back function with 1 player
int unitTest3(int status){
    int passed = 0;
    team_t* test = create_team();
    char player[20] = "Boeser";

    team_push_back(test, 6, player);
    player_t* popPlayer = team_pop_back(test);
    free(popPlayer->name);
    free(popPlayer);
    if(0==team_size(test)){
       passed = 1;
    }else{
    	passed = 0;
    }
    free_team(test);

    return passed;
}

// Tests push_back and push_front, then pops once
// then should compute the correct size.
int unitTest4(int status){
    int passed = 0;
    team_t* test = create_team();
    char player1[20] = "Kuzmenko";
    char player2[20] = "Mikheyev";

    team_push_back(test, 96, player1);
    team_push_front(test, 65, player2);
    player_t* popPlayer = team_pop_back(test);
    free(popPlayer->name);
    free(popPlayer);

    if(1==team_size(test)){
       passed = 1;
    }else{
    	passed = 0;
    }
    free_team(test);

    return passed;
}


// Tests push_back twice, then pops once from the front
// then should compute the correct size.
int unitTest5(int status){
    int passed = 0;
    team_t* test = create_team();
    char player1[20] = "Kuzmenko";
    char player2[20] = "Mikheyev";

    team_push_back(test, 96, player1);
    team_push_back(test, 65, player2);

    player_t* popPlayer = team_pop_back(test);
    free(popPlayer->name);
    free(popPlayer);

    if(1==team_size(test)){
       passed = 1;
    }else{
    	passed = 0;
    }
    free_team(test);

    return passed;
}


// Tests push_back twice, then pops once from the front
// tests the return value
int unitTest6(int status){
    int passed = 0;
    team_t* test = create_team();
    char player1[20] = "Kuzmenko";
    char player2[20] = "Mikheyev";

    team_push_back(test, 96, player1);
    team_push_back(test, 65, player2);
    player_t* forward = team_pop_front(test);
    char nameComp[15] = "Kuzmenko";
    if(0==strcmp(forward->name, nameComp)){
       passed = 1;
    }else{
    	passed = 0;
    }
    free(forward->name);
    free(forward);
    free_team(test);

    return passed;
}

// Tests push_front 3x, then pops once from the back
// tests the return value
int unitTest7(int status){
    int passed = 0;
    team_t* test = create_team();

    char player1[20] = "Kuzmenko";
    char player2[20] = "Mikheyev";
    char player3[20] = "Demko";

    team_push_front(test, 96, player1);
    team_push_front(test, 65, player2);
    team_push_front(test, 35, player3);

    player_t* forward = team_pop_back(test);
    char nameComp[15] = "Kuzmenko";
    if(0==strcmp(forward->name, nameComp)){
       passed = 1;
    }else{
    	passed = 0;
    }
    free(forward->name);
    free(forward);
    free_team(test);

    return passed;
}

// Tests push_front 3x, checks roster number of 2nd position
// player (who is third, since pos starts at 0)
// tests the return value
int unitTest8(int status){
    int passed = 0;
    team_t* test = create_team();

    char player1[20] = "Kuzmenko";
    char player2[20] = "Mikheyev";
    char player3[20] = "Demko";

    team_push_front(test, 96, player1);
    team_push_front(test, 65, player2);
    team_push_front(test, 35, player3);

    if(96==team_list_get(test, 2)){
       passed = 1;
    }else{
    	passed = 0;
    }
    free_team(test);

    return passed;
}


// Tests pushing front and back and then removing
// the player at position 1
int unitTest9(int status){
    int passed = 0;
    team_t* test = create_team();

    char player1[20] = "Pettersson";
    char player2[20] = "Demko";
    char player3[20] = "Kuzmenko";
    char player4[20] = "Horvat";

    team_push_back(test, 47, player1);
    team_push_front(test, 35, player2);
    team_push_back(test, 96, player3);
    team_push_back(test, 49, player4);

    player_t* forward = team_list_remove(test, 1);

    char nameComp[15] = "Pettersson";
    // printf("name is %s\n", forward->name);
    if(0==strcmp(forward->name, nameComp)){
       passed = 1;
    }else{
    	passed = 0;
    }
    free(forward->name);
    free(forward);
    free_team(test);

    return passed;
}


// Tests push_front 3x, inserts at position 1, 
// checks roster number of 2nd position
// player (who is third, since pos starts at 0)
// tests the return value
int unitTest10(int status){
    int passed = 0;
    team_t* test = create_team();

    char player1[20] = "Kuzmenko";
    char player2[20] = "Mikheyev";
    char player3[20] = "Demko";
    char player4[20] = "Ekman-Larsson";

    team_push_front(test, 96, player1);
    team_push_back(test, 65, player2);
    team_push_front(test, 35, player3);
    team_insert(test, 1, 23, player4);

    if(96==team_list_get(test, 2)){
       passed = 1;
    }else{
    	passed = 0;
    }
    free_team(test);

    return passed;
}

//Tests push_fron and size functions with 2 players
int unitTest11(int status) {
    int passed = 0;
    team_t* test = create_team();
    char player1[20] = "Rick";
    char player2[20] = "Morty";
    team_push_front(test, 11, player1);
    team_push_front(test, 10, player2);
    if (team_size(test) == 2) {
        passed = 1;
    }
    else {
        passed = 0;
    }
    free_team(test);

    return passed;
}

//Tests push_back and size functions with 2 players
int unitTest12(int status) {
    int passed = 0;
    team_t* test = create_team();
    char player1[20] = "Justin";
    char player2[20] = "Roiland";
    
    team_push_back(test, 3, player1);
    team_push_back(test, 4, player2);
    if (team_size(test) == 2) {
        passed = 1;
    }
    else {
        passed = 0;
    }
    free_team(test);

    return passed;
}

//Tests push back and pop_back function with 2 players
int unitTest13(int status) {
    int passed = 0;
    team_t* test = create_team();
    char player1[20] = "Rick";
    char player2[20] = "Morty";

    team_push_back(test, 6, player1);
    team_push_back(test, 20, player2);
    player_t* popPlayer1 = team_pop_back(test);
    player_t* popPlayer2 = team_pop_back(test);
    free_player(popPlayer1);
    free_player(popPlayer2);
    if (team_size(test) == 0) {
        passed = 1;
    } 
    else {
        passed = 0;
    }
    free_team(test);

    return passed;
}

//test push_back and push_front twice, then pops twice
int unitTest14(int status) {
    int passed= 0;
    team_t* test = create_team();
    char player1[20] = "Rick";
    char player2[20] = "Morty";
    char player3[20] = "Justin";
    char player4[20] = "Roiland";

    team_push_back(test, 23, player1);
    team_push_front(test, 6, player2);
    team_push_back(test, 4, player3);
    team_push_front(test, 66, player4);
    player_t* popPlayer1 = team_pop_back(test);
    player_t* popPlayer2 = team_pop_front(test);
    free_player(popPlayer1);
    free_player(popPlayer2);

    if (team_size(test) == 2) {
        passed = 1;
    }
    else {
        passed = 0;
    }
    free_team(test);

    return passed;
}

//Test push_back four times, then pops twice from the front
//then should compute the correct size
int unitTest15(int status) {
    int passed = 0;
    team_t* test = create_team();
    char player1[20] = "Rick";
    char player2[20] = "Morty";
    char player3[20] = "Justin";
    char player4[20] = "Roiland";
    
    team_push_back(test, 11, player1);
    team_push_back(test, 22, player2);
    team_push_back(test, 23, player3);
    team_push_back(test, 44, player4);

    player_t* popPlayer1 = team_pop_back(test);
    player_t* popPlayer2 = team_pop_back(test);
    free_player(popPlayer1);
    free_player(popPlayer2);

    if (team_size(test) == 2) {
        passed = 1;
    }
    else {
        passed = 0;
    }
    free_team(test);

    return passed;
}

//Test push_back four times, then pops twice from the front
//tests the return value
int unitTest16(int status) {
    int passed = 0;
    team_t* test = create_team();
    char player1[20] = "Rick";
    char player2[20] = "Morty";
    char player3[20] = "Justin";
    char player4[20] = "Roiland";

    team_push_back(test, 96, player1);
    team_push_back(test, 69, player2);
    team_push_back(test, 11, player3);
    team_push_back(test, 22, player4);
    player_t* forward1 = team_pop_front(test);
    player_t* forward2 = team_pop_front(test);
    char nameComp[15] = "Morty";
    if (strcmp(forward2->name, nameComp) == 0) {
        passed = 1;
    }
    else {
        passed = 0;
    }
    free_player(forward1);
    free_player(forward2);
    free_team(test);

    return passed;
}

//Tests push_front four times, then pops twice from the back
//tests the return value
int unitTest17(int status) {
    int passed = 0;
    team_t* test = create_team();

    char player1[20] = "Rick";
    char player2[20] = "Morty";
    char player3[20] = "Justin";
    char player4[20] = "Roiland";

    team_push_front(test, 96, player1);
    team_push_front(test, 67, player2);
    team_push_front(test, 43, player3);
    team_push_front(test, 22, player4);
    
    player_t* back1 = team_pop_back(test);
    player_t* back2 = team_pop_back(test);
    char nameComp[15] = "Morty";
    if (strcmp(back2->name, nameComp) == 0) {
        passed = 1;
    }
    else {
        passed = 0;
    }
    free_player(back1);
    free_player(back2);
    free_team(test);

    return passed;
}

//Tests push_front 4 times, checks roster number of 3nd position
//player(who is forth, since pos starts at 0)
//tests the return value
int unitTest18(int status) {
    int passed = 0;
    team_t* test = create_team();
    
    char player1[20] = "Rick";
    char player2[20] = "Morty";
    char player3[20] = "Justin";
    char player4[20] = "Roiland";

    team_push_front(test, 86, player1);
    team_push_front(test, 76, player2);
    team_push_front(test, 33, player3);
    team_push_front(test, 22, player4);

    if (team_list_get(test, 3) == 86) {
        passed = 1;
    }
    else {
        passed = 0;
    }
    free_team(test);

    return passed;
}

//Tests pushing front and back and then removing the player
//at position 1 twice
//tests the return value and the size of remaining team
int unitTest19(int status) {
    int passed = 0;
    team_t* test = create_team();

    char player1[20] = "Rick";
    char player2[20] = "Morty";
    char player3[20] = "Justin";
    char player4[20] = "Roiland";

    team_push_back(test, 47, player1);
    team_push_back(test, 35, player2);
    team_push_back(test, 96, player3);
    team_push_back(test, 40, player4);

    player_t* forward1 = team_list_remove(test, 1);
    player_t* forward2 = team_list_remove(test, 1);

    char nameComp[15] = "Justin";
    if (strcmp(forward2->name, nameComp) == 0 &&
        team_size(test) == 2) {
        passed = 1;
    }
    else {
        passed = 0;
    }
    free_player(forward1);
    free_player(forward2);
    free_team(test);

    return passed;
}

//Tests push_front three times, inserts at the position same as
//the team size, checks roster number of 3rd position
int unitTest20(int status) {
    int passed = 0;
    team_t* test = create_team();

    char player1[20] = "Rick";
    char player2[20] = "Morty";
    char player3[20] = "Justin";
    char player4[20] = "Roiland";

    team_push_front(test, 22, player1);
    team_push_front(test, 33, player2);
    team_push_front(test, 44, player3);
    team_insert(test, 3, 55, player4);

    if (team_list_get(test, 3) == 55) {
        passed = 1;
    }
    else {
        passed = 0;
    }
    free_team(test);

    return passed;
}

//Test inserting to an empty team at position 0
//tests the return value, team size, head and tail
//player's previous and next
int unitTest21(int status) {
    int passed = 0;
    team_t* test = create_team();

    char player[20] = "Rick";

    team_insert(test, 0, 23, player);

    if (team_list_get(test, 0) == 23 &&
        team_size(test) == 1 &&
        test->head == test->tail &&
        test->head->previous == NULL &&
        test->tail->next == NULL) {
        passed = 1;
    }
    else {
        passed = 0;
    }
    free_team(test);

    return passed;
}

//Test inserting to an empty team at position 0, 0 and 2
//test the return value, team size, head and tail
int unitTest22(int status) {
    int passed = 0;
    team_t* test = create_team();

    char player1[20] = "Rick";
    char player2[20] = "Morty";
    char player3[20] = "Justin";

    team_insert(test, 0, 11, player1);
    team_insert(test, 0, 22, player2);
    team_insert(test, 2, 33, player3);

    if (team_size(test) == 3 &&
        test->head->rosterNum == 22 &&
        team_list_get(test, 1) == 11 &&
        test->tail->rosterNum == 33 &&
        test->head->previous == NULL &&
        test->tail->next == NULL &&
        test->head->next == test->tail->previous) {
        passed = 1;
    }
    else {
        passed = 0;
    }
    free_team(test);

    return passed;    
}

// An array of function pointers to all of the tests
// that main() can use iterate over them.
int (*unitTests[])(int)={
    unitTest0,
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    unitTest7,
    unitTest8,
    unitTest9,
    unitTest10,
    unitTest11,
    unitTest12,
    unitTest13,
    unitTest14,
    unitTest15,
    unitTest16,
    unitTest17,
    unitTest18,
    unitTest19,
    unitTest20,
    unitTest21,
    unitTest22,
    NULL
};


// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter =0;
    while(unitTests[counter]!=NULL){
    	printf("========unitTest %d========\n",counter);
        if(1==unitTests[counter](1)){
    		printf("passed test\n");
    		testsPassed++;	
    	}else{
    		printf("failed test, missing functionality, or incorrect test\n");
    	}
    counter++;
    }

    printf("%d of %d tests passed\n",testsPassed,counter);

    return 0;
}
