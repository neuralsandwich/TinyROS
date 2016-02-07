#!/usr/bin/env bash -e

PROJECT_ROOT=$(pwd)

abort() {
    local message=$1

    echo "[ERROR] ${message}"
    exit 1
}

test_dependencies() {
    if [ -z $CC ] ; then
	abort "No C compiler set"
    fi
    
    if [ -z $CXX ] ; then
	abort "No C++ compiler set"
    fi

    if [ $(which cmake) == "cmake not found" ] ; then
	abort "CMake not found"
    fi
}

main() {
    local opts=$@

    while getopts "t" opt; do
	declare "opt_$opt=${OPTARG:-0}"
    done

    test_dependencies

    if [ ! -d ${PROJECT_ROOT}/build ] ; then
	mkdir ${PROJECT_ROOT}/build
    fi

    pushd ${PROJECT_ROOT}/build > /dev/null
    if [ ! -z $opt_t ] ; then
	cmake ${PROJECT_ROOT} -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug \
	      -DBUILD_TESTING=1
    else
	cmake ${PROJECT_ROOT} -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release \
	      -DBUILD_TESTING=1
    fi
    make -j $(sysctl -n hw.ncpu)
    make test
    popd > /dev/null
}

main $@
