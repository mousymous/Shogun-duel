# For Debug Build
debug:
	g++ main.cpp -o SHOGUN-DUEL -Wall -Wconversion -Weffc++ -pedantic-errors -lsfml-graphics -lsfml-window -lsfml-system -std=c++20 -g -ggdb -O0

release:
	g++ main.cpp -o SHOGUN-DUEL -pedantic-errors -lsfml-graphics -lsfml-window -lsfml-system -std=c++20 -g -O3 -DNDDEBUG

# -O0 is an no-optimization flag for easier debugging
# -pedantic-errors is a no-compiler-extension flag for generating a standard behavior
# -lsfml-graphics -lsfml-window -lsfml-system is a SFML specifier flag
# -Wall -Wconversion -Weffc++ are for warning checking 

# -O0 is the recommended optimization level for debug builds, as it disables optimization. This is the default setting.
# -O2 is the recommended optimization level for release builds, as it applies optimizations that should be beneficial for all programs.
# -O3 adds additional optimizations that may or may not perform better than -O2 depending on the specific program. Once your program is
# written, you can try compiling your release build with -O3 instead of -O2 and measure to see which is faster.

#Add -ggdb to the command line for debug builds and -O2 -DNDEBUG for release builds. Use the debug build options for now.