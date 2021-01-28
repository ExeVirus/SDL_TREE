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

https://medium.com/@bromanz/another-view-on-the-classic-ray-aabb-intersection-algorithm-for-bvh-traversal-41125138b525

BoundingBox<-->bounding box intersection

AABB: duh.

BoundingSphere<-->bounding box intersection

https://stackoverflow.com/questions/28343716/sphere-intersection-test-of-aabb

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

## Research project overview

1. Generates a random list of positions between x=0-800 by y=0-800
    - This random list can have a distribution, say "clump around X random points" which would be more accurate to minetest gameplay
    - These random points should tend towards the center: (400,400)
    - Controlled by command line args
    --Insertion and Deletion time MUST be considered, how does it affect performance per level?

2. Use SDL2 to render each of these as a single point
3. Render the dividing boxes as a light color box
4. Player represents a lua question for the code: Either of:
    - Get Objects in range
    - Get Objects in area
    - Get Objects in raycast
5. All keyboard inputs:
    - Arrow keys: player walks around
    - A,S,D range,area,raycast
        - These *toggle*
        - When toggled, arrow keys behave differently
        - for range, up and down increase the range
        - for area, up and down increase vertical area, etc.
        - for raycast, up and down change the length, left right, the aim.
6. During the checking modes, timing information on how long each check takes is output to terminal.

7. There will be 3 levels:
    - level one divides the 800 length by 4, for 16 total boxes (200x200)
    - Level Two divides the 200 length by 4, for 16 total boxes (50x50)
    - level 3   divides the 50 length by 5, for 25 total boxes  (10x10)
    - Other options will be used to test, obviously. 

8. 10x10 represents a "block" in this example, so we will only spawn stuff within say 4 blocks of a random spawn point.

