# Pokemon
a C++ Pokemon game created by Derek Barbosa for EC 327 with Professor Densmore
This project was divided into two parts-- PA3 and PA4 (Programming Assignments 3 & 4)
The project essentially was the culmination of all of our C++ skills, particularly with Object Oriented Programming.
In PA3, students were required to essentially create an in-terminal "Pokemon" Game using classes that have several member functions that alter the objects "state" and "behavior," (i.e. making a pokemon move or train). This was done with using pointers to objects as well as inheritance.
For example, the virtual base class "GameObject" is inherited by essentially all objects in the program, as every object was a "GameObject".
After constructing all classes that were necessary for the game's function, students were required to construct the MVC (Model - View - Controller), as well as a main.cpp that took user input in a loop, executed a game command (the controller) that called a model function, and updated the viewmodel.
In PA4, students were required to update the game with linked lists instead of using arrays (STL) so that the user could input a new command that would create a new persistent object at runtime that would be able to interact with the rest of the game (such as a new pokemon, a new gym, or a new arena/rival).

below is the version history edits and problems I ran into/resolved.


first commit
--edited slight errors in model.cpp function &  view functions when trying to determine why User Input commands "weren't doing anything" (i assumed view and model were broken)

--fixed issue with main.cpp i was having in PA3 i.e I was accidentally redeclaring functions by including the return typename as well as the typename for the variables, so it wasn't recognizing any of my commands --> this was a confusing issue in PA3 because a user could freely input commands but they wouldnt move the pokemon nor showstatus

finished all of step 1. --> now for some reason, getting strange segfaults with any commands, and grid no longer shows pokemon's location (nor does showstatus print their proper location)

--end of first commit (also deleted some files that randomly got pushed?)


second commit --after finishing parts of step one, for some reason, everything in my program broke (as listed above) pushing most updated versions of fixes to test on GDB on enggrid

third commit --finished all of PA4 (in terms of getting code written), even though linked lists were implemented, code still breaks after ANY command (segmentation fault 11). added more comments

fifth commit -- fixed segfault issue, all pokemon now show up on grid with proper initialized values. speed still shows up as 0, and pokemon do not move on the actual grid.
--> edited pokemon constructor & it's inheritance from GameObject in Pokemon.cpp and Model.cpp

Final commit -- fixed program issue, was an issue with the Pokemon constructor & speed declaration, as well as view::Plot().
Program works with little to no hiccups

NOTE AS OF 12/11/19 -- for some reason, program functions completely on devices with C++11 flag ONLY (this only occurs on ENGGRID) i.e. commands do not execute properly when compiling on EngGrid without C++ 11 flag.

PLEASE INCLUDE THE C++ 11 FLAG WHEN COMPILING

# Enjoy!
just run 'make' and ./PA4 to run the program
