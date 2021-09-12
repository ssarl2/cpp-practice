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

if [ "${file_name%%_*}" == "day01" ]
then
    gcc $1 -lstdc++ -o ${file_name}
elif [ "${file_name%%_*}" == "day02" ]
then
    gcc $1 -lstdc++ -o ${file_name}
else
    echo !!!!!!!!!!!!!!!!!! YOU HAVE TO PASS AT LEAST ONE CORRECT PARAMETER FILE !!!!!!!!!!!!!!!!!!
    exit 0
fi

mv ${file_name} build/
cd build
./${file_name}
