#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/aricoin.png
ICON_DST=../../src/qt/res/icons/aricoin.ico
convert ${ICON_SRC} -resize 16x16 aricoin-16.png
convert ${ICON_SRC} -resize 32x32 aricoin-32.png
convert ${ICON_SRC} -resize 48x48 aricoin-48.png
convert aricoin-16.png aricoin-32.png aricoin-48.png ${ICON_DST}

