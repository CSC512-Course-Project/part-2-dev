# take 1 command line argument - the name of file to be tested

rm -r build
rm -r IR_Outputs
mkdir build
mkdir IR_Outputs
cd build
cmake ..
make
cd ..

clang -g -o0 -fpass-plugin=build/libSeminalInputFeaturesAnalysis.so -emit-llvm -c tests/$1.c -o IR_Outputs/$1.ll