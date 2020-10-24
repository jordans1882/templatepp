# Mat

## Dependencies

- [Boost](https://www.boost.org/) (tested with 1.58)
- [CMake](https://cmake.org) (tested with 3.11.0)
- [Google Test](https://github.com/google/googletest) (tested with 1.8.0)
- [PLF Nanotimer](https://github.com/mattreecebentley/plf_nanotimer) (tested with commit 8c42255)

## Building and Setup

Dependences are installed using CMake!  For more on getting started with cmake
see the [cmake tutorial](https://cmake.org/cmake-tutorial/). To get started just
build as you would any standard cmake project (but the dependences will be
handled for you).

    mkdir build
    cd build
    cmake ..
    make

Before making edits use:

	git checkout -b [new_branch_name]

to create a new branch to work on.
