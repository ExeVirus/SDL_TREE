# Map Structure

MapBlock: 16x16x16
World size: 773*80 = 61840
Simulated World size for object bounding: 800*80 = 64000

number of mapblocks:
3865x3865 = 14,938,225

Highest Level: World
0th level: 12800x12800x12800 chunks, 125 of them
1st level: 2560x2560x2560 chunks, 125 of them
2nd level: 512x512x512 chunks, 125 of them
3rd level: 128x128x128 chunks, 64 of them
4th level: 32x32x32    chunks, 64 of them
5th level: 16x16x16    chunks, 8 of them

So I could define 6 structs:

numberActive = 0; //up to 125
level_0 pointers[5][5][5];

struct level_0 {
    level_1* pointers[5][5][5];
}

struct level_1 {
    level_2* pointers[5][5][5];
}

struct level_2 {
    level_3* pointers[4][4][4];
}

struct level_3 {
    level_4* pointers[4][4][4];
}

struct level_4 {
    objectList* pointers[2][2][2]; //when no objects inside, just null it out
}

std::forward_list() objectList;

## Functions needed

Raycast<-->through bounding box

BoundingBox<-->bounding box intersection

BoundingSphere<-->bounding box intersection

## Raycast Algo

get current Level4 (mapblock)

Raycast from current position, do we leave our mapblock?
    No: linear search local mapblock objects, return on first intersection.
    Yes: Get next mapblock in that direction. Recurse. 

## Sphere Algo

get current Level4 (mapblock)

Sphere from current position, do we leave our struct?
    No: Sphere intersection with local objects?
        Yes: Is struct? Recurse [No:]
        Yes: Is object? add to list
        No: Continue
    yes: get parent structure. Recurse.
    
## Box Algo

get current Level4 (mapblock)

Box from current position, do we leave our struct?
    No: Sphere intersection with local objects?
        Yes: Is struct? Recurse to [No:]
        Yes: Is object? add to list
        No: Continue
    yes: get parent structure. Recurse.

#### Templating is actually going to make sense here
Why would it make sense? because we can know the chunk sizes at compile time.

## Research Project

Should research via 2D program first.
Generates objects with 2d positions. 
Very simple interface using SDL and KeyDown events

Definitely should profile it to compare linear search vs tree search. Play with sizes and dispersal, etc.

Should definitely use templating for defining the tree classes.

Should use template booleans to specify the kind of list/array to use for the contained class

To specify the templates, must work from bottom-up, so that higher structs have a class they can template on. 

