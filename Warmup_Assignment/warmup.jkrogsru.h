#ifndef ASSIGNMENT1_WARMUP_JKROGSRU_H
#define ASSIGNMENT1_WARMUP_JKROGSRU_H

#define MAXNAMELEN 63
#define NUMSONGS 10

typedef struct {
    char title[1+MAXNAMELEN];
    char artist[1+MAXNAMELEN];
    unsigned int year;
} Song;

Song *createSong(char *title, char *artist, unsigned int year);

int compareSongs(Song *songOne, Song *songTwo);

// Helper function to determine the length of a char array
int size(char* string);

// Builds the song array for sorting
int buildSongArray(Song **songArray_p, int *numSongs);

// prints, sorts and prints a songarray
int buildAndSort();

#endif //ASSIGNMENT1_WARMUP_JKROGSRU_H
