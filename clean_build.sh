rm -r build
rm -r IR_Outputs
mkdir build
mkdir IR_Outputs
cd build
cmake ..
make
cd ..

clang -g -o0 -fpass-plugin=build/libSeminalInputFeaturesAnalysis.so -emit-llvm -c tests/dmc_unrar.c -o IR_Outputs/dmc_unrar.ll