#!/bin/bash

MAIN_DIR=$(pwd)

NAME="mgba-0.5.2"
FILE="$NAME.tar.gz"
BUILD_DIR="$NAME"
INSTALL_DIR="mGBA"
URL="https://github.com/mgba-emu/mgba/archive/0.5.2.tar.gz"

echo "############# mGBA ############"
if [ ! -d "$INSTALL_DIR" ]; then
	cd /var/tmp
	if [ ! -f "$FILE" ]; then
		echo "Downloading..."
		wget -O $FILE $URL
	else
		echo "Already downloaded"
		sleep 1
	fi
	
	if [ ! -d "$BUILD_DIR" ]; then
		echo "Extracting..."
		tar xzf $FILE
	else
		echo "Already extracted"
		sleep 1
	fi

	cd "$BUILD_DIR"
	mkdir -p build
	cd build
	cmake -DBUILD_SDL:BOOL=OFF ..
	make -j4

	#mkdir -p "$MAIN_DIR/$INSTALL_DIR"
	#cp -r qt/mgba-qt "$MAIN_DIR/$INSTALL_DIR"
else
	echo "Already installed"
fi

NAME="devkitARM"
FILE="$NAME.tar.bz2"
BUILD_DIR="$NAME"
INSTALL_DIR="$NAME"
URL="https://sourceforge.net/projects/devkitpro/files/devkitARM/devkitARM_r45/devkitARM_r45-i686-linux.tar.bz2/download"

echo "########## devkitArm ##########"
if [ ! -d "$INSTALL_DIR" ]; then
	cd /var/tmp
	if [ ! -f "$FILE" ]; then
		echo "Downloading..."
		wget -O $FILE $URL
	else
		echo "Already downloaded"
		sleep 1
	fi
	
	if [ ! -d "$BUILD_DIR" ]; then
		echo "Extracting..."
		tar xjf $FILE
		#add mv??
	else
		echo "Already extracted"
		sleep 1
	fi

	cd "$BUILD_DIR"
	#mkdir -p "$MAIN_DIR/$INSTALL_DIR"
	#cp -r ./* "$MAIN_DIR/$INSTALL_DIR"
else
	echo "Already installed"
fi
