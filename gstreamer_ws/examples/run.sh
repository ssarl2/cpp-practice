# echo "${file_name}" : basic-tutorial-4
# echo "${file_name%-*}" : basic-tutorial
# echo "${file_name##*-}" : 4
# What is '##*-'?
# http://egloos.zum.com/entireboy/v/4767066

#!/bin/bash

file_name="${1%.*}"

if [ ! -d build ]
then
    mkdir build
fi

if [ -f build/${file_name} ]
then
    rm build/${file_name}
fi

echo "Run $1"

if [ "${file_name%-*}" == "playback-tutorial" ] || [ "${file_name}" == "basic-tutorial-5" ]
then
    gcc $1 -o ${file_name} `pkg-config --cflags --libs gstreamer-video-1.0 gtk+-3.0 gstreamer-1.0`
elif [ "${file_name}" == "basic-tutorial-8" ]
then
    gcc $1 -o ${file_name} `pkg-config --cflags --libs gstreamer-1.0 gstreamer-audio-1.0`
elif [ "${file_name}" == "basic-tutorial-9" ]
then
    gcc $1 -o ${file_name} `pkg-config --cflags --libs gstreamer-1.0 gstreamer-pbutils-1.0`
elif [ "${file_name}" == "appsrc" ] || [ "${file_name%-*}" == "basic-tutorial" ]
then
    gcc $1 -o ${file_name} `pkg-config --cflags --libs gstreamer-1.0`
elif [ "${file_name}" == "test_receiver" ] || [ "${file_name}" == "test_receiver_cube" ] || [ "${file_name}" == "receiver_from_file" ]
then
    g++ $1 -o ${file_name} `pkg-config --cflags --libs gstreamer-1.0` -lgstpbutils-1.0 -lgstvideo-1.0 -lGL -ldl -Wno-write-strings
    # g++ $1 -o ${file_name} `pkg-config --cflags --libs gstreamer-1.0 gstreamer-plugins-bad-1.0 glfw3` glad.c -lGL -lGLU -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl
elif [ "${file_name}" == "receiver" ]
then
    g++ $1 -o ${file_name}  `pkg-config --cflags --libs gstreamer-1.0` -lgstpbutils-1.0 -lgstvideo-1.0 -lGL -ldl -Wno-write-strings
    # g++ $1 -o ${file_name} `pkg-config --cflags --libs gstreamer-1.0 gstreamer-plugins-bad-1.0 glfw3` glad.c -lGL -lGLU -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl
else
    g++ $1 -o ${file_name} `pkg-config --cflags --libs opencv gstreamer-1.0` -lstdc++
fi

mv ${file_name} build/
cd build
./${file_name}

    # X11
    # pthread
    # Xrandr
    # Xi
# -lX11 -lpthread -lXrandr -lXi
