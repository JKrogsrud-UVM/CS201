// jdh CS201 Spring 2023
// for graduate portion of the warmup assignment

#include <string.h>
#include <stdlib.h>
#include "warmup.jkrogsru.h"

#define NUMSONGS 10

int buildSongArray(Song **songArray_p, int *numSongs) {
  *songArray_p = malloc(NUMSONGS * sizeof(Song));
  *numSongs = NUMSONGS;
  Song *songArray = *songArray_p;

  strcpy(songArray[0].title, "The Rain (Supa Dupa Fly");
  strcpy(songArray[0].artist, "Missy Elliott");
  songArray[0].year =  1997;

  strcpy(songArray[1].title, "I Can't Stand the Rain");
  strcpy(songArray[1].artist, "Ann Peebles");
  songArray[1].year = 1973;

  strcpy(songArray[2].title, "Ceremony");
  strcpy(songArray[2].artist, "New Order");
  songArray[2].year = 1981;

  strcpy(songArray[3].title, "Ceremony");
  strcpy(songArray[3].artist, "Radiohead");
  songArray[3].year = 2007;

  strcpy(songArray[4].title, "Fearless");
  strcpy(songArray[4].artist, "Taylor Swift");
  songArray[4].year = 2021;

  strcpy(songArray[5].title, "Fearless");
  strcpy(songArray[5].artist, "Taylor Swift");
  songArray[5].year = 2008;

  strcpy(songArray[6].title, "Good Will Come to You");
  strcpy(songArray[6].artist, "Fruit Bats");
  songArray[6].year = 2016;

  strcpy(songArray[7].title, "Take Me to the River");
  strcpy(songArray[7].artist, "Talking Heads");
  songArray[7].year = 1978;

  strcpy(songArray[8].title, "Take Me to the River");
  strcpy(songArray[8].artist, "Al Green");
  songArray[8].year = 1974;

  strcpy(songArray[9].title, "Long Black Veil");
  strcpy(songArray[9].artist, "Lefty Frizzell");
  songArray[9].year = 1959;

  return 0;
}

Song *songArray;
int numSongs;
int doit = buildSongArray(&songArray, &numSongs);



for (int index = 0; index < numSongs; index++)
{
    printf("%d): %s, %s, %d", index, songArray->title, songArray->artist, songArray->year);
}

// void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
qsort(songArray, numSongs, sizeof(Song), compareSongs)

for (int index = 0; index < numSongs; index++)
{
    printf("%d): %s, %s, %d", index, songArray->title, songArray->artist, songArray->year);
}


