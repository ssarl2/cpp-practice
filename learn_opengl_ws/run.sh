rm -rf bin/ build/

mkdir build
cd build
cmake ..
make -j

cd ../bin/
./$1
