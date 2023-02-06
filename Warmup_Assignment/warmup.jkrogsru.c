#include "warmup.jkrogsru.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Song *createSong(char *title, char *artist, unsigned int year)
{
    Song *song = malloc(sizeof (Song));

    /*
     * Dividing space allocated for entire array by the space of a single character
     * will return the length of the array
     */
    if (title != NULL && artist != NULL)
    {
        int titleSize = size(title);
        int artistSize = size(artist);

        //printf("Title: %s has size %d, Artist: %s has size %d\n", title, titleSize, artist, artistSize);

        /* Checking here that title and artist have valid lengths */
        if (titleSize > 0 && titleSize <= MAXNAMELEN && artistSize > 0 && artistSize <= MAXNAMELEN )
        {
            strcpy (song->title, title);
            strcpy (song->artist, artist);
            song->year = year;
            return song;
        }
        else return NULL;
    }

    else return NULL;
}

int compareSongs(Song *songOne, Song *songTwo)
{
    // Check title first
    // If title of songOne precedes title of songTwo
    int cmpTitle = strcmp(songOne->title, songTwo->title);
    int cmpArtist = strcmp(songOne->artist, songTwo->artist);

    if (cmpTitle < 0)
    {
        return -1;
    }
    // Else If title of songtwo follows title of songTwo
    else if (cmpTitle > 0)
    {
        return 1;
    }
    // Else (they are equal)
    else
    {
        // Check which artist occurs earlier lexographically
        if (cmpArtist < 0)
        {
            return -1;
        }
        else if (cmpArtist > 0)
        {
            return 1;
        }
        else
        {
            // Check the years
            if (songOne->year < songTwo->year)
            {
                return -1;
            }
            else if (songOne->year > songTwo->year)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}

int size(char* string)
{
    int loc = 0;
    int count = 0;

    // We loop through the character array that is being pointed to and count until we hit the
    // null character
    while (*(string + loc) != '\0')
    {
        count++;
        loc++;
    }

    return count;
}

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

int buildAndSort()
{
    Song *songArray;
    int numSongs;
    buildSongArray(&songArray, &numSongs);

    printf("Before Sorting:\n");
    for (int index = 0; index < numSongs; index++)
    {
        printf("%d): %s, %s, %d\n", index, songArray[index].title, songArray[index].artist, songArray[index].year);
    }

    // void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
    qsort(songArray, numSongs, sizeof(Song), (int (*)(const void *, const void *)) compareSongs);

    printf("\nAfter Sorting:\n");
    for (int index = 0; index < numSongs; index++)
    {
        printf("%d): %s, %s, %d\n", index, songArray[index].title, songArray[index].artist, songArray[index].year);
    }
}
