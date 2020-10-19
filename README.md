# ft_cub3d
The Graphic project of 1337 curses
# The Global Goal
The goal of cub3d is to make something using raycasting (like Wolfenstein 3D).

## The MiniGoals
- WASD to move, QE or Left/Right directional keys to rotate camera
- I to toggle Interface, O to toggle crosshair, L to toggle shadows
- ESC to quit
- Textures or colors for each sides (North, South, West, East) and Sky/Floor
- Shadows based on the distance
- Crosshair
- 3 different sprites
- Minimap
- Collectable items

# Till Now
`NOTE: The project still under working so This's not The final result`. <br />
>**What's New?**<br />
>>    - The Mandatory Part is Done NO need for any Thing.<br />
>>    - HUD:<br />
>>>        - The MiniMap is done.<br />
>>>        - need some other Things.<br />
>>    - Sprite:<br />
>>>        - Now You can add More Then one sprite.<br />
>>    - Fix Some Bugs.<br />
>>    - You can close the game now using (X) in The tab.<br />
>      The Game Is Still Under Devlop so May There's some other Bugs (^-^).<br /><br />
# What is finished?
- The Things that just finished
  1. [x] The walls are draw
  2. [x] Your Player can Move forward and backward and Rotate to right and left Now.
  3. [x] Minimap.
  4. [x] Textuer, every side of the wall have it's texture.
  5. [x] Draw the sky and the floor color.
  6. [x] Add texture for The N,E,W, and S of the wall.
  7. [x] the Game now can read the Map from a .cub file look at ``./maps`` folder.
  8. [x] Player can move to left and right.
  9. [x] fix some bugs in the map reading.
  10. [x] add --save flag get a screen shot to the map.
  11. [x] All The bugs in Map files has been fixed.
  12. [x] Edit The Files.
  12. [x] Fix some Bugs.
- Working on:
  1. [ ] The texture for the sky and the floor.
  2. [ ] Ability to look up and Down.
  3. [ ] jump or couch.
  4. [ ] More items in the Maze.
  5. [ ] secret Doors.
  6. [ ] Sounds and Music.
  
# cub3d Alpha version 5: (what's new)
- minimap:
  - Now The minimap draw the wall with the color like in the map
  - Add the position of the player
  - the position of the player change in the minimap like in the map4
- Edit the wall color
- Now drawing of the wall get more faster because The drawing now using images 
- give x and y sides different brightness in the wall
- The textuer for all the walls
- draw the sky and the floor
- Add The ability to get a screenshot to The map.
# ScreenShot From The Game:
![Image From The game](https://github.com/barimehdi77/ft_cub3d/blob/master/screenshot.bmp)
# How To Play: (Installation)
**MacOS Users:**
  - `git clone https://github.com/barimehdi77/ft_cub3d.git.`.
  - `cd ft_cub3d`.
  - if You want to play Mandatory part: `./run.sh maps/<Number of The map>.cub`.
  - if You want to take a screenshot : `./run.sh maps/<Number of The map>.cub --save`.
  - if You want to Play The Bonus Part : `./run.sh bonus maps/<Number of The map>.cub`.
  - if You want to Take a ScreenShot With Bonus : `./run.sh bonus maps/<Number of The map>.cub --save`.
  
# The project Deadline
**For Mandatory Part:**  
  - started: `28/04/2020`.  
  - The deadline: ` 19/10/2020`.  

**For The Bonus part:**  
  - started: `20/10/2020`.  
  - The Deadline:  `01/11/2020`.
# Ressources
- [Playable Wolfenstein 3D](http://users.atw.hu/wolf3d/)
- [Raycasting in JS](http://www.playfuljs.com/a-first-person-engine-in-265-lines/)
- [Some X11 event numbers](https://github.com/qst0/ft_libgfx)
- [Full tutorial in English](https://lodev.org/cgtutor/raycasting.html)
- [Images in minilibx](https://github.com/keuhdall/images_example)
- [BMP format on StackOverflow](https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries)
- [BMP format explanation](https://web.archive.org/web/20080912171714/http://www.fortunecity.com/skyscraper/windows/364/bmpffrmt.html)
