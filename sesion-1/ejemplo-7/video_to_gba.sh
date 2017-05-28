#!/bin/bash

mkdir -p output
rm output/*

ffmpeg -i $1.mp4 -r 15 -f image2 output/image-%3d.png

mogrify -path ./output -format png -resize "240x160^" -gravity center -crop 240x160+0+0 +repage output/*.png

convert output/*.png -append output/$1.png
