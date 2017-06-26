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

	if [ ! -d "build" ]; then
                echo "Building..."
		mkdir -p build
		cd build
		cmake -DBUILD_SDL:BOOL=OFF ..
		make -j4
        else
                echo "Already built"
                sleep 1
        fi
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
	else
		echo "Already extracted"
		sleep 1
	fi
else
	echo "Already installed"
fi

NAME="tiled"
BUILD_DIR="$NAME"
URL="https://github.com/JFonS/tiled"

echo "############ Tiled ############"
if [ ! -d "$BUILD_DIR" ]; then
	cd /var/tmp
	if [ ! -d "$BUILD_DIR" ]; then
		echo "Downloading..."
		git clone $URL
	else
		echo "Already downloaded"
		sleep 1
	fi
	
	cd $BUILD_DIR
	qmake-qt5
	make -j4
	
else
	echo "Already installed"
fi

echo "###############################"
echo "Installation done. Please configure your environment."
echo -e "\e[1m\e[31mThis is your first test and it will be evaluated...\e[0m"

echo ""
echo ""

echo -n "$MAIN_DIR>"
sleep 15

echo ""
echo ""

echo -e "\e[1m\e[5m\e[31mCome on... I'm waiting... \e[0m"
echo ""
echo ""

sleep 5
echo -e "\e[1m\e[31mNothing? ok.\e[0m"
sleep 1

echo -e "\e[1m\e[31mIf you are lazy you can just copy the following command:"
echo -e "\e[1m\e[32msetenv DEVKITARM /var/tmp/devkitARM/ && set path = ( \$path /var/tmp/mgba-0.5.2/build/qt/ /var/tmp/tiled/bin/)\e[0m"

