rm -r build
mkdir build
cd build
cmake ..
make
cd ..

clang -g -o0 -fpass-plugin=build/libSeminalInputFeaturesAnalysis.so -emit-llvm -c tests/red_black_tree.c -o IR_Outputs/red_black_tree.ll