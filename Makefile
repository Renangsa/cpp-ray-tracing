program = RayTracing

# Flags
hide = --no-print-directory --silent
flags = -O3
export path ?= $(realpath src/)



# -----< VARIABLES SECTION >----- #

# Locations to packages
upstream = /home/gabriel/Projects/algorithms/packages/makefile
location = /home/gabriel/Projects/.repo
repositories = $(sort $(foreach repo,$(file < $(location)),$(wildcard $(repo))))
index = $(firstword $(filter %/$1,$(repositories)))


# File Functions
readfile = $(foreach word,$(file < $1),$(word))
writefile = $(file > $2) $(foreach item,$1,$(file >> $2,$(item)))

# Search Functions
search = $(foreach item,$1,$(if $(suffix $(item)),$(item),$(call search,$(wildcard $(item)/*))))
locate = $(filter $1,$(call search,$(wildcard $2/**/*)))


# Folder Structure
folders = $(sort $(dir $(call locate,%.cpp,src)))
structure = $(subst src,build,$(call folders))


# Packages
sources = $(subst src,build,$(call locate,%.cpp,src))


# Object files
main = src/main.cpp
headers = $(call locate,%.hpp,src)
objects = $(subst .cpp,.o,$(sources))



# -----< BUILD PROGRAM SECTION >----- #

# Build program
build/$(program): build $(main) $(structure) $(objects) $(headers)
	@echo "Building Executable"
	@echo " Generating $@"
	@echo "   Compiling $(main)"
	@g++ $(flags) $(foreach item,$(path),-I$(item)) $(main) $(objects) $(dependencies) -o build/$(program)
	@echo "Finished Building"
	@echo


# Run program
run: build/$(program)
	@build/$(program)


# Clean files and rebuild
rebuild: clear build/$(program)


debug: debugger build $(main) $(structure) $(objects) $(headers)
	$(eval directories=$(foreach item,$(path),-I$(item)))
	@g++ $(flags) $(directories) $(main) $(objects) $(dependencies) -o debugger/$(program) 
	@echo "Build: Debug"
	@echo



# -----< BUILD OBJECTS SECTION >----- #

# Build object files
.SECONDEXPANSION:
build/%.o: src/%.cpp $$(wildcard src/$$*.hpp)
	@echo "    Compiling: $@"
	@g++ $(flags) $(foreach item,$(path),-I$(item)) -c $< -o $@



# -----< SUBFOLDERS SECTION >----- #

# Creates subfolder
create:
 ifdef file
	$(eval folder?=$(file))
	$(eval filename=src/$(folder)/$(file).x)
	@mkdir -p src/$(folder)
	@echo "Creating $(file)"
	@echo "#pragma once" > $(filename:.x=.hpp)
	@echo '#include "$(file).hpp"' > $(filename:.x=.cpp)
 else ifdef folder
	@echo "Creating $(folder)"
	@mkdir -p src/$(folder)
  ifdef header
	@echo "#pragma once" > src/$(folder)/$(header).hpp
  else ifdef source
	@touch src/$(folder)/$(source).cpp
  endif
 else
	@echo "The name of the file was not specified."
	@echo "Use 'make create file=<name>'"
 endif


# Deletes subfolder
delete:
 ifdef folder
  ifdef file
	@echo "Deleting file $(file)"
	@rm -f src/$(folder)/$(file).*
  else
	@echo "Deleting folder $(folder)"
	@rm -rf src/$(folder)
  endif
 else
	@echo "The name of the folder was not specified."
	@echo "Use 'make delete folder=<name>'"
 endif



# -----< PROJECT STRUCTURE SECTION >----- #

# Create source folder
init:
	@mkdir -p src .vscode
	@touch src/main.cpp
	@touch .vscode/settings.json
	@echo '{\n\t"files.associations": {\n\t\t"$(program)": "shellscript"\n\t}\n}' > .vscode/settings.json

# Create header folder
header:
  ifdef file
	@mkdir -p exports/$(program)
	@touch exports/$(program)/$(file).h
  else
	@mkdir -p exports
	@touch exports/$(program).h
  endif

# Creates source subfolders
build/%:
	@echo "  Creating: $@"
	@mkdir -p $@

# Creates folders
build:
  ifndef silent
	@echo "Building Project"
  endif
	@mkdir build

lib:
	@mkdir lib

packages:
	@mkdir packages

debugger:
	@rm -rf lib build
	@mkdir debugger



# -----< CLEARING SECTION >----- #

# Clear project
clear:
	@rm -rf build debugger

clear-lib:
	@rm -rf lib packages/**/Makefile

# Clear every build file
purge:
	@rm -rf lib build packages debugger exports/*.gch



# -----< DISPLAY HELP MESSAGE >----- #

# Help command
help:
	@echo "  Makefile helper"
	@echo ""
	@echo "    make  ==>   Builds the program"
	@echo "    make run  ==>   Executes the program"
	@echo "    make rebuild  ==>   Rebuilds the program"
	@echo "    make compile  ==>   Builds the dependency packages"
	@echo ""
	@echo ""
	@echo "    make create file=<name>  ==>   Creates <name>.cpp and <name>.hpp in 'src/<name>/'"
	@echo "    make create folder=<dir>  ==>   Creates directory 'src/<dir>/'"
	@echo "    make delete folder=<dir>  ==>   Deletes folder <dir> from the source directory"
	@echo ""
	@echo "    make create folder=<dir> file=<name>  ==>   Creates <name>.cpp and <name>.hpp in 'src/<dir>/'"
	@echo "    make delete folder=<dir> file=<name>  ==>   Deletes <name>.* from 'src/<dir>/'"
	@echo ""
	@echo ""
	@echo "    make clear  ==>   Delete the executable and the object files"
	@echo "    make purge  ==>   Delete everything apart from source code"
	@echo ""
