/**
 * @file player.h
 * @author Durgesh
 * @date 8 Sep 2013
 */
#include "player.h"

/**
 * @brief Player::Player class to store the information of the user and stores its object into a binary file for future use
 * @param name name of the user
 */
Player::Player(char *name)
{
    int i;
    for(i = 0 ; name[i] != '\0' ; i++){
        this->name[i] = name[i] ;
    }
    this->name[i] = '\0' ;
    this->noOfUnlockTracks = 1; // intially one track is unlocked
    this->totalScore = 0 ;
}

Player::Player(){

}

char* Player::getName(){
    return this->name ;
}

void Player::settotalScore(int score){
    this->totalScore = score ;
}

void Player::setnoOfUnlockTracks(int tracks){
    this->noOfUnlockTracks = tracks ;
}

int Player::getnoOfUnlockTracks(){
    return this->noOfUnlockTracks ;
}

int Player::gettotalScore(){
    return this->totalScore ;
}
