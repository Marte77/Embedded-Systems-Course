the hls zip contains the vivado hls project for the IP CORE that implements the equalizer


the vivado zip contains the project, it is based on the RealTimeAudioCode from the teacher, so if you cant get the project to work, try using that one and import the core yourself.
the code should run without problems.

currently the code doesnt work very well. the classes instantiated lose their data when the threads/tasks are created

# I SENT YOU THE STUFF I DID ON ONEDRIVE IF YOU READ THIS HERE


# UPDATES 17/12/2025 23:37: NEW PROJECT FOLDER AND NEW CODE
- i realized the RealTimeAudioCode/ project is for the zybo board (not the z7), so I tried moving the code to audioEqSolutionZ7/
- the prof's code worked fine, compiling and giving "audio" (was just buzzing but its audio)
- the original code i wrote didn't work, so i tried to see if it would work in the prof's code
- when i enable the audio to pass by our IP core, the output audio is 0s, if i dont disable it i get buzz... This is the same result on the old code
- i dont understand what is wrong, but theres code to test, its the martinho_equalizer, on the main() thats on the bottom of main.cpp
- the original code i wrote in the old project is in the "antigo" folder (means old in portuguese)
- we should probably use the old code since i used state patterns in it
- 23:58: I had the genius idea of actually using floats, and it "works" now! works as in, there's no more 0s as the output, but there is no real audio. progress!
