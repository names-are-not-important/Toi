************************** IF YOU ARE NOT ON WINDOWS THIS DOES NOT WORK ****************************
************************** IF YOU ARE NOT ON WINDOWS THIS DOES NOT WORK ****************************
************************** IF YOU ARE NOT ON WINDOWS THIS DOES NOT WORK ****************************
************************** IF YOU ARE NOT ON WINDOWS THIS DOES NOT WORK ****************************



- How to compile Toi
		first you need to install mingw-32 here is how: (note you only have to go up to step 3 and dont do it)https://www.matsson.com/prog/sdl2-mingw-w64-tutorial.php#
		after downloading run this in powershell in the same directory as the toi.cpp file
		make sure that in the toi/bin folder there is sdl2.dll
		then type this:
		g++ ./toi.cpp -o ./bin/toi.exe -I{path to sdl2/include} -L{path to sdl2/libs} -lmingw32 -lSDL2main -lSDL2 -static-libgcc -static-libstdc++ -lSDL2_mixer -mwindows icon.res
		now go to bin/toi.exe BOOM you just compiled Toi congrats




		if you are lost in the compiler part here is a example:
		g++ ./toi.cpp -o ./bin/toi.exe -IC:\Users\yourname\OneDrive\Documents\coding\libraries\include -LC:\Users\yourname\OneDrive\Documents\coding\libraries\lib -lmingw32 -lSDL2main -lSDL2 -static-libgcc -static-libstdc++ -lSDL2_mixer -mwindows icon.res