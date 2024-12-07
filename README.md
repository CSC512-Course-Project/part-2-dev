# CSC512 Course Project (Part-2-dev)

This project extracts seminal input features from C code using LLVM.

## Running

#### NOTE: Please only run on VCL (program relies on debug instructions which may not generate correctly on other platforms (ex: MacOS))

##### A convenient script is located in the working directory to run the LLVM pass
`bash clean_build.sh`
##### If you would like to CMake manually run these in the working directory
```
mkdir build
cd build
cmake ..
make
cd ..
clang -g -o0 -fpass-plugin=build/libSeminalInputFeaturesAnalysis.so -emit-llvm -c tests/red_black_tree.c -o IR_Outputs/red_black_tree.ll
```
##### Outputs:
The analysis file should populate in the working directory as `analysis_output.txt` by default

If you would like it in a different file - change `FILE_NAME` in `part2/SeminalInputFeaturesAnalysis.cpp`

**NOTE:** The code by default deletes any previous analysis file and rewrites it 
