rm -r build
rm -r IR_Outputs
mkdir build
mkdir IR_Outputs
cd build
cmake ..
make
cd ..

clang -g -o0 -fpass-plugin=build/libSeminalInputFeaturesAnalysis.so -emit-llvm -c tests/tinyobj_loader_c.h -o IR_Outputs/tinyobj_loader_c.ll