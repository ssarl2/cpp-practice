#!/bin/bash

if [ ! -d "build" ]
then
    mkdir build
fi

cd src

file_name="${1%.*}"

if [ -f ../build/${file_name} ]
then
    rm ../build/${file_name}
fi

echo "Run $1"
echo "Go to build folder"

if [ "${file_name}" == "server" ]
then
    rm ../build/client
    echo "Please run ./client in another window"
    g++ client.cpp -o client
    g++ server.cpp -o server
    mv client ../build/
elif [ "${file_name}" == "chat_server" ]
then
    rm ../build/chat_client
    echo "Please run ./chat_client in another window"
    g++ chat_client.cpp -o chat_client
    g++ chat_server.cpp -o chat_server
    mv chat_client ../build/
elif [ "${file_name}" == "one_di_server" ]
then
    rm ../build/one_di_client
    echo "Please run ./one_di_client in another window"
    g++ one_di_client.cpp -o one_di_client
    g++ one_di_server.cpp -o one_di_server
    mv one_di_client ../build/
elif [ "${file_name}" == "one_di_server2" ]
then
    rm ../build/one_di_client2
    echo "Please run ./one_di_client2 in another window"
    g++ one_di_client2.cpp -o one_di_client2
    g++ one_di_server2.cpp -o one_di_server2
    mv one_di_client2 ../build/
else
    echo "You typed wrong."
fi

mv ${file_name} ../build/
cd ../build
./${file_name}
