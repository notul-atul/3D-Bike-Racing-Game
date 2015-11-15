#ifndef PLAYER_H
#define PLAYER_H
// header for information about player
class Player
{
public:
    Player(char *name);
    Player() ;
    char *getName() ;
    void settotalScore(int score) ;
    void setnoOfUnlockTracks(int tracks) ;
    int gettotalScore() ;
    int getnoOfUnlockTracks() ;

private:
    char name[50] ;
    int totalScore, noOfUnlockTracks ;
};

#endif // PLAYER_H
