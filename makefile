SHELL=powershell.exe
.SHELLFLAGS=-Command
COMPILER=g++ 
COMPILE_FLAGS=-c -std=c++11 -static
LINK_FLAGS=-std=c++11 -static

SRC_DIR=src
OBJ_DIR=obj
DIST_DIR=dist
PROGRAM=main.exe

cleaning=@if( Test-Path $(1) ) { Remove-Item $(1) }
finding=$(shell ls $(SRC_DIR) -File -Name -Recurse -Filter *.cpp)

srcs=$(foreach src,$(subst \,/,$(finding)),$(SRC_DIR)/$(src))


VPATH=$(dir $(srcs))
MODULES=$(notdir $(srcs))

objs=$(MODULES:%.cpp=%.obj)

start: clean build run

$(objs): %.obj: %.cpp
	$(COMPILER) $(COMPILE_FLAGS) $< -o $(OBJ_DIR)/$@

compile: $(objs)

build: compile
	$(COMPILER) $(LINK_FLAGS) $(wildcard $(OBJ_DIR)/*.obj) -o $(DIST_DIR)/$(PROGRAM)

run: 
	$(DIST_DIR)/$(PROGRAM)

.PHONY: clean
clean:
	$(call cleaning,./$(OBJ_DIR)/*.obj)
	$(call cleaning,./$(DIST_DIR)/$(PROGRAM))

test:
	echo $(VPATH)
	echo $(MODULES)
