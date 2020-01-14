# pa4-derekbarbosa
pa4-derekbarbosa created by GitHub Classroom

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
thanks
