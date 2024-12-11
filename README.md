# CSC512 Course Project (Part-2-dev)

This project extracts seminal input features from C code using LLVM.

#### Running

##### NOTE: Please only run on VCL (program relies on debug instructions which may not generate correctly on other platforms (ex: MacOS))

##### A convenient script is located in the working directory to run the LLVM pass on a given test. Replace \<file_name\> with file names given under Testing below
`bash clean_build.sh <file_name>`

##### If you would like to CMake manually run these in the working directory
```
mkdir IR_Outputs
mkdir build
cd build
cmake ..
make
cd ..
clang -g -o0 -fpass-plugin=build/libSeminalInputFeaturesAnalysis.so -emit-llvm -c tests/<test_file_name>.c -o IR_Outputs/<test_file_name>.ll
```

#### Testing

2 simple and 3 complex (>200 LOC) test files are located in the tests folder
1. (Simple) file_copy.c - `bash clean_build.sh file_copy`
2. (Simple) merge_two.c - `bash clean_build.sh merge_two`
3. (Non-trivial) file_manupulation.c - `bash clean_build.sh file_manupulation`
4. (Non-trivial) dmc_unrar.c - `bash clean_build.sh dmc_unrar`
5. (Non-trivial) stb_vorbis.c - `bash clean_build.sh stb_vorbis`

**NOTE:** Some test files may not meet the conditions in the analysis (some simple tests may not populate loop analysis) (try the complex files)

#### Outputs:
The analysis file should populate in the working directory as `analysis_output.txt` by default

If you would like it in a different file - change `FILE_NAME` in `part2/SeminalInputFeaturesAnalysis.cpp`

**NOTE:** The code by default deletes any previous analysis file and rewrites it. So please look/save an output before running the next test.


